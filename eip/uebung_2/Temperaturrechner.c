/* Temperaturrechner */

#include <stdio.h>

int main() {
  float t_eing;										/* Eingabe */
  float t_ausg;										/* Ausgabe */
  int t_einh;										/* Einheit */
  printf("\n\n  Willkommen zu Ihrem persoenlichen Temperaturrechner!\n");			/* Begruessung */
  printf("  Temperatur: ");								/* Temperatureingabe */
  scanf("%f", &t_eing);									/* Dateneingabe */
  printf("  Welche Einheit moechten Sie umrechnen? (Celsius = 0/Fahrenheit = 1): ");	/* Einheit? */
  scanf("%d", &t_einh);
  printf("\n");
  if(t_einh == 0) {
    t_ausg = 9 * t_eing / 5 + 32;							/* Cel -> Fah */
    printf("  %.2f Grad Celsius entsprechen %.2f Grad Fahrenheit.\n\n", t_eing, t_ausg);    
  } else if(t_einh == 1) {
    t_ausg = (t_eing-32) * 5 / 9;
    printf("  %.2f Grad Fahrenheit entsprechen %.2f Grad Celsius.\n\n", t_eing, t_ausg);
  } else {
    printf("  Incorrecte Eingabe. Bitte waehlen Sie 0 (Celsius) oder 1 (Fahrenheit).\n\n");/* Fehlermeldung */
  }
  return(0);
}
