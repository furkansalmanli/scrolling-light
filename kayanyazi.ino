int delayTime = 40;    // A variable to set a delay time between each LED
int currentLED = 3;     // A variable to store which LED we are currently working on
int dir = 1;    // A variable to store the direction of travel
long timeChanged = 0;     // A variable to store the last time we changed something
byte ledPin[] = {3,4, 5, 6, 7, 8, 9};      // An array to hold the value for each LED pin
void setup() {
for (int i=0; i<7; i++) {// Set all pins for OUTPUT
pinMode(ledPin[i], OUTPUT);
}
timeChanged = millis();    // Record the time once the setup has completed
}
void loop() {
if ((millis() - timeChanged) > delayTime) {     // Check whether it has been long enough
for (int i=0; i<7; i++) {    //turn off all of the LEDs
digitalWrite(ledPin[i], LOW);
}
digitalWrite(ledPin[currentLED], HIGH);    // Light the current LED
currentLED = currentLED + dir;      // Increase the direction value (up or down)
if (currentLED == 7) {       // If we are at the end of a row, change direction
dir = -1;
}
if (currentLED == 0) {
dir = 1;
}
timeChanged = millis();     // store the current time as the time we last changed LEDs
}
}

