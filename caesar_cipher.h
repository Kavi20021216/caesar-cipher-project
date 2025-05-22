// header.h
#ifndef HEADER_H
#define HEADER_H

#define SIZE 26


// Alphabet queue initialization and character-level Caesar logic
void initializeQueue();
char shiftEncryptChar(char ch, int key);
char shiftDecryptChar(char ch, int key);

#endif