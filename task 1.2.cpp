//assign pins to pirsensor and led
const int detector = 2;
const int led = 4;

//initialise motion as 0 (no motion)
int motion = 0;

void setup()
{
  //initialise pir sensor as input, and led as outpu
  pinMode(2, INPUT);
  pinMode(4, OUTPUT);
  digitalWrite(detector, HIGH);
  
  //assign interrupt statement
  attachInterrupt(0,detect_motion, CHANGE);
  Serial.begin(9600);
}

void loop()
{
  
}

//detect_motion function
void detect_motion() {
  motion = digitalRead(detector);
  digitalWrite(led, !motion);
  
  //if motion is equal to 1 (motion detected)
  if(motion==1){
  	Serial.println("motion detected");
  }
}