/*
Copyright (c) 2019 Generation Loss Interactive

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef __Q_VECTOR2_H__
#define __Q_VECTOR2_H__

#include "qCore.h"
#include <iostream>

template<typename T, int ALIGN>
class qVector2_T
{
public:
    
    union
    {
        struct
        {              
            T x;
            T y;
		} __attribute__ ((aligned (ALIGN)));
		
       T v[2];
    };
    
    qVector2_T(T _x, T _y)
    : x(_x)
    , y(_y)
    {}
    
    qVector2_T(T _f)
    : x(_f)
    , y(_f)
    {}
    
    qVector2_T(const qVector2_T &vec)
    : x(vec.x)
    , y(vec.y)
    {}
    
    qVector2_T()
    : x(T(0))
    , y(T(0))
    {}
    
    ~qVector2_T()
    {}
    
#pragma mark getters
    
    T operator[](int pos) const
    {
        qASSERT(pos < 2);
        return v[pos];
    }
    
#pragma mark assignment
    
    qVector2_T& operator=(const qVector2_T &rhs)
    { 
        x = rhs.x;
        y = rhs.y;
        return *this;
    }
    
#pragma mark addition
    
    qVector2_T operator+(const T t) const
    { 
        qVector2_T temp;
        temp.x = x + t;
        temp.y = y + t;
        return temp;
    }
    
    qVector2_T operator+(const qVector2_T &rhs) const
    { 
        qVector2_T temp;
        temp.x = x + rhs.x;
        temp.y = y + rhs.y;
        return temp;
    }
    
    qVector2_T& operator+=(const T t)
    { 
        x += t;
        y += t;
        return *this;
    }
    
    qVector2_T& operator+=(const qVector2_T &rhs)
    { 
        x += rhs.x;
        y += rhs.y;
        return *this;
    };
    
#pragma mark subtraction
    
    qVector2_T operator-(const T t) const
    { 
        qVector2_T temp;
        temp.x = x - t;
        temp.y = y - t;
        return temp;
    }
    
    qVector2_T operator-(const qVector2_T &rhs) const
    { 
        qVector2_T temp;
        temp.x = x - rhs.x;
        temp.y = y - rhs.y;
        return temp;
    }
    
    qVector2_T& operator-=(const T t)
    { 
        x -= t;
        y -= t;
        return *this;
    }
    
    qVector2_T& operator-=(const qVector2_T &rhs)
    { 
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
	
#pragma mark negation

    qVector2_T operator-()
    {
		qVector2_T temp;
		temp.x = -x;
		temp.y = -y;
		return temp;
    }
    
#pragma mark multiplication
    
    qVector2_T operator*(const T t) const
    { 
        qVector2_T temp;
        temp.x = x * t;
        temp.y = y * t;
        return temp;
    }
    
    qVector2_T operator*(const qVector2_T &rhs) const
    { 
        qVector2_T temp;
        temp.x = x * rhs.x;
        temp.y = y * rhs.y;
        return temp;
    }
    
    qVector2_T& operator*=(const T t)
    { 
        x *= t;
        y *= t;
        return *this;
    }
    
    qVector2_T& operator*=(const qVector2_T &rhs)
    { 
        x *= rhs.x;
        y *= rhs.y;
        return *this;
    }
    
#pragma mark division
    
    qVector2_T operator/(const T t) const
    { 
        qVector2_T temp;
        qASSERT(t != T(0));
        temp.x = x / t;
        temp.y = y / t;
        return temp;
    }
    
    qVector2_T operator/(const qVector2_T &rhs) const
    { 
        qVector2_T temp;
        qASSERT(rhs.x != T(0));
        temp.x = x / rhs.x;
        qASSERT(rhs.y != T(0));
        temp.y = y / rhs.y;
        return temp;
    }
    
    qVector2_T& operator/=(const T t)
    { 
        qASSERT(t != T(0));
        x /= t;
        y /= t;
        return *this;
    }
    
    qVector2_T& operator/=(const qVector2_T &rhs)
    { 
        qASSERT(rhs.x != T(0));
        x /= rhs.x;
        qASSERT(rhs.y != T(0));
        y /= rhs.y;
        return *this;
    }

#pragma mark util
    
    void Normalize()
	{
		float length = Length(*this);
		qASSERT(length != T(0));
		*this /= length;
	}
	
    T Length() const
	{
		return qVector2_T::Length(*this);
	}
	
    qVector2_T Perpendicular()
	{
		qVector2_T v(-y, x);
		return v;
	}
    
	static qVector2_T Normalize(const qVector2_T &v)
	{
		qVector2_T temp = v;
		temp.Normalize();
		return temp;
	}
	
	static T Dot(const qVector2_T &v1, const qVector2_T &v2)
	{
		return (v1.x * v2.x) + (v1.y * v2.y);
	}
	
	static T Length(const qVector2_T &v)
	{
		return sqrtf(Dot(v, v ));
	}
	
	static qVector2_T Abs(const qVector2_T &v)
	{
		return qVector2_T(
			qAbs(v.x),
			qAbs(v.y)
		);
	}
	
	static qVector2_T Max(const qVector2_T &v1, const qVector2_T &v2)
	{
		return qVector2_T(
			qMax(v1.x, v2.x),
			qMax(v1.y, v2.y)
		);
	}
	
	static qVector2_T Min(const qVector2_T &v1, const qVector2_T &v2)
	{
		return qVector2_T(
			qMin(v1.x, v2.x),
			qMin(v1.y, v2.y)
		);
	}
	
	friend std::ostream& operator<<(std::ostream& out, const qVector2_T& v)
	{
		out << "[" << v.x << ", " << v.y << "]";
		return out;
	}
} __attribute__ ((aligned (ALIGN)));

typedef qVector2_T<float, 4> qVector2;
typedef qVector2_T<half, 2> qVector2h;

const qVector2 qVector2_NegativeOne(-1.0f, -1.0f);
const qVector2 qVector2_Zero(0.0f, 0.0f);
const qVector2 qVector2_One(1.0f, 1.0f);

#endif // __VECTOR2_H__
