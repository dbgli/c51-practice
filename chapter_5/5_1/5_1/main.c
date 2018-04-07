#include <REG51.H>
#include <INTRINS.H>

#define uchar unsigned char
#define uint unsigned int

void delay(uint i) {
    uchar j;
    while (--i) {
        for (j = 0; j < 125; ++j);
    }
}

void main() {
    P1 = 0xFE;
    while (1) {
        delay(500);
        P1 = _crol_(P1, 1);
    }
}