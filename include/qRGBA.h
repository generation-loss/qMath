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

#ifndef __Q_RGBA_H__
#define __Q_RGBA_H__

#include <math.h>
#include "qUtil.h"
#include "qCore.h"
#include <iostream>

template<typename T>
class qRGBA
{
public:
    
    union
    {
        struct
        {              
            T r;
            T g;
            T b;
            T a;
		} __attribute__ ((aligned (4)));
        T rgba[4];
    };
    
    qRGBA(T _r, T _g, T _b, T _a)
	: r(_r)
	, g(_g)
	, b(_b)
	, a(_a)
	{}

    qRGBA(T _r, T _g, T _b)
	: r(_r)
	, g(_g)
	, b(_b)
	, a(T(1))
	{}
	
    qRGBA(T grayscale, T _a)
	: r(grayscale)
	, g(grayscale)
	, b(grayscale)
	, a(_a)
	{}
	
    qRGBA(T grayscale)
	: r(grayscale)
	, g(grayscale)
	, b(grayscale)
	, a(T(1))
	{}
    
    qRGBA()
	: r(T(0))
	, g(T(0))
	, b(T(0))
	, a(T(0))
	{}

#pragma mark getters
    
    T& operator[](int pos)
    {
		return rgba[pos];
	}
	
    T operator[](int pos) const
    {
		return rgba[pos];
	}
    
#pragma mark assignment
    
    qRGBA& operator=(const qRGBA &rhs)
	{
		r = rhs.r;
		g = rhs.g;
		b = rhs.b;
		a = rhs.a;
		return *this;
	}
    
#pragma mark comparison
    
    bool operator==(const qRGBA &rhs) const
	{
		return ((r == rhs.r) && (g == rhs.g) && (b == rhs.b) && (a == rhs.a));
	}
	
    bool operator!=(const qRGBA &rhs) const
	{
		return !(*this == rhs);
	}
    
#pragma mark addition
    
    qRGBA operator+(const T f) const
	{
		qRGBA temp;
		temp.r = r + f;
		temp.g = g + f;
		temp.b = b + f;
		temp.a = a + f;
		return temp;
	}
	
    qRGBA operator+(const qRGBA &rhs) const
	{
		qRGBA temp;
		temp.r = r + rhs.r;
		temp.g = g + rhs.g;
		temp.b = b + rhs.b;
		temp.a = a + rhs.a;
		return temp;
	}
	
    qRGBA& operator+=(const T f)
	{
		r += f;
		g += f;
		b += f;
		a += f;
		return *this;
	}
	
    qRGBA& operator+=(const qRGBA &rhs)
	{
		r += rhs.r;
		g += rhs.g;
		b += rhs.b;
		a += rhs.a;
		return *this;
	}
    
#pragma mark subtraction
    
    qRGBA operator-(const T f) const
	{
		qRGBA temp;
		temp.r = r - f;
		temp.g = g - f;
		temp.b = b - f;
		temp.a = a - f;
		return temp;
	}
	
    qRGBA operator-(const qRGBA &rhs) const
	{
		qRGBA temp;
		temp.r = r - rhs.r;
		temp.g = g - rhs.g;
		temp.b = b - rhs.b;
		temp.a = a - rhs.a;
		return temp;
	}
	
    qRGBA& operator-=(const T f)
	{
		r -= f;
		g -= f;
		b -= f;
		a -= f;
		return *this;
	}
	
    qRGBA& operator-=(const qRGBA &rhs)
	{
		r -= rhs.r;
		g -= rhs.g;
		b -= rhs.b;
		a -= rhs.a;
		return *this;
	}
    
#pragma mark multiplication
    
    qRGBA operator*(const T f) const
	{
		qRGBA temp;
		temp.r = r * f;
		temp.g = g * f;
		temp.b = b * f;
		temp.a = a * f;
		return temp;
	}
	
    qRGBA operator*(const qRGBA &rhs) const
	{
		qRGBA temp;
		temp.r = r * rhs.r;
		temp.g = g * rhs.g;
		temp.b = b * rhs.b;
		temp.a = a * rhs.a;
		return temp;
	}
	
    qRGBA& operator*=(const T f)
	{
		r *= f;
		g *= f;
		b *= f;
		a *= f;
		return *this;
	}
	
    qRGBA& operator*=(const qRGBA &rhs)
	{
		r *= rhs.r;
		g *= rhs.g;
		b *= rhs.b;
		a *= rhs.a;
		return *this;
	}
    
#pragma mark division
    
    qRGBA operator/(const T f) const
	{
		qRGBA temp;
		qASSERT(f != T(0));
		temp.r = r / f;
		temp.g = g / f;
		temp.b = b / f;
		temp.a = a / f;
		return temp;
	}
	
    qRGBA operator/(const qRGBA &rhs) const
	{
		qRGBA temp;
		qASSERT(rhs.r != T(0));
		temp.r = r / rhs.r;
		qASSERT(rhs.g != T(0));
		temp.g = g / rhs.g;
		qASSERT(rhs.b != T(0));
		temp.b = b / rhs.b;
		qASSERT(rhs.a != T(0));
		temp.a = a / rhs.a;
		return temp;
	}
	
    qRGBA& operator/=(const T f)
	{
		qASSERT(f != 0.0f);
		r /= f;
		g /= f;
		b /= f;
		a /= f;
		return *this;
	}
	
    qRGBA& operator/=(const qRGBA &rhs)
	{
		qASSERT(rhs.r != 0.0f);
		r /= rhs.r;
		qASSERT(rhs.g != 0.0f);
		g /= rhs.g;
		qASSERT(rhs.b != 0.0f);
		b /= rhs.b;
		qASSERT(rhs.a != 0.0f);
		a /= rhs.a;
		return *this;
	}
	
#pragma mark util
	
    qRGBA<T> Saturate()
    {
		return qRGBA<T>(qSaturate(r), qSaturate(g), qSaturate(b), qSaturate(a));
	}
	
	static qRGBA<T> FromKelvin(float kelvin)
	{
		float temp = kelvin / 100.0f;
		
		float rx = temp - 55.0f;
		float gxa = temp - 2.0f;
		float gxb = temp - 50.0f;
		float bx = temp - 10.0f;
		
		float r = (temp < 66.0f) ?
			1.0f :
			(351.97690566805693f + 0.114206453784165f * rx - 40.25366309332127f * logf(rx)) / 255.0f;
		float g = (temp < 66.0f) ?
			(-155.25485562709179f - 0.44596950469579133f * gxa + 104.49216199393888f * logf(gxa)) / 255.0f:
			(325.4494125711974f + 0.07943456536662342f * gxb - 28.0852963507957f * logf(gxb)) / 255.0f;
		float b = (temp > 66.0f) ?
			1.0f : ((temp < 19.0f) ? 0.0f :
			(-254.76935184120902f + 0.8274096064007395f * bx + 115.67994401066147 * logf(bx)) / 255.0f);
		
		qRGBA<T> result(r, g, b, 1);
		return result.Saturate();
	}
	
	friend std::ostream& operator<<(std::ostream& out, const qRGBA<T>& rgba)
	{
		out << "[" << rgba.r << ", " << rgba.b << ", " << rgba.b << ", " << rgba.a << "]";
		return out;
	}
	
} __attribute__ ((aligned (4)));

typedef qRGBA<uint8_t> qRGBA8;
typedef qRGBA<half> qRGBA16f;
typedef qRGBA<float> qRGBA32f;

const qRGBA<uint8_t> qRGBA8_Transparent(0, 0, 0, 0);
const qRGBA<uint8_t> qRGBA8_Black(0, 0, 0, 1);
const qRGBA<uint8_t> qRGBA8_White(255, 255, 255, 255);

const qRGBA<half> qRGBA32h_Transparent(0.0, 0.0, 0.0, 0.0);
const qRGBA<half> qRGBA32h_Black(0.0, 0.0, 0.0, 1.0);
const qRGBA<half> qRGBA32h_White(1.0, 1.0, 1.0, 1.0);

const qRGBA<float> qRGBA32f_Transparent(0.0f, 0.0f, 0.0f, 0.0f);
const qRGBA<float> qRGBA32f_Black(0.0f, 0.0f, 0.0f, 1.0f);
const qRGBA<float> qRGBA32f_White(1.0f, 1.0f, 1.0f, 1.0f);

#endif // __Q_RGBA_H__
