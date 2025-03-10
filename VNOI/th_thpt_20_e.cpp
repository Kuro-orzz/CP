// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("CAU5.INP", "r", stdin);
#define fileout() freopen("CAU5.OUT", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD (int)(1e9+7)
#define N 1000000

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define fi first
#define se second

void solve(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    ll nhon = 0;
    ll vuong = 0;
    ll tu = 0;
    for(int i = 0; i < n-2; i++)
        for(int j = i+1; j < n-1; j++){
            if(a[i] + a[j] > a[j+1]){
                auto start = upper_bound(a+j+1, a+n, a[i]+a[j]-1);
                auto it = upper_bound(a+j+1, a+n, sqrt(a[i]*a[i]+a[j]*a[j]));
                bool kt = false;
                if(*(it-1) == sqrt(a[i]*a[i]+a[j]*a[j])){
                    vuong++;
                    kt = true;
                }
                tu += (start-a)-(it-a);
                if(!kt)
                    nhon += (it-a)-j-1;
                else
                    nhon += (it-a)-j-2;
            } 
        }
    cout << nhon << " " << vuong << " " << tu;
}

int main(){
    fast(); //cin.exceptions(cin.failbit);
    filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
