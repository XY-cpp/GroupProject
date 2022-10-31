#ifndef BASE_HEAD
#define BASE_HEAD
#include <iostream>
template<class T>
class Base
{
private:
	T* p=NULL;
	size_t len=0;
public:
	Base();
	~Base();

	Base(const Base<T>& t){ *this = t; };
	Base<T>& operator=(const Base<T>& t);

	T& operator[](const size_t& t);
	const T& operator[](const size_t& t) const;

	virtual bool operator==(const Base<T>& t);
	virtual bool operator!=(const Base<T>& t){ return ~(*this==t); }

	void resize(size_t lenNew);
	size_t size(){ return len; };
};
template<class T>
T& Base<T>::operator[](const size_t &t)
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
	if(t.len != this->len ) return false;
	for(size_t i = 0; i < this->len; i++)
		if((*this)[i] != t[i] )	 
			return false;
	return true;
}
template<class T>
void Base<T>::resize(size_t lenNew)
{
	T *pNew = new T[lenNew];
	std::memcpy(pNew, this->p, std::min(this->len, lenNew) * sizeof(T));
	std::swap(this->p, pNew);
	std::swap(this->len, lenNew);
}
#endif