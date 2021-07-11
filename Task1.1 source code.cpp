//initialise temperatures
int baselineTemperature = 0;
int fahrenheit = 0;
int celsius = 0;

void setup()
{
  //initialise temperature as A3 input
  pinMode(A3, INPUT);
  Serial.begin(9600);

  //initialise led as digital 4 output
  pinMode(4, OUTPUT);
}

void loop()
{
  //choose baseline temp
  baselineTemperature = 20;
  
  //calibrate celsius
  celsius = map(((analogRead(A3) - 20) * 3.04), 0, 1023, -40, 125);
  
  //convert between celsius and farenheit
  fahrenheit = ((celsius * 9) / 5 + 32);
  Serial.print(celsius);
  Serial.print("C, ");
  Serial.print(fahrenheit);
  Serial.println("F");
  
  //if temperature is below baseline, turn led off
  if (celsius < baselineTemperature){
    digitalWrite(4, LOW);
  }
  //if temperature if above baseline, turn led on
  if (celsius >= baselineTemperature) {
    digitalWrite(4, HIGH);
  }

  //delay the input reading
  delay(1000); 
}