//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ALIAS_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_LOCATION_LENGTH 20
#define MAX_LIKES_COUNT 5
#define MAX_WORD_LENGTH 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20

// Definición de structs

typedef struct FriendRequest {
    struct User* sender;
    struct User* receiver;
    struct FriendRequest* next;
} FriendRequest;


// Estructura para un amigo
typedef struct Friend {
    struct User* user;  // Usuario amigo
    struct Friend* next;
} Friend;

typedef struct QueueNode {
    struct User* data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;


typedef struct AcceptedRequest {
    struct User* sender;  // Remitente de la solicitud
    struct AcceptedRequest* next;
} AcceptedRequest;









typedef struct Post {
    struct Node* author;
    char content[100];
} Post;



typedef struct User {
    char username[MAX_USERNAME_LENGTH];
    char alias[MAX_ALIAS_LENGTH];
    int age;
    char email[MAX_EMAIL_LENGTH];
    char location[MAX_LOCATION_LENGTH];
    char likes[MAX_LIKES_COUNT][MAX_WORD_LENGTH];
    int postsCount;
    Post* posts;
    FriendRequest* friendRequests;
    struct Node* userFriends;
    Friend *friends;
} User;

typedef struct Node {
    User user;
    struct Node* next;
} Node;







void add_user(Node** userList, const char* username);
void get_username(Node** userList);
void imprimir_user_info(User user);
Node* buscar_usuario(Node* userList, const char* username);
void enviar_solicitud_amistad(Node** userList, const char* senderUsername);
void gestionar_solicitudes_amistad(struct User* currentUser);



void volver_menu_principal(int* mainOption);
void agregar_amigo(Node* currentUser, Node* friendNode);
void eliminar_solicitud(Node* currentUser, FriendRequest* request);
FriendRequest* buscar_solicitud(Node* currentUser, Node* targetUser);
void submenu_usuario(Node* currentUser, Node* userList);
void imprimir_usuario(Node* userList);
void generar_usuarios(Node** userList, int cantidad);




void initializeQueue(Queue* queue);
int isQueueEmpty(Queue* queue);
void enqueue(Queue* queue, struct User* user);
struct User* dequeue(Queue* queue);