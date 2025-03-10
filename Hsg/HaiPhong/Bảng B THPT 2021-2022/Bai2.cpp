#include <iostream>
#include <cstring>
#include <cmath>
#define N 10000000
using namespace std;
bool nt[N+1];

void snt(){
    memset(nt, true, sizeof(nt));
    nt[0]=nt[1]=false;
    for(int i=2; i<=sqrt(N); i++)
        if(nt[i]){
            for(int j = i*i; j <= N; j+=i)
                nt[j] = false;
        }
}

bool check_nt(int x){
    for(int i = 2; i <= sqrt(x); i++)
        if(x%i==0)
            return false;
    return x > 1;
}

bool check(int x){
    if(x <= N && !nt[x]) return false;
    else if(x > N && !check_nt(x)) return false;
    bool del = false;
    for(int i = 0; i < 10; i++)
        if(x*10+i > N && check_nt(x*10+i))
            del = true;
        else if(x*10+i <= N && nt[x*10+i])
            del = true;
    if(!del) return false;
    while(x>=10){
        if(!nt[x/10]) return false;
        x /= 10;
    }
    return true;
}

int main()
{
    int n; cin >> n;
    int a[n];
    bool res[n];
    snt();
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(check(a[i]))
            res[i] = true;
        else
            res[i] = false;
    }
    int f[n+1];
    f[0] = 0;
    int cnt = 0;
    for(int i = 1; i<=n; i++){
        if(res[i-1])
            cnt++;
        f[i]=cnt;
    }
    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        cout << f[y] - f[x-1]<<'\n';
    }
    return 0;
}
