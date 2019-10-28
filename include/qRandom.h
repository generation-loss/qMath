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

#ifndef __Q_RANDOM_H__
#define __Q_RANDOM_H__

#include "qVector2.h"
#include "qVector3.h"
#include "qVector4.h"
#include "qRGBA.h"

void qSeedRandom(int seed = 0);

NSUInteger qRandom(const NSUInteger max);
NSUInteger qRandom(const NSUInteger min, const NSUInteger max);

template<class T>
T qRandom(const T max)
{
	float rand01 = float(rand()) / float(RAND_MAX);
	T result = float(max) * rand01;
    return T(result);
}

template<class T>
T qRandom(const T min, const T max)
{
	qASSERT(max >= min);
	T offset = qRandom<T>(max - min);
	return min + offset;
}

template<typename T, int ALIGN>
qVector2_T<T, ALIGN> qRandom(const qVector2_T<T, ALIGN> min, const qVector2_T<T, ALIGN> max)
{
    qVector2_T<T, ALIGN> result;
    result.x = qRandom(min.x, max.x);
    result.y = qRandom(min.y, max.y);
    return result;
}

template<typename T, int ALIGN>
qVector3_T<T, ALIGN> qRandom(const qVector3_T<T, ALIGN> min, const qVector3_T<T, ALIGN> max)
{
    qVector3_T<T, ALIGN> result;
    result.x = qRandom(min.x, max.x);
    result.y = qRandom(min.y, max.y);
    result.z = qRandom(min.z, max.z);
    return result;
}

template<typename T, int ALIGN>
qVector4_T<T, ALIGN> qRandom(const qVector4_T<T, ALIGN> min, const qVector4_T<T, ALIGN> max)
{
    qVector4_T<T, ALIGN> result;
	result.x = qRandom(min.x, max.x);
	result.y = qRandom(min.y, max.y);
	result.z = qRandom(min.z, max.z);
	result.w = qRandom(min.w, max.w);
    return result;
}

template<class T>
qRGBA<T> qRandom(const qRGBA<T> min, const qRGBA<T> max)
{
    qRGBA<T> result;
    result.r = qRandom(min.r, max.r);
    result.g = qRandom(min.g, max.g);
    result.b = qRandom(min.b, max.b);
    result.a = qRandom(min.a, max.a);
    return result;
}

float qRandomGaussian(const float mean, const float stdDev);

int qRandomInt(const int count);

bool qRandomBool();

template <class TYPE>
TYPE qPick(const TYPE* list, const int listLength)
{
    return list[qRandomInt(listLength)];
}

#endif //__Q_RANDOM_H__

