#include "question1.c"

int main()
{   
	
	printf("\nQUESTION N°1 : CRYPTAGE\n\n");
														 
	///Initialisation :
	
	u_int32_t m,c;
    u_int32_t ensemble_des_sous_cles[11];
    
    
    ///***********************************************************************************
    ///1) TEST 1 :
        
    ///Affichage = 1 car l'on veut avoir une trace de tout les etats et toutes les sous clés.
    
    affichage = 1;
    
    ///Initialisation m à 000000 et cle_maitre à 000000
    
    m = c = cle_maitre = 0;
    
    for( int i = 0; i < 11 ; i++) { ensemble_des_sous_cles[i] = cadencement_de_cle();  }
	
	///Affichage :
	
    printf("\n     --------------------TEST 1--------------------");
    printf("\n     -                                            -");
    printf("\n     -          MESSAGE CLAIR  : %.6X           -",m);
    printf("\n     -          CLE MAITRE     : %.6X           -",cle_maitre);
    printf("\n     -                                            -\n"); 
    
    ///c prend la valeur de PRESENT24(m) soit la valeur du message chiffré :
    
    c = PRESENT24(m,ensemble_des_sous_cles);
    
    ///Affichage :
    
    printf("     -                                            -\n");
    printf("     -          MESSAGE CRYPTE : %.6X           -",c); 
    printf("\n     -                                            -"); 
  
    ///On ne souhaite plus afficher les Etat et sous clé à chaque tours :
    
    affichage = 0;
    
    
    
    ///***********************************************************************************
    ///2) TEST 2 :
        
    ///Initialisation m à FFFFFF et cle_maitre à 000000
     
    m = 0xFFFFFF;
    c = cle_maitre = 0;
    
    ///Calcul de l'ensemble des ous clés :
    
    for( int i = 0; i < 11 ; i++) ensemble_des_sous_cles[i] = cadencement_de_cle();
	
	///Affichage :
	
    printf("\n     --------------------TEST 2--------------------");
    printf("\n     -                                            -");
    printf("\n     -          MESSAGE CLAIR  : %.6X           -",m);
    printf("\n     -          CLE MAITRE     : %.6X           -\n",cle_maitre); 
    
    ///c prend la valeur de PRESENT24(m) soit la valeur du message chiffré :
    
    c = PRESENT24(m,ensemble_des_sous_cles);
    
    ///Affichage :
    
    printf("     -          MESSAGE CRYPTE : %.6X           -",c); 
    printf("\n     -                                            -"); 
  

   
   
    ///***********************************************************************************
    ///3) TEST 3 :
        
    ///Initialisation m à 000000 et cle_maitre à FFFFFF
    
    
    cle_maitre = 0xFFFFFF;
    m = c = 0;
    
    ///Calcul de l'ensemble des sous clés :
        
    for( int i = 0; i < 11 ; i++) ensemble_des_sous_cles[i] = cadencement_de_cle(); 
	
	///Affichage :
	
    printf("\n     --------------------TEST 3--------------------");
    printf("\n     -                                            -");
    printf("\n     -          MESSAGE CLAIR  : %.6X           -",m);
    printf("\n     -          CLE MAITRE     : %.6X           -\n",cle_maitre); 
    
    ///c prend la valeur de PRESENT24(m) soit la valeur du message chiffré :
    
    c = PRESENT24(m,ensemble_des_sous_cles);
    
    ///Affichage :
    
    printf("     -          MESSAGE CRYPTE : %.6X           -",c); 
    printf("\n     -                                            -"); 
    
    
    
    
    ///***********************************************************************************
    ///4) TEST 4 
    
	///m prend la valeur F955B9 et cle_maitre prend la valeur D1BD2D

    m = 0xF955B9;
    cle_maitre = 0xD1BD2D;
    c = 0;
    
    ///On calcul l'ensemble des sous clés
    
    for( int i = 0; i < 11 ; i++) ensemble_des_sous_cles[i] = cadencement_de_cle(); 

	///Affichage :
	
    printf("\n     --------------------TEST 1--------------------");
    printf("\n     -                                            -");
    printf("\n     -          MESSAGE CLAIR  : %.6X           -",m);
    printf("\n     -          CLE MAITRE     : %.6X           -\n",cle_maitre);
    
    ///c prend la valeur de PRESENT24(m) soit la valeur du message chiffré :
    
    c = PRESENT24(m,ensemble_des_sous_cles);
    
    ///Affichage :
    
    printf("     -          MESSAGE CRYPTE : %.6X           -",c); 
    printf("\n     -                                            -"); 
    
    ///Affichage :
    
    printf("\n     ----------------------------------------------\n\n");
    
    return 0;   
}
