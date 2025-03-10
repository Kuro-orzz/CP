#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string s; cin>>s;
    string x="";
    while(s!=""){
        if(s[0]=='.' && s.length()>0){
            x+='0';
            s=s.substr(1,s.length());
            //continue;
        }
        if(s[0]=='-' && s[1]=='.' && s.length()>1){
            x+='1';
            s=s.substr(2,s.length());
            //continue;
        }
        if(s[0]=='-' && s[1]=='-' && s.length()>1){
            x+='2';
            s=s.substr(2,s.length());
            //continue;
        }
    }
    cout<<x;
    return 0;
}