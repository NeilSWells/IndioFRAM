// IndioFram - Access the FRAM memory on the Ethernet module of the Industruino D21G
// Copyright Neil Wells 2021  https://github.com/NeilSWells
// MIT License

#ifndef INDIO_FRAM_h
#define INDIO_FRAM_h

#include <Arduino.h>
#include <SPI.h>

const byte OP_CODE_WREN  = 0x06; //B00000110
const byte OP_CODE_WRDI  = 0x04; //B00000100
const byte OP_CODE_READ  = 0x03; //B00000011
const byte OP_CODE_WRITE = 0x02; //B00000010
const byte FRAM_PIN = 6;
const byte MAX_PAGE = 31;

const byte SIZE_DOUBLE = 8;
const byte SIZE_FLOAT = 4;
const byte SIZE_INT = 4;
const byte SIZE_LONG = 4;
const byte SIZE_UINT = 4;
const byte SIZE_ULONG = 4;
const byte SIZE_WORD = 2;

class IndioFram
{
    public:
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
    private:
        bool readRange(byte page, byte address, byte * value, byte count);
        bool writeRange(byte page, byte address, byte * value, byte count);
};

#endif
