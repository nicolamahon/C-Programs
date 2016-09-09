/* Program to search for a specific student by surname, using user input of the student's name. 

Name: Nicola Mahon C15755031
Date: 2016-04-12

Compiler: Borland
OS: Windows 10

*/

// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// symbollic names
#define MINSIZE 20
#define LIMIT 36

// structure templates
struct student_rec
{
	int id;
    char type[MINSIZE];
	char surname[MINSIZE];
	char firstname[MINSIZE];
};
    
main()
{
    // file pointers for merging the files
    FILE *fp_read;
    
    // search parameters
    char search_str[MINSIZE]; 
    
    // array to hold student records
    struct student_rec student1;
        
	// try to create a new file for merging
	fp_read = fopen("MergedStudentsBySurname.txt", "r");
	
	// error check for opening the file
    if (fp_read == NULL)
    {
        printf("WARNING: MergedStudentsBySurname.txt could not be opened at this time.");
        exit(0);
    }
	else
	{
		printf("MergedStudentsBySurname.txt opened successfully.");
	}
	
    // ask user what type of student they want to find
    printf("\n\nWhat surname do you want to search for?");
    printf("\nNOTE: Surnames are CASE SENSITIVE and begin with a capital letter i.e. Byrne, Cullen, Waldron)");
    printf("\n\nPlease enter your selection now:\n");
    gets(search_str);
    
    // count the number of records found, catch records NOT found
    int count = 0;
    
    // while the pointer is not at the end of the file
    while (feof(fp_read) == 0)
    {
        // read a record
        fscanf(fp_read, "%s %s %d %s", student1.surname, student1.firstname, &student1.id, student1.type);
        
        // if the record type matches the search parameter 
        if (strcmp(search_str, student1.surname) == 0)
        {
            printf("\nRecord Found!\nID: %d\nType: %s\nSurname: %s\nFirstname: %s\n", student1.id, student1.type, student1.surname, student1.firstname);
            count++;
        }
    }
    
    // catch any input that doesnt match the string compare
    if (count == 0)
    {
        printf("\nSorry, no records were found of that type, please try again, ensuring your selection is case sensitive.");
    }
    
    // close the file
    fclose(fp_read);
    
    printf("\n\nPress 'enter' to exit program.");
    getchar();

} // end main)
