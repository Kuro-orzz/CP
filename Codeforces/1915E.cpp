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

#define mp make_pair
#define pb push_back
#define f first
#define s second

using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i%2)
            a[i] *= -1;
    }
    map<ll, int> mp;
    mp[0] = 0;
    ll cur = 0;
    for(int i = 1; i < n+1; i++){
        cur += a[i-1];
        if(mp.count(cur)){
            cout << "YES" << endl;
            return;
        }
        mp[cur] = i;
    }
    cout << "NO" << endl;
}

int main(){
    fast();
    ifstream file("test.inp");
    if(file){
        filein(); fileout();
    }
    int t; cin >> t;
    while(t--)
        solve(); 
    return 0;
}