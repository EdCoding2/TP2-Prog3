# bibliotheque
1. cl c /c 
2. lib 
3. documenter MD5Init, MD5Update, MD5Final, MD5_CTX(structure)


# Le programme
## on verifie si le code de hachage est valide + vérification des arguments

## On essaie de trouver la chaîne de caractères hachée (force brute)



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

