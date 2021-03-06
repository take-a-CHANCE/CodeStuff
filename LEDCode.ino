//Pin Declarations
int red1=3;
int green1=5;
int blue1=6;

int red2=9;
int green2=10;
int blue2=11; 

int badLED = 13;

int strand;
int red;
int green;
int blue;

int slow;
int bright;
boolean getOut = true;

void setup() {
  //Yo set thos Pins default
  pinMode(red1, OUTPUT);
  pinMode(blue1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(blue2, OUTPUT);
  pinMode(green2, OUTPUT);
  
  pinMode(badLED, OUTPUT);
  
  analogWrite(red1, 0);
  analogWrite(blue1, 0);
  analogWrite(green1, 0);
  analogWrite(red2, 0);
  analogWrite(blue2, 0);
  analogWrite(green2, 0);
  
  digitalWrite(badLED, LOW);

  Serial.begin(115200);
  
  //Print Instructions
  Serial.println("                    INSTRUCTIONS");
  Serial.println("    (Strand#'s 1=1, 2=2, 3=1+2; max color values 255)");
  Serial.println("Solid color:  Strand#, Red Value, Green Value, Blue Value");
  Serial.println("Blink:        Strand#b, Delay Value, R, G, B");
  Serial.println("Fade:         Strand#f, Delay Value, Brightness");
  Serial.println("Clear:        Strand#c");
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>=2) {
    strand = Serial.parseInt();
    switch( Serial.read()) {
      case 'f':
        slow=Serial.parseInt();
        bright=Serial.parseInt();
        if (Serial.read() == '\n')
          rainbowFade(strand,slow,bright);
        getOut = false;
        break;
      case 'c':
        //if (Serial.read() == '\n')
          setColor(strand,0,0,0);
        break;
      case 'b':
        getOut = false;
        slow=Serial.parseInt();
        red = Serial.parseInt();
        green = Serial.parseInt();
        blue = Serial.parseInt();
        if (Serial.read() == '\n')
          blinky(strand,slow,red,green,blue);
        break;  
      case ',':
        red = Serial.parseInt();
        green = Serial.parseInt();
        blue = Serial.parseInt();
        if (Serial.read() == '\n')
          setColor(strand,red,green,blue);
        break;
      default:
        digitalWrite(badLED,HIGH);
        break;
    }
    delay(20);
    Serial.flush();
  }
  
}

void setColor(int s, int r , int g, int b) {
  if (s == 1) {
    analogWrite(red1, r);
    analogWrite(green1, g);
    analogWrite(blue1, b);
    digitalWrite(badLED, LOW);
  }
  else if (s == 2) {
    analogWrite(red2, r);
    analogWrite(green2, g);
    analogWrite(blue2, b);
    digitalWrite(badLED, LOW);
  }
  else if (s == 3) {
    analogWrite(red1, r);
    analogWrite(green1, g);
    analogWrite(blue1, b);
    analogWrite(red2, r);
    analogWrite(green2, g);
    analogWrite(blue2, b);
    digitalWrite(badLED, LOW);
  }
  else 
    digitalWrite(badLED, HIGH);
}


void blinky(int s, int delayVal, int r, int g, int b) {
   while(getOut!=true) {
     setColor(s,r,g,b);
     delay(delayVal);
     if (Serial.available()>0){
       getOut=true;
       break;
     }
     setColor(s,0,0,0);
     delay(.75*delayVal);
     if (Serial.available()>0){
       getOut=true;
       break;
     }
   }
}

int largest(int one,int two,int three) {
  if(one>=two && one>=three) {
   return one;
  }
  else if (two>=one && two>=three) {
    return two;
  }
  else if (three>=two && three>=one) {
    return three;
  }
  
}

void fade(int strand, int delayVal, int r1, int g1, int b1, int r2, int g2, int b2) {
  setColor(strand,r1,g1,b1);
  delay(delayVal);
  
}

void rainbowFade(int strand, int delayVal, int brightness){
   int r, g, b;
   constrain(brightness, 1,255);
   while(getOut!=true){
     if (Serial.available()>0){
       getOut=true;
       break;
     }
     if (strand==1){
       
      // fade from blue to violet
      for (r = 0; r <= brightness; r++) { 
        analogWrite(red1, r);
        delay(delayVal);
      }
     if (Serial.available()>0){
       getOut=true;
       break;
     } 
      // fade from violet to red
      for (b = brightness; b >= 0; b--) { 
        analogWrite(blue1, b);
        delay(delayVal);
      } 
      if (Serial.available()>0){
       getOut=true;
       break;
     }
      // fade from red to yellow
      for (g = 0; g <= brightness; g++) { 
        analogWrite(green1, g);
        delay(delayVal);
      } 
      if (Serial.available()>0){
       getOut=true;
       break;
     }
      // fade from yellow to green
      for (r = brightness; r >= 0; r--) { 
        analogWrite(red1, r);
        delay(delayVal);
      } 
      if (Serial.available()>0){
       getOut=true;
       break;
     }
      // fade from green to teal
      for (b = 0; b <= brightness; b++) { 
        analogWrite(blue1, b);
        delay(delayVal);
      } 
      if (Serial.available()>0){
       getOut=true;
       break;
     }
      // fade from teal to blue
      for (g = brightness; g >= 0; g--) { 
        analogWrite(green1, g);
        delay(delayVal);
      } 
      if (Serial.available()>0){
       getOut=true;
       break;
     }
     }
     else if (strand==2){
   
      // fade from blue to violet
      for (r = 0; r <= brightness; r++) { 
        analogWrite(red2, r);
        delay(delayVal);
      } 
      if (Serial.available()>0){
       getOut=true;
       break;
     }
      // fade from violet to red
      for (b = brightness; b >= 0; b--) { 
        analogWrite(blue2, b);
        delay(delayVal);
      } 
      if (Serial.available()>0){
       getOut=true;
       break;
     }
      // fade from red to yellow
      for (g = 0; g <= brightness; g++) { 
        analogWrite(green2, g);
        delay(delayVal);
      } 
      if (Serial.available()>0){
       getOut=true;
       break;
     }
      // fade from yellow to green
      for (r = brightness; r >= 0; r--) { 
        analogWrite(red2, r);
        delay(delayVal);
      } 
      if (Serial.available()>0){
       getOut=true;
       break;
     }
      // fade from green to teal
      for (b = 0; b <= brightness; b++) { 
        analogWrite(blue2, b);
        delay(delayVal);
      } 
      if (Serial.available()>0){
       getOut=true;
       break;
     }
      // fade from teal to blue
      for (g = brightness; g >= 0; g--) { 
        analogWrite(green2, g);
        delay(delayVal);
      } 
      if (Serial.available()>0){
       getOut=true;
       break;
     }
     }
     else if (strand==3){
   
      // fade from blue to violet
      for (r = 0; r <= brightness; r++) { 
        analogWrite(red1, r);
        analogWrite(red2, r);
        delay(delayVal);
      } 
      if (Serial.available()>0){
       getOut=true;
       break;
     }
      // fade from violet to red
      for (b = brightness; b >= 0; b--) { 
        analogWrite(blue1, b);
        analogWrite(blue2, b);
        delay(delayVal);
      } 
      if (Serial.available()>0){
       getOut=true;
       break;
     }
      // fade from red to yellow
      for (g = 0; g <= brightness; g++) { 
        analogWrite(green1, g);
        analogWrite(green2, g);
        delay(delayVal);
      } 
      if (Serial.available()>0){
       getOut=true;
       break;
     }
      // fade from yellow to green
      for (r = brightness; r >= 0; r--) { 
        analogWrite(red1, r);
        analogWrite(red2, r);
        delay(delayVal);
      } 
      if (Serial.available()>0){
       getOut=true;
       break;
     }
      // fade from green to teal
      for (b = 0; b <=brightness; b++) { 
        analogWrite(blue1, b);
        analogWrite(blue2, b);
        delay(delayVal);
      } 
      if (Serial.available()>0){
       getOut=true;
       break;
     }
      // fade from teal to blue
      for (g = brightness; g >= 0; g--) { 
        analogWrite(green1, g);
        analogWrite(green2, g);
        delay(delayVal);
      } 
     }
     if (Serial.available()>0){
       getOut=true;
       break;
     }
   }
}

