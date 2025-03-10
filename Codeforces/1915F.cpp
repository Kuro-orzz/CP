#include "bits/stdc++.h"
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define N 1000000
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
using namespace std;


void solve(){
    int n; cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a+n);
    ordered_set s;
    ll res = 0;
    for(int i = 0; i < n; i++){
        res += s.size()-s.order_of_key(a[i].second);
        s.insert(a[i].second);
    }
    cout << res << '\n';
}

int main(){
    fast();
    //filein(); fileout();
    int t; cin >> t;
    while(t--)
        solve(); 
    return 0;
}