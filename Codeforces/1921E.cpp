#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD (int)(1e9+7)
#define N 100000

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define fi first
#define se second

void solve(){
    int h, w; cin >> h >> w;
    int Xa, Ya; cin >> Xa >> Ya;
    int Xb, Yb; cin >> Xb >> Yb;
    if(Xa >= Xb){
        cout << "Draw" << '\n';
        return;
    }
    if(abs(Xa-Xb) % 2 == 1){
        if(abs(Ya-Yb) <= 1){
            cout << "Alice" << '\n';
            return;
        }
        if(Ya < Yb && Ya+abs(Xa-Xb)/2+1 < w){
            cout << "Draw" << '\n';
            return;
        }
        else if(Ya < Yb && Ya+abs(Xa-Xb)/2+1 >= w){
            cout << "Alice" << '\n';
            return;
        }
        if(Ya > Yb && Ya-abs(Xa-Xb)/2-1 > 1){
            cout << "Draw" << '\n';
            return;
        }
        else if(Ya > Yb && Ya-abs(Xa-Xb)/2-1 <= 1){
            cout << "Alice" << '\n';
            return;
        }
    }
    else{
        if(abs(Ya-Yb) == 0){
            cout << "Bob" << '\n';
            return;
        }
        if(Ya > Yb && Yb+abs(Xa-Xb)/2 < w){
            cout << "Draw" << '\n';
            return;
        }
        else if(Ya > Yb && Yb+abs(Xa-Xb)/2 >= w){
            cout << "Bob" << '\n';
            return;
        }
        if(Ya < Yb && Yb-abs(Xa-Xb)/2 > 1){
            cout << "Draw" << '\n';
            return;
        }
        else if(Ya < Yb && Yb-abs(Xa-Xb)/2 <= 1){
            cout << "Bob" << '\n';
            return;
        }
    }
}

int main(){
    fast(); //cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    filein(); fileout();
    #endif    
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
