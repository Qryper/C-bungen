#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP

class DoubleLinkedList
{
public:
  DoubleLinkedList();
  ~DoubleLinkedList();
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
    Node() : previous(nullptr), next(nullptr), content(0) {};
    Node(int content) : previous(nullptr), next(nullptr), content(content) {};
    Node *previous;
    Node *next;
    int content;
  };
  Node* first;
  Node* last;
  Node* getNode(int index) const;
  void addAsFirst(int data);
  void addToMiddle(int data, int index);
  void removeFirst();
  void removeLast();
  void removeFromMiddle(int index);
  int size;
};

#endif
