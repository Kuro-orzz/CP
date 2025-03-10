#include <iostream>
using namespace std;

int main(){
    string s; cin>>s;
    //cout<<'a'-'A'=32;
    int lower=0;
    int upper=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='a' && s[i]<='z')
            lower++;
        else upper++;
    }

    for(int i=0; i<s.length(); i++){
        if(lower>=upper && s[i]>='A' && s[i]<='Z')
            s[i]=(char)(s[i]+32);
        if(upper>lower && s[i]>='a' && s[i]<='z')
            s[i]=(char)(s[i]-32);
    }
    cout<<s;
    return 0;
}