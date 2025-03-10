// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 10006

void solve(){
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> tmp = {x, y, z};
    sort(all(tmp));
    x = tmp[0]; y = tmp[1]; z = tmp[2];
    ll all_way = 0;
    ll t;
    for(int i = 1; i <= x; i++){
        if(i > k)
            break;
        if(k % i == 0){
            int a1 = k/i;
            for(int j = 1; j <= y; j++){
                if(j > a1)
                    break;
                if(a1%j == 0){
                    int a2 = a1/j;
                    for(int l = 1; l <= z; l++){
                        if(l > a2)
                            break;
                        if(a2 == l){
                            vi v = {i, j, l};
                            sort(all(v));
                            all_way = max(all_way, (x-v[0]+1)*(y-v[1]+1)*(z-v[2]+1));
                        }
                    }
                }
            }
        }
    }
    cout << all_way << '\n';
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif    
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}