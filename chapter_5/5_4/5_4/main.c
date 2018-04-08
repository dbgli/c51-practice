#include <REG51.H>

#define uchar unsigned char

void main() {
    uchar state;
    while (1) {
        P1 = 0xFF;
        state = P1 & 0x03;
        switch (state) {
            case 0: P2 = 0x01; break;
            case 1: P2 = 0x02; break;
            case 2: P2 = 0x04; break;
            case 3: P2 = 0x08; break;
            default: P2 = 0x00; break;
        }
    }
}