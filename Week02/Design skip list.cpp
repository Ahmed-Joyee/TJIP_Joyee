//TC: O(log n) on average for search(), add() and erase()
//MC: O(n), where n is the no of elements in the skiplist as each node has pointers for multiple levels

class Skiplist {
private:
    struct Node {
        int value;
        vector<Node*> next;
        Node(int val, int level): value(val), next(level, nullptr) {}
    };

    Node* head;
    int maxLevel;
    float probability;

    //random level generator based on the probability
    int random_level() {
        int level = 1;
        while(rand() * probability < RAND_MAX && level < maxLevel)
            level++;
        return level;
    }

public:
    Skiplist() {
        maxLevel = 16;
        probability = 0.5;
        head = new Node(-1, maxLevel);
    }
    
    bool search(int target) {
        Node* curr = head;
        for(int level = maxLevel - 1; level >= 0; level--) {
            while(curr->next[level] && curr->next[level]->value < target) {
                curr = curr->next[level];
            }
        }
        curr = curr->next[0];
        return curr && curr->value == target;
    }
    
    void add(int num) {
        vector<Node*> update(maxLevel, nullptr);
        Node* curr = head;

        for(int level = maxLevel - 1; level >= 0; level--) {
            while(curr->next[level] && curr->next[level]->value < num) {
                curr = curr->next[level];
            }
            update[level] = curr;
        }

        int newLevel = random_level();
        Node* newNode = new Node(num, newLevel);

        for(int i = 0; i < newLevel; i++) {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }   
    }
    
    bool erase(int num) {
        vector<Node*> update(maxLevel, nullptr);
        Node* curr = head;
        bool found = false;

        for (int level = maxLevel - 1; level >= 0; level--) {
            while (curr->next[level] && curr->next[level]->value < num) {
                curr = curr->next[level];
            }
            update[level] = curr;
        }
        curr = curr->next[0];

        if (curr && curr->value == num) {
            found = true;
            for (int i = 0; i < maxLevel; i++) {
                if (update[i]->next[i] != curr) break;
                update[i]->next[i] = curr->next[i];
            }
            delete curr;
        }
        return found;
    }
};
