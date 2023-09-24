#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    int row;
    int col;
    int val;
} sparse;

void readsparse(sparse a[], int m, int n)
{
    int i, j, k, item, p;
    a[0].row = m;
    a[0].col = n;
    k = 1;

    printf("\nEnter the elements:\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &item);
            if (item == 0)
                continue;
            a[k].row = i;
            a[k].col = j;
            a[k].val = item;
            k++;
        }
    }
    a[0].val = k - 1;

    printf("\nThe entered sparse matrix is:\n");
    printf("\nRow\tColumn\tValue\n");
    for (p = 0; p <= a[0].val; p++)
    {
        printf("%d\t", a[p].row);
        printf("%d\t", a[p].col);
        printf("%d\n", a[p].val);
    }
}

void fast_transpose(sparse a[], sparse b[])
{
    int total[100], index[100]; // Replace row_terms and start_pos
    int i, j, p;

    int numTerms = a[0].val;//numterms is number of non zero values
    int numCols = a[0].col;//no of columns

// b ki pehli row mei col, row aur value store ki hai

    b[0].row = numCols;
    b[0].col = a[0].row;
    b[0].val = numTerms;

    if (numTerms > 0)
    {
        //total aur index vala array bana rahe hai ab
        for (i = 0; i < numCols; i++)
            total[i] = 0;

        for (i = 1; i <= numTerms; i++)
            total[a[i].col]++;

        index[0] = 1;

        for (i = 1; i < numCols; i++)
            index[i] = index[i - 1] + total[i - 1];

        for (i = 1; i <= numTerms; i++)
        {
            //transpose kiya
            j = index[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].val = a[i].val;
        }
    }

    printf("\nThe Fast Transpose sparse matrix is:\n");
    printf("\nRow\tColumn\tValue\n");
    for (p = 0; p <= a[0].val; p++)
    {
        printf("%d\t", b[p].row);
        printf("%d\t", b[p].col);
        printf("%d\n", b[p].val);
    }
}

int main()
{
    int m, n, key;
    sparse a[MAX], b[MAX];
    printf("\nEnter the no of rows and columns:\t");
    scanf("%d%d", &m, &n);

    readsparse(a, m, n);
    fast_transpose(a, b);

    return 0;
}
