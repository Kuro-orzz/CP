#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    int res = 0;
    while (t--){
        int cnt = 0;
        for (int i = 0; i < 3; i++){
            int x; cin >> x;
            if (x == 1)
                cnt++;
        }
        if (cnt >= 2)
            res++;
    }
    cout << res;
    return 0;
}