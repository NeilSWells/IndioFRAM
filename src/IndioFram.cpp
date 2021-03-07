#include "IndioFram.h"

//Public
void IndioFram::begin()
{
    pinMode(FRAM_PIN, OUTPUT);
    digitalWrite(FRAM_PIN, HIGH);
    SPI.begin();
    SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
    SPI.endTransaction();
}


byte IndioFram::readByte(byte page, byte address)
{
    byte r;
    if (page > MAX_PAGE) return 0;
    digitalWrite(FRAM_PIN, LOW);
    SPI.transfer(OP_CODE_READ);
    SPI.transfer(page);
    SPI.transfer(address);
    r = SPI.transfer(0x00);
    digitalWrite(FRAM_PIN, HIGH);
    return r;
}


bool IndioFram::writeByte(byte page, byte address, byte value)
{
    if (page > MAX_PAGE) return false;
    digitalWrite(FRAM_PIN, LOW);
    SPI.transfer(OP_CODE_WREN);
    digitalWrite(FRAM_PIN, HIGH);
    digitalWrite(FRAM_PIN, LOW);
    SPI.transfer(OP_CODE_WRITE);
    SPI.transfer(page);
    SPI.transfer(address);
    SPI.transfer(value);
    digitalWrite(FRAM_PIN, HIGH);
    return true;
}


void IndioFram::readChar(byte page, byte address, char *value, byte count)
{
    readRange(page, address, (byte*) value, count);
}


void IndioFram::writeChar(byte page, byte address, char *value, byte count)
{
    writeRange(page, address, (byte*) value, count);
}


double IndioFram::readDouble(byte page, byte address)
{
    union
    {
        double doubleValue;
        byte byteValue[SIZE_DOUBLE];
    };
    if (readRange(page, address, byteValue , SIZE_DOUBLE)) return doubleValue;
    return 0.0;
}


bool IndioFram::writeDouble(byte page, byte address, double value)
{
    union
    {
        double doubleValue;
        byte byteValue[SIZE_DOUBLE];
    };
    doubleValue = value;
    return writeRange(page, address, byteValue, SIZE_DOUBLE);
}


float IndioFram::readFloat(byte page, byte address)
{
    union
    {
        float floatValue;
        byte byteValue[SIZE_FLOAT];
    };
    if (readRange(page, address, byteValue , SIZE_FLOAT)) return floatValue;
    return 0.0;
}


bool IndioFram::writeFloat(byte page, byte address, float value)
{
    union
    {
        float floatValue;
        byte byteValue[SIZE_FLOAT];
    };
    floatValue = value;
    return writeRange(page, address, byteValue, SIZE_FLOAT);
}


int IndioFram::readInt(byte page, byte address)
{
    union
    {
        int intValue;
        byte byteValue[SIZE_INT];
    };
    if (readRange(page, address, byteValue , SIZE_INT)) return intValue;
    return 0;
}


bool IndioFram::writeInt(byte page, byte address, int value)
{
    union
    {
        int intValue;
        byte byteValue[SIZE_INT];
    };
    intValue = value;
    return writeRange(page, address, byteValue, SIZE_INT);
}


long IndioFram::readLong(byte page, byte address)
{
    union
    {
        long longValue;
        byte byteValue[SIZE_LONG];
    };
    if (readRange(page, address, byteValue , SIZE_LONG)) return longValue;
    return 0;
}


bool IndioFram::writeLong(byte page, byte address, long value)
{
    union
    {
        long longValue;
        byte byteValue[SIZE_LONG];
    };
    longValue = value;
    return writeRange(page, address, byteValue, SIZE_LONG);
}


unsigned int IndioFram::readUnsignedInt(byte page, byte address)
{
    union
    {
        unsigned int uintValue;
        byte byteValue[SIZE_UINT];
    };
    if (readRange(page, address, byteValue , SIZE_UINT)) return uintValue;
    return 0;
}


bool IndioFram::writeUnsignedInt(byte page, byte address, unsigned int value)
{
    union
    {
        unsigned int uintValue;
        byte byteValue[SIZE_UINT];
    };
    uintValue = value;
    return writeRange(page, address, byteValue, SIZE_UINT);
}

unsigned long IndioFram::readUnsignedLong(byte page, byte address)
{
    union
    {
        unsigned long ulongValue;
        byte byteValue[SIZE_ULONG];
    };
    if (readRange(page, address, byteValue , SIZE_ULONG)) return ulongValue;
    return 0;
}


bool IndioFram::writeUnsignedLong(byte page, byte address, unsigned long value)
{
    union
    {
        unsigned long ulongValue;
        byte byteValue[SIZE_ULONG];
    };
    ulongValue = value;
    return writeRange(page, address, byteValue, SIZE_ULONG);
}


word IndioFram::readWord(byte page, byte address)
{
    union
    {
        word wordValue;
        byte byteValue[SIZE_WORD];
    };
    if (readRange(page, address, byteValue , SIZE_WORD)) return wordValue;
    return 0;
}


bool IndioFram::writeWord(byte page, byte address, word value)
{
    union
    {
        word wordValue;
        byte byteValue[SIZE_WORD];
    };
    wordValue = value;
    return writeRange(page, address, byteValue, SIZE_WORD);
}

//Private
bool IndioFram::readRange(byte page, byte address, byte * value, byte count)
{
    if (page > MAX_PAGE || address > (255 - count)) return false;
    digitalWrite(FRAM_PIN, LOW);
    SPI.transfer(OP_CODE_READ);
    SPI.transfer(page);
    SPI.transfer(address);
    for (byte b = 0; b < count; b++) value[b] = SPI.transfer(0x00);
    digitalWrite(FRAM_PIN, HIGH);
    return true;
}


bool IndioFram::writeRange(byte page, byte address, byte * value, byte count)
{
    if (page > MAX_PAGE || address > (255 - count)) return false;
    digitalWrite(FRAM_PIN, LOW);
    SPI.transfer(OP_CODE_WREN);
    digitalWrite(FRAM_PIN, HIGH);
    digitalWrite(FRAM_PIN, LOW);
    SPI.transfer(OP_CODE_WRITE);
    SPI.transfer(page);
    SPI.transfer(address);
    for (byte b = 0; b < count; b++) SPI.transfer(value[b]);
    digitalWrite(FRAM_PIN, HIGH);
    return true;
}
