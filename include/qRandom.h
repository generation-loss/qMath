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

template<class T>
qRGBA<T> qRandom(const qRGBA<T> min, const qRGBA<T> max)
{
    qRGBA<T> temp;
    temp.r = qRandom(min.r, max.r);
    temp.g = qRandom(min.g, max.g);
    temp.b = qRandom(min.b, max.b);
    temp.a = qRandom(min.a, max.a);
    return temp;
}

qVector2 qRandom(const qVector2 min, const qVector2 max);
qVector3 qRandom(const qVector3 min, const qVector3 max);
qVector4 qRandom(const qVector4 min, const qVector4 max);

float qRandomGaussian(const float mean, const float stdDev);

int qRandomInt(const int count);

bool qRandomBool();

template <class TYPE>
TYPE qPick(const TYPE* list, const int listLength)
{
    return list[qRandomInt(listLength)];
}

#endif //__Q_RANDOM_H__

