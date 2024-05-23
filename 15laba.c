#include <stdio.h>
#include <string.h>

struct Flight {
    char destination[50];
    int flightNumber;
    char planeType[20];
};

int main() {
    FILE *file = fopen("Spravka.dat", "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    struct Flight flights[] = {
        {"Москва", 101, "Boeing 737"},
        {"Лондон", 202, "Airbus A320"},
        {"Новосибирск", 303, "Boeing 777"}
    };

    fwrite(flights, sizeof(struct Flight), 3, file);
    fclose(file);

    char searchDestination[50];
    printf("пункт назначения: ");
    scanf("%s", searchDestination);

    file = fopen("Spravka.dat", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    struct Flight flight;
    int found = 0;

    while (fread(&flight, sizeof(struct Flight), 1, file)) {
        if (strcmp(flight.destination, searchDestination) == 0) {
            printf("номеров рейса: %d\n", flight.flightNumber);
            found = 1;
        }
    }

    if (!found) {
        printf("No flights found for destination: %s\n", searchDestination);
    }

    fclose(file);

    return 0;
}
