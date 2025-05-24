#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e5+6;
int a[maxn];
ll pre[maxn], suf[maxn], bestPre[maxn], bestSuf[maxn];

void init(int n){
    pre[0] = suf[n+1] = 0;
    bestPre[0] = bestSuf[n+1] = -1e9;
    ll sum1 = 0, sum2 = 0;
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i-1] + a[i];
        sum1 = sum1 + a[i]; 
        bestPre[i] = max(bestPre[i-1], sum1);
        sum1 = max(sum1, 1ll*0);
    }
    for(int i = n; i >= 1; i--){
        suf[i] = suf[i+1] + a[i];
        sum2 = sum2 + a[i];
        bestSuf[i] = max(bestSuf[i+1], sum2);
        sum2 = max(sum2, 1ll*0);
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    init(n);
    ll ans = -1e18;
    ll best = -1e18;
    for(int i = 1; i < n; i++){
        best = max(best, -pre[i-1] + bestPre[i-1]);
        ans = max(ans, pre[i] + best + bestSuf[i+1]);
    }
    cout << ans;
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