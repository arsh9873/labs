#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <math.h>
using namespace std;
string encrypted(string s,int key){
    string key_str= to_string(key);
    int key_len = key_str.size(),cnts=0,cnt=0;
    string temp_str;
    int new_order[key_len];
    string enc_matrix[4][key_len];
    for(int i=0;i<4;i++){
        for(int j=0;j<key_len;j++){
            if(cnts<s.size()){
                enc_matrix[i][j]=s[cnts];
                cnts++;
            }
            else{
                enc_matrix[i][j]='-';
            }            
        }
    }

    for(int i=0;i<key_len;i++){
        int div=pow(10,key_len-i-1);
        new_order[i]=key / div;
        key=key%div;
    }
    
    string temp[4][key_len];
    for(int i=0;i<4;i++)
        for(int j=0;j<key_len;j++)
            temp[i][j]=enc_matrix[i][new_order[j]];

    cout<<"initial encrypted matrix"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<key_len;j++){
            cout<<temp[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<key_len;i++){
        for(int j=0;j<4;j++)
            temp_str.append(temp[j][i]);
    }
    return temp_str;
}

string decrypted(string s,int key){
    string key_str= to_string(key);
    int key_len = key_str.size(),cnts=0,cnt=0;
    string temp_str;
    int used_order[key_len];
    string dec_matrix[4][key_len];
    for(int i=0;i<4;i++){
        for(int j=0;j<key_len;j++){
            
                dec_matrix[i][j]=s[i+cnt];
                cnt=cnt+4;
            }            
        cnt=0;    
        }
    

    cout<<"\ninitialy deccrypted matrix\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<key_len;j++){
            cout<<dec_matrix[i][j];
        }
        cout<<endl;
    }


    for(int i=0;i<key_len;i++){
        int div=pow(10,key_len-i-1);
        used_order[i]=key / div;
        key=key%div;
    }
    
    string temp[4][key_len];
    for(int i=0;i<4;i++)
        for(int j=0;j<key_len;j++)
            temp[i][used_order[j]]=dec_matrix[i][j];

    cout<<"\norder revised matrix\n"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<key_len;j++){
            cout<<temp[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<key_len;j++)
            temp_str.append(temp[i][j]);
    }
     return temp_str;
}

int main(){
    string plain_text,enc,dec;
    int key;
    cout<<"\nenter plain text";
    getline(cin,plain_text);
    cout<<"enter key";
    cin>>key;
    enc = encrypted(plain_text,key);
    dec = decrypted(enc,key);
    cout<<"\nencrypted text is:"<<enc;
    dec.erase(dec.find_first_of("-"));
    cout<<"\ndecrypted text is:"<<dec;
    
    return 0;
}