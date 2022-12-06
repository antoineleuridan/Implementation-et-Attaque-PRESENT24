
#include "question1.c"

u_int8_t reverse_BoiteS(u_int8_t bits)
{	
	///1) Initialisation :
	
	u_int8_t sortie;
	
	///2) Conversion inverse:
		
	if(!bits) sortie = 5;
	else if(bits == 1) sortie = 14;
	else if(bits == 2) sortie = 15;
	else if(bits == 3) sortie = 8;
	else if(bits == 4) sortie = 12;
	else if(bits == 5) sortie = 1;
	else if(bits == 6) sortie = 2;
	else if(bits == 7) sortie = 13;
	else if(bits == 8) sortie = 11;
	else if(bits == 9) sortie = 4;
	else if(bits == 10) sortie = 6;
	else if(bits == 11) sortie = 3;
	else if(bits == 12) sortie = 0;
	else if(bits == 13) sortie = 7;
	else if(bits == 14) sortie = 9;
	else if(bits == 15) sortie = 10;
	else printf("Error : Can't run boîte-s with the value: %d\n",bits);
	
	///3) Sortie :
		
	return sortie;
}


u_int32_t reverse_substitution(u_int32_t bits)
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
		
		///2.2) Reverse Boîte-S :
		
		mot = reverse_BoiteS( mot );

		///2.3 Remplissage de sortie :
		
		sortie += mot << ((4*(5-i))); 
	}
	
	///4) Sortie :

	return sortie;
}


u_int32_t reverse_permutation(u_int32_t bits)
{
	///1) Initialisation :

	u_int32_t sortie = 0;
	u_int32_t buffer;
	int permu_table[24];
	
	permu_table[0] = 0;		permu_table[6] = 1;		permu_table[12] = 2;		permu_table[18] = 3;
	permu_table[1] = 4;		permu_table[7] = 5;		permu_table[13] = 6;		permu_table[19] = 7;
	permu_table[2] = 8;		permu_table[8] = 9;		permu_table[14] = 10;		permu_table[20] = 11;
	permu_table[3] = 12;	permu_table[9] = 13;	permu_table[15] = 14;		permu_table[21] = 15;
	permu_table[4] = 16;	permu_table[10] = 17;	permu_table[16] = 18;		permu_table[22] = 19;
	permu_table[5] = 20;	permu_table[11] = 21;	permu_table[17] = 22;		permu_table[23] = 23;
	
	///2) Permutation inverse :
	
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


u_int32_t reverse_PRESENT24(u_int32_t c, u_int32_t ensemble_des_sous_cles[11])
{
	///1) Initialisation :
	
	u_int32_t Etat = c;
	
	///2) Etat XOR cle 11
		
	Etat ^= ensemble_des_sous_cles[10];
	
	///3) Pour i allant de 1 à 10 :
	
	for( int i = 1 ; i <= 10 ; i++ )
	{	
			
		///3.1) Reverse_permutation :
		
		Etat = reverse_permutation(Etat);
		
		///3.2) Reverse_substituion :
		
		Etat = reverse_substitution(Etat);
		
		///3.3) Etat XOR cle 10-i :
		
		Etat ^= ensemble_des_sous_cles[10-i];

	}
	
	///6) Sortie :
	
	tour = 0;
	
	return Etat;
}

