#include <IndioFram.h>
IndioFram fram;

const byte FRAM_PAGE = 31;

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

    //Word
    word w = 65535;
    fram.writeWord(FRAM_PAGE, 21, w);
    SerialUSB.println(fram.readWord(FRAM_PAGE, 21));

    //Int
    int i = 2147483647;
    fram.writeInt(FRAM_PAGE, 23, i);
    SerialUSB.println(fram.readInt(FRAM_PAGE, 23));

    //Float
    float f = 1.4142136;
    fram.writeFloat(FRAM_PAGE, 27, f);
    SerialUSB.println(fram.readFloat(FRAM_PAGE, 27), 7);
}

void loop()
{

}
