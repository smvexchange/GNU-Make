#include <stdio.h>
#include "mod1.h"
#include "mod2.h"
#include "mod3.h"

int main()
{
    double a, b, result;
    int c;
    char s;
    printf("Enter a numbers:\n");
    c = scanf("%lf %lf", &a, &b);
    if (c < 2 || c > 2) {
        printf("Error: wrong input.\n");
        return 2;
    }
    fflush(stdin);
    printf("Enter operation:\n");
    s = getchar();
    if (s == '+') {
        result = sum(a, b);
        printf("%.5f", result);
        return 0;
    } else if (s == '-') {
        result = sub(a, b);
        printf("%.5f", result);
        return 0;
    } else if (s == '/') {
        result = div(a, b);
        printf("%.5f", result);
        return 0;      
    } else {
        printf("No such operation.\n");
        return 1;
    }
    return 0;     
}
