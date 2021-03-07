# IndioFRAM
## _FRAM library for the Ethernet Module of the Industruino D21G_

Access the 8k FRAM storage on the Ethernet Module.

The library divides the memory into 32 pages of 256 bytes of storage.
Page 0 to 31
Address 0 to 255
Although this structure can be wasteful, pages allows different configuration data to be stored in at the same addresses on different pages.

## Basic code
```sh
#include <IndioFram.h>
IndioFram fram;

void setup()
{
    fram.begin();

    SerialUSB.begin(9600);
    while (!SerialUSB);

    //Byte
    fram.writeByte(0, 0 , 42); //Write to page 0, address 0
    SerialUSB.println(fram.readByte(0, 0));

    //Char array
    char textWrite[20] = "This is a FRAM test";
    char textRead[20];
    fram.writeChar(0, 1, textWrite, 20); //Write to page 0, address 1
    fram.readChar(0, 1, textRead, 20);
    SerialUSB.println(textRead);
}

void loop()
{

}
```
