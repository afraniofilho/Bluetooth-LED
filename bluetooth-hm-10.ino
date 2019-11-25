char appData;  
String inData = "";

void setup() { 
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(7, OUTPUT);
}

void loop() { 
  char c;
  if (Serial.available()) {
    c = Serial.read();
    Serial1.print(c);
    Serial.print(c);
  }
  if (Serial1.available()) {
    appData = Serial1.read();
    inData = String(appData);  // save the data in string format
    
    if (inData == "N")
      {
        digitalWrite(7, HIGH);
      }
    else if (inData == "F")
      {
        digitalWrite(7, LOW);
      }
    Serial.print(inData);   
  }
}
