#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#define SIZE 26


// Alphabet queue initialization and character-level Caesar logic
void initializeQueue();
char shiftEncryptChar(char ch, int key);
char shiftDecryptChar(char ch, int key);

//Full message Caesar logic
void encryptMessage(const char *input,int key, char *output);
void decryptMessage(const char *input,int key, char *output);

#endif
