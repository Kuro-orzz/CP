// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <cstring>
// #include <bitset>
// #include <stack>
// #include <fstream>
// #include <numeric>
// #include <iomanip>
// #include <vector>
// #include <sstream>
// #include <set>
// #include <map>
// #include <list> 
// #include <iomanip>
// #define filein() freopen("test.inp", "r", stdin);
// #define fileout() freopen("test.out", "w", stdout);
// #define ll long long
// #define MOD 1000000007
// #define N 1000000
// using namespace std;

// class Author{
// 	private:
// 		string name, email;
// 		char gender;
// 	public:
// 		Author(string, string, char);
// 		string getName();
// 		string getEmail();
// 		void setEmail(string);
// 		char getGender();
// 		string toString();
// };

// Author::Author(string name, string email, char gender){
// 	this->name = name;
// 	this->email = email;
// 	this->gender = gender;
// }
// string Author::getName(){return this->name;}
// string Author::getEmail(){return this->email;}
// void Author::setEmail(string email){this->email=email;}
// char Author::getGender(){return this->gender;}
// string Author::toString(){}

// class Book{
// 	friend class Author;
// 	private:
// 		string name;
// 		Author authors[1000];
// 		double price;
// 		static int qty;
// 	public:
// 		Book(string, Author[], double);
// 		Book(string, Author[], double, int);
// 		string getName();
// 		Author getAuthors();
// 		double getPrice();
// 		void setPrice(double);
// 		int getQty();
// 		void setQty(int);
// 		string toString();
// 		string getAuthorNames();
// };
// int Book::qty = 0;
// Book::Book(string name, Author authors[], double price){
// 	this->name = name;
// 	//this->authors[1000] = authors[1000];
// 	this->price = price;
// }


// void solve(){
	
// }

// int main(){
//     filein(); fileout();
//     int t; cin >> t;
//     while(t--)
//         solve();
//     return 0;
// }
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
#include <climits>
#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define N 1000000
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 0; i < n; i++)
    	if(i+2 < n && (s[i] == 'a' || s[i] == 'e') && (s[i+2] == 'a' || s[i+2] == 'e')){
    		cout << s[i] << '.';
    	}
    	else if(i+2 < n && (s[i] == 'a' || s[i] == 'e') && (s[i+2] != 'a' || s[i+2] != 'e')){
    		cout << s[i] << s[i+1] << '.';
    		i++;
    	}
    	else
    		cout << s[i];
    cout << '\n';
}

int main(){
    fast();
    //filein(); fileout();
    int t; cin >> t;
    while(t--)
        solve(); 
    return 0;
}