#include <stdlib.h>
#include <stdio.h>


extern struct list {
    const char* nom;
    const char* tel;
    struct list* suiv;
};



int main(void) {

    char tampon[10];
    fgets(tampon, 10, stdin);
    printf("%s", tampon);
    int annee = strtoul(tampon, NULL, 0);
    annee = strtoul(tampon, NULL, 0);
    printf("%i", annee);

    return 0;


}	