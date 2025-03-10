#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define FOR(i, x, n) for(int i = x; i < n; i++)
#define REP(i, x, n) for(int i = x; i <= n; i++)
#define MOD (int)(1e9+7)
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    int x, y; cin >> x >> y;
    if(y >= -1)
        cout << "YES\n";
    else   
        cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}