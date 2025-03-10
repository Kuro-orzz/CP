// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("CHUNGCU.inp", "r", stdin);
#define fileout() freopen("CHUNGCU.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define N 1000000

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define fi first
#define se second

void solve(){
    string s; cin >> s;
    int W_chan = 0;
    int W_le = 0; 
    for(int i = 0; i < s.length(); i++){
        if(i%2==0 && s[i]=='W')
            W_chan++;
        else if(i%2==1 && s[i]=='W')
            W_le++;
    }
    if(W_chan > W_le){
        cout << (s.length()-1)/2+1-W_chan+W_le << '\n';
        for(int i = 0; i < s.length(); i++)
            if(i%2==0 && s[i]=='B')
                cout << i+1 << " ";
            else if(i%2==1 && s[i]=='W')
                cout << i+1 << " "; 
    }
    else{
        cout << s.length()/2-W_le+W_chan << '\n';
        for(int i = 0; i < s.length(); i++)
            if(i%2==1 && s[i]=='B')
                cout << i+1 << " ";
            else if(i%2==0 && s[i]=='W')
                cout << i+1 << " "; 
    }
}

int main(){
    fast();
    filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve();
     cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
