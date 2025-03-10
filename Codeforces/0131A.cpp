#include <iostream>
using namespace std;

void solve(){
    string s; cin>>s;
    bool kt=false;
    for(int i=1; i<s.length(); i++)
        if(s[i]==tolower(s[i]))
            kt=true;
    if(kt)
        cout<<s;
    else{
        if(s[0]==toupper(s[0]))
            s[0]=tolower(s[0]);
        else
            s[0]=toupper(s[0]);
        for(int i=1; i<s.length(); i++)
            s[i]=tolower(s[i]);
        cout<<s;
    }
}

int main(){
    solve();
    return 0;
}