# RC_ReceiverAdapter
Connect an RC receiver to a USB port on a computer to act as a joystick

This project uses an Arduino Micro board to convert the output from an RC receiver into a two-channel joystick via USB.
It specifically depends on boards that use the atmega32u4 or atmega16u4 microncontroller because they have built-in USB device functionality.

This project also depends on the joystick library that can be found here: https://github.com/MHeironimus/ArduinoJoystickLibrary

Using the code provided, connect a receiver plug to VCC, GND and pin 2 of the Micro board. This will plug into port 1 of the receiver, which is typically the steering channel. Connect a single wire plug to pin 7 of the Micro board. This will plug into the throttle channel.

Upload the code to the board. Once the program is running, the computer should now recognise a USB game device. It's recommended to calibrate this using the control panel app, so that centre and end-stop positions are registered properly.

Hopefully more details to come when I get time :-)

## Building an adapter
Whilst not difficult, some tools and proficiency with using them is expected. Most RC racers are likely to have the bulk of the tools and expertise required, but in some cases, some shortcuts are available.

You'll need an Arduino Micro or compatible board. These are based on the ATMega32u4 microncontroller which has a handy built-in USB interface. We exploit this and some software to emulate a joystick. The boards are available from a variety of sources and come in different form factors too. Make sure you get one configured for 5V operation and strongly recommend a 16MHz version. They often come in packaging like this:
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/IMG_3786.JPG )

You won't need the header pins that are often included, so don't worry if you don't have them.

The next most important part is some wires and connectors to attach the board to your receiver. You need two plugs and associated wire.
The simplest thing to do is find some old ones you don't need and just cut them to an appropriate length. However, you can build your own if you have the bits and tools lying around. Although they are very useful tools to have, good ones aren't cheap, so don't buy them just for this project.
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/IMG_3788.JPG )

Likewise, if you're knocking together your own connections, you'll need the plug bits and pieces:
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/IMG_3789.JPG )

Make up the first connector with the plugs and wires. Set up all three pins. Now, due to the magic of electrons and physics, the second connector only needs a single wire to the signal channel. Of course, there's no harm in wiring up all three, so your call.

Now you have your board and wires ready for soldering.

![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/IMG_3791.JPG )

Solder the ground wire to the GND pin on the board (some boards have more than one, so anyone is fine). Solder the positive wire to the VCC pin or one marked 5V. Finally, solder the receiver steering signal wire to pin 2 and the throttle signal wire to pin 3. Of course, you can adjust these pin assignments in the software, within limits. It should look a little like this:
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/IMG_3792.JPG )

The hardware side is now pretty much done. For a bit of protection, consider wrapping the assembly in shrink wrap:
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/IMG_3796.JPG )

## Connecting the adapter

Plug the two connectors into the receiver. Although it can vary, channel 1 on the receiver is typically the steering and channel 2 is usually throttle. Check the configuration on your equipment and adjust as appropriate. Here's what it looks like on my Sanwa receiver.
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/IMG_3793.JPG )

Unless you've used Arduino before, don't plug the board into the computer just yet.

## Installing the software
This section is likely incomplete and skims the process a bit. Hopefully, I'll expand it over time to be a bit more self-contained.

You need the Arduino "Integrated Development Environment" or IDE. This can be downloaded from here:
https://www.arduino.cc/en/main/software

It's usually a very straightforward installation.

Download the library referenced here: https://github.com/MHeironimus/ArduinoJoystickLibrary and copy the "joystick" library into the library folder of the Arduino installation. If you get stuck on this, search the web for managing Arduino libraries.

At this time, you can plug the adapter in to the computer using a micro USB cable.

Now, you can grab the code from this repository. You only need the single .ino file Open this in the Arduino IDE.

Select the right board type from the "Tools" menu:
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/Screenshot%20(47).png )

Also, make sure the correct USB port is selected:
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/Screenshot%20(48).png )

With all of that, you can now hit the "Upload" button in the upper left:
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/Screenshot%20(49).png )

The compilation process will take place and then it should upload the code to the board. Hopefully, you'll see a success message in the lower status window.

## Calibrating the adapter

Theses instructions assume you're on a Windows 10 computer.

Press the Windows “start” button and type “set up usb game” and the following item should appear:
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/Screenshot%20(36).png )

Select that one and it will take you to this screen:
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/Screenshot%20(37).png )

Press the “Properties” button and the following window appears:
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/Screenshot%20(38).png )

Choose the “Settings” tab in the upper left:
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/Screenshot%20(39).png )

And now press the “Calibrate…” button.
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/Screenshot%20(40).png )

Press “Next>”
Make sure your radio is on, the receiver is showing connected and leave throttle and steering at neutral.
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/Screenshot%20(41).png )

Press “Next>”
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/Screenshot%20(42).png )

Now, move the steering and throttle the full range of travel in all directions a few times. Eventually, when left in their neutral positions, the cross hair will be relatively close to the centre of the square. It may bobble slightly, this is normal.
Press “Next>” a few times until you get to this view. The additional dialog windows can be ignored since we are only setting up 2 channels.
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/Screenshot%20(43).png )

The controller should now be ready to use in any games that support a two channel joystick.
![image](https://github.com/grandaspanna/RC_ReceiverAdapter/blob/master/images/Screenshot%20(44).png )


## Fin
Cut some laps.
