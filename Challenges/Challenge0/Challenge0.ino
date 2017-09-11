/* sketch 1 
turn on a LED when the button is pressed
*/
int pushButton1 = 8; //the pin where we connect the button
int pushButton2 = 9; //the pin where we connect the button
int stateButton = 0;
int stateButton2 = 0;
int LEDG = 2; //the pin we connect the LED
int LEDY = 3; //the pin we connect the LED
int LEDR = 4; //the pin we connect the LED
int count = 0; 
unsigned long previousMillis = 0;
const long interval = 1000;
unsigned long t = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton1, INPUT); //set the button as INPUT
  pinMode(pushButton2, INPUT); //set the button as INPUT
  pinMode(LEDG, OUTPUT); //set the LED pin as OUTPUT
  pinMode(LEDY, OUTPUT); //set the LED pin as OUTPUT
  pinMode(LEDR, OUTPUT); //set the LED pin as OUTPUT
}
  
void loop() {
  stateButton = digitalRead(pushButton1); //read the state of the button 1
  stateButton2 = digitalRead(pushButton2); //read the state of the button 2
  int kick = 0;
//-----------------------------------------------  
  if (stateButton == 1) {
    delay(100);      //wait so you dont read bouncing effects (milliseconds)
    stateButton = digitalRead(pushButton1); //read the state of the button
    if (stateButton == 0){
      if (count == 0) {
        count = count + 1;
        digitalWrite(LEDR,HIGH);
        digitalWrite(LEDY,LOW);
        digitalWrite(LEDG,LOW);
        delay(10);
      } else if (count == 1 ) {
        count = count + 1;
        digitalWrite(LEDY,HIGH);
        digitalWrite(LEDG,LOW);
        digitalWrite(LEDR,LOW);
        delay(10);
      } else if (count > 1) {
        count = 0;
        digitalWrite(LEDG,HIGH);
        digitalWrite(LEDY,LOW);
        digitalWrite(LEDR,LOW);
        delay(10);
      }
      else {  // FAULT, SOMETHING WENT WRONG!
        count = 0;
        digitalWrite(LEDR,HIGH);
        digitalWrite(LEDY,HIGH);
        digitalWrite(LEDR,HIGH);
      }
      
    }
  }
//-----------------------------------------------
  if (stateButton2 == 1) {
    delay(50);      //wait so you dont read bouncing effects (milliseconds)
    stateButton2 = digitalRead(pushButton2); //read the state of the button
    if(stateButton2 == 0){
      while ( kick == 0) {
        t = millis() + interval;
        //Serial.println(t);
        digitalWrite(LEDR,HIGH);
        digitalWrite(LEDY,LOW);
        digitalWrite(LEDG,LOW);
        while ( millis()<t) {
          if(digitalRead(pushButton2) == 1) {
            kick = 1;
            //break;
          }
        }
        digitalWrite(LEDR,LOW);
        digitalWrite(LEDY,HIGH);
        t = millis() + interval;
        while ( millis()<t) {
          if(digitalRead(pushButton2) == 1) {
            kick = 1;
            //break;
          }
        }
        digitalWrite(LEDY,LOW);
        digitalWrite(LEDG,HIGH);
        delay(1000); 
        while ( millis()<t) {
          if(digitalRead(pushButton2) == 1) {
            kick = 1;
            //break;
          }
        }
        
      }
    }
  }
  //Serial.println(kick);
  //Serial.println(count);
  
}
