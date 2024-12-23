#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to add two numbers represented by linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0); // Dummy node to start the result list
    ListNode* current = dummyHead;        // Pointer to traverse the result list
    int carry = 0;                        // Initialize carry to 0

    // Traverse both lists until both are null
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry; // Start with the carry
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;            // Calculate carry
        current->next = new ListNode(sum % 10); // Create new node with the digit
        current = current->next;    // Move to the next node
    }

    return dummyHead->next; // Return the head of the result list
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
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
    // Example 1
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);
    cout << "Input l1: ";
    printList(l1);
    cout << "Input l2: ";
    printList(l2);
    ListNode* result = addTwoNumbers(l1, l2);
    cout << "Output: ";
    printList(result);

    // Example 2
    int arr3[] = {0};
    int arr4[] = {0};
    ListNode* l3 = createList(arr3, 1);
    ListNode* l4 = createList(arr4, 1);
    cout << "Input l1: ";
    printList(l3);
    cout << "Input l2: ";
    printList(l4);
    result = addTwoNumbers(l3, l4);
    cout << "Output: ";
    printList(result);

    // Example 3
    int arr5[] = {9, 9, 9, 9, 9, 9, 9};
    int arr6[] = {9, 9, 9, 9};
    ListNode* l5 = createList(arr5, 7);
    ListNode* l6 = createList(arr6, 4);
    cout << "Input l1: ";
    printList(l5);
    cout << "Input l2: ";
    printList(l6);
    result = addTwoNumbers(l5, l6);
    cout << "Output: ";
    printList(result);

    return 0;
}
