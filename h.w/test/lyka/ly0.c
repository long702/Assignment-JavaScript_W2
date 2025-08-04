#include <stdio.h>
typedef struct {
    float x;
    float y;
} Point;
typedef struct {
    Point topLeft;
    Point bottomRight;
} Rectangle;
// Function to compute perimeter
int getPerimeter(Rectangle rect) {
	// @todo
   if(topleft x1 > x2 && y1 > y2){
      printf("1 ,2")
   }else if( Bottomright x1 ){
      printf("")
   }
}
int main() {
    Rectangle rect;
    // Read top-left point
    scanf("%f %f", &rect.topLeft.x, &rect.topLeft.y);
    // Read bottom-right point
    scanf("%f %f", &rect.bottomRight.x, &rect.bottomRight.y);
    int result = getPerimeter(rect);
    printf("%d\n", result);
    return 0;
}

