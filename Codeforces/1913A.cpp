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
#define N 100000
using namespace std;

bool check_merge(string s, string s1, string s2){
	int cnt1 = 0;
	int cnt2 = 0;
	for(int i = 0; i < (int)s.length(); i++)
		if(s[i] == s1[cnt1])
			cnt1++;
		else if(s[i] == s2[cnt2])
			cnt2++;
		else
			return false;
	if(cnt1 != (int)s1.length() || cnt2 != (int)s2.length())
		return false;
	return true;
}

void solve(){
    string s; cin >> s;
    vector<int> v;
    for(int i = 0; i < (int)s.length(); i++)
   		if(s[i] == '0')
   			v.push_back(0);
   		else
   			v.push_back(1);
   	for(int i = s.length()-1; i > 0; i--){
   		string s1 = s.substr(0, i);
   		string s2 = s.substr(i);
   		if(v[i] == 1 && stoi(s1) < stoi(s2)){
   			cout << s1 << " " << s2 << endl;
   			return;
   		}
   	}
   	cout << -1 << endl;
}

int main(){
    //filein(); fileout();
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}