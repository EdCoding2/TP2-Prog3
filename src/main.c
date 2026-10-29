/// @file main.c
/// @brief Programme de recherche de chaîne correspondant à un hash MD5.
/// @authors Eduardo De Oliveira Rodrigues

# include <string.h>
# include <math.h>
# include "MD5.h"
# include <stdio.h>

/// @brief Affiche la syntaxe d'utilisation du programme.
void afficherUsage(){
	printf("Usage : program hash_code");
}

/// @brief Calcule la longueur d'une chaîne de caractères.
/// @param chaine Chaîne de caractères à mesurer.
/// @return Nombre de caractères présents dans la chaîne.
int length(char chaine[]){
	int longueur = 0;
	if(chaine)
		while (chaine[longueur]) ++longueur;
	else 
		return -1;
	return longueur;
}

/// @brief Initialise un tableau avec des espaces et termine la chaîne par '\0'.
/// @param tableau Tableau à initialiser.
/// @param taille Nombre de caractères du tableau.
void initTableau(char tableau[], int taille){
	for (int i = 0; i < taille; i++){
		if(i == taille - 1)
			tableau[i] = '\0';
		else
			tableau[i] = ' ';
	}
}

/// @brief Vérifie si une chaîne correspond au hash MD5 attendu.
/// @param tabMotsGen Chaîne de caractères à hacher.
/// @param nbDeLettres Nombre de caractères de la chaîne.
/// @param hashCodeOrigine Hash MD5 de référence.
/// @return 0 si le hash correspond, 1 sinon.
short verificationHashCode(char tabMotsGen[], int nbDeLettres, char hashCodeOrigine[]){
	MD5_CTX context;
	unsigned char digest[16];

	MD5Init(&context);
	MD5Update(&context, tabMotsGen, nbDeLettres);
	MD5Final(digest, &context);

	char byte[3], md5[33] = "";
	for(unsigned char i = 0; i< 16; ++i){
		sprintf(byte, "%02x", digest[i]);
		strcat(md5, byte);
	}

	return !(strcmp(md5, hashCodeOrigine)) ? 0 : 1;
}

/// @brief Incrémente une chaîne de caractères en gardant un alphabet ASCII visible.
/// @param chaine Chaîne à incrémenter.
/// @param longueur Longueur de la chaîne.
void incrementerChaine(char chaine[], int longueur) {
  for (int i = longueur - 1; i >= 0; i--) {
      if (chaine[i] < 126) {
        chaine[i]++;
        return;
      }

      chaine[i] = 32;
    }
}

/// @brief Fonction principale du programme.
/// @param argc Nombre d'arguments passés au programme.
/// @param argv Tableau des arguments du programme.
/// @return Code de retour du programme.
int main(int argc, char* argv[]) {
	int longueurArg1;
  char chaineHashCode[33];
  short motDePasseTrouve = 0;
  char chaineCharGeneree[10];
  int nbDeLettres = 1;
  unsigned long long nbDePossibilites = 95;
  unsigned long long nbPossibilitesPrecendentes = 0;
  int i;

  if (argc != 2) {
    afficherUsage();
    return 1;
  }

  longueurArg1 = length(argv[1]);
  strcpy(chaineHashCode, argv[1]);

	if(longueurArg1 != 32){
		printf("La taille de la chaine n'est as égale à 32\n");
		return 1;
	} 

	for(int i = 0; i < longueurArg1; i++){
		if(!(chaineHashCode[i] >= 'a' && chaineHashCode[i] <= 'f') && !(chaineHashCode[i] >= '0' && chaineHashCode[i] <= '9')){
			printf("\n la chaine de 32 caracteres n'est pas hexadecimale!");
			i = longueurArg1;
			return 1;
		}
	}
		
	initTableau(chaineCharGeneree, 10);

	while(motDePasseTrouve == 0){
		for (unsigned long long i = 0; i <= (nbDePossibilites - nbPossibilitesPrecendentes); i++){
			if(i == (nbDePossibilites - nbPossibilitesPrecendentes)){
				nbPossibilitesPrecendentes = nbDePossibilites;
				nbDeLettres++;
				initTableau(chaineCharGeneree, nbDeLettres);
				nbDePossibilites = (long)pow(95, nbDeLettres);
			}

			incrementerChaine(chaineCharGeneree, nbDeLettres);
			if(!(verificationHashCode(chaineCharGeneree, nbDeLettres, chaineHashCode))){
				motDePasseTrouve = 1;
				i = nbDePossibilites;
				printf("Hash code: %s \nChaine: %s", chaineHashCode, chaineCharGeneree);
			}
		}
	}
	
	return 0;
}