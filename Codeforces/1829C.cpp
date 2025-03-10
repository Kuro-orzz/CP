#include <iostream>
using namespace std;

int main(){
    //freopen("file.inp.c","r",stdin);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int time_first = 1e9;
        int time_second = 1e9;
        int time_both = 1e9;
        for(int i=0; i < n; i++){
            int time; cin >> time;
            string s; cin >> s;
            if (s == "11" && time < time_both)
                time_both = time;
            if (s == "10" && time < time_first)
                time_first = time;
            if (s == "01" && time <time_second)
                time_second = time;
        }
        if (time_both < time_first + time_second && time_both != 1e9)
            cout << time_both << endl;
        else if (time_both == 1e9 && (time_first == 1e9 || time_second == 1e9))
            cout << -1 << endl;
        else
            cout << time_first + time_second << endl;
    }
    return 0;
}