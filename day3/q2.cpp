#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse the linked list iteratively
ListNode* reverseListIterative(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* nextTemp = curr->next; // Save the next node
        curr->next = prev;              // Reverse the link
        prev = curr;                    // Move prev forward
        curr = nextTemp;                // Move curr forward
    }
    return prev;
}

// Function to reverse the linked list recursively
ListNode* reverseListRecursive(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // Base case: empty list or single node
    }
    ListNode* newHead = reverseListRecursive(head->next); // Reverse the rest
    head->next->next = head; // Reverse the current link
    head->next = nullptr;    // Set the current node's next to null
    return newHead;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Test case 1: Iterative approach
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1, 5);
    cout << "Original List: ";
    printList(head1);
    ListNode* reversed1 = reverseListIterative(head1);
    cout << "Reversed List (Iterative): ";
    printList(reversed1);

    // Test case 2: Recursive approach
    int arr2[] = {1, 2};
    ListNode* head2 = createList(arr2, 2);
    cout << "Original List: ";
    printList(head2);
    ListNode* reversed2 = reverseListRecursive(head2);
    cout << "Reversed List (Recursive): ";
    printList(reversed2);

    return 0;
}
