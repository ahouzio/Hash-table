/*Pour la compilation et l'édition des liens du test tapez : gcc -std=c99 -Wall -Wextra -g directory-03.c ../src/directory.c ../src/contact.c ../src/hash.c -o exe */
/*
  Test du module directory.

  Crée un directory, y rajoute trois entrées, l'affiche et le libère.
  Deux entrées sont en conflit dans ce test.
 */

#include <stdlib.h>

#include "../include/directory.h"
#include "../include/hash.h"
#include "../include/contact.h"

int main(void)
{
    struct dir *dir = dir_create(10);
    dir_insert(dir, "Colonel Moutarde", "06789435351");
    dir_insert(dir, "Caporal Ketchup", "0678346533");
    dir_insert(dir, "Sergent Mayo", "06723236533");
    dir_print(dir);
    dir_free(dir);

    return EXIT_SUCCESS;
}
