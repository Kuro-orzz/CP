// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
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
    double a[4];
    for(int i = 0; i < 4; i++) cin >> a[i];
    int cnt[3]{};
    for(int i = 0; i < 4; i++){
        if(a[i] < 0) cnt[0]++;
        else if(a[i] == 0) cnt[1]++;
        else if(a[i] > 0) cnt[2]++;
    }
    if(cnt[1]){
        cout << "0\n";
        return;
    }
    if(cnt[0]%2)
        cout << "-1\n";
    else
        cout << "1\n";
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    // #ifndef ONLINE_JUDGE
    freopen("TBS.INP", "r", stdin);
    freopen("TBS.OUT", "w", stdout);
    // #endif
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
