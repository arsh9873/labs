#include<bits/stdc++.h>
using namespace std;
int main(){
    FILE *pfile,*pf;
    pfile = fopen("dfa.txt","r");
    pf = fopen("dfa.txt","r");
    int init,c,newline_cnt=0,numspace=0;
    vector<int> finals;
    vector<vector<int>> states;
    fscanf(pf,"%d",&init);//scan initial 1
    while((c=fgetc(pfile))!=EOF){
        if(c==10){
        if(newline_cnt==1){//intial newline count was done and now finals newline is encountered
        for(int k=0;k<numspace+1;k++){
        int z;
        fscanf(pf,"%d",&z);//scanning nums properly using %d space + 1 times and a new file pointer
        finals.push_back(z);
        }
        }
        else if(newline_cnt>1){
        vector<int> temp;
        for(int k=0;k<numspace+1;k++){
        int z;
        fscanf(pf,"%d",&z);
        temp.push_back(z);
        }
        states.push_back(temp);
        temp.clear();
        }
            newline_cnt++;
            numspace=0;
        }
        if(c==32){
            numspace++;
        }
    }
    cout<<"initial\n";
    cout<<init<<endl;
    cout<<"finals\n";
    for(int i=0;i<finals.size();i++)
        cout<<finals[i]<<" ";
    cout<<endl;
    cout<<"states\n";
    for(int i=0;i<states.size();i++){
        for(int j=0;j<states[i].size();j++)
            cout<<states[i][j]<<" ";
        cout<<endl;
    }
    string ip;
    cout<<"\nenter your input:";
    cin>>ip;
    int currstate,ipsize=ip.size(),k=0;
    currstate=0;//at first currstate = intial state
    for(int i=0;i<ip.size();i++){
        int inp;
        inp=int(ip[i])-48;
        if(states[currstate][inp]==-1){
            cout<<"\nexecution failed as no transistion present from that point";
            break;
        }
        else{
            cout<<"\nq"<<currstate<<"->";
            currstate=states[currstate][inp];
            cout<<"q"<<currstate;
        }
        if(i==ip.size()-1){
            if(std::find(finals.begin(),finals.end(),currstate)!=finals.end()){
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
