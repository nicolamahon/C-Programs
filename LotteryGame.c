/* Program to create a Lottery Game, including options 
for the user to control the game via a menu.

User can select 6 options from the Main Menu:
1: to select their lottery numbers 
2: to display their chosen numbers
3: to sort their chosen numbers in ascending order
4: to see if they have won with their chosen numbers
5: to display the frequency of their chosen numbers being selected in each round of the game, until they quit and the game ends
6: to exit or quit the game.

Rules/Controls:
- The program should return to the Main Menu after each option (1-5) has been run.
- The user cannot enter options 2-5 if they have not entered 6 valid numbers:
        - within the range 1 to 42
        - with only one occurence of any single number
- The frequency of the user's chosen numbers are remembered on each round of the game, until exit. 
- There is no limit on the number of rounds that can be played. 

Name: Nicola Mahon C15755031
Date: 2016-02-18

Operating System: Windows 10
Compiler: Borland

*/

// include standard input/output library
#include <stdio.h>

// define size for user's number array
#define USER_SIZE 6

// to create a range from 1-42 for looping
#define MAX_SIZE 42 


// Prototypes
void print_welcome(void);               // print the welcome message to the user 
void print_menu(void);                  // print the Menu Options to the user
void enter_nums1(int *, int *, int *);  // Option 1; read user's numbers, error checking
void display_user_nums2(int *);         // Option 2; display the user's numbers
void sort3(int *);                      // Option 3; sort the user's numbers in ascending order
void check_wins4(int *);                // Option 4; check user numbers against winning numbers, print results
void check_frequency5(int *, int *);    // Option 5; keep a count on the frequency of selection of the user's numbers, print the frequency
void exit_game6(void);                  // Option 6; exit the game, gently


main()
{
    // variable to store the users option selection, char used instead of int for error checking purposes
    char option;
    
    // array to store the user's selected numbers
    int user_nums[USER_SIZE];
    
    // validity check, variable for passing to function enter_nums1(), to check if user's input is valid before allowing access to options 2-6
    int valid = 0;
    
    // frequency check, variable for passing to function check_frequency5(), to check if the user has entered new numbers before incrementing the frequency again
    int flag_freq = 0;
    
    // welcome message to user
    print_welcome();
    
    
    // do-while option !=6, this loops around after each option ends and reprints the menu, asking for the user's next option choice
    do 
    {
    
        // print the menu for user and ask their menu option
        print_menu();
        
        // scanf to hold the user option choice, using a char type to assist in error checking the user's input
        scanf("%1s", &option);
        
        // switch statement to control the menu options (1-6)
        switch(option)
        {
            
            // Menu Option 1: user selects 6 numbers from the range 1 to 42
            case '1':
            {
                // call function 'enter_nums1' 
                enter_nums1(&valid, &flag_freq, user_nums);
                    
                // break out of option 1
                break;
                
            } // end case 1
            
            
            // Menu Option 2: display user numbers
            case '2':
            {
                
                // control to prevent the user beginning the game without having first selected menu option 1 (enter numbers)
                if (valid == 0)
                {
                    printf("\n*** ERROR: You must enter valid numbers first!\n");
                    
                } // end if()
                
                else
                {                
                    // call function 'display_user_nums2'
                    display_user_nums2(user_nums);
                    
                } // end else
                
                // break out of option 2
                break;
                
            } // end case 2
            
            
            // Menu Option 3: Sort the user's numbers
            case '3':
            {
                
                // control to prevent the user beginning the game without having first selected menu option 1 (enter numbers)
                if (valid == 0)
                {
                    printf("\n*** ERROR: You must enter valid numbers first!\n");
                    
                } // end if()
                
                else
                {
                    // call function 'sort3'
                    sort3(user_nums);
                    
                } // end else
                
                // break out of option 3
                break;
                
            } // end case 3, sorting numbers
            
            
            // Menu Option 4: Check winnings
            case '4':
            {
                // control to prevent the user beginning the game without having first selected menu option 1 (enter numbers)
                if (valid == 0)
                {
                    printf("\n*** ERROR: You must enter valid numbers first!\n");
                    
                } // end if()
                
                else
                {
                    // call function 'check_nums4'
                    check_wins4(user_nums);
                    
                } // end else
                
                // break out of option 4
                break;
                
            } // end case 4, check for winnings
            
            
            // Menu Option 5: Check Frequency
            case '5':
            {
                
                // control to prevent the user beginning the game without having first selected menu option 1 (enter numbers)
                if (valid == 0)
                {
                    printf("\n*** ERROR: You must enter valid numbers first!\n");
                    
                } // end if()
                
                else
                {
                    // call function 'check_frequency5'
                    check_frequency5(&flag_freq, user_nums);
                    
                } // end else
                    
                // break out of option 5
                break;
                
            } // end case 5, check frequency
            
            
             // Menu Option 6: Exit Game
            case '6':
            {
                
                // if the user selects char '6', it must be converted to an int value in order to exit the do-while loop and therefore the program
                option = 6;
                getchar();
                
                // print exit message to user
                printf("\n\t\t\tYou selected Option 6 - Exit Game\n");
                printf("\n   Thank You for Playing - Goodbye!\n");
                printf("\n   - Press 'enter' to exit.");
                
                // break out of option 6
                break;
                
            } // end case 6, game ends
            
            
            // Default, if option != 1, 2, 3, 4, 5, 6
            default:
            {
                // print error message 
                printf("\n*** ERROR: Please enter a VALID OPTION 1-6\n");
                
                // break out of switch_default  
                break;
                
            } // end default
            
        } // end switch (option)
        
    } // end do-while 
    while (option !=6);
    
    // to keep the window open for the user
    getchar();
    
} // end main()


/* Implement function: print_welcome()
Print the welcome message to the user at the start of each game. 
*/

void print_welcome(void)
{
    printf("\t\t\t*** JACKPOT LOTTERY ***\t\t\t\n");
    printf("\n\t\t\tWelcome to the Lottery Draw!\t\t\t");
    printf("\n\tPlease select one of the following options from the Main Menu below...\t");
    
} // end function print_welcome()


/* Implement function: print_menu()
Print the menu to the user and ask for their Menu Option
*/

void print_menu(void)
{
    // print Main Menu
    printf("\n\n\n\t\t\t*** MAIN MENU ***\t\t\t\n");
    printf(">>> Select 1: to SELECT your 6 numbers from the range 1 to 42.\n");
    printf(">>> Select 2: to DISPLAY your 6 chosen numbers.\n");
    printf(">>> Select 3: to SORT your numbers in ascending order.\n");
    printf(">>> Select 4: to CHECK if you are a winner.\n");
    printf(">>> Select 5: to display the FREQUENCY of the numbers you have selected.\n");
    printf(">>> Select 6: to EXIT the game.\n\n");
    
    // ask user to select a menu option, store in scanf (option)
    printf("\n>>> Please select a Menu Option: ");
    
} // end function print_menu()


/* Implement Option 1: Read numbers from user
1) error check: for number in range
2) error check: for duplicate values
3) store in user_nums array
4) contains a validation check to ensure that user's numbers are valid before allowing the user to select options 2-5
5) contains a flag for function check_frequency5(), to ensure frequencies are only incremented when the user enters NEW numbers

*/

void enter_nums1(int *valid, int *flag_freq, int *user_array)
{
    // indexes to use with for-loops
    // REGISTER to allow faster looping
    register int i, j;
    
    // print instructions to user
    printf("\n\t\tYou selected Option 1 - Select Numbers\n");
    printf("\nYou must select %d numbers per game. ", USER_SIZE);
    printf("Please enter your numbers now:\n");
        
    // for-loop to store the users numbers with scanf into user_array
    for (i=0; i<USER_SIZE; i++)
    {
        scanf("%d", &*(user_array + i));
        flushall();
        
        // check the user's numbers to confirm they are in range 1-42
        if (*(user_array + i) < 1 || *(user_array + i) > 42)
        {
            
            // if not in range 1-42, print error message
            printf("\n***ERROR: This number is NOT IN RANGE, please select a number between 1 and %d!\n", MAX_SIZE);
            
            // put the array pointer back one place and allow the user to enter a new number
            *(user_array + i) = i--;
            
            // indicate that the numbers are currently not valid
            *(valid) = 0;
            
        } // end if
        
        else
        {
            // indicate that the numbers are now valid
            *(valid) = 1;
            
        } // end else
        
    } // end for-loop
    
    // for-loop to check if any of the numbers in the user's number array are duplicates
    for (i=0; i<USER_SIZE; i++)
    {
        
        // the starting value of in this inner for-loop j is set to 1, as the first element of the array will ALWAYS be equal to itself, so we skip that element in our check
        for (j=i+1; j<(USER_SIZE); j++)
        {
            
            // if the number on the right is equal to the number in the i position
            if (*(user_array + j) == *(user_array + i))
            {
                
                // print error message to the user
                printf("\n***ERROR: The number you entered above in position no.%d contained a duplicate number. Please try again.\n", (j+1));
                
                // indicate that the numbers are now not valid
                *(valid) = 0;
                break;
                
            } // end if
            
            else 
            {
                // indicate that the numbers are now valid
                *(valid) = 1;
                
            } // end else
            
        } // end inner for-loop
        
    } // end outer for-loop
    
    
    // flag to indicate user has entered new numbers, this is passed to function check_frequency5() for validation
    *flag_freq = 1;
    
} // end function enter_nums1()


/* Implement Option 2: Display user numbers entered
1) reads in user_nums  (option 1)
2) prints the user numbers

*/

void display_user_nums2(int *user_array)
{
    // print instructions to user
    printf("\n\t\tYou selected Option 2 - Display Numbers\n");
    
    // indexes to use with for-loops
    // REGISTER to allow faster looping
    register int i;
    
    // for-loop prints the user's numbers from the array
    printf("\nYour numbers are:  ");
    
    for (i=0; i<USER_SIZE; i++)
    {
        printf("%d ", *(user_array + i));
        
    } // end for-loop
    
    
} // end function display_user_nums2()


/* Implement Option 3: Sort the users numbers 

1) read in the user_nums
2) use modified bubble sort to sort in ascending order

*/
void sort3(int *user_array)
{
    // print instructions to user
    printf("\n\t\tYou selected Option 3 - Sort My Numbers\n");
    
    // indexes to use with for-loops
    // REGISTER to allow faster looping
    register int i, j;
    
    // temporary variable to store numbers during the sort/swapping process
    int temp;
    
    // variable to hold a flag to tell the bubble sort when there has been no further swaps, and so the function can end without further iterations
    // this will speed up the sorting
    int sort_flag = 1;
    
    /* I have chosen to use the modified Bubble Sort, it has a potential Big O(n^2) but is more efficient with the use of a flag
        */
    
    // for-loop to begin sorting; outer loop to ensure all swaps are made
    for (i=0; i<USER_SIZE && sort_flag; i++)
    {
        // set the sort_flag to zero inside the loop, if the condition is not met, and no swaps are made, the flag will remain zero to indicate no changes
        sort_flag = 0;
        
        // inner for-loop to make the swap at each pair of variables if condition is true
        for (j=0; j<USER_SIZE-1; j++)
        {
            // if number on the left is greater than number on the right
            if (*(user_array + j) > *(user_array +j+1))
            {
                
                // store the value in a temp variable and then start swaps
                temp = *(user_array + j);
                *(user_array + j) = (*(user_array +j +1));
                (*(user_array +j +1)) = temp;
                
                // set sort_flag to one to confirm a change has been made
                sort_flag = 1;
                
            } // end if
            
        } // end inner for-loop
        
    } // end outer for-loop
    
    
    // tell the user that their numbers have been sorted 
    // (NOTE: option 3 does not include displaying the sorted numbers to the user)
    printf("\nYour numbers have now been sorted. Select Menu Option 2 to display them.\n");
    
} // end function sort3()


/* Implement Option 4: Check user_nums against winning numbers

1) Read in user numbers
2) Compare against static winning numbers array
*/

void check_wins4(int *user_array)
{
    // print instructions to user
    printf("\n\t\tYou selected Option 4 - Check Winnings\n");
    
    // variables to store winning numbers
    // STATIC so that they will not be wiped when the function ends the first time, and will be available on the next function call, saving some run time
    static int bonus = 42;
    static int win_nums[USER_SIZE] = {1, 3, 5, 7, 9, 11};
    
    // indexes for looping
    // REGISTER to speed up looping
    register int i, j;
    
    // counters to display results 
    int win = 0;
    int plus_bonus = 0; 
    
    // for-loop to check against the 6 winning numbers 
    for (i=0; i<USER_SIZE; i++)
    {
        
        // for each number in the user's selected numbers
        for (j=0; j<USER_SIZE; j++)
        {
            
            // if a winning number is in the user's numbers
            if (*(win_nums +i) == *(user_array +j))
            {
                
                // increment the winning counter
                win++;
                
            }// end if
            
        } // end inner for-loop
        
    } // end outer for-loop
    
    
    // for-loop to also check against the bonus number
    for (i=0; i<USER_SIZE; i++)
    {
        
        // if one of the user's numbers is the bonus number
        if (*(user_array + i) == bonus)
        {
            
            // increment the bonus counter
            plus_bonus++;
            
        } // end if
        
    } // end for-loop
    
    
    // Print the results of checking the user's numbers against the winning numbers
    //
    
    // Match 6
    if (win == 6)
    {
        printf("\nMatch 6: Congratulations You Win - JACKPOT!!");
    }
    
    // Match 5 + bonus
    else if (win == 5 && plus_bonus == 1)
    {
        printf("\nMatch 5 + Bonus: Congratulations You Win - NEW CAR!!");
    }
    
    // Match 5
    else if (win == 5 && plus_bonus == 0)
    {
        printf("\nMatch 5: Congratulations You Win - HOLIDAY!!");
    }
    
    // Match 4 + bonus
    else if (win == 4 && plus_bonus == 1)
    {
        printf("\nMatch 4 + Bonus: Congratulations You Win - WEEKEND AWAY!!");
    }
    
    // Match 4
    else if (win == 4 && plus_bonus == 0)
    {
        printf("\nMatch 4: Congratulations You Win - NIGHT OUT!!");
    }
    
    // Match 3 + bonus
    else if (win == 3 && plus_bonus == 1)
    {
        printf("\nMatch 3 + Bonus: Congratulations You Win - CINEMA TICKET!!");
    }
    
    // otherwise there are no winning numbers in user's numbers
    else 
    {
        printf("\nSorry, Bad Luck! - NO WINS");
    }
    
} // end function check_wins4()


/* Implement Option 5: Display frequency of numbers entered
1) reads in user_nums  (option 1)
2) compares user_nums to a range 1-42
3) increments the corresponding value in the frequency array
4) prints the occurences of each value that has been selected by the user in each iteration of the game
NOTE: the frequency will only increment once a new set of numbers have been selected in Option 1

*/

void check_frequency5(int *flag_freq, int *user_array)
{
    // print instructions to user
    printf("\n\t\tYou selected Option 5 - Check Frequency\n");
    
    // array to store option 5, the frequency of numbers selected
    // STATIC so that the values won't reset when the function ends
    static int frequency[MAX_SIZE] = {0};
    
    // indexes for looping
    // REGISTER to speed up looping
    register int i, j;
    
    // increment the frequency values, this ONLY executes a second time, if NEW numbers have been selected in option 1
    //
    
    // if the user has entered new numbers in Option 1, increment the frequency values
    if (*flag_freq == 1)
    {
        
        // for-loop to check each number entered by the user
        for (i=0; i<USER_SIZE; i++)
        {    
            
            // check against the numbers stored in frequency until a match is found
            // j index range is 1 to 42 (inclusive) which reflects the range of possible numbers that can be selected for the game
            for (j=1; j<(MAX_SIZE+1); j++)
            {
                
                // where a match is found, increment the frequency stored in ROW 1, COL J
                if (*(user_array + i) == j)
                {
                    (*(frequency + j -1))++;
                    
                }// end if
                
            } // end inner for
            
        } // end outer for
        
        
        // reset the flag to tell the frequency array not to increment in the next function call, unless new numbers are entered by the user in Option 1
        *flag_freq = 0;
        
    } // end if (flag_freq)
    
    
    // print results to screen, this ALWAYS executes in the function
    //
    
    //for-loop, j is set to ZERO to be first element of the array this time, NOT a number range (as with for-loop above)
    for (j=0; j<MAX_SIZE; j++)
    {
        
        // check the contents of frequency array for values greater that ZERO
        if (*(frequency + j) > 0)
        {
            
            // if value is greater than zero, print the frequency
            printf("\nNumber %d has been selected %d time(s).", (j+1), *(frequency + j));
            
        } // end if()
        
    } // end for-loop
    
} // end function check_frequency5()
