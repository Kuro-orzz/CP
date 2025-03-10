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
#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define ll long long
#define MOD 1000000007
#define N 1000000
using namespace std;

string arr[100];
int cnt = 0;
string a, b;

void down(){
	while(a[1] > b[1]){
		arr[cnt] = "D";
		a[1]--;
		cnt++;
	}
}

void up(){
	while(a[1] < b[1]){
		arr[cnt] = "U";
		a[1]++;
		cnt++;
	}
}

void left(){
	while(a[0] > b[0]){
		arr[cnt] = "L";
		a[0]--;
		cnt++;
	}
}

void right(){
	while(a[0] < b[0]){
		arr[cnt] = "R";
		a[0]++;
		cnt++;
	}
}

void left_up(){
	while(a[0] > b[0] && a[1] < b[1]){
		arr[cnt] = "LU";
		a[0]--;
		a[1]++;
		cnt++;
	}
}

void left_down(){
	while(a[0] > b[0] && a[1] > b[1]){
		arr[cnt] = "LD";
		a[0]--;
		a[1]--;
		cnt++;
	}
}

void right_up(){
	while(a[0] < b[0] && a[1] < b[1]){
		arr[cnt] = "RU";
		a[0]++;
		a[1]++;
		cnt++;
	}
}

void right_down(){
	while(a[0] < b[0] && a[1] > b[1]){
		arr[cnt] = "RD";
		a[0]++;
		a[1]--;
		cnt++;
	}
}

void solve(){
	cin >> a >> b;
	if(a[0] > b[0] && a[1] < b[1])
		left_up();
	if(a[0] > b[0] && a[1] > b[1])
		left_down();
	if(a[0] < b[0] && a[1] < b[1])
		right_up();
	if(a[0] < b[0] && a[1] > b[1])
		right_down();
	//cout << a << " " << b << endl;
	if(a[1] > b[1])
		down();
	if(a[1] < b[1])
		up();
	if(a[0] > b[0])
		left();
	if(a[0] < b[0])
		right();
	//cout << a << " " << b << endl;
	cout << cnt << endl;
	for(int i = cnt - 1; i >= 0; i--)
		cout << arr[i] << endl;
}

int main(){
    //filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}