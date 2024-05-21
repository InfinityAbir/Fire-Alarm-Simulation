#define flamePin A0
#define gasPin A1
#define buzzer1 10
#define
  buzzer2 9
#define greenLed 2
#define redLed 3
int flameVal;
int gasVal;
int
  btSwitch=49;
unsigned long curTime;
void(* resetFunc) (void) = 0;

void
  setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(greenLed,
  OUTPUT);
  pinMode(redLed, OUTPUT);
  curTime=millis();
}

void loop()
  {
    // put your main code here, to run repeatedly:
   if(Serial.available()
  > 0){ // Checks whether data is comming from the serial port
      btSwitch =
  Serial.read(); // Reads the data from the serial port
   }
   if(btSwitch=='1'){digitalWrite(greenLed,HIGH);digitalWrite(redLed,LOW);}

   else if(btSwitch=='0'){digitalWrite(redLed,HIGH);digitalWrite(greenLed,LOW);}

   else if(btSwitch=='2'){resetFunc();}
   
   flameVal=analogRead(flamePin);

   gasVal=analogRead(gasPin);
   
   if (flameVal<1000 && gasVal>159 && btSwitch=='1'){

     buzzerCall();
   }
   else if(gasVal>159 && btSwitch=='1'){
     buzzerCall();

   }
}

void buzzerCall(){
    digitalWrite(greenLed,LOW);
    digitalWrite(redLed,HIGH);

    tone(buzzer1, 5000);
    delay(1000);
    noTone(buzzer1);
    tone(buzzer2,
  1000);
    digitalWrite(redLed,LOW);
    delay(1000);
    noTone(buzzer2);

  }
