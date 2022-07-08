# ECG-R-Peak-detector

ECG R-peak detecting with Arduino Uno

We used ECG sensor which is self-made.

Depending on Arduino input voltage (0V ~ 5V)
-> End of the sensor circuit, there is a inverting amplifier which changes the range of output voltage of sensor.

Sensor combines LPF, Notch Filter(60Hz power noise) etc.

HPF is processed by Arduino code, you can see in main code.
