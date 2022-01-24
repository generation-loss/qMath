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

#ifndef __Q_QUAD_H__
#define __Q_QUAD_H__

#include "qCore.h"
#include "qVector4.h"
#include <iostream>

template<typename T, int ALIGN>
class qQuad_T
{
public:
    
    union
    {
        struct
        {              
            T a;
            T b;
            T c;
            T d;
        } __attribute__ ((aligned (ALIGN)));
		
        T q[4];
    };
    
    qQuad_T(T _a, T _b, T _c, T _d)
    : a(_a)
    , b(_b)
    , c(_c)
    , d(_d)
    {}
	
    qQuad_T(const qQuad_T& quad)
    : a(quad.a)
    , b(quad.b)
    , c(quad.c)
    , d(quad.d)
    {}
    
    qQuad_T()
    : a(T(0))
    , b(T(0))
    , c(T(0))
    , d(T(0))
    {}
    
    ~qQuad_T()
    {}

#pragma mark getters
    
    T operator[](int pos) const
    {
        qASSERT(pos < 4);
        return q[pos];
    }
    
#pragma mark assignment
    
    qQuad_T& operator=(const qQuad_T &rhs)
    { 
        a = rhs.a;
        b = rhs.b;
        c = rhs.c;
        d = rhs.d;
        return *this;
    }
    
#pragma mark util
    
	friend std::ostream& operator<<(std::ostream& out, const qQuad_T& quad)
	{
		out << "[" << quad.a << ", " << quad.b << ", " << quad.c << ", " << quad.d << "]";
		return out;
	}
} __attribute__ ((aligned (ALIGN)));

typedef qQuad_T<qVector2d, 8> 	qQuad2d;
typedef qQuad_T<qVector2, 4> 	qQuad2;
typedef qQuad_T<qVector2h, 2> 	qQuad2h;

typedef qQuad_T<qVector3d, 8> 	qQuad3d;
typedef qQuad_T<qVector3, 4> 	qQuad3;
typedef qQuad_T<qVector3h, 2> 	qQuad3h;

typedef qQuad_T<qVector4d, 8> 	qQuad4d;
typedef qQuad_T<qVector4, 4> 	qQuad4;
typedef qQuad_T<qVector4h, 2> 	qQuad4h;

#endif // __Q_QUAD_H__
