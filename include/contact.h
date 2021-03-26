#ifndef _CONTACT_H_
#define _CONTACT_H_

/*
  Un contact représente une association {nom, numéro}.Il est représenté ici par une cellule d'une liste chainée simple.
*/



extern struct list {
    const char* nom;
    const char* tel;
    struct list* suiv;
};




/*Supprime la premiere occurence d'un element de notre liste*/
extern void supprimer_premiere_occurrence(struct list** pl, char const* name, uint32_t *contacts);

/*Ajouter une cellule au queue de la liste chainée*/
extern void ajouter_queue(struct list** p1, char const* name,char const* number, uint32_t *contacts);


/*Affiche le contenu d'une liste chainée*/
extern void afficher(struct list* l);

void list_free(struct list* l);

#endif /* _CONTACT_H_ */
