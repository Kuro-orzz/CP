// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD (int)(1e9+7)
#define INF ((1ll<<31)-1)
#define bit(mask, i) ((mask>>i)&1)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 100006
#define MASK64(x) (1LL << (x))

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string x = "";
    for(char c : s)
        if(isdigit(c))
            x += c;
    n = x.size()-n;
    if(!n){
        cout << x;
        return;
    }
    stack<char> st;
    int i = 0;
    while(n && i < x.size()){
        while(!st.empty() && st.top() > x[i] && n){
            st.pop();
            n--;
        }
        st.push(x[i]);
        i++;
    }
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    ans += x.substr(i);
    cout << ans.substr(0, ans.size()-n);
}   

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    cin.exceptions(cin.failbit);
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