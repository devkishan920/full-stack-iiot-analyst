// x(t) = 3 Sin(2 pie t) + Sin(2 pie 4t) + 0.5 Sin(2 pie 7t)
// Fourier transform = integration (-inf, +inf) x(t) e^-jwt

#include<stdio.h>
#include<math.h> // for cos, etc
#include<complex.h> // for complex


int main()
{
    int w = 0;
    int t = 0;
    float pie = 3.14159;
    // float xt = 3*Sin(2*pie*t) + Sin(2*pie*4*t) + 0.5*Sin(2*pie*7*t);
    // float ejwt = cos(w*t)-I*sin(w*t); since w = 2 pie f

    float xt1 = (3*sin(2*pie*t)) * (cos(2*pie*t)-I*sin(2*pie*t));
    float xt2 = (sin(2*pie*4*t)) * (cos(2*pie*4*t)-I*sin(2*pie*4*t));
    float xt3 = (0.5*sin(2*pie*7*t)) * (cos(2*pie*7*t)-I*sin(2*pie*7*t));

    //float result [10];
    float y = 0;
    float a = 0;
    float b = 0;


    for (t = 1; t <= 10; t++)
    {
        xt1 = (3*sin(2*pie*t)) * (cos(2*pie*t)-I*sin(2*pie*t));
        y = y+xt1;

        xt2 = (sin(2*pie*4*t)) * (cos(2*pie*4*t)-I*sin(2*pie*4*t));
        a = a+xt2;

        xt3 = (0.5*sin(2*pie*7*t)) * (cos(2*pie*7*t)-I*sin(2*pie*7*t));
        b = b+xt3;
        //printf("the result for ft %d is %f",i,result[i]);
    }
    
    printf("the result for ft1 is y : %f\n",y);
    printf("the result for ft2 is a : %f\n",a);
    printf("the result for ft3 is b : %f\n",b);
    printf("Final result for ft is : %f\n",y+a+b);
    return 0;
}