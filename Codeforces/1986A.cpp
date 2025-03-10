#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    int v[3];
    for(int i = 0; i < 3; i++){
        cin >> v[i];
    }
    sort(v, v+3);
    cout << v[2]-v[0] << '\n';
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}