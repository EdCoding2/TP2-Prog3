# bibliotheque
1. cl c /c 
2. lib 
3. documenter MD5Init, MD5Update, MD5Final, MD5_CTX(structure)

# MD5
```c
	char stringToHash[] = "Langages de programmation";

	MD5_CTX context;
	unsigned char digest[16];

	MD5Init(&context);
	MD5Update(&context, stringToHash, strlen(stringToHash));
	MD5Final(digest, &context);

	char byte[3], md5[33] = "";
	for(unsigned char i = 0; i< 16; ++i){
		sprintf(byte, "%02x", digest[i]);
		strcat(md5, byte);
	}

	printf("%s : %s\n", stringToHash, md5);
```

# Le programme
## on verifie si le code de hachage est valide + vérification des arguments

## On essaie de trouver la chaîne de caractères hachée (force brute)

(si nb de possibilités && chaîne n'a pas été trouvée) -> on agrandit le nombre de lettres de la chaine de caractères à trouver(3 lettres -> 4 lettres).

Nb de possibilités: 95(32-126) ^ nbDeLettres -> variable **long**

1. Début de la génération
En conservant l'ordre ASCII croissant (espace, !, ", #, etc.) :
| Ordre | Chaîne candidate |
| ----- | ---------------- |
| 1     | ␠␠␠              |
| 2     | !␠␠              |
| 3     | "␠␠              |
| 4     | #␠␠              |
| 5     | $␠␠              |
| 6     | %␠␠              |
| …     | …                |
| 95    | ~␠␠              |
| 96    | ␠!␠              |
| 97    | !!␠              |
| 98    | "!␠              |
| …     | …                |

*␠ représente un espace ordinaire.*

2. Vers la fin de la génération
| Ordre   | Chaîne candidate |
| ------- | ---------------- |
| 9 026   | ␠␠!              |
| 9 027   | !␠!              |
| 9 028   | "␠!              |
| …       | …                |
| 18 050  | ␠␠"              |
| …       | …                |
| 857 375 | ~~~              |


### les étapes:
1. on fait un essai de mot généré aléatoirement(au début de une lettre).
2. on verifie son hash code. (si le hash code est != de l'original(chaineArg1) -> continuer; else -> arrêter(on a trouvé le mot);) **fonction au futur**
3. Si toutes les possibilités avec X nombre de lettre a fini -> on incremente X nombre de lettre +1;

### fonction pour éviter les valeurs inutiles d'un tableau

### fonction verification de hash code
```c

short verificationHashCode(char tabMotsGen[], int nbDeLettres, char hashCodeOrigine[]){
	// tabMotsGen -> à être hash
	// si on hache le tabMotsGen comme ceci on hâchera aussi ses champs contenant des espaces. 
	// Donc, il prendre compte de seulement des indices qui sont pas des ' ' dans mon cas.
	// je pourrais prendre un autre tableau et stocker seulement les indices qui ne sont pas des ' '.
	// on fera une boucle pour stocker que les valeurs qui sont -> autre fonction

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
```


### fonction generation de mots
```c
/*
trois choix de retour:
1. retourner un * pointeur()
2. void maFonction (char tab[32]){} (modification du tableau au dedans de la fonction)
3. retourner une structure contenant le tableau

typedef struct {
    char tab[32];
} Resultat;

Resultat maFonction(void)
{
    Resultat r = {0};
    (Remplir r.tab...)
    return r;
}

*/
```
(avant la création de la fonction)

```c
// variables
(booleen) short motDePasseTrouve = 0;
char chaineArg1[33];
char chaineCharGeneree[1000] -> faudrait automatiser ceci;
int nbDeLettres = 1;
long nbDePossibilites = (long) pow(95, nbDeLettres); // #include <math.h> 

// ou faire une boucle: 
/*
long nbDePossibilites = 1;

for (int i = 0; i < nbdelettres; i++)
{
    nbDePossibilites *= 95;
}
*/




//code
// init toutes les positions du tableau à ' ' -> fonction
initTableau(chain);
while(motDePasseTrouve = 0(faux)){
	// on commence avec le tableau ayant des espaces seulement
	// test 1: est-ce que ' ' + 1 = '!' ?
	// réponse : oui.

	for (int i = 0; i < nbDePossibilites; i++){
		chaineCharGeneree[nbDeLettres - 1]++;
		//envoyer ceci à une fct qui vérifie le hash code avec l'original(le tableau, nbDelettres, hashcode original)

	}
	
}

```

**Init toutes les positions du tableau à ' '**
```c
void initTableau(char tableau[]){
	int longueur = length(tableau);

	for (int i = 0; i < longueur; i++){
		tableau[i] = ' '; 
	}
}
```

# Début du programme
Toujours exclure le premier argument argv[0], donc commencer à 1

// si nous avons plusieurs arguments  OU que nous n'avons pas d'argument

if argc > 1 || argc <= 0{
	afficher usage
}
else{
	// on vérifie si le code de hachage est une chaine de 32 caractères hexadécimale
	
	// 1. la longueur de la chaine est = 32 
	// si je veux utiliser length alors il faut faire length(argv[0])

	if (length(argv[1] != 32)){
		printf(erreur);
	} else {
		// on continue 
		// 2. vérifier si la chaine est en hexadecimal: 
	}

}

## comment vérifier si la chaine est en hexadecimal(2):

c'est une boucle (100%) sur chaque caractere: 
```c
int longueurArg1 = length(argv[1]);


for (int i = 0; i < longueurArg1; i++){
	
}
```

est-ce que argv[1][0] fonctionne? -> non 

option facile -> 
```c
char tab[33];

strcpy(tab, argv[1]);

// for (int i = 0; i < 32; i++)
// {		
// 	printf("%c", tab[i]);
// }
```

1. On parcours la chaine de caracteres et on vérifie:
if(!(tab[i] >= 'a' && tab[i] <= 'f')){
	printf("la chaine de 32 caractères n'est pas hexadecimale!");
}



# Générateur de châines de caractères

