#include <IRremote.h>

IRsend irsend;

unsigned char string[10];
int i=0;
int string_len;
int inByte;
int failed = 0;
int toggled = 0;

int PIN_POWER = 7;

void setup() {
  Serial.begin(9600); //INTIALISING THE SERIAL PORT

  digitalWrite(PIN_POWER, HIGH);

  /*sample usage
    turning on power:
    process_power(1);

    controlling ac:
    process_mit_ac(0, 22);

  */
}

void loop()  // LOOP FUNCTION
{

}

void process_mit_ac(unsigned int data1, unsigned int data2){
  unsigned int fan = (data1 & 0xff);
  fan = (fan << 8) + ((~fan) & 0xff);
  unsigned int temp = (data2 & 0xff);
  temp = (temp << 8) + ((~temp) & 0xff);

  irsend.sendMitsubishiAC(0x4a, 0x75C3649B, 0xDF20, fan, temp);
}

void process_power(unsigned int data){
  if(data == 1){
    digitalWrite(PIN_POWER, LOW);
  }else{
    digitalWrite(PIN_POWER, HIGH);
  }
}

