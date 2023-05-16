//
// ated by usuario on 16/05/2023.
#include "utils.h"
//
void init_list(LinkedList* l) {
    l->start = NULL;

}


void insert_into_list(LinkedList* l, char* c) {
    Node* newElem = (Node*) malloc(sizeof(Node));
    strcpy(newElem->data, c);

    newElem->next = l->start;
    if (l->start != NULL)
        l->start->prev = newElem;
    newElem->prev = NULL;

    l->start = newElem;
}

Node* find_in_list(LinkedList l, char* word) {
    Node *temp = l.start;
    while(temp !=NULL){
        if (strcmp(temp->data,word) == 0){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void str_to_lowercase(char *s) {
    while (*s != '\0') {
        if (*s >= 65 && *s <= 90) *s += 32;
        s++;
    }
}