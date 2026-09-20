#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int grades[20];
int grades_count;

void add_grade(){
    printf("\nIle ocen chcesz podac? ");
    scanf("%d", &grades_count);
    if (grades_count < 20 && grades_count > 0){
        for (int i = 0; i < grades_count; i++) {
            printf("\nPodaj ocene: ");
            scanf("%d", &grades[i]);
            if (grades[i] > 6 || grades[i] < 2){
                printf("Liczba powinna byc z zakrasu <2, 6>");
                i--;
            }
        }
    }else {
        printf("Nie mozna dodac wiecej niz 20 i mniej niz 0");
        add_grade();
    } 
};

void show_grades(){
    if (grades_count != 0) {
        for (int i = 0; i < grades_count; i++){
            printf("\nOcena %d: ", i+1);
            printf("%d \n", grades[i]);
        }
    } else{
        printf("\nBrak ocen\n\n");
    }
};

float avg(){
    if (grades_count != 0) {
        float avg = 0;
        int sum = 0;

        for (int i = 0; i < grades_count; i++){
            sum += grades[i];
        }
        avg = (float)sum / grades_count;
        return avg;
    } else{
        printf("\nBrak ocen\n\n");
        return 0;
    }
};

int find_max(){
    if (grades_count != 0) {
        int max = grades[0];
        for (int i = 0; i < grades_count; i++){
            if (max < grades[i]){
                max = grades[i];
            }
        }
        return max;
    } else{
        printf("\nBrak ocen\n\n");
        return 0;
    }
};

int find_min(){
    if (grades_count != 0) {
        int min = grades[0];
        for (int i = 0; i < grades_count; i++){
            if (min > grades[i]){
                min = grades[i];
            }
        }
        return min;
    } else{
        printf("\nBrak ocen\n\n");
        return 0;
    }
}

int count_passed(){
    if (grades_count != 0) {
        int passed = 0;
        for (int i = 0; i < grades_count; i++){
            if (grades[i] >= 3){
                passed += 1;
            }
        }
        return passed;
    } else{
        printf("\nBrak ocen\n\n");
        return 0;
    }
}

int main(){

    bool exit = false;
    const char *menu[] = {
    "Dodaj ocene",
    "Pokaz wszystkie oceny",
    "Policz srednia",
    "Znajdz najwyzsza ocene",
    "Znajdz najnizsza ocene",
    "Policz zdane przedmioty",
    "Wyjscie"
};

    int length = sizeof(menu) / sizeof(menu[0]);
    int choice = 0;
    while(!exit){
        printf("===== ANALIZATOR OCEN =====\n\n");
        for(int i = 0; i < length; i++){
            printf("%d. %s\n", i + 1, menu[i]);
        }
        printf("\nWybierz opcje: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: {
                add_grade();
                break;
            }
            case 2: {
                show_grades();
                break;
            }
            case 3: {
                float output = avg();
                printf("\nSrednia ocen to: %.2f\n\n", output);
                break;
            }
            case 4: {
                int output = find_max();
                printf("\nNajwieksza ocena to: %d\n\n", output);
                break;
            }
            case 5: {
                int output = find_min();
                printf("\nNajmniejsza ocena to: %d\n\n", output);
                break;
            }
            case 6: {
                int output = count_passed();
                printf("\nLiczba zaliczonych przedmiotow to: %d\n\n", output);
                break;
            }
            case 7: {
                exit = true;
            }
        }
    }
    return 0;
}