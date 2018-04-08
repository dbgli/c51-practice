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
    uchar digits[] = { 0xC0, 0x99, 0xA4, 0x99, 0xA4, 0xC0, 0xF9, 0x82 };
    uchar i, j = 0x01;
    while (1) {
        for (i = 0; i < 8; ++i) {
            P0 = digits[i];
            P2 = j;
            j = _crol_(j, 1);
            delay(300);
        }
    }
}