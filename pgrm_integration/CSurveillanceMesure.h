#ifndef CSurveillanceMesure_h
#define CSurveillanceMesure_h
#include "Arduino.h"

typedef class 
{
      public:
      
      CSurveillanceMesure(float valdefaut);
      bool mesurer();
      
      private:
      
        float tabMesures[10];
        int nbMesures;
        

}CSurveillanceMesure;

#endif
