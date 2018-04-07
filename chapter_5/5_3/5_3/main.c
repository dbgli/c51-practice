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
    uchar temp;
    while (1) {
        P1 = 0xFF;
        temp = P1 & 0xF0;
        P1 = temp >> 4;
        delay(500);
    }
}