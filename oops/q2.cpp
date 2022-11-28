#include <iostream>
#include <string>
class basic{
    protected:
        std::string name,adress;
    public:
        void show_data(int ch){
            if(ch==1)
                std::cout<<"\ndata of student";
            else
                std::cout<<"\ndata of staff";
        std::cout<<"\nname:"<<name;
        std::cout<<"\adress:"<<adress;
        }
};
class STUDENT:public basic{
    private:
        float percentage;
    public:
        STUDENT(){
            std::cout<<"\nenter name adress and percentage of the student:";
            std::cin>>basic::name>>basic::adress>>percentage;
        }
        void show_data(){
            basic::show_data(1);
            std::cout<<"\npercentage:"<<percentage;
        }
};
class STAFF:public basic{
    private:
        int salary;
    public:
        STAFF(){
            std::cout<<"\nenter name adress and salary of the staff:";
            std::cin>>basic::name>>basic::adress>>salary;
        }
        void show_data(){
            basic::show_data(2);
            std::cout<<"\nsalary:"<<salary;
        }
};
int main(){
    STUDENT st;
    STAFF sta;
    st.show_data();
    std::cout<<"\n";
    sta.show_data();
    std::cout<<"\n";
    return 0;
}