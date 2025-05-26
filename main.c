#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "caesar_cipher.h"

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

void encryptMessage(const char *input, int key, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = shiftEncryptChar(input[i], key);
    }
    output[strlen(input)] = '\0';

void decryptMessage(const char *input, int key, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = shiftDecryptChar(input[i], key);
    }
    output[strlen(input)] = '\0';



int main() {
    char option;
    char originalText[1000], processedText[1000];
    int shift;

    initializeQueue();

    printf("Choose an option - Encrypt (E) or Decrypt (D): ");
    scanf(" %c", &option);
    getchar();  // flush newline from input buffer

    if (option == 'E' || option == 'e') {
        printf("Enter plain text: ");
        fgets(originalText, sizeof(originalText), stdin);
        originalText[strcspn(originalText, "\n")] = '\0';

        printf("Enter shift key: ");
        scanf("%d", &shift);

        encryptMessage(originalText, shift, processedText);

        printf("*\n");
        printf("Encrypted Message: %s\n", processedText);

    } else if (option == 'D' || option == 'd') {
        printf("Enter encrypted text: ");
        fgets(originalText, sizeof(originalText), stdin);
        originalText[strcspn(originalText, "\n")] = '\0';

        printf("Enter shift key: ");
        scanf("%d", &shift);

        decryptMessage(originalText, shift, processedText);

        printf("*\n");
        printf("Decrypted Message: %s\n", processedText);
    } else {
        printf("Invalid input. Please choose 'E' or 'D'.\n");
    }

    return 0;
}
