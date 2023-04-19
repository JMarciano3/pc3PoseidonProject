#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char food_choice, customer_name[50];
    float sub_total = 0, tax_amount, total_amount, amount_paid, change_amount;
    int item_quantity, i, n;
    time_t current_time;
    char* c_time_string;

    printf("Enter your name: ");
    scanf("%[^\n]", customer_name);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("\nEnter the details of each item:\n");

    for (i = 1; i <= n; i++) {
        printf("\nItem %d:\n", i);
        printf("Food choice (A-F): ");
        scanf(" %c", &food_choice);
        printf("Quantity: ");
        scanf("%d", &item_quantity);

        switch (food_choice) {
            case 'A':
                sub_total += item_quantity * 4.75; // Price of food choice A
                break;
            case 'B':
                sub_total += item_quantity * 12.00; // Price of food choice B
                break;
            case 'C':
                sub_total += item_quantity * 9.50; // Price of food choice C
                break;
            case 'D':
                sub_total += item_quantity * 12.99; // Price of food choice D
                break;
            case 'E':
                sub_total += item_quantity * 7.99; // Price of food choice E
                break;
            case 'F':
                sub_total += item_quantity * 6.99; // Price of food choice F
                break;
            default:
                printf("Invalid food choice. Please try again.\n");
                i--;
                break;
        }
    }

    tax_amount = sub_total * 0.07; // Assuming 7% tax rate
    total_amount = sub_total + tax_amount;

    printf("\nEnter amount paid: $");
    scanf("%f", &amount_paid);

    change_amount = amount_paid - total_amount;

    // Get current time and convert to string format
    current_time = time(NULL);
    c_time_string = ctime(&current_time);

    printf("\n-----------------------\n");
    printf("  POSEIDON RESTAURANT SALES RECEIPT\n");
    printf("-----------------------\n\n");

    printf("Date and Time: %s\n\n", c_time_string);

    printf("Customer Name: %s\n", customer_name);

    printf("\nFood Choices:\n");
    for (i = 1; i <= n; i++) {
        printf("Item %d: Choice %c\n", i, food_choice);
    }

    printf("\nSubtotal: $%.2f\n", sub_total);
    printf("Tax: $%.2f\n", tax_amount);
    printf("Total: $%.2f\n", total_amount);
    printf("Amount Paid: $%.2f\n", amount_paid);
    printf("Change: $%.2f\n", change_amount);

    printf("\n-----------------------\n");

    return 0;
}
