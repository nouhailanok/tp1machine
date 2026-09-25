#pragma once

const int nb_max_piece_en_sortie = 99999;
const int taille_tableau = 10;
const int taille_file = taille_tableau -1;

const int LIBRE = 0;
const int OCCUPEE = 1;

const int INFINI = 2000000000;


typedef struct t_piece {
	int identifient;
	int date_entree_system;
	int date_access_serveur;
	int date_fin_service;

} t_piece;


typedef struct t_file {
	int debut;
	int fin; 
	t_piece liste[taille_file+1];
} t_file;

typedef struct t_machine {
	int etat;
	t_piece contenu;
	int DPE;
} t_machine;


typedef struct t_entree {
	int DPE;           /* date de la prochaine arrivee          */
	int compteur_id;   /* pour numeroter les pieces             */
	int nb_creees;     /* nb de pieces generees                 */
	int nb_refusees;   /* nb de pieces perdues (file pleine)    */
} t_entree;


typedef struct t_sortie {
	int nb_piece;
	t_piece liste[nb_max_piece_en_sortie];

} t_sortie;


/* Resultats d'une simulation */
typedef struct t_resultats {
	int duree;
	int nb_creees;
	int nb_refusees;
	int nb_sorties;
	double pourcentage_refusees;
	double sejour_systeme;
	double sejour_file;
	double sejour_machine;
} t_resultats;


void initialiser_file(t_file& une_file);
int  nb_elements_file(const t_file& une_file);
void ajouter_element(t_file& une_file, t_piece une_piece);
void deposer_sur_sortie(t_sortie& S, t_piece P);
int tester_file_vide(t_file une_file);
int tester_file_pleine(t_file une_file);
void retirer_element(t_file& une_file, t_piece& une_piece);
void faire_statistique(t_sortie une_sortie, float duree_moyenne_dans_le_systeme);
t_resultats simulation(int duree_simulation, int Lam, int Sa, int trace);
