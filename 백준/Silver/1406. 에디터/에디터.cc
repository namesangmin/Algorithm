#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct _nodeDLL {
    ElementType Data;
    struct _nodeDLL* Prev;
    struct _nodeDLL* Next;
} NodeDLL;

NodeDLL* DLL_CreateNode(ElementType data);
void DLL_AppendNode(NodeDLL* tail, NodeDLL* newnode);
void DLL_InsertBefore(NodeDLL* curr, NodeDLL* newnode);
void DLL_RemoveNode(NodeDLL* target);

int main(void) {
    int N;

    NodeDLL* head = DLL_CreateNode(0);
    NodeDLL* tail = DLL_CreateNode(0);

    head->Next = tail;
    tail->Prev = head;

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        DLL_AppendNode(tail, DLL_CreateNode(ch));
    }

    NodeDLL* cursor = tail;

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        char cmd = getchar();
        getchar();
        if (cmd == 'L') {
            if (cursor->Prev != head)
                cursor = cursor->Prev;
        }
        else if (cmd == 'D') {
            if (cursor != tail)
                cursor = cursor->Next;
        }
        else if (cmd == 'B') {
            if (cursor->Prev != head)
                DLL_RemoveNode(cursor->Prev);
        }
        else if (cmd == 'P') {
            char c = getchar();
            getchar();
            DLL_InsertBefore(cursor, DLL_CreateNode(c));
        }
    }

    char out[1000001];
    int idx = 0;
    for (NodeDLL* cur = head->Next; cur != tail; cur = cur->Next)
        out[idx++] = cur->Data;
    out[idx] = '\0';

    puts(out);
    return 0;
}


NodeDLL* DLL_CreateNode(ElementType data) {
    NodeDLL* node = (NodeDLL*)malloc(sizeof(NodeDLL));
    node->Data = data;
    node->Prev = NULL;
    node->Next = NULL;
    return node;
}

void DLL_AppendNode(NodeDLL* tail, NodeDLL* newnode) {
    NodeDLL* prev = tail->Prev;

    prev->Next = newnode;
    newnode->Prev = prev;

    newnode->Next = tail;
    tail->Prev = newnode;
}

void DLL_InsertBefore(NodeDLL* curr, NodeDLL* newnode) {
    NodeDLL* prev = curr->Prev;

    newnode->Prev = prev;
    newnode->Next = curr;

    prev->Next = newnode;
    curr->Prev = newnode;
}

void DLL_RemoveNode(NodeDLL* target) {
    target->Prev->Next = target->Next;
    target->Next->Prev = target->Prev;
    free(target);
}
