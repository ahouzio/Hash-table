    /*Pour la compilation et l'�dition des liens du test tapez : gcc -std=c99 -Wall -Wextra -g directory-05.c ../src/directory.c ../src/contact.c ../src/hash.c -o exe */
/*
  Test du module directory.

  Suppression dans un directory.
 */

#include <stdlib.h>
#include <stdio.h>

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

    const char *names[4] = {
        "Colonel Moutarde",
        "Tartempion",
        "Caporal Ketchup",
        "Sergent Mayo"
    };

    for (size_t id = 0; id < 4; id++) {
        dir_delete(dir, names[id]);
        dir_print(dir);
    }

    dir_free(dir);

    return EXIT_SUCCESS;
}
