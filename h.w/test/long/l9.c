#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 20
#define MAX_TEAMS 10

// Define Player structure
typedef struct {
    int number;
    char name[50];
    char position[30];
} Player;

// Define Team structure
typedef struct {
    char name[50];
    char coach[50];
    Player players[MAX_PLAYERS];
    int playerCount;
} Team;

// Define League structure
typedef struct {
    Team teams[MAX_TEAMS];
    int teamCount;
} League;

// Function to display league info
void displayLeague(const League *league) {
    for (int i = 0; i < league->teamCount; i++) {
        Team team = league->teams[i];
        printf("\nTeam: %s\n", team.name);
        printf("Coach: %s\n", team.coach);
        printf("Players:\n");
        for (int j = 0; j < team.playerCount; j++) {
            Player p = team.players[j];
            printf("  #%d - %s (%s)\n", p.number, p.name, p.position);
        }
    }
}

// Main function to create example league
int main() {
    League league;
    league.teamCount = 2;

    // Team 1: Sharks
    strcpy(league.teams[0].name, "Sharks");
    strcpy(league.teams[0].coach, "Coach Adams");
    league.teams[0].playerCount = 2;
    league.teams[0].players[0] = (Player){7, "Liam Harper", "Forward"};
    league.teams[0].players[1] = (Player){10, "Noah Smith", "Midfielder"};

    // Team 2: Tigers
    strcpy(league.teams[1].name, "Tigers");
    strcpy(league.teams[1].coach, "Coach Bennett");
    league.teams[1].playerCount = 2;
    league.teams[1].players[0] = (Player){3, "Emma Johnson", "Defender"};
    league.teams[1].players[1] = (Player){1, "Olivia Brown", "Goalkeeper"};

    // Display the league data
    displayLeague(&league);

    return 0;
}
