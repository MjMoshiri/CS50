// Implements a dictionary's functionality

#include <stdbool.h>
#include <sys/types.h>
#include "dictionary.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
// Represents a node in a hash table
int word_size = 0;
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
#define N 1024

// Hash table
node *table[N];
bool insert(node *head, char *word)
{
    node *temp = malloc(sizeof(node));
    if (temp == NULL)
    {
        return false;
    }
    temp->next = head->next;
    head->next = temp;
    strcpy(temp->word, word);
    word_size++;
    return true;
}
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int pos;
    int len = strlen(word) + 1;
    char *temp = malloc(sizeof(char) * len);
    for (int i = 0; i < len; i++)
    {
        if (word[i] < 91 && word[i] > 64)
            temp[i] = word[i] + 32;
        else
            temp[i] = word[i];
    }
    pos = hash(temp);
    if (table[pos]->next != NULL)
    {
        node *search;
        search = table[pos];
        do
        {
            search = search->next;
            if (strcmp(search->word, temp) == 0)
            {
                free(temp);
                return true;
            }
        } while (search->next != NULL);
        free(temp);
        return false;
    }
    else
    {
        free(temp);
        return false;
    }
}
unsigned int hash(const char *new_word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *new_word++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return (hash % 1024);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char *new_word = malloc(47 * sizeof(char));
    for (size_t i = 0; i < N; i++)
    {
        table[i] = malloc(sizeof(node));
        table[i]->next = NULL;
    }
    FILE *dic = fopen(dictionary, "r");
    if (!dic)
    {
        return false;
    }

    while (fscanf(dic, " %s", new_word) == 1)
    {
        insert(table[hash(new_word)], new_word);
    }
    free(new_word);
    fclose(dic);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node* temp ;
    for (size_t i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            temp = table[i];
            table[i]=table[i]->next;
            free(temp);
        }
    }
    return true;
}
