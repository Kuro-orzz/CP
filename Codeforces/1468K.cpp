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

void solve(){
    string s; cin >> s;
    vector<pii> cal;
    pii cur = {0, 0};
    FOR(i, 0, s.size()){
        if(s[i] == 'L') cur.fi--;
        else if(s[i] == 'R') cur.fi++;
        else if(s[i] == 'D') cur.se--;
        else if(s[i] == 'U') cur.se++;
        cal.push_back(cur);
    }
    FOR(i, 0, cal.size()){
        cur = {0, 0};
        FOR(j, 0, s.size()){
            if(s[j] == 'L' && make_pair(cur.fi-1, cur.se) != cal[i]) cur.fi--;
            else if(s[j] == 'R' && make_pair(cur.fi+1, cur.se) != cal[i]) cur.fi++;
            else if(s[j] == 'D' && make_pair(cur.fi, cur.se-1) != cal[i]) cur.se--;
            else if(s[j] == 'U' && make_pair(cur.fi, cur.se+1) != cal[i]) cur.se++;
        }
        if(cur == make_pair(0, 0)){
            cout << cal[i].fi << " " << cal[i].se << '\n';
            return;
        }
    }
    cout << "0 0\n";
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