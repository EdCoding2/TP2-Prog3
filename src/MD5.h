/// @brief Contexte contenant l'état interne du calcul MD5
typedef struct {
    unsigned int state[4];   ///< État interne de l'algorithme (A, B, C et D)
    unsigned int count[2];   ///< Nombre total de bits traités, modulo 2^64
    unsigned char buffer[64]; ///< Tampon de 64 octets pour les données à traiter
} MD5_CTX;

/// @brief Initialiser le contexte de calcul MD5
/// @param context Contexte MD5 à initialiser
void MD5Init(MD5_CTX *context);

/// @brief Ajouter des données au calcul de l'empreinte MD5
/// @param context Contexte MD5 à mettre à jour
/// @param input Données à traiter
/// @param inputLen Nombre d'octets à traiter
void MD5Update(MD5_CTX *context, unsigned char *input, unsigned int inputLen);

/// @brief Finaliser le calcul MD5 et produire l'empreinte résultante
/// @param digest Tableau de 16 octets dans lequel stocker l'empreinte MD5
/// @param context Contexte MD5 contenant l'état du calcul
void MD5Final(unsigned char digest[16], MD5_CTX *context);