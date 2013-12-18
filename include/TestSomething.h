#ifndef TestSomething_HH
#define TestSomething_HH

#include "TNamed.h"

class TestSomething : public TNamed {
   public :
      TestSomething(const char * n = "" , const char * t = "") : TNamed(n,t) {

      }
      ~TestSomething(){}
      
      ClassDef(TestSomething,1)
};


#endif 


