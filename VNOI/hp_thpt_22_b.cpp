#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    pair<int, bool> a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        if(a[i].first < 10){
            a[i].first *= 11;
            a[i].second = true;
        }
        else
            a[i].second = false;
    }
    sort(a, a+n);
    string s = "";
    for(int i = n-1; i >= 0; i--)
        if(!a[i].second)
            s += to_string(a[i].first);
        else
            s += to_string(a[i].first/11);
    cout << s;
    return 0;
}
