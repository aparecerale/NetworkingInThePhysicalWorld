// Demonstrate hardware implemented debouncer and software implemented debouncer

int pushButton1 = 8; //the pin where we connect the button
int pushButton2 = 9; //the pin where we connect the button
int LEDR = 4; //the pin we connect the LED

int stateButton1 = 0;
int stateButton2 = 0;
long lDebounceTime = 0;
long debounceDelay = 200; // this is for a bouncy button
                          // it usually is 50 -100
void setup() {
  Serial.begin(9600);
  pinMode(pushButton1, INPUT);
  pinMode(pushButton2, INPUT);
  pinMode(LEDR, OUTPUT);
}

void loop(){
  stateButton1 = digitalRead(pushButton1); //read the state of the button 1

  // The first push botton has a hardware debouncer
  // 5V series 1kohm switch node + 1uF to ground
  // pull down in the other side of the switch
  
  if (stateButton1 == 1) {
    Serial.println("BANG!");
  }

  // Software debouncer
  // 1 read high, add delay and read zero
  // this means it went full cycle up and down
  stateButton2 = digitalRead(pushButton2); //read the state of the button 2
  /*
  if (stateButton2 == 1) {
    delay(50);
    stateButton2 = digitalRead(pushButton2); //read the state of the button 2
    if (stateButton2 == 0) {
      Serial.println("BOM!");
    }
  } */

  //Software Debounce 2
  //filter out noise 
  if ( (millis() - lDebounceTime) > debounceDelay) {
    // if state is still the same after first push then its a high
    if (stateButton2 == 1){ 
      Serial.println("BAM");
      lDebounceTime = millis();
    }
    
  }
  
}

