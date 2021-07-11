int baselineTemperature = 0;
int fahrenheit = 0;
int celsius = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(4, OUTPUT);
}

void loop()
{
  baselineTemperature = 20;
  
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
  fahrenheit = ((celsius * 9) / 5 + 32);
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");
  
  if (celsius < baselineTemperature){ 
    digitalWrite(4, LOW);
  }
  if (celsius >= baselineTemperature) {
    digitalWrite(4, HIGH);
  }

  delay(1000); 
}