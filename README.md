# IndioFRAM
## _FRAM library for the Ethernet Module of the Industruino D21G_

Access the 8k FRAM storage on the Ethernet Module.

The library divides the memory into 32 pages of 256 bytes of storage.

Page 0 to 31

Address 0 to 255

Although this structure can be wasteful, pages allows different configurations to be stored at the same addresses on different pages.

## Basic code
```sh
#include <SPI.h>
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
    fram.writeChar(0, 1, textWrite, 20); //Write 20 chars of textWrite to page 0, address 1
    fram.readChar(0, 1, textRead, 20);
    SerialUSB.println(textRead);
}

void loop()
{

}
```

## Functions
    begin();
    
    //Byte = 1 byte
    byte = readByte(page, address);
    bool = writeByte(page, address, byte);
    
    //Char = count bytes
    readChar(page, address, char, count);
    writeChar(page, address, char, count);
    
    //Double = 8 bytes
    double = readDouble(page, address);
    bool = writeDouble(page, address, double);
    
    //Float = 4 bytes
    float readFloat(byte page, byte address);
    bool writeFloat(byte page, byte address, float value);
    
    //Int = 4 bytes
    int = readInt(page, address);
    bool = writeInt(page, address, int);
    
    //Long = 4 bytes
    long = readLong(page, address);
    bool = writeLong(page, address, long);
    
    //Unsigned Int = 4 bytes
    unsigned int = readUnsignedInt(page, address);
    bool = writeUnsignedInt(page, address, unsigned int);
    
    //Unsigned Long = 4 bytes
    unsigned long = readUnsignedLong(page, address);
    bool = writeUnsignedLong(page, address, unsigned long);
    
    //Word = 2 bytes
    word = readWord(page, address);
    bool = writeWord(page, address, word);
    
Write functions return true if successful. Writes will fail if there is not enough space before the end of the page

`fram.writeInt(0, 253, 42);` will fail because there is not enough room for the 4 bytes of an Int at address 253
