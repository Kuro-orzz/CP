#include <iostream>
using namespace std;

int main()
{
    string s; getline(cin, s);
    string x = "";
    for(int i = 0; i < s.length(); i++)
        if(s[i]>='a'&&s[i]<='z' || s[i]>='A' && s[i]<='Z')
            x += s[i];
    cout << x;
    return 0;
}
