#include <stdio.h>

#define ARTICHOKE_PRICE 2.05
#define BEET_PRICE 1.15
#define CARROT_PRICE 1.09

#define DISCOUNT_LIMIT 100
#define DISCOUNT_RATE 0.05

#define WEIGHT_BREAK1 5
#define WEIGHT_BREAK2 20

#define FREIGHT1 6.5
#define FREIGHT2 14.0
#define FREIGHT_OVER_BREAK2 0.5

int main(void) {
    char ch;
    float temp_weight;
    float artichoke_weight, beet_weight, carrot_weight;
    artichoke_weight = beet_weight = carrot_weight = 0.0;
    float total_weight = 0.0;
    float order_price, total_price, vegetables_price,
          freight_price, discount_price;
    order_price = total_price = vegetables_price = 
        freight_price = discount_price = 0.0;

    while (1) {
        printf("Please choose what you want: \n");
        printf("a) Artichoke %f $/pound\n", ARTICHOKE_PRICE);
        printf("b) Beet %f $/pound\n", BEET_PRICE);
        printf("c) Carrot %f $/pound\n", CARROT_PRICE);
        printf("q) quit\n");
        scanf("%c", &ch);
        
        if (ch == 'q')
            break;
        
        printf("Please enter weight: ");
        scanf("%f", &temp_weight);
        switch (ch) {
            case 'a':
                artichoke_weight += temp_weight;
                break;
            case 'b':
                beet_weight += temp_weight;
                break;
            case 'c':
                carrot_weight += temp_weight;
                break;
            default:
                printf("Invalid input!\n");
                break;
        }

        while ((ch = getchar()) != '\n')
            continue;
    }

    total_weight = artichoke_weight + beet_weight + carrot_weight;
    vegetables_price = artichoke_weight * ARTICHOKE_PRICE +
        beet_weight * BEET_PRICE + carrot_weight * CARROT_PRICE;
    
    if (order_price >= DISCOUNT_LIMIT)
        discount_price = DISCOUNT_RATE * order_price;
    order_price = vegetables_price - discount_price;
    
    if (total_weight <= 0)
        freight_price = 0.0;
    else if (total_weight <= WEIGHT_BREAK1) 
        freight_price = FREIGHT1;
    else if (total_weight <= WEIGHT_BREAK2)
        freight_price = FREIGHT2;
    else
        freight_price = FREIGHT2 + 
            (total_weight - WEIGHT_BREAK2) * FREIGHT_OVER_BREAK2;
    
    total_price = order_price - discount_price + freight_price;

    printf("Artichoke price: %.2f $/pound, weight: %.2f pound\n", 
            ARTICHOKE_PRICE, artichoke_weight);
    printf("Beet price: %.2f $/pound, weight: %.2f pound\n",
            BEET_PRICE, beet_weight);
    printf("Carrot price: %.2f $/pound, weight: %.2f pound\n",
            CARROT_PRICE, carrot_weight);
    printf("Vegetables price: %.2f\n", vegetables_price);
    printf("Order price: %.2f\n", order_price);
    printf("Discount: %.2f\n", discount_price);
    printf("Freight price: %.2f\n", freight_price);
    printf("Total price: %.2f\n", total_price);

    return 0;
}
