#include <stdio.h>
#include <stdlib.h>

void function(double **A, int n)
{
    for (int i = 1; i <= 4; i++)
    {
        char filename[50];
        sprintf(filename, "inputfiles/vec_%06d_%06d.in", n, i);

        FILE *filePtr = fopen(filename, "r");
        if (filePtr == NULL)
        {
            printf("Error opening vector file: %s\n", filename);
            continue;
        }

        double *TestVector = (double *)malloc(n * sizeof(double));
        if (TestVector == NULL)
        {
            printf("Memory allocation failed.\n");
            fclose(filePtr);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            fscanf(filePtr, "%lf,", &TestVector[j]);
        }
        fclose(filePtr);

        // for (int j = 0; j < n; j++)
        // {
        //     printf("%e,", TestVector[j]);
        // }

        double minLambda = 1e7;
        double maxLambda = -1e7;

        for (int x = 0; x < n; x++)
        {
            double sum = 0;
            for (int y = 0; y < n; y++)
            {
                sum += A[x][y] * TestVector[y];
            }

            if (TestVector[x] != 0)
            {
                double lambda = sum / TestVector[x];
                if (lambda > maxLambda)
                {
                    maxLambda = lambda;
                }
                if (lambda < minLambda)
                {
                    minLambda = lambda;
                }
            }
        }
        printf("minLamda :%e  maxLambda :%e\n", maxLambda, minLambda);
        double epsilon = 1e-6;
        if (abs(maxLambda - minLambda) < epsilon)
        {
            printf(" vec_%06d_%06d : Yes : %e\n", n, i, maxLambda);
        }
        else
        {
            printf(" vec_%06d_%06d : Not an eigenvector\n", n, i);
        }
        printf("\n");

        free(TestVector);
    }
}

int main()
{
    FILE *file = fopen("input.in", "r");
    if (file == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);
    fclose(file);

    double **A = (double **)malloc(n * sizeof(double *));
    if (A == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        A[i] = (double *)malloc(n * sizeof(double));
        if (A[i] == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }
    }

    char filename[50];
    sprintf(filename, "inputfiles/mat_%06d.in", n);
    FILE *filePtr = fopen(filename, "r");
    if (filePtr == NULL)
    {
        printf("Error opening matrix file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(filePtr, "%lf,", &A[i][j]);
        }
    }
    fclose(filePtr);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("%e ", A[i][j]);
    //     }
    //     printf("\n");
    // }

    function(A, n);

    for (int i = 0; i < n; i++)
    {
        free(A[i]);
    }
    free(A);

    return 0;
}
