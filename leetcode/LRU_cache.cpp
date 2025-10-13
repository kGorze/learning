#include <unordered_map>
#include <iostream>

struct Node{
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
    Node(int key, int value, Node* next, Node* prev) : key(key), value(value), next(next), prev(prev) {}
};

class LRUCache {
public:
    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* left_most;   
    Node* right_most;  

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->cache = std::unordered_map<int, Node*>();
        this->left_most = new Node(0,0);
        this->right_most = new Node(0,0);
        left_most->next = right_most;
        right_most->prev = left_most;
    }

    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        node->prev = node->next = nullptr;
    }   

    void insert(Node* node){
        Node* prev = right_most->prev;
        node->next = right_most;
        node->prev = prev;
        prev->next = node;
        right_most->prev = node;
    }

    int get(int key) {
        auto it = cache.find(key);
        if(it != cache.end()){
            Node* node = it->second;
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if(it != cache.end()){
            Node* node = it->second;
            node->value = value;
            remove(node);
            insert(node);
            return;
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);
        if(cache.size() > (size_t)capacity){
            Node* lru = left_most->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

int main(){
    LRUCache* cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    std::cout << cache->get(1) << std::endl; // 1
    cache->put(3, 3);
    std::cout << cache->get(2) << std::endl; // -1
    cache->put(4, 4);
    std::cout << cache->get(1) << std::endl; // -1
    std::cout << cache->get(3) << std::endl; // 3
    std::cout << cache->get(4) << std::endl; // 4
    return 0;
}