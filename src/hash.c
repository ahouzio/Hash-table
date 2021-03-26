#include <stdlib.h>
#include <stdint.h>
#include "../include/directory.h"
#include <stdio.h>


/*Implémentationdes fonction de hachages*/
extern uint32_t hash(const char *str)
{
    int i = 0;
    char c = str[i];
    uint32_t hash = 5381;

    while (c != '\0') {
        hash = 33 * hash + c;
        ++i;
        c = str[i];
    }

    return hash; 
}