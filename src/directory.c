

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "../include/hash.h"
#include "../include/contact.h"



/*
Cree une structure dir
*/
struct dir { /*dir sera défini comme une liste de liste chainées que je peux créer à l'aide de calloc*/

    uint32_t len; /*nombre d'entrées de l'annuaire*/

    uint32_t contacts;  /*nombre de contacts disponible dans l'annuaire*/

    struct list *start; 
                         
};




/*
  Crée un nouvel annuaire contenant _len_ listes vides
*/
struct dir *dir_create(uint32_t lenght)
{
    
    struct dir* annuaire = malloc(sizeof(struct dir));
    struct list *ptr = calloc(lenght, sizeof(struct list));
    annuaire->start = ptr;
    annuaire->len = lenght;
    annuaire->contacts = 0;
    return annuaire;
}




/*
  Insère un nouveau contact dans l'annuaire _dir_, construit à partir des nom et
  numéro passés en paramètre. Si il existait déjà un contact du même nom, son
  numéro est remplacé et la fonction retourne une copie de l'ancien numéro.
  Sinon, la fonction retourne NULL.
*/
const char *dir_insert(struct dir *dir, const char *name, const char *num)
{
    uint32_t cle = hash(name) % (dir->len);

    struct list* ptr = &(dir->start)[cle];
    struct list** ptrr = &(ptr);
    ajouter_queue(ptrr, name, num, &(dir->contacts));      //On commence la recherche dans la liste chaine numero cle

    

    /*On verifie si notre table devrait s'aggrandir*/
    if ((float)(dir->contacts) >= 0.75 * (dir->len)) {
        struct dir* dir_1 = dir_create((dir->len) * 2); /*Création d'un nouvel annuaire ayant le double de la taille de l'ancien*/
        for (uint32_t i = 0; i < dir->len; ++i) {
            struct list *liste = &dir->start[i];
            while (liste->suiv != NULL) {
                const char* nam = liste->suiv->nom;
                const char* tele = liste->suiv->tel;
                uint32_t cle = hash(nam) % (dir_1->len);
                struct list* ptr = &(dir_1->start)[cle];
                struct list** ptrr = &(ptr);
                ajouter_queue(ptrr, nam, tele, &(dir_1->contacts));
                liste = liste->suiv;
            }
        }
        dir->start = dir_1->start;
        dir->len = dir_1->len;
        dir->contacts = dir_1->contacts;
    }
    return 0;
    
}



/*
  Retourne le numéro associé au nom _name_ dans l'annuaire _dir_. Si aucun contact
  ne correspond, retourne NULL.
*/
const char *dir_lookup_num(struct dir *dir, const char *name)
{

    for (uint32_t i = 0; i < (dir->len); ++i) {

        struct list *contact = &((dir->start)[i]);
        while (contact->suiv != NULL) {
            if (contact->suiv->nom != name) {
                contact = contact->suiv;
            }
            else {
                return contact->suiv->tel;
            }
        }    
    }
    return NULL;
}


uint32_t max(uint32_t a, uint32_t b) {
    if (a <= b) {
        return b;
    }
    return a;
}


/*
  Supprime le contact de nom _name_ de l'annuaire _dir_. Si aucun contact ne
  correspond, ne fait rien.
*/
void dir_delete(struct dir* dir, const char* name)
{
    if (dir->start == NULL) {
        return;
    }

    for (uint32_t i = 0; i < (dir->len); ++i) {
        struct list* ptr = &(dir->start)[i];
        struct list** ptrr = &(ptr);
        supprimer_premiere_occurrence(ptrr, name, &(dir->contacts));

    }
    if ((float)(dir->contacts) <= 0.15 * (dir->len)) {
        struct dir* dir_1 = dir_create(max(10, (dir->len) / 2));
        for (uint32_t i = 0; i < dir->len; ++i) {
            struct list *liste = &((dir->start[i]));
            while (liste->suiv != NULL) {
                const char* nam = liste->suiv->nom;
                const char* tele = liste->suiv->tel;
                uint32_t cle = hash(nam) % (dir_1->len);
                struct list* ptr = &(dir_1->start)[cle];
                struct list** ptrr = &(ptr);
                ajouter_queue(ptrr, nam, tele, &(dir_1->contacts));
                liste = liste->suiv;
            }
        }
        dir->start = dir_1->start;
        dir->len = dir_1->len;
        dir->contacts = dir_1->contacts;
    }
}



/*
  Libère la mémoire associée à l'annuaire _dir_.
*/

void dir_free(struct dir *dir)
{
    for (uint32_t i = 0; i < dir->len; ++i) {
        struct list* ma_liste = &dir->start[i];
        list_free(ma_liste);
    }
    free(dir->start);   /*libere l'espace memoire de la liste T*/
    free(dir);
}

/*
  Affiche sur la sortie standard le contenu de l'annuaire _dir_.
*/
void dir_print(struct dir* dir)
{
    printf("ANNUAIRE : \n");
    for (uint32_t i = 0; i < (dir->len); ++i){
        struct list* ma_liste = &dir->start[i];
        afficher(ma_liste);
    }
    printf("FIN \n");
}