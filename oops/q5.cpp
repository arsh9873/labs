#include<iostream>
#include<string>
class accountbook{
    private:
        int accnum[5];
        std::string name[5];
    public:
        void get_data(){
            for(int i=0;i<5;i++){
                std::cout<<"\nenter accnumber and name for user "<<i+1<<":";
                std::cin>>accnum[i]>>name[i];
            }
        }
        std::string& operator[](int num){
            for(int i=0;i<4;i++){
                if(num == accnum[i])
                    return name[i];
            }
        }
        int& operator[](std::string s){
            for(int i=0;i<4;i++){
                if(s == name[i])
                    return accnum[i];
            }
        }   
};

int main(){
accountbook a;
a.get_data();
std::string name,namer;
int num,numr;
std::cout<<"\nenter name to search:";
std::cin>>name;
numr = a[name];
std::cout<<"\nperson with that name has number:"<<numr;
std::cout<<"\nenter number to search:";
std::cin>>num;
namer = a[num];
std::cout<<"\nperson with that number has name:"<<namer;
return 0;
}