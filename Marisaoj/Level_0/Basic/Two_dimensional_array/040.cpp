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
    vector<vi> v(101, vi(101, 0));
    for(int i = 0; i < n; i++){
        pii a, b;
        cin >> a.fi >> a.se >> b.fi >> b.se;
        for(int j = a.fi; j <= b.fi; j++)
            for(int k = a.se; k <= b.se; k++)
                v[j][k]++;
    }
    int ans = 0;
    for(int i = 0; i < 101; i++)
        for(int j = 0; j < 101; j++)
            if(v[i][j]) ans++;
    cout << ans;
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