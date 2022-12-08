// tp3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "sommet.h"
#include <string>
#include <fstream>
const int temps_max = 999;
const int ressource_max = 50;
const int nb_sommet = 100;
int nombre_activite;
int capacite;
int temps;



int pile;
using namespace std;
void lecteur(string nom, sommet s[]) {
    ifstream infile;
    string vide;

    infile.open(nom);
    infile >> nombre_activite;
    infile >> capacite;
    for (int i = 1; i <= nombre_activite; i++)
    {
        infile >> s[i].cout_ressource;
    }
    for (int i = 1; i <= nombre_activite; i++)
    {
        infile >> s[i].duree;
    }
    for (int i = 1; i <= nombre_activite; i++)
    {
        infile >> vide;
        infile >> s[i].nombre_succ;
        for (int j = 1; j <= s[i].nombre_succ; j++)
        {
            infile >> s[i].succ[j];
        }

    }

    cout << s[10].succ[1] << endl;
}


int cherche_place(int i,int * capacite_t,sommet s[]) {
    bool ajoute = true;

    for (int j = 0; j < 999; j++)
    {

        int duree = s[i].duree;
        int espace = 0;
        for (int k = 0; k < duree; k++)
        {
            if (capacite_t[j] > s[i].cout_ressource) {
                espace++;
                continue;
            }
            else
            {
                break;
            }
        }
        if (espace == duree)
        {
            s[i].position = j;
            break;
        }
    }

    return s[i].position;
}

void ajouter_chemin(int i, int* capacite_t, sommet s[]) {
    int position = s[i].position;
    for (int i = 0; i < s[i].duree; i++)
    {
        capacite_t[position] = capacite_t[position] - s[i].cout_ressource;
        position++;
    }
}

void deplacer_sommet(int i, int* capacite_t, sommet s[]) {
    int position;
    position = cherche_place(i, capacite_t, s);
    ajouter_chemin(i, capacite_t, s);
}

void generer_chemin(sommet s[]) {
    static int capacite_t[temps_max] = { capacite }; //le rest de ressource dans ce moment
    int chemin1[50];
    int* sommet;
    int sommet_origin[100] = { 0 };
    sommet_origin[1] = 1;


    int chemin;
    int i = 1;// numero de sommet qui est en train d'être traité

    while (true)
    {
        deplacer_sommet(i, capacite_t, s);
        i++;
        for (int i = 1; i < 10; i++)
        {
            cout << capacite_t[i];
        }
        if (i>= nombre_activite)
        {
            break;
        }
        cout << endl;
        //for (int j = 1; j <= s[i].nombre_succ; j++)
        //{
        //    int position1;
        //    position1 = cherche_place(s[i].succ[j], capacite_t, s);
        //    ajouter_chemin(s[i].succ[j], capacite_t, s);
        //}
  
    }
    
}
//for (int i = 1; i <= 100; i++)
//{
//
//}
//cherche_place(i, capacite_t, s);
//
//chemin1[i] = chemin1[i - 1] + s[i].duree;
//
//for (int k = 1; k <= s[i].nombre_succ; k++)
//{
//    int n_s = s[i].succ[k];
//    cherche_place(n_s, capacite_t, s);
//}
int main()
{
    sommet mon_sommet[nb_sommet];
    string nom = "inst_2.dat";
    lecteur(nom, mon_sommet);

    int *mon_chemin;
    generer_chemin(mon_sommet);
    cout << mon_sommet[5].position;

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
