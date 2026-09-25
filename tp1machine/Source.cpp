#include "struc.h"
#include <cstdio>
#include <cstdlib>

 
void ajouter_element(t_file& une_file, t_piece une_piece)
{
	if ((une_file.fin + 1) % taille_tableau == une_file.debut){
		printf("Erreur : ajout dans une file pleine\n");
		exit(-1);
	}
	else
	{
		une_file.liste[une_file.fin] = une_piece;

		une_file.fin = (une_file.fin + 1) % taille_tableau;
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

int nb_elements_file(const t_file& une_file)
{
	return (une_file.fin - une_file.debut + taille_tableau) % taille_tableau;
}


int tester_file_pleine(t_file une_file)
{
	int d = une_file.debut;
	int f = une_file.fin;
	if ((f + 1) % taille_tableau == d) {
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
	if ((f) % taille_tableau == d) {
		return 1;
	}
	else {
		return 0;
	}
}

void initialiser_file(t_file& une_file)
{
	une_file.debut = 0;
	une_file.fin = 0;
}


void deposer_sur_sortie(t_sortie &S, t_piece P) {
	S.nb_piece = S.nb_piece + 1;
	S.liste[S.nb_piece] = P;
}

void faire_statistique(t_sortie une_sortie, float duree_moyenne_dans_le_systeme) {

}

t_resultats simulation(int duree_simulation, int Lam, int Sa, int trace);