#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> v(m);
    for(int i = 0; i < m; i++)
        cin >> v[i];
    string c; cin >> c;
    sort(v.begin(), v.end());
    sort(c.begin(), c.end());
    set<int> st;
    for(auto x : v)
        st.insert(x);
    int cnt = 0;
    for(int i : st){
        s[i-1] = c[cnt];
        cnt++;
    }
    cout << s << '\n';
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}