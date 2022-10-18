#include"sting.h"
void sting::resize(size_t lenNew)
{
	char *pNew = new char[lenNew];
	std::memcpy(pNew, this->p, std::min(this->len, lenNew) * sizeof(char));
	std::swap(this->p, pNew);
	std::swap(this->len, lenNew);
}
sting::sting()
{
	this->p = NULL;	
	this->len = 0;
}
sting::~sting()
{
	if(this->len) delete [] this->p;
	this->len = 0;	
}
sting& sting::operator=(const sting& t)
{
	if(this->len) delete [] this->p;
	this->len = t.len;
	p = new char[this->len];
	std::memcpy(this->p, t.p, this->len * sizeof(char));
	return *this;	
}
sting& sting::operator=(const char* t)
{
	if(this->len) delete [] this->p;
	this->len = strlen(t);
	p = new char[this->len];
	std::memcpy(this->p, t, this->len * sizeof(char));
	return *this;	
}
char& sting::operator[](const size_t& t)
{
	assert(this->len > t);
	return this->p[t];
}
const char& sting::operator[](const size_t& t) const
{
	assert(this->len > t);
	return this->p[t];
}
bool sting::operator==(const sting &t) const
{
	if(t.len != this->len ) return false;
	for(size_t i = 0; i < this->len; i++)
		if((*this)[i] != t[i] )	 
			return false;
	return true;		
}
bool sting::operator<(const sting &t) const
{
	for(int i = 0; i < std::min(this->len, t.len); i++)
		if((*this)[i] != t[i]) 
			return (*this)[i] < t[i];
	return this->len < t.len;
}
bool sting::operator>(const sting &t) const
{
	for(int i = 0; i < std::min(this->len, t.len); i++)
		if((*this)[i] != t[i])	
			return (*this)[i] > t[i];
	return this->len > t.len;
}
sting& sting::operator+=(const sting&t)
{
	size_t lenOld=this->len;
	this->resize(lenOld + t.len);
	for(size_t i = 0; i < t.len; i++)
		(*this)[lenOld + i] = t[i];
	return *this;
}
sting sting::operator+(const sting&t)
{
	sting res = *this;
	res.resize(this->len + t.len);
	for(size_t i = 0; i < t.len; i++)
		res[this->len + i] = t[i];
	return res;
}
sting operator+(const char* s, const sting &t)
{
	sting res = s ;
	return res += t;
}
std::ostream &operator<<(std::ostream& out ,const sting& t)
{
	for(size_t i = 0; i < t.len; i++)
		out << t[i] ;
	return out;
}
std::istream &operator>>(std::istream& in ,sting& t)
{
	static char s[100000];
	in >> s;
	t = s;
	return in;
}