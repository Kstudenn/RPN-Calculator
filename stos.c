/*stos.c niezbedne funckje do operowania na stosie*/
#include <stdlib.h>
#include <stdio.h>

#include "stos.h"


/*****************************
 * Służy do inicjowania      *
 * wskaznika typu t_elem     *
 *****************************
 * PRE:                      *
 * POST: Zwraca wartosc NULL * 
 *****************************/
t_elem *inicjuj()
{return NULL;}




/**************************************************
 * Funkcja odkłada zmienna dynamiczna na stos     *
 **************************************************
 * PRE: Funcka wymaga wskaznika na liste oraz     *
 *      wskaznika z adresem zmiennej dynamicznej  *
 *      odkladanej na stos.                       *
 **************************************************
 * POST: Zmienna dynamiczne jest umieszczana na   *
 *       szczycie stosu.                          *
 **************************************************/
void push(t_elem **lista,int dana)
{
  t_elem *tmp;
  tmp=inicjuj();
  tmp=(t_elem*)malloc(sizeof(t_elem));
  (tmp->liczba)=dana;
  tmp->next=NULL;
  tmp->next=*lista;
  *lista=tmp;
}




/*************************************************
 * Funkcja podnosi element ze stosu              *
 *************************************************
 * PRE: Funkcja potrzebuje adresu listy oraz     *
 *      zmiennej typu int pod ktora wpisze liczbe*
 *      z podnoszonej zmiennej dynamicznej       *
 *************************************************
 * POST: Funkcja wyjmuje ze stosu element        *
 *       przypisuje lista->liczba pod zmienna int*
 *       i zwalnia pamiec zmiennej dynamicznej   *
 *************************************************/
void pop(t_elem **lista, int *dana)
{
  t_elem *kosz;
  kosz=inicjuj();
  *dana=(*lista)->liczba;
  kosz=*lista;
  (*lista)=(*lista)->next;
  free(kosz);
}




/*******************************************
 * Funkcja sprawdza czy na liscie cos jest *
 *******************************************
 * PRE: Wymagany jest wskaznik na liste    *
 *******************************************
 * POST: Wypisuje komunikat o zawartosci   *
 *       listy.                            *  
 *******************************************/
int empty(t_elem **lista)
{
  if((*lista)!=NULL)
    return 0;
  else
    return 1;
}



/*************************************
 * Funckje maja na celu wydrukowanie *
 * zawartosci stosu                  *
 *************************************
 * Parametry:                        *
 *       **lista - adres wskaznika na*
 *       pierwszy element listy      *
 *************************************
 * PRE:  **lista - dostep do         *
 *        pierwszego elementu        *
 * POST: na stdout wyswietlana jest  *
 *       zawartosc stosu             *
 *************************************/
/*=======================================*/
void drukuj(t_elem **lista)
{     
  if((*lista)!=NULL)
    {
      printf("\n");
      printf("|STOS|\n");
      przegladaj(*lista);
    }
  else
    printf("Stos jest pusty");
}

void przegladaj(t_elem *elem)
{
  printf("%d\n", elem->liczba);
  if((elem->next)!=NULL)
    przegladaj(elem->next);  
}

/*========================================*/






/**********************************************
 * Funckje rekurencyjnie czysci cala liste    *
 * ze zmiennych dynamicznych                  *
 **********************************************/

/*==========================================*/


void wyczysc_liste(t_elem **lista)
{
  if((*lista)!=NULL)            /*Jesli lista nie jest pusta to wczytuje*/
    sprzatanie(*lista);      /*funkcje sprzatnie*/
      
}


void sprzatanie(t_elem *elem)
{
  if(elem->next!=NULL)            /*Rekurencyjnie wywoluje sama siebie na nastepnym elemencie do momentu az jego wartos wynosi NULL*/
    sprzatanie(elem->next);
  free(elem);                /*Poźniej czysci pamiec od ostatniego elementu*/
}
/*=========================================*/
