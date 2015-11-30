/* Program to create a simple maths quiz, including options 
for the user to control the game via a menu.

User can select 4 options from the Main Menu:
1: to select the number of questions they would like to answer per round. 
2: to start the quiz.
3: to display their score for the round.
4: to exit or quit the quiz.

Rules/Controls:
- There are a maximum of 5 questions per round. 
- The user cannot start the quiz (2) without having first selected the number of questions to be asked (1).
- The user cannot display their score (3) without having first selected the number of questions to be asked (1) AND without having played at least one round (2). 
- Scores are reset after each round and do not accumulate. 
- Each round is numbered. 
- There is no limit on the number of rounds that can be played. 

Name: Nicola Mahon C15755031
Date: 2015-10-30

*/

// include standard input/output library
#include <stdio.h>
// set max and min sizes for answer array, num_questions
#define MAX_SIZE 5 
#define MIN_SIZE 1 

main()
{
    // array of answers to the maths questions
    int answers[MAX_SIZE] = {88, 228, 156, -4, 1};
    // variable to store the users selected menu option
    int option;
    // variables to store correct /incorrect answer scores
    int score = 0;
    int wrong = 0;
    // variable to hold the users selection in Menu Option 1 (number of questions to be asked)
    int num_questions = 0;
    // index variable for looping through array and also controlling number of questions asked each round
    int i;
    // variable to store users answers to questions
    int user_answer;
    // to count the rounds played by the user (if replaying)
    int round = 1;
    
    // welcome message to user
    printf("\t\t\t*** FUN MATHS QUIZ ***\t\t\t\n");
    printf("\n\t\t\tWelcome to your Maths Quiz!\t\t\t");
    printf("\n\tPlease select one of the following options from the Main Menu below...\t\n");
    
    // do_while: to print the main menu once, and loop until the user selects '4' i.e. to exit the game
    do
    {
        // print the main menu once, and loop back after each menu option ends
        printf("\n\t\t\t*** MAIN MENU ***\t\t\t\n");
        printf(">>> Select 1: to select the number of QUESTIONS you would like to answer.\n");
        printf(">>> Select 2: to START the quiz.\n");
        printf(">>> Select 3: to display your SCORE for the ROUND.\n");
        printf(">>> Select 4: to EXIT the quiz.\n");
        
        // ask user to select a menu option, store in scanf (option)
        printf("\n>>> Please select a menu option: ");
        scanf("%d", &option);
        flushall();
        
        // check for user selecting invalid menu option
        if (option != 1 && option != 2 && option != 3)
        {
            printf("This is not a valid option.\n");
        }
        
        // switch statement to control the menu options (1-3), 4 exits the program and is not in the switch statement
        switch(option)
        {
            // Menu Option 1: user chooses how many questions to answer in this round
            case 1:
            {
                // print this once in do_while and repeat until program receives a valid selection (1-5)
                do
                {
                    // print instructions to user, store in scanf (num_questions)
                    printf("\n--- You selected Menu Option: %d", option);
                    printf("\nThere are a maximum of %d questions per round.\n", MAX_SIZE);
                    printf("Please enter number of questions for this round: ");
                    scanf("%d", &num_questions); 
                    // this variable (num_questions) will be reset at the end of each round so that the user 
                    // has to select the number of questions again, if they are playing another round
                    flushall();
                    // output to user their chosen selection (1-5)
                    printf("--- You have selected to answer %d questions this round.\n", num_questions);
                    
                    // check for user selecting invalid option i.e. less than 1 or greater than 5
                    if (num_questions > MAX_SIZE || num_questions < MIN_SIZE)
                    {
                        printf("\n*** ERROR: Please select a number up to max of %d!\n", MAX_SIZE);
                    }
                } // repeat looping in do_while until user selects number between 1-5
                while (num_questions > MAX_SIZE || num_questions < MIN_SIZE);
                break;
            } // end case 1, how many questions to answer in this round
            
            // Menu Option 2: start the quiz and print the questions 
            case 2:
            {
                // control to prevent the user beginning the quiz without having first selected menu option 1 (num of questions)
                if (num_questions == 0)
                {
                    printf("\n*** ERROR: Please select the number of questions first!\n");
                    break;
                }
                // if user has selected number of questions, begin printing questions
                else
                {
                    // set all score and index counters to zero (used repeatedly when playing multiple rounds)
                    score = 0;
                    wrong = 0;
                    i = 0;
                    // output to user, their chosen selection, and round X of quiz is now starting
                    printf("\n--- You selected Menu Option: %d", option);
                    printf("\n--- Let's begin...\n");
                    printf("\n\t***** ROUND %d *****\n", round);
                    
                    // do_while; prints the first question when quiz starts (DO)
                    // and proceeds to next question as long as [i] index is less than the num_questions (WHILE)
                    do
                    {
                        // Question 1
                        // print question, store in scanf (user_answer)
                        printf("\nQuestion 1: >> (9 x 8) + 16 = _ \n");
                        scanf("%d", &user_answer);
                        flushall();
                        // check if answer is same as [i] index in answers array (initialized with values at start)
                        if (user_answer == answers[i])
                        {
                            // if correct, print correct, increment score counter
                            printf("--- You entered: %d - Correct!!\n", user_answer);
                            score++;
                        }
                        else
                        {
                            // if wrong, print wrong, increment wrong counter
                            printf("--- You entered: %d - Wrong!! The correct answer: %d\n", user_answer, answers[i]);
                            wrong++;
                        }
                        // increment [i] index so that if the do_while evaulates to false at next question (below), 
                        //the program will exit out of the loop before asking the next question
                        i++;
                        
                        // as explained (above), check if [i] is less than num_questions
                        // if false, exit loop otherwise move on and ask the next question
                        if (i < num_questions)
                        {
                            // Question 2
                            // print question, store in scanf (user_answer)
                            printf("\nQuestion 2: >> (121 - 83) x 6 = _ \n");
                            scanf("%d", &user_answer);
                            flushall();
                            // check if answer is same as [i] index in answers array (initialized with values at start)
                            if (user_answer == answers[i])
                            {
                                // if correct, print correct, increment score counter
                                printf("--- You entered: %d - Correct!!\n", user_answer);
                                score++;
                            }
                            else
                            {
                                // if wrong, print wrong, increment wrong counter
                                printf("--- You entered: %d - Wrong!! The correct answer: %d\n", user_answer, answers[i]);
                                wrong++;
                            }
                            // increment [i] index so that if the do_while evaluates to false, 
                            //the program will exit out of the loop before the next question
                            i++;
                        } // end if Q2
                        
                        // check if [i] is less than num_questions, if false, exit loop otherwise move on and ask the next question
                        if (i < num_questions)
                        {
                            // Question 3
                            // print question, store in scanf (user_answer)
                            printf("\nQuestion 3: >> 12 x (143 / 11) = _ \n");
                            scanf("%d", &user_answer);
                            flushall();
                            // check if answer is same as [i] index in answers array (initialized with values at start)
                            if (user_answer == answers[i])
                            {
                                // if correct, print correct, increment score counter
                                printf("--- You entered: %d - Correct!!\n", user_answer);
                                score++;
                            }
                            else
                            {
                                // if wrong, print wrong, increment wrong counter
                                printf("--- You entered: %d - Wrong!! The correct answer: %d\n", user_answer, answers[i]);
                                wrong++;
                            }
                            // increment [i] index so that if the do_while evaluates to false, 
                            //the program will exit out of the loop before the next question
                            i++;
                        } // end if Q3
                        
                        
                        // check if [i] is less than num_questions, if false, exit loop otherwise move on and ask the next question
                        if (i < num_questions)
                        {
                            // Question 4
                            // print question, store in scanf (user_answer)
                            printf("\nQuestion 4: >> (56 x 3) - 172 = _ \n");
                            scanf("%d", &user_answer);
                            flushall();
                            // check if answer is same as [i] index in answers array (initialized with values at start)
                            if (user_answer == answers[i])
                            {
                                // if correct, print correct, increment score counter
                                printf("--- You entered: %d - Correct!!\n", user_answer);
                                score++;
                            }
                            else
                            {
                                // if wrong, print wrong, increment wrong counter
                                printf("--- You entered: %d - Wrong!! The correct answer: %d\n", user_answer, answers[i]);
                                wrong++;
                            }
                            // increment [i] index so that if the do_while evaluates to false, 
                            //the program will exit out of the loop before the next question
                            i++;
                        } // end if Q4
                        
                        
                        // check if [i] is less than num_questions, if false, exit loop otherwise move on and ask the next question
                        if (i < num_questions)
                        {
                            // Question 5
                            // print question, store in scanf (user_answer)
                            printf("\nQuestion 5: >> 216 / (18 x 12) = _ \n");
                            scanf("%d", &user_answer);
                            flushall();
                            // check if answer is same as [i] index in answers array (initialized with values at start)
                            if (user_answer == answers[i])
                            {
                                // if correct, print correct, increment score counter
                                printf("--- You entered: %d - Correct!!\n", user_answer);
                                score++;
                            }
                            else
                            {
                                // if wrong, print wrong, increment wrong counter
                                printf("--- You entered: %d - Wrong!! The correct answer: %d\n", user_answer, answers[i]);
                                wrong++;
                            }
                        } // end if Q5
                    } // end DO (menu option 2) 
                    while (i < num_questions-1);
                    
                    // display notice of End of Round to user
                    printf("\n>>> That is the end of Round %d.\n", round);
                    // increment round counter for next round
                    round++;
                    break;
                } // end ELSE, printing quiz questions
            } // end case 2, start the quiz and print the questions 
            
            // Menu Option 3: Print the player's scores for the round
            case 3:
            {
                // control to prevent the user choosing menu option 3 (print score)
                // without first having selected num of questions and playing at least one round
                if (num_questions == 0)
                {
                    printf("\n*** ERROR: You must play the game first!\n");
                    //break;
                }
                // at least one round must have been played
                else if (score == 0 && wrong == 0)
                {
                    printf("\n*** ERROR: You must play the game first!\n");
                    //break;
                } // end inner IF
                else                
                {
                    // if above conditions are false, print the scores; correct and wrong
                    printf("\nScore for Round %d: %d CORRECT, %d WRONG.\n", round-1, score, wrong);
                    // ask user if they want to play again
                    printf("\n>>> Would you like to play again? Press 1 (yes) / 4 (EXIT)\n");
                    
                    // reset the num_questions counter for new round so that loop will start again
                    num_questions = 0;
                    break;
                } // end else
            } // end case 3, printing scores for the round
        } // end switch (option)
    } // end DO; printing the main menu once, and looping back after each menu option ends, until user quits (i.e until option = 4)
    while (option != 4);
    
    // to keep the window open for the user
    getchar();
} // end main()
