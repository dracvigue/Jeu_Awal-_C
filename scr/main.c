#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void affiche( int tab[12] )  //Permet d'afficher le jeux
{
    int i;

    printf("\n***************************");
    printf("\n\n\n");
    printf("Case :          1      2      3      4      5      6\n\n");
    printf("Joueur 1 :  ");
    for(i=0; i<6; i++)
    {
        printf("   [%d] ", tab[i]);
    }
    printf("\n");

    printf("\n");
    printf("Joueur 2 :  ");
    for(i=0; i<6; i++)
    {
        printf("   [%d] ", tab[i+6]);
    }
    printf("\n\n");
    printf("Case :          7      8      9      10     11     12\n\n");

}

void partieJ1 (int tab[12], int* scoreJ1, int* scoreJ2, char prenomJ1[20], char prenomJ2[20])
{
    int A,i,c=0,d;
    do
    {
        do
        {
            printf("%s : Veuillez saisir une case entre 1 et 6 : ",prenomJ1);//Entrer une case pour le joueur1
            scanf("%d",&A);
        }
        while(A<1 || A>6);      //condition si A est entre 1 et 6
    }
    while(tab[A-1]<1);          //condition Il faut que la case ait des billes

    printf("\n");
    d=12-A;     //Soustraction qui permet de savoir cb de case �  faire pour aller jusqu'�  12 (ainsi voir la répétition après la case 12) // case 1,2,3...

//-------------FAIRE DEFILER LES BILLES LIGNE JOUEUR1-------------
    for(i=0; i<tab[A-1]; i++) //Repete dans le tableau de mannière normal
    {
        tab[A+i]=tab[A+i]+1; //Ajoute une bille aux cases suivant la case sélectionner
        c++;                //Compteur qui me permet de savoir sur quelle case on s'arrête �  la fin de la boucle
    }

//------------SCORE JOUEUR 1------------------
    if(A-1+c>5 && A-1+c<12)          //Si la case s'est arrêté entre 7 et 12 je compte les points gagné par joueur1
    {
        if(tab[A-1+c]>0 && tab[A-1+c]<4) //Si la case arrêtée a entre 1 et 3 billes
        {
            *scoreJ1=*scoreJ1+tab[A-1+c]; //Compte les points
            tab[A-1+c]=0;                 //Mise �  zéro après que joueur1 ait gagné ses points

            if(A+c-2>5)
            {
                if((tab[A+c-2]>0) && (tab[A+c-2]<4))//Si �  la case juste avant a entre 1 et 3 billes le joueur1 les gagne en plus
                {
                    *scoreJ1=*scoreJ1+tab[A+c-2]; //Compte les point en plus
                    tab[A+c-2]=0;                 //Mise �  zéro après que joueur1 ait gagné ses points
                }
            }
        }
    }


//-----------CHANGEMENT DE COLONNE-------------------
    if(tab[A-1]>d)  //Si la valeur de la case dépasse la case 12
    {
        for(i=0; i<tab[A-1]-d; i++) //Repete le restant dans la zone de jeu du joueur1
        {
            if(i==A-1) //Si je retrouve la case que joueur1 a sélectionner au début je saute la case
            {
                i=i+1;
            }
            tab[i]=tab[i]+1; //Ajoute une bille aux cases suivantes
        }

    }

    tab[A-1]=0;     //Mise �  zéro de la case que joueur1 a sélectionner

    printf("\nLe score de %s : %d\n",prenomJ1,*scoreJ1);
    printf("\nLe score de %s : %d\n",prenomJ2,*scoreJ2);

}

void partieJ2 (int tab[12], int* scoreJ1, int* scoreJ2, char prenomJ1[20], char prenomJ2[20])
{
    int A,i,c=0,d;
    do
    {
        do
        {
            printf("%s : Veuillez saisir une case entre 7 et 12 : ",prenomJ2); //Entrer une case pour le joueur2
            scanf("%d",&A);
        }
        while(A<7 || A>12);
    }
    while(tab[A-1]<1);

    printf("\n");
    d=12-A; //Soustraction qui permet de savoir cb de case �  faire pour aller jusqu'�  12 (ainsi voir la répétition après la case 12)

//-----------CHANGEMENT DE COLONNE-------------------

    if(tab[A-1]>d)  //Si la valeur de la case dépasse la case 12
    {
        for(i=0; i<d; i++) //Repete le nombre de fois pour aller a la case 12
        {
            tab[A+i]=tab[A+i]+1;//Ajoute une bille aux cases suivant la case sélectionner
        }
    }
    else
    {
        for(i=0; i<tab[A-1]; i++) //Si ne dépasse pas la case 12 je repete le nombre de fois la valeur de la case sélectionner
        {
            tab[A+i]=tab[A+i]+1;//Ajoute une bille aux cases suivantes
        }
    }

//-------------FAIRE DEFILER LES BILLES LIGNE JOUEUR1-------------
    for(i=0; i<tab[A-1]-d; i++) //Dans le cas ça dépasse la case 12 je repete le reste qui n'a pas été compté dans la zone de jeux de joueur1
    {
        if(i==A-1) //Si je retrouve la case que joueur2 a sélectionner je saute la case
        {
            i=i+1;
        }
        tab[i]=tab[i]+1;
        c++;      //Compteur qui me permet de savoir sur quelle case s'arrête la boucle
    }

    tab[A-1]=0;  //Mise �  zéro de la case que joueur2 a sélectionner


//------------SCORE JOUEUR 1------------------
    if(c<7)     //Si le compteur s'arrête entre la case 1 et 6 je compte les points gagné par joueur2
    {
        if(tab[c-1]>0 && tab[c-1]<4)
        {
            *scoreJ2=*scoreJ2+tab[c-1];//Compte les points
            tab[c-1]=0;               //Mise �  zéro après que joueur 2 ait gagné ses points

            if(c-2>=0)
            {
                if((tab[c-2]>0) && (tab[c-2]<4))//Si �  la case juste avant a entre 1 et 3 billes le joueur1 les gagne en plus
                {
                    *scoreJ2=*scoreJ2+tab[c-2];//Compte les point en plus
                    tab[c-2]=0;             //Mise �  zéro après que joueur 2 ait gagné ses points
                }
            }
        }
    }

    printf("\nLe score de %s : %d\n",prenomJ1,*scoreJ1);
    printf("\nLe score de %s : %d\n",prenomJ2,*scoreJ2);
    //printf("\n  c-1 : %d\n",c-1);

}

int randomordi(int tab[12] )
{
    int x,c,m=1,i,F,score=0;
    int d;
    srand(time(NULL));
    x = rand() %1 + 1; //Choisi au hasard entre 1 et 2

    switch(x)
    {
    case 1:
        srand(time(NULL));
        F= rand() %(12-7) + 7;
        return F;
        break;

    case 2:
        do
        {
            srand(time(NULL));
            F= rand() % (12-7) +7;   //
            d=12-F;

            if(tab[F-1]>d)  //Si la valeur de la case dépasse la case 12
            {
                for(i=0; i<d; i++) //Repete le nombre de fois pour aller a la case 12
                {
                    tab[F+i]=tab[F+i]+1;//Ajoute une bille aux cases suivant la case sélectionner
                }
            }
            else
            {
                for(i=0; i<tab[F-1]; i++) //Si ne dépasse pas je repete le nombre de fois la valeur de la case sélectionner
                {
                    tab[F+i]=tab[F+i]+1;//Ajoute une bille aux cases suivantes
                }
            }


            for(i=0; i<tab[F-1]-d; i++) //Dans le cas ça dépasse la case 12 je repete le reste qui n'a pas été compté dans la zone de jeux de joueur1
            {
                if(i==F-1) //Si je retrouve la case que joueur2 a sélectionner je saute la case
                {
                    i=i+1;
                }
                tab[i]=tab[i]+1;
                c++;      //Compteur qui me permet de savoir sur quelle case s'arrête la boucle
            }


            tab[F-1]=0;  //Mise �  zéro de la case que joueur2 a sélectionner


            //------------SCORE JOUEUR 1------------------
            if(c<7)     //Si le compteur s'arrête entre la case 1 et 6 je compte les points gagné par joueur2
            {
                if(tab[c-1]>0 && tab[c-1]<4)
                {
                    return F;
                    score=tab[c-1];
                }
            }
            m=m+1;
        }
        while(score==0 || m!=3);

        return F;

        break;


    }
}

    void partieordi (int tab[12], int* scoreJ1, int* scoreJ2, char prenomJ1[20])
    {
        int A,i,c=0,d;
        do
        {
            A=randomordi(tab);

        }
        while(tab[A-1]<1);

        printf("\n");
        d=12-A; //Soustraction qui permet de savoir cb de case �  faire pour aller jusqu'�  12 (ainsi voir la répétition après la case 12)

//-----------CHANGEMENT DE COLONNE-------------------

        if(tab[A-1]>d)  //Si la valeur de la case dépasse la case 12
        {
            for(i=0; i<d; i++) //Repete le nombre de fois pour aller a la case 12
            {
                tab[A+i]=tab[A+i]+1;//Ajoute une bille aux cases suivant la case sélectionner
            }
        }
        else
        {
            for(i=0; i<tab[A-1]; i++) //Si ne dépasse pas je repete le nombre de fois la valeur de la case sélectionner
            {
                tab[A+i]=tab[A+i]+1;//Ajoute une bille aux cases suivantes
            }
        }

//-------------FAIRE DEFILER LES BILLES LIGNE JOUEUR1-------------
        for(i=0; i<tab[A-1]-d; i++) //Dans le cas ça dépasse la case 12 je repete le reste qui n'a pas été compté dans la zone de jeux de joueur1
        {
            if(i==A-1) //Si je retrouve la case que joueur2 a sélectionner je saute la case
            {
                i=i+1;
            }
            tab[i]=tab[i]+1;
            c++;      //Compteur qui me permet de savoir sur quelle case s'arrête la boucle
        }

        tab[A-1]=0;  //Mise �  zéro de la case que joueur2 a sélectionner


//------------SCORE JOUEUR 1------------------
        if(c<7)     //Si le compteur s'arrête entre la case 1 et 6 je compte les points gagné par joueur2
        {
            if(tab[c-1]>0 && tab[c-1]<4)
            {
                *scoreJ2=*scoreJ2+tab[c-1];//Compte les points
                tab[c-1]=0;               //Mise �  zéra après que joueur 2 ait gagné ses points

                if(c-2>=0)
                {
                    if((tab[c-2]>0) && (tab[c-2]<4))//Si �  la case juste avant les points gagné �  entre 1 et 3 billes le joueur1 les gagne
                    {
                        *scoreJ2=*scoreJ2+tab[c-2];//Compte les point en plus
                        tab[c-2]=0;             //Mise �  zéra après que joueur 2 ait gagné ses points
                    }
                }
            }
        }

        printf("\nLe score de %s : %d\n",prenomJ1,*scoreJ1);
        printf("\nLe score de ORDI : %d\n",*scoreJ2);

    }

    int menu ()
    {
        int n;
        printf("Bienvenue vous jouez au jeu ALAWE");
        printf("\n\n");
        printf("Veuiller Choisir le mode\n");
        printf("Taper 1 : Pour jouer 1 vs 1\n");
        printf("Taper 2 : Pour jouer 1 vs ORDI\n");
        scanf("%i",&n);

        return n;
    }


    int main()
    {
        int i,y,n;
        // int tab[12]={11,1,1,3,0,0,11,1,1,3,0,0}; //Test
        //int tab[12]={1,1,1,1,1,1,0,0,0,0,0,1}; //Test2
        int tab[12]= {4,4,4,4,4,4,4,4,4,4,4,4};
        int tableau[2];
        int scoreJ1=0;
        int scoreJ2=0;
        char prenom1[20],prenom2[20]; // déclaration des prenoms

        n=menu();

//-----------Presentation du jeux entrer les noms-----------
        if(n==1)
        {
            do
            {
                printf("\n");
                printf("Veuillez saisir Le prenom du joueur 1 :"); //entrer le nom du joueur 1
                fflush(stdin);
                gets(prenom1);
                printf("\n");

                printf("Veuillez saisir Le prenom du joueur 2 :"); //entrer le nom du joueur 2
                fflush(stdin);
                gets(prenom2);
                printf("\n");

                affiche(tab);

                //----------DEBUT DU JEUX A 2 JOUEURS---------------
                do
                {
                    tableau[0]=0;
                    tableau[1]=0;

                    partieJ1(tab,&scoreJ1,&scoreJ2,prenom1,prenom2);
                    affiche(tab);
                    for(i=0; i<6; i++)             //Permet �  la variable tableau d'avoir les case 7 �  12, pour voir si joueur2 a perdu
                    {
                        tableau[0]=tableau[0]+tab[i];
                        tableau[1]=tableau[1]+tab[i+6];
                    }

                    if(tableau[0]!=0)
                    {
                        partieJ2(tab,&scoreJ1,&scoreJ2,prenom1,prenom2);
                        affiche(tab);
                    }
                    tableau[0]=0;
                    tableau[1]=0;
                    for(i=0; i<6; i++)             //Permet �  la variable tableau d'avoir les case 7 �  12, pour voir si joueur2 a perdu
                    {
                        tableau[0]=tableau[0]+tab[i];
                        tableau[1]=tableau[1]+tab[i+6];
                    }

                    if((tableau[0]!=0) && (tableau[1]==0))             //Si Joueur1 gagne, il gagne en plus les billes qu'il y a dans sa zone de jeu
                    {
                        scoreJ1=scoreJ1+tableau[0];
                    }
                    else if((tableau[0]==0) && (tableau[1]!=0))        //Si Joueur2 gagne, il gagne en plus les billes qu'il y a dans sa zone de jeu
                    {
                        scoreJ2=scoreJ2+tableau[1];
                    }

                }
                while((tableau[0] != 0) && (tableau[1] != 0)); //condition si un des joueurs n'a plus de billes dans sa zone de jeux

                if(scoreJ1<scoreJ2)                              //si joueur1 n'a plus de billes dans sa zone de jeux
                {
                    printf("BRAVO JOUEUR2 TU AS GAGNE :%d points",scoreJ2);
                }
                else                                  //si joueur2 n'a plus de billes dans sa zone de jeux
                {
                    printf("BRAVO JOUEUR1 TU AS GAGNE :%d points",scoreJ1);
                }
                printf("\n\nPour rejouer entrer 1\n");
                scanf("%i",&y);
                printf("\n\n");

            }
            while(y==1);
        }

        if(n==2)
        {
            do
            {
                printf("Veuillez saisir Le prenom du joueur 1 :"); //entrer le nom du joueur 1
                fflush(stdin);
                gets(prenom1);
                printf("\n");

                affiche(tab);

                //----------DEBUT DU JEUX CONTRE L'ORDI---------------
                do
                {
                    tableau[0]=0;
                    tableau[1]=0;

                    partieJ1(tab,&scoreJ1,&scoreJ2,prenom1,prenom2);
                    affiche(tab);
                    for(i=0; i<6; i++)             //Permet �  la variable tableau d'avoir les case 7 �  12, pour voir si joueur2 a perdu
                    {
                        tableau[0]=tableau[0]+tab[i];
                        tableau[1]=tableau[1]+tab[i+6];
                    }

                    if(tableau[0]!=0)
                    {
                        partieordi(tab,&scoreJ1,&scoreJ2,prenom1);
                        affiche(tab);
                    }
                    tableau[0]=0;
                    tableau[1]=0;
                    for(i=0; i<6; i++)             //Permet �  la variable tableau d'avoir les case 7 �  12, pour voir si joueur2 a perdu
                    {
                        tableau[0]=tableau[0]+tab[i];
                        tableau[1]=tableau[1]+tab[i+6];
                    }

                    if((tableau[0]!=0) && (tableau[1]==0))             //Si Joueur1 gagne, il gagne en plus les billes qu'il y a dans sa zone de jeu
                    {
                        scoreJ1=scoreJ1+tableau[0];
                    }
                    else if((tableau[0]==0) && (tableau[1]!=0))        //Si Joueur2 gagne, il gagne en plus les billes qu'il y a dans sa zone de jeu
                    {
                        scoreJ2=scoreJ2+tableau[1];
                    }

                }
                while((tableau[0] != 0) && (tableau[1] != 0)); //condition si un des joueurs n'a plus de billes dans sa zone de jeux

                if(scoreJ1<scoreJ2)                              //si joueur1 n'a plus de billes dans sa zone de jeux
                {
                    printf("DESOLER TU AS PERDU :%d points",scoreJ2);
                }
                else                                  //si joueur2 n'a plus de billes dans sa zone de jeux
                {
                    printf("BRAVO JOUEUR1 TU AS GAGNE :%d points",scoreJ1);
                }
                printf("\n\nPour rejouer entrer 1\n");
                scanf("%i",&y);
                printf("\n\n");

            }
            while(y==1);

        }

    }

