# qMath

qMath is a c++ math library for rendering data that targets the GPU. 

## Why another math library?

Most math libraries are designed for general purpose math on the CPU, often taking advantage of SIMD units. Numerical data for rendering generally has has different goals.

## What types does qMath provide?

- 2, 3, and 4 component vector types, at 16-bit (half), 32-bit (float), and 64-bit (double) precision
- 2x2, 3x3, and 4x4 matrix types, again at half, float, and double precision
- A dedicated RGBA type, which has half, float, and 8-bit unsigned precision support
- A range type, which supports random sampling with both uniforma and Guassian distributions
- A plane type, at half, float or double precision
- A triangle and quad type, which are essentially 3-tuple and 4-tuples, again at half, float, and double precision for each of qVector2, qVector3, and qVector4. For example, a qTriangle2h is a 3-tuple of qVector2's at half precision.

## What are the features of qMath?

- All types are templated, for both data type and alignment; a simple typedef allows you to produce any new vector, matrix, triangle, quad or RGBA type you might need (e.g. unsigned long 3 component vectors)
- All built-in data types are tightly packed: for example 32-bit float vector 3's take up 12 bytes (not 16 as in many libraries), reducing memory usage
- All types have the expect suite of operations: addition, subtraction, multiplication, division, along with things that are often handy in rendering:
    - Vectors: member and static functions for length, normalization, dot product, cross-product, absolute value, and compontent-wise min and max 
    - Matrices: static functions for scale, rotation, and transpose 
- Camera utilities to produce 4x4 orthographic, perspective, and look-at matrices
- Random number support throughout all types, including generation of random vectors and RGBA values
- A collection of scalar utilities, including non-secure hashing, min, max, floor, ceil, saturate, clamp, step, lerp, and degree <-> radian conversions
