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

#include "qCamera.h"

namespace qCamera
{
    qMatrix4 Orthographic(const float width,
						  const float height,
						  const float near,
						  const float far)
    {
		qASSERT(width != 0.0f);
        qASSERT(height != 0.0f);
        qASSERT(near != far);
        qMatrix4 m;
        m.m00 = 2.0f / width;
        m.m11 = 2.0f / height;
        m.m22 = 1.0f / (far - near);
        m.m32 = near / (near - far);
        return m;
    }
	
	//left handed, equivalent to D3DXMatrixPerspectiveLH
    qMatrix4 Perspective(const float fovYDegrees,
						 const float aspect,
						 const float near,
						 const float far)
    {
		float angle  = (0.5f * fovYDegrees) * float(M_PI) / 180.0f; // radians
		float yScale = 1.0f / tanf(angle);
		float xScale = yScale / aspect;
		float zScale = far / (far - near);

		qMatrix4 m;
		m.m00 = xScale;
		m.m11 = yScale;
		m.m22 = zScale;
		m.m23 = 1.0f;
		m.m32 = -near * zScale; //same as near * far / (near - far), just multiplied top and bottom by -1
		m.m33 = 0.0f;
		return m;
	}
	
	qMatrix4 LookAt(qVector3 eye,
					qVector3 center,
					qVector3 up)
	{
		qVector3 zAxis = qVector3::Normalize(center - eye);
		qVector3 xAxis = qVector3::Normalize(qVector3::Cross(up, zAxis));
		qVector3 yAxis = qVector3::Cross(zAxis, xAxis);
		
		qMatrix4 m;
		
		m.m00 = xAxis.x;
		m.m10 = xAxis.y;
		m.m20 = xAxis.z;
		
		m.m01 = yAxis.x;
		m.m11 = yAxis.y;
		m.m21 = yAxis.z;
		
		m.m02 = zAxis.x;
		m.m12 = zAxis.y;
		m.m22 = zAxis.z;
		
		m.m30 = -qVector3::Dot(xAxis, eye);
		m.m31 = -qVector3::Dot(yAxis, eye);
		m.m32 = -qVector3::Dot(zAxis, eye);
		
		return m;
	}
}
