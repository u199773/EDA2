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


//generar 10 usuarios aleatorios.


void generar_usuarios(Node** userList, int cantidad) {
    srand(time(NULL));

    char nombres[10][100] = {"Usuario1", "Usuario2", "Usuario3", "Usuario4", "Usuario5",
                             "Usuario6", "Usuario7", "Usuario8", "Usuario9", "Usuario10"};

    char gustos[9][100] = {"comer", "bailar", "deporte", "animales", "cantar",
                           "estudiar", "salir", "quedar", "dormir"};

    char ciudades[5][100] = {"Madrid", "Barcelona", "Valencia", "Sevilla", "Bilbao"};

    int nombresIndices[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // Índices de los nombres
    int gustosIndices[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};        // Índices de los gustos

    // Shuffle de los índices de los nombres y gustos
    for (int i = 9; i >= 1; --i) {
        int j = rand() % (i + 1);
        int temp = nombresIndices[i];
        nombresIndices[i] = nombresIndices[j];
        nombresIndices[j] = temp;
    }

    for (int i = 8; i >= 1; --i) {
        int j = rand() % (i + 1);
        int temp = gustosIndices[i];
        gustosIndices[i] = gustosIndices[j];
        gustosIndices[j] = temp;
    }

    for (int i = 0; i < cantidad; ++i) {
        // Obtener un índice único para el nombre actual
        int indiceNombre = nombresIndices[i % 10];

        // Crear un nuevo usuario
        User newUser;

        // Copiar el nombre de usuario
        strcpy(newUser.username, nombres[indiceNombre]);

        // Generar correo electrónico aleatorio
        sprintf(newUser.email, "%04d@gmail.com", rand() % 10000);

        // Generar gustos aleatorios
        for (int j = 0; j < 5; j++) {
            int gustoIndice = gustosIndices[(i + j) % 9];
            strcpy(newUser.likes[j], gustos[gustoIndice]);
        }

        // Generar dirección de ciudad aleatoria
        int ciudadIndice = rand() % 5;
        strcpy(newUser.location, ciudades[ciudadIndice]);

        // Generar edad aleatoria entre 18 y 50
        int edad = rand() % 33 + 18;
        newUser.age = edad;

        // Generar alias aleatorio
        sprintf(newUser.alias, "Alias%d", i + 1);

        // Crear un nuevo nodo y enlazarlo a la lista
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->user = newUser;
        newNode->next = *userList;
        *userList = newNode;
    }
}





void imprimir_usuario(Node* userList) {
    char nombreUsuario[100];
    printf("Ingrese el nombre de usuario: ");
    fgets(nombreUsuario, sizeof(nombreUsuario), stdin);
    nombreUsuario[strcspn(nombreUsuario, "\n")] = '\0';  // Eliminar el salto de línea del final

    Node* current = userList;
    printf("Lista de usuarios:\n");
    while (current != NULL) {
        if (strcmp(current->user.username, nombreUsuario) == 0) {
            printf("Nombre de usuario: %s\n", current->user.username);
            printf("Alias: %s\n", current->user.alias);
            printf("Edad: %d\n", current->user.age);
            printf("Correo electrónico: %s\n", current->user.email);
            printf("Ubicación actual: %s\n", current->user.location);
            printf("Gustos o preferencias:\n");
            for (int i = 0; i < 5; i++) {
                printf("- %s\n", current->user.likes[i]);
            }
            printf("\n");
            break;
        }
        current = current->next;
    }
}





// imprime toda la lista, con lla funcion de llamar en el main como funcion princiupal
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




//estructuras de colas

// Función para crear una cola vacía
Queue create_queue() {
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;
    return queue;
}

// Función para verificar si la cola está vacía
int is_empty_queue(Queue* queue) {
    return (queue->front == NULL);
}

// Función para encolar un elemento en la cola
void enqueue(QueueNode** front, QueueNode** rear, struct FriendRequest* data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = (struct User*)data;
    newNode->next = NULL;

    if (*front == NULL) {
        *front = newNode;
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}



// Función para desencolar un elemento de la cola
void dequeue(Queue* queue) {
    if (is_empty_queue(queue)) {
        printf("Error: La cola está vacía.\n");
        return;
    }

    QueueNode* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
}

// Función para obtener el elemento frontal de la cola
User front(Queue* queue) {
    if (is_empty_queue(queue)) {
        printf("Error: La cola está vacía.\n");
        User dummyUser;
        return dummyUser;
    }

    return *queue->front->data;
}










// Enviar solicitud de amistad
void enviar_solicitud_amistad(Node** userList, const char* senderUsername) {
    char nombreUsuario[MAX_USERNAME_LENGTH];
    printf("Ingrese el nombre de usuario al que desea enviar la solicitud: ");
    scanf("%s", nombreUsuario);

    Node* current = *userList;
    while (current != NULL) {
        if (strcmp(current->user.username, nombreUsuario) == 0) {
            // Encontrar al usuario al que se enviará la solicitud
            User* receiverUser = &(current->user);  // Receptor de la solicitud

            // Obtener los datos del usuario actual (remitente de la solicitud)
            User* senderUser = NULL;
            Node* currentUser = *userList;
            while (currentUser != NULL) {
                if (strcmp(currentUser->user.username, senderUsername) == 0) {
                    senderUser = &(currentUser->user);
                    break;
                }
                currentUser = currentUser->next;
            }

            if (senderUser == NULL) {
                printf("El usuario \"%s\" no existe.\n", senderUsername);
                return;
            }

            // Crear una nueva solicitud de amistad
            FriendRequest* newRequest = (FriendRequest*)malloc(sizeof(FriendRequest));
            newRequest->sender = senderUser;
            newRequest->receiver = receiverUser;
            newRequest->next = NULL;

            // Agregar la solicitud a la lista del usuario receptor
            if (receiverUser->friendRequests == NULL) {
                receiverUser->friendRequests = newRequest;
            } else {
                FriendRequest* currentRequest = receiverUser->friendRequests;
                while (currentRequest->next != NULL) {
                    currentRequest = currentRequest->next;
                }
                currentRequest->next = newRequest;
            }

            printf("Solicitud de amistad enviada a %s.\n", nombreUsuario);
            return;
        }
        current = current->next;
    }

    printf("El usuario \"%s\" no existe.\n", nombreUsuario);
}



// Gestionar las solicitudes pendientes


// Realizar una publicación




// Listar las publicaciones del usuario seleccionado


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

                enviar_solicitud_amistad(&userList, currentUser->user.username);

                break;
            }
            case 2:

                break;
            case 3:

                break;
            case 4: {

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

    } while (getSubMenuOption() != 5);
}

