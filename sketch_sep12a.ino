//reading pins
int leftReading;
int rightReading;
int leftReadingPin = 2;
int rightReadingPin = 3;
//motor pins
int m1a = 6;
int m1b = 7;
int m2a = 4;
int m2b = 5;
int start;

bool reversed;

//blue is left 
//yellow is right

void setup() {
  // put your setup code here, to run once:
  pinMode(leftReadingPin, INPUT);
  pinMode(rightReadingPin, INPUT);
  
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  
  Serial.begin(9600);
}


void moveForward(){
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
}

void fullStop(){
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
}

//duration in milliseconds
void reverse(int duration){
 start = millis();
 while((millis() - start) < duration) {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH);
  }
  fullStop();
}


void loop() {
  // put your main code here, to run repeatedly:
  leftReading = not digitalRead(leftReadingPin);
  rightReading = not digitalRead(rightReadingPin);

  if (leftReading == 0 && reversed == false){
    moveForward();
  } else if (leftReading == 1 && reversed == false){
    fullStop();
    delay(1000);
    reverse(500);
    reversed = true;
  }
}
