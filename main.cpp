#include "Base/Base.h"
#include "Vector/Vector_WJX.h"
//#include "Vector/Vector_ZLJ.h"
#include<iostream>
using namespace std;
int main()
{
    Vector<double>c;
    Vector<double>a={1,2,3},b={2,3,4};
	c=a;
	cout<<a/2<<endl;
	cout<<a*b<<endl;
	a.resize(2),b.resize(2);
	cout<<a<<" "<<b<<endl;
	cout<<a+b<<endl;
	return 0;
}