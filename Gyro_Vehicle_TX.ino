#include<RH_ASK.h>
#include<SPI.h>

RH_ASK tx;

#define x A0
#define y A1
#define z A2

char *data;

int xi , yi , zi , xl , yl , zl , dx , dy , dz ;

void setup()
{
  Serial.begin(9600);
  tx.init();

  pinMode (x, INPUT);
  pinMode (y, INPUT);
  pinMode (z, INPUT);

  xi = analogRead(x);
  yi = analogRead(y);
  zi = analogRead(z);

}

void loop()
{
  xl = analogRead(x);
  yl = analogRead(y);
  zl = analogRead(z);

  dx = xl - xi ;
  dy = yl - yi ;
  dz = zl - zi ;

  //Serial.println(dx);
   Serial.println(dz);

  if(dy >= 40)
  {
    data="f";
    tx.send((uint8_t *)data, strlen(data));
    tx.waitPacketSent();
    delay(200);
    Serial.println("Forward");
  }
  else if(dy <= -45)
  {
    data="b";
    tx.send((uint8_t *)data, strlen(data));
    tx.waitPacketSent();
    delay(200);
    Serial.println("Backward");
  }
  else if(dx >= 40)
  {
    data="l";
    tx.send((uint8_t *)data, strlen(data));
    tx.waitPacketSent();
    delay(200);
    Serial.println("left");
  }
  else if(dx <= -45)
  {
    data="r";
    tx.send((uint8_t *)data, strlen(data));
    tx.waitPacketSent();
    delay(200);
    Serial.println("right");
  }
  else
  {
    data="s";
    tx.send((uint8_t *)data, strlen(data));
    tx.waitPacketSent();
    delay(200);
    Serial.println("Stop");
  }

}