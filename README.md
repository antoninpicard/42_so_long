# So_long

## Description
So_long est un petit jeu 2D développé dans le cadre du cursus de l'école 42. Le joueur doit collecter tous les items sur la carte et atteindre la sortie en évitant les obstacles.

## Fonctionnalités
- Déplacement du joueur avec les touches WASD ou les flèches directionnelles
- Collecte d'items
- Gestion des collisions avec les murs
- Compteur de mouvements
- Sortie accessible uniquement après avoir collecté tous les items
- Gestion des fichiers de carte au format .ber

## Prérequis
- CC ou Clang
- Make
- MinilibX (incluse dans le projet)
- Bibliothèques X11 pour Linux

## Installation
```bash
# Cloner le dépôt
git clone https://github.com/antoninpicard/42_so_long
cd so_long

# Compiler le projet
make
```

## Utilisation
```bash
./so_long map/nom_de_la_carte.ber
```

### Format des cartes
Les cartes doivent être au format .ber et contenir uniquement les caractères suivants :
- `0` : Espace vide
- `1` : Mur
- `C` : Item à collecter
- `E` : Sortie
- `P` : Position de départ du joueur

Exemple de carte valide :
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## Contrôles
- `W` ou `↑` : Déplacement vers le haut
- `S` ou `↓` : Déplacement vers le bas
- `A` ou `←` : Déplacement vers la gauche
- `D` ou `→` : Déplacement vers la droite
- `ESC` : Quitter le jeu

## Compilation
Le projet utilise un Makefile avec les règles suivantes :
- `make` : Compile le projet
- `make clean` : Supprime les fichiers objets
- `make fclean` : Supprime les fichiers objets et l'exécutable
- `make re` : Recompile le projet
- `make force` : Force la recompilation de tous les fichiers

## Auteur
- anpicard
