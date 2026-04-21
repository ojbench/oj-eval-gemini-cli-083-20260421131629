#include <cstdio>

struct Node {
    int id;
    Node* next;
};

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    if (n <= 0) return 0;

    Node* head = new Node;
    head->id = 1;
    head->next = nullptr;
    
    Node* prev = head;
    for (int i = 2; i <= n; ++i) {
        Node* newNode = new Node;
        newNode->id = i;
        newNode->next = nullptr;
        prev->next = newNode;
        prev = newNode;
    }
    prev->next = head; // Make it circular

    Node* curr = head;
    // prev is currently the last node (node n)

    for (int i = 0; i < n; ++i) {
        // Move m-1 steps to find the node to delete
        for (int j = 0; j < m - 1; ++j) {
            prev = curr;
            curr = curr->next;
        }
        
        // Output the id of the node to be deleted
        printf("%d\n", curr->id);
        
        if (n - i > 1) {
            // Remove curr from the list
            prev->next = curr->next;
            delete curr;
            // Start next count from the next node
            curr = prev->next;
        } else {
            // Last node
            delete curr;
        }
    }

    return 0;
}