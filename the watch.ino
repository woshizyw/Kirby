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

    // check A
    if (digitalRead(PIN_A) == HIGH) {
        if (buf[2] != 4) { 
            buf[2] = 4; // set A
            Serial.write(buf, 8); 
        }
    }
    else if (buf[2] == 4) { 
        releaseKey(); 
    }

    // check D
    if (digitalRead(PIN_D) == HIGH) {
        if (buf[2] != 7) { 
            buf[2] = 7; // Set
            Serial.write(buf, 8); 
        }
    }
    else if (buf[2] == 7) { // release D
        releaseKey(); // release
    }

}

// release
void releaseKey() {
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8); // send
}

// Function for Key Release



