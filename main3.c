
#include "question3.c"

int main()
{		
	printf("\nQUESTION N°3 : A L'ATTAQUE\n\n");
	
	///1) Initialisation 
	
		clock_t start, end; 
		double elapsed; 
		int j,nextj,lastj;  
		                               
		u_int32_t ensemble_des_sous_cles[11];
		u_int32_t buffer;
		u_int32_t m1,c1;


		///*******************************************************************************************************
		///I) Première attaque (m1,c1) = (a31947, 8f7f4b)
		
		printf("I)\033[4m Première attaque (m1,c1) = (a31947, 8f7f4b)\033[0m.\n");
		
		///Initialisation de 31 c1
		
		m1 = 0xA31947;
		c1 = 0x8F7F4B;
		
		///Lancement du timer
		
		start = clock(); 
		
		///I.2) Pour i allant de 0 à max-1
		
		for(int i =0 ; i < max; i++) 
		{	 
			///I.2.1) La clé maitre est égal à i
			
			cle_maitre = i;
			
			///I.2.2) On calcul l'ensemble des sous clés
			
			for(int i = 0 ; i < 11; i++) ensemble_des_sous_cles[i] = cadencement_de_cle();
			
			///I.2.3&4) On rempli les tableaux
			
			buffer = PRESENT24(m1,ensemble_des_sous_cles);
			clair_to_milieu[i][0] = buffer;
			clair_to_milieu[i][1] = cle_maitre;
			
			
			buffer = reverse_PRESENT24(c1,ensemble_des_sous_cles);
			chiffre_to_milieu[i][0] = buffer;
			chiffre_to_milieu[i][1] = cle_maitre;
			
		}
		
		
		///I.3) On arrete le timer et on en relance un pour le tri.
		
		end = clock();                                    
		elapsed = ((double)end - start) / CLOCKS_PER_SEC; 
		
		///Affichage
		
		printf("\nLe remplissage de clair_to_milieu et chiffre_to_milieu a mis %f secondes à s'éxecuter.\n",elapsed);
		
		///Relance chrono
		
		start = end = 0;
		start = clock();  
			
		///I.4) Tri rapide des deux tableaux clair_to_mileu et chiffre_to_milieu.
		
		tri_rapide(clair_to_milieu,0,max-1);
		tri_rapide(chiffre_to_milieu,0,max-1);
		
		///I.5) On arrete le timer et on en relance un pour la recherche des collisions.
		
		end = clock();                                    
		elapsed = ((double)end - start) / CLOCKS_PER_SEC; 
		
		///Affichage
		
		printf("Le tri de clair_to_milieu et chiffre_to_milieu a mis %f secondes à s'éxecuter.\n",elapsed);
		
		///Initialisation de j, nextj, lastj et debut du chrono
			
		j = nextj = lastj = 0;
		start = end = 0;
		start = clock();  
		
		///Recherche collision 
		///I.6) Pour i allant de 0 à max-1
		
		for(int i = 0 ; i < max; i++)
		{	
			
			///I.6.1)
			
			if(i)
			{
				if(clair_to_milieu[i][0] == clair_to_milieu[i-1][0]) j = lastj;
				
				///I.6.2)
				
				else j = nextj;

				lastj = j;
			}
			
			///I.7)
			
			while((clair_to_milieu[i][0] > chiffre_to_milieu[j][0]) && (j < max-1) ) j++;
			
			///I.8)
			
			while((clair_to_milieu[i][0] == chiffre_to_milieu[j][0]) && (j < max-1))
				{	
					///I.8.1)
					
					hit1[h1][0] = clair_to_milieu[i][1];
					hit1[h1][1] = chiffre_to_milieu[j][1];	
					
					///I.8.2)					
					j++; h1++;
					
					///I.8.2)
					nextj = j;		
				}

		} 
		
		///I.9) Arret du chronomètre et affichage
		
		end = clock();                                    
		elapsed = ((double)end - start) / CLOCKS_PER_SEC; 
		printf("La recherche d'éléments communs entre clair_to_milieu et chiffre_to_milieu a mis %f secondes à s'éxecuter il y a ",elapsed);
		printf("%d hits.\n\n",h1);
		
		
		
		///*******************************************************************************************************
		///II) Deuxieme attaque (m2,c2) = (17e7de,166d33)
		
		printf("\nII)\033[4m Deuxieme attaque (m2,c2) = (17e7de,166d33)\033[0m.\n\n");
		
		///Initialisation de m2 et c2.
		
		u_int32_t m2,c2;
		
		m2 = 0x17E7DE;
		c2 = 0x166D33;

		///Debut du chronomètre
		
		start = end = 0;
		start = clock();
		
		///II.2) Remplissage des tableaux
		
		for(int i =0 ; i < max; i++) 
		{	
			
			cle_maitre = i;
			
			for(int i = 0 ; i < 11; i++) ensemble_des_sous_cles[i] = cadencement_de_cle();
			
			buffer = PRESENT24(m2,ensemble_des_sous_cles);
			
			clair_to_milieu[i][0] = buffer;
			
			clair_to_milieu[i][1] = cle_maitre;
			
			buffer = reverse_PRESENT24(c2 , ensemble_des_sous_cles);
			
			chiffre_to_milieu[i][0] = buffer;
			
			chiffre_to_milieu[i][1] = cle_maitre;
			
		}
		
		///Arret du chrono et affichage
		
		end = clock();                                    
		elapsed = ((double)end - start) / CLOCKS_PER_SEC; 
		printf("Le remplissage de clair_to_milieu et chiffre_to_milieu a mis %f secondes à s'éxecuter.\n",elapsed);
		
		///lancement d'un nouveau chrono
		
		start = end = 0;
		start = clock();  

		///II.3) Tri des tableaux
		
		tri_rapide(clair_to_milieu,0,max-1);
		tri_rapide(chiffre_to_milieu,0,max-1);
		
		
		end = clock();                                    
		elapsed = ((double)end - start) / CLOCKS_PER_SEC; 
		printf("Le tri de clair_to_milieu et chiffre_to_milieu a mis %f secondes à s'éxecuter.\n",elapsed);
		
		
		///II.6) Recherche des collisions
		
		start = end = 0;
		start = clock();
		j = nextj = lastj = 0;
		
		for(int i = 0 ; i < max; i++)
		{	
			
			if(i)
			{
				if(clair_to_milieu[i][0] == clair_to_milieu[i-1][0]) j = lastj;
				else j = nextj;

				lastj = j;
			}
			
			///II.7)
			
			while((clair_to_milieu[i][0] > chiffre_to_milieu[j][0]) && (j < max-1)) j++;
			
			///II.8)
			
			while((clair_to_milieu[i][0] == chiffre_to_milieu[j][0]) && (j < max-1))
				{	
					hit2[h2][0] = clair_to_milieu[i][1];
					hit2[h2][1] = chiffre_to_milieu[j][1];	
					j++; h2++;
					nextj = j;		
				}
			
		} 
		
		///Arret du chrono
		end = clock();                                    
		elapsed = ((double)end - start) / CLOCKS_PER_SEC; 
		printf("Le recherche d'éléments communs dans clair_to_milieu et chiffre_to_milieu a mis %f secondes à s'éxecuter, il y a ",elapsed);
		printf("%d hits.\n\n",h2);
		
		///III.1) Tri des tableaux de hits.
		
		start = end = 0;
		start = clock();  
		
		tri_rapide(hit1,0,h1-1);
		tri_rapide(hit2,0,h2-1);
		
		end = clock();                                    
		elapsed = ((double)end - start) / CLOCKS_PER_SEC; 
		printf("Le tri de hit1 et hit2 a mis %f secondes à s'éxecuter.\n",elapsed);
		
		///III.2) Recherche des collisions
		
		start = end = 0;
		j = lastj = nextj = 0;
		
		start = clock();
		
		for(int i = 0 ; i < h1; i++)
		{	
			
			if(i)
			{
				if(hit1[i][0] == hit1[i-1][0]) j = lastj;
				else j = nextj;

				lastj = j;
			}
			while((hit1[i][0] > hit2[j][0]) && (j < h2-1)) j++;
			
			while((hit1[i][0] == hit2[j][0]) && (j < h2-1))
				{	
					if( hit1[i][1] == hit2[j][1] )
					{
					finalhit[fh][0] = hit1[i][0];
					finalhit[fh][1] = hit1[i][1];	
					fh++;
					}
					j++;
					nextj = j;		
				}
			
		} 
		
		///III.3) Arret du chronomètre
		
		end = clock();                                    
		elapsed = ((double)end - start) / CLOCKS_PER_SEC; 
		printf("La recherche d'éléments communs dans hit1 et hit2 a mis %f secondes à s'éxecuter, il y a ",elapsed);
		printf("%d hits.\n",fh);
		
		///Affichage des clés potentielles
		
		printf("\nClé(s) potentielle(s) :\n");
		
		for(int i = 0 ; i < fh ; i++) printf("key1 : <%.6X> & key2 : <%.6X>\n",finalhit[i][0],finalhit[i][1]);
		printf("\n");
		
		return 0;
}
