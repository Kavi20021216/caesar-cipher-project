#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "header.h"

char alphabetQueue[SIZE];

// Initializes the alphabetQueue with letters A–Z (uppercase).
// This simulates a circular queue for Caesar Cipher operations.
void initializeQueue() {
    for (int i = 0; i < SIZE; i++) {
        alphabetQueue[i] = 'A' + i;
    }
}


// Encrypts a single character by shifting it forward in the queue.
// Handles only alphabetic characters and ignores others.
char shiftEncryptChar(char ch, int key) {
    if (!isalpha(ch)) return ch;

    ch = toupper(ch);
    int index = (ch - 'A' + key + SIZE) % SIZE;
    return alphabetQueue[index];
}

// Decrypts a single character by shifting it backward in the queue.
// Ensures wrap-around using modular arithmetic and handles only letters.
char shiftDecryptChar(char ch, int key) {
    if (!isalpha(ch)) return ch;

    ch = toupper(ch);
    int index = (ch - 'A' - key + SIZE) % SIZE;
    return alphabetQueue[index];
}