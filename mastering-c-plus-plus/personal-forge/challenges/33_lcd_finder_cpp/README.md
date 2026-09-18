# LCM (Least Common Multiple) finder:
## ${\color{orange}\text{Concept explanation}}$:
Explanation:
```
  LCM stands for "least common multiple" which receives two integer inputs and outputs one integer
  lcm(16, 42) must return the least multiple between 16 and 42.

  16 = 2* 8 =
    2 * 2 * 2  * 2 =
    2^4

  42 =
    2 * 21 =
    2 * 3 * 7
  The multiple the highest power primes:

  (2)^4 * 3 * 7 =
    16 * 3 * 7 =
    16 * 21 = 336

  Importance of LCM:
  Imagine two different lighting-sign traffic lights; one red and the other is green:

    one turns green after 30 second and the other at 60 seconds
    When will be the first time, the two traffic lights turn green.

    lcm(30, 60) = 60
    They will turn green simultaneously after 60 seconds

    15 sec red -- 15 sec green -- 15 sec red -- 15 sec red
    30 sec red -- -- -- -- -- --  30 sec green -- {Still green}
  
  There is an ancient algorithm called the Euclidean algorithm for finding the greatest common divisor (GCD) of two numbers.
  We can then use the GCD to compute the LCM.

  lcm(a, b) = (a * b)/gcd(a, b)

  Also a multiple means a result of multiplication
  so LlcmCM tries to find the least multiple possible that can also be divided by both numbers without a floating decimal point
  lcm(32, 60) = 480
  there is no positive number smaller than 480 that is a multiple of both 32 and 60, therefore 480 is the least common
  multiple of 32 and 60

```