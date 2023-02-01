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

#include "qRange.h"

qRangeF qJSON::RangeF(NSDictionary* JSON, NSString* key, qRangeF defaultValue)
{
	qRangeF result = defaultValue;
	NSArray* rangeArray = [JSON objectForKey:key];
	if (rangeArray != nil)
	{
		NSNumber* lowRange = rangeArray[0];
		if (lowRange != nil)
		{
			result.min = lowRange.floatValue;
		}
		NSNumber* highRange = rangeArray[1];
		if (highRange != nil)
		{
			result.max = highRange.floatValue;
		}
		if (rangeArray.count > 2)
		{
			NSString* modeString = rangeArray[2];
			if ([modeString isEqualToString:@"uniform"])
			{
				result.sampleMode = qRangeF::eSampleMode_Uniform;
			}
			else if ([modeString isEqualToString:@"gaussian"])
			{
				result.sampleMode = qRangeF::eSampleMode_Gaussian;
			}
			else
			{
				qBREAK("Unknown sample mode %s", [modeString cStringUsingEncoding:NSUTF8StringEncoding]);
			}
		}
	}
	return result;
}

qRangeI qJSON::RangeI(NSDictionary* JSON, NSString* key, qRangeI defaultValue)
{
	qRangeI result = defaultValue;
	NSArray* rangeArray = [JSON objectForKey:key];
	if (rangeArray != nil)
	{
		NSNumber* lowRange = rangeArray[0];
		if (lowRange != nil)
		{
			result.min = lowRange.intValue;
		}
		NSNumber* highRange = rangeArray[1];
		if (highRange != nil)
		{
			result.max = highRange.intValue;
		}
		if (rangeArray.count > 2)
		{
			NSString* modeString = rangeArray[2];
			if ([modeString isEqualToString:@"uniform"])
			{
				result.sampleMode = qRangeI::eSampleMode_Uniform;
			}
			else if ([modeString isEqualToString:@"gaussian"])
			{
				result.sampleMode = qRangeI::eSampleMode_Gaussian;
			}
			else
			{
				qBREAK("Unknown sample mode %s", [modeString cStringUsingEncoding:NSUTF8StringEncoding]);
			}
		}
	}
	return result;
}

qRangeF qJSON::RangeF(NSArray* rangeArray, qRangeF defaultValue)
{
	qRangeF result = defaultValue;
	NSNumber* lowRange = rangeArray[0];
	if (lowRange != nil)
	{
		result.min = lowRange.floatValue;
	}
	NSNumber* highRange = rangeArray[1];
	if (highRange != nil)
	{
		result.max = highRange.floatValue;
	}
	if (rangeArray.count > 2)
	{
		NSString* modeString = rangeArray[2];
		if ([modeString isEqualToString:@"uniform"])
		{
			result.sampleMode = qRangeF::eSampleMode_Uniform;
		}
		else if ([modeString isEqualToString:@"gaussian"])
		{
			result.sampleMode = qRangeF::eSampleMode_Gaussian;
		}
		else
		{
			qBREAK("Unknown sample mode %s", [modeString cStringUsingEncoding:NSUTF8StringEncoding]);
		}
	}
	return result;
}

qRangeI qJSON::RangeI(NSArray* rangeArray, qRangeI defaultValue)
{
	qRangeI result = defaultValue;
	NSNumber* lowRange = rangeArray[0];
	if (lowRange != nil)
	{
		result.min = lowRange.intValue;
	}
	NSNumber* highRange = rangeArray[1];
	if (highRange != nil)
	{
		result.max = highRange.intValue;
	}
	if (rangeArray.count > 2)
	{
		NSString* modeString = rangeArray[2];
		if ([modeString isEqualToString:@"uniform"])
		{
			result.sampleMode = qRangeI::eSampleMode_Uniform;
		}
		else if ([modeString isEqualToString:@"gaussian"])
		{
			result.sampleMode = qRangeI::eSampleMode_Gaussian;
		}
		else
		{
			qBREAK("Unknown sample mode %s", [modeString cStringUsingEncoding:NSUTF8StringEncoding]);
		}
	}
	return result;
}
