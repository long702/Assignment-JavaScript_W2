#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 10

struct Product{
    int productID;
    char name[100];
    float price;
    int quantity;
};
void displayProduct(struct Product p){
    //Your code here
    printf("product ID: %d\n", p.productID);
    printf("Name      : %s\n", p.name);
    printf("Price     : $%.2f\n", p.price);
    printf("Quantity  : %d\n", p.quantity);

}
struct Product findproductByID(struct Product products[], int numProducts, int searchID){
    //Your code here
    for (int i = 0; i < numProducts; i++){
        if (products[i].productID == searchID){
            return products[i];
        }
    }

    struct Product notFound = {-1, "N/A", 0.0, 0};
    return notFound;
}
void updateQuantity(struct Product *p, int newQuantity ){
    //Your code here
    p->quantity = newQuantity;
}
int main(){
    struct Product inventory[MAX_PRODUCTS] = {
        {101, "Laptop", 1200.00, 5},
        {102, "Mouse", 25.50, 20},
        {103, "Keyboard", 75.00, 10}  
};
int numProducts = 3;
    printf("--- Current Inventory ---\n");
for (int i = 0; i < numProducts; i++) {
    displayProduct(inventory[i]); // Pass by value
}
// Search for a product
int searchID;
    printf("\nEnter Product ID to search: ");
    scanf("%d", &searchID);
struct Product foundProduct = findproductByID(inventory, numProducts, searchID);
if (foundProduct.productID != -1) {
    printf("\nProduct Found:\n");
    displayProduct(foundProduct);
} else {
    printf("Product with ID %d not found.\n", searchID);
}
// Update quantity
int updateID, newQty;
    printf("\nEnter Product ID to update quantity: ");
    scanf("%d", &updateID);
    printf("Enter new quantity: ");
    scanf("%d", &newQty);
for (int i = 0; i < numProducts; i++) {
if (inventory[i].productID == updateID) {
    updateQuantity(&inventory[i], newQty); // Pass by pointer to modify
    printf("\nQuantity updated for Product ID %d.\n", updateID);
    displayProduct(inventory[i]);
break;
}
if (i == numProducts - 1) {
    printf("Product with ID %d not found for update.\n", updateID);
}

}

return 0;
}