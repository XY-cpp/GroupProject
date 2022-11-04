//
// Created by ShoiLyaung on 2022/11/5.
//

#ifndef XY_VECTOR_WJX_H
#define XY_VECTOR_WJX_H
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <initializer_list>
#include "../Base/Base.h"
template<class T>
class Vector:public Base<T>{
private:
    T* p=NULL;
    size_t len=0;
public:
    Vector();
    ~Vector();

    Vector(const Vector<T>& t){ *this = t; };
    Vector<T>& operator=(const Vector<T>& t);

    // example: Vector<int>a = {1,2};
    Vector(const std::initializer_list<T>& t){ *this = t; }
    Vector<T>& operator=(const std::initializer_list<T>& t);
    bool operator==(const Vector<T>& t);
    bool operator!=(const Vector<T>& t){ return ~(*this==t); }

    Vector<T>& operator+=(const Vector<T>& t);//a vector add a vector
    Vector<T>operator+(Vector<T> t){ return t += *this; };
    Vector<T>& operator-=(const Vector<T>& t);//a vector minus a vector
    Vector<T>operator-();//get a opposite vector
    Vector<T>operator-(Vector<T> t){ return -(t -= *this); };
    Vector<T>operator*(const T& t);//a vector times a number
    Vector<T>& operator*=(const T& t);
    Vector<T>operator/(const T& t);//a vector divides a number
    Vector<T>& operator/=(const T& t);

    T operator*(const Vector<T>& t);//Dot product

    void resize(size_t lenNew);//change the dimension of a vector
    size_t size(){ return len; };//get the size of a vector
    long double length();//get the length of a vector

    friend std::ostream &operator<<(std::ostream& out ,const Vector<T>& t)
    {
        out << "{" ;
        if(t.len) out << t[0];
        for(size_t i = 1; i < t.len; i++)
            out << "," << t[i] ;
        out << "}";
        return out;
    }
    friend std::istream &operator>>(std::istream& in ,Vector<T>& t)
    {
        size_t len;
        in >> len;
        t.resize(len);
        for(size_t i = 0; i < len; i++)
            in >> t[i];
        return in;
    }
};

template<class T>
Vector<T>::Vector()
{
    this->p = NULL;
    this->len = 0;
}

template<class T>
Vector<T>::~Vector()
{
    if(this->len) delete [] this->p;
    this->len = 0;
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& t)
{
    if(this->len) delete [] this->p;
    this->len = t.len;
    p = new T[this->len];
    std::memcpy(this->p, t.p, this->len * sizeof(T));
    return *this;
}

template<class T>
Vector<T>& Vector<T>::operator=(const std::initializer_list<T>& t)
{
    if(this->len) delete [] this->p;
    this->len = t.size();
    p = new T[this->len];
    for(size_t i = 0; i < t.size(); i++)
        p[i] = *(t.begin() + i);
    return *this;
}

template<class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& t)
{
    assert(this->len == t.len);
    for(size_t i = 0; i < this->len; i++)
        (*this)[i] += t[i];
    return *this;
}

template<class T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& t)
{
    assert(this->len == t.len);
    for(size_t i = 0; i < this->len; i++)
        (*this)[i] -= t[i];
    return *this;
}

template<class T>
Vector<T> Vector<T>::operator-()
{
    for(size_t i = 0; i < this->len; i++)
        (*this)[i] = -(*this)[i];
    return *this;
}

template<class T>
Vector<T> Vector<T>::operator*(const T& t)
{
    Vector<T>res = *this;
    for(size_t i = 0; i < this->len; i++)
        res[i] *= t;
    return res;
}

template<class T>
Vector<T>& Vector<T>::operator*=(const T& t)
{
    for(size_t i = 0; i < this->len; i++)
        (*this)[i] *= t;
    return *this;
}

template<class T>
Vector<T> Vector<T>::operator/(const T& t)
{
    assert(t != 0);
    Vector<T>res = *this;
    for(size_t i = 0; i < this->len; i++)
        res[i] /= t;
    return res;
}

template<class T>
Vector<T>& Vector<T>::operator/=(const T& t)
{
    assert(t != 0);
    for(size_t i = 0; i < this->len; i++)
        (*this)[i] /= t;
    return *this;
}

template<class T>
T Vector<T>::operator*(const Vector<T>& t)
{
    assert(this->len == t.len)	;
    T res=0;
    for(size_t i = 0; i < this->len; i++)
        res += (*this)[i] * t[i];
    return res;
}

template<class T>
long double Vector<T>::length()
{
    long double res = 0;
    for(int i = 0; i < this->len; i++)
        res += std::pow((*this)[i], 2);
    return std::sqrt(res);
}
#endif //XY_VECTOR_WJX_H
