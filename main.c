#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include <time.h>


void get_username(Node** userList) {
    char username[20];
    printf("Ingrese el nombre de usuario: ");
    scanf("%s", username);
    add_user(userList, username);
}



void imprimir_lista(Node* userList) {
    Node* current = userList;
    printf("Lista de usuarios:\n");
    while (current != NULL) {
        imprimir_user_info(current->user);
        current = current->next;
    }
}
//Node* llamar_buscar_usuario(Node* userList) {
// char username[MAX_USERNAME_LENGTH];
//  printf("Ingrese el nombre de usuario: ");
// scanf("%s", username);

//  Node* usuarioEncontrado = buscar_usuario(userList, username);
//  return usuarioEncontrado;
//}
int llamar_submenu(Node* userList, int* mainOption) {
    char username[MAX_USERNAME_LENGTH];
    printf("Ingrese su nombre de usuario o '0' para salir del submenu): ");
    scanf("%s", username);

    if (strcmp(username, "0") == 0) {
        // El usuario eligió regresar al menú principal
        *mainOption = 1;
        return 0;

    }

    Node* currentUser = buscar_usuario(userList, username);
    if (currentUser == NULL) {
        printf("El usuario '%s' no existe.\n", username);
        return 1;  // Permanecer en el submenú
    } else {
        submenu_usuario(currentUser, userList);
        return 1;  // Permanecer en el submenú
    }
}

void generar_usuarios_proceso(Node** userList, int cantidad) {
    generar_usuarios(userList, cantidad);

    // Solicitar una entrada adicional para mantener la consola abierta
    printf("\nPresione cualquier tecla para volver al menu principal...");
    getchar();
    getchar(); // Se agregan dos llamadas a getchar() para capturar la entrada del usuario
}



int main() {
    Node* userList = NULL;
    int mainOption = 0;

    do {
        printf("\n---- Menu Principal ----\n");
        printf("1. Insertar un nuevo usuario\n");
        printf("2. Listar todos los usuarios existentes\n");
        printf("3. Salir\n");
        printf("4. Log in\n");
        printf("5. Ingresar 10 usuarios\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &mainOption);

        switch (mainOption) {
            case 1:
                get_username(&userList);
                break;
            case 2:
                imprimir_lista(userList);
                break;
            case 3:
                printf("¡Hasta pronto!\n");
                break;
            case 4:
                while (llamar_submenu(userList, &mainOption)) {
                }
                break;
            case 5:
                generar_usuarios_proceso(&userList, 10);
                break;
            default:
                printf("Opcion no válida. Seleccione una opción del 1 al 5.\n");
                break;
        }

    } while (mainOption != 3);

    // Liberar memoria de la lista de usuarios
    Node* current = userList;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}