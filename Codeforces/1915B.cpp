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
#define N 1000000
using namespace std;

void solve(){
    string a, b, c; cin >> a >> b >> c;
    map<char, int> mp;
    for(int i = 0; i < 3; i++){
        mp[a[i]]++;
        mp[b[i]]++;
        mp[c[i]]++;
    }
    if(mp['A'] != 3)
        cout << "A" << endl;
    else if(mp['B'] != 3)
        cout << "B" << endl;
    else if(mp['C'] != 3)
        cout << "C" << endl;
}

int main(){
    fast();
    //filein(); fileout();
    int t; cin >> t;
    while(t--)
        solve(); 
    return 0;
}