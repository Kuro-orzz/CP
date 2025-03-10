#include <iostream>
using namespace std;

bool split(int n,int m){
    if(n%3!=0)
        return false;
    if(n/3==m || n/3*2==m)
        return true;
    if(split(n/3,m))
        return true;
    if(split(n/3*2,m))
        return true;
    return false;
}

void solve(){
    int n, m;
    cin >> n >> m;
    if(m==n){
        cout<<"YES"<<endl;
        return;
    }
    if(n<m){
        cout<< "NO"<<endl;
        return;
    }
    if(split(n,m)){
        cout<< "YES"<<endl;
        return;
    }
    cout<< "NO"<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}