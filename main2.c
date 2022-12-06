#include "question2.c"

int main()
{   
	
	printf("\nQUESTION N°2 : DECRYPTAGE\n\n");
														 
	///Initialisation :

	u_int32_t m,c;
    u_int32_t ensemble_des_sous_cles[11]; 
    
    
    ///***********************************************************************************
    ///1) TEST 1 :
    
    ///Initialisation c à BB57E6 et cle_maitre à 000000 
    
    c = 0xBB57E6;
    cle_maitre = m = 0;
	
	///Calcul de l'ensemble des sous clés
	
	for(int i = 0; i < 11; i++) ensemble_des_sous_cles[i] = cadencement_de_cle();

	///Affichage :
	
    printf("\n     --------------------TEST 1--------------------");
    printf("\n     -                                            -\n");
    printf("     -          MESSAGE CRYPTE : %.6X           -",c); 
    printf("\n     -          CLE MAITRE     : %.6X           -",cle_maitre);
    
    ///m prend la valeur de PRESENT24(c) soit la valeur du message clair :
    
    m = reverse_PRESENT24(c,ensemble_des_sous_cles);
    
    ///Affichage :
    
    printf("\n     -          MESSAGE CLAIR  : %.6X           -",m);
    printf("\n     -                                            -"); 

    
    

    ///***********************************************************************************
    ///2) TEST 2 :
    
    ///Initialisation c à 739293 et cle_maitre à 000000
	
	c = 0x739293;
	m = cle_maitre = 0;
	
	///Calcul de l'ensemble des sous clés
	
    for(int i = 0; i < 11; i++) ensemble_des_sous_cles[i] = cadencement_de_cle();
	
	///Affichage :
	
    printf("\n     --------------------TEST 2--------------------");
    printf("\n     -                                            -\n");
    printf("     -          MESSAGE CRYPTE : %.6X           -",c); 
    printf("\n     -          CLE MAITRE     : %.6X           -",cle_maitre);
    
    ///m prend la valeur de PRESENT24(c) soit la valeur du message clair :
    
    m = reverse_PRESENT24(c,ensemble_des_sous_cles);
    
    ///Affichage :
 
    printf("\n     -          MESSAGE CLAIR  : %.6X           -",m);
    printf("\n     -                                            -"); 
    


    
    ///***********************************************************************************
    ///3) TEST 3 :
    
    ///Initialisation c à 1B56CE et cle_maitre à FFFFFF
    
    c = 0x1B56CE;
	cle_maitre = 0xFFFFFF;
	m = 0;
	
	///Calcul de l'ensemble des sous clés
	
    for(int i = 0; i < 11; i++) ensemble_des_sous_cles[i] = cadencement_de_cle();

	///Affichage :
	
    printf("\n     --------------------TEST 3--------------------");
    printf("\n     -                                            -\n");
    printf("     -          MESSAGE CRYPTE : %.6X           -",c); 
    printf("\n     -          CLE MAITRE     : %.6X           -",cle_maitre);
    
    ///m prend la valeur de PRESENT24(c) soit la valeur du message clair :
    
    m = reverse_PRESENT24(c,ensemble_des_sous_cles);
    
    ///Affichage :
 
    printf("\n     -          MESSAGE CLAIR  : %.6X           -",m);
    printf("\n     -                                            -"); 
	


    ///***********************************************************************************
    ///4) TEST 4 :
    
    ///Initialisation de c à 47A929 et de cle_maitre à D1BD2D

    c = 0x47A929;
	cle_maitre = 0xD1BD2D;
	m = 0;
	
	///Calcul de l'ensemble des sous clés
	
    for(int i = 0; i < 11; i++) ensemble_des_sous_cles[i] = cadencement_de_cle();

	///Affichage :
	
    printf("\n     --------------------TEST 4--------------------");
    printf("\n     -                                            -\n");
    printf("     -          MESSAGE CRYPTE : %.6X           -",c); 
    printf("\n     -          CLE MAITRE     : %.6X           -",cle_maitre);
    
    ///m prend la valeur de PRESENT24(c) soit la valeur du message clair :
    
    m = reverse_PRESENT24(c,ensemble_des_sous_cles);
    
    ///Affichage :
 
    printf("\n     -          MESSAGE CLAIR  : %.6X           -",m);
    printf("\n     -                                            -");    
    printf("\n     ----------------------------------------------\n\n");
    
    return 0;   
}
