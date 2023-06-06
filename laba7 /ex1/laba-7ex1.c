/* Ответы на вопросы:
    1. Возьмем такой словарь: cat, dog, dollar, amazing, cucumber, iphone, beuty, volleyboll, 
    tomato, cofee. //замета слов на любые анг слова 

    В результате сортировки первого словаря мы видим такие результаты: / нужно будет ввести свои слова 

        1. Сортировка выбором: 4 итераций,  0.000284 секунда
        2. Сортировка пузырьком: 17 итераций, 0.000608 секунд
        3. Сортировка расчёской: 7 итераций,  0.000284 секунд



    Это позволяет нам сделать вывод, что сортировка выбором - лучшее решение.
    За меньшее количество итераций и меньшее количество секунд она способна отсортировать любой словарь. 

    

    2. Нет, каждая из сортировок выполнялась за разное время, и в подтверждение этому можно 
    посмотреть на данные из ответа на первый вопрос. Это и очевидно: в сортировке пузырьком, например,
    сраниваются соседние элементы - что в общем случае более времязатратно. В сортировке выборкой,
    например, при каждой итерации ищется наименьший элемент, и количество итераций в данном
    случае ВСЕГДА будет равно количество элементов минус единица, что, в общем случае, менее 
    времязатратно.
*/

#include <stdio.h>
#include <string.h> 
#include <time.h> 
#include <unistd.h> 

int PrintingArr (char words[10][100]) { // замена на инг и на арр 
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

int CombSort (char words[10][100]) { 
    int itertion = 0;  
    float rfactor = 1.24733; 
    int j, swaps = 1, gap = 10;
    char a[100];  
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
            if (strcmp (words[i], words[j]) > 0) {
                strcpy (a, words[i]);
                strcpy (words[i], words[j]);
                strcpy (words[j], a);
                itertion++;
                printf ("Итерация %d\n", itertion);
                PrintingArr(words);                
                swaps = 1;
            }
        }
    }
    sleep(3);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf ("Ваш отсортированный массив (метод Сomb Sort): \n");
    PrintingArr(words);
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
    
    if (search == 1) {
        SelectionSort (words);
    }
    else if (search == 2) {
        BubbleSort (words);
    }
    else if (search == 3) {
        CombSort (words);
    }
    else if (search == 4) {
        SelectionSort (words);
        BubbleSort (old_arr);
        CombSort (old_arr2); 
    }

    return 0;
}