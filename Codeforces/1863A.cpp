#include <iostream>
using namespace std;

void solve(){
    int n, a, q;
    cin >> n >> a >> q;
    string s; cin >> s;
    if(n <= a){
        cout<< "YES"<<endl;
        return;
    }
    else if(n > a+q){
        cout<< "NO"<<endl;
        return;
    }
    int online=a;
    int duong=0;
    int am=0;
    int pos=0;
    while(s[pos]=='-')
        pos++;
    online-=pos;
    bool check=false;
    for(int i=pos; i<q; i++){
        if(s[i]=='+'){
            duong++;
            online++;
        }
        else{
            am++;
            online--;
        }
        if(a+duong-am-pos >= n){
            cout<< "YES"<<endl;
            return;
        }
        if(a+duong>=n)
            check=true;
    }
    //cout<<online<<" "<<duong<<" "<<am;
    if(check)
        cout<< "MAYBE"<<endl;
    else
        cout<< "NO"<<endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}