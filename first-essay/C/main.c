#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double generateRandomDouble();
double **generateRandomSquaredMatrix(int size);
double *generateRandomVector(int size);
double *alocateVector(int size);

int main(int argc, char *argv[])
{
    clock_t t;
    int size = atoi(argv[1]);;
    double **A = generateRandomSquaredMatrix(size);
    double *x = generateRandomVector(size);
    double *b = alocateVector(size);
    double timeTaken;
    int i, j;

    t = clock();
    for (i = 0; i < size; i++) {
        b[i] = 0;
        for (j = 0; j < size; j++) {
            b[i] += A[i][j] * x[j];
        }
    }
    t = clock() - t;
    timeTaken = ((double)t/CLOCKS_PER_SEC);

    printf("Product iterating first through matrix lines took %f seconds to execute \n", timeTaken);

    t = clock();
    for (j = 0; j < size; j++) {
        b[j] = 0;
        for (i = 0; i < size; i++) {
            b[i] += A[i][j] * x[j];
        }
    }
    t = clock() - t;
    timeTaken = ((double)t/CLOCKS_PER_SEC);

    printf("Product iterating first through matrix columns took %f seconds to execute \n", timeTaken);

    return 0;
}

double generateRandomDouble()
{
    return (double)rand();
}

double **generateRandomSquaredMatrix(int size)
{
    double **matrix = (double **)malloc(size * sizeof(double*));
    int i, j;

    for (i = 0; i < size; i++) {
        matrix[i] = alocateVector(size);

        for (j = 0; j < size; j++) {
            matrix[i][j] = generateRandomDouble();
        }
    }

    return matrix;
}

double *generateRandomVector(int size)
{
    double *vector = alocateVector(size);
    int i;

    for (i = 0; i < size; i++) {
        vector[i] = generateRandomDouble();
    }

    return vector;
}

double *alocateVector(int size)
{
    double *vector = (double *)malloc((size +1) * sizeof(double));

    return vector;
}