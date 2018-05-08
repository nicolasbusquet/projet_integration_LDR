#include <SoftwareSerial.h>
#include "Arduino.h"
#include "CSurveillanceMesure.h"

void setup() {

                // Initialise la communication avec le PC
                 Serial.begin(9600);
                 
             }

// Fonction loop(), appelée continuellement en boucle tant que la carte Arduino est alimentée
void loop() {
bool verif;
int test = 0;
int x = 0;

if (x == 0)
{
CSurveillanceMesure mesure(1.11);
x = 1;
}

verif = mesure.mesurer();
while (verif==false)
     {
        serial.println("mesure echouee");
        verif = mesure.mesurer();
     }
  
  // Envoi la mesure au PC pour affichage et attends 250ms
  //Serial.println(valeur);
  delay(250);
}
