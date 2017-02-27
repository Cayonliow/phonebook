#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt_hash.h"

/*by BKDRHash function*/
//try DJBHash
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; //(2^n)-1, n>=5
    unsigned int hash = 0;

    while (*str)
        hash = hash * seed + (*str++);

    return (hash & 0x7FFFFFFF) % TABLE_SIZE;
}

unsigned int DJBHash(char *str)
{
    unsigned int hash = 5381;

    while (*str) {
        hash += (hash << 5) + (*str++);
    }

    return (hash & 0x7FFFFFFF) % TABLE_SIZE;
}

entry *findName(char lastName[], entry *e[])
{
    //unsigned int hash_value = BKDRHash(lastName);
    unsigned int hash_value = DJBHash(lastName);
    entry *temp = e[hash_value];

    while (temp != NULL) {
        if (strcasecmp(lastName, temp->lastName)==0)
            return e[hash_value];
        temp = e[hash_value]->pNext;
    }
    return NULL;
}

void append(char lastName[], entry *e[])
{
    //unsigned int hash_value = BKDRHash(lastName);
    unsigned int hash_value = DJBHash(lastName);
    entry *temp;

    if (!e[hash_value]) {
        e[hash_value] = (entry *) malloc(sizeof(entry));
        e[hash_value]->pNext = NULL;
        strcpy(e[hash_value]->lastName, lastName);
    } else {
        temp = (entry *) malloc(sizeof(entry));
        temp->pNext = e[hash_value];
        e[hash_value] = temp;
        strcpy(e[hash_value]->lastName, lastName);
    }
}
