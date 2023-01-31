#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ifstream myfile("dfa.txt");
    string temp,init,finals,states;
    int counter=0,stcount=0;
    while(getline(myfile,temp)){
        if(counter==0){
            init+=temp;
            
        }
        else if(counter==1){
            finals+=temp;
            
        }
        else if(counter>1){
            states+=temp;
            states.push_back('/');
            stcount++;
        }
        counter++;
        temp.clear();
    }
    // cout<<"\nnum of states:"<<stcount<<endl;
    // cout<<"init:"<<init<<endl;
    // cout<<"finals:"<<finals<<endl;
    // cout<<"states:"<<states;
    int dfa[stcount][2];//rows=num of states,col=num of inputs
    int temp2=stcount,i=0,j=0,r=0,c=0;
    while(temp2>0){
        while(states[i]!='/'){
            if(states[i]!=' '){
                if(states[i]=='-'){
                    dfa[r][c++]=-1;
                    i++;//skipped in case of -
                }
                else
                    dfa[r][c++]=int(states[i])-48;
                }
            i++;
        }
        c=0;
        i++;
        temp2--;
        r++;
    }
    vector<int> finalstates;
    for(i=0;i<finals.size();i++){
        if(finals[i]!=' '){
            finalstates.push_back(int(finals[i])-48);
        }
    }
    cout<<"\nstate table is:"<<endl;
    for(i=0;i<stcount;i++){
        for(j=0;j<2;j++){
            cout<<dfa[i][j]<<" ";
        }
        cout<<endl;
    }
    string ip;
    cout<<"\nenter your input:";
    cin>>ip;
    int currstate,ipsize=ip.size(),k=0;
    currstate=0;//at first currstate = intial state
    for(i=0;i<ip.size();i++){
        int inp;
        inp=int(ip[i])-48;
        if(dfa[currstate][inp]==-1){
            cout<<"\nexecution failed as no transistion present from that point";
            break;
        }
        else{
            cout<<"\nq"<<currstate<<"->";
            currstate=dfa[currstate][inp];
            cout<<"q"<<currstate;
        }
        if(i==ip.size()-1){
            if(std::find(finalstates.begin(),finalstates.end(),currstate)!=finalstates.end()){
                cout<<"\nexecution successful";
            }
            else{
                cout<<"\nexecution failed as the last state is not a final state";
            }
            break;
        }
    }
    return 0;
}
