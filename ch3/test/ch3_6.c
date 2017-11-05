#include <stdio.h>

int main(void) {
    float quality_of_water_molecule = 3.0E-23f;
    int quart_of_water = 950;
    int quarts;
    printf("Enter quarts: ");
    scanf("%d", &quarts);
    printf("Numbers of water molecule are %e\n", 
            quarts * quart_of_water / quality_of_water_molecule);

    return 0;
}
