#include <stdio.h>
#include <ctype.h>

#include "stos.h"
#include "operacje.h"


/*******************************************
 * Autor: Kacper Studenny                  * 
 * Data ukończenia programu: 28.01.2017    *
 *******************************************
 * Kalkulator działający na zasadzie RPN   *
 * na liczbach rzeczywistych, dziesiętnych *
 *-----------------------------------------*
 * Podawania liczb na wejście powoduje     *
 * zapisanie ich na stosie [wskaznik na    *
 * jego pierwszy element to *lista].       *
 *******************************************
 * Funkcje:                                *
 *    '+' - Dodaje dwa elementy ze szczytu *
 *          stosu i odklada wynik na stos  *
 *    '-' - Odejmuje dwa elementy ze       *
 *          szczytu stosu i odklada na     *
 *          niego wynik                    *
 *    '/' - Dokonuje dzielenia, gdzie      *
 *          dzielnikiem jest liczba        *
 *          z wierzchy stosu [RPN]         *
 *    '*' - Mnoży dwa pierwsze elementy ze *
 *          stosu i odklada wynik na stos  *
 *    '^' - Poteguje pierwsza liczbe ze    *
 *          stosu i odklada wynik na stos  *
 *    '%' - Dzielenie modulo, gdzie        *
 *          dzielnikiem jest liczba z      *
 *          wierzchy stosu                 *
 *    'p' - Wyciaga pierwiastek z liczby   *
 *          z wierzchy stosu zaokraglony   *
 *          do czesci pierwszych i wynik   *
 *          odklada na stos                *
 *    '#' - Usun element z wierzchu stosu  *
 *    '$' - Zamien kolejnoscia dwa elementy*
 *          z wierzchu stosu               *
 *    '&' - Zdubplikuj element z wierzchu  *
 *          stosu                          *
 *    '?' - Wydrukuj zawartosc stosu       *
 *          poczynajac od elementu z jego  *
 *          wierzchu                       *
 *    'q' - zakoncz dzialanie programu     *
 *******************************************/



int main()
{

  t_elem *lista;
  char oper, pom;
  int arg;
  
  lista=inicjuj();
  
  do{
    oper=getchar();
    
    if(isdigit(oper))
     {
       ungetc(oper,stdin);
       scanf("%d",&arg);
       push(&lista,arg);
     }
    
    if(oper=='-')
      {
	oper=getchar();
	
       if(isdigit(oper))
	 {
	   ungetc(oper,stdin);
	   scanf("%d", &arg);
	   push(&lista,(-arg));
	 }
       else
	 {
	   pom='-';
	   menu_wyboru(pom,&lista);
	   menu_wyboru(oper,&lista);
	 }
      }
    
    if(oper=='+')
     {
       oper=getchar();
       if(isdigit(oper))
	 {
	   ungetc(oper,stdin);
	   scanf("%d", &arg);
	   push(&lista,arg);
	 }
       else
	 {
	   pom='+';
	   menu_wyboru(pom,&lista);
	   menu_wyboru(oper,&lista);
	 }
     }

   
   else
     menu_wyboru(oper,&lista);
   
   
  }while(oper!='q');
  
  wyczysc_liste(&lista);

  
}
