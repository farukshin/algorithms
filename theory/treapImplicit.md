# Декартово дерово по неявному ключу

```
#include <iostream>
#include <algorithm>
#include <string>
#include <random>

using namespace std;

class TreapImplicit {
    static minstd_rand generator;

    struct Node {
        int priority, value = 0, size = 1;
        Node* l = nullptr, * r = nullptr;
        Node(int _value) : priority(generator()), value(_value) {};
    } *root = nullptr;

    static int getSize(Node* n)
    {
        return n ? n->size : 0;
    }

    static void update(Node* n)
    {
        if (n)
            n->size = getSize(n->l) + 1 + getSize(n->r);
    }

    static Node* merge(Node* a, Node* b) {
        if (!a || !b) return a ? a : b;
        if (a->priority > b->priority)
        {
            a->r = merge(a->r, b);
            update(a);
            return a;
        }
        else {
            b->l = merge(a, b->l);
            update(b);
            return b;
        }
    }

    static void split(Node* n, int k, Node*& a, Node*& b)
    {
        if (!n) { a = b = nullptr; return; }
        if (getSize(n->l) < k)
        {
            split(n->r, k - getSize(n->l) - 1, n->r, b);
            a = n;
        }
        else {
            split(n->l, k, a, n->l);
            b = n;
        }
        update(a);
        update(b);
    }

public:

    int get(int index) {
        Node* less, * greater, * equal;
        split(root, index, less, greater);
        split(greater, 1, equal, greater);
        int result = equal->value;
        root = merge(merge(less, equal), greater);
        return result;
    }

    void pushBack(int value) {
        root = merge(root, new Node(value));
    }

    void pushFront(int value) {
        root = merge(new Node(value), root);
    }

    void insert(int index, int value) {
        Node* less, * greater;
        split(root, index, less, greater);
        root = merge(merge(less, new Node(value)), greater);
    }

    void erase(int index) {
        Node* less, * greater, * equal;
        split(root, index, less, greater);
        split(greater, 1, equal, greater);
        root = merge(less, greater);
    }

    void erase(int l, int r) {
        Node* less, * greater, * equal;
        split(root, l, less, greater);
        split(greater, r - l + 1, equal, greater);
        root = merge(less, greater);
    }

    int size() {
        return getSize(root);
    }

};

minstd_rand TreapImplicit::generator;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    TreapImplicit t;
    t.pushBack(111);
    t.pushBack(222);
    t.pushBack(777);
    t.pushFront(888);
    t.insert(0,5);
    t.erase(2);

    for (int i = 0;i < t.size();i++)
        cout << t.get(i) << " ";
}

```
