#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    int n; cin >> n;
    vector<ll> a(n+1);
    a[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++)
            cout << a[j] << " ";
        cout << '\n';
        vector<ll> b = a;
        for(int j = 1; j <= i; j++)
            b[j] += a[j-1];
        b[i+1] = 1;
        a.swap(b);
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}