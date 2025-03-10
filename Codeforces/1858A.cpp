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

#define mp make_pair
#define pb push_back
#define f first
#define s second

using namespace std;

void solve(){
    int a, b, c; cin >> a >> b >> c;
    if(a + (c+1)/2 > b + c/2)
        cout <<  "First" << endl;
    else
        cout << "Second" << endl; 
}

int main(){
    fast();
    cin.exceptions(cin.failbit);
    ifstream file("test.inp");
    if(file){
        filein(); fileout();
    }
    int t; cin >> t;
    while(t--)
        solve(); 
    return 0;
}