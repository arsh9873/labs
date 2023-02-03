#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ifstream myfile("mealy.txt");
    string temp,init,states;
    int counter=0,stcount=0;
    while(getline(myfile,temp)){
        if(counter==0){
            init+=temp;
            
        }
        else if(counter>0){
            states+=temp;
            states.push_back('/');
            stcount++;
        }
        counter++;
        temp.clear();
    }
    int temp2=stcount,i=0,j=0,k=0;
    string ipstates,opstates;
    while(i<states.size()){
        if(states[i]==' '){
            i++;
            continue;
        }
        else if(states[i]=='/'){
            ipstates.push_back('/');
            opstates.push_back('/');
            i++;
            k=0;
            continue;
        }
        else{
        if(k==0 || k==2){
            if(states[i]=='-'){
            ipstates.push_back('-');
            ipstates.push_back(' ');    
            i++;//skipped when -
            k++;
            }
            else{
            ipstates.push_back(states[i]);
            ipstates.push_back(' ');
            k++;
            }
        }
        else if(k==1 || k==3){
            if(states[i]=='-'){
            opstates.push_back('-');
            opstates.push_back(' ');    
            i++;//skipped when -
            k++;
            }
            else{
            opstates.push_back(states[i]);
            opstates.push_back(' ');
            k++;
            }
        }
    }
        i++;
    }
    temp2=stcount;
    int ip[stcount][2],op[stcount][2];//rows= num of states, col = num of inputs
    int r1=0,c1=0,r2=0,c2=0;
    i=0;
    while(temp2>0){
    if(ipstates[i]!='/'){
        if(ipstates[i]==' '){
            i++;
        }
        else{
            if(ipstates[i]=='-'){
                ip[r1][c1++]=-1;
                i++;
            }
            else{
            ip[r1][c1++]=int(ipstates[i])-48;
            i++;
            }
        }
    }
    else if(ipstates[i]=='/'){
        r1++;
        c1=0;
        i++;
        temp2--;
    }
    }
 
    i=0;
    r1=0;
    c1 =0;
    temp2=stcount;
    while(temp2>0){
    if(opstates[i]!='/'){
        if(opstates[i]==' '){
            i++;
        }
        else{
            if(opstates[i]=='-'){
                op[r1][c1++]=-1;
                i++;
            }
            else{
            op[r1][c1++]=int(opstates[i])-48;
            i++;
            }
        }
    }
    else if(opstates[i]=='/'){
        r1++;
        c1=0;
        i++;
        temp2--;
    }
    }
    while(1){
    string userinput;
    cout<<"\nenter your input:";
    cin>>userinput;
    string nullip="null";
    if(userinput==nullip){
        cout<<"null";
        exit(0);
    }
    int currstate,ipsize=userinput.size();
    currstate=0;//at first currstate = intial state
    for(i=0;i<ipsize;i++){
        int inp;
        inp=int(userinput[i])-48;
        if(ip[currstate][inp]==-1){
            break;
        }
        else{
            if(op[currstate][inp]==0){
                cout<<"A";
            }
            else if(op[currstate][inp]==1){
                cout<<"B";
            }
            currstate=ip[currstate][inp];
        }
 
        if(i==ipsize-1){
            break;
        }
    }
cout<<endl;
    }
    return 0;
}
