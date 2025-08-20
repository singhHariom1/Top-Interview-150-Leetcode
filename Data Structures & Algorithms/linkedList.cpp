#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    Node* getHead() { return head; }
    void setHead(Node* newHead) { head = newHead; }

    // 1️⃣ Insert at head
    void insertAtHead(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    // 2️⃣ Insert at tail
    void insertAtTail(int x) {
        Node* newNode = new Node(x);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // 3️⃣ Delete head
    void deleteHead() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // 4️⃣ Delete tail
    void deleteTail() {
        if (!head) return;
        if (!head->next) { delete head; head = NULL; return; }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    // 5️⃣ Search
    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->val == key) return true;
            temp = temp->next;
        }
        return false;
    }

    // 6️⃣ Display
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }

    // 7️⃣ Count nodes
    int count() {
        int cnt = 0;
        Node* temp = head;
        while (temp) { cnt++; temp = temp->next; }
        return cnt;
    }

    // 8️⃣ Reverse whole list
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }

    // 9️⃣ Middle
    int findMiddle() {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow ? slow->val : -1;
    }

    // 🔟 Detect cycle
    bool hasCycle() {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    // 1️⃣1️⃣ Remove duplicates (sorted)
    void removeDuplicates() {
        Node* temp = head;
        while (temp && temp->next) {
            if (temp->val == temp->next->val) {
                Node* dup = temp->next;
                temp->next = dup->next;
                delete dup;
            } else temp = temp->next;
        }
    }

    // 1️⃣2️⃣ Delete value
    void deleteValue(int key) {
        if (!head) return;
        if (head->val == key) { deleteHead(); return; }
        Node* temp = head;
        while (temp->next && temp->next->val != key) temp = temp->next;
        if (temp->next) {
            Node* toDel = temp->next;
            temp->next = temp->next->next;
            delete toDel;
        }
    }

    // 1️⃣3️⃣ Reverse in k-groups
    Node* reverseK(Node* h, int k) {
        Node* prev = NULL;
        Node* curr = h;
        Node* nxt = NULL;
        int cnt = 0;
        Node* temp = h;
        for (int i=0;i<k && temp;i++) temp=temp->next;
        if (!temp && cnt<k-1) return h; // less than k left
        while (curr && cnt < k) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            cnt++;
        }
        if (nxt) h->next = reverseK(nxt, k);
        return prev;
    }
    void reverseKGroup(int k) { head = reverseK(head, k); }

    // 1️⃣4️⃣ Palindrome check
    bool isPalindrome() {
        if (!head || !head->next) return true;
        // find mid
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse second half
        Node* prev = NULL;
        Node* curr = slow;
        while (curr) {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        Node* left = head;
        Node* right = prev;
        while (right) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }

    // 1️⃣5️⃣ Remove Nth from end
    void removeNthFromEnd(int n) {
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* first = dummy;
        Node* second = dummy;
        for (int i=0;i<=n;i++) first=first->next;
        while (first) {
            first=first->next;
            second=second->next;
        }
        Node* del = second->next;
        second->next = second->next->next;
        if (del == head) head = head->next;
        delete del;
        head = dummy->next;
        delete dummy;
    }

    // 1️⃣6️⃣ Merge two sorted lists
    void mergeSortedLists(Node* otherHead) {
        Node dummy(0);
        Node* tail = &dummy;
        Node* l1 = head;
        Node* l2 = otherHead;
        while (l1 && l2) {
            if (l1->val < l2->val) { tail->next = l1; l1=l1->next; }
            else { tail->next = l2; l2=l2->next; }
            tail=tail->next;
        }
        tail->next = l1?l1:l2;
        head = dummy.next;
    }

    // 1️⃣7️⃣ Detect + remove cycle
    void detectAndRemoveCycle() {
        if (!head) return;
        Node* slow = head;
        Node* fast = head;
        bool hasC = false;
        while (fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast) { hasC=true; break; }
        }
        if (!hasC) return;
        slow=head;
        while (slow!=fast) { slow=slow->next; fast=fast->next; }
        while (fast->next!=slow) fast=fast->next;
        fast->next=NULL;
    }

    // 1️⃣8️⃣ Intersection of 2 lists
    Node* getIntersectionNode(Node* headA, Node* headB) {
        if (!headA || !headB) return NULL;
        Node* a = headA;
        Node* b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }

    // 1️⃣9️⃣ Merge sort list
    Node* merge(Node* l1, Node* l2) {
        Node dummy(0); Node* tail=&dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) { tail->next=l1; l1=l1->next; }
            else { tail->next=l2; l2=l2->next; }
            tail=tail->next;
        }
        tail->next = l1?l1:l2;
        return dummy.next;
    }
    Node* mergeSortUtil(Node* h) {
        if (!h || !h->next) return h;
        Node* slow=h; Node* fast=h->next;
        while (fast && fast->next) { slow=slow->next; fast=fast->next->next; }
        Node* mid=slow->next; slow->next=NULL;
        Node* left=mergeSortUtil(h);
        Node* right=mergeSortUtil(mid);
        return merge(left,right);
    }
    Node* mergeSort(Node* h) { return mergeSortUtil(h); }

    // 2️⃣0️⃣ Rotate right by k
    void rotateRight(int k) {
        if (!head || !head->next || k==0) return;
        int len=1;
        Node* tail=head;
        while (tail->next) { tail=tail->next; len++; }
        k%=len;
        if (k==0) return;
        tail->next=head; // make cycle
        int steps=len-k;
        Node* newTail=head;
        for (int i=1;i<steps;i++) newTail=newTail->next;
        head=newTail->next;
        newTail->next=NULL;
    }
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
    list.reverseKGroup(2);
    cout << "After reverse in K groups: ";
    list.display();
    cout << endl;

    // 1️⃣4️⃣ Check if palindrome
    cout << "Is Palindrome? " << (list.isPalindrome() ? "Yes" : "No") << endl;

    // 1️⃣5️⃣ Remove N-th node from end
    list.removeNthFromEnd(2);
    cout << "After removing N-th node from end: ";
    list.display();
    cout << endl;

    // 1️⃣6️⃣ Merge two sorted lists
    LinkedList other;
    other.insertAtTail(15);
    other.insertAtTail(35);
    list.mergeSortedLists(other.getHead());
    cout << "After merging with another sorted list: ";
    list.display();
    cout << endl;

    // 1️⃣7️⃣ Detect and remove cycle
    Node* head = list.getHead();
    head->next->next->next = head;  // Creating a cycle
    cout << "Cycle present? " << (list.hasCycle() ? "Yes" : "No") << endl;
    list.detectAndRemoveCycle();
    cout << "Cycle after removal? " << (list.hasCycle() ? "Yes" : "No") << endl;

    // 1️⃣8️⃣ Find intersection point
    // (You’ll need to simulate intersection manually if needed)

    // 1️⃣9️⃣ Merge sort the linked list
    Node* sorted = list.mergeSort(list.getHead());
    LinkedList sortedList;
    sortedList.setHead(sorted);
    cout << "Sorted List: ";
    sortedList.display();
    cout << endl;

    // 2️⃣0️⃣ Rotate by k places
    list.rotateRight(2);
    cout << "After rotating by 2 places: ";
    list.display();
    cout << endl;

    return 0;
}
