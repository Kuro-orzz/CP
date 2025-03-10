#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,k; cin>>n>>k;
    k*=2;
    pair<int, int> a[n];
    for(int i = 0; i<n;i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a, a+n);
    int x = 0;
    int y = n-1;
    while(x < y){
        if(a[x].first+a[y].first<k)
            x++;
        else if(a[x].first+a[y].first>k)
            y--;
        else{
            cout << a[x].second << " " << a[y].second;
            return 0;
        }
    }
    cout << "0 0";
    return 0;
}
