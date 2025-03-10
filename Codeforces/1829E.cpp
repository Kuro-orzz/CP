#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

int a[1001][1001];

ll dfs(int i, int j){
    ll sum=a[i][j];
    if(a[i][j])
        a[i][j]=0;
    else
        return 0;
    if(i-1>0 && a[i-1][j]>0)
        sum+=dfs(i-1,j);
    if(i+1<1001 && a[i+1][j]>0)
        sum+=dfs(i+1,j);
    if(j-1>0 && a[i][j-1]>0)
        sum+=dfs(i,j-1);
    if(j+1<1001 && a[i][j+1]>0)
        sum+=dfs(i,j+1);
    return sum;
}

void solve(){
    memset(a,0,sizeof(a));
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> a[i][j];
    ll max_val=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i][j]){
                ll x=dfs(i,j);
                if(x > max_val)
                    max_val = x;
            }
    cout << max_val <<endl;
}

int main(){
    //freopen("file.inp.c", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}