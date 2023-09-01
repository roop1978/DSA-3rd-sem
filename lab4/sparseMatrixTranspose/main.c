


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Element;

void displayMatrix(Element matrix[], int numRows, int numCols) {
    int k = 1;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (i == matrix[k].row && j == matrix[k].col) {
                printf("%d ", matrix[k].value);
                k++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void fastTranspose(Element a[], Element b[], int numRows, int numCols) {
    int rowTerms[numCols];
    int startingPos[numCols];

    for (int i = 0; i < numCols; i++) {
        rowTerms[i] = 0;
    }

    for (int i = 1; i <= a[0].value; i++) {
        rowTerms[a[i].col]++;
    }

    startingPos[0] = 1;
    for (int i = 1; i < numCols; i++) {
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
    }

    for (int i = 1; i <= a[0].value; i++) {
        int j = a[i].col;
        int pos = startingPos[j];
        b[pos].row = a[i].col;
        b[pos].col = a[i].row;
        b[pos].value = a[i].value;
        startingPos[j]++;
    }

    b[0].row = numCols;
    b[0].col = numRows;
    b[0].value = a[0].value;
}

int main() {
    int numRows, numCols, numTerms;

    printf("Enter the number of rows, columns, and non-zero terms: ");
    scanf("%d %d %d", &numRows, &numCols, &numTerms);

    Element *sparseMatrix = (Element *)malloc((numTerms + 1) * sizeof(Element));
    Element *transposedMatrix = (Element *)malloc((numTerms + 1) * sizeof(Element));

    printf("Enter the elements (row, column, value):\n");
    for (int i = 1; i <= numTerms; i++) {
        scanf("%d %d %d", &sparseMatrix[i].row, &sparseMatrix[i].col, &sparseMatrix[i].value);
    }

    sparseMatrix[0].row = numRows;
    sparseMatrix[0].col = numCols;
    sparseMatrix[0].value = numTerms;

    printf("Original Sparse Matrix:\n");
    displayMatrix(sparseMatrix, numRows, numCols);

    fastTranspose(sparseMatrix, transposedMatrix, numRows, numCols);

    printf("Transposed Sparse Matrix:\n");
    displayMatrix(transposedMatrix, numCols, numRows);

    free(sparseMatrix);
    free(transposedMatrix);

    return 0;
}
