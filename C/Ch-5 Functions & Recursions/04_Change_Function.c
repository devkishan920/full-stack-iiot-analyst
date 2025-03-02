// Just for practice & Concept clearance that NAME of function can be anything. So don't judge the function by it's name only

// Example of Misnomer 

#include<stdio.h>
#include<conio.h>

void change(int b);

void change(int b)
{
    b = 45;
}


int main()
{
    int b = 675;
    printf("the value of b before change is %d\n",b);

    change(b);  // only a copy of (b) is passed to the funtion. Hence, functions can't change the original values. 

    printf("the value of b after change is %d\n",b);

    return 0;
}