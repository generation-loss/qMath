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

#ifndef __Q_RANGE_H__
#define __Q_RANGE_H__

#include "qRandom.h"
#include <iostream>

template<typename T>
struct qRange
{
	enum SampleMode
	{
		eSampleMode_Uniform,
		eSampleMode_Gaussian,
	};
	
    T min;
    T max;
	SampleMode sampleMode;
	
    qRange()
	: min(T(0))
	, max(T(0))
	, sampleMode(eSampleMode_Uniform)
    {
    }
	
	qRange(const T _val, const SampleMode _sampleMode = eSampleMode_Uniform)
	: min(_val)
	, max(_val)
	, sampleMode(_sampleMode)
	{
	}
    
    qRange(const T _min, const T _max, const SampleMode _sampleMode = eSampleMode_Uniform)
    : min(_min)
    , max(_max)
	, sampleMode(_sampleMode)
    {
    }

    T RandomInRange() const
    {
		switch(sampleMode)
		{
			case eSampleMode_Uniform:
				return qRandom(min, max);
			case eSampleMode_Gaussian:
				while(true)
				{
					T candidate = qRandom(T(0), T(1));
					T gaussian = exp(-(candidate-T(0.5))*(candidate-T(0.5))/0.045);
					if (qRandom(T(0), T(1)) < gaussian)
					{
						return candidate * (max - min) + min;
					}
				}
		}
    }
	
	T Median() const
	{
		return (min + max) / T(2);
	}
	
	bool Contains(T _val) const
	{
		return (_val >= min) && (_val <= max);
	}
	
	friend std::ostream& operator<<(std::ostream& out, const qRange<T>& range)
	{
		out << "min: " << range.min << " max: " << range.max;
		return out;
	}
	
	qRange operator*(const qRange &rhs) const
	{
		qRange temp;
		temp.min = min * rhs.min;
		temp.max = max * rhs.max;
		return temp;
	}
};

typedef qRange<float> qRangeF;
typedef qRange<int> qRangeI;

namespace qJSON
{
	qRangeF RangeF(NSDictionary* JSON, NSString* key, qRangeF defaultValue = qRangeF(0.0f, 1.0f));
	qRangeI RangeI(NSDictionary* JSON, NSString* key, qRangeI defaultValue = qRangeI(0, 1));

	qRangeF RangeF(NSArray* array, qRangeF defaultValue = qRangeF(0.0f, 1.0f));
	qRangeI RangeI(NSArray* array, qRangeI defaultValue = qRangeI(0, 1));
}

#endif //__Q_RANGE_H__

