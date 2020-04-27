#include <SPI.h>
#include <Servo.h>
uint8_t buf[100];
uint16_t data[100];
int idx = 0;
volatile byte pos;
volatile bool process_it;

Servo left;
Servo right;
void setup (void)
{
  Serial.begin (9600);   // debugging
  right.attach(1);
  left.attach(2);
  
  // turn on SPI in slave mode
  SPCR |= bit (SPE);

  // have to send on master in, *slave out*
  pinMode (MISO, OUTPUT);

  // get ready for an interrupt
  pos = 0;   // buffer empty
  process_it = false;

  // now turn on interrupts
  SPI.attachInterrupt();

}  // end of setup


// SPI interrupt routine
ISR (SPI_STC_vect)
{
byte c = SPDR;  // grab byte from SPI Data Register

  // add to buffer if room
  if (pos < sizeof buf)
    {
    buf [pos++] = c;

    // time to process buffer
    if (c == 255)
      process_it = true;

    }  // end of room available
}  // end of interrupt routine SPI_STC_vect

// main loop - wait for flag set in interrupt routine
void loop (void)
{
  if (process_it)
    {
    buf [pos] = 0;
    idx = 0;
    for(int i = 0; i<12; i++){
    data[idx] = buf[i]*255+buf[i+1];
    //Serial.println (buf[i]);
    //Serial.println (data[idx]);
    idx++;
    i++;
    }
    pos = 0;
    process_it = false;
    }  // end of flag set
  left.write(data[1]);
  Serial.println (data[1]);
  left.write(data[2]);
  Serial.println (data[2]);
}  
