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

bool visited[100001];
vector<int> adj[100001];
int a[100001];
vector<int> linked[100001];
int cnt = 0;

void dfs(int u){
	visited[u] = true;
	for(int i : adj[u])
		if(!visited[i])
			dfs(i);
	linked[cnt].push_back(a[u]);
}

void solve(){
	int n, m; cin >> n >> m;
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 1; i <= n; i++)
		if(!visited[i]){
			dfs(i);
			cnt++;
		}
	ll res = 0;
	for(int i = 0; i < cnt; i++)
		res += *min_element(linked[i].begin(), linked[i].end());
	cout << res;
}

int main(){
    //filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}