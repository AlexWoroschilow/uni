/* Programm: Taschenrechner.c             Oktober 2010
 *  Ziel: Ist ja wohl klar :)                                       */

#include <stdio.h>

int main()
{
  int operator;      /* Variable fuer: +, -, *, / */
  float op1;         /* 1.Operand */
  float op2;         /* 2.Operand */

  printf(" >> Taschenrechner\n");       /* Textausgabe */

  printf(" Was wollen Sie berechnen: Summe (0), Differenz (1), Produkt (2),"
                   " Quotient (3): ");                  /* Textausgabe */

  scanf("%d", &operator);									/* Hier soll der Operator eingelesen werden */

  printf("\n");
											/*Bedingung testet, ob die Eingabe gueltig ist, falls nicht->Fehlermeldung*/
  if (!( operator == 0 || operator == 1 || operator == 2 || operator == 3) ) {
    printf("Dies ist keine gueltige Eingabe. Versuchen Sie es spaeter nochmal!\n");
  } else {										/* korrekte Eingabe -> Programm laeuft weiter: 1.Operand eingeben*/
    printf(" Geben Sie nun ihre beiden Operanden ein.\n");
    printf(" Operand 1: ");
    if (scanf("%f", &op1) != 1) {							/* Eingabe 1.Operand und Eingabetest*/
      printf("  Bitte das naechste Mal eine Zahl eingeben. Danke.\n");			/*Hier soll eine Fehlermeldung ausgegeben werden, wenn Eingabe ungueltig*/
    } else {
      printf("\n");									/* korrekte Eingabe -> Programm laueft weiter: 2.Operand */
      printf(" Operand 2: "); 	 							/* Eingabe 2.Operand und Eingabetest*/
      if (scanf("%f", &op2) != 1) {
	printf("  Bitte das naechste Mal eine Zahl eingeben. Danke.\n");		/* Fehlermeldung wenn Operand 2 falsch */
      } else { 										/* korrekte Eingabe -> Programm laueft weiter: gewuenschte Operation ausfuehren  */
        printf("\n");
        switch(operator) {								/* Diese Fallunterscheidung soll die gewuenschte Operation: Summe, Differenz Produkt oder Division ausfuehren */
            case 0: 
	      printf(" Die Summe von %.3f und %.3f ist: %.3f \n\n", op1, op2, op1 + op2);/* Textausgabe Ergebnis Summe und Berechnung Summe */
	      break;
	    case 1:
	      printf(" Die Differenz von %.3f und %.3f ist: %.3f \n\n", op1, op2, op1 - op2);
	      break;
	    case 2:
	      printf(" Das Produkt von %.3f und %.3f ist: %.3f \n\n", op1, op2, op1 * op2);
	      break;
	    case 3:									/* zuerst Test ob 2.Operand Null ist->Division nicht erlaubt */
	      if ( op2 == 0 ) {
		printf("  Durch %f teilt man nicht! \n\n", op2);
	      } else {
		printf(" Der Quotient von %.3f und %.3f ist: %.3f \n\n", op1, op2, op1 / op2);
		break;
	      }
	    default:/* Textausgabe Fehlermeldung */
            printf(" Falsche Eingabe, bitte nochmal :).\n");
        }
      }
    }
  }

  return(0);

}
