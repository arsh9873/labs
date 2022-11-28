#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class rupee{
    private:
        int val;
    public:
        rupee(){
        }
        rupee(int val){
            this->val = val;
        }
        int get_val(){
            return val;
        }
};
class dollar{
    private:
        int val;
    public:
        dollar(){
        }
        dollar(int val){
            this->val = val;
        }
        dollar(rupee obj){
            this->val = obj.get_val()/80;
        }
        operator rupee(){
            rupee temp(val * 80);
            return temp;
        }
        int get_val(){
            return val;
        }
};
int main(){
    int tempr,tempd;
    cout<<"\nenter rupees";
    cin>>tempr;
    cout<<"\nenter dollar";
    cin>>tempd;
    dollar d1,d2(tempd);
    rupee r1(tempr),r2;
    d1=r1;
    r2=d2;
    cout<<"\nrupee to dollar:"<<d1.get_val();
    cout<<endl;
    cout<<"\ndollar to rupee:"<<r2.get_val();
}