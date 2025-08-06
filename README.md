# Morpion IA

Un jeu de morpion (tic-tac-toe) avec intelligence artificielle en C++.

## Description

Ce projet implémente un jeu de morpion classique avec la possibilité de jouer contre une intelligence artificielle. Le jeu utilise des algorithmes d'IA pour créer une expérience de jeu intelligente et engageante.

## Fonctionnalités

- Interface de jeu en console
- Intelligence artificielle pour l'adversaire
- Différents niveaux de difficulté
- Sauvegarde des parties
- Statistiques de jeu

## Prérequis

- CMake 3.10 ou supérieur
- Compilateur C++ compatible (GCC, Clang, MSVC)

## Installation

1. Clonez le dépôt :
```bash
git clone <url-du-depot>
cd morpion_ia
```

2. Créez un dossier de build :
```bash
mkdir build
cd build
```

3. Configurez et compilez :
```bash
cmake ..
make
```

## Utilisation

Lancez le jeu avec :
```bash
./morpion_ia
```

## Structure du projet

```
morpion_ia/
├── README.md
├── .gitignore
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   ├── game/
│   │   ├── board.cpp
│   │   ├── player.cpp
│   │   └── ai.cpp
│   └── utils/
│       └── helpers.cpp
└── include/
    ├── game/
    │   ├── board.h
    │   ├── player.h
    │   └── ai.h
    └── utils/
        └── helpers.h
```

## Contribution

Les contributions sont les bienvenues ! N'hésitez pas à ouvrir une issue ou à soumettre une pull request.

## Licence

Ce projet est sous licence MIT. 