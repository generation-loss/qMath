# qMath

qMath is a c++ math library, designed for rendering data that targets the GPU. 

## Why another math library?

Most math libraries are designed for general purpose math on the CPU, often taking advantage of SIMD units. Numerical data for rendering generally has has different goals.

## What types does qMath provide?

1. 2, 3, and 4 component vector types, at 64-bit (double), 32-bit (float), and 16-bit (half) precision
1. 2x2, 3x3, and 4x4 component matrix types, again at 64-bit (double), 32-bit (float), and 16-bit (half) precision
1. A dedicated RGBA type, which has 32-bit float, 16-bit float, and 8-bit unsigned precision support

## What are the features of qMath?

1. All types are templated, for both data type and alignment; a simple typedef allows you to produce any new vector, matrix, or RGBA type you might need
1. All built-in data types are tightly packed: 32-bit vector 3's take up 12 bytes (not 16 as in many libraries), reducing memory usage.
1. All types have the expect suite of operations: addition, subtraction, multiplication, division, along with things that are often handy in rendering:
    - Vectors: member and static functions for length, normalization, dot product, cross-product, absolute value, and compontent-wise min and max 
    - Matrices: static functions for scale, rotation, and transpose 
