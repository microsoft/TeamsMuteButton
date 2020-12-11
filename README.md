# Microsoft Teams Mute Button!

> This project uses an [Adafruit Circuit Playground Express (CPX)](https://www.adafruit.com/product/3333) and a large pushbutton to create an easy-to-reach mute button for Microsoft Teams. Because 2020.

Skill level: Beginner
Estimated Build Time: <30 min
Estimated Cost: $30

## Materials
* [Adafruit Circuit Playground Express and microUSB cable](https://www.adafruit.com/product/3517)
* 2 [alligator clips](https://www.adafruit.com/product/1008)
* 1 ["Big Dome" pushbutton](https://www.gravitech.us/bigdopubured.html)

## Software
* Arduino IDE (or VS Code w/ Arduino extension)

## Build Instructions
1. Connect the bottom pushbutton terminal to CPX pin A1.
2. Connect the bottom side pushbutton terminal to CPX 3.3V pin.
3. Plug in the microUSB cable between the CPX and your computer.

That's it!

## Software Instructions
1. Download this repo, or copy and paste the code in "TeamsMuteButton" folder called "TeamsMuteButton.ino".
1. Open the Arduino IDE (download for free here) and open (or paste) the "TeamsMuteButton.ino" file.
1. Open the Boards Manager (under Tools --> Board) and install the Arduino SAMD Boards.
1. Once the boards are installed, suggested to restart Arduino IDE. Then go back to Tools--> Boards and select "Adafruit Circuit Playground Express" from the "Arduino SAMD (32-Bits ARM Cortex-M0+) Boards" option.
1. Select the port your CPX is connected to (under Tools --> Port).
1. Upload the code to the CPX (click the arrow key on the shortcut menu).
1. When the code is finished uploading, check that the program works by moving the slide switch to the left (towards CPX Button A) and pressing the pushbutton.
    
    You should see the red LED on the CPX turn on, and the command should open the Arduino Serial Monitor.

1. Once it's working as expected, you're ready to deploy! Use the slide switch to enable/disable the button.

Note: The pushbutton triggers the keyboard "CTRL + Shift + M" keys, which does different things in different apps. **The mute function will only work if you're actively using Teams.**

### Troubleshooting
1. Check the alligator clip connections between the pushbutton and CPX. 
    * Ensure you're using the proper Pushbutton leads
    * Check that you're connected to CPX pin A1.
1. Use the Serial Monitor to check the CPX slide switch status. When it is enabled, it will print "Ready to mute!" to the Serial Monitor.
1. Use the Serial Monitor to check if the pushbutton is getting triggered. When it is pressed and read by the CPX, it will print "Pressed" to the Serial Monitor.
1. Questions or other problems? Please open an issue or reach out to us: AskAMaker@microsoft.com

Happy Making!

## Contributing

This project welcomes contributions and suggestions.  Most contributions require you to agree to a
Contributor License Agreement (CLA) declaring that you have the right to, and actually do, grant us
the rights to use your contribution. For details, visit https://cla.opensource.microsoft.com.

When you submit a pull request, a CLA bot will automatically determine whether you need to provide
a CLA and decorate the PR appropriately (e.g., status check, comment). Simply follow the instructions
provided by the bot. You will only need to do this once across all repos using our CLA.

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/).
For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or
contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.

## Trademarks

This project may contain trademarks or logos for projects, products, or services. Authorized use of Microsoft 
trademarks or logos is subject to and must follow 
[Microsoft's Trademark & Brand Guidelines](https://www.microsoft.com/en-us/legal/intellectualproperty/trademarks/usage/general).
Use of Microsoft trademarks or logos in modified versions of this project must not cause confusion or imply Microsoft sponsorship.
Any use of third-party trademarks or logos are subject to those third-party's policies.
