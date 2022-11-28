#include<iostream>
class car  
{
public:
    void start()
    {
        std::cout<<"Started the car"<<"\n";
    }
};
 
class mercedes:public car  
{
public:
    void upshift()
    {
        std::cout<<"mercedes upshift."<<"\n";
    }
};
 
int main()
{
    
    mercedes m;
    car *p=NULL;
    p=&m;
    p->start();
    return 0;
}