#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    bool v=false;
    bool i=false;
    bool k=false;
    bool a=false;
    vector<string> f;
    for(int j=0; j<n; j++){
        string x; cin >> x;
        f.push_back(x);
    }
    if(m<4){
        cout<< "NO"<<endl;
        return;
    }
    for(int j=0; j<m; j++){
        for(string x:f){
            bool kt=false;
            if(x[j] == 'v' && v==false){
                v=true;
                break;
            }
            else if(x[j] == 'i' && v==true && i==false){
                i=true;
                break;
            }
            else if(x[j] == 'k' && i==true && k==false){
                k=true;
                break;
            }
            else if(x[j] == 'a' && k==true && a==false){
                a=true;
                break;
            }
        }
    }
    if(a==true)
        cout<< "YES"<<endl;
    else
        cout<< "NO"<<endl;
}

int main(){
    //freopen("file.inp.c", "r", stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}