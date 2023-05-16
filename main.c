#include <stdio.h>

#include "utils.h"
typedef struct {
    char username[20];
    int age;
    char email[50];
    char location[20];
    char likes[5][20];
} User;


void menu_add_new_word() {
    char word[MAX_WORD_LENGTH];
    printf("Ingresa una palabra: ");
    scanf("%s", word);
    str_to_lowercase(word);
    void insert_into_list(LinkedList* l, char* word);




}

void find_user(){
    char word[MAX_WORD_LENGTH];
    printf("Ingresa una palabra: ");
    scanf("%s", word);
    str_to_lowercase(word);
    Node* find_in_list(LinkedList l, char* word);
}

int main() {
    int option;
    User users[100];
    int numUsers = 0;
    int currentUserIndex = -1;

    do {
        printf("\n---- Menú Principal ----\n");
        printf("1. Insertar un nuevo usuario\n");
        printf("2. Listar todos los usuarios existentes\n");
        printf("3. Operar como un usuario específico\n");
        printf("4. Enviar solicitudes de amistad\n");
        printf("5. Gestionar las solicitudes pendientes\n");
        printf("6. Realizar una publicación\n");
        printf("7. Listar las publicaciones del usuario seleccionado\n");
        printf("8. Volver al menú principal\n");
        printf("9. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                menu_add_new_word();
                    break;
            case 2:
                find_user();
                break;
            case 3:
                // Codi per operar como un usuario específico
                break;
            case 4:
                // Codi per enviar sol·licituts de amistat
                break;
            case 5:
                // Codi per gestionar les sol·licituts pendents
                break;
            case 6:
                // Codi para realitzar una publicació
                break;
            case 7:
                // Codi para llistar las publicacions del usuari seleccionat
                break;
            case 8:
                // No es necessita codi, simplement torna al menu principal
                break;
            case 9:
                printf("¡Hasta pronto!\n");
                break;
            default:
                printf("Opción no válida. Seleccione una opción del 1 al 9.\n");
                break;
        }

    } while (option != 9);

    return 0;
}

