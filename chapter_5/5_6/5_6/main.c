#include <REG51.H>

void main() {
    P0 = 0xA4;
    P1 = 0xF8;
    while (1);
}