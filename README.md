# IndioFRAM
## _FRAM library for the Ethernet Module of the Industruino D21G_

Access the 8k FRAM storage on the Ethernet Module.

The library divides the memory into 32 pages of 256 bytes of storage.

## Basic code
```sh
#include <IndioFram.h>
IndioFram fram;
const byte FRAM_PAGE = 31; //Page 0 - 31

void setup()
{
    fram.begin();

    SerialUSB.begin(9600);
    while (!SerialUSB);

    //Byte
    byte b = 255;
    fram.writeByte(FRAM_PAGE, 0 , b);
    SerialUSB.println(fram.readByte(FRAM_PAGE, 0));

    //Char array
    char textWrite[20] = "This is a FRAM test";
    char textRead[20];
    fram.writeChar(FRAM_PAGE, 1, textWrite, 20);
    fram.readChar(FRAM_PAGE, 1, textRead, 20);
    SerialUSB.println(textRead);
}

void loop()
{

}
```
