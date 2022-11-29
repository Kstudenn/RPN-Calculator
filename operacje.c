#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "stos.h"
#include "operacje.h"
#include "asercje.h"


/****************************************************
 * Funkcja w ktorej w zaleznosci od znaku zawartego *
 * w <operator> dokonywana jest zmiana na liczbach  *
 * poczynajac od pierwszej na stosie                * 
 ****************************************************
 * Parametry:                                       *
 *       oper    - znak operacji w <menu_wboru>     *
 *       **lista - poczatek stosu, pierwszy element *
 ****************************************************
 * PRE:  operator, przechowuje znak do dzialan mat  *
 *       ematycznych lub logicznych                 *
 *       **lista jest adresem na wskaznik pokazujacy*
 *       pierwszy element stosu.                    *
 * POST: W zaleznosci od potrzeby pom1 lub pom2     *
 *       staje sie wynikiem operacji matematycznej  *
 *       lub operacji na elementach stosu           *
 ****************************************************/




void menu_wyboru(char operator, t_elem **lista)
{
  int pom1, pom2;
  
  switch(operator)
    {
      
/*===================Działania Matematyczna====================*/


  /*  *----------------------------------------------*  */
  /*  | Wszystkie funkcje opcje switcha robiace oper-|  */
  /*  | acje na liczbach zostaly wzbogacone o asercje|  */
  /*  | badajaca przed dokonaniem dzialania czy      |  */
  /*  | stos nie jest pusty. Po czym kontynuuje      |  */
  /*  | dzialanie lub je przerywa i zwraca komunikat |  */
  /*  *----------------------------------------------*  */


      
    /*suma*/
    case '+':          
      if(pusty_stos(lista))   /*jesli stos pusty zwraca zero i
				wypisuje komunikat na stderr*/
	{
	  pop(lista,&pom1);
	  if(pusty_stos(lista))
	    {
	      pop(lista,&pom2);
	      dodawanie(&pom1,&pom2);
	      push(lista,pom1);
	    }
	  else
	    {
	      push(lista,pom1);     /*Zwraca pobrany element
				     bo drugiego w stosie juz nie ma				    i nie mozna przeprowadzic dzialania*/
	    }                   
	}
      break;

    /*różnica*/
    case '-':          
      if(pusty_stos(lista))   /*jesli stos pusty zwraca zero i
				wypisuje komunikat na stderr*/
	{
	  pop(lista,&pom1);
	  if(pusty_stos(lista))
	    {
	      pop(lista,&pom2);
	      odejmowanie(&pom2,&pom1);
	      push(lista,pom2);
	    }
	  else
	    push(lista,pom1);      /*Zwraca pobrany element bo drugiego w stosie juz nie ma i nie mozna przeprowadzic dzialania*/

	    
	}
      break;

    /*dzielenie*/
    case '/':         
      if(pusty_stos(lista))   /*jesli stos pusty zwraca zero i wypisuje komunikat na stderr*/
	{
	  pop(lista,&pom1);
	  if(pom1!=0)
	    {
	      if(pusty_stos(lista))
		{
		  pop(lista,&pom2);
		  dzielenie(&pom2,&pom1);
		  push(lista,pom2);
		}
	      else
		push(lista,pom1);       /*Zwraca pobrany element bo drugiego w stosie juz nie ma i nie mozna przeprowadzic dzialania*/
		
	    }
	  else
	    {
	      dzielenie_przez_zero();
	      push(lista,pom1);
	    }
	}
      break;

    /*mnożenie*/
    case '*':           
      if(pusty_stos(lista))   /*jesli stos pusty zwraca zero i
				wypisuje komunikat na stderr*/
	{
	  pop(lista,&pom1);
	  if(pusty_stos(lista))
	    {
	      pop(lista,&pom2);
	      mnozenie(&pom2,&pom1);
	      push(lista,pom2);
	    }
	  else
	    push(lista,pom1);      /*Zwraca pobrany element bo drugiego w stosie juz nie ma i nie mozna przeprowadzic dzialania*/
	  
	}          
      break;

    /*pierwiastek*/
    case 'p':            
      if(pusty_stos(lista))   /*jesli stos pusty zwraca zero i
				wypisuje komunikat na stderr*/
	{

	  pop(lista, &pom1);
	  if(pom1>=0)
	    {
	      pierwiastek(&pom1);
	      push(lista,pom1);
	    }
	  else
	    {
	      push(lista,pom1);
	      pierwiastek_ujemny();
	    }
	}
      break;
    case '^':               /*potęgowanie*/
      if(pusty_stos(lista))    /*jesli stos pusty zwraca zero i
				wypisuje komunikat na stderr*/
	{
	  pop(lista,&pom1);
	  potega(&pom1);
	  push(lista,pom1);
	}
      break;

    /*dzielenie modulo*/
    case '%':             
      if(pusty_stos(lista))   /*jesli stos pusty zwraca zero i wypisuje komunikat na stderr*/
	{
	  pop(lista, &pom1);
	  if(pom1!=0)
	    {
	      if(pusty_stos(lista))
		{
		  pop(lista, &pom2);
		  modulo(&pom2,&pom1);
		  push(lista, pom2);
		}
	      else
		{
		  push(lista,pom1);      /*Zwraca pobrany element bo drugiego w stosie juz nie ma i nie mozna przeprowadzic dzialania*/
		}
	    }
	  else
	    
	    {
	      dzielenie_przez_zero();
	      push(lista,pom1);
	    }
	}   
      break;
    
 /**********************OPERACJE MODYFIKACJI******************/

    case '#':      /*usuniecie elementu ze szczytu stosu*/
      pop(lista,&pom1);
      break;
    case '$':     /*zamiana kolejnosci dwoch elementow na szczycie stosu*/
      pop(lista,&pom1);
      pop(lista,&pom2);
      push(lista,pom1);
      push(lista,pom2);
      break;
    case '&':  /*duplikowanie elemntu na szczycie sotsu*/
      pop(lista,&pom1);
      push(lista,pom1);
      push(lista,pom1);
      break;
    case '?':  /*wydrukuj zawartosc stosu*/
      drukuj(lista);
      break;
    case 'q': /* koniec programu, zbedne przy petli while*/
      break;

    }
}





/**************************************************/





/***************************************
 * Zbiór funkcji, które dokonuja       *
 * prostych obliczen matematycznych    *
 * zaimplementowanych w kalkulatorze   *
 ***************************************
 * Parametry:                          *
 *       pom1 - pierwsza liczba (int)  *
 *       pom2 - druga liczba (int)     *
 ***************************************
 * PRE:  pom1, pom2, bedace liczbami   *
 *       do dokonania operacji         *
 *       matematycznej.                *
 * POST: pod pom1 wpisywany jest wynik *
 ***************************************/

void dodawanie(int *pom1,int *pom2)
{
  *pom1=(*pom1)+(*pom2);
}

void odejmowanie(int *pom1,int *pom2)
{
  *pom1=(*pom1)-(*pom2);
}

void dzielenie(int *pom1,int *pom2)
{
  *pom1=(*pom1)/(*pom2);
}

void mnozenie(int *pom1,int *pom2)
{
  *pom1=(*pom1)*(*pom2);
}

void modulo(int *pom1,int *pom2)
{
  *pom1=(*pom1)%(*pom2);
}

void pierwiastek(int *pom1)
{
  *pom1=sqrt((float)(*pom1));
}

void potega(int *pom1)
{
  *pom1=(*pom1)*(*pom1);
}
	    
/*******************************************************************/

