// Current Control using PWM technique
// for Mechanical Optical Beam Shutter
// www.fotonica.ifsc.usp.br
// André Romero - 2016
// andretec@ifsc.usp.br

// set pin numbers:
const int triggerPin = 2;     // the number of the trigger pin
const int shutterPin = 0;     // the number of the shutter pin
// variables will change:
int buttonState = 0;          // variable for reading the trigger

void setup() {
  // initialize the LED pin as an output:
  pinMode(shutterPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(triggerPin, INPUT);
  // set PWM 0%
  analogWrite(shutterPin, 0);  
}

void loop()
{
  // read the state of the trigger value:
  buttonState = digitalRead(triggerPin);

  // check if the trigger is on
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH)
    {     
      // turn LED on:    
      analogWrite(shutterPin, 255); // set PWM 100%
      delay(20);                    // delay 20ms
      analogWrite(shutterPin, 127); // set PWM 50%
      // wait until the trigger fall
      while (buttonState == HIGH)
        {
          // read the state of the trigger value:
          buttonState = digitalRead(triggerPin);
        }//while 
      analogWrite(shutterPin, 0); // set PWM 0%
    }//if
}//loop
