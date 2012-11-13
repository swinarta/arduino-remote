arduino-remote
==============

Controlling Mitsubishi AC and power bar using arduino.

IRemote library is based on Ken Shirriff's Arduino-IRremote (https://github.com/shirriff/Arduino-IRremote)

## Usage

    process_power(num);

    process_mit_ac(fanIndex, temp);

    0 for power off
    1 for power on

    fanIndex 0 for medium
    fanIndex 1 for low


