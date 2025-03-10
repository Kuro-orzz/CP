// #define _CRT_SECURE_NO_WARNINGS
// #include <bits/stdc++.h>
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update>;
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
#define N 1000000

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

void solve(){
    int n, k; cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int res = 2023;
    for(int i = 0; i < n; i++){
        if(res % a[i] != 0){
            cout << "NO" << endl;
            return;
        }
        else
            res /= a[i];
    }
    cout << "YES" << endl;
    cout << res << " ";
    for(int i = 0; i < k-1; i++)
        cout << 1 << " ";
    cout << endl;
}

int main(){
    fast(); cin.exceptions(cin.failbit);
    //if("test.inp"){filein(); fileout();}
    int t; cin >> t;
    while(t--)
        solve(); 
    return 0;
}