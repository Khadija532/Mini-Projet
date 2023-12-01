//
//  main.c
//  Mise à jour de la liste des employés
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

// Affiche le menu général
void afficher_menu_general() {
    printf("\n\t\tMENU GÉNÉRAL\n");
    printf("1- Création des employés\n");
    printf("2- Mise à jour de la liste des employés\n");
    printf("3- Calcul et affichage des salaires des employés\n");
    printf("4- Recherche, affichage et Tri\n");
    printf("5- Quitter\n");
}

// Affiche le menu de mise à jour
void afficher_menu_maj() {
    printf("\n\t\tMenu MAJ\n");
    printf("1- Ajouter un nouvel employé\n");
    printf("2- Supprimer un employé\n");
    printf("3- Modifier les données d'un employé\n");
    printf("4- Retour Menu général\n");
}

// Affiche le menu d'ajout
void afficher_menu_ajouter() {
    printf("\n\t\tMenu Ajouter\n");
    printf("1- Ajout en tête\n");
    printf("2- Ajout en queue\n");
    printf("3- Ajout dans une position\n");
    printf("4- Retour au menu MAJ\n");
}

// Affiche le menu de suppression
void afficher_menu_suppression() {
    printf("\n\t\tMenu Suppression\n");
    printf("1- Suppression en tête\n");
    printf("2- Suppression en queue\n");
    printf("3- Suppression à partir d'une position\n");
    printf("4- Suppression d'un employé donné\n");
    printf("5- Suppression des employés d'un service\n");
    printf("6- Retour au menu MAJ\n");
}

// Affiche le menu de modification
void afficher_menu_modification() {
    printf("\n\t\tMenu Modification\n");
    printf("1- Adresse\n");
    printf("2- Téléphone\n");
    printf("3- Retour au menu MAJ\n");
}

//  fonctions pour ajouter, supprimer et modifier des employés.

int main() {
    liste_emp LE = NULL;
    int choix, choix_maj, choix_ajout, choix_suppression, choix_modification;

    do {
        afficher_menu_general();
        printf("Donner votre choix SVP : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                // le code pour la création des employés
                break;

            case 2:
                do {
                    afficher_menu_maj();
                    printf("Donner votre choix SVP : ");
                    scanf("%d", &choix_maj);

                    switch (choix_maj) {
                        case 1:
                            do {
                                afficher_menu_ajouter();
                                printf("Donner votre choix SVP : ");
                                scanf("%d", &choix_ajout);

                                switch (choix_ajout) {
                                    case 1:
                                        // Ajout en tête
                                        break;
                                    case 2:
                                        // Ajout en queue
                                        break;
                                    case 3:
                                        // Ajout dans une position
                                        break;
                                    case 4:
                                        // Retour au menu MAJ
                                        break;
                                    default:
                                        printf("Choix invalide. Veuillez réessayer.\n");
                                }
                            } while (choix_ajout != 4);
                            break;

                        case 2:
                            do {
                                afficher_menu_suppression();
                                printf("Donner votre choix SVP : ");
                                scanf("%d", &choix_suppression);

                                switch (choix_suppression) {
                                    case 1:
                                        // Suppression en tête
                                        break;
                                    case 2:
                                        // Suppression en queue
                                        break;
                                    case 3:
                                        // Suppression à partir d'une position
                                        break;
                                    case 4:
                                        // Suppression d'un employé donné
                                        break;
                                    case 5:
                                        // Suppression des employés d'un service
                                        break;
                                    case 6:
                                        // Retour au menu MAJ
                                        break;
                                    default:
                                        printf("Choix invalide. Veuillez réessayer.\n");
                                }
                            } while (choix_suppression != 6);
                            break;

                        case 3:
                            do {
                                afficher_menu_modification();
                                printf("Donner votre choix SVP : ");
                                scanf("%d", &choix_modification);

                                switch (choix_modification) {
                                    case 1:
                                        // Modification de l'adresse
                                        break;
                                    case 2:
                                        // Modification du téléphone
                                        break;
                                    case 3:
                                        // Retour au menu MAJ
                                        break;
                                    default:
                                        printf("Choix invalide. Veuillez réessayer.\n");
                                }
                            } while (choix_modification != 3);
                            break;

                        case 4:
                            // Retour au menu général
                            break;

                        default:
                            printf("Choix invalide. Veuillez réessayer.\n");
                    }
                } while (choix_maj != 4);
                break;

            //cas pour les autres fonctionnalités

            case 5:
                // Quitter
                break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 5);

    

    return 0;
}
