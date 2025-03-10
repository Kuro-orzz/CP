#include <iostream>
#include <map>
using namespace std;

void solve(){
    multimap<int,int> mp;
    int str; cin>>str;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int x,y; cin>>x>>y;
        mp.insert({x,y});
    }
    int cnt=0;
    for(auto it:mp){
        if(str > it.first){
            cnt++;
            str+=it.second;
        }
        else{
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";
}

int main(){
    solve();
    return 0;
}