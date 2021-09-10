## Задача SuperMemo

Дан массив из N элементов. Необходимо поддерживать следубщие операции:

* ADD x y D: Add D to each number in sub-sequence {Ax ... Ay}. For example, performing "ADD 2 4 1" on {1, 2, 3, 4, 5} results in {1, 3, 4, 5, 5}
* REVERSE x y: reverse the sub-sequence {Ax ... Ay}. For example, performing "REVERSE 2 4" on {1, 2, 3, 4, 5} results in {1, 4, 3, 2, 5}
* REVOLVE x y T: rotate sub-sequence {Ax ... Ay} T times. For example, performing "REVOLVE 2 4 2" on {1, 2, 3, 4, 5} results in {1, 3, 4, 2, 5}
* INSERT x P: insert P after Ax. For example, performing "INSERT 2 4" on {1, 2, 3, 4, 5} results in {1, 2, 4, 3, 4, 5}
* DELETE x: delete Ax. For example, performing "DELETE 2" on {1, 2, 3, 4, 5} results in {1, 3, 4, 5}
* MIN x y: query the participant what is the minimum number in sub-sequence {Ax ... Ay}. For example, the correct answer to "MIN 2 4" on {1, 2, 3, 4, 5} is 2

```
// http://poj.org/problem?id=3580
#include <iostream>
#include <algorithm>
#include <string>
#include <random>

using namespace std;

class TreapImplicit {
    static minstd_rand generator;

    struct Node {
        int priority, value = 0, size = 1, minValue, add=0;
        bool rev = false;
        Node* l = nullptr, * r = nullptr;
        Node(int _value) : priority(generator()), value(_value), minValue(_value) {};
    } *root = nullptr;

    static int getSize(Node* n)
    {
        return n ? n->size : 0;
    }
    
    static int getMinValue(Node* n)
    {
        return n ? n->minValue + n->add : 2e9;
    }
    
    static void push(Node *n)
    {
    	if(n){
    		if(n->add)
    		{
    			n->value += n->add;
	    		n->minValue += n->add;
	    		if(n->l) n->l->add+=n->add;
	    		if(n->r) n->r->add+=n->add;
    			n->add = 0;
    		}
    		if(n->rev)
    		{
    			swap(n->l, n->r);
    			if(n->l) n->l->rev ^=1;
	    		if(n->r) n->r->rev ^=1;
    			n->rev = false;
    		}
    	}
    }

    static void update(Node* n)
    {
        if (n)
        {
           	n->size = getSize(n->l) + 1 + getSize(n->r);
           	n->minValue = min(min(getMinValue(n->l), getMinValue(n->r)), n->value);
        }
    }

    static Node* merge(Node* a, Node* b) {
    	push(a);
    	push(b);
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
    	push(n);
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
    
    void revolve(int l, int r, int t) {
        Node* less, * greater, * equal;
        split(root, l, less, greater);
        split(greater, r - l + 1, equal, greater);
        
        int len = getSize(equal);
        t%=len;
        Node *a, *b;
        split(equal, len - t, a, b);
        equal = merge(b,a);
        root = merge(merge(less, equal), greater);
    }

    int size() {
        return getSize(root);
    }
    
    int minValue(int l, int r) {
        Node* less, * greater, * equal;
        split(root, l, less, greater);
        split(greater, r-l+1, equal, greater);
        int result = equal->minValue;
        root = merge(merge(less, equal), greater);
        return result;
    }
    
    void add(int l, int r, int val) {
        Node* less, * greater, * equal;
        split(root, l, less, greater);
        split(greater, r - l + 1, equal, greater);
        equal->add += val;
        root = merge(merge(less, equal), greater);
    }
    
    void reverse(int l, int r) {
        Node* less, * greater, * equal;
        split(root, l, less, greater);
        split(greater, r - l + 1, equal, greater);
        equal->rev ^= 1;
        root = merge(merge(less, equal), greater);
    }

};

minstd_rand TreapImplicit::generator;

void solve()
{
	int n;
	cin>>n;
	TreapImplicit t;
	for(int i=0;i<n;i++)
	{
		int cur;
		cin>>cur;
		t.pushBack(cur);
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		string command;
		cin>>command;
		if(command == "INSERT")
		{
			int x, val;
			cin>>x>>val;
			t.insert(x, val);
		}
		
		if(command == "DELETE")
		{
			int x;
			cin>>x;
			t.erase(x);
		}
		
		if(command == "REVOLVE")
		{
			int x, y, cnt;
			cin>>x>>y >> cnt;
			t.revolve(x, y, cnt);
		}
		
		if(command == "MIN")
		{
			int l, r;
			cin>>l>>r;
			cout<< t.minValue(l-1, r-1) <<"\n";
		}
		
		if(command == "ADD")
		{
			int l, r, val;
			cin>>l>>r >> val;
			t.add(l-1, r-1, val);
		}
		
		if(command == "REVERSE")
		{
			int l, r;
			cin>>l>>r;
			t.reverse(l-1, r-1);
		}
	}
	
	// for(int i=0;i<t.size();i++)
	// 	cout<<t.get(i)<<" ";
	
}

int main()
{
	solve();
	return 0;
}

```