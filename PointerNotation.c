/* Program using pointers and indirection operators only to access variable

Name: Nicola Mahon C15755031
Date: 2015-11-24

*/

#include <stdio.h>
# define SIZE 3

main()
{
    float array1[SIZE];
    float array2[SIZE];
    int i;
    
    printf("Enter 3 decimal numbers: \n");
    
    // read contents into array1
    for (i=0; i<SIZE; i++)
    {
        scanf("%f", &*(array1 + i));
        flushall();
    }
    
    // copy contents into array2
    for (i=0; i<SIZE; i++)
    {
        *(array2 + i) = *(array1 + i);
    }
    
    // print contents of both arrays  
    printf("\nThe contents of array1 are: \n"); 
    for (i=0; i<SIZE; i++)
    {
        printf("%f \n", *(array1 + i));
    }
    
    printf("\nThe contents of array2 are: \n"); 
    for (i=0; i<SIZE; i++)
    {
        printf("%f \n", *(array2 + i));
    }    
    
    printf("\nPress 'enter' to exit...\n"); 
    getchar();
}
