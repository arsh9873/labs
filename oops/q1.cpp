#include <iostream>
#include <string>
class STUDENT{
    private:
        std::string name;
        int enrollid,marks;
    public:
        static int count;
        STUDENT(){
            std::cout<<"\nenter name enroll id and marks for student "<<++count<<":";
            std::cin>>name>>enrollid>>marks;
        }
        void show_data(){
            std::cout<<"\ndata for student "<<++count;
            std::cout<<"\nname:"<<name;
            std::cout<<"\enroll id:"<<enrollid;
            std::cout<<"\nmarks:"<<marks;
        }
};
int STUDENT::count = 0;
int main(){
    STUDENT s[3];
    std::cout<<"\ndata for all the students:";
    STUDENT::count = 0;
    for(int i=0;i<3;i++)
        s[i].show_data();
    return 0;
}