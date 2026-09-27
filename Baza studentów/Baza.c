#include <stdio.h>
#include <stdbool.h>

int id = 0;
struct Student {
    char imie[30];
    char nazwisko[30];
    int wiek;
    float srednia;
};

struct Student studenci[100];

void add_student(){
    printf("\n\nPodaj imie studenta: ");
    scanf("%s", studenci[id].imie);
    printf("\n\nPodaj nazwisko sudenta: ");
    scanf("%s", studenci[id].nazwisko);
    printf("\n\nPodaj wiek studenta: ");
    scanf("%d", &studenci[id].wiek);
    printf("\n\nPodaj srednia studenta: ");
    scanf("%f", &studenci[id].srednia);

    id++;
}

void show_students(){
    for (int i = 0; i < id; i++){
        printf("\n[%d] %s %s %d %.2f\n", i+1, studenci[i].imie, studenci[i].nazwisko, studenci[i].wiek, studenci[i].srednia);
    }
}

int main(){
    bool exit = false;
    int menu = 0;

    while(!exit){
        printf("\n===== BAZA STUDENTÓW =====\n\n");
        printf("1. Dodaj studenta\n");
        printf("2. Wyświetl studentów\n");
        printf("3. Znajdź studenta\n");
        printf("4. Najlepszy student\n");
        printf("5. Średnia wszystkich\n");
        printf("6. Posortuj po średniej\n");
        printf("7. Usuń studenta\n");
        printf("0. Wyjście\n");

        scanf("%d", &menu);

        switch (menu){
            case 1:{
                add_student();
                break;
            }
            case 2:{
                show_students();
                break;
            }
            case 3:{

            }
            case 4:{

            }
            case 5:{

            }
            case 6:{

            }
            case 7:{

            }
            case 0:{
                exit = true;
                break;
            }
            default:{
                printf("Niepoprawny numer");
                break;
            }
        }
    }
    return 0;
}