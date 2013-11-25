 /* Programm: Zahlenraten.c  */
#include <stdio.h>
#include <math.h>

void fehlermeldung() {
  printf(" ERRORRR!\n");
}

void zuGross(vtipp) {
  printf(" Dein letzter Tipp war %d und das war zu GROSS." 
    " ES HERRSCHT ZU WENIG KONZENTRON\n", vtipp);
}

void zuKlein(vtipp) {
  printf(" Dein letzter Tipp war %d und das war zu KLEIN." 
    " ES HERRSCHT ZU WENIG KONZENTRON\n", vtipp);
}


int main()
{ const int MAX_ZAHL = 100;       /* Ratebereich 1 - MAX_ZAHL */
  int z;                         /* zu erratende Zahl */
  int tipp, vtipp;               /* aktuell/vorher getippte Zahl */
  int n;                         /* Anzahl Tippversuche */
  int Int1;
  int Int2;
  int Loesr[3];
  int gr_kl;
  int weider = 1;
  
  

  printf(" >> Huhu, rate mal meine Zahl, sie liegt zwischen 1 und %d!\n",
      MAX_ZAHL); 
  tipp= -1; n= 1;

while(weider == 1) { 
  printf("Na, dann rate mal, das ist dein %dter Versuch: ", n);
  if(!scanf("%d", &tipp)) {
    fehlermeldung();
  } else if(n == 1) {
    Int1 = MAX_ZAHL - tipp;						/* kleine Eingabe */
    Int2 = MAX_ZAHL - Int1;
    if(Int1 > Int2) {
      Loesr[0] = Int1 + 1;
      Loesr[1] = MAX_ZAHL;
      gr_kl = 1;
      vtipp = tipp;
      printf(" Das war zu klein!\n");
      printf(" Loesungsintervall von %d bis %d\n", Loesr[0], Loesr[1]);
    } else if(Int2 > Int1) {						/* grosse Eingabe */
      Loesr[0] = 1;
      Loesr[1] = Int2 - 1;
      gr_kl = 0;
      vtipp = tipp;
      printf(" Das war zu gross!\n");
      printf(" Loesungsintervall von %d bis %d\n", Loesr[0], Loesr[1]);      
    } else if(Int1 == Int2) {
      Loesr[0] = 51;
      Loesr[1] = 100;
      gr_kl = 1;
      vtipp = tipp;
      printf(" Das war zu klein!\n");
      printf(" Loesungsintervall von %d bis %d\n", Loesr[0], Loesr[1]);
    }
    n++;
  } else if((n > 1) && (Loesr[0] != Loesr[1])) {
    if(gr_kl == 0 && tipp > vtipp) {
      zuGross(vtipp);
    } else if(gr_kl == 1 && tipp < vtipp) {
      zuKlein(vtipp);
    } else {
      Int1 = Loesr[1] - tipp;
      Int2 = tipp - Loesr[0];
      if((Int1 > Int2) || (Int1 == Int2)) {							/* zu kleine Eingabe */
	Loesr[0] = tipp + 1;
	gr_kl = 1;
	vtipp = tipp;
	printf(" Das war zu klein!\n");
	printf(" Loesungsintervall von %d bis %d\n", Loesr[0], Loesr[1]);
      } else if(Int1 < Int2) {						/* zu grosse Eingabe */
	Loesr[1] = tipp - 1;
	gr_kl = 0;
	vtipp = tipp;
	printf(" Das war zu gross!\n");
	printf(" Loesungsintervall von %d bis %d\n", Loesr[0], Loesr[1]);
      }
    }
    n++;
   } else if(tipp == Loesr[0] && tipp == Loesr[1]) {
      if( n > 6 ) {
	printf("Ok, richtig, aber schlappe Leistung!\n");
      } else if( n > 1 ) {
	printf("Ok, richtig, gut geraten!\n");
      }
      weider = 0;
   } else if(tipp <= 0) {
     weider = 0;
   }
}
      
      
      
// while( tipp != z && tipp != 0 )     /* pro Rateversuch eine Wiederholung */
//  { vtipp = tipp; n++;                /* naechster Rateversuch */
//    printf("Na, dann rate mal, das ist dein %dter Versuch: ", n);
//    scanf("%d", &tipp);
//    if( tipp > 0 && tipp < z )
//    { if( vtipp > 0 && vtipp < z && tipp < vtipp )
//        printf("Dein letzter Tipp war %d und das war"
//            " zu KLEIN.\n", vtipp);
//      else printf("Leider nicht, etwas zu klein!\n");
//    }
//    if( tipp > z )
//    { if( vtipp > 0 && vtipp > z && tipp > vtipp )
//        printf("Dein letzter Tipp war %d und das war"
//            " zu GROSS.\n", vtipp);
//      else printf("Leider nicht, etwas zu gross!\n");
//    }
//    if( tipp != z && n == 5 )
//      printf("Du kannst ja 0 eintippen, dann hab ich gewonnen!\n");
//  }                          /* ENDE DER WHILE-SCHLEIFE */
//  if( tipp == 0 ) printf("Looser!\n");
//  else if( n > 6 ) printf("Ok, richtig, aber schlappe Leistung!\n");
//  else if( n > 1 ) printf("Ok, richtig, gut geraten!\n");
//  else printf("Beim ersten Versuch richtig, DU HAST MIR IN DEN SPEICHER GEGUCKT!\n");
  
  return(0);
} 

