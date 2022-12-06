#include <stdlib.h>
#include <stdio.h>
#include <time.h> ///clock question3.

#define max 16777215 ///Q3

//**************************************************************************************************************************************
//Fonction et Variables QUESTION1 :
 
/**
 * VARIABLES GLOBALES :
 * 
 * int tour; Variable qui permet de sauvegarder le tour et de le rendre accessible dans n'importe quelle fonction.
 * 
 * u_int8_t registre[10]; Tableau de 10* 8bits qui permet de sauvegarder le registre et de le rendre accessible à chaque appel de 
 * 					  	  cadencement_cle() (cf.l158).
 * 
 * u_int32_t cle_maitre; Variable qui permet la transmition de la clé maître a cadencement_cle() (cf.l158) qui n'a pas d'argument.
 * 
 * int affichage; Variable qui permet de savoir si il faut afficher ou non l'etat et la sous cle de chaque tour. 
 * 				  Utile lors de la visualisation des 11etats et clé du premier test.
 * */



/**
 * La fonction BoiteS convertit une suite binaire de 4bits (sous la forme de u_int8_t) en une autre suite
 * binaire de 4bits celon la méthode décrite dans la partie 2.2 SUBSTITUTION du devoir maison.
 * 
 * Fonctionnement :
 * 
 * 1) Initialisation :
 * 		
 * 		On initialise un u_int8_t sortie qui sera la variable que l'on va remplir et renvoyer.
 * 
 * 4) Conversion :
 * 
 * 		On recupère la valeur decimal de bits(variable en argument) et on modifie la variable sortie celon le tableau
 * 		BoîteS.
 * 
 * 5) Sortie :
 * 	
 * 		On renvoie la variable sortie.
 * 
 * 
 * NB: Boîte - S est un fonction a part entière car nous avons voulu respecter un maximum l'énoncer qui
 * 	   stipulait : "boîte-S, [...] qui prend en entrée 4 bits et qui donne en sortie 4 bits". De plus cette
 * 	   fonctionnalité nous permet d'appeller directement Boîte - S lors du cadencement des clés et non pas
 * 	   l'intégralité de substitution. Seulement 4bits sur les 8 de u_int8_t sont remplis.
 * 
 * */
u_int8_t BoiteS(u_int8_t bits);




/**
 * La fonction substitution est une fonction qui prend en entrée une suite binaire de 24 bits (sous la
 * forme d'un u_int32_t), qui va fractionner cette suite pour la faire passer dans la Boîte - S et qui va 
 * ensuite renvoyer une nouvelle suite de 24 bits (toujours sous la forme d'un u_int32_t). Elle est décrite
 * dans la partie 2.2 du devoir maison et assure la confusion au sein du cryptage.
 * 
 * Fonctionnement :
 * 
 * 1) Initialisation :
 * 		
 * 		On initialise un u_int32_t sortie qui représente la future suite de 24bits après passage dans la Boîte - S.
 * 		On initialise un u_int8_t mot qui représente les 4bits de la partie i de bits(variable en argument). (0 <= i <= 5)
 *		On initialise un u_int32_t manipulation qui va nous permettre d'isoler les bits de la varibale en argument.
 * 
 * 2) Pour i allant de 0 à 5 :
 * 
 * 		2.1) Remplissage de mot :
 * 				
 * 				On isole la ième partie de la suite de bits (4i ; 4i+1 ; 4i+2; 4i+3) dans manipulation jusqu'à que manipulation fasse 
 * 				4 bits. Une fois cela atteint, mot prend la valeur de manipulation.
 * 		
 * 		2.2) Boîte - S :
 * 		
 * 				La Boîte - S est appellée avec u_int8_t mot en argument et mot prend la valeur du nouveau mot retourné.
 * 
 * 		2.3) Remplissage sortie :
 * 
 * 				On rempli u_int32_t sortie à la position [(4*i)]; [(4*i)+1]; [(4*i)+2]; [(4*i)+3] par les bits du nouveau
 * 				mot aux mêmes positions.
 * 
 * 3) Sortie :
 * 	
 * 		On renvoie u_int32_t sortie. 
 * 
 * */
u_int32_t substitution(u_int32_t bits);




/**
 * La fonction permutation est une fonction qui prend en entrée une suite binaire de 24 bits (sous la forme d'un u_int32_t)
 * et qui renvoie une nouvelle suite de 24 bits après une permutation. Cette fonction est décrite dans la partie
 * 2.3 du devoir maison et assure la confusion du cryptage.
 * 
 * Fonctionnement :
 * 
 * 1) Initialisation :
 * 
 * 		On initialise u_int32_t sortie qui sera la future suite de bits permutée.
 * 		On initialise u_int32_t buffer qui nous permet la manipulation et l'isolement des bits souhaité.
 * 		On initialise int permu_table[24] qui represente la future position du bit i. permu_table[i] renvoie
 * 		la future position de i.
 * 
 * 2) Permutation :
 * 		
 * 		On permute bits (variable en argument) dans sortie celon la partie 2.3 du devoir maison.
 * 		On isole le i_ème bit et on le deplace à la position permu_table[i], puis on ajoute ce bit à
 * 		la variable sortie pour pouvoir ensuite la renvoyer.
 * 
 * 3) Sortie :
 *
 * 		On renvoi u_int_32 sortie.
 * 
 * */
u_int32_t permutation(u_int32_t bits);
 
 
 

/**
 * Fonction de cadencement de clé qui renvoie la sous clé i lors de son i-ème appel. La sous clé renvoyée
 * est sous la forme d'un u_int32_t et représente une suite de 24bits. Cette fonction est décrite dans la partie
 * 2.4 du devoir maison et permet la génération des sous-clés.
 * 
 * Fonctionnement :
 * 
 * 1) Initialisation 
 * 
 * 		On initialise u_int32_t sous_cle qui sera la sous_cle renvoyée
 * 		On initialise u_int32_t copy_key qui permet de copier la clé maitre pour la mettre dans le registre lors de la partie 2.1) du code.
 * 
 * 2) Si c'est le premier tour :
 * 
 * 		2.1) Initialisation du registre :
 * 
 * 				La clé maitre renseigné dans le main est placé a la postion 79 à 56.
 * 
 * 		2.2) Récupération de la sous clé :
 * 				
 * 				On récupère la i_ème sous clé qui se trouve de la position 39 à 16. 
 * 
 * 		2.3) Sortie :
 * 				
 * 				On incrémente le tour.
 * 				On retourne la sous_cle.
 * 
 * 3) Sinon :
 * 
 * 		3.1) Initialisation :
 * 
 * 				On initialise un nouveau registre u_int32_t permu_segment[10] qui représente chaque chaque segment du registre.
 * 				On initialise un u_int8_t manipulation qui va nous permettre d'isoler les bits pour lancer la substitution.
 * 
 * 		3.2) Remplissage de permu_segment :
 * 
 * 				On rempli permu segment de manière a ce que le pivot de 61 postions vers la gauche soit effectué.
 * 		
 * 		3.3) Permutation :
 * 
 * 				Les segments du registre actuel sont remplacés par les segments remplis préalablement.
 * 
 * 		3.3) Substitution du registre :
 * 				
 * 				3.3.1) Remplissage de manipulation par les 4 bits de poids fort du registre.
 * 				3.3.2) Appel de la Boîte - S avec les bits de manipulation en argument. manipulation prend la valeur des nouveaux bits.
 * 				3.3.3) En rempli le registre en replacant ces nouveaux bits à la position 79 à 76.				
 * 
 * 		3.4) XOR du registre :
 * 
 * 				Xor du registre à la position 15 à 19 par les bits du tour.
 * 
 * 		3.6) Récupération de la sous_cle :
 * 
 * 				On récupère les bits 16 à 39 du registre dans sous_cle comme à l'étape 2.2) ci dessus.
 * 
 * 		3.7) Sortie
 * 				
 * 				On incrémente le tour.
 * 				On retourne la sous_cle.
 * 
 * */
u_int32_t cadencement_de_cle();




/**
 * La fonction PRESENT24 prend en argument un message clair de 24bits (sous la forme d'un u_int32_t) et un 
 * tableau contenant l'ensemble des sous clé (0 à 10) de la clé maitre du tour. Elle renvoie
 * un message crypté de 24bits (également sous la forme d'un u_int32_t). Cette fonction décrite dans la partie 
 * 2.0 du devoir maison a pour but d'effectuer les différentes étapes du cryptage.
 * 
 * NB: Pourquoi prendre en argument un tableau d'ensemble de sous cle ? Car premierement dans l'enoncé il est stipulé que
 * 	   cet algorithme prend en argument 11 sous-clé et car lors du PRESENT24⁻¹ il sera necessaire de recalculer ce tableau.
 * 	   (Donc moins d'appels grâce a cela c'est une legère optimisation).
 * 
 * Fonctionnement :
 * 
 * 1) Initialisation :
 * 
 * 		On initialise u_int32_t Etat sur la valeur m qui represente une suite claire de 24 bits.
 * 
 * 2) Pour i allant de 1 à 10 :
 * 
 * 		2.1) XOR de l'Etat avec la sous_cle correspondante récupéré grâce au tableau
 * 
 * 		2.2) Substitution :
 * 				
 * 				Etat prend la valeur de Substitution(Etat).
 * 
 * 		2.3) Permutation :
 * 
 * 				Etat prend la valeur de Permutation(Etat).
 * 
 * 3) XOR de l'Etat et de la derniere sous clé (comme dans la partie 3.2 ci dessus)
 * 
 * 4) Sortie :
 * 
 * 		On réinitialise tour à 0.
 * 		On retourne Etat.
 * 
 * */
u_int32_t PRESENT24(u_int32_t m, u_int32_t ensemble_des_sous_cles[11]);




/**
 * La fonction main permet de faire les tests de la question 1.
 * 
 * Fonctionnement :
 * 		
 * 		1) Test 1: m = 000000 et cle_maitre = 000000
 * 		   affichage = 0; pour ne plus afficher les etats et sous clés (initialement affichage = 1/ il fonctionne comme un bool).
 * 
 * 		2) Test 2: m = FFFFFF et cle_maitre = 000000
 * 
 * 		3) Test 3: m = 000000 et cle_maitre = FFFFFF
 * 
 * 		4) Test 4: m = F955B9 et cle_maitre = D1BD2D
 * 
 * * main1.c */


//**************************************************************************************************************************************
//Fonctions QUESTION2 :



/** La fonction reverse BoiteS est exactement la même que BoiteS sauf que son tableau de substitution est inversé. 
 * */
u_int8_t reverse_BoiteS(u_int8_t bits);



/** La fonction reverse_substitution est exactement la même que substitution sauf qu'elle appelle reverse_BoiteS et non BoiteS.
 * */
u_int32_t reverse_substitution(u_int32_t bits);



/** La fonction reverse_permutation est exactement la même que permutation sauf que son tableau de permutation est inversé.
 * */
u_int32_t reverse_permutation(u_int32_t bits);



/** La fonction reverse_PRESENT24 est l'inverse de PRESENT24 et sert donc au decryptage.
 * 
 * Fonctionnement bref :
 * 
 * 1) Initialisation :
 * 
 * 		On initialise Etat sur la valeur c qui represente une suite crypte de 24 bits sous la forme d'un u_int32_t.
 * 
 * 2) Etat XOR sous_cle11
 * 
 * 3) Pour i allant de 1 à 10
 * 
 * 		3.1) Reverse permutation
 * 		3.2) Reverse substitution
 * 		3.3) Etat xor sous cle 10-i
 * 
 * 4) Sortie
 * 		
 * 		Reset de tour à 0. (pour pouvoir relancer cadecement cle apres).
 * 
 * */
u_int32_t reverse_PRESENT24(u_int32_t c, u_int32_t ensemble_des_sous_cles[11]);




/**
 * La fonction main permet de faire les tests de la question 2.
 * 
 * Fonctionnement :
 * 		
 * 		1) Test 1: c = BB57E6 et cle_maitre = 000000
 * 
 * 		2) Test 2: c = 739293 et cle_maitre = 000000
 * 
 * 		3) Test 3: c = 1B56CE et cle_maitre = FFFFFF
 * 
 * 		4) Test 4: c = F955B9 et cle_maitre = D1BD2D
 * 
 * * main2.c */


//**************************************************************************************************************************************
//Fonction et variables QUESTION3 :


/**
 * VARIABLES GLOBALES
 * 
 * #define max 16777215 : define qui permet de changer le nombre de clés a tester, initialisé sur 0xFFFFFF
 * 
 * u_int32_t clair_to_milieu[max][2] tableau qui représente toutes les possibilitées de clair to milieu avec les clés testés.
 * 									 [0] represente le milieu trouvé et [1] la clé utilisé.
 * 
 * u_int32_t chiffre_to_milieu[max][2] tableau qui représente toutes les possibilitées de chiffre to milieu.
 *  								   [0] represente le milieu trouvé et [1] la clé utilisé.	
 * 
 * u_int32_t hit1[max*2][2]	 tableau qui représente le nombre de hit entre le premier tableau clair to milieu et chiffre to milieu.
 * 					         max*2 car il peut il y avoir un maximum de max*max hits mais generalement ça ne depasse pas 1.5 * max. 
 * 					         (Pour eviter des erreurs de ségmentation)
 * 
 * u_int32_t hit2[max*2][2]  tableau qui représente le nombre de hit entre le deuxieme tableau clair to milieu et chiffre to milieu.
 * 
 * 
 * u_int32_t finalhit[max][2]  tableau qui représente le nombre de hit entre hit1 et hit2.		
 * 
 * int h1 = 0; 	nombre de hit de hit1.
 * 
 * int h2 = 0;	nombre de hit de hit2.
 * 
 * int fh = 0;  nombre de hit de final hit.
 * 
 * */
 
 
/** La fonction void tri rapide est un tri quicksort qui sert a trier les tableaux pour reduire le temps de recherche de collisions.
 * 	Elle modifie directement le tableau en argument.
 * */ 
void tri_rapide(u_int32_t tab[max][2],int first,int last); 


			
/**
 * La fonction main permet de faire l'attaque du milieu de double PRESENT24.
 * 
 * NB: Nous avons pris les couples clair chiffré de Antoine LEURIDAN.
 * 
 * Fonctionnement :
 * 		
 * 		1) Initialisation :
 * 
 * 				On initialise clock_t start et end ainsi que double elapsed qui vont nous permettre de faire un chronomètre.
 * 				On initialise int j,nextj et lastj qui vont intervenir dans la partie recherche de collision.
 * 				On initialise u_int32_t buffer qui nous permet de remplir les tableau en prenant la valeur de Present24 et reverse
 * 				Present24 à chaque appel.
 * 				On initialise un tableau ensemble des sous cle de type u_int32_t et de longueur 11 qui va nous permettre de stocker 
 * 				les sous clés pendant l'attaque.
 * 				  
 * 
 * 		I) Première attaque (m1,c1) = (a31947, 8f7f4b)
 * 
 * 				I.1) Initialisation 
 * 						
 * 						On initialise m1 et c1 sur les valeurs données par sur moodle.
 * 					    On lance le timer.
 * 				
 * 				I.2) Pour i allant de 0 à max-1 (soit 16777215-1 ou 0xFFFFFE) :
 * 
 * 					I.2.1) La clé maitre est égal à i
 * 				    I.2.2) On calcul l'ensemble des sous clés
 * 					I.2.3) On rempli le tableau clair_to_milieu avec toutes les valeurs possible de PRESENT24(m1,ensemble_des_sous_cles);
 * 					I.2.4) On rempli le tableau chiffre_to_milieu avec toutes les valeurs possible de reverse_PRESENT24(c1,ensemble_des_sous_cles);
 * 
 * 				I.3) On arrete le timer et on en relance un pour le tri.
 * 
 * 				I.4) Tri rapide des deux tableaux clair_to_mileu et chiffre_to_milieu.
 * 
 * 				I.5) On arrete le timer et on en relance un pour la recherche des collisions.
 * 
 * 				I.6) Pour i allant de 0 à max-1
 * 
 * 					I.6.1) Si i n'est pas nul on definit le prochain j :
 * 						   Tant que clair_to_milieu[i][0] == clair_to_milieu[i-1][0] , on garde le j d'avant car il faut tester toutes
 * 						   les valeurs qui sont identique. 
 * 							
 * 					I.6.2) Sinon j = nextj. Le next j représente l'emplacement ou la valeur change. 
 * 
 * 					EX : 1  1	ici i=0 et j=0. Tant que i == i-1 , on revient toujours sur lastj = j = 0 pour tester toutes les combinaisons
 * 						 1  1                   ou le milieu est identique. Nextj est calculé c'est la position j=2, car on remarque un changement 
 * 						 1  3					de valeur. 
 * 						 1	3
 * 					     3	3   ici i = 4 et j est donc directement égal à nextj = 2 pour eviter de recomparer toutes les valeurs.
 * 
 * 				I.7) Tant qui clair_to_milieu[i][0] est plus grand que chiffre_to_milieu[j][0] j++.
 * 						Cela sert a sauter les elements qui ne sont pas en communs.
 * 
 * 				I.8) Tant que clair_to_milieu[i][0] est egal à chiffre_to_milieu
 * 
 * 						I.8.1) On rempli le tableau de hit avec les clés de clair_to_milieu et chiffre_to_milieu car nous savons que 
 * 							   ce couple de clé donne le meme milieu.
 * 
 * 					    I.8.2) On incrément le conteur h1 de hit
 * 						I.8.3) On incrémente j et nextj=j. 
 * 							Cela permet de retenir le dernier j auquel clair_to_milieu[i][0] et chiffre_to_milieu[j][0] etait egaux.
 * 
 * 				I.9) Arret du chronomètre et on en relance un pour la deuxieme attaque.
 * 
 * 		II) Deuxieme attaque (m2,c2) = (17e7de,166d33)
 * 
 * 			Cette attaque est identique à la premiere donc nous n'allons pas tout redétailler. Les seuls changement sont que le tablau de hit est
 * 			maintenant hit2 et le compteur de hit h2.  
 * 			On initialise aussi m2 et c2 qui remplacerons m1 et c1.
 * 			On reinitialise également j next j et last j.
 * 
 * 		III) Arret du chronomètre et on en relance un pour le tri rapide des tableaux de hit.
 * 
 * 		III.1) Tri des tableau de hit hit1 et hit2.
 * 
 * 		III.2) Algorithme similaire a la recherche de collisions de I.6. mais cette fois ci pour les tableaux hit1 et hit2.
 * 				Le tableau finalhit sera rempli par les couples de clé présent a la fois dans hit1 et hit2.
 * 
 * 		III.3) Arret du chronomètre et affichage de la / des clé potentielles.
 * 						
 * * main3.c */








