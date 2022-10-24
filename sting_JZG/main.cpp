#include"sting.h"
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	// sting tmp;
	// cin >> tmp;
	// cout << tmp << endl;
	/*sting tset;
	cin>>tset;
	cout<<tset<<endl;
	sting s = "a", t = "b";
	s += "a", t += "b";
	cout << s << " " << t << endl;
	s = "a" + s, t = t + "a";
	t = t + s;
	cout << s << " " << t << endl;
	cout << (s < t ? "true" : "false") << endl;
	cout << (s == "aaa" ? "true" : "false") << endl;*/
	sting a="qwertyuiop";
	cout<<"创建sting类数据a，初始化为qwertyuiop"<<endl;
	cout<<"调用c_str函数返回a的首地址:"<<a.c_str();

	return 0;
}