#include <stdio.h>
#include <stdbool.h>

void sort(int array[], int array_elements){
    printf("\n\nTablica przed sortowaniem: ");
    for (int i = 0; i < array_elements; i++){
            printf("%d ", array[i]);
        }
    
    int sorted_array[array_elements];
    for (int i = 0; i < array_elements; i++){
            sorted_array[i] = array[i];
        }
    int tmp = 0;

    for (int i = 0; i < array_elements - 1; i++){
        for (int j = 0; j < array_elements - 1 - i; j++){
            if (sorted_array[j] > sorted_array[j+1]){
                tmp = sorted_array[j+1];
                sorted_array[j+1] = sorted_array[j];
                sorted_array[j] = tmp;
            }
        }
    }

    printf("\n\nTablica po sortowaniu: ");
    for (int i = 0; i < array_elements; i++){
            printf("%d ", sorted_array[i]);
        }
}

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

        int sum = 0, min = 0, max = 0, odd = 0, even = 0;
        float avg = 0;

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
            if (array[i] % 2 == 0){
                even++;
            }else{
                odd++;
            }
        }

        avg = (float)sum / array_elements;

        printf("\n");

        for (int i = 0; i < array_elements; i++){
            printf("%d ", array[i]);
        }

        printf("\n");

        printf("\nSuma: %d", sum);
        printf("\nSrednia: %.2f", avg);
        printf("\nMinimum: %d", min);
        printf("\nMaksimum: %d", max);
        printf("\nLiczba parzystych: %d", even);
        printf("\nLiczba nieparzystych: %d", odd);

        sort(array, array_elements);
    }
}

int main(){
    bool exit = false;
    int menu = 0;
    while (!exit)
    {
        printf("\n\nJaki typ tablicy?\n\n");
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