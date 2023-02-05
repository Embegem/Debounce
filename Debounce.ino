int inPin = 7; 
int outPin = 13; 
int state = HIGH; 
int reading; 
int previous = LOW; 
long time = 0; // the last time the output pin was toggled
long debounce = 200; // the debounce time, increase if the output flickers
void setup()
{
pinMode(inPin, INPUT);
pinMode(outPin, OUTPUT);
}
void loop()
{
reading = digitalRead(inPin);
if (reading == HIGH && previous == LOW && millis() - time > debounce) { // millis -time>200
if (state == HIGH){
state = LOW;}
else{
state = HIGH;}
// ... and remember when the last button press was
time = millis();
}
digitalWrite(outPin, state);
previous = reading;
}
