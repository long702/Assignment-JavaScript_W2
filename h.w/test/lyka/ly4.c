#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10
#define WALL '#'
#define PATH '.'
#define START 'S'
#define GOAL 'G'
#define VISITED '*'

// Maze grid
char maze[SIZE][SIZE];

// Node structure for A*
typedef struct {
    int x, y;
    int g, h, f;
    int parentX, parentY;
    int visited;
} Node;

Node nodes[SIZE][SIZE];

// Movement directions: up, down, left, right
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// Function prototypes
void generateMaze();
void printMaze();
int isValid(int x, int y);
int isWalkable(int x, int y);
int heuristic(int x, int y);
void aStar();

int main() {
    srand(time(0));
    generateMaze();
    printf("Generated Maze:\n");
    printMaze();
    printf("\nRunning A* Pathfinding...\n");
    aStar();
    printf("\nMaze After A* Pathfinding:\n");
    printMaze();
    return 0;
}

// Generate random maze with some walls
void generateMaze() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            maze[i][j] = (rand() % 100 < 25) ? WALL : PATH;
            nodes[i][j].x = i;
            nodes[i][j].y = j;
            nodes[i][j].visited = 0;
        }
    }
    maze[0][0] = START;
    maze[SIZE-1][SIZE-1] = GOAL;
}

// Print the maze
void printMaze() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Check bounds
int isValid(int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}

// Check if cell is walkable
int isWalkable(int x, int y) {
    return maze[x][y] == PATH || maze[x][y] == GOAL;
}

// Manhattan distance
int heuristic(int x, int y) {
    return abs(x - (SIZE - 1)) + abs(y - (SIZE - 1));
}

// A* Algorithm
void aStar() {
    Node *openList[SIZE * SIZE];
    int openSize = 0;

    // Initialize start node
    Node *start = &nodes[0][0];
    start->g = 0;
    start->h = heuristic(0, 0);
    start->f = start->g + start->h;
    start->parentX = -1;
    start->parentY = -1;
    openList[openSize++] = start;

    while (openSize > 0) {
        // Find node with lowest f
        int minIndex = 0;
        for (int i = 1; i < openSize; i++) {
            if (openList[i]->f < openList[minIndex]->f)
                minIndex = i;
        }

        Node *current = openList[minIndex];

        // Remove from open list
        for (int i = minIndex; i < openSize - 1; i++)
            openList[i] = openList[i + 1];
        openSize--;

        int cx = current->x;
        int cy = current->y;
        current->visited = 1;

        // Goal found
        if (maze[cx][cy] == GOAL) {
            int px = current->parentX;
            int py = current->parentY;
            while (px != -1 && py != -1 && maze[px][py] != START) {
                maze[px][py] = VISITED;
                int tx = nodes[px][py].parentX;
                int ty = nodes[px][py].parentY;
                px = tx;
                py = ty;
            }
            return;
        }

        // Check neighbors
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (isValid(nx, ny) && isWalkable(nx, ny) && !nodes[nx][ny].visited) {
                int newG = current->g + 1;
                int newH = heuristic(nx, ny);
                int newF = newG + newH;

                Node *neighbor = &nodes[nx][ny];
                if (neighbor->f == 0 || newF < neighbor->f) {
                    neighbor->g = newG;
                    neighbor->h = newH;
                    neighbor->f = newF;
                    neighbor->parentX = cx;
                    neighbor->parentY = cy;
                    openList[openSize++] = neighbor;
                }
            }
        }
    }

    printf("No path found!\n");
}