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
					cout<<x<<" ";
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
					// for(int i=0;i<table.size();i++)
					// {
					// 	for(int j=0;j<table[i].size();j++)
					// 	{
					// 		for(int k=0;k<table[i][j].size();k++){
					// 			cout<<table[i][j][k]<<" ";
					// 		}
					// 	cout<<"-";
					// 	}
					// 	cout<<endl;
					// 	}
				}			
			newline_cnt++;
			// cout<<newline_cnt<<"-";
			space_cnt=0;
			}
        if(c==32){//space encountered
            space_cnt++;
        }
    }
    return 0;
}