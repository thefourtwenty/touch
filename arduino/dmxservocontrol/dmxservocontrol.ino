
#include <DMXSerial.h>
#include <Servo.h>
Servo serv1;
int val = 0;
int pos;

void setup () {
  serv1.attach(9);
  DMXSerial.init(DMXReceiver);
  DMXSerial.write(1, 0);
}


void loop() {
  // Calculate how long no data backet was received
  unsigned long lastPacket = DMXSerial.noDataSince();
  pos = DMXSerial.read(val);
  pos = map(pos, 0, 255, 0, 180);
  serv1.write(pos);
  delay(1);
}

// End.
