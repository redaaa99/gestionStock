#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <errno.h>


typedef struct{
    int ID;
    char Rubrique[30];
    char Unit[10];
    char Designation[50];
    int quantity;
    unsigned int Rayon;
    struct Article *suivant;

}Article;



Article* ListeParRubrique(Article* Liste,char* Rubrique);
Article* CreerArticle(int N);
void AfficherArticle(Article A);
void AfficherListe(Article *Liste);
void AjouterFin(Article** AdrListe,Article* AdrA);
Article* ListeParQuantity(Article *Liste,int Seuil);
Article* ListeParRayon(Article* Liste,int Rayon);
void SupprimerArticle(Article**AdrListe,int ID);
void RechercheArticle(Article*AdrListe,int ID);
void ModifierArticle(Article *Liste,int ID);
void TrierListe(Article *Liste);
void ChargerStock(Article* Liste,int ID,int Quantity);
void DechargerStock(Article* Liste,int ID,int Quantity);
void ElimineDoublons(Article* Liste);
int Taille(Article* Liste);


void AfficherListe(Article* Liste){
   Article* TMP = Liste;
   if(TMP==NULL)
   {
       printf("\nLA LISTE VIDE!!\n");

   }
   else
    {
    while(TMP)
    {
        AfficherArticle(*TMP);
        printf("\n\n");
        TMP = TMP->suivant;

    }


   }

}
Article* CreerArticle(int N){

    Article *NvArticle=(Article*)malloc(sizeof(Article));
    NvArticle->ID=N+1;
    int choix;
    int choix1;

    do{
        printf("entrez la Rubrique de votre article\n");
        printf("tapez 0 : Fourniture de bureau \n tapez 1 : Materiel informatique \n tapez 2 :Produit de nettoyage \n tapez 3 : Materiel d enseignement \n");
        scanf("%d",&choix);
    }while(choix!=0 && choix!=1 && choix!=2 && choix!=3 );
   switch (choix){
       case 0 : strcpy(NvArticle->Rubrique,"Fourniture de bureau");break;
       case 1 : strcpy(NvArticle->Rubrique,"Materiel informatique");break;
       case 2 : strcpy(NvArticle->Rubrique,"Produit de nettoyage");break;
       case 3 : strcpy(NvArticle->Rubrique,"Materiel d enseignement");break;
   }

    do{
        printf("Donnez Une unite : \n");
        printf("Tapez 0 :  KG \n");
        printf("Tapez 1 :  Boite  \n");
        printf("Tapez 2 :  Litre  \n");
        printf("Tapez 3 :  Unite  \n");
        scanf("%d",&choix1);
    }while(choix1!=0 && choix1!=1 && choix1!=2 && choix1!=3 );

    switch (choix1){
        case 0 : strcpy(NvArticle->Unit,"KG");break;
        case 1 : strcpy(NvArticle->Unit,"Boite");break;
        case 2 : strcpy(NvArticle->Unit,"Litre");break;
        case 3 : strcpy(NvArticle->Unit,"Unite");break;
    }
    getchar();
    printf("Donnez le nom de l'article\t:");
    gets(NvArticle->Designation);
    printf("Donnez la quantite \t:");
    scanf("%d",&NvArticle->quantity);

    do{
        printf("Donnez le Numero du rayon de l'article de 1 a 5 \t :  ");
        scanf("%d",&NvArticle->Rayon);

    }while(((NvArticle->Rayon)<1) || ((NvArticle->Rayon)>5));

    NvArticle->suivant=NULL;
    return NvArticle;
}
void AfficherArticle(Article A){

    printf("\n \n     ID est : %d\n\n",A.ID);
    printf("\nLa rubrique est %s",A.Rubrique);
    printf("\nl unite est %s ",A.Unit);
    printf("\nla designation est %s",A.Designation);
    printf("\nla quantite est %d",A.quantity);
    printf("\nle rayon est %d",A.Rayon);
}
void AjouterFin(Article** AdrListe,Article *AdrA){
    Article* TMP = *AdrListe;
    if(*AdrListe==NULL)
    {
        *AdrListe=AdrA;
    }

    else
    {
    	Article* TMP = *AdrListe;
        while(TMP->suivant)
        {
            TMP=TMP->suivant;
        }
        TMP->suivant=AdrA;
    }
    AdrA->suivant=NULL;

}
Article* ListeParRubrique(Article* Liste,char* Rubrique){
     Article* ListeDeRub=NULL;
     Article* TMP=Liste;



    while (TMP)
    {


        if(strcmp((TMP->Rubrique),Rubrique)==1){

            Article* NvArticle=(Article*)malloc(sizeof(Article));


            *NvArticle=*TMP;



            AjouterFin(&ListeDeRub,NvArticle);


        }
        TMP=TMP->suivant;


    }




    return ListeDeRub;

}
Article *ListeParQuantity(Article *Liste,int Seuil){
     Article *ListeDeSeuil=NULL;
    Article* TMP=Liste;

    while (TMP)
    {
        if((Seuil) >= (TMP->quantity)){

            Article* NvArticle=(Article*)malloc(sizeof(Article));
            *NvArticle=*TMP;
            AjouterFin(&ListeDeSeuil,NvArticle);
        }
        TMP=TMP->suivant;
    }
    return ListeDeSeuil;
}
Article* ListeParRayon(Article* Liste,int Rayon){
    Article* TMP=Liste;

    Article* ListeDeRayon=NULL;

    while (TMP)
    {


        if((TMP->Rayon)== (Rayon)){

            Article* NvArticle=(Article*)malloc(sizeof(Article));


            *NvArticle=*TMP;



            AjouterFin(&ListeDeRayon,NvArticle);


        }
        TMP=TMP->suivant;


    }




    return ListeDeRayon;


}
int Taille(Article* Liste){
    Article*TMP = Liste;
    int compteur=0;
    while(TMP)
    {
        compteur++;
        TMP = TMP->suivant;
    }

return compteur;

}
void SupprimerArticle(Article**AdrListe,int ID) {

    int trouve=0;
  if((*AdrListe)->ID==ID){
    *AdrListe=(*AdrListe)->suivant;
    trouve=1;
  }
  else{
    Article *TMP=*AdrListe;
    while(TMP){
      if(TMP->suivant==NULL) break;
      Article *n = TMP->suivant;
      if(n->ID==ID){
      TMP->suivant=(n)->suivant;
      trouve=1;
      break;
      }

      TMP=TMP->suivant;
    }
  }
  if(!trouve)
      printf("L'ARTICLE DONT l' ID = %d n'existe pas!!\a\n\n",ID);
  else
      printf("L'ARTICLE DONT l' ID = %d est supprime\n\n",ID);
}
void RechercheArticle(Article*AdrListe,int ID){
     Article *TMP=AdrListe;

  while(TMP && TMP->ID!=ID)
    {
            TMP=TMP->suivant;
    }

  if(TMP==NULL)
        {
                printf("\n L Article n'existe pas!!\n");
        }
  else{

  AfficherArticle(*TMP);
  }
}
void ModifierArticle(Article *Liste,int ID){
    Article *TMP=Liste;

  while(TMP && TMP->ID!=ID)
    {
            TMP=TMP->suivant;
    }

  if(TMP==NULL)
        {
                printf("\n L Article n'existe pas!!\n");
        }
  else{

  Article *NvArticle=TMP->suivant;
    *TMP=*(CreerArticle(ID-1));
    TMP->suivant=NvArticle;
  }
}
void ChargerStock(Article* Liste,int ID,int Quantity){
	Article *TMP=Liste;

  while((TMP!=NULL) && (TMP->ID!=ID))
    {
            TMP=TMP->suivant;
    }


  if(TMP==NULL)
        {
                printf("\n L Article n'existe pas!!\n");
        }
  else{

  Article *NvArticle=TMP->suivant;
  (TMP)->quantity+=Quantity;
   TMP->suivant=NvArticle;
  }

}
void DechargerStock(Article* Liste,int ID,int Quantity){
        Article *TMP=Liste;

  while(TMP && TMP->ID!=ID)
    {
            TMP=TMP->suivant;
    }

  if(TMP==NULL)
        {
                printf("\n L Article n'existe pas!!\n");
        }
  else{

  Article *NvArticle=TMP->suivant;
  if(NvArticle->quantity <= Quantity)
  {
          printf("\n \n Alerte  STOCK INSUFFISANT\n \n");
  }
  else{
          (TMP)->quantity-=Quantity;
        TMP->suivant=NvArticle;
  }


  }

}
void ElimineDoublons(Article* Liste){
    Article* actuel = Liste;
    Article* suivDesuiv;

    if (actuel == NULL)
       return 0;
    while (actuel->suivant != NULL)
    {

       Article* suivActu= actuel->suivant;
       if ((strcmp(actuel->Designation,suivActu->Designation)==0) && (strcmp(actuel->Rubrique,suivActu->Rubrique)==0))
       {
           actuel->quantity+=suivActu->quantity;
           suivDesuiv = suivActu->suivant;

           actuel->suivant = suivDesuiv;
       }
       else
       {
          actuel = actuel->suivant;
       }
    }
}
void TrierListe(Article *Liste){
 Article *i,*j,*min,*suivAideI,*suivAidesMin;
 Article TMP;
  i=Liste;
  while(i){
    min=i;
    j=i->suivant;
    while(j){
      if(min->quantity > j->quantity)
        {
            min=j;
        }
      j=j->suivant;
    }
    suivAideI=i->suivant;
    suivAidesMin=min->suivant;
    TMP=*i;
    *i=*min;
    *min=TMP;

    i->suivant=suivAideI;
    min->suivant=suivAidesMin;
    i=i->suivant;
  }
}

