#ifndef gcd_lcm_H
#define gcd_lcm_H

/*
    File: gcd_lcm.h
    ----------------
    This header file provides functions to find the greatest common divisor (GCD) and least common multiple (LCM) of two numbers.
*/

/*
    Function: FindGCD
    -----------------
    Finds the greatest common divisor (GCD) of two numbers using the Euclidean algorithm.

    a: The first integer.
    b: The second integer.

    returns: The GCD of the two input numbers.
*/
long int FindGCD(long int a, long int b) {
    // Ensure positive values for calculation
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    // Euclidean algorithm for GCD calculation
    while (b != 0) {
        long int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

/*
    Function: FindLCM
    -----------------
    Finds the least common multiple (LCM) of two numbers using the relation LCM(a, b) = (a * b) / GCD(a, b).

    a: The first integer.
    b: The second integer.

    returns: The LCM of the two input numbers.
*/
long int FindLCM(long int a, long int b) {
    // Ensure positive values for calculation
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    // Calculate LCM using GCD
    return (a * b) / FindGCD(a, b);
}

#endif
