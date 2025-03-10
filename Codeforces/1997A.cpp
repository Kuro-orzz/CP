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
    if(s.size() == 1){
        if(s == "a")
            cout << "ab\n";
        else
            cout << s+"a" << '\n';
        return;
    }
    int pos = -1;
    char c;
    for(int i = 0; i < s.size()-1; i++)
        if(s[i] == s[i+1]){
            pos = i;
            if(s[i] != 'a' && s[i+1] != 'a')
                c = 'a';
            else if(s[i] != 'b' && s[i+1] != 'b')
                c = 'b';
            else
                c = 'c';
            break;
        }
    string ans;
    if(pos != -1)
        ans = s.substr(0, pos+1)+c+s.substr(pos+1);
    else
        ans = s+(s[s.size()-1]!='a' ? 'a' : 'b');
    cout << ans << '\n';
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