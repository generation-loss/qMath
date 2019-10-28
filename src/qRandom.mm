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

#include "qRandom.h"
#include "qCore.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

NSUInteger qRandom(const NSUInteger max)
{
	float rand01 = float(rand()) / float(RAND_MAX);
	float result = float(max) * rand01;
    return NSUInteger(result);
}

NSUInteger qRandom(const NSUInteger min, const NSUInteger max)
{
	qASSERT(max >= min);
	NSUInteger offset = qRandom(max - min);
	return min + offset;
}

void qSeedRandom(int seed)
{
	srand(seed == 0 ? (uint)time(NULL) : seed);
}

float qRandomGaussian(const float mean, const float stdDev)
{    
    const int iterations = 12;
    float sum = 0.0f;
    
    for(int i = 0; i < iterations; ++i)
    {
        sum += qRandom(2.0f / iterations);
    }
    
    sum -= 1.0f;
    
    return sum * stdDev * stdDev + mean;
}

int qRandomInt(const int count)
{
	return floor(qRandom((float)count));
}

bool qRandomBool()
{
	return qRandom(0.0f, 1.0f) < 0.5f;
}

