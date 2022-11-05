#ifndef BASE_HEAD
#define BASE_HEAD
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
#include <cstring>
using namespace std;
template<typename T>
class Base {
protected:
	T *p=NULL;
	size_t len;
public:
	Base(size_t i = 0,const T *x=NULL) {
		len=(i>0)?i:0;
		x=NULL;
		if(len>0){
			p=new T[len];
			for(size_t j=0;j<len;j++)
				p[i]=(x!=NULL)?x[i]:0;
		}
	}
	virtual ~Base() {
		delete[] p;
		p=NULL;
		len=0;
	}
	Base(const Base<T>& t):len(0),p(NULL)
	{
		*this = t;
	};
	Base & operator=(const Base& t) {
		if(*this == t) return *this;
		if(p!=NULL )delete[] p;
		len=t.len;
		p=NULL;
		if(len>0){
			p=new T[len];
			for(size_t i=0;i<len;i++)
				p[i]=t.p[i];
		}
	};
	T& operator[](const size_t& t);
	const T& operator[](const size_t& t) const;

	virtual bool operator==(const Base<T>& t);
	virtual bool operator!=(const Base<T>& t) { return ~(*this == t); }
	virtual void Output(ostream& out)const=0;

	void resize(size_t lenNew);
	size_t size() const { return len; };
};
template<class T>
T& Base<T>::operator[](const size_t& t)
{
	assert(this->len > t);
	return this->p[t];
}
template<class T>
const T& Base<T>::operator[](const size_t& t) const
{
	assert(this->len > t);
	return this->p[t];
}
template<class T>
bool Base<T>::operator==(const Base<T>& t)
{
	if (t.len != this->len) return false;
	for (size_t i = 0; i < this->len; i++)
		if ((*this)[i] != t[i])
			return false;
	return true;
}
template<class T>
void Base<T>::resize(size_t lenNew)
{
	T* pNew = new T[lenNew];
	std::memcpy(pNew, this->p, std::min(this->len, lenNew) * sizeof(T));
	std::swap(this->p, pNew);
	std::swap(this->len, lenNew);
	if(pNew!=NULL) delete[] pNew;
}
template<typename T>
ostream& operator << (ostream& out, const Base<T>& t) {
	t.Output(out);
	return out;
}
#endif
