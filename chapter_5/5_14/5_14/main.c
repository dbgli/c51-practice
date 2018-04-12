#include <REG51.H>

#define uchar unsigned char
#define uint unsigned int

sbit C0 = P1 ^ 0;
sbit C1 = P1 ^ 1;
sbit C2 = P1 ^ 2;
sbit C3 = P1 ^ 3;

void delay(uint i) {
    uchar j;
    while (--i) {
        for (j = 0; j < 125; ++j);
    }
}

void main() {
    uchar code digits[] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E };
    uchar i, temp;
    while (1) {
        P1 = 0xEF;
        for (i = 0; i < 4; ++i) {
            if (C0 == 0) P0 = digits[i * 4 + 0];
            else if (C1 == 0) P0 = digits[i * 4 + 1];
            else if (C2 == 0) P0 = digits[i * 4 + 2];
            else if (C3 == 0) P0 = digits[i * 4 + 3];
            delay(5);
            temp = P1 | 0x0F;   //只读取高四位
            temp <<= 1;
            P1 = temp | 0x01;   //将最低位的0置1
        }
    }
}