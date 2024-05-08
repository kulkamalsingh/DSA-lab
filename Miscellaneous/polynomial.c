#include <stdio.h>
#include <stdlib.h>

void polynomialAddition()
{
    int degree1, degree2, i;

    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);
    int poly1[degree1 + 1];
    printf("Enter the coefficients of the first polynomial:\n");
    for (i = 0; i <= degree1; i++)
    {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }

    printf("\nEnter the degree of the second polynomial: ");
    scanf("%d", &degree2);
    int poly2[degree2 + 1];
    printf("Enter the coefficients of the second polynomial:\n");
    for (i = 0; i <= degree2; i++)
    {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly2[i]);
    }

    int maxDegree = (degree1 > degree2) ? degree1 : degree2;
    int result[maxDegree + 1];

    for (i = 0; i <= maxDegree; i++)
    {
        result[i] = 0;
        if (i <= degree1)
            result[i] += poly1[i];
        if (i <= degree2)
            result[i] += poly2[i];
    }

    
    printf("\nResult of polynomial addition:\n");
    for (i = maxDegree; i >= 0; i--)
    {
        if (i > 0)
            printf("%dx^%d + ", result[i], i);
        else
            printf("%d\n", result[i]);
    }
}

int main()
{
    polynomialAddition();
    return 0;
}