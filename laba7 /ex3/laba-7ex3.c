
#include <stdio.h>

int main () {
    char word[100];
    char *word_ukazatel; 
    char glasnue_letters[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    char *glasnue_letters_ukazatel;
    int glasnue = 0, soglacnue; 
    printf ("Введите слово: ");
    scanf ("%s", &word);
    word_ukazatel  = word;
    glasnue_letters_ukazatel = glasnue_letters;
    for (int i = 0; *(word_ukazatel+i)!='\0'; i++) {
        for (int j = 0; j < 6; j++) {
            if (*(word_ukazatel+i) == *(glasnue_letters_ukazatel+j)) {
                glasnue++;
            }
        }
         soglacnue = i - glasnue + 1;
    }

    printf ("Количество согласных: %d\n", soglacnue);
    printf ("Количество гласных: %d\n", glasnue);

    return 0;
}