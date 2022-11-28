#include<iostream>
class B {
   public:
      virtual void s() = 0; // Pure Virtual Function
};

class D:public B {
   public:
      void s() {
         std::cout << "Virtual Function in Derived class";
      }
};

int main() {
   B *b;
   D dobj;
   b = &dobj;
   std::cout<<"\nthe function called is:\n";
   b->s();
}