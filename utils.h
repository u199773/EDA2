//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    struct Node* sender;
    struct Node* receiver;
    struct FriendRequest* next;
} FriendRequest;

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
} User;

typedef struct Node {
    User user;
    struct FriendRequest* friendRequests;
    struct Node* next;
} Node;







void add_user(Node** userList, const char* username);
void get_username(Node** userList);
void imprimir_user_info(User user);
Node* buscar_usuario(Node* userList, const char* username);
void enviar_solicitud(Node* currentUser, Node* targetUser);
void gestionar_solicitudes_pendientes(Node* currentUser);
void gestionar_solicitud(FriendRequest* request, Node* currentUser);
void realizar_publicacion(Node* currentUser);
void listar_publicaciones(Node* user);
void volver_menu_principal();
void agregar_amigo(Node* currentUser, Node* friendNode);
void eliminar_solicitud(Node* currentUser, FriendRequest* request);
FriendRequest* buscar_solicitud(Node* currentUser, Node* targetUser);
void submenu_usuario(Node* currentUser, Node* userList);