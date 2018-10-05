
#include <time.h>

int MODE = 2;
int RCLK = 3;
int SRCLK = 12;
int ENGND1 = 4;
int ENGND2 = 5;
int ENGND3 = 6;
int ENGND4 = 7;
int SER = 9;
volatile int modeNum = 0;
int count = 0;
int DELAY = 1;
int NUMMODES = 5;


void setup() {
  Serial.begin(115200);
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(ENGND1, OUTPUT);
  pinMode(ENGND2, OUTPUT);
  pinMode(ENGND3, OUTPUT);
  pinMode(ENGND4, OUTPUT);
  digitalWrite(SRCLK, LOW);
  digitalWrite(RCLK, LOW);
  digitalWrite(SER, LOW);
  attachInterrupt(digitalPinToInterrupt(MODE), changeMode, RISING);
}

/************************************************
 * OUTER SQUARE
 * lights up only the LEDs on the outer square.
 ***********************************************/
void outerSquare()
{
  while(count < 16)
  {
    switch(count)
    {
    case 0:
    {
      digitalWrite(SER, HIGH);
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 5:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 6:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 9:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 10:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    default:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
  
    }
    digitalWrite(SRCLK, HIGH);
    digitalWrite(SRCLK, LOW);
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
    if(count == 0)
      digitalWrite(SER, LOW);

    delay(DELAY);

    count++;
 
    digitalWrite(ENGND1, LOW);
    digitalWrite(ENGND2, LOW);
    digitalWrite(ENGND3, LOW);
    digitalWrite(ENGND4, LOW);
  }
  count = 0;
}

void innerSquare()
{
    while(count < 16)
  {
    switch(count)
    {
    case 0:
    {
      digitalWrite(SER, HIGH);
      break;
    }
    case 5:
    {
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      break;
    }
    case 6:
    {
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      break;
    }
    case 9:
    {
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      break;
    }
    case 10:
    {
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      break;
    }
    default:
    {
      break;
    }
  
    }
    digitalWrite(SRCLK, HIGH);
    digitalWrite(SRCLK, LOW);
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
    if(count == 0)
      digitalWrite(SER, LOW);

    delay(DELAY);

    count++;
 
    digitalWrite(ENGND1, LOW);
    digitalWrite(ENGND2, LOW);
    digitalWrite(ENGND3, LOW);
    digitalWrite(ENGND4, LOW);
  }
  count = 0;
}

/************************************************
 * TWO AND FOUR
 * lights up layers two and four.
 ***********************************************/
void twoAndFour()
{
    while(count < 16)
  {
    switch(count)
    {
    case 0:
    {
      digitalWrite(SER, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    default:
    {
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
  
    }
    digitalWrite(SRCLK, HIGH);
    digitalWrite(SRCLK, LOW);
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
    if(count == 0)
      digitalWrite(SER, LOW);

    delay(DELAY);

    count++;
    
    digitalWrite(ENGND2, LOW);
    digitalWrite(ENGND4, LOW);
  }
  count = 0;
}

/************************************************
 * ONE AND THREE
 * lights up layers one and three.
 ***********************************************/
void oneAndThree()
{
    while(count < 16)
  {
    switch(count)
    {
    case 0:
    {
      digitalWrite(SER, HIGH);
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND3, HIGH);
      break;
    }
    default:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND3, HIGH);
      break;
    }
  
    }
    digitalWrite(SRCLK, HIGH);
    digitalWrite(SRCLK, LOW);
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
    if(count == 0)
      digitalWrite(SER, LOW);

    delay(DELAY);

    count++;
 
    digitalWrite(ENGND1, LOW);
    digitalWrite(ENGND3, LOW);
  }
  count = 0;
}

void sideOne()
{
    while(count < 16)
  {
    switch(count)
    {
    case 0:
    {
      digitalWrite(SER, HIGH);
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 1:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 2:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 3:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    default:
    {
      break;
    }
  
    }  digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(SRCLK, HIGH);
    digitalWrite(SRCLK, LOW);
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
    if(count == 0)
      digitalWrite(SER, LOW);

    delay(DELAY);

    count++;
 
    digitalWrite(ENGND1, LOW);
    digitalWrite(ENGND2, LOW);
    digitalWrite(ENGND3, LOW);
    digitalWrite(ENGND4, LOW);
  }
  count = 0;
}

void sideTwo()
{
      while(count < 16)
  {
    switch(count)
    {
    case 0:
    {
      digitalWrite(SER, HIGH);
      break;
    }
    case 4:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 5:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 6:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 7:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    default:
    {
      break;
    }
  
    }
    digitalWrite(SRCLK, HIGH);
    digitalWrite(SRCLK, LOW);
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
    if(count == 0)
      digitalWrite(SER, LOW);

    delay(DELAY);

    count++;
 
    digitalWrite(ENGND1, LOW);
    digitalWrite(ENGND2, LOW);
    digitalWrite(ENGND3, LOW);
    digitalWrite(ENGND4, LOW);
  }
  count = 0;
}

void sideThree()
{
      while(count < 16)
  {
    switch(count)
    {
    case 0:
    {
      digitalWrite(SER, HIGH);
      break;
    }
    case 8:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 9:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 10:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 11:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    default:
    {
      break;
    }
  
    }
    digitalWrite(SRCLK, HIGH);
    digitalWrite(SRCLK, LOW);
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
    if(count == 0)
      digitalWrite(SER, LOW);

    delay(DELAY);

    count++;
 
    digitalWrite(ENGND1, LOW);
    digitalWrite(ENGND2, LOW);
    digitalWrite(ENGND3, LOW);
    digitalWrite(ENGND4, LOW);
  }
  count = 0;
}

void sideFour()
{
      while(count < 16)
  {
    switch(count)
    {
    case 0:
    {
      digitalWrite(SER, HIGH);
      break;
    }
    case 12:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 13:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 14:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 15:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    default:
    {
      break;
    }
  
    }
    digitalWrite(SRCLK, HIGH);
    digitalWrite(SRCLK, LOW);
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
    if(count == 0)
      digitalWrite(SER, LOW);

    delay(DELAY);

    count++;
 
    digitalWrite(ENGND1, LOW);
    digitalWrite(ENGND2, LOW);
    digitalWrite(ENGND3, LOW);
    digitalWrite(ENGND4, LOW);
  }
  count = 0;
}

void sideRight()
{
      while(count < 16)
  {
    switch(count)
    {
    case 0:
    {
      digitalWrite(SER, HIGH);
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 4:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 8:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 12:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    default:
    {
      break;
    }
  
    }
    digitalWrite(SRCLK, HIGH);
    digitalWrite(SRCLK, LOW);
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
    if(count == 0)
      digitalWrite(SER, LOW);

    delay(DELAY);

    count++;
 
    digitalWrite(ENGND1, LOW);
    digitalWrite(ENGND2, LOW);
    digitalWrite(ENGND3, LOW);
    digitalWrite(ENGND4, LOW);
  }
  count = 0;
}

void sideLeft()
{
      while(count < 16)
  {
    switch(count)
    {
    case 0:
    {
      digitalWrite(SER, HIGH);
      break;
    }
    case 3:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 7:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 11:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    case 15:
    {
      digitalWrite(ENGND1, HIGH);
      digitalWrite(ENGND2, HIGH);
      digitalWrite(ENGND3, HIGH);
      digitalWrite(ENGND4, HIGH);
      break;
    }
    default:
    {
      break;
    }
  
    }
    digitalWrite(SRCLK, HIGH);
    digitalWrite(SRCLK, LOW);
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
    if(count == 0)
      digitalWrite(SER, LOW);

    delay(DELAY);

    count++;
 
    digitalWrite(ENGND1, LOW);
    digitalWrite(ENGND2, LOW);
    digitalWrite(ENGND3, LOW);
    digitalWrite(ENGND4, LOW);
  }
  count = 0;
}

void oneLED(int num, int num2)
{
  int led = num2 + 4;
  while(count < 16)
  {
    if(count == 0)
    {
      digitalWrite(SER, HIGH);
    }
    if(count == num)
    {
      digitalWrite(led, HIGH);
      break;
    }
    count++;
    digitalWrite(led, LOW);
  }
  count = 0;
}

/****************************************
 * CHANGE MODE
 * changes the mode that the cube is on
 ***************************************/
void changeMode()
{
  modeNum = (modeNum + 1) % NUMMODES;
}

/**************************************
 * loop
 * switches through the different 
 * patterns.
 *************************************/
void loop() 
{
  switch(modeNum)
  {
    case 0:
    {
      for(int i = 0; i < 100; i++)
      {
        outerSquare();
      }
      for(int i = 0; i < 100; i++)
      {
        innerSquare();
      }
      break;
    }
    case 1:
    {
      for(int i = 0; i < 50; i++)
      {
        twoAndFour();
      }
      for(int i = 0; i < 50; i++)
      {
        oneAndThree();
      }
      break;
    }
    case 2:
    {
      for(int i = 0; i < 30; i++)
      {
        sideOne();
      }
      for(int i = 0; i < 30; i++)
      {
        sideTwo();
      }
      for(int i = 0; i < 30; i++)
      {
        sideThree();
      }
      for(int i = 0; i < 30; i++)
      {
        sideFour();
      }
      break;
    }
    case 3:
    {
      for(int i = 0; i < 30; i++)
      {
        sideOne();
      }
      for(int i = 0; i < 30; i++)
      {
        sideTwo();
      }
      for(int i = 0; i < 30; i++)
      {
        sideThree();
      }
      for(int i = 0; i < 30; i++)
      {
        sideFour();
      }
      for(int i = 0; i < 30; i++)
      {
        sideThree();
      }
      for(int i = 0; i < 30; i++)
      {
        sideTwo();
      }
      break;
    }
    case 4:
    {
      for(int i = 0; i < 30; i++)
      {
        sideOne();
      }
      for(int i = 0; i < 30; i++)
      {
        sideRight();
      }
      for(int i = 0; i < 30; i++)
      {
        sideFour();
      }
      for(int i = 0; i < 30; i++)
      {
        sideLeft();
      }
      break;
    }
    case 5:
    {
      int num = rand() % 16;
      int num2 = rand() % 4;
      for(int i = 0; i < 50; i++)
      {
        oneLED(num, num2);
      }
      break;
    }
  }
}
