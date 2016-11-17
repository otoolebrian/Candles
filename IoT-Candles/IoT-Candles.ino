/*
Adafruit Arduino - Lesson 3. RGB LED
*/

int redPin = 9;
int greenPin = 10;
int bluePin = 11;


//Global Variable for the delay time, so that everything
//fades in and out at the same rate
int delayTime = 10;

//Global RGB variables to allow the candles to return
//to the prior color
int red = 170;
int green = 170;
int blue = 170;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  

  setColor(red,green,blue);
  delay(20);
}

void loop()
{
  /*setColor(255, 0, 0);  // red
  delay(1000);
  setColor(0, 255, 0);  // green
  delay(1000);
  setColor(0, 0, 255);  // blue
  delay(1000);
  setColor(255, 255, 0);  // yellow
  delay(1000);  
  setColor(80, 0, 80);  // purple
  delay(1000);
  setColor(0, 255, 255);  // aqua
  delay(1000);
  setColor(0, 0xff, 0); //Green
  delay(1500);
  setColor(255, 255, 255); //White
  delay(1500);
  setColor(0xFF, 0xdd, 0x00); //Orange 
  delay(1500);*/

  flicker();

  
}

//Function to create flickering effect for the candles
//This is the default state
void flicker()
{
  //setColor(red,green,blue);
  
  setColor(random(60)+190, random(120)+135,random(120)+135);
  delay(random(150));
}

//Function to fade in Green White and Orange
//Runs once, returns nothing
void IrishFlag()
{
  
  //Green
  for(int i=0; i< 255; i++)
  {
    setColor(0,i,0);
    delay(delayTime);
  }

  
  for(int i=255; i>0; i--)
  {
    setColor(0,i,0);
    delay(delayTime);
  } 

  //White
  for(int i=0; i< 255; i++)
  {
    setColor(i,i,i);
    delay(delayTime);
  }

  
  for(int i=255; i>0; i--)
  {
    setColor(i,i,i);
    delay(delayTime);
  } 

  
  //Orange

  //HEX code for orange is FFA500
  //Ratio is 1:.64:0

  int greenVal = 0;
  
  for(int i=0; i< 255; i++)
  {
    //Create a value for green that is .64 of the value for
    //red; this allows orange to fade in smoothly
    greenVal = i * .64;
    setColor(i, greenVal, 0x00);
    delay(delayTime);
  }

  
  for(int i=255; i>0; i--)
  {
    greenVal = i * .64;
    setColor(i, greenVal, 0x00);
    delay(delayTime);
  }  


   //Go back to the default color
   setColor(red,green,blue);
}



void setColor(int red, int green, int blue)
{

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
