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

#include "qUtil.h"
#include <string.h>

unsigned int qPowerOfTwo(unsigned int v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

bool qIsPowerOfTwo(unsigned int val)
{
    return ( (val & (val - 1)) == 0);
}

//public domain from http://www.burtleburtle.net/bob/hash/doobs.html
qHashType qHash(const char* key, unsigned int len)
{
    unsigned int hash, i;
    for(hash=0, i=0; i<len; ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
} 

qHashType qHash(const char* key)
{
    unsigned int length = (unsigned int)strlen(key);
    return qHash(key, length);
}

float qFloor(const float a)
{
    return floorf(a);
}

float qCeil(const float a)
{
    return ceilf(a);
}

float qRound(const float a)
{
    return a >= 0.0f ? qFloor(a + 0.5f) : qCeil(a - 0.5f);
}
