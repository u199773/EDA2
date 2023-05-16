//
// Created by usuario on 16/05/2023.
//
#define MAX_WORD_LENGTH 60
#ifndef LABEDA2_UTILS_H
#define LABEDA2_UTILS_H
#include <stdlib.h>
#define NULL ((void *)0)

char * __cdecl strcpy(char * __restrict__ _Dest,const char * __restrict__ _Source);
int __cdecl strcmp(const char *_Str1,const char *_Str2);
#endif //LABEDA2_UTILS_H


typedef struct _Node {
    //char* data;
    char data[MAX_WORD_LENGTH];
    struct _Node* next;
    struct _Node* prev;
} Node;

typedef struct {

    Node* start;
} LinkedList;

void str_to_lowercase(char *s);