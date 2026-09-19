#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int grades[10];
int grades_count;

void add_grade(){
    printf("Ile ocen chcesz podac? ");
    scanf("%d", &grades_count);

    for (int i = 0; i < grades_count; i++) {
        printf("Podaj ocene: ");
        scanf("%d", &grades[i]);
    }
};

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
        //printf("===== ANALIZATOR OCEN =====\n");
        for(int i = 0; i < length; i++){
            printf("%d. %s\n", i + 1, menu[i]);
        }
        printf("Wybierz opcje: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_grade();
                break;
            case 7:
                exit = true;
        }
    }
    return 0;
}