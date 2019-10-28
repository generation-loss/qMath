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

#ifndef __Q_MATRIX2_H__
#define __Q_MATRIX2_H__

#include <math.h>
#include "qVector2.h"
#include "qCore.h"

/*
 column major
 [ m00 m10 ]
 [ m01 m11 ]
*/

template<typename T>
class qMatrix2_T
{
public:
	
    union
    {
        struct
        {
            T m00;
            T m01;
            T m10;
            T m11;
        };
        T m[4];
        T mm[2][2];
    };
	
    qMatrix2_T()
    : m00(T(1))
    , m01(T(0))
    , m10(T(0))
    , m11(T(1))
    {
    }
	
    qMatrix2_T(const qMatrix2_T &mat)
    : m00(mat.m00)
    , m01(mat.m01)
    , m10(mat.m10)
    , m11(mat.m11)
    {}
	
    qMatrix2_T(const T _m00, const T _m01,
              const T _m10, const T _m11)
    : m00(_m00)
    , m01(_m01)
    , m10(_m10)
    , m11(_m11)
    {}
	
#pragma mark getters
	
    T& operator[](int pos)
    {
        return m[pos];
    }
	
    T operator[](int pos) const
    {
        return m[pos];
    }
	
#pragma mark assignment
	
    qMatrix2_T& operator=(const qMatrix2_T &rhs)
    {
        m[0] = rhs.m[0];
        m[1] = rhs.m[1];
        m[2] = rhs.m[2];
        m[3] = rhs.m[3];
        return *this;
    }
	
#pragma mark addition
	
    qMatrix2_T operator+(const T f) const
    {
        qMatrix2_T temp;
        temp.m[0] = m[0] + f;
        temp.m[1] = m[1] + f;
        temp.m[2] = m[2] + f;
        temp.m[3] = m[3] + f;
        return temp;
    }
	
    qMatrix2_T operator+(const qMatrix2_T &rhs) const
    {
        qMatrix2_T temp;
        temp.m[0] = m[0] + rhs.m[0];
        temp.m[1] = m[1] + rhs.m[1];
        temp.m[2] = m[2] + rhs.m[2];
        temp.m[3] = m[3] + rhs.m[3];
        return temp;
    }
	
    qMatrix2_T& operator+=(const T f)
    {
        m[0] += f;
        m[1] += f;
        m[2] += f;
        m[3] += f;
        return *this;
    }
	
    qMatrix2_T& operator+=(const qMatrix2_T &rhs)
    {
        m[0] += rhs.m[0];
        m[1] += rhs.m[1];
        m[2] += rhs.m[2];
        m[3] += rhs.m[3];
        return *this;
    }
	
#pragma mark subtraction
	
    qMatrix2_T operator-(const T f) const
    {
        qMatrix2_T temp;
        temp.m[0] = m[0] - f;
        temp.m[1] = m[1] - f;
        temp.m[2] = m[2] - f;
        temp.m[3] = m[3] - f;
        return temp;
    }
	
    qMatrix2_T operator-(const qMatrix2_T &rhs) const
    {
        qMatrix2_T temp;
        temp.m[0] = m[0] - rhs.m[0];
        temp.m[1] = m[1] - rhs.m[1];
        temp.m[2] = m[2] - rhs.m[2];
        temp.m[3] = m[3] - rhs.m[3];
        return temp;
    }
	
    qMatrix2_T& operator-=(const T f)
    {
        m[0] -= f;
        m[1] -= f;
        m[2] -= f;
        m[3] -= f;
        return *this;
    }
	
    qMatrix2_T& operator-=(const qMatrix2_T &rhs)
    {
        m[0] -= rhs.m[0];
        m[1] -= rhs.m[1];
        m[2] -= rhs.m[2];
        m[3] -= rhs.m[3];
        return *this;
    }
	
#pragma mark multiplication
	
    qMatrix2_T operator*(const T f) const
    {
        qMatrix2_T temp;
        temp.m[0] = m[0] * f;
        temp.m[1] = m[1] * f;
        temp.m[2] = m[2] * f;
        temp.m[3] = m[3] * f;
        return temp;
    }
	
    qVector2 operator*(const qVector2 &rhs) const
    {
        qVector2 out;
        out.x = (m00 * rhs.x) + (m10 * rhs.y);
        out.y = (m01 * rhs.x) + (m11 * rhs.y);
        return out;
    }
	
    qMatrix2_T operator*(const qMatrix2_T &rhs) const
    {
        qMatrix2_T out;
		
        out.m00 = (m00 * rhs.m00) + (m10 * rhs.m01);
        out.m01 = (m01 * rhs.m00) + (m11 * rhs.m01);
		
        out.m10 = (m00 * rhs.m10) + (m10 * rhs.m11);
        out.m11 = (m01 * rhs.m10) + (m11 * rhs.m11);
		
        return out;
    }
	
    qMatrix2_T& operator*=(const T f)
    {
        m[0] *= f;
        m[1] *= f;
        m[2] *= f;
        m[3] *= f;
        return *this;
    }
	
    qMatrix2_T& operator*=(const qMatrix2_T &rhs)
    {
        qMatrix2_T out;
		
        out.m00 = (m00 * rhs.m00) + (m10 * rhs.m01);
        out.m01 = (m01 * rhs.m00) + (m11 * rhs.m01);
		
        out.m10 = (m00 * rhs.m10) + (m10 * rhs.m11);
        out.m11 = (m01 * rhs.m10) + (m11 * rhs.m11);
		
        (*this) = out;
        return *this;
    }
	
#pragma mark division
	
    qMatrix2_T operator/(const T f) const
    {
        qMatrix2_T temp;
        qASSERT(f != T(0));
        temp.m[0] = m[0] / f;
        temp.m[1] = m[1] / f;
        temp.m[2] = m[2] / f;
        temp.m[3] = m[3] / f;
        return temp;
    }
	
    qMatrix2_T operator/(const qMatrix2_T &rhs) const
    {
        qMatrix2_T temp;
        qASSERT(rhs.m[0] != T(0));
        qASSERT(rhs.m[1] != T(0));
        qASSERT(rhs.m[2] != T(0));
        qASSERT(rhs.m[3] != T(0));
        temp.m[0] = m[0] / rhs.m[0];
        temp.m[1] = m[1] / rhs.m[1];
        temp.m[2] = m[2] / rhs.m[2];
        temp.m[3] = m[3] / rhs.m[3];
        return temp;
    }
	
    qMatrix2_T& operator/=(const T f)
    {
        qASSERT(f != T(0));
        m[0] /= f;
        m[1] /= f;
        m[2] /= f;
        m[3] /= f;
        return *this;
    }
	
    qMatrix2_T& operator/=(const qMatrix2_T &rhs)
    {
        qASSERT(rhs.m[0] != T(0));
        qASSERT(rhs.m[1] != T(0));
        qASSERT(rhs.m[2] != T(0));
        qASSERT(rhs.m[3] != T(0));
        m[0] /= rhs.m[0];
        m[1] /= rhs.m[1];
        m[2] /= rhs.m[2];
        m[3] /= rhs.m[3];
        return *this;
    }
	
#pragma mark util
	
    static qMatrix2_T Rotate(T angle)
    {
        qMatrix2_T rotMat;
        rotMat.m00 = cos(angle);
        rotMat.m10 = -sin(angle);
        rotMat.m01 = sin(angle);
        rotMat.m11 = cos(angle);
        return rotMat;
    }
	
    static qMatrix2_T Scale(qVector2 scale)
    {
        qMatrix2_T scaleMat;
        scaleMat.m00 = scale.x;
        scaleMat.m11 = scale.y;
        return scaleMat;
    }
	
    void Transpose()
    {
        qMatrix2_T copy = *this;
        for(int x = 0; x < 2; ++ x)
        {
            for(int y = 0; y < 2; ++ y)
            {
                mm[x][y] = copy.mm[y][x];
            }
        }
    }

};

typedef qMatrix2_T<double> qMatrix2d;
typedef qMatrix2_T<float> qMatrix2;
typedef qMatrix2_T<half> qMatrix2h;

const qMatrix2 qMatrix2_Identity;

#endif // __Q_MATRIX2_H__


