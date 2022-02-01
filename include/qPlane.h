/*
Copyright (c) 2022 Generation Loss Interactive

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

#ifndef __Q_PLANE_H__
#define __Q_PLANE_H__

#include "qCore.h"
#include "qVector3.h"

template<typename T, int ALIGN>
class qPlane_T
{
public:

	qVector3_T<T, ALIGN> normal;
	qVector3_T<T, ALIGN> origin;
	T d;
    
    qPlane_T(qVector3_T<T, ALIGN> _normal, qVector3_T<T, ALIGN> _origin)
    {
		Update(_normal, _origin);
	}
	
    qPlane_T(const qPlane_T &p)
    : normal(p.normal)
    , origin(p.origin)
    , d(p.d)
    {}
    
    ~qPlane_T()
    {}
    
#pragma mark setters

	void Update(qVector3_T<T, ALIGN> _normal, qVector3_T<T, ALIGN> _origin)
	{
		normal = _normal;
		normal.Normalize();
		origin = _origin;
		d = T(-1.0) * qVector3_T<T, ALIGN>::Dot(_normal, _origin);
	}
    
#pragma mark assignment
    
    qPlane_T& operator=(const qPlane_T &rhs)
    { 
        normal = rhs.normal;
        origin = rhs.origin;
        d = rhs.d;
        return *this;
    }
	
#pragma mark util

	T Distance(qVector3_T<T, ALIGN> point)
	{
		return std::abs(qVector3_T<T, ALIGN>::Dot(normal, point) + d);
	}
	
	qVector3_T<T, ALIGN> Location(T x, T y)
	{
		T z = -d - normal.x * x - normal.y * y;
		return qVector3(x, y, z);
	}
	
	qVector3_T<T, ALIGN> Project(qVector3_T<T, ALIGN> point)
	{
		return point - normal * (qVector3_T<T, ALIGN>::Dot(point, normal) + d);
	}
	
	friend std::ostream& operator<<(std::ostream& out, const qPlane_T& plane)
	{
		out << "plane [normal:" << plane.normal << ", origin: " << plane.origin << "]";
		return out;
	}

} __attribute__ ((aligned (ALIGN)));

typedef qPlane_T<double, 8> qPlaned;
typedef qPlane_T<float, 4> qPlane;
typedef qPlane_T<half, 2> qPlaneh;

#endif // __Q_PLANE_H__
