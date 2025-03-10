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

int n, m;
bool visited[1001][1001];
int adj[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int cnt;

void dfs(int a, int b){
	visited[a][b] = true;
	for(int i = 0; i < 4; i++){
		int x = a + dx[i];
		int y = b + dy[i];
		if(x >= 0 && y >= 0 && x < n && y < m && !visited[x][y])
			dfs(x, y);		
	}
	cnt += adj[a][b];
}

void solve(){
	cin >> n >> m;
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin >> adj[i][j];
			if(adj[i][j] == 0)
				visited[i][j] = true;
		}
	int max = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!visited[i][j]){
				cnt = 0;
				dfs(i, j);
				if(cnt > max)
					max = cnt;
			}
	cout << max << endl;
}

int main(){
    //filein(); fileout();
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}