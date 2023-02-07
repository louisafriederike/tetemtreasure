long light = 0;

void setup() {
    pinMode(A0,INPUT); 
    Serial.begin(9600);
}

void loop() {
    light = 0;
    light += analogRead(A0); 
    delay(0.5); 
    Serial.println(light);
}
