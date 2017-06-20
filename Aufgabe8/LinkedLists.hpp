#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

class LinkedList
{
public:
  LinkedList();
  ~LinkedList();
  int getFirst() const;
  int getLast() const;
  int getSize() const;
  int get(int index) const;
  bool add(int data);
  bool add(int data, int index);
  bool remove(int index);
  void print() const;
  bool isEmpty() const;

private:
  struct Node
  {
    Node() : next(nullptr), content(0) {};
    Node(int content) : next(nullptr), content(content) {};
    Node *next;
    int content;
  };
  Node* first;
  Node* getNode(int index) const;
  void addAsFirst(int data);
  void addToMiddle(int data, int index);
  void removeFirst();
  void removeLast();
  void removeFromMiddle(int index);
  int size;
};

#endif
