# Battery Voltmeter to .csv
Is a tiny program written in Arduino and Python to store the voltage of batteries into a .csv file.

This program has been created to measure and store fastly the voltage of more than 70 AA batteries.

## To Do:
- [ ] use csv library from python     
- [ ] translate comments to english   
- [ ] make French and English available (fr csv uses , instead of ., and ; instead of ,)   


## What you'll need:
* an Arduino (Uno for example)
* a USB cable to link the computer to the Arduino
* a Python working environnement
* some batteries to measure

=> then download the code!!!

## How to use it:
0. Put a wire between D2 and 5V on the Arduino.
1. Edit the parameters :
```python
port = str(6)
vitesse = 9600
caracFin = "stop"
cheminFichier = "pathToMyFile.csv"
```
2. Launch the Python script.
3. Use probes plugged into A0 and Gnd (a couple of wires works great) to measure the voltage across the batteries. The values must appear in the Python console. When it's the case you can measure the following battery.
4. When you have finished, unplug the wire on D2. The Python script should quit itself.
5. Open your .csv file with your favorite spreadsheet.

## How it works:

BatteryVoltmeter2csv.ino reads the voltage on A0 and send it over Serial only one time and if it is greater than 0.

Python listen the Serial port. It prints and stores the values into a .csv file.

To stop the measuring process, D2 on Arduino must be put to LOW. The Arduino sends over Serial a `stop`, then when Python receive it, it stops and close the Serial port.
