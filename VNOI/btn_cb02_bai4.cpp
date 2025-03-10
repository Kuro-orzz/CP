// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("chupanh.inp", "r", stdin);
#define fileout() freopen("chupanh.out", "w", stdout);
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

void solve(){
    int n, m; cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    set<int> st;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        st.insert(x);
    }
    int ans = 0;
    int Max = 0;
    int pos = 0;
    for(int i = 0; i < n; i++){
        if(st.find(a[i]) != st.end())
            ans++;
        else
            ans = 0;
        if(ans > Max)
            pos = i;
        Max = max(Max, ans);
    }
    cout << Max << '\n';
    cout << pos-Max+2 << " " << pos+1;
}

int main(){
    fast();
    filein(); fileout();    
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}
