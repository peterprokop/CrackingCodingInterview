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

int fibonacci(int n) {
    if (n <= 2) {
        return 1;
    }
    
    return fibonacci(n-1) + fibonacci(n-2);
}

int coinCombinations(int amount) {
    int combinations = 0;
    
    if (amount >= 25) {
        combinations += coinCombinations(amount - 25);
    }
    
    if (amount >= 10) {
        combinations += coinCombinations(amount - 10);
    }
    
    if (amount >= 5) {
        combinations += coinCombinations(amount - 5);
    }
    
    if (amount >= 1) {
        combinations += coinCombinations(amount - 1);
    }
    
    if (amount == 0) {
        return 1;
    }
    
    return combinations;
}


void shift(int* A, int index, int totalSize) {
    int currentIndex = totalSize- 1;
    
    while ( currentIndex > index) {
        A[currentIndex] = A[currentIndex - 1];
        currentIndex--;
    }
}

void mergeSorted (int* A, int* B, int sizeA, int sizeB, int totalSizeA) {
    int indexA = 0;
    int indexB = 0;
    
    while ( indexA != sizeA + sizeB
           && indexB != sizeB)
    {
        if ( A[indexA] > B[indexB] ) {
            shift(A, indexA, totalSizeA);
            A[indexA] = B[indexB];
            indexA++;
            indexB++;
        } else {
            indexA++;
        }
    }
    
    
}

void testMergeSorted() {
    int A[20] = {1, 3, 5, 7, 8, 10, 12, 14, 16, 18};
    int B[7] = {1, 2, 3, 4, 5, 6, 7};
    
    mergeSorted(A, B, 10, 7, 20);
    
    printf("test");
}

int main(int argc, const char * argv[]) {
    
//    reverseString("123");
//    reverseString("");
    
//    Node c = Node{3, nullptr};
//    Node b = Node{2, &c};
//    Node a = Node{1, &b};
    
    //removeMiddleNode(&b);
    
    //printList(&a);
    
//    testListLoop();
    
//    printf("fib: %d\n", fibonacci(10));
    
//    printf("combinations: %d\n", coinCombinations(1));
//    printf("combinations: %d\n", coinCombinations(5));
//    printf("combinations: %d\n", coinCombinations(10));
    
    testMergeSorted();
    
    return 0;
}
