#include <stdio.h>
#include <stdbool.h>

void array_stats(){
    int array_elements;
    printf("\nPodaj liczbe elementow tablicy: ");
    scanf("%d", &array_elements);
    if (array_elements < 0){
        printf("Liczba nie może być ujemna-!\n");
    }else{
        int array[array_elements];
        for (int i = 0; i < array_elements; i++){
            printf("\nPodaj %d element tablicy: ", i+1);
            scanf("%d", &array[i]);
        }

        int sum, min, max, odd, even;
        float avg;

        min = array[0];
        max = array[0];

        for (int i = 0; i < array_elements; i++){
            sum += array[i];
            if (max < array[i]){
            max = array[i];
            }
            if (min > array[i]){
            min = array[i];
            }
        }

        avg = sum / array_elements;
    }
}


int main(){
    bool exit = false;
    int menu = 0;
    while (!exit)
    {
        printf("\nJaki typ tablicy?\n\n");
        printf("1. Jednowymiarowa\n");
        printf("2. Dwuwymiarowa\n");
        printf("3. Wyjscie\n\n");
        scanf("%d", &menu);

        switch (menu) {
            case 1: {
                array_stats();
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