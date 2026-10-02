// tp1machine.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "struc.h"

const int LIBRE = 0;
const int OCCUPEE = 1;

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
    retirer_element(ma_file, P);
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



    int Lam = 1;                
    int Sa = 4;                 

    int date_simulaton = 0;
    int date_max = 1000;

    t_entree l_entree;
	l_entree.DPE = 0;           // premiere arrivee a la date 0 ( it's important à ne pas oublier )
    l_entree.compteur_id = 0;
    l_entree.nb_creees = 0;
    l_entree.nb_refusees = 0;

    t_file la_file;
    initialiser_file(la_file);

    t_machine la_machine;
    la_machine.etat = LIBRE;
    la_machine.DPE = INFINI;   

    t_sortie la_sortie;
    la_sortie.nb_piece = 0;

    while (date_simulaton < date_max)
    {
		// find le min DPE between la machine et l'entree
        int date_evenement = l_entree.DPE;
        if (la_machine.DPE < date_evenement)
            date_evenement = la_machine.DPE;

        if (date_evenement > date_max)
            break;

        date_simulaton = date_evenement; 

        // machine done et on libère la place
        if (la_machine.etat == OCCUPEE && la_machine.DPE == date_simulaton)
        {
            la_machine.contenu.date_fin_service = date_simulaton;
            deposer_sur_sortie(la_sortie, la_machine.contenu);
            la_machine.etat = LIBRE;
            la_machine.DPE = INFINI;
        }

        // si la machine est libre et la liste est pleine
        if (la_machine.etat == LIBRE && tester_file_vide(la_file) == 0)
        {
            retirer_element(la_file, la_machine.contenu);
            la_machine.contenu.date_access_serveur = date_simulaton;
            la_machine.etat = OCCUPEE;
            la_machine.DPE = date_simulaton + Sa;
        }

        // newwwwwww piece 
        if (l_entree.DPE == date_simulaton)
        {
            l_entree.compteur_id++;
            l_entree.nb_creees++;

            t_piece nouvelle;
            nouvelle.identifient = l_entree.compteur_id;
            nouvelle.date_entree_system = date_simulaton;
            nouvelle.date_access_serveur = -1;
            nouvelle.date_fin_service = -1;

            if (tester_file_pleine(la_file) == 1)
            {
                l_entree.nb_refusees++;
            }
            else
            {
                ajouter_element(la_file, nouvelle);
            }

            l_entree.DPE = date_simulaton + Lam;
        }

        // 
        if (la_machine.etat == LIBRE && tester_file_vide(la_file) == 0)
        {
            retirer_element(la_file, la_machine.contenu);
            la_machine.contenu.date_access_serveur = date_simulaton;
            la_machine.etat = OCCUPEE;
            la_machine.DPE = date_simulaton + Sa;
        }
    }

    int nb_creees = l_entree.nb_creees;
    int nb_refusees = l_entree.nb_refusees;

    // ---- calcul des temps moyens de sejour ----
    double somme_systeme = 0.0;
    double somme_file = 0.0;

    for (int i = 0; i < la_sortie.nb_piece; i++)
    {
        t_piece p = la_sortie.liste[i];
        somme_systeme += (p.date_fin_service - p.date_entree_system);
        somme_file += (p.date_access_serveur - p.date_entree_system);
    }

    double sejour_systeme = (la_sortie.nb_piece > 0) ? somme_systeme / la_sortie.nb_piece : 0.0;
    double sejour_file = (la_sortie.nb_piece > 0) ? somme_file / la_sortie.nb_piece : 0.0;

    std::cout << "\nDuree simulation = " << date_max << std::endl;
    std::cout << "Pieces creees    = " << nb_creees << std::endl;
    std::cout << "Pieces refusees  = " << nb_refusees << std::endl;
    std::cout << "Pieces sorties   = " << la_sortie.nb_piece << std::endl;
    std::cout << "Sejour moyen systeme = " << sejour_systeme << std::endl;
    std::cout << "Sejour moyen file    = " << sejour_file << std::endl;

    return 0;
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
