#pragma once

const int nb_max_piece_en_sortie = 99999;
const int taille_tableau = 10;
const int taille_file = taille_tableau -1;

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


} t_entree;


typedef struct t_sortie {
	int nb_piece;
	t_piece liste[nb_max_piece_en_sortie];

} t_sortie;

void ajouter_element(t_file& une_file, t_piece une_piece);