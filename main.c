  #include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaration des structures de donnees

typedef struct Avion Avion;
typedef struct Date Date;
struct Date{
        int jour;
        int mois;
        int annee;
    } Date_Fab;
struct Avion{
    char Code_Avion[5];
    int Cap_Stok;
    char Etat;
    Date Date_Fab;
    int Nbre_Vol_Ass;
    Avion  *Suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Avion *premier;
};

 Liste *maListe;

 int choix_A;
 int choix_B;
 int touche;
 //******************************************
 //function gotoxy: positionnement du curseur
 //*******************************************
 void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}
//***********************************************************
//**   fonction de verification d'un entier
//*******************************************************
int est_int(char str[5])
{
	int i = 0;
    int   testsaisie =0;
	for(i = 0; i < strlen(str); i++)
	{
      if( (isdigit(str[i])) )
            testsaisie = 1+testsaisie;
    }
    if (testsaisie != strlen(str)) return -1;
    else return 0;
}

//**************************************
//**********Procedure insertion avion***
//**************************************

void Insertion_Avion(Liste *liste, char code_a[5],int cap_a,char etat,int jour,int mois,int annee, int nbre_vol)
{
    /* Creation du nouvel element */
    Avion *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    strcpy(nouveau->Code_Avion, code_a);
    nouveau->Cap_Stok    = cap_a;
      nouveau->Etat   = etat;
    nouveau->Date_Fab.jour= jour;
      nouveau->Date_Fab.mois=mois;
      nouveau->Date_Fab.annee=annee;
    nouveau->Nbre_Vol_Ass = nbre_vol;

    /* Insertion de l'element au debut de la liste */
    nouveau->Suivant = liste->premier;
    liste->premier = nouveau;
}
//*****************************************
//**********Procedure verification avion***
//*****************************************

void Verification_Avion(char Code_Avion[5])

 {
    system("cls");

    Avion *actuel= maListe->premier;
    while ((actuel != NULL) && (strcmp(actuel->Code_Avion,Code_Avion)!=0))
    {
        actuel = actuel->Suivant;
    }
    if (strcmp(actuel->Code_Avion,Code_Avion)==0)
                          if  (actuel->Etat=='A') printf("%s  est à l aeroport",Code_Avion);
                          else printf("-1** n est pas a l aeroport");
    else printf("Avion introuvable nulle part");
    int v; scanf("%d",&v);
}

//*********************************************
 // Verifie si avion est dans l'aeroport ou non
 //*********************************************
 void Verif_avion_a()
 {
    char Code_Avion[5];

    int verif;
    system("cls");
    printf("**********************************************:\n");
    printf("***Introduire un Code  Avion*****************:\n");
    printf("***Pour verifie sa presence dans l aeroport**:\n");
    printf("*********************************************:\n");

    printf("Code Avion               :\n");

    printf("***************************************:\n");
    gotoxy(27,5);  scanf("%s",&Code_Avion);

    gotoxy(4,14);  printf("0: Annuler****  1: Verifier   :\n");
    gotoxy(34,14);  scanf("%d",&verif);
    if (verif==1) Verification_Avion(Code_Avion);

 }

 //************************************
 //* controle de la date
 //**************************************
 int verifdate(int jour, int mois, int annee){

	if ((mois==1 || mois==3 || mois==5 || mois==7 || mois==8 || mois==10 || mois==12) && ((jour >= 1) && (jour<=31))) return 1;
	if ((mois==4 || mois==6 || mois==9 || mois==11) && ((jour >= 1) && (jour<=30))) return 1;
	if (mois==2 && ((jour >= 1) && (jour<=28)))return 1;
	if (mois==2 && jour == 29 && ((annee%4 == 0) && (annee%100 !=0) || (annee%400==0))) return 1;
	return 0;
}
 //**************************************
 // Saisie des information de l'avion
 //***************************************

 void Saisie_avion()
 {

    char Code_Avion[5];
    int Cap_Stock;
    char Etat_Avion;
    int jour;
    int mois;
    int annee;

    int Nbre_vol_ass;
    char nva[5];
    char ch[5]="";
    int valid;
    int cont=1;
    do
    {
    system("cls");
    printf("***************************************:\n");
    printf("***Saisie des informations de l Avion**:\n");
    printf("***************************************:\n");
    printf("Code Avion               :\n");
    printf("Capacite de stockage     :\n");
    printf("Etat de l Avion(A,D,M)   :\n");
    printf("Date de fabrication Avion:  /  /    \n");
    printf("Nombre de vol assures    :\n");
    printf("***************************************:\n");
    gotoxy(27,4);  scanf("%s",&Code_Avion);
    //Saisie & Controle  Capacite de stockage

    do
    { gotoxy(46,5);  printf("Enter un entier SVP");
       gotoxy(27,5);printf("             ");
       gotoxy(27,5);rewind(stdin);
       scanf("%s",&nva);
       gotoxy(46,5);   printf("                   ");
    }

    while  (est_int(nva)==-1);
     Cap_Stock = atoi(nva);


    //Saisie et control Etat de l'avion
    do
    {

      gotoxy(46,6);  printf("Enter A ou D ou M SVP");
      gotoxy(27,6);  rewind(stdin);
      gotoxy(27,6);  scanf(" %c",&Etat_Avion);
      gotoxy(46,6);   printf("                     ");

    }  while  ((Etat_Avion!='A') && (Etat_Avion!='D') && (Etat_Avion!='M'));

    // saisie & Controle de la date de fabrication;
    char sjour[2];
    char smois[2];
    char sannee[4];
    do {

    gotoxy(27,7);printf("  /  /    ");

    gotoxy(27,7);
    if(scanf("%d",&jour)==1)
    {
     gotoxy(30,7);  if(scanf("%d",&mois)==1)
                    {
                       gotoxy(33,7);
                       scanf("%d",&annee);
                    }
    }


    } while (verifdate(jour,mois,annee)==0);
     //Saisie & controle du nombre de vols assures par l'avion
   do

    { gotoxy(46,8);  printf("Enter un entier SVP");
       gotoxy(27,8);printf("             ");
       gotoxy(27,8);rewind(stdin);
       scanf("%s",&nva);

     gotoxy(46,8);   printf("                   ");

    }

    while  (est_int(nva)==-1);
     Nbre_vol_ass = atoi(nva);

    gotoxy(4,14);  printf("0: Annuler****  1: Valider   :\n");
    gotoxy(34,14);  scanf("%d",&valid);
    if (valid==1) Insertion_Avion(maListe, Code_Avion,Cap_Stock,Etat_Avion,jour,mois,annee,Nbre_vol_ass);

    gotoxy(4,14);  printf("0: Sortie****  1: Saisie Encore  :\n");
    gotoxy(38,14);  scanf("%d",&cont);
    } while (cont!=0);
 }

//********************************************//
//****Procedure Menu B*********************************//
//******************************************//
int menu_b()
  {
   choix_B=0;
  do
  {

   system ("cls");
printf("  *************************************************************************\n");
printf("************************************* Affichage ***************************\n");
printf("  *************************************************************************\n");
printf("* 1 : - > Liste des avions decolles - - - - - - - - - - - - - - - - - ----*\n");
printf("* 2 : - > Liste des avions atterris - - - - - - - - - - - - - - - - -- ---*\n");
printf("* 3 : - > Liste des avions en maintenance - - - - - - - - - - - - - ------*\n");
printf("* 4 : - > Liste des avions qui ont assure (max des vols et ages de 10 ans *\n");
printf("* 5 : - > Liste des avions qui ont assure (min des vols et ages de 10 ans *\n");
printf("* 6 : - > Retour page principale - ---------------------------------------*\n");
printf("***************************************************************************\n");
printf("Donnez votre choix SVP ?\n");
scanf("%d",&choix_B);
} while (choix_B < 1 || choix_B > 6);

return choix_B;

    }

//*****************************************************//
//****Procedure Menu B*********************************//
//****************************************************//
void menu_bb()

  {
      int cont=1;
    do
               {
                  switch (menu_b())
                 {
                  case 1:afficherListe('D');
                         break;
                  case 2:afficherListe('A');
                         break;
                  case 3:afficherListe('M');
                         break;
                  case 4:afficher_Max_Min_vols_10ans(1);
                         break;
                  case 5:afficher_Max_Min_vols_10ans(0);
                         break;
                  case 6:  printf ("retour menu principal\n") ;
                         break;
                 }
                 gotoxy(50,8);printf("1: Menu precedent   0:Menu principal");
                 gotoxy(38,14);  scanf("%d",&cont);
               } while (cont!=0);
              }
//*****************************************************//
//****Procedure Menu A*********************************//
//***************************************************//

int menu_a()

   {
  choix_A=0;

  do
  {

   system ("cls");
    printf("  ******************************************************************************\n");
    printf("  ************************* Gestion du Trafic Aerien ***************************\n");
    printf("  ******************************************************************************\n");
    printf("  ******************************************************************************\n");
    printf("  * 1 : - - - - - - - - - - - - > Remplir la liste des avions -----------------*\n");
    printf("  * 2 : - - - - - - - - - - - - > Verifier si un avion est dans l aeroport  ---*\n");
    printf("  * 3 : - - - - - - - - - - - - > Supprimer les avions plus de 20 ans ---------*\n");
    printf("  * 4 : - - - - - - - - - - - - > Trier la liste des avions - - - - - - - - - **\n");
    printf("  * 5 : - - - - - - - - - - - - > Afficher la liste des avions - - - - - - - - *\n");
    printf("  * 6: - - - - - - - - -  - - - > Sortie - - - - - - ----------------------- - *\n");
    printf("********************************************************************************\n");

    printf("\n");
    printf("  Donnez votre choix SVP?\n");
    scanf("%d",&choix_A);
    } while (choix_A < 1 || choix_A > 6);

   return choix_A ;
    }

 //********************************************//
//****Procedure Menu A*************************//
//*********************************************//

void menu_aa()

   {
  do
    {
    switch (menu_a())
    {
      case 1: Saisie_avion();
              break;
      case 2: Verif_avion_a(maListe);
              break;
      case 3: Suppresion_avion();
              break;
      case 4: Tri_Affiche_Liste();
             break;
      case 5: menu_bb();
              break;
      case 6:printf ("Quitter l application \n") ;
            break;
    }
    } while (choix_A!=6);
   }
//*************************************************************//
// Affichage des avions selon l'etat(parametre de la procedure:
// A  ou D  ou M)
//*************************************************************//

void afficherListe(char etat)
{
    system("cls");

    Avion *actuel = maListe->premier;
    printf("*******************************************\n");
    if (etat=='D')
    printf("*              Liste des Avions decolles  *\n");

    if (etat=='A')
    printf("*              Liste des Avions  atterris *\n");

    if (etat=='M')
    printf("*         Liste des Avions en maintenance *\n");

    printf("*******************************************\n");
    printf(" * Code * Capacite * Etat * Date Fabrication * Nombre de vol *\n");
    while (actuel != NULL)
    {
      if (actuel->Etat==etat)
        printf(" * %4s * %8d * %4c *   %2d/%2d/%4d     * %13d * \n", actuel->Code_Avion,actuel->Cap_Stok,actuel->Etat,
               actuel->Date_Fab.jour,actuel->Date_Fab.mois,actuel->Date_Fab.annee,actuel->Nbre_Vol_Ass);
      actuel = actuel->Suivant;
    }

    }

//************************************************************************//
// Affichage liste (deja triees (ordre croissant) par capacite de stockage
//************************************************************************//

void afficherListe_SC()
{
    system("cls");

    Avion *actuel = maListe->premier;
    printf("*******************************************\n");

    printf("*    Liste des Avions triees/Capacite     *\n");

    printf("*******************************************\n");
    printf(" * Code * Capacite * Etat * Nombre de vol *\n");
    while (actuel != NULL)
    {

        printf(" * %4s * %8d * %4c * %13d * \n", actuel->Code_Avion,actuel->Cap_Stok,actuel->Etat,actuel->Nbre_Vol_Ass);
      actuel = actuel->Suivant;
    }
    scanf("%d",touche);

}
//*******************************************************
// Calcul de l'ecart (nombre d'annees) entre deux dates
//*******************************************************
int ecart_dates(int jd,int md,int ad,int jf,int mf,int af)
{
    int ea=af-ad;
    int em=mf-md;
    int ej=jf-jf;

   if (ej<0)  {ej=ej+30;em=em-1;}
   if (em<0)  {em=em+12;ea=ea-1;}

   return ea;
}

//***************************************************************//
// Suppression des avions (age >20 ans et se trouve en maintenance)
//***************************************************************//

void Suppresion_avion()
{
    system("cls");

    int ja, ma, aa;
  time_t now;

  // Renvoie l'heure actuelle
  struct tm *local = localtime(&now);

  ja = local->tm_mday;
  ma = local->tm_mon + 1;
  aa = local->tm_year + 1900;
   int ea; //** écart annuel entre deux dates

    Avion *p =NULL;
    Avion *actuel = maListe->premier;
    printf("*******************************************\n");
    printf("*         Liste des Avions supprimees     *\n");
    printf("*******************************************\n");
    printf(" * Code * Capacite * Etat * Date Fabrication * Nombre de vol *\n");
    while (actuel != NULL)
    {
       ea=ecart_dates(actuel->Date_Fab.jour,actuel->Date_Fab.mois,actuel->Date_Fab.annee,ja,ma,aa);
      if ((ea>20) && (actuel->Etat=='M'))
        {

          printf(" * %4s * %8d * %4c *   %2d/%2d/%4d     * %13d * \n", actuel->Code_Avion,actuel->Cap_Stok,actuel->Etat,
               actuel->Date_Fab.jour,actuel->Date_Fab.mois,actuel->Date_Fab.annee,actuel->Nbre_Vol_Ass);

           if (p==NULL) {maListe->premier=actuel->Suivant;actuel->Suivant=NULL;free(actuel);actuel=maListe->premier;}
           else
           {p->Suivant= actuel->Suivant; actuel->Suivant=NULL;free(actuel);actuel=p->Suivant; }
         }
        else
           {p=actuel; actuel = actuel->Suivant;}
    }

}

//****************************************************//
// Tri de la liste des avions par capacite de stockage
// avec quatre pointeurs courant(actuel) et précedent(P)
// et courant 2(actuel2)  et précedent2 (p2)
//****************************************************//

void Tri_Affiche_Liste()
{
    system("cls");

    Avion *actuel = maListe->premier;

    Avion *actuel2 ;
    Avion *ip ;
    Avion *ia ;
    Avion *p=NULL;
    Avion *p2;
    Avion *inter;
    int change=0;

    while (actuel != NULL)
    {
        p2=actuel;
        actuel2 = actuel->Suivant;
      while (actuel2 != NULL)
      {
           if (actuel->Cap_Stok > actuel2->Cap_Stok)
         {
          if (p!=NULL)
            {

                 p->Suivant=actuel2;
                 p2->Suivant=actuel;

                ia=actuel->Suivant;
                actuel->Suivant=actuel2->Suivant;
                actuel2->Suivant=ia;
            }
           else
           {

                      p2->Suivant=actuel;
                      ia=actuel->Suivant;
                      actuel->Suivant=actuel2->Suivant;
                      actuel2->Suivant=ia;

               }
         inter=actuel;
         actuel=actuel2;
         actuel2=inter;

        }
        p2=actuel2;
        actuel2 = actuel2->Suivant;

      }
      if (change==0) {maListe->premier=actuel;change=1;}
      p=actuel;
      actuel = actuel->Suivant;

    }
// affichage de la liste triée
afficherListe_SC();
}

//************************************************************//
// Affichage des avions ayants le maximun ou le minimum de vols et age 10 ans
//parametre : mm si mm=1 recherche max  si mm =0 recherche min
//************************************************************//

void afficher_Max_Min_vols_10ans(int mm)
{
    system("cls");

     int max_v;
     int min_v;
    if (mm==1)  max_v=Max_vols();
    if (mm==0)  min_v=Min_vols();

    //**

  int ja, ma, aa;
  time_t now;

  // Renvoie l'heure actuelle
  //time(&now);
  struct tm *local = localtime(&now);

  ja = local->tm_mday;
  ma = local->tm_mon + 1;
  aa = local->tm_year + 1900;

   int ea; //** ecart en années entre deux dates

    Avion *actuel = maListe->premier;
    printf("*******************************************\n");
    if (mm==1)
    printf("* Liste des Avions max vols et age= 10 ans \n");

    if (mm==0)
    printf("* Liste des Avions min vols et age= 10 ans \n");
    printf("*******************************************\n");
    printf(" * Code * Capacite * Etat * Nombre de vol *\n");
    while (actuel != NULL)
    {
      ea=ecart_dates(actuel->Date_Fab.jour,actuel->Date_Fab.mois,actuel->Date_Fab.annee,ja,ma,aa);
      if (((actuel->Nbre_Vol_Ass==max_v) && (mm==1) && (ea==10)) || ((actuel->Nbre_Vol_Ass==min_v) && (mm==0)&& (ea==10)))
        printf(" * %4s * %8d * %4c * %13d * \n", actuel->Code_Avion,actuel->Cap_Stok,actuel->Etat,actuel->Nbre_Vol_Ass);
      actuel = actuel->Suivant;
    }


}
//*****************************************//
// recherche Maximum des vols
//******************************************//

int Max_vols()
{
    int max_v=0;

    Avion *actuel = maListe->premier;
    if (actuel != NULL)
    {
    max_v=actuel->Nbre_Vol_Ass;
    actuel = actuel->Suivant;}
    while (actuel != NULL)
    {
      if (actuel->Nbre_Vol_Ass > max_v) max_v=actuel->Nbre_Vol_Ass;
      actuel = actuel->Suivant;
    }
    return max_v;
}
//*****************************************//
// recherche minimum des vols
//******************************************//
int Min_vols()
{
    int min_v=0;
   Avion *actuel = maListe->premier;
    if (actuel != NULL)
    {
    min_v=actuel->Nbre_Vol_Ass;
    actuel = actuel->Suivant;}
    while (actuel != NULL)
    {
      if (actuel->Nbre_Vol_Ass < min_v) min_v=actuel->Nbre_Vol_Ass;
      actuel = actuel->Suivant;
    }
    return min_v;

}
//****************************************//
//* fonction  initialisation de la liste
//****************************************//
Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    liste->premier = NULL;
    return liste;
}
//********************************************//
//****Programme principal*********************//
//*******************************************//
int main()
{
    //initialisation maListe (liste de travail)
maListe=initialisation();
// Menu principal
menu_aa();
// vider la mémoire à la sortie du programme
free(maListe);
 return 0;
}
