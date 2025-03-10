// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("chusont.inp", "r", stdin);
#define fileout() freopen("chusont.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define N 10000000

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

bool check(int n){
    while(n){
        int i = n % 10;
        if(i!=2 && i!=3 && i!= 5 && i!=7)
            return false;
        n /= 10;
    }
    return true;
}

void solve(){
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(check(x))
            ans++;
    }
    cout << ans;
}

int main(){
    fast();
    filein(); fileout();    
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}
