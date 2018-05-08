#include <SoftwareSerial.h>
#include "Arduino.h"
#include "CSurveillanceMesure.h"

CSurveillanceMesure::CSurveillanceMesure(float valdef)
{
  
  int i = 0; //compteur
    while (i<10)
    {
        tabMesures[i] = valdef; //on initialise le tableau de mesures avec la valeur par défaut
        i++;
    }
    nbMesures = 0; //on initialise le nombre de valeurs a 0
}


bool CSurveillanceMesure::mesurer()
{
    int j = 1;
    
    if (nbMesures == 10) //si le tableau est plein, il faut "supprimer" la premiere mesure du tableau et decaler les autres mesures
    {
        while (j<10) //on parcourt tout le tableau
            {
                tabMesures[j-1] = tabMesures[j]; //on remplace la case j-1 du tableau par la case j
                j++; //compteur boucle
            }
    tabMesures[9] = analogRead(A0); //on range la mesure rentree par l'utilisateur dans la derniere case du tableau
    return true; //tout s'est bien passe
    //il est important de noter que l'on incremente plus notre nombre de mesures, le tableau etant deja plein
    }
    
    else //si le tableau n'est pas plein
    {
        tabMesures[nbMesures] = analogRead(A0); //on range la mesure dans le tableau
        nbMesures = nbMesures + 1; //on incremente le nombre de mesure
        return true; //tout s'est bien passe
    }
    return false; //quelque chose s'est mal deroule


}
