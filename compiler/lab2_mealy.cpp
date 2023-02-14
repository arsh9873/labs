#include<bits/stdc++.h>
using namespace std;
int main(){
    FILE *pfile,*pf;
    pfile = fopen("mealy.txt","r");
    pf = fopen("mealy.txt","r");
    int init,c,newline_cnt=0,numspace=0;
    vector<vector<int>> ipstates,opstates;
    fscanf(pf,"%d",&init);
    while((c=fgetc(pfile))!=EOF){
        if(c==10){
        if(newline_cnt>0){
        vector<int> temp1,temp2;
        for(int k=0;k<(numspace+1)/2;k++){
        int iptemp,optemp;
        fscanf(pf,"%d %d",&iptemp,&optemp);
        temp1.push_back(iptemp);
        temp2.push_back(optemp);
        }
        ipstates.push_back(temp1);
        opstates.push_back(temp2);
        temp1.clear();
        temp2.clear();
        }
            newline_cnt++;
            numspace=0;
        }
        if(c==32){
            numspace++;
        }
    }
    cout<<"\nipsteates:\n";
    for(int i=0;i<ipstates.size();i++){
        for(int j=0;j<ipstates[i].size();j++)
            cout<<ipstates[i][j]<<" ";
        cout<<endl;
    }
    cout<<"\nopsteates:\n";
    for(int i=0;i<opstates.size();i++){
        for(int j=0;j<opstates[i].size();j++)
            cout<<opstates[i][j]<<" ";
        cout<<endl;
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
    for(int i=0;i<ipsize;i++){
        int inp;
        inp=int(userinput[i])-48;
        if(ipstates[currstate][inp]==-1){
            break;
        }
        else{
            if(opstates[currstate][inp]==0){
                cout<<"A";
            }
            else if(opstates[currstate][inp]==1){
                cout<<"B";
            }
            currstate=ipstates[currstate][inp];
        }
 
        if(i==ipsize-1){
            break;
        }
    }
cout<<endl;
    }
return 0;
}
