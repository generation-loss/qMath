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

#ifndef __Q_VECTOR4_H__
#define __Q_VECTOR4_H__

#include "qCore.h"
#include "qUtil.h"
#include "qVector3.h"

template<typename T, int ALIGN>
class qVector4_T
{
public:
    
    union
    {
        struct
        {              
            T x;
            T y;
            T z;
            T w;
		} __attribute__ ((aligned (ALIGN)));
        T v[4];
    };
    
    qVector4_T(T _x, T _y, T _z, T _w)
    : x(_x)
    , y(_y)
    , z(_z)
    , w(_w)
    {}
    
    qVector4_T(T _f)
    : x(_f)
    , y(_f)
    , z(_f)
    , w(_f)
    {}
	
    qVector4_T(const qVector4_T &vec)
    : x(vec.x)
    , y(vec.y)
    , z(vec.z)
    , w(vec.w)
    {}
	
    qVector4_T(const qVector3 &vec, const T _w)
    : x(vec.x)
    , y(vec.y)
    , z(vec.z)
    , w(_w)
    {}
    
    qVector4_T()
    : x(T(0))
    , y(T(0))
    , z(T(0))
    , w(T(0))
    {}
    
    ~qVector4_T()
    {}
    
#pragma mark getters
    
    T operator[](int pos) const
    {
        qASSERT(pos < 4);
        return v[pos];
    }
    
#pragma mark assignment
    
    qVector4_T& operator=(const qVector4_T &rhs)
    { 
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        w = rhs.w;
        return *this;
    }
    
#pragma mark addition
    
    qVector4_T operator+(const T t) const
    { 
        qVector4_T temp;
        temp.x = x + t;
        temp.y = y + t;
        temp.z = z + t;
        temp.w = w + t;
        return temp;
    }
    
    qVector4_T operator+(const qVector4_T &rhs) const
    { 
        qVector4_T temp;
        temp.x = x + rhs.x;
        temp.y = y + rhs.y;
        temp.z = z + rhs.z;
        temp.w = w + rhs.w;
        return temp;
    }
    
    qVector4_T& operator+=(const T t)
    { 
        x += t;
        y += t;
        z += t;
        w += t;
        return *this;
    }
    
    qVector4_T& operator+=(const qVector4_T &rhs)
    { 
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        w += rhs.w;
        return *this;
    };
    
#pragma mark subtraction
    
    qVector4_T operator-(const T t) const
    { 
        qVector4_T temp;
        temp.x = x - t;
        temp.y = y - t;
        temp.z = z - t;
        temp.w = w - t;
        return temp;
    }
    
    qVector4_T operator-(const qVector4_T &rhs) const
    { 
        qVector4_T temp;
        temp.x = x - rhs.x;
        temp.y = y - rhs.y;
        temp.z = z - rhs.z;
        temp.w = w - rhs.w;
        return temp;
    }
    
    qVector4_T& operator-=(const T t)
    { 
        x -= t;
        y -= t;
        z -= t;
        w -= t;
        return *this;
    }
    
    qVector4_T& operator-=(const qVector4_T &rhs)
    { 
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        w -= rhs.w;
        return *this;
    }
	
#pragma mark negation

    qVector4_T operator-()
    {
		qVector4_T temp;
		temp.x = -x;
		temp.y = -y;
		temp.z = -z;
		temp.w = -w;
		return temp;
    }
    
#pragma mark multiplication
    
    qVector4_T operator*(const T t) const
    { 
        qVector4_T temp;
        temp.x = x * t;
        temp.y = y * t;
        temp.z = z * t;
        temp.w = w * t;
        return temp;
    }
    
    qVector4_T operator*(const qVector4_T &rhs) const
    { 
        qVector4_T temp;
        temp.x = x * rhs.x;
        temp.y = y * rhs.y;
        temp.z = z * rhs.z;
        temp.w = w * rhs.w;
        return temp;
    }
    
    qVector4_T& operator*=(const T t)
    { 
        x *= t;
        y *= t;
        z *= t;
        w *= t;
        return *this;
    }
    
    qVector4_T& operator*=(const qVector4_T &rhs)
    { 
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        w *= rhs.w;
        return *this;
    }
    
#pragma mark division
    
    qVector4_T operator/(const T t) const
    { 
        qVector4_T temp;
        qASSERT(t != T(0));
        temp.x = x / t;
        temp.y = y / t;
        temp.z = z / t;
        temp.w = w / t;
        return temp;
    }
    
    qVector4_T operator/(const qVector4_T &rhs) const
    { 
        qVector4_T temp;
        qASSERT(rhs.x != T(0));
        temp.x = x / rhs.x;
        qASSERT(rhs.y != T(0));
        temp.y = y / rhs.y;
        qASSERT(rhs.z != T(0));
        temp.z = z / rhs.z;
        qASSERT(rhs.w != T(0));
        temp.w = w / rhs.w;
        return temp;
    }
    
    qVector4_T& operator/=(const T t)
    { 
        qASSERT(t != T(0));
        x /= t;
        y /= t;
        z /= t;
        w /= t;
        return *this;
    }
    
    qVector4_T& operator/=(const qVector4_T &rhs)
    { 
        qASSERT(rhs.x != T(0));
        x /= rhs.x;
        qASSERT(rhs.y != T(0));
        y /= rhs.y;
        qASSERT(rhs.z != T(0));
        z /= rhs.z;
        qASSERT(rhs.w != T(0));
        w /= rhs.w;
        return *this;
    }
	
#pragma mark util
	
    qVector3_T<T, ALIGN> XYZ()
    {
		return qVector3_T<T, ALIGN>(x, y, z);
	}
    
    void Normalize()
	{
		float length = Length(*this);
		qASSERT(length != T(0));
		*this /= length;
	}
	
    T Length() const
	{
		return qVector4_T::Length(*this);
	}
    
	static qVector4_T Normalize(const qVector4_T &v)
	{
		qVector4_T temp = v;
		temp.Normalize();
		return temp;
	}
	
	static T Dot(const qVector4_T &v1, const qVector4_T &v2)
	{
		return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w);
	}
	
	static T Length(const qVector4_T &v)
	{
		return sqrtf(Dot(v, v ));
	}
	
	static qVector4_T Abs(const qVector4_T &v)
	{
		return qVector4_T(
			qAbs(v.x),
			qAbs(v.y),
			qAbs(v.z),
			qAbs(v.w)
		);
	}
	
	static qVector4_T Max(const qVector4_T &v1, const qVector4_T &v2)
	{
		return qVector4_T(
			qMax(v1.x, v2.x),
			qMax(v1.y, v2.y),
			qMax(v1.z, v2.z),
			qMax(v1.z, v2.w)
		);
	}
	
	static qVector4_T Min(const qVector4_T &v1, const qVector4_T &v2)
	{
		return qVector4_T(
			qMin(v1.x, v2.x),
			qMin(v1.y, v2.y),
			qMin(v1.z, v2.z),
			qMin(v1.w, v2.w)
		);
	}
	
	friend std::ostream& operator<<(std::ostream& out, const qVector4_T& v)
	{
		out << "[" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "]";
		return out;
	}
} __attribute__ ((aligned (ALIGN)));

typedef qVector4_T<double, 8> qVector4d;
typedef qVector4_T<float, 4> qVector4;
typedef qVector4_T<half, 2> qVector4h;

const qVector4 qVector4_NegativeOne(-1.0f, -1.0f, -1.0f, -1.0f);
const qVector4 qVector4_Zero(0.0f, 0.0f, 0.0f, 0.0f);
const qVector4 qVector4_One(1.0f, 1.0f, 1.0f, 1.0f);

#endif // __VECTOR4_H__
