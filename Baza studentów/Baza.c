#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

void find_student(){
    char imie[30];
    char nazwisko[30];
    printf("\n\nPodaj Imie studenta do wyszukania: ");
    scanf("%s", imie);
    printf("\n\nPodaj Nazwisko studenta do wyszukania: ");
    scanf("%s", nazwisko);

    for (int i = 0; i < id; i++){
        if (strcmp(imie, studenci[i].imie) == 0 && strcmp(nazwisko, studenci[i].nazwisko) == 0){
            printf("\n\nZnaleziono studenta na pozycji %d", i+1);
            printf("\n[%d] %s %s %d %.2f\n", i+1, studenci[i].imie, studenci[i].nazwisko, studenci[i].wiek, studenci[i].srednia);
        }
    }
}

void best_student(){
    float max_avg = studenci[0].srednia;
    int index = 0;
    for (int i = 0; i < id; i++){
        if (max_avg < studenci[i].srednia){
            max_avg = studenci[i].srednia;
            index = i;
        }
    }

    printf("\nNajlepszy student to: [%d] %s %s %d %.2f\n", index+1, studenci[index].imie, studenci[index].nazwisko, studenci[index].wiek, studenci[index].srednia);
}

void all_students_avg(){
    float avg = 0;
    float sum = 0;
    for (int i = 0; i < id; i++){
        sum += studenci[i].srednia;
    }
    avg = sum / id;

    printf("Srednia wszystkich studentow wynosi: %.2f", avg);
}

void sort_students(){

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
                find_student();
                break;
            }
            case 4:{
                best_student();
                break;
            }
            case 5:{
                all_students_avg();
                break;
            }
            case 6:{
                sort_students();
                break;
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