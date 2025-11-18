#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//общее задание
int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("Error: Please specify filename as command line argument.\n");
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    int N, M;
    if (fscanf(file, "%d %d", &N, &M) != 2) {
        printf("Error: Invalid file format. Expected matrix dimensions N M\n");
        fclose(file);
        return 1;
    }

    int** matrix = (int**)malloc(N * sizeof(int*));
    if (matrix == NULL) {
        printf("Error: Could not allocate memory for matrix\n");
        fclose(file);
        return 1;
    }
    for (int i = 0; i < N; i++) {
        matrix[i] = (int*)malloc(M * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Error: Could not allocate memory for matrix row\n");
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            fclose(file);
            return 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                printf("Error: Could not read element [%d][%d]\n", i, j);
                for (int k = 0; k < N; k++) {
                    free(matrix[k]);
                }
                free(matrix);
                fclose(file);
                return 1;
            }
        }
    }

    fclose(file);

    printf("Matrix %d x %d successfully read from file '%s':\n", N, M, filename);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    //1 задание
    int min_1;
    min_1 = -1000000;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] < 0 && i+j < N) {
                min_1 = fmax(min_1, matrix[i][j]);
            }
        }
    }
    if (min_1 == -1000000) {
        printf("Error: There are no negative numbers in the matrix\n");
    }
    else {
        printf("%d", min_1);
    }
    //2 задание
    for (int j = 0; j < M; j++) {
        int a;
        float S;
        a = 0;
        for (int i = 0; i < N; i++) {
            a = a + matrix[i][j];
        }
        S = sin(a + 3 * matrix[2][3]);
        printf("%f \n", S);
    }


    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
