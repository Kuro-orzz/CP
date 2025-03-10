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
#define ll long long
#define MOD 1000000007
#define N 100000
using namespace std;

void solve(){
    int n; cin >> n;
    int a[100];
    int duong = 0;
    int am = 0;
    int zero = 0;
    int pos_am = 0;
    int pos_duong = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > 0){
            pos_duong = i;
            duong++;
        }
        else if(a[i] < 0){
            pos_am = i;
            am++;
        }
        else if(a[i] == 0)
            zero++;
    }
    if(zero > 0){
        cout << 0 << endl;
        return;
    }
    if(am > 0 && am % 2 == 1){
        cout << 0 << endl;
        return;
    }
    else if(am > 0 && am % 2 == 0){
        cout << 1 << endl;
        cout << pos_am+1 << " " << 0 << endl;
        return;
    }
    cout << 1 << endl;
    cout << pos_duong+1 << " " << 0 << endl;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    //filein(); fileout();
    int t; cin >> t;
    while(t--)
        solve(); 
    return 0;
}