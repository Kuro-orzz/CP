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
    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(m));
    // int x = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    pii cur{0, 0};
    auto isValid = [&](pii u){
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    };
    cout << a[0][0] << " ";
    while(cur != make_pair(n-1, m-1)){
        while(isValid(make_pair(cur.fi-1, cur.se+1))){
            cout << a[cur.fi-1][cur.se+1] << " ";
            cur.fi--; cur.se++;
        } 
        if(cur.se+1 < m){
            cout << a[cur.fi][cur.se+1] << " ";
            cur.se++;
        }
        else if(cur.fi+1 < n){
            cout << a[cur.fi+1][cur.se] << " ";
            cur.fi++;
        }
        while(isValid(make_pair(cur.fi+1, cur.se-1))){
            cout << a[cur.fi+1][cur.se-1] << " ";
            cur.fi++; cur.se--;
        }
        if(cur.fi+1 < n){
            cout << a[cur.fi+1][cur.se] << " ";
            cur.fi++;
        }
        else if(cur.se+1 < m){
            cout << a[cur.fi][cur.se+1] << " ";
            cur.se++;
        }
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