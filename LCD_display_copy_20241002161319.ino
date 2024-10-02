uint8_t buf[8] = { 0 }; //Keyboard report buffer



#define PIN_A 5 // Pin for a


#define PIN_D 7 // Pin for d

void setup() {

Serial.begin(9600); // Setup Serial communication

//Set pinmode of Input pins


pinMode(PIN_A, INPUT);


pinMode(PIN_D, INPUT);

}

void loop() {

    // 检查 A 键是否按下
    if (digitalRead(PIN_A) == HIGH) {
        if (buf[2] != 4) { // 只在按下时发送一次按键按下的信号
            buf[2] = 4; // 设置为 A 键的键码
            Serial.write(buf, 8); // 发送按键按下信号
        }
    }
    else if (buf[2] == 4) { // 当 A 键松开时
        releaseKey(); // 发送按键松开信号
    }

    // 检查 D 键是否按下
    if (digitalRead(PIN_D) == HIGH) {
        if (buf[2] != 7) { // 只在按下时发送一次按键按下的信号
            buf[2] = 7; // 设置为 D 键的键码
            Serial.write(buf, 8); // 发送按键按下信号
        }
    }
    else if (buf[2] == 7) { // 当 D 键松开时
        releaseKey(); // 发送按键松开信号
    }

}

// 释放按键的函数
void releaseKey() {
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8); // 发送按键释放信号
}

// Function for Key Release

