#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int arr[], int n)
{
    srand(time(NULL));
    int i; 
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void fillArrayFromKeyboard(int arr[], int n)
{
    printf("Vvedite elementy massiva:\n");
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void fillArrayFromFile(int arr[], int n, char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Oshibka otkrytia faila.\n");
        return;
    }
	int i;
    for (i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            printf("Oshibka chtenia massiva.\n");
            return;
        }
    }

    fclose(file);
}

void binaryInsertionSort(int arr[], int n, int* comparisons, int* swaps)
{
	int i;
    for ( i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0;
        int right = i - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            (*comparisons)++;
            if (arr[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
	int j;
        for ( j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
            (*swaps)++;
        }

        arr[left] = key;
    }
}

void shellSort(int arr[], int n, int* comparisons, int* swaps)
{	
	int gap;
    for ( gap = n / 2; gap > 0; gap /= 2) {
    	int i;
        for ( i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            (*comparisons)++;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                (*swaps)++;
            }
            arr[j] = temp;
        }
    }
}

void selectionSort(int arr[], int n, int* comparisons, int* swaps)
{
	int i;
    for (i = 0; i < n - 1; i++) {
        int min_index = i;
        int j;
        for ( j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            (*swaps)++;
        }
    }
}

void printArray(int arr[], int n)
{
    printf("Massiv:\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n = 0;
    int* arr = NULL;
    int comparisons = 0;
    int swaps = 0;
    

    int choice;
    do {
       printf("\nMenu:\n");
	        printf("1. Zapolnit' massiv s klaviatury'\n");
	        printf("2. Zapolnit' massiv iz faila'\n");
	        printf("3. Zapolnit' massiv sluchainimi chislami'\n");
	        printf("4. Sortirovka metodom binarnogo vkluchenia\n");
	        printf("5. Sortirovka metodom Shella\n");
	        printf("6. Sortirovka metodom prostogo vibora\n");
	        printf("7. Vivesti massiv na ekran\n");
	        printf("8. Vivesti kolichestvo sravneniy i peresilok\n");
	        printf("9. Exit\n");


        printf("Viberite opciu: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Vvedite razmer massiva: ");
            scanf("%d", &n);
            arr = (int*)malloc(n * sizeof(int));
            fillArrayFromKeyboard(arr, n);
            printArray(arr, n);
            break;
        case 2:
            printf("Vvedite razmer massiva: ");
            scanf("%d", &n);
            arr = (int*)malloc(n * sizeof(int));
            fillArrayFromFile(arr, n, "input.txt");
            printArray(arr, n);
            break;
        case 3:
            printf("Vvedite razmer massiva: ");
            scanf("%d", &n);
            arr = (int*)malloc(n * sizeof(int));
            generateArray(arr, n);
            printArray(arr, n);
            break;
        case 4:
            n = 100;
            arr = (int*)malloc(n * sizeof(int));
            generateArray(arr, n);
            comparisons = 0;
            swaps = 0;
            binaryInsertionSort(arr, n, &comparisons, &swaps);
            printf("Massiv otsortirovan.\n");
            printf("Kolichestvo sravneniy: %d\n", comparisons);
            printf("Kolichestvo peressilok: %d\n", swaps);
            break;
        case 5:
            n = 100;
            arr = (int*)malloc(n * sizeof(int));
            generateArray(arr, n);
            comparisons = 0;
            swaps = 0;
            shellSort(arr, n, &comparisons, &swaps);
            printf("Massiv otsortirovan.\n");
            printf("Kolichestvo sravneniy: %d\n", comparisons);
            printf("Kolichestvo peressilok: %d\n", swaps);
            break;
        case 6:
            n = 100;
            arr = (int*)malloc(n * sizeof(int));
            generateArray(arr, n);
            comparisons = 0;
            swaps = 0;
            selectionSort(arr, n, &comparisons, &swaps);
            printf("Massiv otsortirovan.\n");
            printf("Kolichestvo sravneniy: %d\n", comparisons);
            printf("Kolichestvo peressilok: %d\n", swaps);
            break;
        case 7:
            printArray(arr, n);
            break;
        case 8:
            printf("Opcia dostupna tol'ko posle sortirovki'.\n");
            break;
        case 9:
            printf("Exit...\n");
            break;
        default:
            printf("Nekorrectniy vibor. Viberite opciu iz menu.\n");
            break;
        }
    } while (choice != 9);

    free(arr);

    return 0;
}
