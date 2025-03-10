// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define INF ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
#define all(x) (x).begin(),(x).end()
#define modulo 998244353

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 1000006
#define tuple64 tuple<ll, int, int>

bool nt[maxn+1];

void sieve(){
    memset(nt, true, sizeof(nt));
    nt[0] = nt[1] = false;
    for(int i = 2; i*i <= maxn; i++)
        if(nt[i])
            for(int j = i*i; j <= maxn; j+=i)
                nt[j] = false;
}

void solve(){
    int t; cin >> t;
    sieve();
    while(t--){
        ll n; cin >> n;
        if(sqrt(n) == (int)(sqrt(n)) && nt[(int)sqrt(n)])
            cout << "1\n";
        else
            cout << "0\n";
    }
    
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    // #ifndef ONLINE_JUDGE
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    // #endif    
    // int t; cin >> t;
    // while(t--)
        solve();
    // cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
