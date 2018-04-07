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
    uchar i, temp = 0x01;
    while (1) {
        for (i = 0; i < 7; ++i) {
            P1 = ~temp;
            delay(500);
            temp <<= 1;
        }
        for (i = 0; i < 7; ++i) {
            P1 = ~temp;
            delay(500);
            temp >>= 1;
        }
    }
}