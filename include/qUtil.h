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

#ifndef __Q_UTIL_H__
#define __Q_UTIL_H__

#import "math.h"

typedef unsigned int qHashType;
qHashType qHash(const char *key, unsigned int len);
qHashType qHash(const char *key);

unsigned int qPowerOfTwo(unsigned int val);
bool qIsPowerOfTwo(unsigned int val);

template <class TYPE>
TYPE qMax(const TYPE a, const TYPE b)
{
    return (a > b) ? a : b;
}

template <class TYPE>
TYPE qMin(const TYPE a, const TYPE b)
{
    return (a < b) ? a : b;
}

template <class TYPE>
TYPE qAbs(const TYPE a)
{
    return (a < TYPE(0)) ? -a : a;
}

template <class TYPE>
TYPE qClamp(const TYPE a, const TYPE min, const TYPE max)
{
    return qMax(min, qMin(a, max ));
}

template <class TYPE>
TYPE qSaturate(const TYPE a)
{
    return qMax(TYPE(0), qMin(a, TYPE(1) ));
}

template <class TYPE>
TYPE qStep(const TYPE a, const TYPE b)
{
    return a < b ? TYPE(0) : TYPE(1);
}

template <class TYPE>
TYPE qLerp(const TYPE min, const TYPE max, const float t)
{
    return min + ((max - min) * t);
}

template <class TYPE>
TYPE qLerpClamp(const TYPE min, const TYPE max, const float t)
{
    return qClamp(min + ((max - min) * t), min, max);
}

template <class TYPE>
TYPE qDegToRad(const TYPE a)
{
    return a * TYPE(3.141592653589793 / 180.0);
}

template <class TYPE>
TYPE qRadToDeg(const TYPE a)
{
    return a * TYPE(180.0 / 3.141592653589793);
}

float qFloor(const float a);
float qCeil(const float a);
float qRound(const float a);

#endif //__Q_UTIL_H__

