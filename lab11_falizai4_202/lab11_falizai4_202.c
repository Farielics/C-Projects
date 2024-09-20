/* Faryal Alizai G01364057
 * CS 262, Lab Section 202
 * Lab 11
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d"
#define BYTETOBINARY(byte) \
    (byte & 0x80 ? 1 : 0), \
    (byte & 0x40 ? 1 : 0), \
    (byte & 0x20 ? 1 : 0), \
    (byte & 0x10 ? 1 : 0), \
    (byte & 0x08 ? 1 : 0), \
    (byte & 0x04 ? 1 : 0), \
    (byte & 0x02 ? 1 : 0), \
    (byte & 0x01 ? 1 : 0)
#define PRINTBIN(x) printf(BYTETOBINARYPATTERN, BYTETOBINARY(x)); printf("\n");

void setlsbs(unsigned char *p, unsigned char b0) {
    for (int i = 0; i < 8; i++) {
        p[i] = (p[i] & 0xFE) | ((b0 >> i) & 1);
    }
}

unsigned char getlsbs(unsigned char *p) {
    unsigned char byte0 = 0;
    for (int i = 0; i < 8; i++) {
        byte0 |= (p[i] & 0x01) << i;
    }
    return byte0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <seed>\n", argv[0]);
        return 1;
    }

    srand(atoi(argv[1]));

    unsigned char p[8];
    printf("Values in decimal and binary format:\n");
    for (int i = 0; i < 8; i++) {
        p[i] = rand() % 256;
        printf("%3u = ", p[i]);
        PRINTBIN(p[i]);
    }

    unsigned char byte0 = rand() % 256;
    printf("\nByte0 in decimal and binary format:\n");
    printf("%3u = ", byte0);
    PRINTBIN(byte0);
    printf("------------------------\n");

    setlsbs(p, byte0);

    printf("Binary and decimal values after modification:\n");
    for (int i = 0; i < 8; i++) {
        printf("%3u = ", p[i]);
        PRINTBIN(p[i]);
    }

    unsigned char getbyte0 = getlsbs(p);
    printf("\nValue returned by getlsbs in decimal and binary format:\n");
    printf("%3u = ", getbyte0);
    PRINTBIN(getbyte0);

    return 0;
}
