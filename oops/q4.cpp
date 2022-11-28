#include<iostream>
#include<string>
class media
{
protected:
    std::string title;
    float price;
public:
    media(std::string s, float a)
    {
        title = s;
        price = a;
    }
    virtual void display(){}
};

class book : public media
{
    int pages;
public:
    book(std::string s, float a, int p) : media(s,a)
    {
        pages = p;
    }
    void display();
};

class tape : public media
{
    float time;
public:
    tape(std::string s, float a, float t):media(s,a)
    {
        time =t;
    }
    void display();
};

void book ::display()
{
    std::cout<<"\n Title:"<<title;
    std::cout<<"\n Pages:"<<pages;
    std::cout<<"\n Price:"<<price;
}
void tape ::display ()
{
    std::cout<<"\n Title:"<<title;
    std::cout<<"\n Play Time:"<<time<<"mins";
    std::cout<<"\n Price:"<<price;
}
int main()
{
std::string title;
float price, time;
int pages;
std::cout<<"\n Enter Book Details \n";
std::cout<<"\n Title:";
std::cin>>title;
std::cout<<"\n Price:";
std::cin>>price;
std::cout<<"\n Pages:";
std::cin>>pages;
book book1(title, price, pages);
std::cout<<"\n Enter Tape Details";
std::cout<<"\n Title:";
std::cin>>title;
std::cout<<"\n Price:";
std::cin>>price;
std::cout<<"\n Play Times:";
std::cin>>time;
tape tape1(title, price, time);
media* list[2];
list[0] = &book1;
list[1] = &tape1;
std::cout<<"\n Media Details";
std::cout<<"\n---------Book---------";
list[0]->display ();
std::cout<<"\n----------Tape----------";
list[1]->display ();
return 0;
}