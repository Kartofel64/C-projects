#include <stdio.h>
#include <stdbool.h>

int main(){
    bool exit = false;
    int menu = 0;
    while (!exit)
    {
        printf("Jaki typ tablicy?\n\n");
        printf("1. Jednowymiarowa\n");
        printf("2. Dwuwymiarowa\n");
        printf("3. Wyjscie");
        scanf("%d", &menu);

        switch (menu) {
            case 1: {
                break;
            }
            
            case 2: {
                break;
            }

            case 3:{
                exit = true;
                break;
            }
            
            default: {
                printf("Brak podanego numeru na liscie");
                break;
                }
            }
    }
    
    return 0;
}