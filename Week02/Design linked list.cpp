//MC: O(1)
//TC: added above individual functions

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int x): val(x), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    MyLinkedList(): head(nullptr), size(0) {}

    //O(n)
    int get(int index) {
        if(index < 0 || index >= size) return -1;

        Node* curr = head;
        for(int i = 0; i < index; i++)
            curr = curr->next;
        return curr->val;
    }

    //O(1)
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    //O(n)
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) head = newNode;
        else {
            Node* curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size++;
    }

    //O(n)
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* curr = head;
        for (int i = 0; i < index - 1; i++)
            curr = curr->next;
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }

    //O(n)
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        Node* curr = head;
        if (index == 0) {
            head = head->next;
            delete curr;
        }
        
        else {
            for (int i = 0; i < index - 1; i++)
                curr = curr->next;
            Node* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
        }
        size--;
    }
};
