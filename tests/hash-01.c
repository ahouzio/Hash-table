
        /*Pour la compilation et l'édition des liens du test tapez : gcc -std=c99 -Wall -Wextra -g hash-01.c ../src/hash.c -o exe */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "../include/hash.h"


/*test l'efficacité de la fonction hash(moins de collisions => plus efficace)*/


int cmpfunc(const void* a, const void* b) {     /*effectue la difference de deux elements d'une liste(utilisé par qsort de notre fonction main)*/
    return (*(int*)a - *(int*)b);
}



int main() {
    const char* long_list[10] = { "Eleri Abbott", /*liste de nom un peu long*/
"Lynda Mcghee",
"Emer Rigby",
"Aryan Vincent",
"Jarrod Ortiz",
"Lorelei Mccallum",
"Kristin Mccann",
"Nicolle Moreno",
"Steve Mccall",
"Meadow Gray"
    };
    const char* short_list[10] = { "Aspha",     /*liste de noms courts*/
"Oeveage",
"Cho",
"Lue",
"So",
"Bhugena",
"Eave Dob",
"Ayth Knai",
"Iw Oysch",
"Oet" };

    /*On applique la fonction hash a tous les elements de chaque liste*/

    uint32_t hash_long[10];
    uint32_t hash_short[10];

    for (int i = 0; i < 10; ++i) {
        hash_long[i] = hash(long_list[i]) % 10;
        hash_short[i] = hash(short_list[i]) % 10;
    }

    uint32_t short_collisions = 0;
    uint32_t long_collisions = 0;


    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 10; ++j) {

            if (hash_long[i] == hash_long[j]) {
                ++long_collisions;
            }

            if (hash_short[i] == hash_short[j]) {
                ++short_collisions;
            }
        }
    }
    uint32_t score = 20 - (short_collisions + long_collisions);
    printf("Le score de ta fonction de hachage est : %i / 20 \n", score);

    return 0;
}