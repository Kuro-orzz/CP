#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*---------bvd trick--------*/
//
// f0 f1f2f3 f4 f5
//  0 1 5 14 30 55  bac 3
//   1 4 9 16 25    bac 2
//    3 5 7  9      bac 1
//     2 2 2        bac 0

// f = ax^3 + bx^2 + cx + d

// f0 = 0 = d
// f1 = 1 = a + b + c
// f2 = 5 = 8a + 4b + 2c
// f3 = 14 = 27a + 9b + 3c 

// a = 1/3, b = 1/2, c = 1/6

// => fn = (x^3)/3 + (x^2)/2 + x/6
//		 = (2x^3+3x^2+x)/6

int main() {
	ll n = 100;
	ll fn = (2*powl(n, 3) + 3*powl(n, 2) + n)/6;
	int k = 0;
	ll t = powl(n*(1+n)/2, 2);
	cout << fn << " " << t << '\n';
	cout << t-fn;
	return 0;
}