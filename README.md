#Rapport du TP Survivor
***Par Willis Pinaud et Eric Lalevée***

##Choix de construction
Dans cette partie nous presenterons des différents choix de construction que nous avons du faire dans le but de réaliser ce jeu.

###La classe Animal
La classe Animal a été structurée suite à un dialogue entre tous les étudiants de l'option.
Voici le diagramme UML la représentant:
![UML](Animal.jpg "Diagramme UML de la classe")

###Les sous-classes d'animaux
Chaque classe d'animaux reprend les fonctions virtuelles de la classe mère pour les redéfinir.
Ainsi nos classes deviennent instanciable. 
De plus, les attributs de la classe mère étant private, nous pouvons les réutiliser dans les classes filles par le principe d'héritage.

Nous avons pris en compte les spécificités de chaque espèces, par exemple l'attaque de la classe Pierre est:
'''std::string Pierre::attaquer(){
    return "PIERRE";
}'''

et la fonction '''deplacer()''' de la classe loup:
'''void Lion::deplace(int i){
    //mouvement d'une case vers le bas
    if (i%2==0){
        y=(y+1)%82;
    }
    //mouvement d'une case sur la droite
    else {
        x=(x+1)%82;
    }
}'''

Lors de la contruction d'un nouvel objet des sous classes d'animaux ses coordonnées x et y sont initialisées à l'aide d'un générateur de nombre aléatoire entre 0 et 82 (la taille du tablea).
Donc à chaque début de partie les animaux sont réparti aléatoirement sur la table de jeu.

Si le match est nul alors on selectionne un vainqueur de maniere aléatoire grâce à l'opérateur ternaire:
'''
vainqueur = ( rand()%2 ? animal1 : animal2 );
'''


###La classe DarkLoup
Notre classe Loup personnalisée possède les caractéristiques suivantes:
1) Fonction d'attaque

2) Fonction de déplacement

3) Autres singularités?


##Principe du jeu

###Comment se déroule une partie ?
Chaque partie se déroule automatiquement car le jeu est un simulateur de vie.
Notre boucle principale comporte une boucle faisant 1000 itérations.

Lors d'un tour de boucle :
0) Chaque animal est créé sur une case aléatoire de la table de jeu.
1) On appel la fonction déplacer de tous les animaux présents sur le plateau de jeu.
2) On vérifie chaque case :
	* si la case est vide on passe à la suivante.
	* si plusieurs animaux sont sur une même case on tire au sort deux animaux, on les fait combattre en appelant leur fonction attaquer, on compare les réponses puis on appel la fonction suicider du perdant.
4) On efface le plateau de jeu du tour précédent.
3) On affiche le plateau de jeu mis à jour.

###Fonction de combat
Notre fonction de combat utilise les propriétés du polymorphisme.
Elle renvoit un pointeur vers un animal et prend en arguments des pointeurs vers des animaux.
Cela nous permet de faire combattre n'importe quelle espèce entre elle.

####Fonctionnement
1) On stock le résultat des fonctions attaquer des deux animaux.
2) On les compare:
	* Feuille/Feuille = nul, donc on choisit un vainqueur aléatoirement.
	* Feuille/Pierre = La feuille gagne.
	* Feuille/Ciseau = Le ciseau gagne.
3) On appel le destructeur du perdant.
4) On renvoit l'animal vainqueur.

###Comment affiche-t-on la table de jeu ?


###Limite de notre jeu (bugs et autres joyeusetés)


##Jeux de tests

###Initialisation

###Premier tour

...

