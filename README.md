# PMODMIC3-RPI4-Testing
Code to test the PMOD MIC3 microphone on a Raspberry Pi 4. Runs at around 57KHz. Can be increased by changing the CLOCK_SPEED define. (This is actually baud rate,
not the clock frequency. Anything above 2000000 and the microphone may not perform as expected)

## Requirements

* Raspberry Pi 4 (4GB model)
* PMOD MIC3 microphone module
* x6 female to female jumper wires
* pigpio c library

## Connections
```
PMOD MIC3 Module    Raspberry Pi 4
SS      --------->  Pin 24  (GPIO 08 CE0)
94V-0   --------->  
MISO    --------->  Pin 21  (GPIO 09 MISO)
SCK     --------->  Pin 23  (GPIO 11 SCLK)
GND     --------->  Pin 06  (Ground)
VCC     --------->  Pin 01  (3V3 Power)
```

## Instructions

* install pigpio with the following commands

```
wget https://github.com/joan2937/pigpio/archive/master.zip
unzip master.zip
cd pigpio-master
make
sudo make install
```

* Build the c code by running the build.sh script
```
bash build.sh
```
* Run test.py as sudo to test microphone
```
sudo python test.py
```
* test.py can be edited to change the number of samples taken
