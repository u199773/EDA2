//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_CONTENT_LENGTH 120
#define MAX_ALIAS_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_LOCATION_LENGTH 20
#define MAX_LIKES_COUNT 5
#define MAX_WORD_LENGTH 50

#define TOP_WORDS_COUNT 10

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


// Estructura para una solicitud aceptada
typedef struct AcceptedRequest {
    struct User* sender;  // Remitente de la solicitud
    struct AcceptedRequest* next;
} AcceptedRequest;



typedef struct StackNode {
    struct User* data;
    struct StackNode* next;
} StackNode;

// Definición de la estructura Stack
typedef struct Stack {
    StackNode* top;
    int size;
} Stack;





typedef struct Post {
    struct User* author;
    char content[MAX_CONTENT_LENGTH];
    struct Post* next;
} Post;

typedef struct List {
    Post* head;
    int size;
} List;

typedef struct Dictionary {
    int count;
    struct Dictionary* next;
    char word[MAX_WORD_LENGTH];
} Dictionary;

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
    AcceptedRequest* acceptedRequests;
} User;

typedef struct Node {
    User user;
    struct Node* next;
    struct Node* prev;
    struct Node* low;  // Puntero al nodo "low" para el ordenamiento
    struct Node* high; // Puntero al nodo "high" para el ordenamiento
    AcceptedRequest* acceptedRequests;
} Node;




















int linear_search(const char* arr, const char* target);
void ordenar_por_edad(Node* userList);
void add_user(Node** userList, const char* username);
void get_username(Node** userList);
void imprimir_user_info(User user);
Node* buscar_usuario(Node* userList, const char* username);
void enviar_solicitud_amistad(Node** userList, const char* senderUsername);
void gestionar_solicitudes_amistad(struct User* currentUser);
void imprimir_solicitudes_amistad(FriendRequest* solicitudes);
void imprimir_solicitudes_aceptadas(Friend* friends);
void buscar_usuario_por_nombre(Node* userList);
void volver_menu_principal(int* mainOption);
void agregar_amigo(Node* currentUser, Node* friendNode);
void eliminar_solicitud(Node* currentUser, FriendRequest* request);
FriendRequest* buscar_solicitud(Node* currentUser, Node* targetUser);
void submenu_usuario(Node* currentUser, Node* userList);
void imprimir_usuario(Node* userList);
void generar_usuarios(Node** userList, int cantidad);

void agregar_amigos_random(User* currentUser, Node* userList);
void makePost(User* currentUser);
void addPostToUser(User* user, const char* content);
void initializeList(List* list);
void printUserPosts(User* user);

void initializeQueue(Queue* queue);
int isQueueEmpty(Queue* queue);
void enqueue(Queue* queue, struct User* user);
struct User* dequeue(Queue* queue);
void printTopWords(Post** posts);



