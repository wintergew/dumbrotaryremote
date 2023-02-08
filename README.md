# Dumb Rotary Encoder Remote for Yeelight Lamps

## Bill of Materials

* LoLin NodeMCU v3
* 5x Jumper Cables
* KY-040 Rotary Encoder
* 4x M3 Screws
* 2x M2 Screws
* 3D Printed Case
* 3D Printed Knob (I recommend this one: [Printables](https://www.printables.com/model/191627-knurled-knob-for-ky-040-rotary-encoderhttps:/))

## Instructions

### Hardware

1. Plug the Jumper Cables as follows;


   | KY-040 | NodeMCU |
   | :------- | --------- |
   | CLK    | D7      |
   | DT     | D6      |
   | SW     | D5      |
   | +      | 3V      |
   | GND    | G       |
2. Screw NodeMCU to the case with M3 screws as shown in the image.
3. Screw the rotary encoder to the case with M2 screws as shown in the image.
4. Put the knob on the rotart encoder.

### Software

1. Install the required drivers.
2. Install the "EncoderButton" library.
3. Edit code and add your wifi password and ssid.
4. Enable **"Lan Control"** in the advanced setting tab on the Yeelight app.
5. Compile & Upload the code!

# Images
![](https://raw.githubusercontent.com/wintergew/dumbrotaryremote/master/assets/2.png)

![](https://raw.githubusercontent.com/wintergew/dumbrotaryremote/master/assets/1.png)
