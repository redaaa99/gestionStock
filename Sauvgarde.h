
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <errno.h>




int ExistenceFichier(char* NomFichier);
void CreerFichier(Article* Liste, int N);
Article* LireFichier(int* N);


int ExistenceFichier(char* NomFichier){
  int success=1;
  FILE *MonFichier;
  MonFichier=fopen(NomFichier,"r");
  if(MonFichier==NULL)
  {
    success=0;
  }
  else
  {
    fclose(MonFichier);
  }

  return success;
}
void CreerFichier(Article* Liste, int N){
  char NomFich[20];
  Article *TMP=Liste;
  FILE *MonFichier;
  int choix;
  do{
    printf("\n\nLe nom du fichier a cree : ");
    scanf("%s",NomFich);
    if(ExistenceFichier(NomFich)==1){
      printf("\nLe fichier %s existe deja, voulez-vous l'ecraser?\nTaper '1': Oui \n '0' :Non : ",NomFich);
      scanf("%d",&choix);
    }
    else
    {
        break;
    }
  }while(choix!=1);
  MonFichier=fopen(NomFich,"w");
  fprintf(MonFichier,"%d\n",N);
  while(TMP){
    fprintf(MonFichier,"\n%d\n%s\n%s\n%s\n%d\n%d\n",TMP->ID,TMP->Rubrique,TMP->Unit,TMP->Designation,TMP->quantity,TMP->Rayon);
    TMP=TMP->suivant;
  }
  fclose(MonFichier);
  printf("\n\n Enregistree dans le fichier !!!\n\n");
  system("pause");
}
Article* LireFichier(int* N){
  char NomFich[30];
  Article* Liste=NULL;
  FILE *MonFichier;
  do{
    printf("\n\nLe nom du fichier a lire: ");
    scanf("%s",NomFich);
    if(ExistenceFichier(NomFich)==0)
      printf("\nLe fichier %s n'existe pas!!\n ",NomFich);
  }while(ExistenceFichier(NomFich)==0);
  MonFichier=fopen(NomFich,"r");
  fscanf(MonFichier,"%d\n",N);
  printf("Votre Fichier contient %d Article.\n\n",*N);
  int cpt =0;
  while(!feof(MonFichier)){
    cpt++;
    Article *TMP=(Article*)malloc(sizeof(Article));
    int id,rayon,quantity;
    char unit[15];
    char Rubrique[30];
    char Designation[50];
    fscanf(MonFichier,"%d",&id);
    TMP->ID=id;
    fscanf(MonFichier,"\n");
    fgets(Rubrique,30,MonFichier);
    strcpy(TMP->Rubrique,Rubrique);
    fgets(unit,30,MonFichier);
    strcpy(TMP->Unit,unit);
    fgets(Designation,30,MonFichier);
    strcpy(TMP->Designation,Designation);
    fscanf(MonFichier,"%d",&quantity);
    TMP->quantity=quantity;
    fscanf(MonFichier,"%d",&rayon);
    TMP->Rayon=rayon;
    AjouterFin(&Liste,TMP);
    if(cpt==*N){
        break;
    }
  }
  fclose(MonFichier);
  printf("\n\n DONNEES LUES \n\n");
  system("pause");
  return Liste;
}


