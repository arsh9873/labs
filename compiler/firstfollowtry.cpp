//even first is working only for some cases
#include<bits/stdc++.h>
using namespace std;

void disp(vector<vector<char>> table){
    for(int i=0;i<table.size();i++){
        for(int j=0;j<table[i].size();j++){
            if(j==1)
                cout<<"->";
            cout<<table[i][j];
        }
        cout<<endl;
    }
}
void expi(vector<vector<char>> table,map<char,vector<int>> lhs,set<char> &ans,int row){//just start with s0
    if(table[row][1]=='#'){
        ans.insert('#');
        return;
    }
    else if(islower(table[row][1])){
        ans.insert(table[row][1]);
        return;
    }
    else{
        char ch;
        ch=table[row][1];
        for(int i=0;i<lhs[ch].size();i++){
            expi(table,lhs,ans,lhs[ch][i]);
        }
    }
}

int main(){
vector<vector<char>> table;
map<char,vector<int>> lhs,rhs;//appearences on lhs and rhs in the main table
set<char> cap_letters,sm_letters;
map<char,set<char>> first,follow;
    ifstream pf("test.txt");
    string str;
    while(getline(pf,str)){
        int dash=0;
        vector<char> temp1;
        for(int i=0;i<str.size();i++){
            if(str[i]!='-'){
                temp1.push_back(str[i]);
            }
        }
        table.push_back(temp1);
    }
    

    for(int i=0;i<table.size();i++){
        cap_letters.insert(table[i][0]);
        for(int j=1;j<table[i].size();j++){
            if(islower(table[i][j]))
                sm_letters.insert(table[i][j]);
        }
    }
    
    set<char>::iterator itr; 
    for(itr=cap_letters.begin();itr!=cap_letters.end();++itr){
        for(int i=0;i<table.size();i++){
            if(table[i][0]==*itr)
                lhs[*itr].push_back(i);
        }
        for(int i=0;i<table.size();i++){
            for(int j=1;j<table[i].size();j++){
                if(table[i][j]==*itr)
                    rhs[*itr].push_back(i);
            }
        }
    }
    set<char>::iterator itr1;
    for(itr1=sm_letters.begin();itr1!=sm_letters.end();++itr1){
        first[*itr1].insert(*itr1);
    }
    for(int i=0;i<table.size();i++){
        if(table[i][1]=='#')
            first[table[i][0]].insert('#');
    }
    map<char,vector<int>>::iterator itr2;
    for(itr2=lhs.begin();itr2!=lhs.end();++itr2){
        set<char> ans2;
        for(int i=0;i<itr2->second.size();i++){
            expi(table,lhs,ans2,itr2->second[i]);
        }
        set<char>::iterator itr3;
        for(itr3=ans2.begin();itr3!=ans2.end();++itr3){
            first[itr2->first].insert(*itr3);
        }
    }
    map<char,set<char>>::iterator itr4;
    for(itr4=first.begin();itr4!=first.end();++itr4){
        set<char>::iterator itr5;
        cout<<itr4->first<<":";
        for(itr5=itr4->second.begin();itr5!=itr4->second.end();itr5++){
            cout<<*itr5<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
