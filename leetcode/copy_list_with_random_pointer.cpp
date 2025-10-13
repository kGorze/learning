#include <iostream>
#include <unordered_map>

struct Node {
    int val;
    Node* next;
    Node* random;
    Node() : val(0), next(nullptr), random(nullptr) {}
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
    Node(int _val, Node* _next, Node* _random) : val(_val), next(_next), random(_random) {}
};

static void printList(Node* head){
    while(head){
        std::cout << head->val << " (rand=";
        if(head->random) std::cout << head->random->val;
        else std::cout << "X";
        std::cout << ")  ";
        head = head->next;
    }
    std::cout << "\n";
}

Node* copyRandomList(Node* head) {
    if(!head) return nullptr;

    std::unordered_map<Node*, Node*> mp;
    for(Node* p = head; p; p = p->next) {
        mp[p] = new Node(p->val);
    }
    for(Node* p = head; p; p = p->next) {
        mp[p]->next   = p->next   ? mp[p->next]   : nullptr;
        mp[p]->random = p->random ? mp[p->random] : nullptr;
    }
    return mp[head];
}

int main() {
    Node* n5 = new Node(5);
    Node* n4 = new Node(4, n5, nullptr);
    Node* n3 = new Node(3, n4, nullptr);
    Node* n2 = new Node(2, n3, nullptr);
    Node* head = new Node(1, n2, nullptr);

    // bezpieczne ustawienia random (tylko w granicach 1..5)
    head->random       = n3; // 1 -> 3
    n2->random         = n4; // 2 -> 4
    n3->random         = n5; // 3 -> 5
    n4->random         = nullptr; // 4 -> X
    n5->random         = head; // opcjonalnie: ustaw n1 poniżej

    // poprawka: potrzebujemy wskaźnika na n1 (head już go ma)
    n5->random = head; // 5 -> 1

    std::cout << "Stara lista:\n";
    printList(head);

    Node* copy = copyRandomList(head);
    std::cout << "Nowa lista:\n";
    printList(copy);
}