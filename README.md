# Projet Printf en C

### Explication du projet :
Pour ce projet, l'objectif était de reproduire une grande partie des fonctionnalités de la fonction dprintf de la bibliothèque standard. 

Elle prend comme paramètres :
* fd : le descripteur de fichier sur lequel écrire
* pattern : la chaîne a afficher qui contient des formats
* ... : les arguments variadiques

Voici les differents formats que nous avons implémenté :
* %c pour les caractères individuels ;
* %s pour les chaînes de caractères ;
* %d pour les entiers à afficher en base 10 ;
* %p pour les pointeurs à afficher en base 16 ;
* %x pour les entiers à afficher en base 16 ;
* %b pour les entiers à afficher en binaire ;
* %o pour les entiers à afficher en base 8 ;
* %% pour afficher le symbole %.
