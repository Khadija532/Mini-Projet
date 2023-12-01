//
//  main.c
//  Création des employés
//
//  Created by Macbook Pro  on 29/11/2023.
//

#include <stdio.h>
#include <stdlib.h>

struct date {
    int j;
    int m;
    int a;
};

struct employe {
    int mat;
    char nom[20];
    char prenom[20];
    char adresse[50];
    struct date DE; /* date d'embauche */
    int telephone;
    char service;
    float salairebrut;
    struct employe *suiv;
};

typedef struct employe *liste_emp;

// Fonction pour obtenir la taille de la liste
int taille_liste_emp(liste_emp LE) {
    int taille = 0;
    while (LE != NULL) {
        taille++;
        LE = LE->suiv;
    }
    return taille;
}

// Fonction pour rechercher un employé par matricule
struct employe *recherche_emp(liste_emp LE, int num) {
    while (LE != NULL) {
        if (LE->mat == num) {
            return LE;
        }
        LE = LE->suiv;
    }
    return NULL; // Matricule non trouvé
}

// Fonction pour insérer un employé au début de la liste
void insere_tete_emp(liste_emp *LE, struct employe *nouvelEmp) {
    nouvelEmp->suiv = *LE;
    *LE = nouvelEmp;
}

// Fonction pour créer un nouvel employé
struct employe *creer_employe(liste_emp *LE) {
    struct employe *nouvelEmp = (struct employe *)malloc(sizeof(struct employe));

    printf("Matricule : ");
    scanf("%d", &nouvelEmp->mat);

    // Vérifier l'unicité du matricule
    while (recherche_emp(*LE, nouvelEmp->mat) != NULL) {
        printf("Matricule déjà existant. Entrez un matricule unique : ");
        scanf("%d", &nouvelEmp->mat);
    }

    printf("Nom : ");
    scanf("%s", nouvelEmp->nom);

    printf("Prénom : ");
    scanf("%s", nouvelEmp->prenom);

    // Ajouter du code ici pour saisir d'autres informations sur l'employé
    // ...

    nouvelEmp->suiv = NULL;

    return nouvelEmp;
}

// Fonction pour créer une liste d'employés
void CREATION(liste_emp *LE) {
    int position;
    int continuer;

    do {
        struct employe *nouvelEmp = creer_employe(LE);

        printf("Position dans la liste (1 pour ajouter en tête) : ");
        scanf("%d", &position);

        if (position < 1 || position > taille_liste_emp(*LE) + 1) {
            printf("Position invalide. L'employé sera ajouté en tête.\n");
            position = 1;
        }

        if (position == 1) {
            insere_tete_emp(LE, nouvelEmp);
        } else {
            struct employe *temp = *LE;
            for (int i = 1; i < position - 1; i++) {
                temp = temp->suiv;
            }
            nouvelEmp->suiv = temp->suiv;
            temp->suiv = nouvelEmp;
        }

        printf("Voulez-vous ajouter un autre employé ? (1 pour Oui, 0 pour Non) : ");
        scanf("%d", &continuer);

    } while (continuer == 1);
}

// Fonction pour afficher le menu général
void afficher_menu_general() {
    printf("\n\t\tMENU GÉNÉRAL\n");
    printf("1- Création des employés\n");
    printf("2- Mise à jour de la liste des employés\n");
    printf("3- Calcul et affichage des salaires des employés\n");
    printf("4- Recherche, affichage et Tri\n");
    printf("5- Quitter\n");
}

// Fonction pour afficher le menu de mise à jour
void afficher_menu_maj() {
    printf("\n\t\tMenu MAJ\n");
    printf("1- Ajouter un nouvel employé\n");
    // ... (Autres options de mise à jour)
    printf("4- Retour Menu général\n");
}

// Fonction pour afficher le menu d'ajout
void afficher_menu_ajouter() {
    printf("\n\t\tMenu Ajouter\n");
    printf("1- Ajout en tête\n");
    printf("2- Ajout en queue\n");
    printf("3- Ajout dans une position\n");
    printf("4- Retour au menu MAJ\n");
}

// ... (Autres fonctions de menu)

int main() {
    liste_emp LE = NULL;

    int choix, choix_maj, choix_ajout;

    do {
        afficher_menu_general();
        printf("Donnez votre choix SVP : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                CREATION(&LE);
                break;

            // ... (Autres cas dans le menu principal)

            case 5:
                // Quitter
                break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 5);

    // ... (Nettoyage et libération de mémoire si nécessaire)

    return 0;
}
