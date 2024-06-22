// Recursion Introduction

// Types of Recursion
/* // Type 1 - Tail Recusrsion : function call is the last statement
#include<iostream>
using namespace std;
void display(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        display(n-1);
    }
}
int main()
{
    display(3);     //output 321
} */

/* //Type 2 - Head Recusrsion :Function call is the first statement
#include <iostream>
using namespace std;
void display(int n)
{
    if (n > 0)
    {
        display(n - 1);
        cout << n<<" ";
    }
}
int main()
{
    display(3); // output 123
} */

/* // Type-3 - Tree Recursion : when a recursive function is called more than one time in a function
#include <stdio.h>
void fun(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun(n - 1);
        fun(n - 1);
    }
}
int main()
{
    fun(3);
} */

/* // Type 4- Indirect Recursion: when there are more than one functions calling each other in a circular fashion.
#include <stdio.h>
void funB(int n);
void funA(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        funB(n - 1);
    }
}
void funB(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        funA(n / 2);
    }
}
int main()
{
    funA(20);
} */
/*
// Type 5- Nested Recursion: when function call is passed as a parameter to the recursive function call
// -> in order to know the result, output of nested function call should be known first.
#include<stdio.h>
int fun(int n)
{
    if(n>100)
    return n-10;
    else
    return fun(fun(n+11));
}
int main()
{
    printf("%d",fun(95));
} */

// Static Variable in recursion
/* // without static variable
#include <stdio.h>
int fun(int n)
{
    if (n > 0)
    {
        return fun(n - 1) + n;
    }
}
int main()
{
    printf("%d", fun(3));
} */

/* // With static variable
#include <stdio.h>
int fun(int n)
{
    static int x=0;
    if (n > 0)
    {
        x++;
        return fun(n - 1) + x;
    }
}
int main()
{
    printf("%d", fun(3));
} */

/* // Program 1 : Sum of First n Natural numbers
#include <stdio.h>
int sum(int n)
{
    if (n == 0)
        return 0;
    else
        return n + sum(n - 1);
}
int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Sum of first %d natural numbers is %d !", n, sum(n));
} */

/* //Program 2 : Factorial of a number
#include<stdio.h>
int fact(int n)
{
    if (n==0)
    return 1;
    else
    return fact(n-1)*n;
}
int main()
{
    int n;
    printf("Enter number to calculate factorial: ");
    scanf("%d",&n);
    printf("Factorial of %d is %d",n,fact(n));
} */

/* // Program 3 (a): Power function (Exponent)
#include <stdio.h>
int pow(int m, int n)
{
    if (n == 0)
        return 1;
    else
        return pow(m, n - 1) * m;
}
int main()
{
    int a, b;
    printf("Enter base number: ");
    scanf("%d", &a);
    printf("Enter exponent value: ");
    scanf("%d", &b);
    printf("%d to the power %d is %d", a, b, pow(a, b));
} */

/* // Program 3 (b) : Rewriting power function faster with less multiplications
#include <stdio.h>
int pow(int m, int n)
{
    if (n == 0)
        return 1;
    else
    {
        if ((n % 2) == 0)
        {
            return pow(m * m, n / 2);
        }
        else
        {
            return m * pow(m * m, (n - 1) / 2);
        }
    }
}
int main()
{
    int a, b;
    printf("Enter base number: ");
    scanf("%d", &a);
    printf("Enter exponent value: ");
    scanf("%d", &b);
    printf("%d to the power %d is %d", a, b, pow(a, b));
} */

/* // Program 4 (a): Calculating taylor series for e^x: Standard approach
#include <stdio.h>
double taylor(int x, int n)
{
    static double p = 1, f = 1;
    double res;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        res = taylor(x, n - 1);
        p = p * x;
        f = f * n;
        return res + p / f;
    }
}
int main()
{
    int x, n;
    printf("Enter value of x and number of terms required: ");
    scanf("%d %d", &x, &n);
    printf("Result of taylor series for e^%d = %lf", x, taylor(x, n));
} */

/* // Program 4 (b): Calculating taylor series for e^x: Horner's Rule using loop
#include <stdio.h>
double taylor(int x, int n)
{
    if (n == 0)
        return 1;
    else
    {
        static double s = 1;
        for (; n > 0; n--)
        {
            s = 1 + x*s / n;
        }
        return s;
    }
}
int main()
{
    int x, n;
    printf("Enter value of x and number of terms required: ");
    scanf("%d %d", &x, &n);
    printf("Result of taylor series for e^%d = %lf", x, taylor(x, n));
} */

/* // Program 4 (c): Calculating taylor series for e^x: Horner's Rule using recursion
#include<stdio.h>
double taylor(int x,int n)
{
    static double s;
    if(n==0)
    return s;
    s=1+x*s/n;
    return taylor(x,n-1);
}
int main()
{
    int x, n;
    printf("Enter value of x and number of terms required: ");
    scanf("%d %d", &x, &n);
    printf("Result of taylor series for e^%d = %lf", x, taylor(x, n));
} */

/* // Program 4 (d): Calculating taylor series for e^x: Horner's Rule using iteration
#include<stdio.h>
double taylor(int x,int n)
{
    double s=1,num=1,den=1;
    int i;
    for(i=1;i<=n;i++)
    {
        num=num*x;
        den=den*i;
        s=s+(num/den);
    }
    return s;
}
int main()
{
    int x, n;
    printf("Enter value of x and number of terms required: ");
    scanf("%d %d", &x, &n);
    printf("Result of taylor series for e^%d = %lf", x, taylor(x, n));
} */

/* // Program 5 (a)- Fibonacci series using iterations
#include <stdio.h>
int fib(int n)
{
    int t1 = 0, t2 = 1, s, i;
    if (n >= 2)
        printf("0,1");

    for (i = 2; i < n; i++)
    {
        s = t1 + t2;
        t1 = t2;
        t2 = s;
        printf(",%d", s);
    }

    // return s; // if we have to return only the value of that element
}
int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    fib(n);
} */

/* // Program 5 (b)- Fibonacci series using basic recursion(to return value)
#include <stdio.h>
int fib(int n)
{
    if (n == 0 | n == 1)
        return n;
    else
        return fib(n - 2) + fib(n - 1);
}
int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("%d", fib(n));
} */

/* // Program 5 (b)- Fibonacci series using basic recursion(to print series)
#include <stdio.h>
int fib(int n)
{

    if (n == 0 | n == 1)
        return n;
    else
        return fib(n - 2) + fib(n - 1);
}
int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fib(i));
    }
} */

/* // Program 5 (c)- Fibonacci series using memoization (to return value)
#include <stdio.h>
int F[10];
int fib(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = fib(n - 2);
        }
        if (F[n - 1] == -1)
        {
            F[n - 1] = fib(n - 1);
        }
        return F[n - 2] + F[n - 1];
    }
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        F[i] = -1;
    }
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci term at %d is %d \n", n, fib(n));
    printf("The fibonacci series is : ");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", fib(i));
    }
} */

/* // Program 6(a)- nCr i.e Combinations Formula using recursion (factorial formula)
#include <stdio.h>
int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}
int ncr(int n, int r)
{
    int nt, dt;
    nt = fact(n);
    dt = fact(r) * fact(n - r);
    return nt / dt;
}
int main()
{
    int n, r;
    printf("Enter the values of n and r to calculate nCr: ");
    scanf("%d %d", &n, &r);
    printf("%dC%d = %d", n, r, ncr(n, r));
    return 0;
} */

/* // Program 6(b)- nCr i.e Combinations Formula using recursion (using pascals triangle)
#include <stdio.h>
int ncr(int n, int r)
{
    // Extreme conditions =1
    if (r == 0 | n == r)
        return 1;
    else
        return ncr(n - 1, r - 1) + ncr(n - 1, r); // using pascal's triangle
}
int main()
{
    int n, r;
    printf("Enter the values of n and r to calculate nCr: ");
    scanf("%d %d", &n, &r);
    printf("%dC%d = %d", n, r, ncr(n, r));
    return 0;
} */
/* // Program 7 : Tower of hanoi using recursion
#include <stdio.h>
void toh(int n, int a, int b, int c)
{
    if (n > 0)
    {
        toh(n - 1, a, c, b);
        printf("Move Disk from %d to %d\n", a, c);
        toh(n - 1, b, a, c);
    }
}
int main()
{
    int n, a, b, c;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Enter the First tower(1/2/3): ");
    scanf("%d", &a);
    printf("Enter the destination tower(1/2/3): ");
    scanf("%d", &c);
    printf("Enter the tower through which task is completed(1/2/3): ");
    scanf("%d", &b);
    printf("Steps to complete: \n");
    toh(n, a, b, c);
} */
#include <stdio.h>
void foo(int n, int sum)

{

    int k = 0, j = 0;

    if (n == 0)
    {
    }
    k = n % 10;

    j = n / 10;

    sum = sum + k;

    foo(j, sum);

    printf("%d", k);
}

int main()

{

    int a = 2048, sum = 0;

    foo(a, sum);

    printf("%d", sum);
}
