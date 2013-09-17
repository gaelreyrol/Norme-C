Norme-C
====

Projet Open Source dédié à l'implémentation de la "norminette" en C. C'est à titre expérimental et pédagogique,
afin d'augmenter mes compétences pour permmettre un approfondissement dans le language.
N'hésitez pas à contribuer :D

====

Instalation :
-------------

 - make
 - ./norme file_to_scan.(c/h)

ToDo :
--------

- Filtres (regex) :
	- Intégrité du header
	- 80 caractères par lignes
	- Mots-clé et fonctions interdites
	- Indetation
	- Syntaxe (espaces, tabulations)
	- 5 déclarations par fonctions
	- 25 lignes par fonction (à l'intérieur des accolades)
- Disociation des filtres en fonction du type de fichier
- Mode :
	- Récursif
	- Log
	- Gestion des filtres
- Stockage des erreurs (Fichier: Ligne: Erreur)
