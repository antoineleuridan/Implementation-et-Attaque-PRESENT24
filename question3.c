
#include "question2.c"

u_int32_t clair_to_milieu[max][2];
u_int32_t chiffre_to_milieu[max][2];
u_int32_t hit1[max*2][2];
u_int32_t hit2[max*2][2];
u_int32_t finalhit[max][2];
int h1 = 0;
int h2 = 0;
int fh = 0;


void tri_rapide(u_int32_t tab[max][2],int first,int last)
{
   u_int32_t i, j, pivot, temp, temp2;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while((tab[i][0]<=tab[pivot][0]) && (i<last)) i++;
         while(tab[j][0]>tab[pivot][0]) j--;

         if(i<j){
            temp=tab[i][0];
            temp2=tab[i][1];
            tab[i][0]=tab[j][0];
            tab[i][1]=tab[j][1];
            tab[j][0]=temp;
            tab[j][1]=temp2;
         }
      }

      temp=tab[pivot][0];
      temp2=tab[pivot][1];
      tab[pivot][0]=tab[j][0];
      tab[pivot][1]=tab[j][1];
      tab[j][0]=temp;
      tab[j][1]=temp2;
      tri_rapide(tab,first,j-1);
      tri_rapide(tab,j+1,last);

   }
}


















