#include "arduino.h"

typedef class 
{
      private:
      
        float tabMesures[10];
        int nbMesures;
        void tritableau();

}CSurveillanceMesure;


void initialisermesures (CSurveillanceMesure *init)
{
  
  int i = 0; //compteur
  int valdefaut = -1;
    while (i<10)
    {
        (*init).tabMesures[i] = valdefaut; //on initialise le tableau de mesures avec la valeur par défaut
        i++;
    }
    (*init).nbMesures = 0; //on initialise le nombre de valeurs a 0
}
    //void affichemesures();
    //bool mesurer();



bool mesurer(CSurveillanceMesure *msr)
{
    int j = 1;
    

    if ((*msr).nbMesures == 10) //si le tableau est plein, il faut "supprimer" la premiere mesure du tableau et decaler les autres mesures
    {
        while (j<10) //on parcourt tout le tableau
            {
                (*msr).tabMesures[j-1] = (*msr).tabMesures[j]; //on remplace la case j-1 du tableau par la case j
                j++; //compteur boucle
            }
    (*msr).tabMesures[9] = analogRead(A0); //on range la mesure rentree par l'utilisateur dans la derniere case du tableau
    return true; //tout s'est bien passe
    //il est important de noter que l'on incremente plus notre nombre de mesures, le tableau etant deja plein
    }
    
    else //si le tableau n'est pas plein
    {
        (*msr).tabMesures[(*msr).nbMesures] = analogRead(A0); //on range la mesure dans le tableau
        (*msr).nbMesures = (*msr).nbMesures + 1; //on incremente le nombre de mesure
        return true; //tout s'est bien passe
    }
    return false; //quelque chose s'est mal deroule


}


void setup() {

                // Initialise la communication avec le PC
                 Serial.begin(9600);
             }

// Fonction loop(), appelée continuellement en boucle tant que la carte Arduino est alimentée
void loop() {
bool verif;
int test = 0;

if (x == 0)
{
CSurveillanceMesure mesure;
initialisermesures(&mesure);
x = 1;
}

verif = mesurer(&mesure);
while (verif==false)
     {
        serial.println("mesure echouee");
        verif = mesurer(&mesure);
     }
  
  // Envoi la mesure au PC pour affichage et attends 250ms
  Serial.println(valeur);
  delay(250);
}
