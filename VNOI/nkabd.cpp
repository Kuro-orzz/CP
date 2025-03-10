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
#define pb push_back
#define fi first
#define se second

int prime[N + 1];
void Prime(){
    for(int i = 0; i < N; i++)
        prime[i] = 1;
    prime[1] = 0;
    for(int i = 2; i <= N; i++){
        int j = i + i;
        while(j <= N){
            prime[j] += i;
            j += i;
        }
    }
}

void solve(){
    int l, r; cin >> l >> r;
    int cnt = 0;
    Prime();
    for(int i = l; i <= r; i++){
        if(prime[i] > i)
            cnt++;
            //cout << i << " " << prime[i] << '\n';
    }
    cout << cnt;
}

int main(){
    fast(); //cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    filein(); fileout();
    #endif    
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
