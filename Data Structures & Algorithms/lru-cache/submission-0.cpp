class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        // Dummy nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Insert node just after head
    void insertAfterHead(Node* node) {

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // Delete a node from the list
    void deleteNode(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {

        // Key does not exist
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // Move this node to the front
        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];

            // Update value
            node->value = value;

            // Make it most recently used
            deleteNode(node);
            insertAfterHead(node);

            return;
        }

        // Key does not exist
        Node* newNode = new Node(key, value);

        // Add to hashmap
        mp[key] = newNode;

        // Add to front
        insertAfterHead(newNode);

        // Capacity exceeded
        if(mp.size() > capacity) {

            // Least recently used node
            Node* lru = tail->prev;

            // Remove from linked list
            deleteNode(lru);

            // Remove from hashmap
            mp.erase(lru->key);

            // Free memory
            delete lru;
        }
    }
};