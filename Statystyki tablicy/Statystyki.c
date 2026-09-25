#include <stdio.h>
#include <stdbool.h>

void matrix(){
    int row = 0, col = 0;

    printf("\n\nPodaj liczbe w poziomie: ");
    scanf("%d", &row);

    printf("\n\nPodaj liczbe w pionie: ");
    scanf("%d", &col);

    if (row <= 0 || col <= 0){
        printf("\n\nLiczba musi byc dodatnia");
    }else{
        int matrix_array[row][col];

        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                printf("\n\nPodaj element [%d][%d]: \n", i+1, j+1);
                scanf("%d", &matrix_array[i][j]);
            }
        }

        printf("\n\n");

        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                printf("%d ", matrix_array[i][j]);
            }
            printf("\n");
        }

        int sum = 0, max = matrix_array[0][0], sumR = 0;

        int collsum[col];
        int rowsum[row];

        for (int j = 0; j < col; j++) {
            collsum[j] = 0;
        }

        for (int i = 0; i < row; i++) {
            sumR = 0;

            for (int j = 0; j < col; j++) {
                sum += matrix_array[i][j];

                if (max < matrix_array[i][j]) {
                    max = matrix_array[i][j];
                }

                sumR += matrix_array[i][j];
                collsum[j] += matrix_array[i][j];
            }

            rowsum[i] = sumR;
        }


        printf("\n\nSuma wszystkich elementow: %d", sum);
        printf("\nNajwiekszy element: %d", max);
        printf("\nSuma wierszy: ");
        for (int i = 0; i < row; i++){
            printf("%d ", rowsum[i]);
        }
        printf("\nSuma kolumn: ");
        for (int i = 0; i < col; i++){
            printf("%d ", collsum[i]);
        }
    }
}

void search(int sorted_array[], int array_elements){
    int number = 0;
    printf("\n\nPodaj liczbe do wyszukania: ");
    scanf("%d", &number);

    int index[array_elements];

    for (int i = 0; i < array_elements; i++){
        index[i] = false;
    }

    for (int i = 0; i < array_elements; i++){
        if (sorted_array[i] == number){
            index[i] = true;
        }
    }

    printf("\n\nLiczba jest na pozycji: ");
    for (int i = 0; i < array_elements; i++){
        if (index[i] == true){
            printf("%d ", i+1);
        }
    }
}

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

    search(sorted_array, array_elements);
}

void array_stats(){
    int array_elements;
    printf("\nPodaj liczbe elementow tablicy: ");
    scanf("%d", &array_elements);
    if (array_elements <= 0){
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
                matrix();
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