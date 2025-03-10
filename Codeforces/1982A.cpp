#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    if(a < b){
        if(c < d)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else{
        if(c > d)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}