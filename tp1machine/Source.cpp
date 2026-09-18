#include "struc.h"
#include <iostream>


void ajouter_element(t_file& une_file, t_piece une_piece)
{
	if ((une_file.fin + 1) % 10 == une_file.debut)
		exit(-1);
	else
	{
		une_file.liste[une_file.fin] = une_piece;

		une_file.fin = (une_file.fin + 1) % 10;
	}
}


void retirer_element(t_file& une_file, t_piece& une_piece)
{
	if (tester_file_vide(une_file) == 1)
	{

		printf("Erreur : retrait dans une file vide\n");
		exit(-1);

	}

	une_piece = une_file.liste[une_file.debut];

	une_file.debut = (une_file.debut + 1) % taille_tableau;
}




int tester_file_pleine(t_file une_file)
{
	int d = une_file.debut;
	int f = une_file.fin;
	if ((f + 1) % 10 == d) {
		return 1;
	}
	else {
		return 0;
	}

}


int tester_file_vide(t_file une_file)
{
	int d = une_file.debut;
	int f = une_file.fin;
	if ((f) % 10 == d) {
		return 1;
	}
	else {
		return 0;
	}
}


int deposer_sur_sortie(t_sortie &S, t_piece P) {
	S.nb_piece = S.nb_piece + 1;
	S.liste[S.nb_piece] = P;
}


