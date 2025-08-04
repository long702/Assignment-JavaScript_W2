#include <stdio.h>
#include <stdlib.h> 

int main() {
    int num_ratings;
    int* ratings = NULL;
    
    printf("How many ratings will you enter? ");
    scanf("%d", &num_ratings);
    if (num_ratings <= 0) {
        printf("Error: Number of ratings must be positive.\n");
        return 1;
    }
    ratings = (int*)malloc(num_ratings * sizeof(int));
    if (ratings == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < num_ratings; i++) {
        printf("Enter rating #%d: ", i + 1);
        scanf("%d", &ratings[i]);
        while (ratings[i] < 1 || ratings[i] > 10) {
            printf("Rating must be between 1 and 10. Try again.\n");
            printf("Enter rating #%d: ", i + 1);
            scanf("%d", &ratings[i]);
        }
    }
    printf("\nRatings entered: ");
    for (int i = 0; i < num_ratings; i++) {
        printf("%d ", ratings[i]);
    }
    printf("\n");
    free(ratings);
    ratings = NULL;
    return 0;
}