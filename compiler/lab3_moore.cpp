#include<bits/stdc++.h>
using namespace std;
int main(){
    FILE *pfile,*pf;
    pfile = fopen("moore.txt","r");
    pf = fopen("moore.txt","r");
    int init,c,newline_cnt=0,numspace=0;
    vector<vector<int>> ipstates;
    vector<int> opstates;
    fscanf(pf,"%d",&init);
    while((c=fgetc(pfile))!=EOF){
        if(c==10){
        if(newline_cnt>0){
        vector<int> temp1;
        int temp2;
        for(int k=0;k<numspace;k++){
        int iptemp;
        fscanf(pf,"%d",&iptemp);
        temp1.push_back(iptemp);
        }
        fscanf(pf,"%d",&temp2);
        opstates.push_back(temp2);
        ipstates.push_back(temp1);
        temp1.clear();
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
            cout<<opstates[i]<<" ";
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
			cout<<opstates[currstate]<<" ";
            currstate=ipstates[currstate][inp];
        }
 
        if(i==ipsize-1){
            cout<<opstates[currstate]<<" ";
            break;
        }
    }
cout<<endl;
    }
    return 0;
}
