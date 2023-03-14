#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<vector <int> > > table;//3d array to store input
    FILE *pf,*pf2;
    pf=fopen("test.txt","r");
    pf2=fopen("test.txt","r");
	int x=5;
    int init,newline_cnt=0,space_cnt=0,c;
    vector<int> finals;
    while((c=fgetc(pf))!=EOF){
        if(c==10){//newline encountered
            if(newline_cnt==0){//first newline
                fscanf(pf2,"%d",&init);
            }
            else if(newline_cnt==1){//first line was over now 2nd newline enc
               int temp;
			   for(int i=0;i<=space_cnt;i++){
					fscanf(pf2,"%d",&temp);
					finals.push_back(temp);
			   }
            }
			else if(newline_cnt>1){//3rd line onwards
				// cout<<newline_cnt<<"-";
				int x=0,temp;
				fscanf(pf2,"%d",&temp);
				vector<vector<int>> temp1;
				vector<int> temp2;
				temp2.push_back(temp);
				FILE *pf3;
				pf3=pf2;
				while(x!=10){
					x=fgetc(pf3);
					// cout<<x<<" ";
					if(x==44){
						fscanf(pf2,"%d",&temp);
						temp2.push_back(temp);
					}
					else if(x==32){
						temp1.push_back(temp2);
						temp2.clear();
						fscanf(pf2,"%d",&temp);
						temp2.push_back(temp);
					}
					else if(x==10)
						if(temp2.size()!=0)
							temp1.push_back(temp2);
				}
				table.push_back(temp1);
				}			
			newline_cnt++;
			// cout<<newline_cnt<<"-";
			space_cnt=0;
			}
        if(c==32){//space encountered
            space_cnt++;
        }
    }
    //parsing done
    vector<vector<int>> nfas;
    vector<set<int>> freq;//will have one to one mapping with nfas 
    for(int i=0;i<table.size();i++)
					{
						for(int j=0;j<table[i].size();j++)
						{
						if(table[i][j].size()>1){
                            int flag=0;
                            set<int> temp1;
                                for(int k=0;k<table[i][j].size();k++){
                                    temp1.insert(table[i][j][k]);
                                }
                            if(freq.size()==0)
                                flag=0;
                            else{
                                for(int z=0;z<freq.size();z++)
                                {
                                   if(temp1==freq[z])
                                        flag=1; 
                                    if(flag==1)
                                        continue;//could use break but i didnt want to break all loops
                                }
                            }
                            if(flag==0){
                            nfas.push_back(table[i][j]);//has the ones which point to more than 1
                            freq.push_back(temp1);
                            }
                        }
                        }
                    }
                    
    int num_ip=table[0].size();//number of inputs
    for(int i=0;i<nfas.size();i++){
        vector<vector<int>> temp2;
            for(int ip=0;ip<num_ip;ip++){
                vector<int> temp1;
                for(int j=0;j<nfas[i].size();j++){
                    for(int z=0;z<table[nfas[i][j]][ip].size();z++){
                        if(table[nfas[i][j]][ip].size()!=1 or table[nfas[i][j]][ip][z]!=-1)
                            temp1.push_back(table[nfas[i][j]][ip][z]);
                    }
                }
                if(temp1.size()==0)
                    temp1.push_back(-1);
                
                if(temp1.size()>1){
                    set<int> temp3;//temp1 has the new to be inserted
                                for(int k=0;k<temp1.size();k++){
                                    temp3.insert(temp1[k]);
                                }
                    int flag=0;
                    for(int z=0;z<freq.size();z++)
                                {
                                   if(temp3==freq[z])
                                        flag=1; 
                                    if(flag==1)
                                        continue;//could use break but i didnt want to break all loops
                                }
                    if(flag==0){
                        nfas.push_back(temp1);
                        freq.push_back(temp3);
                    }

                    vector<int> newtemp1;//to make 1202 as 012
                    set<int>::iterator itr;
                    for(itr=temp3.begin();itr!=temp3.end();itr++){
                        newtemp1.push_back(*itr);
                    }
                    temp1=newtemp1;
                }

                temp2.push_back(temp1);
            }
            table.push_back(temp2);
    }
    
    cout<<"\nnew dfa is:\n";
    for(int i=0;i<table.size();i++)
					{
						for(int j=0;j<table[i].size();j++)
						{
                            int final_flag=0;
							for(int k=0;k<table[i][j].size();k++){
								cout<<table[i][j][k];
                                for(int z=0;z<finals.size();z++)
                                    if(table[i][j][k]==finals[z])
                                        final_flag=1;
							}
                            if(final_flag==1)
                            cout<<"*";
						cout<<"          ";
						}
						cout<<endl;
						}
    return 0;
}
