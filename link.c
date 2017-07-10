#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char data;
    struct node* next;
} Node;

typedef struct head{
    int length;
    struct node* next;
} HEAD;

HEAD* init();
Node* append(HEAD* head,char data);
int set(HEAD* head,char* s);
char* get(HEAD* head);

Node* find(HEAD* head,char data);
int findAndDelete(HEAD* head,char data);
int delete(HEAD* head,Node* node);
Node* insert(Node* node,char data);

int main(){
    HEAD* n = init();
    char s[100];
    scanf("%s",s);
    set(n,s);
    char* ns = get(n);
    printf("%s\n",ns);
}

int set(HEAD* head,char* s){
    int i = 0;
    while((s[i] != '\0') && i < 100){
        char c = s[i];
        append(head,c);
        i++;
    }
    return 1;
}

char* get(HEAD* head){
    char* s = (char*)malloc(sizeof(char) * head -> length + 1);
    int i = 0;
    Node* now = head -> next;
    while(1){
        if(now == NULL) break;
        char c = now -> data;
        s[i] = c;
        i++;
        now = now -> next;
    }
    s[i] = '\0';
    return s;
}

HEAD* init(){
    HEAD* h = (HEAD*)malloc(sizeof(HEAD));
    h -> length = 0;
    h -> next = NULL;
    return h;
}

Node* append(HEAD* head,char data){
    if(head -> next == NULL){
        Node* next = (Node*)malloc(sizeof(Node));
        head -> next = next;
        next -> data = data;
        next -> next = NULL;
        head -> length += 1;
        return next;
    }
    Node* now = head -> next;
    while(1){
        if(now -> next == NULL){
            Node* next = (Node*)malloc(sizeof(Node));
            now -> next = next;
            next -> data = data;
            next -> next = NULL;
            head -> length += 1;
            return next;
        }
        now = now -> next;
    }
}