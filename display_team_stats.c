/* Program to display the win, lose, draw stats for a country that is input by the user. 
Stats are taken from a binary file containing football match results. 

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
#define SIZE 20

// structure templates
struct st_match
{
	char team1[SIZE];
	char team2[SIZE];
	int goals1;
	int goals2;
};

main()
{
    // file pointers
    FILE *fp_read;
    
    // variable to store records read from file
    struct st_match game;
    
    // open file for reading
	fp_read = fopen("results.bin", "rb");
    
    // error check for opening
	if (fp_read == NULL)
	{
		printf("\nFile could not be opened for reading.");
        exit(0);
	}
    // if the file opens okay then run the program
	else
	{
        // variable to hold the user's input
        char search_str[SIZE];
        
        // ask user for input
        printf("\nEnter the country name (case sensitive) i.e. Ireland, Scotland, Wales:\n");
        gets(search_str);
        
        // variable counters to display stats
        int played = 0;
        int win = 0;
        int draw = 0;
        int loss = 0;
        int scored = 0;
        int conceded = 0;
        
        // while pointer is not at the end of file
        while (feof(fp_read) == 0)
        {
            // read one record from the file
            fscanf(fp_read, "%s %s %d %d", game.team1, game.team2, &game.goals1, &game.goals2);
            {
                // if the user's input matches the team1 read from the file
                if(strcmp(search_str, game.team1) == 0)
                {
                    // if the goals1 is greater than goals2 country wins
                    if (game.goals1 > game.goals2) 
                    {
                        win++;
                    }
                    // if the goals1 is less than goals2 country loses
                    else if (game.goals1 < game.goals2) 
                    {
                        loss++;
                    }
                    // if the goals1 is equal to goals2 country draws
                    else if (game.goals1 == game.goals2) 
                    {
                        draw++;
                    }
                    
                    // count the matches played by country
                    played++;
                    
                    // count the goals scored
                    scored = scored + game.goals1;
                    
                    // count the conceded goals
                    conceded = conceded + game.goals2;
                }
                
                // if the user's input matches the team2 read from the file
                if (strcmp(search_str, game.team2) == 0)
                {
                    // if the goals2 is greater than goals1 country wins
                    if (game.goals2 > game.goals1) 
                    {
                        win++;
                    }
                    // if the goals2 is less than goals1 country loses
                    else if (game.goals2 < game.goals1)
                    {
                        loss++;
                    }
                    // if the goals2 is equal to goals1 country draws
                    else if (game.goals2 == game.goals1)
                    {
                        draw++;
                    }
                    
                    // count the matches played by country
                    played++;
                    
                    // count the goals scored
                    scored = scored + game.goals2;
                    
                    // count the goals conceded
                    conceded = conceded + game.goals1;
                }
            }
        }
        
        // if the user enters a country that isnt in the league
        if (played == 0)
        {
            printf("\nERROR: This team is not in the league or you may have used an incorrect spelling.");
            printf("\nPlease try again.\n");
            exit(0);
        }
        
        // display the results if the user has entered a team that is in the league
        printf("\nTeam: %s\nMatch Played: %d\nWin: %d\nDraw: %d\nLoss: %d\nGoals Scored: %d\nGoals Conceded: %d\n", search_str, played, win, draw, loss, scored, conceded);
        
        // close the files
        fclose(fp_read);
        printf("\nFile closed.\n");
        
        // gently end the program
        printf("\nPress 'enter' to exit this program.\n");
        getchar();
        
    }// end else check for file open
    
} // end main
