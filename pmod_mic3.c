#include <stdio.h>
#include <stdlib.h>
#include <pigpio.h>
#include <unistd.h>

#define BAUD_RATE 500000

struct timespec ts;

double pmod_mic3(double* in_array, int size){
  if (gpioInitialise() < 0) return 1;
  ts.tv_nsec = 2300;
  ts.tv_sec = 0;
  double start, delta;
  double analog = 0;
  int h = spiOpen(0, BAUD_RATE, 0);
  if (h < 0) return 1;
  
  /*bits to send*/
  unsigned char snd[2] = {0, 0};
  
  /*buffer*/
  unsigned char buf[2] = {0, 0};
  
  start = time_time();


  for (int i=0; i<size; i++){
    spiXfer(h, snd, buf, 2);
    analog = buf[0] << 8 | buf[1];
    in_array[i] = analog;
  }
  
  delta = time_time() - start;
  spiClose(h);
  return delta;
}
