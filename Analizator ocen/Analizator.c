#include <stdio.h>
#include <stdbool.h>

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
    printf("%d\n", length);
    while(!exit){
        //printf("===== ANALIZATOR OCEN =====\n");
        for(int i = 0; i < length; i++){
            printf("%d. %s\n", i + 1, menu[i]);
        }
    }
    return 0;
}