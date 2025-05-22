#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "header.h"

char alphabetQueue[SIZE];


void initializeQueue() {
    for (int i = 0; i < SIZE; i++) {
        alphabetQueue[i] = 'A' + i;
    }
}

char shiftEncryptChar(char ch, int key) {
    if (!isalpha(ch)) return ch;

    ch = toupper(ch);
    int index = (ch - 'A' + key + SIZE) % SIZE;
    return alphabetQueue[index];
}

char shiftDecryptChar(char ch, int key) {
    if (!isalpha(ch)) return ch;

    ch = toupper(ch);
    int index = (ch - 'A' - key + SIZE) % SIZE;
    return alphabetQueue[index];
}