#include "arduino.h"

typedef class 
{
    public:
    CSurveillanceMesure(float valdefaut = 0);
    void affichemesures();



    private:
        float tabMesures[10];
        int nbMesures;
        void tritableau();

}CSurveillanceMesure;

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
