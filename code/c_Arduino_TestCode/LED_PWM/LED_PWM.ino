int pin1 = 2;
int pin2 = 3;
int pin3 = 4;
int pin4 = 5;



void setup() {
  // put your setup code here, to run once:

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 0; i <= 255; i++){

    analogWrite(3, i);
    delay(1000);
        
  }

 
}
