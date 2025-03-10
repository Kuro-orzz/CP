// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define N 100000

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

void solve(){
    int n; cin >> n;
    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+n, greater<int>());
    int ans = 0;
    int tmp = 0;
    while(tmp <= sum / 2){
        tmp += a[ans];
        ans++;
    }
    cout << ans;
}

int main(){
    fast();
    ifstream file("test.inp");
    if(file.is_open()){filein(); fileout();}    
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}