// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
#define all(x) (x).begin(),(x).end()
#define modulo 20071409

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 1000006
#define tuple64 tuple<ll, int, int>

int a[maxn];

void solve(){
    int n; cin >> n;
    int bit[32];
    memset(bit, 0, sizeof(bit));
    for(int i = 0; i < n; i++){
        cin >> a[i];
        bitset<32> bin(a[i]);
        for(int j = 0; j < 32; j++)
            if(bin[j] == 1)
                bit[j]++;
    }
    int ans = 0;
    for(int i = 0; i < 32; i++)
        ans = max(ans, bit[i]);
    cout << ans;
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
