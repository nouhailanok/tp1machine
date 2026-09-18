// tp1machine.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "struc.h"



int main()
{
    t_piece P;
    P.identifient = 123;

    t_piece Q;
    Q.identifient = 900;

    t_piece R;
    R.identifient = -134;


    t_file ma_file;
    ma_file.debut = 2;
    ma_file.fin = 2;
    
    // plus add smt pour intialiser lafile de manière plus belle

    ajouter_element(ma_file, P);
    
    for (int i = 1;i <= 5;i++)
    {
        t_piece P;
        P.identifient = i * 10 + 1000;
        ajouter_element(ma_file, P);
    }

    std::cout << "fin ";


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
