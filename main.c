#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Fonction qui affiche le menu qui présente les différent mode de Jeu
int menuModeJoueur()
{
    int choix = 0;

    while (choix < 1 || choix > 2)
    {
        printf("Menu Mode Joueur:\n");
        printf("1. Mode 1 Joueur\n");
        printf("2. Mode 2 Joueurs\n");
        printf("Votre choix ? ");
        scanf("%d",&choix);
        if(choix < 1 || choix > 2){
            printf("Mauvais choix. Veuillez reesayer en choisissant l'option 1 ou 2\n");
        }
    }

    return choix;
}

//Fonction qui affiche le menu qui présente les différent niveau de difficultés
int menuNiveauxDificulter()
{
    int choix = 0;

    while (choix < 1 || choix > 3)
    {
        printf("Menu Niveaux de Dificulter:\n");
        printf("1. entre 1 et 100\n");
        printf("2. entre 1 et 1000\n");
        printf("3. entre 1 et 10000\n");
        printf("Votre choix ? ");
        scanf("%d",&choix);
        if(choix < 1 || choix > 3){
            printf("Mauvais choix. Veuillez reesayer en choisissant l'option 1, 2 ou 3\n");
        }
    }

    return choix;
}

//Fonction qui affiche le menu qui présente les différent option pour continuer ou arreter une partie
int menuContinuerPartie()
{
    int choix = 0;

    while (choix < 1 || choix > 2)
    {
        printf("Menu Continuer Partie:\n");
        printf("1. Non \n");
        printf("2. Oui \n");
        printf("Votre choix ? ");
        scanf("%d",&choix);
        if(choix < 1 || choix > 2){
            printf("Mauvais choix. Veuillez reesayer en choisissant l'option 1 ou 2\n");
        }
    }

    return choix;
}

/*Fonction qui prend en parametre un min et un max et fais jouer une
partie a un joueur en lui fesant deviner un nombre geenere de maniere aléatoire*/
void partieModeJoueur1(int MIN, int MAX)
{
    int nombreMystere = 0, coups = 1, proposition = 0;
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

    do{
        printf("\nQuel est le nombre ? ");
        scanf("%d",&proposition);
        if(proposition > MAX || proposition < MIN)
            printf("Votre proposition doit estre compris entre 1 et %d\n", MAX);
        else if(proposition > nombreMystere)
            printf("C'est moin !\n");
        else if(proposition < nombreMystere)
            printf("C'est plus !\n");
        else
            printf("Bravo, vous avez trouve le nombre mystere en %d coups !!!\n\n",coups);
        coups++;
    }while(proposition != nombreMystere);
}

/*Fonction qui prend en parametre un min et un max et fais jouer une partie a deux
joueurs en demandant d'abord au joueur 1 un nombre qui sera deviner par le Joueur 2
Puis au tour du joueur 2 d'entrer un nombre qui sera deviner par le Joueur 1.*/

void partieModeJoueur2(int MIN, int MAX)
{
    int nombreJoueur = 0, coups = 1, propositionJoueur = 0;

    while(nombreJoueur < MIN || nombreJoueur > MAX){
        printf("Joueur 1 entrer un nombre compris entre %d et %d: ", MIN, MAX);
        scanf("%d", &nombreJoueur);
    }
    system("cls");
    do{
        printf("\nJoueur 2 Quel est le nombre ? ");
        scanf("%d",&propositionJoueur);
        if(propositionJoueur > MAX || propositionJoueur < MIN)
            printf("Votre proposition doit estre compris entre 1 et %d\n", MAX);
        else if(propositionJoueur > nombreJoueur)
            printf("C'est moin !\n");
        else if(propositionJoueur < nombreJoueur)
            printf("C'est plus !\n");
        else
            printf("Bravo Joueur 2, vous avez trouve le nombre mystere en %d coups !!!\n\n",coups);
        coups++;
    }while(propositionJoueur != nombreJoueur);

    printf("Au tour du Joueur 2 pour fais deviner son nombre\n");
    nombreJoueur = 0;

    while(nombreJoueur < MIN || nombreJoueur > MAX){
        printf("Joueur 2 entrer un nombre compris entre %d et %d: ", MIN, MAX);
        scanf("%d", &nombreJoueur);
    }
    system("cls");
    do{
        printf("\nJoueur 1 Quel est le nombre ? ");
        scanf("%d",&propositionJoueur);
        if(propositionJoueur > MAX || propositionJoueur < MIN)
            printf("Votre proposition doit estre compris entre 1 et %d\n", MAX);
        else if(propositionJoueur > nombreJoueur)
            printf("C'est moin !\n");
        else if(propositionJoueur < nombreJoueur)
            printf("C'est plus !\n");
        else
            printf("Bravo Joueur 1, vous avez trouve le nombre mystere en %d coups !!!\n\n",coups);
        coups++;
    }while(propositionJoueur != nombreJoueur);


}

int main()
{
    const int MIN=1, MAX1=100, MAX2=1000, MAX3=10000;
    int continuerPartie = 1;
    srand(time(NULL));

        switch(menuModeJoueur()){
        case 1:
            switch(menuNiveauxDificulter()){
            case 1:
                do{
                    partieModeJoueur1(MIN,MAX1);
                    continuerPartie=menuContinuerPartie();
                }
                while(continuerPartie != 1);
                break;

            case 2:
                do{
                    partieModeJoueur1(MIN,MAX2);
                    continuerPartie=menuContinuerPartie();
                }
                while(continuerPartie != 1);
                break;

            case 3:
                do{
                    partieModeJoueur1(MIN,MAX3);
                    continuerPartie=menuContinuerPartie();
                }
                while(continuerPartie != 1);
                break;
            default:
                printf("Mauvais choix");
            }
            break;

        case 2:
            switch(menuNiveauxDificulter()){
                case 1:
                    do{
                        partieModeJoueur2(MIN,MAX1);
                        continuerPartie=menuContinuerPartie();
                    }
                    while(continuerPartie != 1);
                    break;

                case 2:
                    do{
                        partieModeJoueur2(MIN,MAX2);
                        continuerPartie=menuContinuerPartie();
                    }
                    while(continuerPartie != 1);
                    break;

                case 3:
                    do{
                        partieModeJoueur2(MIN,MAX3);
                        continuerPartie=menuContinuerPartie();
                    }
                    while(continuerPartie != 1);
                    break;
                default:
                    printf("Mauvais choix");
                }
                break;

        default:
            printf("Mauvais choix");
        }

    return 0;
}
