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

#ifndef __Q_VECTOR3_H__
#define __Q_VECTOR3_H__

#include "qCore.h"
#include <iostream>

template<typename T, int ALIGN>
class qVector3_T
{
public:
    
    union
    {
        struct
        {              
            T x;
            T y;
            T z;
        } __attribute__ ((aligned (ALIGN)));
		
        T v[3];
    };
    
    qVector3_T(T _x, T _y, T _z)
    : x(_x)
    , y(_y)
    , z(_z)
    {}
    
    qVector3_T(T _f)
    : x(_f)
    , y(_f)
    , z(_f)
    {}
	
    qVector3_T(const qVector3_T &vec)
    : x(vec.x)
    , y(vec.y)
    , z(vec.z)
    {}
    
    qVector3_T()
    : x(T(0))
    , y(T(0))
    , z(T(0))
    {}
    
    ~qVector3_T()
    {}

#pragma mark getters
    
    T operator[](int pos) const
    {
        qASSERT(pos < 3);
        return v[pos];
    }
    
#pragma mark assignment
    
    qVector3_T& operator=(const qVector3_T &rhs)
    { 
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        return *this;
    }
    
#pragma mark addition
    
    qVector3_T operator+(const T t) const
    { 
        qVector3_T temp;
        temp.x = x + t;
        temp.y = y + t;
        temp.z = z + t;
        return temp;
    }
    
    qVector3_T operator+(const qVector3_T &rhs) const
    { 
        qVector3_T temp;
        temp.x = x + rhs.x;
        temp.y = y + rhs.y;
        temp.z = z + rhs.z;
        return temp;
    }
    
    qVector3_T& operator+=(const T t)
    { 
        x += t;
        y += t;
        z += t;
        return *this;
    }
    
    qVector3_T& operator+=(const qVector3_T &rhs)
    { 
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    };
    
#pragma mark subtraction
    
    qVector3_T operator-(const T t) const
    { 
        qVector3_T temp;
        temp.x = x - t;
        temp.y = y - t;
        temp.z = z - t;
        return temp;
    }
    
    qVector3_T operator-(const qVector3_T &rhs) const
    { 
        qVector3_T temp;
        temp.x = x - rhs.x;
        temp.y = y - rhs.y;
        temp.z = z - rhs.z;
        return temp;
    }
    
    qVector3_T& operator-=(const T t)
    { 
        x -= t;
        y -= t;
        z -= t;
        return *this;
    }
    
    qVector3_T& operator-=(const qVector3_T &rhs)
    { 
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }
	
#pragma mark negation

    qVector3_T operator-()
    {
		qVector3_T temp;
		temp.x = -x;
		temp.y = -y;
		temp.z = -z;
		return temp;
    }
    
#pragma mark multiplication
    
    qVector3_T operator*(const T t) const
    { 
        qVector3_T temp;
        temp.x = x * t;
        temp.y = y * t;
        temp.z = z * t;
        return temp;
    }
    
    qVector3_T operator*(const qVector3_T &rhs) const
    { 
        qVector3_T temp;
        temp.x = x * rhs.x;
        temp.y = y * rhs.y;
        temp.z = z * rhs.z;
        return temp;
    }
    
    qVector3_T& operator*=(const T t)
    { 
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    
    qVector3_T& operator*=(const qVector3_T &rhs)
    { 
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        return *this;
    }
    
#pragma mark division
    
    qVector3_T operator/(const T t) const
    { 
        qVector3_T temp;
        qASSERT(t != T(0));
        temp.x = x / t;
        temp.y = y / t;
        temp.z = z / t;
        return temp;
    }
    
    qVector3_T operator/(const qVector3_T &rhs) const
    { 
        qVector3_T temp;
        qASSERT(rhs.x != T(0));
        temp.x = x / rhs.x;
        qASSERT(rhs.y != T(0));
        temp.y = y / rhs.y;
        qASSERT(rhs.z != T(0));
        temp.z = z / rhs.z;
        return temp;
    }
    
    qVector3_T& operator/=(const T t)
    { 
        qASSERT(t != T(0));
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }
    
    qVector3_T& operator/=(const qVector3_T &rhs)
    { 
        qASSERT(rhs.x != T(0));
        x /= rhs.x;
        qASSERT(rhs.y != T(0));
        y /= rhs.y;
        qASSERT(rhs.z != T(0));
        z /= rhs.z;
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
		return qVector3_T::Length(*this);
	}
	
    qVector3_T Perpendicular()
	{
		//there are an infinite number of perpendicular vectors to a 3d vector;
		//this just provides a consistent way to find one, such that the dot product is zero
		qVector3_T v(-y, x, T(0));
		
		//on the chance x & y are both 0
		if (v.Length() == T(0))
		{
			v = qVector3_T(-z, T(0), T(0));
			qASSERTM(v.Length() != T(0), "Asking for perpendicular vector to 0,0,0");
		}
		
		return v;
	}
    
	static qVector3_T Normalize(const qVector3_T &v)
	{
		qVector3_T temp = v;
		temp.Normalize();
		return temp;
	}
	
	static T Dot(const qVector3_T &v1, const qVector3_T &v2)
	{
		return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	}
	
	static qVector3_T Cross(const qVector3_T &v1, const qVector3_T &v2)
	{
		return qVector3_T(
			(v1.y * v2.z) - (v1.z * v2.y),
			(v1.z * v2.x) - (v1.x * v2.z),
			(v1.x * v2.y) - (v1.y * v2.x)
		);
	}
	
	static T Length(const qVector3_T &v)
	{
		return sqrtf(Dot(v, v ));
	}
	
	static qVector3_T Abs(const qVector3_T &v)
	{
		return qVector3_T(
			qAbs(v.x),
			qAbs(v.y),
			qAbs(v.z)
		);
	}
	
	static qVector3_T Max(const qVector3_T &v1, const qVector3_T &v2)
	{
		return qVector3_T(
			qMax(v1.x, v2.x),
			qMax(v1.y, v2.y),
			qMax(v1.z, v2.z)
		);
	}
	
	static qVector3_T Min(const qVector3_T &v1, const qVector3_T &v2)
	{
		return qVector3_T(
			qMin(v1.x, v2.x),
			qMin(v1.y, v2.y),
			qMin(v1.z, v2.z)
		);
	}
	
	static qVector3_T RotateAroundAxis(qVector3_T p, T theta, qVector3_T axis)
	{
		qVector3_T q(0);
		qVector3_T r = qVector3_T::Normalize(axis);
		
		float costheta = cos(theta);
		float sintheta = sin(theta);

		q.x += (costheta + (1 - costheta) * r.x * r.x) * p.x;
		q.x += ((1 - costheta) * r.x * r.y - r.z * sintheta) * p.y;
		q.x += ((1 - costheta) * r.x * r.z + r.y * sintheta) * p.z;

		q.y += ((1 - costheta) * r.x * r.y + r.z * sintheta) * p.x;
		q.y += (costheta + (1 - costheta) * r.y * r.y) * p.y;
		q.y += ((1 - costheta) * r.y * r.z - r.x * sintheta) * p.z;

		q.z += ((1 - costheta) * r.x * r.z - r.y * sintheta) * p.x;
		q.z += ((1 - costheta) * r.y * r.z + r.x * sintheta) * p.y;
		q.z += (costheta + (1 - costheta) * r.z * r.z) * p.z;

		return q;
	}
	
	friend std::ostream& operator<<(std::ostream& out, const qVector3_T& vec3)
	{
		out << "[" << vec3.x << ", " << vec3.y << ", " << vec3.z << "]";
		return out;
	}
} __attribute__ ((aligned (ALIGN)));

typedef qVector3_T<double, 8> qVector3d;
typedef qVector3_T<float, 4> qVector3;
typedef qVector3_T<half, 2> qVector3h;

const qVector3 qVector3_NegativeOne(-1.0f, -1.0f, -1.0f);
const qVector3 qVector3_Zero(0.0f, 0.0f, 0.0f);
const qVector3 qVector3_One(1.0f, 1.0f, 1.0f);
const qVector3 qVector3_Up(0.0f, 1.0f, 0.0f);
const qVector3 qVector3_Down(0.0f, -1.0f, 0.0f);

#endif // __Q_VECTOR3_H__
