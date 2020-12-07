#include <stdio.h>
#include <stdlib.h>
#include <pigpio.h>
#include <unistd.h>

#define CLOCK_SPEED 500000

/*
   gcc -pthread -o spi-speed spi-speed.c -lpigpio
*/

struct timespec ts;

double pmod_mic3(double* in_array, int size){
  if (gpioInitialise() < 0) return 1;
  ts.tv_nsec = 2300;
  ts.tv_sec = 0;
  double start, delta;
  double analog = 0;
  int h = spiOpen(0, CLOCK_SPEED, 0);
  if (h < 0) return 1;
  
  /*bits to send*/
  unsigned char snd[2] = {0, 0};
  
  /*buffer*/
  unsigned char buf[2] = {0, 0};
  
  start = time_time();
  
  //double tmp_start, tmp_delta;

  for (int i=0; i<size; i++){
    //tmp_start = time_time();
    spiXfer(h, snd, buf, 2);
    analog = buf[0] << 8 | buf[1];
    in_array[i] = analog;
    //nanosleep(&ts, NULL);
    //tmp_delta = time_time() - tmp_start;
    //printf("%f\n", tmp_delta);
  }
  
  delta = time_time() - start;
  spiClose(h);
  //printf("%f\n", delta);
  return delta;
}
