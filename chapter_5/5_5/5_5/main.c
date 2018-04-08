#include <REG51.H>

#define uchar unsigned char
#define uint unsigned int

void delay(uint i) {
    uchar j;
    while (--i) {
        for (j = 0; j < 125; ++j);
    }
}

void main() {
    uchar digits[] = { 0xC0, 0xA4, 0x99, 0x82, 0x80, 0xF9, 0xB0, 0x92, 0xF8, 0x90 };
    uchar i = 0;
    while (1) {
        P0 = digits[i++];
        delay(500);
        if (i == 10)
            i = 0;
    }
}