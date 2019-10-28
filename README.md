# qMath

qMath is a c++ math library for rendering data that targets the GPU. 

## Why another math library?

Most math libraries are designed for general purpose math on the CPU, often taking advantage of SIMD units. Numerical data for rendering generally has has different goals.

## What types does qMath provide?

1. 2, 3, and 4 component vector types, at 16-bit (half), 32-bit (float), and 64-bit (double) precision
1. 2x2, 3x3, and 4x4 matrix types, again at half, float, and double precision
1. A dedicated RGBA type, which has half, float, and 8-bit unsigned precision support
1. A range type, which supports random sampling with both uniforma and Guassian distributions

## What are the features of qMath?

1. All types are templated, for both data type and alignment; a simple typedef allows you to produce any new vector, matrix, or RGBA type you might need (e.g. unsigned long 3 component vectors)
1. All built-in data types are tightly packed: 32-bit vector 3's take up 12 bytes (not 16 as in many libraries), reducing memory usage
1. All types have the expect suite of operations: addition, subtraction, multiplication, division, along with things that are often handy in rendering:
    - Vectors: member and static functions for length, normalization, dot product, cross-product, absolute value, and compontent-wise min and max 
    - Matrices: static functions for scale, rotation, and transpose 
1. Camera utilities to produce 4x4 orthographic, perspective, and look-at matrices
1. Random number support throughout all types, including generation of random vectors and RGBA values
1. A collection of scalar utilities, including non-secure hashing, min, max, floor, ceil, saturate, clamp, step, lerp, and degree <-> radian conversions
