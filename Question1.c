#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_to_file(int n, double **A, bool format_flag)
{
    char filename[50];
    FILE *output;

    if (format_flag == true)
    {
        sprintf(filename, "array%06d_%s.out", n, "bin");
        output = fopen(filename, "wb");
        if (output == NULL)
        {
            printf("Error opening file for writing.\n");
            return;
        }
        for (int i = 0; i < n; i++)
        {
            fwrite(A[i], sizeof(double), n, output);
        }
    }
    else
    {
        sprintf(filename, "array%06d_%s.out", n, "asc");
        output = fopen(filename, "w");
        if (output == NULL)
        {
            printf("Error opening file for writing.\n");
            return;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fprintf(output, "%.15f ", A[i][j]);
            }
            fprintf(output, "\n");
        }
    }
    fclose(output);
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

    for (int i = 0; i < n; i++)
    {
        A[i] = (double *)malloc(n * sizeof(double));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = (double)(i + j);
        }
    }

    print_to_file(n, A, false);
    print_to_file(n, A, true);

    for (int i = 0; i < n; i++)
    {
        free(A[i]);
    }
    free(A);

    return 0;
}
