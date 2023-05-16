
#ifndef LABEDA2_FUNCIONS_H
#define LABEDA2_FUNCIONS_H
#include "main.c"
#include <stdio.h>
#include <stdlib.h>

void insertUser(User **users, int *numUsers) {
    User *newUser = (User*)malloc(sizeof(User));

    printf("\n---- Insertar Nuevo Usuario ----\n");
    printf("Nombre de usuario: ");
    scanf("%s", newUser->username);
    printf("Edad: ");
    scanf("%d", &newUser->age);
    printf("Correo electrónico: ");
    scanf("%s", newUser->email);
    printf("Ubicación actual: ");
    scanf("%s", newUser->location);
    printf("Gustos o preferencias (separados por comas): ");
    scanf("%s %s %s %s %s", newUser->likes[0], newUser->likes[1], newUser->likes[2], newUser->likes[3], newUser->likes[4]);

    *users = (User*)realloc(*users, (*numUsers + 1) * sizeof(User));
    (*users)[*numUsers] = *newUser;
    (*numUsers)++;

    free(newUser);

    printf("Usuario agregado con éxito.\n");
}
#endif //LABEDA2_FUNCIONS_H

