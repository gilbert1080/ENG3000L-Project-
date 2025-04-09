// Motor Driver 1 (Right Motors)
#define enA 10  // Enable Right Motors
#define in1 9   // Right Front Motor
#define in2 8   // Right Front Motor
#define in3 7   // Right Rear Motor
#define in4 6   // Right Rear Motor

// Motor Driver 2 (Left Motors)
#define enB 5   // Enable Left Motors
#define in5 4   // Left Front Motor
#define in6 3   // Left Front Motor
#define in7 2   // Left Rear Motor
#define in8 1   // Left Rear Motor

// IR Sensor Pin Definitions
#define R_S A0  // Right IR Sensor
#define L_S A1  // Left IR Sensor

void setup() {
    // Initialize IR sensors as inputs
    pinMode(R_S, INPUT);
    pinMode(L_S, INPUT);
    
    // Initialize motor driver pins as outputs
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    
    pinMode(enB, OUTPUT);
    pinMode(in5, OUTPUT);
    pinMode(in6, OUTPUT);
    pinMode(in7, OUTPUT);
    pinMode(in8, OUTPUT);
    
    // Set initial motor speed (range: 0 to 255)
    analogWrite(enA, 180);  // Speed for Right Motors
    analogWrite(enB, 180);  // Speed for Left Motors
    delay(1000);  // Short delay before the loop starts
}

void loop() {
    // Read sensor values (0 = white surface, 1 = black surface)
    bool rightSensor = digitalRead(R_S);
    bool leftSensor = digitalRead(L_S);
    
    // Line-following logic
    if (!rightSensor && !leftSensor) {  // Both sensors on white (stay on track)
        moveForward();
    } else if (rightSensor && !leftSensor) {  // Right sensor on black, left on white (correct by turning left)
        slightLeft();
    } else if (!rightSensor && leftSensor) {  // Left sensor on black, right on white (correct by turning right)
        slightRight();
    } else {  // Both sensors on black (off track or intersection)
        reverseSlightly(); 
    }
}

// Function to move forward
void moveForward() {
    analogWrite(enA, 180); // Set speed for right motors
    analogWrite(enB, 180); // Set speed for left motors

    digitalWrite(in1, HIGH); 
    digitalWrite(in2, LOW);  
    digitalWrite(in3, HIGH); 
    digitalWrite(in4, LOW);  
    
    digitalWrite(in5, HIGH); 
    digitalWrite(in6, LOW);  
    digitalWrite(in7, HIGH); 
    digitalWrite(in8, LOW);  
}

// Function for a slight left turn (reduce left speed)
void slightLeft() {
    analogWrite(enA, 180); // Right motors keep normal speed
    analogWrite(enB, 100); // Slow down left motors

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    digitalWrite(in7, HIGH);
    digitalWrite(in8, LOW);
}

// Function for a slight right turn (reduce right speed)
void slightRight() {
    analogWrite(enA, 100); // Slow down right motors
    analogWrite(enB, 180); // Left motors keep normal speed

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    digitalWrite(in7, HIGH);
    digitalWrite(in8, LOW);
}

// Function to reverse slightly when both sensors see black
void reverseSlightly() {
    analogWrite(enA, 150); 
    analogWrite(enB, 150); 

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    digitalWrite(in7, LOW);
    digitalWrite(in8, HIGH);

    delay(300); // Reverse for a short time
    stopMotors();
}

// Function to stop both motors
void stopMotors() {
    analogWrite(enA, 0);
    analogWrite(enB, 0);

    digitalWrite(in1, LOW);  
    digitalWrite(in2, LOW);  
    digitalWrite(in3, LOW);  
    digitalWrite(in4, LOW);  
    
    digitalWrite(in5, LOW);  
    digitalWrite(in6, LOW);  
    digitalWrite(in7, LOW);  
    digitalWrite(in8, LOW);  
}

V3 the function names need to be switched 

// Motor Driver 1 (Right Motors)
#define enA 10  // Enable Right Motors
#define in1 9   // Right Front Motor
#define in2 8   // Right Front Motor
#define in3 7   // Right Rear Motor
#define in4 6   // Right Rear Motor

// Motor Driver 2 (Left Motors)
#define enB 5   // Enable Left Motors
#define in5 4   // Left Front Motor
#define in6 3   // Left Front Motor
#define in7 2   // Left Rear Motor
#define in8 1   // Left Rear Motor

// IR Sensor Pin Definitions
#define R_S A0  // Right IR Sensor
#define L_S A1  // Left IR Sensor

void setup() {
    // Initialize IR sensors as inputs
    pinMode(R_S, INPUT);
    pinMode(L_S, INPUT);
    
    // Initialize motor driver pins as outputs
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    
    pinMode(enB, OUTPUT);
    pinMode(in5, OUTPUT);
    pinMode(in6, OUTPUT);
    pinMode(in7, OUTPUT);
    pinMode(in8, OUTPUT);
    
    // Set initial motor speed (range: 0 to 255)
    analogWrite(enA, 180);  // Speed for Right Motors
    analogWrite(enB, 180);  // Speed for Left Motors
    delay(1000);  // Short delay before the loop starts
}

void loop() {
    // Read sensor values (0 = white surface, 1 = black surface)
    bool rightSensor = digitalRead(R_S);
    bool leftSensor = digitalRead(L_S);
    
    // Line-following logic
    if (!rightSensor && !leftSensor) {  // Both sensors on white (stay on track)
        moveForward();
    } else if (rightSensor && !leftSensor) {  // Right sensor on black, left on white (correct by turning left)
        slightLeft();
    } else if (!rightSensor && leftSensor) {  // Left sensor on black, right on white (correct by turning right)
        slightRight();
    } else {  // Both sensors on black (off track or intersection)
        reverseSlightly(); 
    }
}

// Function to move forward
void moveForward() {
    analogWrite(enA, 180); // Set speed for right motors
    analogWrite(enB, 180); // Set speed for left motors

    digitalWrite(in1, HIGH); 
    digitalWrite(in2, LOW);  
    digitalWrite(in3, HIGH); 
    digitalWrite(in4, LOW);  
    
    digitalWrite(in5, HIGH); 
    digitalWrite(in6, LOW);  
    digitalWrite(in7, HIGH); 
    digitalWrite(in8, LOW);  
}

// Function for a slight left turn (reduce left speed)
void slightLeft() {
    analogWrite(enA, 180); // Right motors keep normal speed
    analogWrite(enB, 100); // Slow down left motors

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    digitalWrite(in7, HIGH);
    digitalWrite(in8, LOW);
}

// Function for a slight right turn (reduce right speed)
void slightRight() {
    analogWrite(enA, 100); // Slow down right motors
    analogWrite(enB, 180); // Left motors keep normal speed

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    digitalWrite(in7, HIGH);
    digitalWrite(in8, LOW);
}

// Function to reverse slightly when both sensors see black
void reverseSlightly() {
    analogWrite(enA, 150); 
    analogWrite(enB, 150); 

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    digitalWrite(in7, LOW);
    digitalWrite(in8, HIGH);

    delay(300); // Reverse for a short time
    stopMotors();
}

// Function to stop both motors
void stopMotors() {
    analogWrite(enA, 0);
    analogWrite(enB, 0);

    digitalWrite(in1, LOW);  
    digitalWrite(in2, LOW);  
    digitalWrite(in3, LOW);  
    digitalWrite(in4, LOW);  
    
    digitalWrite(in5, LOW);  
    digitalWrite(in6, LOW);  
    digitalWrite(in7, LOW);  
    digitalWrite(in8, LOW);  
}
