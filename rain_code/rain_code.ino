
//define all LEDs 
int Row1 = 13;  //level 1
int Row2 = 12;  //level 2
int Row3 = 11;  //level 3



int Col1 = 10;
int Col2 = 9;
int Col3 = 8;

int Col4 = 7;
int Col5 = 6;
int Col6 = 5;


int Col7 = 4;
int Col8 = 3;
int Col9 = 2;



int rowmax = 3;
int colmax = 9;

int Col[9];
int Row[3];

void setup() {
  
  pinMode(Row1, OUTPUT); //Top
  pinMode(Row2, OUTPUT); //Middle
  pinMode(Row3, OUTPUT); //Bottom
  

  pinMode(Col1, OUTPUT); //Left
  pinMode(Col2, OUTPUT); //Middle
  pinMode(Col3, OUTPUT); //Right
  pinMode(Col4, OUTPUT); //Left
  pinMode(Col5, OUTPUT); //Middle
  pinMode(Col6, OUTPUT); //Right
  pinMode(Col7, OUTPUT); //Left
  pinMode(Col8, OUTPUT); //Middle
  pinMode(Col9, OUTPUT); //Right
  

  Col[0] = Col1;
  Col[1] = Col2;
  Col[2] = Col3;
  Col[3] = Col4;
  Col[4] = Col5;
  Col[5] = Col6;
  Col[6] = Col7;
  Col[7] = Col8;
  Col[8] = Col9;
  
  Row[0] = Row1;
  Row[1] = Row2;
  Row[2] = Row3;

}

void loop() {
  // put your main code here, to run repeatedly:
  
 rain();
 delay(100);
 rainMed();
 delay(100);
 rainHeavy();
 delay(100);
 lightning();
 delay(100);

 delay(300);
}

//functions to help perform animations

void lightning(){
    topPaneOn();
    bottomPaneOn();
    delay(25);
    topPaneOff();
    bottomPaneOff();
    delay(100);
    topPaneOn();
    bottomPaneOn();
    delay(25);
    topPaneOff();
    bottomPaneOff();
    topPaneOn();
    bottomPaneOn();
    delay(25);
    topPaneOff();
    bottomPaneOff();
    delay(100);
}
//Heavy rain

void rainHeavy(){
  int del = 80;
  int del2 = 60;
  randomSeed(analogRead(0)%10);
  //Serial.println("Analog input"); //testing
  //Serial.println(analogRead(0)%10); //testing
  for(int x= 0; x<50; x++){
    int stCol = random(0,colmax);
    int stCol2 = random(0,colmax);
    int stCol3 = random(0,colmax);
    int stCol4 = random(0,colmax);
    
    int dropNum = random(0,9);
    
    //Serial.println(dropNum); //testing

    for(int y=rowmax-1;y>-1;y--){
      if(y==rowmax-1) del2 = 80;  //if first row
      onLED(Row[y], Col[stCol]);
      if(dropNum>=4){
        onLED(Row[y], Col[stCol2]);
      }
      if(dropNum>=7){
        onLED(Row[y], Col[stCol3]);
      }
      if(dropNum>=8){
        onLED(Row[y], Col[stCol4]);
      }
      
      delay(del2);
      
      //turn off all even if they wern't turned on.
      offLED(Row[y], Col[stCol]);
      offLED(Row[y], Col[stCol2]);
      offLED(Row[y], Col[stCol3]);
      offLED(Row[y], Col[stCol4]);
      
      
      del2=30;
    }
    delay(del);

  }
}



//animate
//light rain
void rainLight(){
  int del = 170;
  int del2 = 70;
  
  for(int x= 0; x<20; x++){
    int stCol = random(0,colmax);

    for(int y=rowmax-1;y>-1;y--){
      if(y==rowmax-1) del2 = 110; 
      onLED(Row[y], Col[stCol]);
      delay(del2);
      offLED(Row[y], Col[stCol]);
      del2=70;
    }
    delay(del);

  }
}

//animate
//Medium rain
void rainMed(){
  int del = 70;
  int del2 = 35;
  
  for(int x= 0; x<25; x++){
    int stCol = random(0,colmax);

    for(int y=rowmax-1;y>-1;y--){
      if(y==rowmax-1) del2 = 85; 
      onLED(Row[y], Col[stCol]);
      delay(del2);
      offLED(Row[y], Col[stCol]);
      del2=35;
    }
    delay(del);

  }
}


//animate
//light rain
void rain(){
  int del = 150;
  int del2 = 50;
  
  for(int x= 0; x<40; x++){
    int stCol = random(0,colmax);

    for(int y=rowmax-1;y>-1;y--){
      if(y==rowmax-1) del2 = 90; 
      onLED(Row[y], Col[stCol]);
      delay(del2);
      offLED(Row[y], Col[stCol]);
      del2=50;
    }
    delay(del);

  }
}
void bottomPaneOn(){
    digitalWrite(Row3, HIGH);
    
    digitalWrite(Col1, HIGH);
    digitalWrite(Col2, HIGH);
    digitalWrite(Col3, HIGH);
    digitalWrite(Col4, HIGH);
    digitalWrite(Col5, HIGH);
    digitalWrite(Col6, HIGH);
    digitalWrite(Col7, HIGH);
    digitalWrite(Col8, HIGH);
    digitalWrite(Col9, HIGH);
}

void bottomPaneOff(){
    digitalWrite(Row3, LOW);
    
    digitalWrite(Col1, LOW);
    digitalWrite(Col2, LOW);
    digitalWrite(Col3, LOW);
    digitalWrite(Col4, LOW);
    digitalWrite(Col5, LOW);
    digitalWrite(Col6, LOW);
    digitalWrite(Col7, LOW);
    digitalWrite(Col8, LOW);
    digitalWrite(Col9, LOW);
}

void topPaneOn(){
    digitalWrite(Row1, HIGH);
    
    digitalWrite(Col1, HIGH);
    digitalWrite(Col2, HIGH);
    digitalWrite(Col3, HIGH);
    digitalWrite(Col4, HIGH);
    digitalWrite(Col5, HIGH);
    digitalWrite(Col6, HIGH);
    digitalWrite(Col7, HIGH);
    digitalWrite(Col8, HIGH);
    digitalWrite(Col9, HIGH);
}

void topPaneOff(){
    digitalWrite(Row1, LOW);
    
    digitalWrite(Col1, LOW);
    digitalWrite(Col2, LOW);
    digitalWrite(Col3, LOW);
    digitalWrite(Col4, LOW);
    digitalWrite(Col5, LOW);
    digitalWrite(Col6, LOW);
    digitalWrite(Col7, LOW);
    digitalWrite(Col8, LOW);
    digitalWrite(Col9, LOW);
}

//turn on LED based on row number and column number
void onLED(int row, int col){
  
  digitalWrite(row, HIGH); //turn on row
  digitalWrite(col, HIGH); //turn on col
  
}

//overload funtion - used to turn LED on with certain intensity
void onLED(int row, int col, int value){
  digitalWrite(row, HIGH); //turn on row
  analogWrite(col, value); //turn on col
}


//turn off LED based on row number and column number
void offLED(int row, int col){
  digitalWrite(row, LOW); //turn on row
  digitalWrite(col, LOW); //turn on col
}
