#ifndef CSurveillanceMesure_h
#define CSurveillanceMesure_h
#include "Arduino.h"

class CSurveillanceMesure
{
      public:
      
      CSurveillanceMesure(int valdefaut);
      bool mesurer();
      
      private:
      
        float tabMesures[10];
        int nbMesures;
        

};

#endif
