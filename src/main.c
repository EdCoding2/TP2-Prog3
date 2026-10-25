# include <string.h>

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

/// @brief Fonction principale
/// @param argc Nombre d'arguments
/// @param argv Arguments
/// @return Code de retour du programme
int main(int argc, char* argv[]) {
	int longueurArg1 = length(argv[1]); 
	char chaineArg1[33];
	strcpy(chaineArg1, argv[1]);
	
	char stringToHash[100]; // string pour le hachage
	
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
	


	return 0;
}