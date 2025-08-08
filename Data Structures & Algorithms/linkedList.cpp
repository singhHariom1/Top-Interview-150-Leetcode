#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

class LinkedList
{
private:
    Node *head;

    // Helper to expose head
    Node *getHead()
    {
        return head;
    }

    // Helper to set head
    void setHead(Node *newHead)
    {
        head = newHead;
    }

public:
    LinkedList()
    {
        head = NULL;
    }

    // 1️⃣ Insert at head
    void insertAtHead(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    // 2️⃣ Insert at tail
    void insertAtTail(int x)
    {
        Node *newNode = new Node(x);
        // If list is empty
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 3️⃣ Delete head
    void deleteHead()
    {
        // If list is empty
        if (head == NULL)
            return;

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // 4️⃣ Delete tail
    void deleteTail()
    {
        // If list is empty
        if (head == NULL)
            return;

        // If list has only one element
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // 5️⃣ Search for a value
    bool search(int key)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->val == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // 6️⃣ Display linked list
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }

    // 7️⃣ Count nodes
    int count()
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // 8️⃣ Reverse linked list
    void reverse()
    {
        Node *prev = NULL;
        Node *curr = head;
        while (curr != NULL)
        {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }

    // 9️⃣ Find middle node
    int findMiddle()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->val;
    }

    // 🔟 Detect cycle (Floyd’s algorithm)
    bool hasCycle()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    // 1️⃣1️⃣ Remove duplicates from sorted list
    void removeDuplicates()
    {
        Node *temp = head;
        while (temp && temp->next)
        {
            if (temp->val == temp->next->val)
            {
                Node *duplicate = temp->next;
                temp->next = duplicate->next;
                delete duplicate;
            }
            else
            {
                temp = temp->next;
            }
        }
    }

    // 1️⃣2️⃣ Delete node with specific value
    void deleteValue(int key)
    {
        if (head == NULL)
            return;
        if (head->val == key)
        {
            deleteHead();
            return;
        }

        Node *temp = head;
        while (temp->next != NULL && temp->next->val != key)
        {
            temp = temp->next;
        }

        if (temp->next != NULL)
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // // 1️⃣3️⃣ Reverse in K groups
    // void reverseKGroup(int k) {};

    // // 1️⃣4️⃣ Check if the list is a palindrome
    // bool isPalindrome() {};

    // // 1️⃣5️⃣ Remove N-th node from end
    // void removeNthFromEnd(int n) {};

    // // 1️⃣6️⃣ Merge two sorted linked lists
    // void mergeSortedLists(Node *otherHead) {};

    // // 1️⃣7️⃣ Detect and remove cycle
    // void detectAndRemoveCycle() {};

    // // 1️⃣8️⃣ Find intersection point of two linked lists
    // Node *getIntersectionNode(Node *headA, Node *headB) {};

    // // 1️⃣9️⃣ Sort the linked list (Merge Sort)
    // Node *mergeSort(Node *head) {}; // Call from wrapper inside class if needed

    // // 2️⃣0️⃣ Rotate linked list by k places
    // void rotateRight(int k) {};
};

int main()
{
    LinkedList list;

    // 🧪 Level 1 Testing
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtHead(5);

    cout << "List: ";
    list.display();
    cout << endl;

    cout << "Searching 20: " << (list.search(20) ? "Found" : "Not Found") << endl;

    list.deleteHead();
    list.deleteTail();

    cout << "List after deletions: ";
    list.display();
    cout << endl;

    // 🚀 Level 2 Testing – Uncomment as you implement each
    list.insertAtTail(40);
    list.insertAtTail(50);

    cout << "\nNew List for Level 2: ";
    list.display();
    cout << endl;

    // 1️⃣3️⃣ Reverse in K groups
    // list.reverseKGroup(2);
    // cout << "After reverse in K groups: ";
    // list.display();
    // cout << endl;

    // 1️⃣4️⃣ Check if palindrome
    // cout << "Is Palindrome? " << (list.isPalindrome() ? "Yes" : "No") << endl;

    // 1️⃣5️⃣ Remove N-th node from end
    // list.removeNthFromEnd(2);
    // cout << "After removing N-th node from end: ";
    // list.display();
    // cout << endl;

    // 1️⃣6️⃣ Merge two sorted lists
    // LinkedList other;
    // other.insertAtTail(15);
    // other.insertAtTail(35);
    // list.mergeSortedLists(other.getHead());
    // cout << "After merging with another sorted list: ";
    // list.display();
    // cout << endl;

    // 1️⃣7️⃣ Detect and remove cycle
    // Node* head = list.getHead();
    // head->next->next->next = head;  // Creating a cycle
    // cout << "Cycle present? " << (list.hasCycle() ? "Yes" : "No") << endl;
    // list.detectAndRemoveCycle();
    // cout << "Cycle after removal? " << (list.hasCycle() ? "Yes" : "No") << endl;

    // 1️⃣8️⃣ Find intersection point
    // (You’ll need to simulate intersection manually if needed)

    // 1️⃣9️⃣ Merge sort the linked list
    // Node* sorted = list.mergeSort(list.getHead());
    // LinkedList sortedList;
    // sortedList.setHead(sorted);
    // cout << "Sorted List: ";
    // sortedList.display();
    // cout << endl;

    // 2️⃣0️⃣ Rotate by k places
    // list.rotateRight(2);
    // cout << "After rotating by 2 places: ";
    // list.display();
    // cout << endl;

    return 0;
}
