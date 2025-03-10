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

ll ucln(int a, int b){
    if(b == 0)
        return a;
    else
        return ucln(b, a%b);
}

void solve(){
    ll a, b; cin >> a >> b;
    if(a == 1 || b == 1){
        cout << 1ll*a*b*a*b << endl;
        return;
    }
    ll tmp = ucln(a, b);
    if(tmp == a || tmp == b){
        cout << 1ll*max(a, b)*max(a, b)/min(a, b) << endl;
        return;
    }
    a /= tmp;
    b /= tmp;
    cout << 1ll*a*b*tmp << endl;
}

int main(){
    fast(); cin.exceptions(cin.failbit);
    //if("test.inp"){filein(); fileout();}
    int t; cin >> t;
    while(t--)
        solve(); 
    return 0;
}