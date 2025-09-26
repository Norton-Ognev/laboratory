#include <stdio.h>
#include <math.h>

int main() {
    float results[3][3];

    for (float x = 1; x <= 3; x=x+1.3) {
        for (float a = 2; a <= 4; a=a+1.3) {
            float z = fmin(sqrt(tan((a-x)/x)), fmin(log((a*a)/x), atan((x*x*x*sqrt(a))/(a+2.5))));
            results[ (int)x-1][(int)a-2] = z;
        }
    }

    printf("         ");
    for (float a = 2; a <= 4; a=a+1.3) {
        if (a == (int)a) {
            printf("a=%-6d", (int)a);
        } else {
            printf("a=%-6.1f", a);
        }
    }
    
    printf("\n");

    for (float x = 1; x <= 3; x=x+1.3) {
        if (x == (int)x) {
            printf("x=%-3d", (int)x);
        } else {
            printf("x=%-2.1f", x);
        }
        for (float a = 2; a <= 4; a=a+1.3) {
            printf(" %-8f", results[(int)x-1][(int)a-2]);
        }
        printf("\n");
    }
    return 0;
}