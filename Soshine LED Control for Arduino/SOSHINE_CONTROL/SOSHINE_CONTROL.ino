 /* (c) 2015 HYPERWERK - Matt Maurer
www.raeuberundstehler.com */
 
  int ledPin = 9; // INPUT PWM TO TOUCHPANEL
  int ledV = 0;   // LED Inputvoltage (5V) @ PIN 0
  
  
  void setup()
  {
    pinMode(ledPin, OUTPUT); 
    pinMode(ledV, OUTPUT);
  }
  
  
  void loop()
  {
   digitalWrite(ledV, HIGH);   // LED POWER ON (5V)
      delay(1000);             // gives the LED-Chip enough time to get ready
   analogWrite(ledPin, 150);   // PWM (0-255)
      delay(10000);            // Dimming to highest value (min 3000)
   digitalWrite(ledV, LOW);    // LED POWER OFF (0V)
   pinMode(ledPin, INPUT);     // Turning PWM OFF
     delay(100);               // gives the LED-Chip enough time to register disconnect

  }
