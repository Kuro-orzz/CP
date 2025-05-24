#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vector<int> a, vis;
int n, k;

void backtrack(int idx) {
    if(a.size() == k){
        for(int x : a) cout << x << " ";
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        a.push_back(i);
        vis[i] = 1;
        backtrack(i);
        a.pop_back();
        vis[i] = 0;
    }
}

void solve() {
    cin >> n >> k;
    vis.resize(n+1, 0);
    backtrack(0);
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