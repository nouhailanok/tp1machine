// tp1machine.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "struc.h"



int main()
{
	t_machine M;

    t_piece P;
    P.identifient = 123;

    t_piece Q;
    Q.identifient = 900;

    t_piece R;
    R.identifient = 321;


    t_file ma_file;
    ma_file.debut = 2;
    ma_file.fin = 2;
    tester_file_vide(ma_file);

    ajouter_element(ma_file, P);
    tester_file_vide(ma_file);

    ajouter_element(ma_file, R);
    ajouter_element(ma_file, Q);
    retirer_element(ma_file, Q);
    tester_file_pleine(ma_file);

    t_piece Z;
    Z.identifient = 777;
    ajouter_element(ma_file, Z);

    t_piece C;
    C.identifient = 777;
    ajouter_element(ma_file, C);

    t_piece A;
    A.identifient = 771;
    ajouter_element(ma_file, A);

    t_piece B;
    B.identifient = 727;
    ajouter_element(ma_file, B);

    t_piece D;
    D.identifient = 727;
    ajouter_element(ma_file, D);

    t_piece E;
    E.identifient = 727;
    ajouter_element(ma_file, E);

    t_piece F;
    F.identifient = 727;
    ajouter_element(ma_file, F);



    tester_file_pleine(ma_file);


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
