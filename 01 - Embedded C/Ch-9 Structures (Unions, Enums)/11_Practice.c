#include <stdio.h>

int main() {
    
    // enum Cars{Audi A3=1, BMW 3 Series, Chevrolet Cruze, Honda Insight (Hybrid), Toyota Prius (Hybrid)};
    enum Cars{Audi_A3=5, BMW_3_Series, Chevrolet_Cruze, Honda_Insight, Toyota_Prius};
    
    int choice;
    
    printf("Whose mileage you want to know :\n1.Audi A3\n2.BMW 3 Series\n3.Chevrolet Cruze\n4.Honda Insight (Hybrid)\n5.Toyota Prius (Hybrid)\n\n");

    scanf("%d",&choice);
    
    switch(choice)
    {
        case Audi_A3:
        printf("City: 11.5 km/l\nHighway: 15.3 km/l\nCombined: 13.2 km/l");
        break;

        case BMW_3_Series:
        printf("City: 11.0 km/l\nHighway: 15.3 km/l\nCombined: 12.8 km/l");
        break;

        case Chevrolet_Cruze:
        printf("City: 11.9 km/l\nHighway: 16.1 km/l\nCombined: 13.6 km/l");
        break;

        case Honda_Insight:
        printf("City: 23.3 km/l\nHighway: 20.8 km/l\nCombined: 22.1 km/l");
        break;

        case Toyota_Prius:
        printf("City: 23.0 km/l\nHighway: 21.3 km/l\nCombined: 22.1 km/l");
        break;

        default:
        break;
    }

    return 0;
}