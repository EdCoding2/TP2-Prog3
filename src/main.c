# include <string.h>
# include <math.h>
# include "MD5.h"
# include <stdio.h>


void afficherUsage(){
	printf("Usage : program hash_code");
}

/// @brief Obtention de la taille d'une chaine de caratères
/// @param chaine Chaîne de caratères
/// @return Nombre de caractères
int length(char chaine[]){

	int longueur = 0;

	while (chaine[longueur]) ++longueur;

	return longueur;
}

void initTableau(char tableau[]){
	int longueur = length(tableau);

	for (int i = 0; i < longueur; i++){
		tableau[i] = ' ';
	}
}

short verificationHashCode(char tabMotsGen[], int nbDeLettres, char hashCodeOrigine[]){
	// tabMotsGen -> à être hash
	MD5_CTX context;
	unsigned char digest[16];

	MD5Init(&context);
	MD5Update(&context, tabMotsGen, strlen(tabMotsGen));
	MD5Final(digest, &context);

	char byte[3], md5[33] = "";
	for(unsigned char i = 0; i< 16; ++i){
		sprintf(byte, "%02x", digest[i]);
		strcat(md5, byte);
	}

	// verification:
	return strcmp(md5, hashCodeOrigine) ? 0 : 1;
}

/// @brief Fonction principale
/// @param argc Nombre d'arguments
/// @param argv Arguments
/// @return Code de retour du programme
int main(int argc, char* argv[]) {
	int longueurArg1 = length(argv[1]);
	char chaineArg1[33];
	strcpy(chaineArg1, argv[1]);

	//génération de mots aléatoires
	short motDePasseTrouve = 0;
	char chaineCharGeneree[1000];
	int nbDeLettres = 1;
	long nbDePossibilites = (long)pow(95, nbDeLettres);

	if(argc > 2 || argc <= 0){
		afficherUsage();
	} else{
		if(longueurArg1 != 32){
			printf("La taille de la chaine n'est as égale à 32");
		} else{
			// verifier si la chaine est hexadecimal
			for(int i = 0; i < longueurArg1; i++){
				if(!(chaineArg1[i] >= 'a' && chaineArg1[i] <= 'f') && !(chaineArg1[i] >= '0' && chaineArg1[i] <= '9')){
					printf("\n la chaine de 32 caracteres n'est pas hexadecimale!");
					//printf("\n la chaine de 32 caracteres n'est pas hexadecimale!, %i", i); si tu veux debugger
					i = longueurArg1;
				}
			}
		}
	}

	// section: Génération de chaînes de caractères.
	initTableau(chaineCharGeneree);

	while(motDePasseTrouve = 0){
		for (int i = 0; i < nbDePossibilites; i++){
			chaineCharGeneree[nbDeLettres - 1]++;
			//envoyer ceci à une fct qui vérifie le hash code avec l'original(le tableau, nbDelettres, hashcode original)
			
		}

	}

	return 0;
}