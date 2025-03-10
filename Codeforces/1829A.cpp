#include <iostream>
using namespace std;

int main(){
    //freopen("test0.inp.cpp","r",stdin);
    int t; cin>>t;
    while(t--){
        string s1="codeforces";
        string s2; cin>>s2;
        int cnt=0;
        for(int i=0; i<s1.length(); i++)
            if(s1[i]!=s2[i]) cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}