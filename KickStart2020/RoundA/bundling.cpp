#include <bits/stdc++.h>
using namespace std;

// Try implementing a radix tree

struct Node {

    // Parent
    Node* p = nullptr;

    // Children
    Node* c = nullptr;
    // Number of children
    int nc = 0;

    // Value
    string v;
};

Node* lookup(Node* r, string x, int* n) {

    Node* p = r;
    int elem_found = 0;

    while (true) {

        if (p == nullptr) {
            break;
        } else if (p->nc == 0) {
            break;
        } else if (elem_found >= x.length()) {
            break;
        }

        // Get next node n
        Node* n = nullptr;
        Node* c = p->c; // Children of p
        string suff = x.substr(elem_found, string::npos);
        for (int i = 0; i < p->nc; i++) {
            // Compare suffix to label of node
            if (suff.compare(c->v) == 0)
                n = c;

            c++;
        }

        // Traversable node was found
        if (n != nullptr) {
            p = n; // Set the next node to explore
            elem_found += n->v.length();
        } else {
            break; // Terminate loop
        }

    }

    *n = elem_found;
    return p;

}

void insert(Node* r, string x) {

    int n;
    Node* e = lookup(r, x, &n);

    Node* c = e->c;
    for (int i = 0; i < e->nc; i++) {

        if (c->)

        c++;
    }

}

void solve() {

    int N, K;
    cin >> N >> K;

    Node r;
    lookup(&r, "test");

}

int main(void) {

    int c;
    cin >> c;
    
    for (int i = 1; i <= c; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
