#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    int res=0;
    while(t--){
        string s; cin>>s;
        if(s[0]=='+' && s[1]=='+')
            res++;
        else if(s[1]=='+' && s[2]=='+')
            res++;
        else if(s[0]=='-' && s[1]=='-')
            res--;
        else
            res--;
    }
    cout<<res;
    return 0;
}