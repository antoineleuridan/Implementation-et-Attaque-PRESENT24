
#include "projetcrypto.h"

u_int8_t tour = 0;
u_int8_t registre[10];
u_int32_t cle_maitre;
int affichage = 0;


u_int8_t BoiteS(u_int8_t bits)
{	
	///1) Initialisation :
	
	u_int8_t sortie;
	
	///2) Conversion :
	
	if(!bits) sortie = 12;
	else if(bits == 1) sortie = 5;
	else if(bits == 2) sortie = 6;
	else if(bits == 3) sortie = 11;
	else if(bits == 4) sortie = 9;
	else if(bits == 5) sortie = 0;
	else if(bits == 6) sortie = 10;
	else if(bits == 7) sortie = 13;
	else if(bits == 8) sortie = 3;
	else if(bits == 9) sortie = 14;
	else if(bits == 10) sortie = 15;
	else if(bits == 11) sortie = 8;
	else if(bits == 12) sortie = 4;
	else if(bits == 13) sortie = 7;
	else if(bits == 14) sortie = 1;
	else if(bits == 15) sortie = 2;
	else printf("Error : Can't run boîte-s with the value: %d\n",bits);
	
	///3) Sortie :
	
	return sortie;
}

u_int32_t substitution(u_int32_t bits)
{	
	///1) Initialisation :

	u_int32_t manipulation;
	u_int8_t mot;
	u_int32_t sortie = 0;
	
	
	///2) Pour i allant de 0 à 5 :
	
	for(int i = 0 ; i < 6 ; i++)
	{	
		///2.1) Remplissage du mot :
		
		manipulation = 0;
		manipulation = bits << (8 + (4*i) );
		manipulation >>= 28;
		mot = manipulation;
		
		///2.2) Boîte-S :
		
		mot = BoiteS( mot );
		
		///2.3 Remplissage de sortie :
		
		sortie += mot << ((4*(5-i))); 	
	}
	
	///4) Sortie :

	return sortie;
}


u_int32_t permutation(u_int32_t bits)
{
	///1) Initialisation :

	u_int32_t sortie = 0;
	u_int32_t buffer;
	int permu_table[24];
	
	permu_table[0] = 0;		permu_table[6] = 13;	permu_table[12] = 3;		permu_table[18] = 16;
	permu_table[1] = 6;		permu_table[7] = 19;	permu_table[13] = 9;		permu_table[19] = 22;
	permu_table[2] = 12;	permu_table[8] = 2;		permu_table[14] = 15;		permu_table[20] = 5;
	permu_table[3] = 18;	permu_table[9] = 8;		permu_table[15] = 21;		permu_table[21] = 11;
	permu_table[4] = 1;		permu_table[10] = 14;	permu_table[16] = 4;		permu_table[22] = 17;
	permu_table[5] = 7;		permu_table[11] = 20;	permu_table[17] = 10;		permu_table[23] = 23;
	
	///2) Permutation :
	
	for( int i = 0 ; i < 24 ; i++ )
	{	
		buffer = 0;
		buffer = bits >> (23 - i);
		buffer <<= (31);
		buffer >>= (8);
		buffer >>= (permu_table[i]);
		sortie += buffer;
	}
	
	///3) Sortie :
	
	return sortie;	
}


u_int32_t cadencement_de_cle()
{	
	///1) Initialisation :
	
	u_int32_t copy_key;
	u_int32_t sous_cle = 0;
	
	///2) Si c'est le premier tour :
	
	if(!tour)
	{			
		///2.1) Initialisation du registre	:
	    
	    copy_key = cle_maitre;  
	     	
		registre[0] = copy_key >> 16;
		copy_key <<= 8;
		  	
		registre[1] = copy_key >> 16;
		copy_key <<= 8;
		  	
		registre[2] = copy_key >> 16;
		copy_key <<= 8;	
		
		for(int i = 3; i<10 ; i++) registre[i] = 0;
		
		///2.2) Récuperation de la sous clé :	
			
		sous_cle ^= registre[7]; 
		sous_cle ^= registre[6] << 8; 
		sous_cle ^= registre[5] << 16; 
		
		///2.3) Sortie :
		
		tour++;
		return sous_cle;
	}
	
	///3) Sinon
	
	///3.1) Initialisation :
	
	u_int8_t permu_segment[10];
	u_int8_t manipulation;
	
	for(int i = 0 ; i < 10 ; i ++) permu_segment[i] = 0;
		
	///3.2) Permutation :

	permu_segment[0] += registre[7] << 5;
	permu_segment[0] += registre[8] >> 3;
	
	permu_segment[1] += registre[8] << 5;
	permu_segment[1] += registre[9] >> 3;
	
	
	permu_segment[2] += registre[9] << 5;
	permu_segment[2] += registre[0] >> 3;
	
	permu_segment[3] += registre[0] << 5;
	permu_segment[3] += registre[1] >> 3;
	
	permu_segment[4] += registre[1] << 5;
	permu_segment[4] += registre[2] >> 3;
	
	permu_segment[5] += registre[2] << 5;
	permu_segment[5] += registre[3] >> 3;
	
	permu_segment[6] += registre[3] << 5;
	permu_segment[6] += registre[4] >> 3;
	
	permu_segment[7] += registre[4] << 5;
	permu_segment[7] += registre[5] >> 3;
	
	permu_segment[8] += registre[5] << 5;
	permu_segment[8] += registre[6] >> 3;
	
	permu_segment[9] += registre[6] << 5;
	permu_segment[9] += registre[7] >> 3;

	
	for(int i = 0 ; i < 10 ; i++ ) registre[i] = permu_segment[i];
	
	///3.3) Substitution :
		
		///3.3.1) Remplissage de manipulation :		
					
		manipulation = registre[0] >> 4;
		
		///3.3.2) Appel de la Boîte-S :
		
		manipulation = BoiteS(manipulation);
		manipulation <<=4;
		
		///3.3.3) Changement du registre :
		
		registre[0] <<= 4;
		registre[0] >>= 4;
		registre[0] ^= manipulation;
		
	///3.4) XOR
	    
		registre[8] ^= tour << 7;
		registre[7] ^= tour >> 1;
	
	///3.5) Récupération de la sous_clé :

		sous_cle ^= registre[7]; 
		sous_cle ^= registre[6] << 8; 
		sous_cle ^= registre[5] << 16; 
		
	///3.6) Sortie : 
			
	tour++;
	return sous_cle;
}


u_int32_t PRESENT24(u_int32_t m, u_int32_t ensemble_des_sous_cles[11])
{
	///1) Initialisation :
	
	u_int32_t Etat = m;
	
	///2) Pour i allant de 1 à 10 :
	
	for( int i = 1 ; i <= 10 ; i++ )
	{	
		
		///Affichage
		
		if(affichage)
		{
			printf("     - TOUR %.2d - Etat: %.6X - Sous-clé: %.6x  -\n",i,Etat,ensemble_des_sous_cles[i-1]);			
		}
		
		///2.1) XOR de l'Etat et de la sous_cle :
		
		Etat ^= ensemble_des_sous_cles[i-1];

		///2.2) Substitution :
	    
		Etat = substitution(Etat);
		
		///3.3) Permutation :

		Etat = permutation(Etat);

	}
	
	if(affichage)
	{
		printf("     - TOUR 11 - Etat: %.6X - Sous-clé: %.6x  -\n",Etat,ensemble_des_sous_cles[10]);			
	}
		
	///3) XOR de l'Etat et de la sous_cle :
	
	Etat ^= ensemble_des_sous_cles[10];
	
	///4) Sortie :
	
	tour = 0;
	
	return Etat;
}
 


