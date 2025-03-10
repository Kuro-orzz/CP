#include <iostream>
using namespace std;

int main(){
    string s; cin>>s;
    string x="";
    for(int i=0; i<s.length(); i++){
        s[i]=tolower(s[i]);
        switch(s[i]){
            case 'a': case 'o': case 'y':
            case 'e': case 'u': case 'i':
                s[i]='.';break;
            default:
                x+=s[i];
        }
    }
    for(int i=0; i<x.length(); i++){
        cout<<'.'<<x[i];
    }
    return 0;
}