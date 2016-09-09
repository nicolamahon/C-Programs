/* Program to scramble a file, byte by byte, saving as a new file with additional .sbl extension

Name: Nicola Mahon C15755031
Date: 2016-04-20

Compiler: Borland
OS: Windows 10

*/

// header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// symbollic names
#define SIZE 50

int main(int argc, char *argv[])
{
    if (argc !=2)
    {
        printf("\nERROR: Function requires 2 inputs.\n");
        printf("Please try again.\n");
        printf("Enter the name of 1) the program file and 2) the file to be scrambled.\n");
        exit(0);
    }
    else
    {
        // file pointers for reading and writing to files
        FILE *fp_read;
        FILE *fp_write;
        
        // variables to hold chars read from the file
        char x, y;
        
        // variable to hold the new .sbl file name
        char newfile[SIZE];
        
        // try to open the file (entered through command line)
        fp_read = fopen(argv[1], "r+");
        
        // error check for opening the file
        if (fp_read == NULL)
        {
            printf("\nERROR: File could not be opened for reading.\n");
            exit(0);
        }
        else 
        {
            // assign the new file it's new additional extension
            strcpy(newfile,(strcat(argv[1], ".sbl")));
            
            // open the new file for reading
            fp_write = fopen(newfile, "w");
            
            // error check for opening the new file
            if (fp_read == NULL)
            {
                printf("\nERROR: New scrambled file could not be opened for writing.\n");
                exit(0);
            }
            else 
            {
                // variables for checking if a char was read from the file
                int i, j;
                
                // while the pointer is not at the end of the reading file
                while (feof(fp_read) == 0)
                {
                    // read 2 chars from the file into x and y
                    i = fread(&x, sizeof(x), 1, fp_read);
                    j = fread(&y, sizeof(y), 1, fp_read);
                    
                    // if able to read chars
                    if (j == 1)
                    {
                        // write them to the new file, in reverse order, swapping them
                        fwrite(&y, sizeof(char), 1, fp_write);
                    }
                    if (i == 1)
                    {
                        fwrite(&x, sizeof(char), 1, fp_write);
                    }
                }
                
                printf("\nThe file has now been scrambled. \nSee file \"%s\" in the directory", newfile);
                
                // close the files
                fclose(fp_read);
                fclose(fp_write);
                printf("\nFiles closed. Program Terminated.\n");
                
                // end the program
                exit(0);
                
            } // end else check for opening file for writing
            
        } // end else check for opening file for reading
        
    } // end else for program args
    
} // end main
