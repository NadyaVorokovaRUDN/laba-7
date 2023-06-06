
#include <stdio.h>
#include <string.h> 
#include <time.h> 
#include <unistd.h> 

int PrintingArr (char words[10][100]) { 
    for (int i = 0; i < 10; i++) {
        printf ("%s\n", words[i]);
    }
    return 0;
}

int SelectionSort (char words[10][100]) { 
    char a[100];  
    int itertion = 0; 
    int min; 
    double time_spent = 0.0;
    clock_t begin = clock();
    for (int i = 0; i < 10 - 1; i++) {
        min = i;
        for (int j = i + 1; j < 10; j++) {
            if (strcmp (words[j], words[min]) < 0) {
                min = j;
            }
        }
        strcpy (a, words[i]);
        strcpy (words[i], words[min]);
        strcpy (words[min], a);
        itertion++;
        printf ("Итерация %d\n", itertion);
        PrintingArr(words);
    }
    sleep(3);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf ("Ваш отсортированный массив (метод Selection Sort): \n");
    PrintingArr(words);
    printf ("Количество итераций: %d\n", itertion);
    printf ("Время выполнения функции: ");
    printf("%f\n", time_spent);

    return 0; 
}

int BubbleSort (char words[10][100]) { 
    int itertion = 0; 
    char a[100];
    double time_spent = 0.0;
    clock_t begin = clock();
    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 10 - 1; j > i; j--) {
            if (strcmp(words[j - 1], words[j]) > 0) {
                strcpy (a, words[j - 1]);
                strcpy (words[j - 1], words[j]);
                strcpy (words[j], a);
                itertion++;
                printf ("Итерация %d\n", itertion);
                PrintingArr(words);
            }
        }
    }
    sleep(3);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf ("Ваш отсортированный массив (метод Bubble Sort): \n");
    PrintingArr(words);
    printf ("Количество итераций: %d\n", itertion);
    printf ("Время выполнения функции: ");
    printf("%f\n", time_spent);

    return 0;
}

int CombSort (char (*words_ukazatel)[100]) { 
    int itertion = 0; 
    float rfactor = 1.24733;
    int j, swaps = 1, gap = 10;
    char q[100];
    double time_spent = 0.0;
    clock_t begin = clock();
    while (gap > 1 || swaps) {
        gap = (int)(gap / rfactor);
        if (gap < 1) {
            gap = 1;
        }
        swaps = 0;

        for (int i = 0; i < 10 - gap; ++i) {
            j = i + gap;
            if (strcmp (*(words_ukazatel+i), *(words_ukazatel+j)) > 0) {
                strcpy (q, *(words_ukazatel+i));
                strcpy (*(words_ukazatel+i), *(words_ukazatel+j));
                strcpy (*(words_ukazatel+j), q);
                itertion++;
                printf ("Итерация %d\n", itertion);
                PrintingArr(words_ukazatel);                
                swaps = 1;
            }
        }
    }
    sleep(3);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf ("Ваш отсортированный массив (метод Сomb Sort): \n");
    PrintingArr(words_ukazatel);
    printf ("Количество итераций: %d\n", itertion);
    printf ("Время выполнения функции: ");
    printf("%f\n", time_spent);

    return 0;
}

int main () {
    char words [10][100];
    char old_arr[10][100]; 
    char old_arr2[10][100];
    int search;

    printf ("Какой алгоритм вы хотите использовать?\n");
    printf ("1. Сортировка выбором\n");
    printf ("2. Сортировка пузырьком\n");
    printf ("3. Сортировка расчёской\n");
    printf ("4. Все сортировки\n");
    scanf("%d", &search);

    printf("Введите 10 слов: ");
    for (int i = 0; i < 10; i++) {
        scanf("%s", &words[i]);
        strcpy (old_arr[i], words[i]);  
        strcpy (old_arr2[i], words[i]);
    }
    
   char (*words_ukazatel)[100] = words; 
   char (*old_arr2_ukazatel)[100] = old_arr2;

    if (search == 1) {
        SelectionSort (words);
    }
    else if (search == 2) {
        BubbleSort (words);
    }
    else if (search == 3) {
        CombSort (words_ukazatel);
    }
    else if (search == 4) {
        SelectionSort (words);
        BubbleSort (old_arr);
        CombSort (old_arr2_ukazatel);
    }

    return 0;
}