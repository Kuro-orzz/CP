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

ll cal(int n, vector<ll> &v){
    stack<int> st;
    vector<ll> ans(n, 0);
    for(int i = 0; i < n; i++){
        if(st.empty())
            st.push(i);
        else{
            while(!st.empty() && v[st.top()] > v[i]){
                int j = st.top();
                st.pop();
                ans[j] += (i-j)*v[j];
            }
            st.push(i);
        }
    }
    int sz1 = st.top()+1;
    while(!st.empty()){
        int t = st.top(); st.pop();
        ans[t] += (sz1-t)*v[t];
    }
    for(int i = n-1; i >= 0; i--){
        if(st.empty())
            st.push(i);
        else{
            while(!st.empty() && v[st.top()] > v[i]){
                int j = st.top();
                st.pop();
                ans[j] += (j-i-1)*v[j];
            }
            st.push(i);
        }
    }
    int sz2 = st.top()-1;
    while(!st.empty()){
        int t = st.top(); st.pop();
        ans[t] += (t-sz2-1)*v[t];
    }
    ll res = 0;
    for(int i = 0; i < n; i++)
        res = max(res, ans[i]);
    return res;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<ll> v(m, 0);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            if(a[i][j] == 1)
                v[j]++;
            else
                v[j] = 0;
        ans = max(ans, cal(m, v));
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
