//
//  main.cpp
//  CrackingCodingInterview
//
//  Created by Peter Prokop on 17/01/2017.
//  Copyright © 2017 Peter Prokop. All rights reserved.
//

#include <iostream>

char* reverseString(char* string) {
    int i = 0;
    
    while ( string[i] != '\0') {
        i++;
    }
    
    char output[i+1];
    int n = i;
    i--;
    
    for (int j = 0; j < n; j++) {
        output[j] = string[i];
        i--;
    }
    
    output[n] = '\0';
    
    printf("reversed:%s\n", output);
    
    return output;
}

struct Node {
    int val;
    Node* next;
};

void removeMiddleNode(Node* node) {
    
    if (!node->next) {
        printf("This is end node. Terminating.");
        exit(1);
    }
    
    Node* previous;
    
    while ( node->next ) {
        node->val = node->next->val;
        previous = node;
        node = node->next;
    }
    
    previous->next = nullptr;
}

Node* findLoopStart(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    
    Node* ptr1 = head;
    Node* ptr2 = head;
    
    while ( ptr1->next
           && ptr2->next
           && ptr2->next->next
        )
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
        
        if (ptr2 == nullptr) {
            return nullptr;
        }
        
        if ( ptr1 == ptr2 ) {
            break;
        }
    }
    
    ptr1 = head;
    
    while (ptr1 != ptr2) {
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    
    return ptr2;
}

void printList(Node* head) {
    while (head) {
        printf("%i -> ", head->val);
        head = head->next;
    }
    
    printf("end\n");
}

void testListLoop() {
    Node d = Node{4, nullptr};
    Node c = Node{3, &d};
    Node b = Node{2, &c};
    Node a = Node{1, &b};
    
    d.next = &b;
    
    printf("Loop start: %i\n", findLoopStart(&a) -> val);
}

int main(int argc, const char * argv[]) {
    
//    reverseString("123");
//    reverseString("");
    
    Node c = Node{3, nullptr};
    Node b = Node{2, &c};
    Node a = Node{1, &b};
    
    //removeMiddleNode(&b);
    
    //printList(&a);
    
    testListLoop();
    
    return 0;
}

