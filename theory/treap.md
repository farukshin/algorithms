# Декартово дерово

```
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

class Treap {
    static minstd_rand generator;


    struct Node {
        int key, priority;
        Node* l = nullptr, * r = nullptr;
        Node(int key) : key(key), priority(generator()) {}
    } *root = nullptr;

    static Node* merge(Node* a, Node* b) {
        if (!a || !b) return a ? a : b;
        if (a->priority > b->priority)
        {
            a->l = merge(a->r, b);
            return a;
        }
        else {
            b->l = merge(a, b->l);
            return b;
        }
    }

    static void split(Node* n, int key, Node*& a, Node*& b)
    {
        if (!n) { a = b = nullptr; return; }
        if (n->key < key)
        {
            split(n->r, key, n->r, b);
            a = n;
        }
        else {
            split(n->l, key, a, n->l);
            b = n;
        }
    }

    int min(Node *n){
        if(!n)
            return -1;
        while(n->l)
            n=n->l;
        return n->key;
    }
public:

    bool contains(int key) {
        Node* less, * greater, * equal;
        split(root, key, less, greater);
        split(greater, key + 1, equal, greater);
        bool result = equal;
        root = merge(merge(less, equal), greater);
        return result;
    }

    void insert(int key) {
        Node* less, * greater;
        split(root, key, less, greater);
        root = merge(merge(less, new Node(key)), greater);
    }

    void erase(int key) {
        Node* less, * greater, * equal;
        split(root, key, less, greater);
        split(greater, key + 1, equal, greater);
        root = merge(less, greater);
    }

    int next(int key){
        Node* less, * greater;
        split(root, key, less, greater);
        int res = min(greater);
        root = merge(less, greater);
        return res;
    }
};

minstd_rand Treap::generator;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("input.txt", "r", stdin);

    Treap t;
    int n;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        string command;
        int x;
        cin >> command >> x;
        if (command == "+" && !t.contains(x))
            if () t.insert(x);
        else if(command == "?")
            cout << t.next(x) << "\n";
    }
}

```


```
6
+ 1
+ 3
+ 3
? 2
+ 1
? 4
```
