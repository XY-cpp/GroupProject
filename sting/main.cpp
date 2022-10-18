#include"sting.h"
#include<iostream>
using namespace std;
int main()
{
	// sting tmp;
	// cin >> tmp;
	// cout << tmp << endl;
	sting s = "a", t = "b";
	s += "a", t += "b";
	cout << s << " " << t << endl;
	s = "a" + s, t = t + "a";
	t = t + s;
	cout << s << " " << t << endl;
	cout << (s < t ? "true":"false") << endl;
	cout << (s == "aaa" ? "true":"false") << endl;
	return 0;
}