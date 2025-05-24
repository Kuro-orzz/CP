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
    vector<vi> a(n, vi(m, 0));
    int cnt = 1;
    pii cur{0, -1};
    while(cnt <= n*m){
        while(cur.se+1 < m && !a[cur.fi][cur.se+1]){
            a[cur.fi][cur.se+1] = cnt;
            cur.se++;
            cnt++;
        }
        while(cur.fi+1 < n && !a[cur.fi+1][cur.se]){
            a[cur.fi+1][cur.se] = cnt;
            cur.fi++;
            cnt++;
        }
        while(cur.se-1 >= 0 && !a[cur.fi][cur.se-1]){
            a[cur.fi][cur.se-1] = cnt;
            cur.se--;
            cnt++;
        }
        while(cur.fi-1 >= 0 && !a[cur.fi-1][cur.se]){
            a[cur.fi-1][cur.se] = cnt;
            cur.fi--;
            cnt++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << '\n';
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