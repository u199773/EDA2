//

#include <stdio.h>
#include "utils.h"
//




void add_user(Node** userList, const char* username) {
    // Verificar si el nombre de usuario ya está presente en la lista
    Node* current = *userList;
    while (current != NULL) {
        if (strcmp(current->user.username, username) == 0) {
            printf("El nombre de usuario ya está registrado.\n");
            return;
        }
        current = current->next;
    }

    User newUser;
    strcpy(newUser.username, username);

    printf("Ingrese el alias: ");
    scanf("%s", newUser.alias);

    printf("Ingrese la edad: ");
    scanf("%d", &newUser.age);

    printf("Ingrese el correo electrónico: ");
    scanf("%s", newUser.email);

    printf("Ingrese la ubicación actual: ");
    scanf("%s", newUser.location);

    printf("Ingrese los 5 gustos o preferencias (separe cada uno por un espacio):\n");
    for (int i = 0; i < 5; i++) {
        scanf("%s", newUser.likes[i]);
    }

    // Crear un nuevo nodo y añadirlo a la lista de usuarios
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->user = newUser;
    newNode->next = NULL;

    if (*userList == NULL) {
        // La lista está vacía, el nuevo nodo se convierte en el primer nodo
        *userList = newNode;
    } else {
        // Encontrar el último nodo de la lista y agregar el nuevo nodo al final
        current = *userList;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("El usuario se ha registrado correctamente.\n");
}


void imprimir_user_info(User user) {
    printf("Nombre de usuario: %s\n", user.username);
    printf("Alias: %s\n", user.alias);
    printf("Edad: %d\n", user.age);
    printf("Correo electrónico: %s\n", user.email);
    printf("Ubicación actual: %s\n", user.location);
    printf("Gustos o preferencias:\n");
    for (int i = 0; i < 5; i++) {
        printf("- %s\n", user.likes[i]);
    }
    printf("\n");
}

Node* buscar_usuario(Node* userList, const char* username) {
    Node* current = userList;
    while (current != NULL) {
        if (strcmp(current->user.username, username) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

FriendRequest* buscar_solicitud(Node* currentUser, Node* targetUser) {
    FriendRequest* currentRequest = currentUser->user.friendRequests;
    while (currentRequest != NULL) {
        if (currentRequest->receiver == targetUser) {
            return currentRequest;
        }
        currentRequest = currentRequest->next;
    }
    return NULL;
}

// Funciones de manipulación de datos
void agregar_amigo(Node* currentUser, Node* friendNode) {
    // Agregar friendNode a la lista de amigos de currentUser
    if (currentUser->user.userFriends == NULL) {
        // La lista de amigos está vacía, friendNode se convierte en el primer amigo
        currentUser->user.userFriends = friendNode;
        friendNode->next = NULL;
    } else {
        // Agregar friendNode al final de la lista de amigos
        Node* current = currentUser->user.userFriends;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = friendNode;
        friendNode->next = NULL;
    }

    printf("Se ha agregado a %s como amigo.\n", friendNode->user.username);
}

void eliminar_solicitud(Node* currentUser, FriendRequest* request) {
    // Eliminar la solicitud de currentUser
    FriendRequest* current = currentUser->friendRequests;
    FriendRequest* previous = NULL;

    while (current != NULL) {
        if (current == request) {
            // Encontrada la solicitud, se elimina de la lista
            if (previous == NULL) {
                // La solicitud es la primera de la lista
                currentUser->friendRequests = current->next;
            } else {
                // La solicitud está en medio o al final de la lista
                previous->next = current->next;
            }

            free(current);
            printf("La solicitud ha sido eliminada.\n");
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("La solicitud no existe.\n");
}











// Enviar solicitud de amistad
void enviar_solicitud(Node* currentUser, Node* targetUser) {
    // Verificar si ya existe una solicitud de amistad entre los usuarios
    if (buscar_solicitud(currentUser, targetUser) != NULL) {
        printf("Ya has enviado una solicitud de amistad a este usuario.\n");
        return;
    }

    // Crear una nueva solicitud de amistad
    FriendRequest* newRequest = (FriendRequest*)malloc(sizeof(FriendRequest));
    newRequest->sender = currentUser;
    newRequest->receiver = targetUser;
    newRequest->next = NULL;

    // Agregar la solicitud a la lista de solicitudes pendientes del usuario objetivo
    if (targetUser->user.friendRequests == NULL) {
        // La lista de solicitudes pendientes está vacía, la nueva solicitud se convierte en la primera solicitud
        targetUser->user.friendRequests = newRequest;
    } else {
        // Encontrar el último nodo de la lista de solicitudes pendientes y agregar la nueva solicitud al final
        FriendRequest* current = targetUser->user.friendRequests;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newRequest;
    }

    printf("Solicitud de amistad enviada a %s.\n", targetUser->user.username);
}

// Gestionar las solicitudes pendientes
void gestionar_solicitudes_pendientes(Node* currentUser) {
    FriendRequest* currentRequest = currentUser->user.friendRequests;
    if (currentRequest == NULL) {
        printf("No tienes solicitudes de amistad pendientes.\n");
        return;
    }

    printf("Solicitudes de amistad pendientes:\n");
    int count = 1;
    while (currentRequest != NULL) {
        printf("%d. De: %s\n", count, currentRequest->sender->user.username);
        currentRequest = currentRequest->next;
        count++;
    }

    int option;
    printf("Seleccione el número de solicitud que desea gestionar (0 para cancelar): ");
    scanf("%d", &option);

    if (option > 0 && option < count) {
        currentRequest = currentUser->user.friendRequests;
        for (int i = 1; i < option; i++) {
            currentRequest = currentRequest->next;
        }
        gestionar_solicitud(currentRequest, currentUser);
    } else if (option == 0) {
        printf("Cancelando...\n");
    } else {
        printf("Opción no válida.\n");
    }
}

// Gestionar una solicitud de amistad específica
void gestionar_solicitud(FriendRequest* request, Node* currentUser) {
    printf("Solicitud de amistad de: %s\n", request->sender->user.username);
    printf("1. Aceptar solicitud\n");
    printf("2. Rechazar solicitud\n");
    printf("Seleccione una opción: ");
    int option;
    scanf("%d", &option);

    if (option == 1) {
        // Aceptar solicitud de amistad
        agregar_amigo(currentUser, request->sender);
        eliminar_solicitud(currentUser, request);
        printf("Has aceptado la solicitud de amistad de %s.\n", request->sender->user.username);
    } else if (option == 2) {
        // Rechazar solicitud de amistad
        eliminar_solicitud(currentUser, request);
        printf("Has rechazado la solicitud de amistad de %s.\n", request->sender->user.username);
    } else {
        printf("Opción no válida.\n");
    }
}

// Realizar una publicación
void realizar_publicacion(Node* currentUser) {
    Post newPost;
    newPost.author = currentUser;
    printf("Ingrese el contenido de la publicación: ");
    scanf(" %[^\n]s", newPost.content);

    // Agregar la nueva publicación a la lista de publicaciones del usuario
    if (currentUser->user.posts == NULL) {
        // La lista de publicaciones está vacía, la nueva publicación se convierte en la primera publicación
        currentUser->user.posts = (Post*)malloc(sizeof(Post));
        *(currentUser->user.posts) = newPost;
        currentUser->user.postsCount = 1;
    } else {
        // Ampliar la lista de publicaciones para incluir la nueva publicación
        int count = currentUser->user.postsCount;
        currentUser->user.posts = (Post*)realloc(currentUser->user.posts, (count + 1) * sizeof(Post));
        (currentUser->user.posts)[count] = newPost;
        currentUser->user.postsCount++;
    }

    printf("La publicación se ha realizado correctamente.\n");
}

// Listar las publicaciones del usuario seleccionado
void listar_publicaciones(Node* user) {
    printf("Publicaciones de %s:\n", user->user.username);
    if (user->user.postsCount == 0) {
        printf("No hay publicaciones disponibles.\n");
    } else {
        for (int i = 0; i < user->user.postsCount; i++) {
            printf("Publicación %d:\n", i + 1);
            printf("Autor: %s\n", user->user.posts[i].author->user.username);
            printf("Contenido: %s\n", user->user.posts[i].content);
            printf("\n");
        }
    }
}

// Volver al menú principal
void volver_menu_principal() {
    printf("Volviendo al menú principal...\n");
}

// Función del submenú del usuario
// Declaración de variable global
int subMenuOption = 0;

// Función para obtener la opción del submenú
int getSubMenuOption() {
    return subMenuOption;
}

// Función para establecer la opción del submenú
void setSubMenuOption(int option) {
    subMenuOption = option;
}

// ... resto del código ...

// Función del submenú del usuario
void submenu_usuario(Node* currentUser, Node* userList) {
    int option;

    do {
        printf("\n---- Submenú del Usuario ----\n");
        printf("1. Enviar solicitud de amistad\n");
        printf("2. Gestionar las solicitudes pendientes\n");
        printf("3. Realizar una publicación\n");
        printf("4. Listar las publicaciones de un usuario\n");
        printf("5. Volver al menú principal\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                char targetUsername[MAX_USERNAME_LENGTH];
                printf("Ingrese el nombre de usuario al que desea enviar la solicitud: ");
                scanf("%s", targetUsername);
                Node* targetUser = buscar_usuario(userList, targetUsername);
                if (targetUser == NULL) {
                    printf("El usuario '%s' no existe.\n", targetUsername);
                } else {
                    enviar_solicitud(currentUser, targetUser);
                }
                break;
            }
            case 2:
                gestionar_solicitudes_pendientes(currentUser);
                break;
            case 3:
                realizar_publicacion(currentUser);
                break;
            case 4: {
                char targetUsername[MAX_USERNAME_LENGTH];
                printf("Ingrese el nombre de usuario del cual desea listar las publicaciones: ");
                scanf("%s", targetUsername);
                Node* targetUser = buscar_usuario(userList, targetUsername);
                if (targetUser == NULL) {
                    printf("El usuario '%s' no existe.\n", targetUsername);
                } else {
                    listar_publicaciones(targetUser);
                }
                break;
            }
            case 5:
                volver_menu_principal();
                break;
            default:
                printf("Opción no válida. Seleccione una opción del 1 al 5.\n");
                break;
        }

        // Actualizamos el valor de subMenuOption
        setSubMenuOption(getSubMenuOption() + 1);

    } while (getSubMenuOption() != 6);
}

