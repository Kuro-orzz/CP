#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <bitset>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <list>    
#include <iomanip>
#include <climits>
#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define N 10000000
using namespace std;

bool nt[N+1];

void snt(){
    memset(nt, true, sizeof(nt));
    nt[0] = nt[1] = false;
    for(int i = 2; i <= sqrt(N); i++)
        if(nt[i]){
            int j = i * i;
            while(j <= N){
                nt[j] = false;
                j += i;
            }
        }
}

void solve(){
    int n, m; cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    snt();
    int f[n];
    f[0] = a[0];
    for(int i = 1; i < n; i++)
        f[i] = f[i-1] + a[i];
    while(m--){
        int x, y; cin >> x >> y;
        if(x == 1){
            int k = f[y-1];
            if(k > 0 && nt[k])
                cout << 1 << '\n';
            else 
                cout << 0 << '\n';
        }
        else{
            int k = f[y-1] - f[x-2];
            if(k > 0 && nt[k])
                cout << 1 << '\n';
            else 
                cout << 0 << '\n';
        }
    }
}

int main(){
    fast();
    //filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve(); 
    return 0;
}
