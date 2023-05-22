//

#include <stdio.h>
#include "utils.h"
//




void add_user(Node** userList, const char* username) {
    // Verificar si el nombre de usuario ya está presente en la lista
    Node* current = *userList;
    while (current != NULL) {
        if (strcmp(current->user.username, username) == 0) {
            printf("El nombre de usuario ya esta registrado.\n");
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

    printf("Ingrese el correo electronico: ");
    scanf("%s", newUser.email);

    printf("Ingrese la ubicacion actual: ");
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
            printf("Correo electronico: %s\n", current->user.email);
            printf("Ubicacion actual: %s\n", current->user.location);
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
    printf("Ubicacion actual: %s\n", user.location);
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
// Inicializar una cola vacía
void initializeQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Verificar si la cola está vacía
int isQueueEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Insertar un elemento en la cola
void enqueue(Queue* queue, struct User* user) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = user;
    newNode->next = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Eliminar un elemento de la cola
struct User* dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    } else {
        QueueNode* frontNode = queue->front;
        struct User* userData = frontNode->data;
        queue->front = frontNode->next;
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
        free(frontNode);
        return userData;
    }
}

// Función para gestionar las solicitudes de amistad
// Función para gestionar las solicitudes de amistad
void gestionar_solicitudes_amistad(struct User* currentUser) {
    Queue requestQueue;
    initializeQueue(&requestQueue);

    // Agregar todas las solicitudes a la cola
    FriendRequest* currentRequest = currentUser->friendRequests;
    while (currentRequest != NULL) {
        enqueue(&requestQueue, currentRequest->sender);
        currentRequest = currentRequest->next;
    }

    printf("Lista de solicitudes de amistad:\n");

    AcceptedRequest* acceptedRequests = NULL;  // Lista de solicitudes aceptadas

    while (!isQueueEmpty(&requestQueue)) {
        struct User* sender = dequeue(&requestQueue);

        printf("- %s te ha enviado una solicitud de amistad. "
               "Deseas aceptarla? (1: Aceptar, 0: Denegar): ", sender->username);
        int option;
        scanf("%d", &option);

        if (option == 1) {
            // Aceptar solicitud
            Friend* newFriend = (Friend*)malloc(sizeof(Friend));
            newFriend->user = sender;
            newFriend->next = NULL;

            // Agregar amigo a la lista de amigos
            if (currentUser->friends == NULL) {
                currentUser->friends = newFriend;
            } else {
                Friend* currentFriend = currentUser->friends;
                while (currentFriend->next != NULL) {
                    currentFriend = currentFriend->next;
                }
                currentFriend->next = newFriend;
            }

            printf("Has aceptado la solicitud de amistad de %s.\n", sender->username);

            // Agregar solicitud a la lista de solicitudes aceptadas
            AcceptedRequest* newAcceptedRequest = (AcceptedRequest*)malloc(sizeof(AcceptedRequest));
            newAcceptedRequest->sender = sender;
            newAcceptedRequest->next = acceptedRequests;
            acceptedRequests = newAcceptedRequest;
        } else if (option == 0) {
            // Denegar solicitud
            printf("Has denegado la solicitud de amistad de %s.\n", sender->username);
        } else {
            printf("Opción no valida. Seleccione 1 o 0.\n");
            enqueue(&requestQueue, sender);
        }
    }

    // Liberar la lista de solicitudes de amistad
    while (currentUser->friendRequests != NULL) {
        FriendRequest* tempRequest = currentUser->friendRequests;
        currentUser->friendRequests = currentUser->friendRequests->next;
        free(tempRequest);
    }

    currentUser->friendRequests = NULL;

    // Liberar la lista de solicitudes aceptadas
    while (acceptedRequests != NULL) {
        AcceptedRequest* tempAcceptedRequest = acceptedRequests;
        acceptedRequests = acceptedRequests->next;
        free(tempAcceptedRequest);
    }

    if (currentUser->friendRequests == NULL) {
        printf("No tienes solicitudes de amistad pendientes.\n");
    }
}

void imprimir_solicitudes_amistad(FriendRequest* solicitudes) {
    if (solicitudes == NULL) {
        printf("No tienes solicitudes de amistad pendientes.\n");
    } else {
        printf("Solicitudes de amistad pendientes:\n");
        int count = 1;
        FriendRequest* currentRequest = solicitudes;
        while (currentRequest != NULL) {
            if (currentRequest->sender != NULL && currentRequest->sender->username != NULL) {
                printf("%d. %s\n", count, currentRequest->sender->username);
                count++;
            }
            currentRequest = currentRequest->next;
        }
    }
}


void imprimir_solicitudes_aceptadas(Friend* friends) {
    if (friends == NULL) {
        printf("No tienes solicitudes de amistad aceptadas.\n");
    } else {
        printf("Solicitudes de amistad aceptadas:\n");
        int count = 1;
        Friend* currentFriend = friends;
        while (currentFriend != NULL) {
            if (currentFriend->user != NULL && currentFriend->user->username != NULL) {
                printf("%d. %s\n", count, currentFriend->user->username);
                count++;
            }
            currentFriend = currentFriend->next;
        }
    }
}

void agregar_amigos_random(User* currentUser, Node* userList) {
    Stack randomUsersStack;
    randomUsersStack.top = NULL;
    randomUsersStack.size = 0;

    int totalUsers = 0;
    Node* tempNode = userList;
    while (tempNode != NULL) {
        totalUsers++;
        tempNode = tempNode->next;
    }

    Friend* currentFriend = currentUser->friends;

    while (randomUsersStack.size < 3 && randomUsersStack.size < totalUsers) {
        int randomIndex = rand() % totalUsers;
        Node* randomNode = userList;
        int i = 0;
        while (randomNode != NULL && i < randomIndex) {
            User* randomUser = &(randomNode->user);
            int isFriend = 0;
            Friend* tempFriend = currentFriend;
            while (tempFriend != NULL) {
                if (tempFriend->user == randomUser) {
                    isFriend = 1;
                    break;
                }
                tempFriend = tempFriend->next;
            }

            if (!isFriend && randomUser != currentUser) {
                i++;
            }

            randomNode = randomNode->next;
        }

        if (randomNode != NULL) {
            User* randomUser = &(randomNode->user);

            StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
            newNode->data = randomUser;
            newNode->next = randomUsersStack.top;
            randomUsersStack.top = newNode;
            randomUsersStack.size++;
        }
    }

    printf("Usuarios aleatorios disponibles:\n");
    int index = 1;
    StackNode* tempStackNode = randomUsersStack.top;
    while (tempStackNode != NULL) {
        User* randomUser = tempStackNode->data;
        printf("%d. %s\n", index, randomUser->username);
        index++;
        tempStackNode = tempStackNode->next;
    }

    // Descartar el carácter de nueva línea residual
    getchar();

    printf("Seleccione el numero de los usuarios que desea agregar como amigos (separados por comas): ");
    char input[100];
    scanf("%99s", input);  // Lee un máximo de 99 caracteres para evitar desbordamiento

    // Eliminar el carácter de nueva línea residual
    input[strcspn(input, "\n")] = '\0';

    char* token = strtok(input, ",");
    while (token != NULL) {
        int selection = atoi(token) - 1;
        if (selection >= 0 && selection < randomUsersStack.size) {
            StackNode* selectedNode = randomUsersStack.top;
            int i = 0;
            while (selectedNode != NULL && i < selection) {
                selectedNode = selectedNode->next;
                i++;
            }
            if (selectedNode != NULL) {
                User* selectedUser = selectedNode->data;

                // Crear una nueva solicitud de amistad
                FriendRequest* newFriendRequest = (FriendRequest*)malloc(sizeof(FriendRequest));
                newFriendRequest->sender = currentUser;
                newFriendRequest->receiver = selectedUser;
                newFriendRequest->next = currentUser->friendRequests;
                currentUser->friendRequests = newFriendRequest;

                printf("Has enviado una solicitud de amistad a %s.\n", selectedUser->username);
            }
        }
        token = strtok(NULL, ",");
    }

    while (randomUsersStack.top != NULL) {
        StackNode* temp = randomUsersStack.top;
        randomUsersStack.top = randomUsersStack.top->next;
        free(temp);
    }
}




// Realizar una publicación




// Listar las publicaciones del usuario seleccionado




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


// Volver al menú principal
void volver_menu_principal(int* mainOption) {
    *mainOption = 0;
    setSubMenuOption(0); // se usa una flag para poder volver para atras, se ve en la funcion de mmain de llamar_submenu.
}
// Función del submenú del usuario
// Función del submenú del usuario
void submenu_usuario(Node* currentUser, Node* userList) {
    int option;
    do {
        printf("\n---- Submenu del Usuario ----\n");
        printf("1. Enviar solicitud de amistad\n");
        printf("2. Gestionar las solicitudes pendientes\n");
        printf("3. Mis solicitudes\n");
        printf("4. Mis amigos\n");
        printf("5. Agregar amigos desconocidos\n");
        printf("3. Realizar una publicación\n");
        printf("4. Listar las publicaciones de un usuario\n");
        printf("6. Volver al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                enviar_solicitud_amistad(&userList, currentUser->user.username);
                break;
            case 2:
                gestionar_solicitudes_amistad(&(currentUser->user));
                break;
            case 3:
                imprimir_solicitudes_amistad(currentUser->user.friendRequests);
                break;
            case 4:
                imprimir_solicitudes_aceptadas(currentUser->user.friends);

                break;
            case 5:
                agregar_amigos_random(&(currentUser->user), userList);

                break;

            case 6:
                volver_menu_principal(&option);
                return;  // Regresar al menú principal
            case 7:

                break;
            default:
                printf("Opcion no valida. Seleccione una opcion del 1 al 5.\n");
                break;
        }

    } while (1);
}
