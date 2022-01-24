/*
Copyright (c) 2022 Generation Loss Interactive

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

#ifndef __Q_TRIANGLE_H__
#define __Q_TRIANGLE_H__

#include "qCore.h"
#include "qVector4.h"
#include <iostream>

template<typename T, int ALIGN>
class qTriangle_T
{
public:
    
    union
    {
        struct
        {              
            T a;
            T b;
            T c;
        } __attribute__ ((aligned (ALIGN)));
		
        T t[3];
    };
    
    qTriangle_T(T _a, T _b, T _c)
    : a(_a)
    , b(_b)
    , c(_c)
    {}
	
    qTriangle_T(const qTriangle_T& tri)
    : a(tri.a)
    , b(tri.b)
    , c(tri.c)
    {}
    
    qTriangle_T()
    : a(T(0))
    , b(T(0))
    , c(T(0))
    {}
    
    ~qTriangle_T()
    {}

#pragma mark getters
    
    T operator[](int pos) const
    {
        qASSERT(pos < 3);
        return t[pos];
    }
    
#pragma mark assignment
    
    qTriangle_T& operator=(const qTriangle_T &rhs)
    { 
        a = rhs.a;
        b = rhs.b;
        c = rhs.c;
        return *this;
    }
    
#pragma mark util
    
	friend std::ostream& operator<<(std::ostream& out, const qTriangle_T& tri)
	{
		out << "[" << tri.a << ", " << tri.b << ", " << tri.c << "]";
		return out;
	}
} __attribute__ ((aligned (ALIGN)));

typedef qTriangle_T<qVector2d, 8> 	qTriangle2d;
typedef qTriangle_T<qVector2, 4> 	qTriangle2;
typedef qTriangle_T<qVector2h, 2> 	qTriangle2h;

typedef qTriangle_T<qVector3d, 8> 	qTriangle3d;
typedef qTriangle_T<qVector3, 4> 	qTriangle3;
typedef qTriangle_T<qVector3h, 2> 	qTriangle3h;

typedef qTriangle_T<qVector4d, 8> 	qTriangle4d;
typedef qTriangle_T<qVector4, 4> 	qTriangle4;
typedef qTriangle_T<qVector4h, 2> 	qTriangle4h;

#endif // __Q_TRIANGLE_H__
