# Pixy-cam-to-RoboRIO
A program for getting serial data from a Pixy to a RoboRIO via an Arduino. Made for use in the FIRST Robotics Competition.  I only know LabVIEW for FRC and enough C to get an Arduino working so the RoboRIO code is only for LabVIEW teams at the moment. 

The purpose of this is to have a quick and simple solution to getting serial data from a CMUcam5 Pixy to a RoboRIO.  
The code assumes you intend to track one target, presumably reflective tape, at 50 frames a second.

The basic hardware setup requires an Arduino UNO R3, a USB male A to Male B cable, the CMUcam5 Pixy, and the ribbon cable included with it.

In order to track reflective tape in an FRC competition you will also need an adequate colored light source and (maybe) a replacement lens with a longer focal length (and subsequently smaller field of view).

What to buy (as of 11/25/2016)

Arduino UNO R3: https://www.amazon.com/Arduino-Uno-R3-Microcontroller-A000066/dp/B008GRTSV6/ref=sr_1_3?ie=UTF8&qid=1480052328&sr=8-3&keywords=arduino

USB male A to Male B cable: https://www.amazon.com/AmazonBasics-USB-2-0-Cable-Male/dp/B00NH11KIK/ref=pd_sim_147_16?_encoding=UTF8&pd_rd_i=B00NH11KIK&pd_rd_r=H0Y0Q6E9X16MP0THTDJV&pd_rd_w=PdymJ&pd_rd_wg=BWcwh&psc=1&refRID=H0Y0Q6E9X16MP0THTDJV

CMUcam5 Pixy: https://www.amazon.com/Pixy-CMUcam5-Smart-Vision-Sensor/dp/B00IUYUA80/ref=sr_ph_1?ie=UTF8&qid=1480052328&sr=sr-1&keywords=arduino

If you want to track reflective tape:
12V LED rings (green recommended and get the 60, 80, and 100 mm sizes): https://www.superbrightleds.com/moreinfo/led-headlight-accent-lights/led-halo-angel-eye-headlight-accent-lights/49/#/tab/Overview

If you want to see things at a distance:
Lens: (will post after tests)

And read this before buying a lens!: http://cmucam.org/projects/cmucam5/wiki/Can_I_replace_the_lens_on_Pixy

To Do:
Test new lens on practice field
Test reflective tape targeting 
Add pictures and diagrams of setup
Write Arduino code to turn LED rings on and off
Design electrical circuit to control LED rings with Arduino and power them from the robot's 12V supply

Also this will hopfuly become obsilete when somone creates a guide to get data from the pixy directly from its SPI port or even better gets the libpixyusb:https://github.com/charmedlabs/pixy working on the RoboRIO.
