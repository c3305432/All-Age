#include "stdio.h"
#include <string.h>
#include <math.h>

void BubbleSortA(int points[], const int pointssize);
void BubbleSortB(int goaldifference[], const int gdsize);
void BubbleSortC(int goalsfor[], const int gfsize);

typedef struct {
char group; /*Variable to be used for group read*/
char team[20] = { '\0' }; /*Array for name of country */
int points = 0, /*Accumulation for points*/
played = 0, /*Accumulation for games played*/
won = 0, /*Accumulation for games won*/
drawn = 0, /*Accumulation for games drawn*/
lost = 0, /*Accumulation for games lost*/
gf = 0, /*Accumulation for goals scored*/
ga = 0, /*Accumulation for goals conceded*/
gd = 0;
} country_t;

typedef struct {
char teamA[20]= { '\0' };
char teamB[20]= { '\0' };
int goalsA;
int goalsB;
} matches_t;


int main(void)
{
FILE *team;
FILE *match;

int input_status1, //Inputs returned by fscanf_s for teams and groups
input_status2, /*Inputs returned by fscanf_s for matches*/
err1, /*variables to check if files are opened correctly*/
err2,
comp1,/*Variables to compare strings*/
comp2,
i = 0, j = 0, q = 0; /*Counters*/
country_t teams[31]; /*Variable names to be held within the structure*/
matches_t games[49];

/*Open files for reading*/
err1 = fopen_s(&team, "team.dat", "r");
err2 = fopen_s(&match, "match.dat", "r"); 

printf_s("FIFA World Cup: Russia 2018 \n");
printf_s("Name: Ryan Mistelbauer \n");
printf_s("Student Number : c3305432 \n");
printf_s("Computer Lab : Friday 11am - 2pm ES105 \n \n \n");

/*Check to see if file has opened correctly*/
if (err1 == NULL)
{
/*Scan first dataset in*/
input_status1 = fscanf_s(team, "%s %c", teams[i].team, 19, &teams[i].group);
while (input_status1 != EOF)
{  /*Scan the rest of the datasets in*/
input_status1 = fscanf_s(team, "%s %c", teams[i].team, 19, &teams[i].group); 
i++;
}

}
else /*If not, display error message*/
{ 
printf_s("The file team.dat was not opened correctly \n");

}
/*Check to see if file has opened correctly*/
if (err2 == NULL)
{
printf_s("Opening Files \n");
printf_s("Processing... \n");

/*Compare strings*/
comp1 = strcmp(games[j].teamA, teams[i].team);
comp2 = strcmp(games[j + 1].teamB, teams[i].team);

/*Scan first dataset in*/
input_status2 = fscanf_s(match, "%s %d %s %d", games[j].teamA, 19, &games[j].goalsA, games[j + 1].teamB, 19, &games[j + 1].goalsB);
if (comp1 == 0 || comp2 == 0) /*If strings aren't identical print error message*/
{
printf_s("%s %d %s %d : Data not on team list \n", games[j].teamA, games[j].goalsA, games[j + 1].teamB, games[j + 1].goalsB);
}
if (games[j].goalsA < 0 || games[j + 1].goalsB < 0)
{
/*If goals are negative, print relevant error message*/
printf_s("%s %d %s %d : Data is INVALID \n", games[j].teamA, games[j].goalsA, games[j + 1].teamB, games[j + 1].goalsB);
}
else
{
/*Otherwise print valid dataset*/
printf_s("%s %d %s %d  \n", games[j].teamA, games[j].goalsA, games[j + 1].teamB, games[j + 1].goalsB);
if (games[j].goalsA > games[j + 1].goalsB)
{
teams[q].won = teams[q].won + 1;
teams[i].lost = teams[i].lost + 1;
teams[q].points = teams[q].points + 3;
teams[q].gf = teams[q].gf + games[j].goalsA;
teams[q].ga = teams[q].ga - games[j + 1].goalsB;
teams[i].gf = teams[i].gf + games[j + 1].goalsB;
teams[i].ga = teams[i].ga - games[j].goalsA;
teams[i].played = teams[i].played + 1;
}
else if (games[j].goalsA < games[j + 1].goalsB)
{
teams[i].won = teams[q].won + 1;
teams[q].lost = teams[i].lost + 1;
teams[i].points = teams[i].points + 3;
teams[q].gf = teams[q].gf + games[j].goalsA;
teams[q].ga = teams[q].ga - games[j + 1].goalsB;
teams[i].gf = teams[i].gf + games[j + 1].goalsB;
teams[i].ga = teams[i].ga - games[j].goalsA;
teams[i].played = teams[i].played + 1;
}
else if (games[j].goalsA == games[j + 1].goalsB)
{
teams[i].drawn = teams[q].drawn + 1;
teams[q].drawn = teams[i].drawn + 1;
teams[i].points = teams[i].points + 1;
teams[i].points = teams[i].points + 1;
teams[q].gf = teams[q].gf + games[j].goalsA;
teams[q].ga = teams[q].ga - games[j + 1].goalsB;
teams[i].gf = teams[i].gf + games[j + 1].goalsB;
teams[i].ga = teams[i].ga - games[j].goalsA;
teams[i].played = teams[i].played + 1;
}
}
