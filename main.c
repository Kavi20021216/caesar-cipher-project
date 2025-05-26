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

//Function to encrypt the input message using a shift cipher
void encryptMessage(const char *input, int key, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        // Encrypt each character using the shiftEncryptChar function and store it in output
        output[i] = shiftEncryptChar(input[i], key);
    }
     // Null-terminate the encrypted output string
    output[strlen(input)] = '\0';
}

// Function to decrypt the input message using a shift cipher 
void decryptMessage(const char *input, int key, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = shiftDecryptChar(input[i], key);
    }
    output[strlen(input)] = '\0';
}



int main() {
    char option;   // Stores user's choice: Encrypt (E) or Decrypt (D)
    char originalText[1000], processedText[1000];
    int shift;

     // Initialize any queue structure if used internally (assumed for message handling)
    initializeQueue();

    // Prompt user to choose encryption or decryption
    printf("Choose an option - Encrypt (E) or Decrypt (D): ");
    scanf(" %c", &option);
    getchar();   // flush newline from input buffer

    if (option == 'E' || option == 'e') {
        // Handle encryption
        printf("Enter plain text: ");
        fgets(originalText, sizeof(originalText), stdin);
        originalText[strcspn(originalText, "\n")] = '\0';   // Remove newline character from input

        printf("Enter shift key: ");
        scanf("%d", &shift);

        encryptMessage(originalText, shift, processedText);

        printf("*\n");
        printf("Encrypted Message: %s\n", processedText);    // Display encrypted result

    } else if (option == 'D' || option == 'd') {
         // Handle decryption
        printf("Enter encrypted text: ");
        fgets(originalText, sizeof(originalText), stdin);
        originalText[strcspn(originalText, "\n")] = '\0';

        printf("Enter shift key: ");
        scanf("%d", &shift);   // Read Caesar cipher shift value used during encryption

        decryptMessage(originalText, shift, processedText);

        printf("*\n");
        printf("Decrypted Message: %s\n", processedText);   // Display decrypted result
    } else {
        // Handle invalid option
        printf("Invalid input. Please choose 'E' or 'D'.\n");
    }

   return 0;
}
