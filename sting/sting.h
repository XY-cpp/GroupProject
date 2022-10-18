#ifndef XY_STRING
#define XY_STRING
#include <iostream>
class sting
{
private:
	char* p = NULL;
	size_t len = 0;
	void resize(size_t lenNew);
public:
	sting();
	~sting();

	sting& operator=(const sting& t);
	sting(const sting& t){ *this = t; };
	sting& operator=(const char *t);
	sting(const char* t){ *this = t; };

	char& operator[](const size_t& t);
	const char& operator[](const size_t& t) const;

	bool operator==(const sting& t)const ;
	bool operator!=(const sting& t)const { return ~(*this == t); }
	bool operator<(const sting& t)const;
	bool operator<=(const sting& t)const { return *this < t||*this == t; }
	bool operator>(const sting& t)const;
	bool operator>=(const sting& t)const { return *this > t||*this == t;}

	sting& operator+=(const sting& t);// there is no need to write another funtion to combine sting and char*,
	sting operator+(const sting& t);//	because the char* would be converted to sting by the function sting(const char* t)
	
	size_t length(){ return len; };

	friend sting operator+(const char* s, const sting &t);
	friend std::ostream &operator<<(std::ostream& out ,const sting& t);
	friend std::istream &operator>>(std::istream& in ,sting& t);
};
#endif