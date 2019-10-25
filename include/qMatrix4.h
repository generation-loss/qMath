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

#ifndef __Q_MATRIX4_H__
#define __Q_MATRIX4_H__

#include <math.h>
#include "qVector3.h"
#include "qVector4.h"
#include "qCore.h"

/*
 column major
 [ m00 m10 m20 m30 ]
 [ m01 m11 m21 m31 ]
 [ m02 m12 m22 m32 ]
 [ m03 m13 m23 m33 ]
*/

template<typename T>
class qMatrix4_T
{
public:
    
    union
    {
        struct
        {              
            float m00;
            float m01;
            float m02;
            float m03;
            float m10;
            float m11;
            float m12;
            float m13;
            float m20;
            float m21;
            float m22;
            float m23;
            float m30;
            float m31;
            float m32;
            float m33;
        };
        float m[16];
        float mm[4][4];
    };
    
    qMatrix4_T()
    : m00(T(1))
    , m01(T(0))
    , m02(T(0))
    , m03(T(0))
    , m10(T(0))
    , m11(T(1))
    , m12(T(0))
    , m13(T(0))
    , m20(T(0))
    , m21(T(0))
    , m22(T(1))
    , m23(T(0))
    , m30(T(0))
    , m31(T(0))
    , m32(T(0))
    , m33(T(1))
    {
    }
    
    qMatrix4_T(const qMatrix4_T &mat)
    : m00(mat.m00)
    , m01(mat.m01)
    , m02(mat.m02)
    , m03(mat.m03)
    , m10(mat.m10)
    , m11(mat.m11)
    , m12(mat.m12)
    , m13(mat.m13)
    , m20(mat.m20)
    , m21(mat.m21)
    , m22(mat.m22)
    , m23(mat.m23)
    , m30(mat.m30)
    , m31(mat.m31)
    , m32(mat.m32)
    , m33(mat.m33)
    {}
	
    qMatrix4_T(const float _m00, const float _m01, const float _m02, const float _m03,
              const float _m10, const float _m11, const float _m12, const float _m13,
              const float _m20, const float _m21, const float _m22, const float _m23,
              const float _m30, const float _m31, const float _m32, const float _m33)
    : m00(_m00)
    , m01(_m01)
    , m02(_m02)
    , m03(_m03)
    , m10(_m10)
    , m11(_m11)
    , m12(_m12)
    , m13(_m13)
    , m20(_m20)
    , m21(_m21)
    , m22(_m22)
    , m23(_m23)
    , m30(_m30)
    , m31(_m31)
    , m32(_m32)
    , m33(_m33)
    {}
    
#pragma mark getters
    
    float& operator[](int pos)
    {
        return m[pos];
    }
    
    float operator[](int pos) const
    {
        return m[pos];
    }
    
#pragma mark assignment
    
    qMatrix4_T& operator=(const qMatrix4_T &rhs)
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
        m[9] = rhs.m[9];
        m[10] = rhs.m[10];
        m[11] = rhs.m[11];
        m[12] = rhs.m[12];
        m[13] = rhs.m[13];
        m[14] = rhs.m[14];
        m[15] = rhs.m[15];
        return *this;
    }
    
#pragma mark addition
    
    qMatrix4_T operator+(const float f) const
    { 
        qMatrix4_T temp;
        temp.m[0] = m[0] + f;
        temp.m[1] = m[1] + f;
        temp.m[2] = m[2] + f;
        temp.m[3] = m[3] + f;
        temp.m[4] = m[4] + f;
        temp.m[5] = m[5] + f;
        temp.m[6] = m[6] + f;
        temp.m[7] = m[7] + f;
        temp.m[8] = m[8] + f;
        temp.m[9] = m[9] + f;
        temp.m[10] = m[10] + f;
        temp.m[11] = m[11] + f;
        temp.m[12] = m[12] + f;
        temp.m[13] = m[13] + f;
        temp.m[14] = m[14] + f;
        temp.m[15] = m[15] + f;
        return temp;
    }
    
    qMatrix4_T operator+(const qMatrix4_T &rhs) const
    { 
        qMatrix4_T temp;
        temp.m[0] = m[0] + rhs.m[0];
        temp.m[1] = m[1] + rhs.m[1];
        temp.m[2] = m[2] + rhs.m[2];
        temp.m[3] = m[3] + rhs.m[3];
        temp.m[4] = m[4] + rhs.m[4];
        temp.m[5] = m[5] + rhs.m[5];
        temp.m[6] = m[6] + rhs.m[6];
        temp.m[7] = m[7] + rhs.m[7];
        temp.m[8] = m[8] + rhs.m[8];
        temp.m[9] = m[9] + rhs.m[9];
        temp.m[10] = m[10] + rhs.m[10];
        temp.m[11] = m[11] + rhs.m[11];
        temp.m[12] = m[12] + rhs.m[12];
        temp.m[13] = m[13] + rhs.m[13];
        temp.m[14] = m[14] + rhs.m[14];
        temp.m[15] = m[15] + rhs.m[15];
        return temp;
    }
    
    qMatrix4_T& operator+=(const float f)
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
        m[9] += f;
        m[10] += f;
        m[11] += f;
        m[12] += f;
        m[13] += f;
        m[14] += f;
        m[15] += f;
        return *this;
    }
    
    qMatrix4_T& operator+=(const qMatrix4_T &rhs)
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
        m[9] += rhs.m[9];
        m[10] += rhs.m[10];
        m[11] += rhs.m[11];
        m[12] += rhs.m[12];
        m[13] += rhs.m[13];
        m[14] += rhs.m[14];
        m[15] += rhs.m[15];
        return *this;
    }
    
#pragma mark subtraction
    
    qMatrix4_T operator-(const float f) const
    { 
        qMatrix4_T temp;
        temp.m[0] = m[0] - f;
        temp.m[1] = m[1] - f;
        temp.m[2] = m[2] - f;
        temp.m[3] = m[3] - f;
        temp.m[4] = m[4] - f;
        temp.m[5] = m[5] - f;
        temp.m[6] = m[6] - f;
        temp.m[7] = m[7] - f;
        temp.m[8] = m[8] - f;
        temp.m[9] = m[9] - f;
        temp.m[10] = m[10] - f;
        temp.m[11] = m[11] - f;
        temp.m[12] = m[12] - f;
        temp.m[13] = m[13] - f;
        temp.m[14] = m[14] - f;
        temp.m[15] = m[15] - f;
        return temp;
    }
    
    qMatrix4_T operator-(const qMatrix4_T &rhs) const
    { 
        qMatrix4_T temp;
        temp.m[0] = m[0] - rhs.m[0];
        temp.m[1] = m[1] - rhs.m[1];
        temp.m[2] = m[2] - rhs.m[2];
        temp.m[3] = m[3] - rhs.m[3];
        temp.m[4] = m[4] - rhs.m[4];
        temp.m[5] = m[5] - rhs.m[5];
        temp.m[6] = m[6] - rhs.m[6];
        temp.m[7] = m[7] - rhs.m[7];
        temp.m[8] = m[8] - rhs.m[8];
        temp.m[9] = m[9] - rhs.m[9];
        temp.m[10] = m[10] - rhs.m[10];
        temp.m[11] = m[11] - rhs.m[11];
        temp.m[12] = m[12] - rhs.m[12];
        temp.m[13] = m[13] - rhs.m[13];
        temp.m[14] = m[14] - rhs.m[14];
        temp.m[15] = m[15] - rhs.m[15];
        return temp;
    }
    
    qMatrix4_T& operator-=(const float f)
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
        m[9] -= f;
        m[10] -= f;
        m[11] -= f;
        m[12] -= f;
        m[13] -= f;
        m[14] -= f;
        m[15] -= f;
        return *this;
    }
    
    qMatrix4_T& operator-=(const qMatrix4_T &rhs)
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
        m[9] -= rhs.m[9];
        m[10] -= rhs.m[10];
        m[11] -= rhs.m[11];
        m[12] -= rhs.m[12];
        m[13] -= rhs.m[13];
        m[14] -= rhs.m[14];
        m[15] -= rhs.m[15];
        return *this;
    }
    
#pragma mark multiplication
    
    qMatrix4_T operator*(const float f) const
    { 
        qMatrix4_T temp;
        temp.m[0] = m[0] * f;
        temp.m[1] = m[1] * f;
        temp.m[2] = m[2] * f;
        temp.m[3] = m[3] * f;
        temp.m[4] = m[4] * f;
        temp.m[5] = m[5] * f;
        temp.m[6] = m[6] * f;
        temp.m[7] = m[7] * f;
        temp.m[8] = m[8] * f;
        temp.m[9] = m[9] * f;
        temp.m[10] = m[10] * f;
        temp.m[11] = m[11] * f;
        temp.m[12] = m[12] * f;
        temp.m[13] = m[13] * f;
        temp.m[14] = m[14] * f;
        temp.m[15] = m[15] * f;
        return temp;
    }
    
    qVector4 operator*(const qVector4 &rhs) const
    {
        qVector4 out;    
        out.x = (m00 * rhs.x) + (m10 * rhs.y) + (m20 * rhs.z) + (m30 * rhs.w);
        out.y = (m01 * rhs.x) + (m11 * rhs.y) + (m21 * rhs.z) + (m31 * rhs.w);
        out.z = (m02 * rhs.x) + (m12 * rhs.y) + (m22 * rhs.z) + (m32 * rhs.w);
        out.w = (m03 * rhs.x) + (m13 * rhs.y) + (m23 * rhs.z) + (m33 * rhs.w);
        return out;
    }
    
    qMatrix4_T operator*(const qMatrix4_T &rhs) const
    { 
        qMatrix4_T out;
		
        out.m00 = (m00 * rhs.m00) + (m10 * rhs.m01) + (m20 * rhs.m02) + (m30 * rhs.m03);
        out.m01 = (m01 * rhs.m00) + (m11 * rhs.m01) + (m21 * rhs.m02) + (m31 * rhs.m03);
        out.m02 = (m02 * rhs.m00) + (m12 * rhs.m01) + (m22 * rhs.m02) + (m32 * rhs.m03);
        out.m03 = (m03 * rhs.m00) + (m13 * rhs.m01) + (m23 * rhs.m02) + (m33 * rhs.m03);
		
        out.m10 = (m00 * rhs.m10) + (m10 * rhs.m11) + (m20 * rhs.m12) + (m30 * rhs.m13);
        out.m11 = (m01 * rhs.m10) + (m11 * rhs.m11) + (m21 * rhs.m12) + (m31 * rhs.m13);
        out.m12 = (m02 * rhs.m10) + (m12 * rhs.m11) + (m22 * rhs.m12) + (m32 * rhs.m13);
        out.m13 = (m03 * rhs.m10) + (m13 * rhs.m11) + (m23 * rhs.m12) + (m33 * rhs.m13);
		
        out.m20 = (m00 * rhs.m20) + (m10 * rhs.m21) + (m20 * rhs.m22) + (m30 * rhs.m23);
        out.m21 = (m01 * rhs.m20) + (m11 * rhs.m21) + (m21 * rhs.m22) + (m31 * rhs.m23);
        out.m22 = (m02 * rhs.m20) + (m12 * rhs.m21) + (m22 * rhs.m22) + (m32 * rhs.m23);
        out.m23 = (m03 * rhs.m20) + (m13 * rhs.m21) + (m23 * rhs.m22) + (m33 * rhs.m23);
		
        out.m30 = (m00 * rhs.m30) + (m10 * rhs.m31) + (m20 * rhs.m32) + (m30 * rhs.m33);
        out.m31 = (m01 * rhs.m30) + (m11 * rhs.m31) + (m21 * rhs.m32) + (m31 * rhs.m33);
        out.m32 = (m02 * rhs.m30) + (m12 * rhs.m31) + (m22 * rhs.m32) + (m32 * rhs.m33);
        out.m33 = (m03 * rhs.m30) + (m13 * rhs.m31) + (m23 * rhs.m32) + (m33 * rhs.m33);
		
        return out;
    }
    
    qMatrix4_T& operator*=(const float f)
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
        m[9] *= f;
        m[10] *= f;
        m[11] *= f;
        m[12] *= f;
        m[13] *= f;
        m[14] *= f;
        m[15] *= f;
        return *this;
    }
    
    qMatrix4_T& operator*=(const qMatrix4_T &rhs)
    {
        qMatrix4_T out;

        out.m00 = (m00 * rhs.m00) + (m10 * rhs.m01) + (m20 * rhs.m02) + (m30 * rhs.m03);
        out.m01 = (m01 * rhs.m00) + (m11 * rhs.m01) + (m21 * rhs.m02) + (m31 * rhs.m03);
        out.m02 = (m02 * rhs.m00) + (m12 * rhs.m01) + (m22 * rhs.m02) + (m32 * rhs.m03);
        out.m03 = (m03 * rhs.m00) + (m13 * rhs.m01) + (m23 * rhs.m02) + (m33 * rhs.m03);

        out.m10 = (m00 * rhs.m10) + (m10 * rhs.m11) + (m20 * rhs.m12) + (m30 * rhs.m13);
        out.m11 = (m01 * rhs.m10) + (m11 * rhs.m11) + (m21 * rhs.m12) + (m31 * rhs.m13);
        out.m12 = (m02 * rhs.m10) + (m12 * rhs.m11) + (m22 * rhs.m12) + (m32 * rhs.m13);
        out.m13 = (m03 * rhs.m10) + (m13 * rhs.m11) + (m23 * rhs.m12) + (m33 * rhs.m13);

        out.m20 = (m00 * rhs.m20) + (m10 * rhs.m21) + (m20 * rhs.m22) + (m30 * rhs.m23);
        out.m21 = (m01 * rhs.m20) + (m11 * rhs.m21) + (m21 * rhs.m22) + (m31 * rhs.m23);
        out.m22 = (m02 * rhs.m20) + (m12 * rhs.m21) + (m22 * rhs.m22) + (m32 * rhs.m23);
        out.m23 = (m03 * rhs.m20) + (m13 * rhs.m21) + (m23 * rhs.m22) + (m33 * rhs.m23);

        out.m30 = (m00 * rhs.m30) + (m10 * rhs.m31) + (m20 * rhs.m32) + (m30 * rhs.m33);
        out.m31 = (m01 * rhs.m30) + (m11 * rhs.m31) + (m21 * rhs.m32) + (m31 * rhs.m33);
        out.m32 = (m02 * rhs.m30) + (m12 * rhs.m31) + (m22 * rhs.m32) + (m32 * rhs.m33);
        out.m33 = (m03 * rhs.m30) + (m13 * rhs.m31) + (m23 * rhs.m32) + (m33 * rhs.m33);

        (*this) = out;
        return *this;
    }
	
#pragma mark division
    
    qMatrix4_T operator/(const float f) const
    { 
        qMatrix4_T temp;
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
        temp.m[9] = m[9] / f;
        temp.m[10] = m[10] / f;
        temp.m[11] = m[11] / f;
        temp.m[12] = m[12] / f;
        temp.m[13] = m[13] / f;
        temp.m[14] = m[14] / f;
        temp.m[15] = m[15] / f;
        return temp;
    }
    
    qMatrix4_T operator/(const qMatrix4_T &rhs) const
    { 
        qMatrix4_T temp;
        qASSERT(rhs.m[0] != T(0));
        qASSERT(rhs.m[1] != T(0));
        qASSERT(rhs.m[2] != T(0));
        qASSERT(rhs.m[3] != T(0));
        qASSERT(rhs.m[4] != T(0));
        qASSERT(rhs.m[5] != T(0));
        qASSERT(rhs.m[6] != T(0));
        qASSERT(rhs.m[7] != T(0));
        qASSERT(rhs.m[8] != T(0));
        qASSERT(rhs.m[9] != T(0));
        qASSERT(rhs.m[10] != T(0));
        qASSERT(rhs.m[11] != T(0));
        qASSERT(rhs.m[12] != T(0));
        qASSERT(rhs.m[13] != T(0));
        qASSERT(rhs.m[14] != T(0));
        qASSERT(rhs.m[15] != T(0));
        temp.m[0] = m[0] / rhs.m[0];
        temp.m[1] = m[1] / rhs.m[1];
        temp.m[2] = m[2] / rhs.m[2];
        temp.m[3] = m[3] / rhs.m[3];
        temp.m[4] = m[4] / rhs.m[4];
        temp.m[5] = m[5] / rhs.m[5];
        temp.m[6] = m[6] / rhs.m[6];
        temp.m[7] = m[7] / rhs.m[7];
        temp.m[8] = m[8] / rhs.m[8];
        temp.m[9] = m[9] / rhs.m[9];
        temp.m[10] = m[10] / rhs.m[10];
        temp.m[11] = m[11] / rhs.m[11];
        temp.m[12] = m[12] / rhs.m[12];
        temp.m[13] = m[13] / rhs.m[13];
        temp.m[14] = m[14] / rhs.m[14];
        temp.m[15] = m[15] / rhs.m[15];
        return temp;
    }
    
    qMatrix4_T& operator/=(const float f)
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
        m[9] /= f;
        m[10] /= f;
        m[11] /= f;
        m[12] /= f;
        m[13] /= f;
        m[14] /= f;
        m[15] /= f;
        return *this;
    }
    
    qMatrix4_T& operator/=(const qMatrix4_T &rhs)
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
        qASSERT(rhs.m[9] != T(0));
        qASSERT(rhs.m[10] != T(0));
        qASSERT(rhs.m[11] != T(0));
        qASSERT(rhs.m[12] != T(0));
        qASSERT(rhs.m[13] != T(0));
        qASSERT(rhs.m[14] != T(0));
        qASSERT(rhs.m[15] != T(0));
        m[0] /= rhs.m[0];
        m[1] /= rhs.m[1];
        m[2] /= rhs.m[2];
        m[3] /= rhs.m[3];
        m[4] /= rhs.m[4];
        m[5] /= rhs.m[5];
        m[6] /= rhs.m[6];
        m[7] /= rhs.m[7];
        m[8] /= rhs.m[8];
        m[9] /= rhs.m[9];
        m[10] /= rhs.m[10];
        m[11] /= rhs.m[11];
        m[12] /= rhs.m[12];
        m[13] /= rhs.m[13];
        m[14] /= rhs.m[14];
        m[15] /= rhs.m[15];
        return *this;
    }
    
#pragma mark util
    
    static qMatrix4_T RotateAroundX(float angle)
    {
        qMatrix4_T rotMat;
        rotMat.m11 = cos(angle);
        rotMat.m21 = -sin(angle);
        rotMat.m12 = sin(angle);
        rotMat.m22 = cos(angle);
        return rotMat;
    }
    
    static qMatrix4_T RotateAroundY(float angle)
    {
        qMatrix4_T rotMat;
        rotMat.m00 = cos(angle);
        rotMat.m20 = -sin(angle);
        rotMat.m02 = sin(angle);
        rotMat.m22 = cos(angle);
        return rotMat;
    }
    
    static qMatrix4_T RotateAroundZ(float angle)
    {
        qMatrix4_T rotMat;
        rotMat.m00 = cos(angle);
        rotMat.m10 = -sin(angle);
        rotMat.m01 = sin(angle);
        rotMat.m11 = cos(angle);
        return rotMat;
    }
    
    static qMatrix4_T Translate(qVector3 translate)
    {
        qMatrix4_T transMat;
        transMat.m30 = translate.x;
        transMat.m31 = translate.y;
        transMat.m32 = translate.z;
        return transMat;
    }
    
    static qMatrix4_T Scale(qVector3 scale)
    {
        qMatrix4_T scaleMat;
        scaleMat.m00 = scale.x;
        scaleMat.m11 = scale.y;
        scaleMat.m22 = scale.z;   
        return scaleMat;
    }
    
    void Transpose()
    {
        qMatrix4_T copy = *this;
        for(int x = 0; x < 4; ++ x)
        {
            for(int y = 0; y < 4; ++ y)
            {
                mm[x][y] = copy.mm[y][x];
            }
        }
    }

};

typedef qMatrix4_T<float> qMatrix4;
typedef qMatrix4_T<half> qMatrix4h;

const qMatrix4 qMatrix4_Identity;

#endif // __Q_MATRIX4_H__
