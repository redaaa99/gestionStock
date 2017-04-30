#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <errno.h>
#include "Gestion.h"
#include "Sauvgarde.h"

void NouvelleBase();
void MenuGestion();
void MenuPrincipale();




void NouvelleBase(){
  int answer;
  int N=0;
  Article *Liste=NULL;
  printf("\t\tCREATION D'UNE NOUVELLE BASE DE DONNEES\t\t");
  while(answer!=0)
    {
    printf("\n\nTaper : 1 : Ajouter un nouvel Article\nTapez : 0 Base de Donnees Vide\n");
    scanf("%d",&answer);
    if(answer!=0){
      system("cls");
      AjouterFin(&Liste,CreerArticle(N));
      N++;
    }
    system("cls");
  }
  system("cls");
  printf("\nLISTE CREE DE TAILLE : %d\n",Taille(Liste));
  CreerFichier(Liste,N);





}
void MenuGestion(){
  int seuil;
  Article* Liste=NULL;
  int N;
  Liste = LireFichier(&N);
  int reponse;



  int ID;
  do{

    system("cls");
    printf("\n\nVeuillez choisir une option: \n\n   Taper '1' Affichage de la base de donnees.\n   Taper '2' Rechercher un article.\n   Taper '3' Supprimer un article.\n   Taper '4' Modifier un article.\n   Taper '5' Trier la base de donnees.\n   Taper '6' Ajouter un nouvel article.\n   Taper '7' Afficher la liste des articles par rubrique.\n   Taper '8' Afficher la liste des articles par quantite suivant un seuil .\n   Taper '9' Afficher la liste des articles par rayon.\n   Taper '10'Eliminer les doublons.\n   Taper '11'Charger le stock.\n   Taper '12'Decharger le stock.\n   Taper '13'Pour enregistrer-sous la base de donnees.\n   Taper '14'Pour afficher la taille \n   Taper '0'  Pour retourner ves le menu principale.\n\nDonner votre option : ");
    scanf("%d",&reponse);

    switch(reponse){
      case 0: {
          MenuPrincipale();}
      case 1:{
          system("cls");AfficherListe(Liste); system("pause"); system("cls"); reponse=16; break;
      }
      case 2:{
              system("cls"); printf("Donner l'ID de l' Aricle a afficher : "); scanf("%d",&ID); RechercheArticle(Liste,ID); system("pause"); system("cls"); reponse=16; break;

      }
      case 3:{
          system("cls"); printf("Donner l'ID de l  a supprimer : "); scanf("%d",&ID); SupprimerArticle(&Liste,ID); system("pause"); system("cls"); reponse=16; break;
      }
      case 4:{
          system("cls"); printf("Donner l'ID de l article a modifier : "); scanf("%d",&ID); ModifierArticle(Liste,ID); system("pause"); system("cls"); reponse=16; break;
      }
      case 5:{
          system("cls"); TrierListe(Liste); printf("Votre base de donnees est triee\n\n"); system("pause"); system("cls"); reponse=16; break;
      }
      case 6:{
          system("cls"); AjouterFin(&Liste,CreerArticle(N)); N++; printf("\n\nL article est ajoute.\n\n"); system("pause"); system("cls"); reponse=16; break;
      }
      case 7:{

          system("cls");
              {

             char  rub[30];
             int choix6;
          do{
            printf("\nEntrez la Rubrique:\n");
            printf("\nTapez 0 : Fourniture de bureau \n Tapez 1 : Materiel informatique \n Tapez 2 :Produit de nettoyage \n Tapez 3 : Materiel d enseignement \n");
            scanf("%d",&choix6);
            }while(choix6!=0 && choix6!=1 && choix6!=2 && choix6!=3 );
        switch (choix6){
            case 0 : strcpy(rub,"Fourniture de bureau");break;
            case 1 : strcpy(rub,"Materiel informatique");break;
            case 2 : strcpy(rub,"Produit de nettoyage");break;
            case 3 : strcpy(rub,"Materiel d enseignement");break;
        }

          AfficherListe(ListeParRubrique(Liste,rub));

      } system("pause"); system("cls"); reponse=16; break;}
      case 8:{
          system("cls"); printf("\n\n Donnez le seuil de quantite des articles que vous voulez ");
          scanf("%d",&seuil);
          AfficherListe(ListeParQuantity(Liste,seuil));
          system("pause");
          system("cls");
          reponse=16;
          break;
	  }
     case 9:{
	      int ray;
	      system("cls");
	      do{
        printf("Donnez le rayon des articles que vouz voulez ( 1 a 5)  \n :  ");
        scanf("%d",&ray);
        }while(((ray)<1) || ((ray)>5));

        AfficherListe(ListeParRayon(Liste,ray));system("pause"); system("cls"); reponse=16; break;
	  }
	  case 10:{
        system("cls");ElimineDoublons(Liste);printf("\n \n DOUBLONS ELIMINES \n \n");system("pause"); system("cls"); reponse=16; break;
     }
	 case 11:{
             int ID;
             int charge;
             system("cls");
             printf("\n\nENTREZ L'ID DU STOCK QUE VOUS VOULEZ ALIMENTER\n\n");
             scanf("%d",&ID);
             printf("\n\nENTREZ LA QUANTITE AVEC LAQUELLE VOUS VOULEZ ALIMENTER\n\n");
             scanf("%d",&charge);
             ChargerStock(Liste,ID,charge);
             system("pause");
             system("cls");
             reponse=16;
             break;

    }
	case 12:{
            int ID;
             int decharge;
             system("cls");
             printf("\n\nENTREZ L'ID DU STOCK QUE VOUS VOULEZ DECREMENTER\n\n");
             scanf("%d",&ID);
             printf("\n\nENTREZ LA QUANTITE AVEC LAQUELLE VOUS VOULEZ DECREMENTER\n\n");
             scanf("%d",&decharge);
             DechargerStock(Liste,ID,decharge);
             system("pause");
             system("cls");
             reponse=16;
             break;

    }
      case 13:{
	      system("cls"); CreerFichier(Liste,N); system("pause"); system("cls"); reponse=16; break;
	  }
     case 14:{
	      system("cls");
	      printf("la Taille est %d",Taille(Liste));
	      system("pause");
	      system("cls");
	      reponse=16;
	      break;
    }







    }

  }while(reponse!=0 && reponse!=1 && reponse!=2 && reponse!=3 && reponse!=4 && reponse!=5 && reponse!=6 && reponse!=7 && reponse!=8 && reponse!=9 && reponse!=10 );

}
void MenuPrincipale(){
  int answer;
  do{
    system("cls");
    printf("\nTaper '1': Creer nouvelle base de donnees.\nTaper '2': Gestion d'une base de donnees existante.\nTaper '0' Quitter le programme\n");
    scanf("%d",&answer);
    switch(answer)

    {
      case 0:
          {
              system("cls");
              printf("\n\n    MERCI POUR VOTRE VISITE     \n\n ");
              exit(-1);
          }
      case 1:
          {
          system("cls");
          NouvelleBase();
          system("cls");
          answer=3;
          break;
          }

      case 2:
          {
              system("cls");
              MenuGestion();
              system("cls");
              answer=3;
              break;
          }
    }
  }while(answer!=0 && answer!=1 && answer!=2 );
}
