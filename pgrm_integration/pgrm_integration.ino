#include "arduino.h"

typedef class 
{
    public:
    CSurveillanceMesure(float valdefaut = 0);
    void affichemesures();
    bool mesurer();


    private:
        float tabMesures[10];
        int nbMesures;
        void tritableau();

}CSurveillanceMesure;



CSurveillanceMesure::CSurveillanceMesure(float valdefaut)
{
  int i = 0; //compteur
    while (i<10)
    {
        this->tabMesures[i] = valdefaut; //on initialise le tableau de mesures avec la valeur par défaut
        i++;
    }
    this->nbMesures = 0; //on initialise le nombre de valeurs a 0
}

bool CSurveillanceMesure::mesurer()
{
    int j = 1;
    

    if (this->nbMesures == 10) //si le tableau est plein, il faut "supprimer" la premiere mesure du tableau et decaler les autres mesures
    {
        while (j<10) //on parcourt tout le tableau
            {
                this->tabMesures[j-1] = this->tabMesures[j]; //on remplace la case j-1 du tableau par la case j
                j++; //compteur boucle
            }
    this->tabMesures[9] = analogRead(A0); //on range la mesure rentree par l'utilisateur dans la derniere case du tableau
    system("cls");
    return true; //tout s'est bien passe
    //il est important de noter que l'on incremente plus notre nombre de mesures, le tableau etant deja plein
    }
    else //si le tableau n'est pas plein
    {
        this->tabMesures[this->nbMesures] = analogRead(A0); //on range la mesure dans le tableau
        this->nbMesures = this->nbMesures + 1; //on incremente le nombre de mesure
        system("cls");
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
CSurveillanceMesure mesure(-1);

verif = mesure.mesurer();
while (verif==false)
     {
        cout << "mesure echouee" << endl;
        verif = mesure.mesurer();
     }
  
  // Envoi la mesure au PC pour affichage et attends 250ms
  Serial.println(valeur);
  delay(250);
}
