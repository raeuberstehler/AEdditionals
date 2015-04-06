/* =================================================================================
Author: 2015 Matt Maurer  / 2011 ScottC
 http://arduinobasics.blogspot.ch/2011/06/arduino-uno-photocell-sensing-light.html
 http://www.raeuberundstehler.com
Description: This sketch will allow you to receive data from 6 individual
             photo-resistors. The sketch auto-adjusts to the ambient light and maps
             them to values from 0-100 thanks to ScottC's fabulous example. You
             can further set a divider-value which translates the results into binary 
             on/off button-states. We use it as a way to
==================================================================================== */


const int photoRPin[] = {0, 1, 2, 3, 4};
int pinCount = 5; //Anzahl Pins
int minLight[] ={0, 0, 0, 0, 0};
int maxLight[] ={0, 0, 0, 0, 0};
int lightLevel[] ={0, 0, 0, 0, 0};
int adjustedLightLevel[] ={0, 0, 0, 0, 0};
int buttonstate[] ={0, 0, 0, 0, 0};

int divider = 15; //divider-value: 0-15 => 1 / 15-100 =>0
int settingminimum = 20;



void setup() {
  Serial.begin(9600);
  for (int thisPin = 0; thisPin < pinCount; thisPin++)  {
    pinMode(photoRPin[thisPin], OUTPUT);
    lightLevel[thisPin] = analogRead(photoRPin[thisPin]);
    minLight[thisPin] = lightLevel[thisPin] - settingminimum;
    maxLight[thisPin] = lightLevel[thisPin];
  }
}

void loop(){
  //auto-adjust the minimum and maximum limits in real time
  for (int thisPin = 0; thisPin < pinCount; thisPin++)  {
    lightLevel[thisPin] = analogRead(photoRPin[thisPin]);
    if(minLight[thisPin] > lightLevel[thisPin]){
      minLight[thisPin] = lightLevel[thisPin];
    }
    if(maxLight[thisPin] < lightLevel[thisPin]){
      maxLight[thisPin] = lightLevel[thisPin];
    }
    if(adjustedLightLevel[thisPin] < divider){
      buttonstate[thisPin] = 1;
    }
    else{
      buttonstate[thisPin] = 0;
    } 
    adjustedLightLevel[thisPin] = map(lightLevel[thisPin], minLight[thisPin], maxLight[thisPin], 0, 100);
    Serial.print(adjustedLightLevel[thisPin]);
    Serial.print(" / ");
    Serial.print(buttonstate[thisPin]);
    Serial.print("    ");
  }

  Serial.println("");

  //slow down the transmission for effective Serial communication.
  delay(50);
}



