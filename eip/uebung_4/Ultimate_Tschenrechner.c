/* Programm: Taschenrechner.c             September 2009  Version 2
 *  Ziel: Ist ja wohl klar :)                                       */

#include <stdio.h>
#include <stdlib.h>

/*Funktion um Hauptmenu anzuzeigen und Eingabeaufforderung*/
int zeige_hauptmenu()
{
  int auswahl;     /*Auswahl, die im Hauptmenu getroffen wurde*/

  /*fuehre die Eingabeaufforderung solange durch bis die Eingabe
    gueltig ist*/
  do
  {
    printf("  *********************************************\n");
    printf("  Hauptmenu\n");
    printf("  *********************************************\n");
    printf("  Bitte Option auswaehlen:\n");
    printf("  Neue Rechnung (0)\n  Weitere Berechnung (1)\n"
              "  Programm beenden (2)\n  Ihre Auswahl: ");
    /*Abbruch des Programms, bei ungueltigem Wertebereich,
      um Endlosschleife durch scanf zu verhindern */
    if (scanf("%d",&auswahl) == 0)
    {
      printf("  Bitte nur Zahlen eingeben.\n");
      printf("  Ungueltige Eingabe. Programm beendet.\n");
      exit(EXIT_FAILURE);  /*Abbruch des Programms, stdlib Funkt.*/
    }
    /*bei falscher Eingabe, aber 'gueltigem' Wertebereich
      -> Fehlermeldung*/
    else
    {
      if(!(auswahl == 0 || auswahl == 1 || auswahl == 2))
        printf("  Falsche Eingabe, bitte nochmal.\n");
    }
  } while(!(auswahl == 0 || auswahl == 1 || auswahl == 2));
  printf("  *********************************************\n");
  return(auswahl); /*Rueckgabe der Auswahl an die aufrufende
                     Funktion*/
}


/*Funktion um Operatormenu anzuzeigen und Eingabeaufforderung*/
int zeige_operatormenu()
{
  int opera;                /*Operator der gewaehlt wurde*/
  
    printf("  Bitte Operation auswaehlen:\n");
    printf("  Addition (0)\n  Subtraktion (1)\n  Multiplikation (2)\n  Division (3)\n"
              "  Ihre Auswahl: ");

    if ((scanf("%d",&opera) == 0) || (opera > 3))
    {
      printf("  Bitte nur gueltige Zahlen eingeben.\n");
      printf("  Ungueltige Eingabe. Programm beendet.\n");
      exit(EXIT_FAILURE);  /*Abbruch des Programms, stdlib Funkt.*/
    } else {
      printf("  *********************************************\n");
      return(opera);
    }
  
}
/*Funktion um Operanden einzulesen, Anzahl der Operanden wird durch
  die Variable n mitgezaehlt und auch angezeigt*/
float lies_operand(int n)
{
  float operand;      /*eingegebener Operand*/

  
  printf("%1d. Operanden eingeben: ", n);
  if ((scanf("%f",&operand) == 0))
    {
      printf("  Bitte nur gueltige Zahlen eingeben.\n");
      printf("  Ungueltige Eingabe. Programm beendet.\n");
      exit(EXIT_FAILURE);  /*Abbruch des Programms, stdlib Funkt.*/
    } else {
      printf("  *********************************************\n");
    }
  return(operand); 
}


/*Funktion zum Berechnen der einfachen arithmetischen Operationen.
 Als Parameter werden die beiden Operanden und der Operator uebergeben*/
float berechne(float oper1, float oper2, int op)
{
  float ergebnis;               /*Ergebnis der Berechnung*/
  if(op == 0) {
    ergebnis = oper1 + oper2;
  } else if(op == 1) {
    ergebnis = oper1 - oper2;
  } else if(op == 2) {
    ergebnis = oper1 * oper2;
  } else if(op == 3) {
    ergebnis = oper1 / oper2;
  } else {
    printf("  Bitte nur gueltige Zahlen eingeben.\n");
    printf("  Ungueltige Eingabe. Programm beendet.\n");
    exit(EXIT_FAILURE);
  }  /*Hier soll die Berechnung erfolgen*/
  return(ergebnis);   /*Rueckgabe des Ergebnis an die aufrufende                        Funktion*/
}


/*Hauptprogramm Taschenrechner*/
int main()
{
  int ausw, opera;     /*Variablen fuer die Auswahl in
                         Haupt- und Operatormenu*/
  float op1, op2, erg, zw_erg;  /*Variablen fuer Operanden, Ergebnis
                                  und Zwischenergebnis*/
  int zaehler = 1;          /*Zaehler der Operanden*/


  printf("  *********************************************\n");
  printf("  ************* Taschenrechner ****************\n");
  printf("  *********************************************\n\n");
  printf("  Erste Rechnung\n");
  printf("  *********************************************\n");

  ausw = 0;  /*Erste Rechnung soll ausgefuehrt werden*/

  /*Schleife wird solange ausgefuehrt bis das Programm verlassen wird*/
  while(1) 
  {
    switch(ausw) /*Auswahl des Hauptmenus*/
    {
      case 0:    /*Neue Berechnung*/
        opera = zeige_operatormenu();  /*Operator wird gelesen*/
	zaehler = 1;
        op1 = lies_operand(zaehler); /*1.Operand wird gelesen*/
        zw_erg = op1;   /*1.Operand wird in Zwischenergebnis abgelegt*/
        zaehler++;      /*Operand Zaehler um 1 erhoehen*/        
        op2 = lies_operand(zaehler);  /*2.Operand wird gelesen*/
        zaehler++;    /*Operand Zaehler wird wieder um 1 erhoeht*/

        break;
      case 1:   /*Weitere Berechnung mit dem Zwischenergebnis:
                  1.Operand ist Zwischenergebnis*/
        opera = zeige_operatormenu();
        op2 = lies_operand(zaehler);
        zaehler++;

        break;
      case 2:    /*Programm beenden*/
        printf("  Der Taschenrechner wird beendet.\n");
        printf("  *********************************************\n");
        return(0);
    }
    if(op2 == 0 && opera == 3) {/*Test Division durch 0*/
      printf("  Division durch 0 ist doch nicht erlaubt!\n");
    }
    else
    {
      erg = berechne(zw_erg,op2,opera); /*Berechnung des Ergebnisses*/
      printf("  Das Ergebnis dieser Rechnung ist: %.3f\n",erg);
      zw_erg = erg; /*Ergebnis wird zum Zwischenergebnis*/
    }

    ausw = zeige_hauptmenu(); /*Hauptmenu wird aufgerufen und Auswahl
                                wird zurueckgegeben*/

  }
return(0);
}
