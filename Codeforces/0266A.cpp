#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    string s; cin>>s;
    int cnt_remove=0;
    char tmp=s[0];
    for(int i=1; i<s.length(); i++){
        if(tmp==s[i]) cnt_remove++;
        else tmp=s[i];
    }
    cout<<cnt_remove;
    return 0;
}