#include <stdio.h>
#include <stdlib.h>
double findmin(double* arr, int n, double min){
    if(n==0){
        return min;
    }
    else{
        if (arr[n]>= 3.5 && arr [n] <=8.5){
            if (arr[n]<min){
                min=arr [n];
            }
        }
        return findmin (arr, n-1, min);
        }
}
int main (){
    double min= 8.5;
    int n;
    printf("\nРазмер массива\n");
    scanf("%d",&n);
    double* arr=(double*)malloc(n*sizeof(double));
    for (int i=0; i<n;i++){
        printf("Введите %d элемент массива", i);
        scanf("%lf", &arr[i]);
    }
    for (int i=0; i<n; i++){
        printf ("%.2f", arr[i]);
    }
    printf("\n %.1f \n", findmin(arr, n-1, min));
}