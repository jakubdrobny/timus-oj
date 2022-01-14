#include <iostream>
#include <string>

class Node {
  public:
    int val;
    Node *nxt;
    Node *prv;

    Node() {
      val = -1;
      nxt = NULL;
      prv = NULL;
    }
    Node(int val, Node *prv, Node* nxt) {
      val = val;
      prv = prv;
      nxt = nxt;
    }
};

class LinkedList {
  Node *head;
  public:
    void add(int val) {
      Node *tmp = new Node(val, head, NULL);
      head->nxt = tmp;
      head = head->nxt;
    }
    int remove() {
      int res = head->val;
      head = head->prv;
      head->nxt = NULL;
      return res;
    }
};

const int mxn = 1001;
LinkedList st[mxn];

int main() {
  int n; std::cin >> n;
  while (n--) {
    std::string op; std::cin >> op;
    int num; std::cin >> num;
    if (op == "PUSH") {
      int val; std::cin >> val;
      st[num].add(val);
    } else {
      printf("%d\n", st[num].remove());
    }
  }
}