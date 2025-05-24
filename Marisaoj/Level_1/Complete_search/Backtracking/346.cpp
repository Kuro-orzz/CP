#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vector<ll> a;
bool ans = false;

void backtrack(int idx, ll sum) {
    if(sum == 0){
        ans = true;
        return;
    }
    if(sum < 0) return;
    for(int i = max(0, idx); i < a.size(); i++){
        if(i == idx) continue;
        backtrack(i, sum-a[i]);
    }
}

void solve() {
    ll n, k; cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    backtrack(-1, k);
    cout << (ans == 1 ? "YES" : "NO");
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