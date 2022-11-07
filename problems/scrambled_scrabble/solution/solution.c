#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isVowel(char a);

int main(void)
{
    char word[1024];
    char letterBank[1024];
    char nBuffer[10];
    int n;

    fgets(nBuffer, 1026, stdin);
    n = atoi(nBuffer);
    fgets(word, 1026, stdin);
    fgets(letterBank, 1025, stdin);

    int vowelIndex = 0;
    // Find index of vowels
    for (int i = 0; i < n; i++)
    {
        if (word[i] != '-')
        {
            if (isVowel(word[i]))
            {
                vowelIndex = i % 2;
            }
            else
            {
                vowelIndex = (i + 1) % 2;
            }
        }
    }

    // Replace each item with its maximum value
    int counts[2] = {0, 0}; // counts[0] = consonant index count, counts[1] = vowel index counts
    for (int i = 0; i < n; i++)
    {
        if (word[i] != '-')
        {
            continue;
        }
        int searchInd = i % 2 == vowelIndex;

        for (int j = counts[searchInd]; j < n; j++)
        {
            if ((searchInd && isVowel(letterBank[j])) || (!searchInd && !isVowel(letterBank[j])))
            {
                word[i] = letterBank[j];
                counts[searchInd] = j + 1;
                break;
            }
        }
        if (word[i] == '-')
        {
            printf("Cannot be done!\n");
            exit(0);
        }
    }
    int finalScore = 0;

    for (int i = 0; i < n; i++)
    {
        finalScore += word[i] - 'a' + 1;
    }
    printf("%d\n", finalScore);
}

bool isVowel(char a)
{
    if ((a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
