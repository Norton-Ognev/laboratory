#include <stdio.h>

int main(){
    int result[10];
    for (int i=0; i=10; i++){
        int a;
        a = scanf("Введите цифры для массива: %d\n", a);
        result[i]=a;
    }
    printf("%d", result);
    return 0;
}