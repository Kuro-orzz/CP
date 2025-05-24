#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1506;
int n, q;
vector<ll> a, pre;

void solve(){
    cin >> n >> q;
    a.resize(n+1);
    pre.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i-1]+a[i];
    }
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int x; cin >> x;
            a.push_back(x);
            pre.push_back(pre.back()+x);
        }
        else if(type == 2){
            a.pop_back();
            pre.pop_back();
        }
        else{
            int l, r; cin >> l >> r;
            cout << pre[r]-pre[l-1] << '\n';
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