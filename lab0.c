#include <stdio.h>
#include <math.h>

int main() {
    float results[3][3];

    for (int x = 1; x <= 3; x++) {
        for (int a = 2; a <= 4; a++) {
            float z = fmin(sqrt(tan((a-x)/(float)x)), fmin(log((a*a)/(float)x), atan((x*x*x*sqrt(a))/(a+2.5))));
            results[x-1][a-2] = z;
        }
    }

    printf("     ");
    for (int a = 2; a <= 4; a++) {
        printf("a=%-8d", a);
    }
    printf("\n");

    for (int x = 1; x <= 3; x++) {
        printf("x=%d", x);
        for (int a = 2; a <= 4; a++) {
            printf(" %-8f", results[x-1][a-2]);
        }
        printf("\n");
    }
    return 0;
}