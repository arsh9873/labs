#include <iostream>
class Base
{
    public:
    virtual ~Base() 
    {
        std::cout << "Base Destructor\n"; 
    }
};

class Derived:public Base
{
    public:
    ~Derived() 
    { 
        std::cout<< "Derived Destructor\n"; 
    }
}; 

int main()
{
    Base* b = new Derived;    
    delete b;
}
