#include <iostream>
using namespace std;

int main()
{
    string s; cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.length()-5; i++)
        if(s.substr(i, 5) == "virus")
            cnt++;
    cout << cnt;
    return 0;
}
