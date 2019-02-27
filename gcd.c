#include<stdio.h>
#include<stdlib.h>

int gcd(int, int);

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (a != b){
        if (a > b)
            a = a - b;
        else 
            b = b - a;
    }
    return a;
}