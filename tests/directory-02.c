/*Pour la compilation et l'édition des liens du test tapez : gcc -std=c99 -Wall -Wextra -g directory-02.c ../src/directory.c ../src/contact.c ../src/hash.c -o exe */

/*
  Test du module directory.

  Crée un annuaire, y rajoute une entrée, l'affiche et le libère.
 */



#include <stdlib.h>
#include "../include/directory.h"
#include "../include/hash.h"
#include "../include/contact.h"


int main(void)
{
    struct dir *dir = dir_create(5);
    dir_insert(dir, "Colonel Moutarde", "06789435351");
    dir_print(dir);
    dir_free(dir);

    return EXIT_SUCCESS;
}
