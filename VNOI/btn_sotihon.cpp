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
#define FOR(i, x, n) for(int i = x; i < n; i++)
#define REP(i, x, n) for(int i = x; i <= n; i++)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 10006

int trau(int n, vector<int> &a){
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1) continue;
        ll sum = 1;
        for(int j = 2; j <= sqrt(a[i]); j++)
            if(a[i] % j == 0)
                sum += j + a[i]/j;
        if(sqrt(a[i]) == (int)(sqrt(a[i])))
            sum -= (int)sqrt(a[i]);
        if(sum > a[i])
            ans++;
    }
    return ans;
}

int sieve(int n, vector<int> &a){
    const int N = 5e6;
    vector<int> v(N+1, 1);
    v[0] = v[1] = 0;
    for(int i = 2; i*i <= N; i++){
        for(int j = i*i; j <= N; j+=i){
            v[j] += i;
            if(j/i != i)
                v[j] += j/i;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(v[a[i]] > a[i])
            ans++;
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(n <= 1e3)
        cout << trau(n, a);
    else
        cout << sieve(n, a);
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
