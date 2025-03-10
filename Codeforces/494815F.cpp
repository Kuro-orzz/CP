// #define _CRT_SECURE_NO_WARNINGS
// #include <bits/stdc++.h>
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <vector>
#include <sstream>
#include <set>
#include <map>   
#include <iomanip>
#include <climits>
using namespace std;

#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define N 10000000

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << '\n';
#else
#define debug(x...)
#endif

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

bool a[N+6];

void sieve(){
    memset(a, true, sizeof a);
    a[0]=a[1]=false;
    for(int i = 2; i <= sqrt(N); i++)
        if(a[i]){
            int j = i * i;
            while(j <= N){
                a[j] = false;
                j += i;
            }
        }
}

void solve(){
    sieve();
    int n; cin >> n;
    ll res = 0;
    for(int i = 2; i <= n; i++)
        if(a[i])
            res += i;
    cout << res;
}

int main(){
    fast(); //cin.exceptions(cin.failbit);
    //filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}