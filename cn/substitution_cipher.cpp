#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

string encrypted(string s,int key){
    for(int i=0;i<s.size();i++){
    if(!isalpha(s[i]))
        continue;
    if(s[i]<=90 && s[i]>=65){
        if((s[i]+key)>90){
            s[i] = ((s[i]+key)%91) + 65;
        }
        else
            s[i]=s[i]+key;
        }
    else if(s[i]<=122 && s[i]>=97){
        if((s[i]+key)>122){
            s[i] = ((s[i]+key)%123) + 97;
        }
        else
            s[i]=s[i]+key;
        }
    }
    return s;
}
string decrypted(string s, int key){
    for(int i=0;i<s.size();i++){
    if(!isalpha(s[i]))
        continue;
    if(s[i]<=90 && s[i]>=65){
        if((s[i]-key)<65){
            s[i] = 91 - (65-(s[i]-key));
        }
        else
            s[i]=s[i]-key;
        }
    else if(s[i]<=122 && s[i]>=97){
        if((s[i]+key)<97){
            s[i] = 123 - (97 - (s[i]-key));
        }
        else
            s[i]=s[i]-key;
        }
    }
    return s;
    }
int main()
{
    string plain_text,enc,dec;
    int key;
    cout<<"\nenter plain text";
    getline(cin,plain_text);
    cout<<"enter key";
    cin>>key;
    enc = encrypted(plain_text,key);
    dec=decrypted(enc,key);
    cout<<"\nencrypted text is:"<<enc;
    cout<<"\ndecrypted text is:"<<dec;
    return 0;
}


