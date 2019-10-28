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

#ifndef __Q_MATRIX3_H__
#define __Q_MATRIX3_H__

#include <math.h>
#include "qVector3.h"
#include "qCore.h"

/*
 column major
 [ m00 m10 m20 ]
 [ m01 m11 m21 ]
 [ m02 m12 m22 ]
*/

template<typename T>
class qMatrix3_T
{
public:
	
    union
    {
        struct
        {
            T m00;
            T m01;
            T m02;
            T m10;
            T m11;
            T m12;
            T m20;
            T m21;
            T m22;
        };
        T m[9];
        T mm[3][3];
    };
	
    qMatrix3_T()
    : m00(T(1))
    , m01(T(0))
    , m02(T(0))
    , m10(T(0))
    , m11(T(1))
    , m12(T(0))
    , m20(T(0))
    , m21(T(0))
    , m22(T(1))
    {
    }
	
    qMatrix3_T(const qMatrix3_T &mat)
    : m00(mat.m00)
    , m01(mat.m01)
    , m02(mat.m02)
    , m10(mat.m10)
    , m11(mat.m11)
    , m12(mat.m12)
    , m20(mat.m20)
    , m21(mat.m21)
    , m22(mat.m22)
    {}
	
    qMatrix3_T(const T _m00, const T _m01, const T _m02,
              const T _m10, const T _m11, const T _m12,
              const T _m20, const T _m21, const T _m22)
    : m00(_m00)
    , m01(_m01)
    , m02(_m02)
    , m10(_m10)
    , m11(_m11)
    , m12(_m12)
    , m20(_m20)
    , m21(_m21)
    , m22(_m22)
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
	
    qMatrix3_T& operator=(const qMatrix3_T &rhs)
    {
        m[0] = rhs.m[0];
        m[1] = rhs.m[1];
        m[2] = rhs.m[2];
        m[3] = rhs.m[3];
        m[4] = rhs.m[4];
        m[5] = rhs.m[5];
        m[6] = rhs.m[6];
        m[7] = rhs.m[7];
        m[8] = rhs.m[8];
        return *this;
    }
	
#pragma mark addition
	
    qMatrix3_T operator+(const T f) const
    {
        qMatrix3_T temp;
        temp.m[0] = m[0] + f;
        temp.m[1] = m[1] + f;
        temp.m[2] = m[2] + f;
        temp.m[3] = m[3] + f;
        temp.m[4] = m[4] + f;
        temp.m[5] = m[5] + f;
        temp.m[6] = m[6] + f;
        temp.m[7] = m[7] + f;
        temp.m[8] = m[8] + f;
        return temp;
    }
	
    qMatrix3_T operator+(const qMatrix3_T &rhs) const
    {
        qMatrix3_T temp;
        temp.m[0] = m[0] + rhs.m[0];
        temp.m[1] = m[1] + rhs.m[1];
        temp.m[2] = m[2] + rhs.m[2];
        temp.m[3] = m[3] + rhs.m[3];
        temp.m[4] = m[4] + rhs.m[4];
        temp.m[5] = m[5] + rhs.m[5];
        temp.m[6] = m[6] + rhs.m[6];
        temp.m[7] = m[7] + rhs.m[7];
        temp.m[8] = m[8] + rhs.m[8];
        return temp;
    }
	
    qMatrix3_T& operator+=(const T f)
    {
        m[0] += f;
        m[1] += f;
        m[2] += f;
        m[3] += f;
        m[4] += f;
        m[5] += f;
        m[6] += f;
        m[7] += f;
        m[8] += f;
        return *this;
    }
	
    qMatrix3_T& operator+=(const qMatrix3_T &rhs)
    {
        m[0] += rhs.m[0];
        m[1] += rhs.m[1];
        m[2] += rhs.m[2];
        m[3] += rhs.m[3];
        m[4] += rhs.m[4];
        m[5] += rhs.m[5];
        m[6] += rhs.m[6];
        m[7] += rhs.m[7];
        m[8] += rhs.m[8];
        return *this;
    }
	
#pragma mark subtraction
	
    qMatrix3_T operator-(const T f) const
    {
        qMatrix3_T temp;
        temp.m[0] = m[0] - f;
        temp.m[1] = m[1] - f;
        temp.m[2] = m[2] - f;
        temp.m[3] = m[3] - f;
        temp.m[4] = m[4] - f;
        temp.m[5] = m[5] - f;
        temp.m[6] = m[6] - f;
        temp.m[7] = m[7] - f;
        temp.m[8] = m[8] - f;
        return temp;
    }
	
    qMatrix3_T operator-(const qMatrix3_T &rhs) const
    {
        qMatrix3_T temp;
        temp.m[0] = m[0] - rhs.m[0];
        temp.m[1] = m[1] - rhs.m[1];
        temp.m[2] = m[2] - rhs.m[2];
        temp.m[3] = m[3] - rhs.m[3];
        temp.m[4] = m[4] - rhs.m[4];
        temp.m[5] = m[5] - rhs.m[5];
        temp.m[6] = m[6] - rhs.m[6];
        temp.m[7] = m[7] - rhs.m[7];
        temp.m[8] = m[8] - rhs.m[8];
        return temp;
    }
	
    qMatrix3_T& operator-=(const T f)
    {
        m[0] -= f;
        m[1] -= f;
        m[2] -= f;
        m[3] -= f;
        m[4] -= f;
        m[5] -= f;
        m[6] -= f;
        m[7] -= f;
        m[8] -= f;
        return *this;
    }
	
    qMatrix3_T& operator-=(const qMatrix3_T &rhs)
    {
        m[0] -= rhs.m[0];
        m[1] -= rhs.m[1];
        m[2] -= rhs.m[2];
        m[3] -= rhs.m[3];
        m[4] -= rhs.m[4];
        m[5] -= rhs.m[5];
        m[6] -= rhs.m[6];
        m[7] -= rhs.m[7];
        m[8] -= rhs.m[8];
        return *this;
    }
	
#pragma mark multiplication
	
    qMatrix3_T operator*(const T f) const
    {
        qMatrix3_T temp;
        temp.m[0] = m[0] * f;
        temp.m[1] = m[1] * f;
        temp.m[2] = m[2] * f;
        temp.m[3] = m[3] * f;
        temp.m[4] = m[4] * f;
        temp.m[5] = m[5] * f;
        temp.m[6] = m[6] * f;
        temp.m[7] = m[7] * f;
        temp.m[8] = m[8] * f;
        return temp;
    }
	
    qVector3 operator*(const qVector3 &rhs) const
    {
        qVector3 out;
        out.x = (m00 * rhs.x) + (m10 * rhs.y) + (m20 * rhs.z);
        out.y = (m01 * rhs.x) + (m11 * rhs.y) + (m21 * rhs.z);
        out.z = (m02 * rhs.x) + (m12 * rhs.y) + (m22 * rhs.z);
        return out;
    }
	
    qMatrix3_T operator*(const qMatrix3_T &rhs) const
    {
        qMatrix3_T out;
		
        out.m00 = (m00 * rhs.m00) + (m10 * rhs.m01) + (m20 * rhs.m02);
        out.m01 = (m01 * rhs.m00) + (m11 * rhs.m01) + (m21 * rhs.m02);
        out.m02 = (m02 * rhs.m00) + (m12 * rhs.m01) + (m22 * rhs.m02);
		
        out.m10 = (m00 * rhs.m10) + (m10 * rhs.m11) + (m20 * rhs.m12);
        out.m11 = (m01 * rhs.m10) + (m11 * rhs.m11) + (m21 * rhs.m12);
        out.m12 = (m02 * rhs.m10) + (m12 * rhs.m11) + (m22 * rhs.m12);
		
        out.m20 = (m00 * rhs.m20) + (m10 * rhs.m21) + (m20 * rhs.m22);
        out.m21 = (m01 * rhs.m20) + (m11 * rhs.m21) + (m21 * rhs.m22);
        out.m22 = (m02 * rhs.m20) + (m12 * rhs.m21) + (m22 * rhs.m22);
		
        return out;
    }
	
    qMatrix3_T& operator*=(const T f)
    {
        m[0] *= f;
        m[1] *= f;
        m[2] *= f;
        m[3] *= f;
        m[4] *= f;
        m[5] *= f;
        m[6] *= f;
        m[7] *= f;
        m[8] *= f;
        return *this;
    }
	
    qMatrix3_T& operator*=(const qMatrix3_T &rhs)
    {
        qMatrix3_T out;
		
        out.m00 = (m00 * rhs.m00) + (m10 * rhs.m01) + (m20 * rhs.m02);
        out.m01 = (m01 * rhs.m00) + (m11 * rhs.m01) + (m21 * rhs.m02);
        out.m02 = (m02 * rhs.m00) + (m12 * rhs.m01) + (m22 * rhs.m02);
		
        out.m10 = (m00 * rhs.m10) + (m10 * rhs.m11) + (m20 * rhs.m12);
        out.m11 = (m01 * rhs.m10) + (m11 * rhs.m11) + (m21 * rhs.m12);
        out.m12 = (m02 * rhs.m10) + (m12 * rhs.m11) + (m22 * rhs.m12);
		
        out.m20 = (m00 * rhs.m20) + (m10 * rhs.m21) + (m20 * rhs.m22);
        out.m21 = (m01 * rhs.m20) + (m11 * rhs.m21) + (m21 * rhs.m22);
        out.m22 = (m02 * rhs.m20) + (m12 * rhs.m21) + (m22 * rhs.m22);
		
        (*this) = out;
        return *this;
    }
	
#pragma mark division
	
    qMatrix3_T operator/(const T f) const
    {
        qMatrix3_T temp;
        qASSERT(f != T(0));
        temp.m[0] = m[0] / f;
        temp.m[1] = m[1] / f;
        temp.m[2] = m[2] / f;
        temp.m[3] = m[3] / f;
        temp.m[4] = m[4] / f;
        temp.m[5] = m[5] / f;
        temp.m[6] = m[6] / f;
        temp.m[7] = m[7] / f;
        temp.m[8] = m[8] / f;
        return temp;
    }
	
    qMatrix3_T operator/(const qMatrix3_T &rhs) const
    {
        qMatrix3_T temp;
        qASSERT(rhs.m[0] != T(0));
        qASSERT(rhs.m[1] != T(0));
        qASSERT(rhs.m[2] != T(0));
        qASSERT(rhs.m[3] != T(0));
        qASSERT(rhs.m[4] != T(0));
        qASSERT(rhs.m[5] != T(0));
        qASSERT(rhs.m[6] != T(0));
        qASSERT(rhs.m[7] != T(0));
        qASSERT(rhs.m[8] != T(0));
        temp.m[0] = m[0] / rhs.m[0];
        temp.m[1] = m[1] / rhs.m[1];
        temp.m[2] = m[2] / rhs.m[2];
        temp.m[3] = m[3] / rhs.m[3];
        temp.m[4] = m[4] / rhs.m[4];
        temp.m[5] = m[5] / rhs.m[5];
        temp.m[6] = m[6] / rhs.m[6];
        temp.m[7] = m[7] / rhs.m[7];
        temp.m[8] = m[8] / rhs.m[8];
        return temp;
    }
	
    qMatrix3_T& operator/=(const T f)
    {
        qASSERT(f != T(0));
        m[0] /= f;
        m[1] /= f;
        m[2] /= f;
        m[3] /= f;
        m[4] /= f;
        m[5] /= f;
        m[6] /= f;
        m[7] /= f;
        m[8] /= f;
        return *this;
    }
	
    qMatrix3_T& operator/=(const qMatrix3_T &rhs)
    {
        qASSERT(rhs.m[0] != T(0));
        qASSERT(rhs.m[1] != T(0));
        qASSERT(rhs.m[2] != T(0));
        qASSERT(rhs.m[3] != T(0));
        qASSERT(rhs.m[4] != T(0));
        qASSERT(rhs.m[5] != T(0));
        qASSERT(rhs.m[6] != T(0));
        qASSERT(rhs.m[7] != T(0));
        qASSERT(rhs.m[8] != T(0));
        m[0] /= rhs.m[0];
        m[1] /= rhs.m[1];
        m[2] /= rhs.m[2];
        m[3] /= rhs.m[3];
        m[4] /= rhs.m[4];
        m[5] /= rhs.m[5];
        m[6] /= rhs.m[6];
        m[7] /= rhs.m[7];
        m[8] /= rhs.m[8];
        return *this;
    }
	
#pragma mark util
	
    static qMatrix3_T RotateAroundX(T angle)
    {
        qMatrix3_T rotMat;
        rotMat.m11 = cos(angle);
        rotMat.m21 = -sin(angle);
        rotMat.m12 = sin(angle);
        rotMat.m22 = cos(angle);
        return rotMat;
    }
	
    static qMatrix3_T RotateAroundY(T angle)
    {
        qMatrix3_T rotMat;
        rotMat.m00 = cos(angle);
        rotMat.m20 = -sin(angle);
        rotMat.m02 = sin(angle);
        rotMat.m22 = cos(angle);
        return rotMat;
    }
	
    static qMatrix3_T RotateAroundZ(T angle)
    {
        qMatrix3_T rotMat;
        rotMat.m00 = cos(angle);
        rotMat.m10 = -sin(angle);
        rotMat.m01 = sin(angle);
        rotMat.m11 = cos(angle);
        return rotMat;
    }
	
    static qMatrix3_T Scale(qVector3 scale)
    {
        qMatrix3_T scaleMat;
        scaleMat.m00 = scale.x;
        scaleMat.m11 = scale.y;
        scaleMat.m22 = scale.z;
        return scaleMat;
    }
	
    void Transpose()
    {
        qMatrix3_T copy = *this;
        for(int x = 0; x < 3; ++ x)
        {
            for(int y = 0; y < 3; ++ y)
            {
                mm[x][y] = copy.mm[y][x];
            }
        }
    }

};

typedef qMatrix3_T<double> qMatrix3d;
typedef qMatrix3_T<float> qMatrix3;
typedef qMatrix3_T<half> qMatrix3h;

const qMatrix3 qMatrix3_Identity;

#endif // __Q_MATRIX3_H__

