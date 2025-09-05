#include <RH_ASK.h>
#include<SPI.h>

#define lf 5
#define lb 6
#define rb 7
#define rf 8

#define ls 3
#define rs 4



RH_ASK rx;

void setup()
{
  Serial.begin(9600);

  rx.init();

  pinMode(lf , OUTPUT);
  pinMode(lb , OUTPUT);
  pinMode(rf , OUTPUT);
  pinMode(rb , OUTPUT);
  pinMode(ls , OUTPUT);
  pinMode(rs , OUTPUT);
/*
  analogWrite(ls,150);
  analogWrite(rs , 150);
  */
}


void loop()
{
    uint8_t buf[1];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rx.recv(buf, &buflen))
    {
      
      //Serial.println((char*)buf);
      //Serial.println(buf[0]);

      if(buf[0]=='f')
      {  
       forward(); 
       Serial.println("Forward");
      }  
      else if(buf[0]=='b')
      {
       backward();
       Serial.println("Backward");
      }
      else if(buf[0]=='r')
      {
       right();
       Serial.println("right");
      }
      else if(buf[0]=='l')
      {
       left();
       Serial.println("left");
      }
      else if(buf[0]=='s')            
      {
       stop();
       Serial.println("Stop");
      }

      

    }
    
}


void forward()
{
  digitalWrite(lf , HIGH);
  digitalWrite(lb , LOW);
  digitalWrite(rf , HIGH);
  digitalWrite(rb , LOW);

 // analogWrite(ls , 150);
  //analogWrite(rs , 150);

}

void backward()
{
  digitalWrite(lb , HIGH);
  digitalWrite(lf , LOW);
  digitalWrite(rb , HIGH);
  digitalWrite(rf , LOW);

 // analogWrite(ls , 150);
  //analogWrite(rs , 150);
}

void right()
{
  digitalWrite(lf , HIGH);
  digitalWrite(lb , LOW);
  digitalWrite(rf , LOW);
  digitalWrite(rb , LOW);

  //analogWrite(ls , 150);
  //analogWrite(rs , 150);
}

void left()
{
  digitalWrite(lf , LOW);
  digitalWrite(lb , LOW);
  digitalWrite(rf , HIGH);
  digitalWrite(rb , LOW);

  //analogWrite(ls , 150);
 // analogWrite(rs , 150);
}

void stop()
{
  digitalWrite(lf , LOW);
  digitalWrite(lb , LOW);
  digitalWrite(rf , LOW);
  digitalWrite(rb , LOW);

 // analogWrite(ls , 150);
 // analogWrite(rs , 150);
}
