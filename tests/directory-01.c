/*Pour la compilation et l'édition des liens du test tapez : /*Pour la compilation et l'édition des liens du test tapez : gcc contact.c "PATH TO LIBRARY" -ldirectory -o exe */

/*
  Test du module directory.

  Crée un annuaire et le libère.
 */

#include <stdlib.h>

#include "../include/directory.h"
#include "../include/hash.h"
#include "../include/contact.h"

int main(void)
{
    struct dir *dir = dir_create(5);
    dir_free(dir);

    return EXIT_SUCCESS;
}