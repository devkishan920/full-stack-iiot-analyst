#include<stdio.h>
int main()
{
    enum meal{breakfast, lunch, dinner};
    
    printf("%d\n",breakfast);
    printf("%d\n",lunch);
    printf("%d\n",dinner);

    int a = breakfast;
    int b = lunch;
    int c = dinner;

    printf("a=%d\nb=%d\nc=%d",a,b,c);

    return 0;
}