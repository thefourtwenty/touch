
#include <DMXSerial.h>
#include <Servo.h>
Servo serv1,serv2;
int val1 = 0;
int val2 = 0;
int pos1;
int pos2;

void setup () {
  serv1.attach(9);
  serv2.attach(10);
  DMXSerial.init(DMXReceiver);
  DMXSerial.write(1, 0);
  DMXSerial.write(2, 0);
}


void loop() {
  // Calculate how long no data backet was received
  unsigned long lastPacket = DMXSerial.noDataSince();
  pos1 = DMXSerial.read(val1);
  pos1 = map(pos1, 0, 255, 0, 180);
  pos2 = DMXSerial.read(val2);
  pos2 = map(pos2, 0, 255, 0, 180);
  serv1.write(pos1);
  serv2.write(pos2);
  delay(1);
}

// End.
