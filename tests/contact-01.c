/*Pour la compilation et l'édition des liens du test tapez : gcc -std=c99 -Wall -Wextra -g contact-01.c ../src/contact.c -o exe */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "../include/contact.h"


int main() {
	struct list *liste = calloc(1,sizeof(struct list));
	char const* noms[10] = { "Jaime Hughes",
"Pearl Bostock",
"Edie Povey",
"Riley James Fernandez",
"Keanan Conway",
"Allen Medina",
"Sophie Louise Redfern",
"Kara Padilla",
"Brianna Dunn",
"Neal Peck" };
	char const* tele[10] = { "0142364327",
"0370078789",
"0265201206",
"0356036783",
"0143379995",
"0164987569",
"0408859122",
"0344801733",
"0183074726",
"0174731470" };
	uint32_t contacts = 0;

	for (int i = 0; i < 10; ++i) {
		ajouter_queue(&liste,noms[i],tele[i],&contacts);
		
	}
	afficher(liste);
	
	supprimer_premiere_occurrence(&liste, "Kara Padilla", &contacts);
	afficher(liste);
	list_free(liste);

	return 0;
}