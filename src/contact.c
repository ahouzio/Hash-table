
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/*
  Un contact représente une association {nom, numéro}.Il est représenté ici par une cellule d'une liste chainée simple.
*/

extern struct list {
    const char *nom;
    const char *tel;
    struct list *suiv;
};



void supprimer_premiere_occurrence(struct list** l, char const *name, uint32_t *contacts)
{
    struct list* debut = *l;
   
    while ((*l)->suiv != NULL && (*l)->suiv->nom != name) {
        (*l) = (*l)->suiv;
    }
    
    if ((*l)->suiv != NULL) {
        
        struct list* style = (*l)->suiv;
        (*l)->suiv = style->suiv;
        free(style);
        if ((*l)->suiv == NULL) {
            *contacts -= 1;
        }
        *l = debut;
        return;
    }
    
}

void ajouter_queue(struct list** l, char const* name, char const* number,uint32_t *contacts) {

    struct list* queue = calloc(1, sizeof(struct list));


    queue->nom = name;
    queue->tel = number;   /*Ici je definie les parametre de ma nouvelle cellule*/
    queue->suiv = NULL;


  
    struct list *debut = *l;

    while ((*l)->suiv != NULL) {
        if ((*l)->suiv->nom != name) {
            *l = (*l)->suiv;
        }
        else {
            (*l)->suiv->tel = number;
            return;
        }
    }

    /*On a pas trouvé le nom dans les contacts, on l'ajoute a la fin de notre liste*/

    if ((*l)->nom == NULL){ /*cas d'une liste vide*/
        (*l)->suiv = queue;
        *contacts += 1;
  
    }
    else {
        (*l)->suiv = queue;
       
    }
    *l = debut;
}
    

void afficher(struct list* l) 
{
    while (l->suiv != NULL) {
        l = l->suiv;
        printf("%s %s -> ", l->nom,l->tel);
        
    }
    printf("\n");
}


void list_free(struct list* l) {   /*Libere la mémoire de la liste chainée*/
    l = l->suiv;
    while (l != NULL) {
        struct list* cellule = l;
        l = l->suiv;
        free(cellule);
    }
}