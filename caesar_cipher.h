#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#define SIZE 26


// Initializes the circular alphabet queue with letters A–Z.
void initializeQueue();

// Encrypts a single character by shifting forward in the queue.
char shiftEncryptChar(char ch, int key);

// Decrypts a single character by shifting backward in the queue.
char shiftDecryptChar(char ch, int key);

//Full message Caesar logic
void encryptMessage(const char *input,int key, char *output);
void decryptMessage(const char *input,int key, char *output);

#endif
