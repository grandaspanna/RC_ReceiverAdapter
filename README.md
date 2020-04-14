# RC_ReceiverAdapter
Connect an RC receiver to a USB port on a computer to act as a joystick

This project uses an Arduino Micro board to convert the output from an RC receiver into a two-channel joystick via USB.
It specifically depends on boards that use the atmega32u4 or atmega16u4 microncontroller because they have built-in USB device functionality.

This project also depends on the joystick library that can be found here: https://github.com/MHeironimus/ArduinoJoystickLibrary

Using the code provided, connect a receiver plug to VCC, GND and pin 2 of the Micro board. This will plug into port 1 of the receiver, which is typically the steering channel. Connect a single wire plug to pin 7 of the Micro board. This will plug into the throttle channel.

Upload the code to the board. Once the program is running, the computer should now recognise a USB game device. It's recommended to calibrate this using the control panel app, so that centre and end-stop positions are registered properly.

Hopefully more details to come when I get time :-)
