class AllOne {
public:

    struct Node {
        int freq;
        unordered_set<string> keys;

        Node* prev;
        Node* next;

        Node(int f) {
            freq = f;
            prev = NULL;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;

    unordered_map<string, Node*> mp;

    AllOne() {
        head = new Node(0);
        tail = new Node(0);

        head->next = tail;
        tail->prev = head;
    }

    // Insert new node after given node
    Node* insertAfter(Node* prevNode, int freq) {

        Node* newNode = new Node(freq);

        newNode->next = prevNode->next;
        newNode->prev = prevNode;

        prevNode->next->prev = newNode;
        prevNode->next = newNode;

        return newNode;
    }

    // Remove a node from linked list
    void removeNode(Node* node) {

        node->prev->next = node->next;
        node->next->prev = node->prev;

        delete node;
    }

    void inc(string key) {

        // Key doesn't exist
        if (mp.find(key) == mp.end()) {

            // Check whether frequency 1 node already exists
            Node* first = head->next;

            if (first == tail || first->freq != 1) {
                first = insertAfter(head, 1);
            }

            first->keys.insert(key);
            mp[key] = first;
        }

        // Key already exists
        else {

            Node* current = mp[key];
            int newFreq = current->freq + 1;

            Node* nextNode = current->next;

            // Frequency +1 node doesn't exist
            if (nextNode == tail || nextNode->freq != newFreq) {
                nextNode = insertAfter(current, newFreq);
            }

            // Move key
            nextNode->keys.insert(key);
            mp[key] = nextNode;

            current->keys.erase(key);

            // Current bucket became empty
            if (current->keys.empty()) {
                removeNode(current);
            }
        }
    }

    void dec(string key) {

        Node* current = mp[key];

        // Frequency is 1 → remove key completely
        if (current->freq == 1) {

            current->keys.erase(key);
            mp.erase(key);

            if (current->keys.empty()) {
                removeNode(current);
            }

            return;
        }

        int newFreq = current->freq - 1;

        Node* prevNode = current->prev;

        // Frequency -1 node doesn't exist
        if (prevNode == head || prevNode->freq != newFreq) {
            prevNode = insertAfter(prevNode, newFreq);
        }

        // Move key
        prevNode->keys.insert(key);
        mp[key] = prevNode;

        current->keys.erase(key);

        // Current bucket became empty
        if (current->keys.empty()) {
            removeNode(current);
        }
    }

    string getMaxKey() {

        if (tail->prev == head) {
            return "";
        }

        return *(tail->prev->keys.begin());
    }

    string getMinKey() {

        if (head->next == tail) {
            return "";
        }

        return *(head->next->keys.begin());
    }
};