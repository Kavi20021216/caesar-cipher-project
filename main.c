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