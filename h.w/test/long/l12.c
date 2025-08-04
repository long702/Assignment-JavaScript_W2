#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 5

// ----------------------- Data Structures -----------------------

typedef enum {
    EMPTY,
    PLAYER,
    ENEMY,
    WALL,
    ITEM
} ObjectType;

typedef struct {
    ObjectType type;
    union {
        struct {
            int health;
            int attack;
        } player;

        struct {
            int health;
            int damage;
        } enemy;

        struct {
            char symbol;
        } wall;

        struct {
            char name[20];
            int value;
        } item;
    };
} GameObject;

typedef struct {
    GameObject* object;
} Tile;

// ----------------------- Global Variables -----------------------

Tile map[ROWS][COLS];
int playerRow = 0;
int playerCol = 0;

// ----------------------- Function Prototypes -----------------------

void initMap();
void displayMap();
void movePlayer(char direction);
void freeObjects();

// ----------------------- Main Function -----------------------

int main() {
    char command;

    initMap();

    printf("=== 2D Game Map ===\n");
    while (1) {
        displayMap();
        printf("Move (WASD, Q to quit): ");
        scanf(" %c", &command);
        if (command == 'q' || command == 'Q') break;

        movePlayer(command);
    }

    freeObjects();
    return 0;
}

// ----------------------- Function Definitions -----------------------

void initMap() {
    // Initialize all tiles to empty
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            map[i][j].object = NULL;

    // Add player
    GameObject* player = malloc(sizeof(GameObject));
    player->type = PLAYER;
    player->player.health = 100;
    player->player.attack = 20;
    map[0][0].object = player;
    playerRow = 0;
    playerCol = 0;

    // Add enemy
    GameObject* enemy = malloc(sizeof(GameObject));
    enemy->type = ENEMY;
    enemy->enemy.health = 50;
    enemy->enemy.damage = 10;
    map[2][2].object = enemy;

    // Add wall
    GameObject* wall = malloc(sizeof(GameObject));
    wall->type = WALL;
    wall->wall.symbol = '#';
    map[4][1].object = wall;

    // Add item
    GameObject* item = malloc(sizeof(GameObject));
    item->type = ITEM;
    strcpy(item->item.name, "Potion");
    item->item.value = 25;
    map[1][3].object = item;
}

void displayMap() {
    printf("\nMap:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            GameObject* obj = map[i][j].object;
            if (obj == NULL) {
                printf(". ");
            } else {
                switch (obj->type) {
                    case PLAYER: printf("P "); break;
                    case ENEMY:  printf("E "); break;
                    case WALL:   printf("# "); break;
                    case ITEM:   printf("I "); break;
                    default:     printf("? ");
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

void movePlayer(char direction) {
    int newRow = playerRow;
    int newCol = playerCol;

    switch (direction) {
        case 'w': case 'W': newRow--; break;
        case 's': case 'S': newRow++; break;
        case 'a': case 'A': newCol--; break;
        case 'd': case 'D': newCol++; break;
        default:
            printf("Invalid input!\n");
            return;
    }

    // Bounds check
    if (newRow < 0 || newRow >= ROWS || newCol < 0 || newCol >= COLS) {
        printf("Cannot move out of bounds!\n");
        return;
    }

    GameObject* target = map[newRow][newCol].object;

    // Check collision
    if (target != NULL) {
        if (target->type == WALL) {
            printf("There's a wall. You can't pass!\n");
            return;
        } else if (target->type == ENEMY) {
            printf("You encountered an enemy! Fighting...\n");
            // Simple fight logic
            target->enemy.health -= map[playerRow][playerCol].object->player.attack;
            if (target->enemy.health <= 0) {
                printf("Enemy defeated!\n");
                free(target);
                map[newRow][newCol].object = NULL;
            } else {
                printf("Enemy still alive with %d HP.\n", target->enemy.health);
                return;
            }
        } else if (target->type == ITEM) {
            printf("You picked up a %s worth %d points!\n", target->item.name, target->item.value);
            free(target);
            map[newRow][newCol].object = NULL;
        }
    }

    // Move player
    map[newRow][newCol].object = map[playerRow][playerCol].object;
    map[playerRow][playerCol].object = NULL;
    playerRow = newRow;
    playerCol = newCol;
}

void freeObjects() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (map[i][j].object != NULL)
                free(map[i][j].object);
}
