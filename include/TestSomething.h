#ifndef TestSomething_HH
#define TestSomething_HH

#include <iostream>
#include <vector>
#include <algorithm>
#include "TNamed.h"
#include "TF1.h"

class TestSomething : public TNamed {
   public :
      TestSomething(const char * n = "" , const char * t = "") : TNamed(n,t) {

      }
      ~TestSomething(){}

      void TestLambdas(){
         std::vector<int> vec;
         vec.push_back( 1 );
         vec.push_back( 2 );
         for (int& i : vec )
         {
            i++; // increments the value in the vector
         }
         for (int i : vec )
         {
            // show that the values are updated
            std::cout << i << std::endl;
         }
         //int norm = 33; 
         std::for_each(vec.begin(), vec.end(), [](int i) { std::cout << i << "^2 = " << i*i << std::endl; /*norm=i*i*norm;*/ });
         //auto l = [](double* xs, double *ps) { return xs[0]*xs[0]; };
         //TF1 * f = new TF1("f", l, 0, 100, 0);
         //f->Draw();

         //std::cout << norm << std::endl;
      }

      
      ClassDef(TestSomething,1)
};


#endif 


