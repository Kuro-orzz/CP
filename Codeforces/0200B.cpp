#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n; cin >> n;
    int res = 0;
    for (int i = 0;  i < n; i++){
        int x; cin >> x;
        res += x;
    }
    cout << fixed << setprecision(12) << (double)res/n;
    return 0;
}