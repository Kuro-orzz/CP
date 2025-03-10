// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("PRIME.INP", "r", stdin);
#define fileout() freopen("PRIME.OUT", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD (int)(1e9+7)
#define N (int)1e6
#define INF ((1ll<<31)-1)
#define bit(mask, i) ((mask>>i)&1)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 1000006

int a[maxn], cnt[maxn];

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 2; i <= sqrt(N); i++)
        if(cnt[i] == 0){
            int j = i;
            while(j <= N){
                cnt[j]++;
                j += i;
            }
        }
    pii ans = {0, a[0]};
    for(int i = 0; i < n; i++){
        if(ans.fi < cnt[a[i]])
            ans = {cnt[a[i]], a[i]};
    }
    cout << ans.se;
}

int main(){
    fast();
    filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}