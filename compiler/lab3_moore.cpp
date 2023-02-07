#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ifstream myfile("moore.txt");
    string temp,init,states,output;
    int counter=0,stcount=0;
    while(getline(myfile,temp)){
        if(counter==0){
            init+=temp;
        }
        else{
            states+=temp;
            states.push_back('/');
            stcount++;
        }
        counter++;
        temp.clear();
    }
    cout<<"\nnum of states:"<<stcount<<endl;
    cout<<"init:"<<init<<endl;
    cout<<"states:"<<states;
    int k=0,i=0,j=0;
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
        if(k<2){
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
        else if(k==2){
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
    cout<<"\ninput states:"<<ipstates;
    cout<<"\noutput states:"<<opstates;
    int temp2=stcount;
    int ip[stcount][2],op[stcount];//rows= num of states, col = num of inputs
    int r1=0,c1=0;
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
    temp2=stcount;
    while(temp2>0){
    if(opstates[i]!='/'){
        if(opstates[i]==' '){
            i++;
        }
        else{
            if(opstates[i]=='-'){
                op[r1++]=-1;
                i++;
            }
            else{
            op[r1++]=int(opstates[i])-48;
            i++;
            }
        }
    }
    else if(opstates[i]=='/'){
        i++;
        temp2--;
    }
    }
    cout<<"\nip table:"<<endl;
    for(i=0;i<stcount;i++){
		for(j=0;j<2;j++)
			cout<<ip[i][j]<<" ";
		cout<<endl;
	}
	cout<<"\nop table:"<<endl;
    for(i=0;i<stcount;i++){
		cout<<op[i]<<" ";
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
    for(i=0;i<ipsize;i++){
        int inp;
        inp=int(userinput[i])-48;
        if(ip[currstate][inp]==-1){
            break;
        }
        else{
			cout<<op[currstate]<<" ";
            currstate=ip[currstate][inp];
        }
 
        if(i==ipsize-1){
            cout<<op[currstate]<<" ";
            break;
        }
    }
cout<<endl;
    }
    return 0;
}

