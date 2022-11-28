#include <iostream>
#include <string>
class time{
    private:
    int hrs,min;
    public:
    time(){
    }//default constructor for temp
    time(int h,int m){
        hrs=h;
        min=m;
    }
    void add_time(time t1,time t2){
        hrs = t1.get_hrs()+t2.get_hrs();
        min = t1.get_min()+t2.get_min();
        if(min>=60){
            hrs++;
            min-=60;
        }
    }
    int get_hrs(){
        return hrs;
    }
    int get_min(){
        return min;
    }
    void show_time(){
        std::cout<<"\nhours:"<<hrs;
        std::cout<<"\nminutes:"<<min;
    }
}t1(3,40),t2(4,50),t3;
int main(){
    std::cout<<"\nfor t1:";
    t1.show_time();
    std::cout<<"\n";
    std::cout<<"\nfor t2:";
    t2.show_time();
    t3.add_time(t1,t2);
    std::cout<<"\n";
    std::cout<<"\nfor t3:";
    t3.show_time();
    std::cout<<"\n";
    return 0;
}