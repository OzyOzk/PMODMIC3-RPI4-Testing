# PMODMIC3-RPI4-Testing
Code to test the PMOD MIC3 microphone on a Raspberry Pi 4. Runs at around 57KHz. Can be increased by changing the CLOCK_FREQUENCY define. (This is actually baud rate,
not the clock frequency. Anything above 2000000 and the microphone may not perform as expected)

## Requirements

* Raspberry Pi 4 (4GB model)
* PMOD MIC3 microphone module
* x6 female to female jumper wires
* pigpio c library

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
