#include <stdio.h>
#include "player.h"

int main() {
    Player players[MAX_PLAYERS];
    int num_players = 0;
    char choice;

    while (1) {
        printf("Are you creating a player (C), loading players (L), or exiting (E)? ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'C':
            case 'c':
                if (num_players < MAX_PLAYERS) {
                    load_players(players, &num_players); // Load existing players
                    create_player(&players[num_players]); // Add new player
                    num_players++; // Increment player count
                    save_player(players, num_players); // Save all players
                } else {
                    printf("Maximum number of players reached.\n");
                }
                break;
            case 'L':
            case 'l':
                load_players(players, &num_players);
                for (int i = 0; i < num_players; i++) {
                    printf("NAME: %s\nPOINTS: %d\nASSISTS: %d\nREBOUNDS: %d\nSHOTS MADE: %d\nSHOTS ATTEMPTED: %d\n\n",
                           players[i].name, players[i].points, players[i].assists, players[i].rebounds, players[i].shots_made, players[i].shots_attempted);
                }
                break;
            case 'E':
            case 'e':
                printf("Exiting.\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
