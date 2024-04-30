#include <stdio.h>
#include <string.h>
#include "player.h"

void create_player(Player *player) {
    printf("Enter name: ");
    scanf(" %[^\n]%*c", player->name);
    player->name[strcspn(player->name, "\n")] = '\0'; 
    printf("Enter points: ");
    scanf("%d", &player->points);

    getchar(); 
    printf("Enter assists: ");
    scanf("%d", &player->assists);
    printf("Enter rebounds: ");
    scanf("%d", &player->rebounds);
    printf("Enter shots made: ");
    scanf("%d", &player->shots_made);
    printf("Enter shots attempted: ");
    scanf("%d", &player->shots_attempted);
}

void save_player(Player *players, int num_players) {
    FILE *file = fopen("player_stats.txt", "w");
    if (file) {
        for (int i = 0; i < num_players; i++) {
            fprintf(file, "%s %d %d %d %d %d\n", players[i].name, players[i].points, players[i].assists, players[i].rebounds, players[i].shots_made, players[i].shots_attempted);
        }
        fclose(file);
        printf("Player stats saved successfully.\n");
    } else {
        printf("Could not save player stats.\n");
    }
}

void load_players(Player *players, int *num_players) {
    FILE *file = fopen("player_stats.txt", "r");
    if (file) {
        *num_players = 0;
        while (fscanf(file, "%s %d %d %d %d %d", players[*num_players].name, &players[*num_players].points, &players[*num_players].assists, &players[*num_players].rebounds, &players[*num_players].shots_made, &players[*num_players].shots_attempted) != EOF && *num_players < MAX_PLAYERS) {
            (*num_players)++;
        }
        fclose(file);
        printf("Loaded %d players successfully.\n", *num_players);
    } else {
        printf("Could not load player stats.\n");
    }
}
