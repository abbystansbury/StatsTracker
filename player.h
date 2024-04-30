#ifndef PLAYER_H
#define PLAYER_H

#define MAX_NAME_LENGTH 50
#define MAX_PLAYERS 50

typedef struct Player {
    char name[MAX_NAME_LENGTH];
    int points;
    int assists;
    int rebounds;
    int shots_made;
    int shots_attempted;
} Player;

void create_player(Player *player);
void save_player(Player *players, int num_players);
void load_players(Player *players, int *num_players);

#endif /* PLAYER_H */
