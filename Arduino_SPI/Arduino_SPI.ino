#include <SPI.h>
#include <Servo.h>
uint8_t buf[100]; // byte buffer
uint16_t data[100]; // data buffer to match data being sent
int idx = 0;
volatile byte pos;
volatile bool processData;

Servo left;
Servo right;
void setup (void){
  Serial.begin (9600);   // debugging
  right.attach(1);
  left.attach(2);
  
  SPCR |= bit (SPE); // turn on SPI in slave mode
  pinMode (MISO, OUTPUT); // master in slave out config

  // initialise data
  pos = 0;
  processData = false;
  SPI.attachInterrupt(); // enable the interrupts
  
}


// SPI interrupt routine
ISR (SPI_STC_vect){
byte c = SPDR;  // get byte from SPI Data Register

  // add to the buffer if it is not full
  if (pos < sizeof buf){
    
    buf[pos++] = c; // add data to the buffer
    
    if (c == 255) // end of the data frame reached so process now in loop
      processData = true;
    }
    
}  // end of interrupt routine


void loop (void){
  
  if (processData)
    {
    buf[pos] = 0;
    idx = 0;
    /*
    need to combine the data correctly as we recive the data in bytes
    the data being sent is 16bits so need to shift the MSB's by 8 to make room 
    for the LSB's
    */
    for(int i = 0; i<12; i++){ // expecting 12 bytes of data in buffer
      data[idx] = buf[i]*255+buf[i+1];
      idx++;
      i++;
    }
    pos = 0;
    processData = false;
    } 

  // Write data to serial for debug and send the timings to the sabertooth
  left.write(data[1]);
  Serial.println (data[1]);
  left.write(data[2]);
  Serial.println (data[2]);
  
}  
