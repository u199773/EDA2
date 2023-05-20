#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"



void get_username(Node** userList) {
    char username[20];
    printf("Ingrese el nombre de usuario: ");
    scanf("%s", username);
    add_user(userList, username);
}

void find_user() {
    char word[MAX_WORD_LENGTH];
    printf("Ingresa el usuario que quieres encontrar: ");
    scanf("%s", word);
    // str_to_lowercase(word);
    // Node* find_in_list(LinkedList l, char* word);
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
int llamar_submenu(Node* userList) {
    char username[MAX_USERNAME_LENGTH];
    printf("Ingrese su nombre de usuario (o '0' para regresar al menú principal): ");
    scanf("%s", username);

    if (strcmp(username, "0") == 0) {
        // El usuario eligió regresar al menú principal
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




int main() {
    Node* userList = NULL;
    int option;

    do {
        printf("\n---- Menu Principal ----\n");
        printf("1. Insertar un nuevo usuario\n");
        printf("2. Listar todos los usuarios existentes\n");
        printf("3. Salir\n");
        printf("4. Submenu\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &option);

        switch (option) {
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
                while (1) {
                    int result = llamar_submenu(userList);
                    if (result == 0) {
                        break;  // Regresar al menú principal
                    }
                }
                break;


            default:
                printf("Opción no válida. Seleccione una opción del 1 al 3.\n");
                break;
        }

    } while (option != 4);

    // Liberar memoria de la lista de usuarios
    Node* current = userList;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}