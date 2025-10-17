#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int durak() {
    char input[100];
    int number;
    
    while (1) {
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Input reading error\n");
            continue;
        }
        
        if (sscanf(input, "%d", &number) == 1) {
            return number;
        } else {
            printf("Incorrect input: enter an integer\n");
        }
    }
}

void find(int N, int S[], int M, int arr[], int len, int last) {
    if (N == 0) {
        printf("[");
        for (int i = 0; i < len; i++) {
            printf("%d", arr[i]);
            if (i < len - 1) printf(", ");
        }
        printf("]\n");
        return;
    }

    if (N < 0) {
        return;
    }

    for (int i = 0; i < M; i++) {
        if (S[i] != last) {
            if (S[i] <= N) {
                arr[len] = S[i];
                find(N - S[i], S, M, arr, len + 1, S[i]);
            }
        }
    }
}

void print(int N, int S[], int M) {

    int* current = (int*)malloc(N * sizeof(int));

    find(N, S, M, current, 0, -1);
    free(current);
}

int main(){
    int N,M;
    int *S;

    printf("Input N: ");
    N = durak();

    printf("Input M: ");
    M = durak();

    S = (int*)malloc(M*sizeof(int));

    for (int i = 0; i<M; i++){
        printf("s%d: ", i+1);
        S[i]= durak();
    }

    print(N, S, M);

    free (S);
    return 0;
}