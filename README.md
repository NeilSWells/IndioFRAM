# IndioFRAM
## _FRAM library for the Ethernet Module of the Industruino D21G_

Access the 8k FRAM storage on the Ethernet Module.

The library divides the memory into 32 pages of 256 bytes of storage.

Page 0 to 31

Address 0 to 255

Although this structure can be wasteful, pages allows different configurations to be stored at the same addresses on different pages.

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

## Functions
    void begin();
    byte readByte(byte page, byte address);
    bool writeByte(byte page, byte address, byte value);
    void readChar(byte page, byte address, char *value, byte count);
    void writeChar(byte page, byte address, char *value, byte count);
    double readDouble(byte page, byte address);
    bool writeDouble(byte page, byte address, double value);
    float readFloat(byte page, byte address);
    bool writeFloat(byte page, byte address, float value);
    int readInt(byte page, byte address);
    bool writeInt(byte page, byte address, int value);
    long readLong(byte page, byte address);
    bool writeLong(byte page, byte address, long value);
    unsigned int readUnsignedInt(byte page, byte address);
    bool writeUnsignedInt(byte page, byte address, unsigned int value);
    unsigned long readUnsignedLong(byte page, byte address);
    bool writeUnsignedLong(byte page, byte address, unsigned long value);
    word readWord(byte page, byte address);
    bool writeWord(byte page, byte address, word value);
    
    
