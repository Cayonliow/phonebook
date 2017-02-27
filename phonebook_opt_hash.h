#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define TABLE_SIZE 100000

#define OPT_HASH 1

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    /*3rd version: by BKDRHash function*/
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __PHONE_BOOK_ENTRY *pNext;
} secondary_entry;

typedef struct __LAST_NAME_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    secondary_entry *detail;
    struct __LAST_NAME_ENTRY *pNext;
} entry;


entry *findName(char lastName[], entry *e[]);
void append(char lastName[], entry *e[]);
unsigned int BKDRHash(char *str);
unsigned int DJBHash(char *str);

#endif
