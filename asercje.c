#include <stdio.h>

#include "stos.h"
#include "asercje.h"



/***********************************
 * W przypadku gdy stos jest pusty *
 * funkcja wypisuje komunikat na   *
 * stderr i zwraca zero.           *
 * W przeciwnym razie zwraca jeden *
 ***********************************
 * PRE:  Dostęp do adresu wskaznika*
 *       na pierwszy element stosu *
 * POST: Zwraca jeden lub zero     *
 *       i komunikat na stderr     *
 ***********************************/
int pusty_stos(t_elem**lista)
{
  if((*lista)==NULL)
    {
      fprintf(stderr,"Stos jest pusty\n");
      return 0;
    }
  else
    return 1;
}




/*Wypisuje komunikat o probie dzielenia przez zero*/
void dzielenie_przez_zero()
{
  fprintf(stderr,"Nie można dzielić przez zero\n");
}


void pierwiastek_ujemny()
{
  fprintf(stderr,"Nie można wyciągnąć pierwiastka z ujemnej liczby\n");
}
