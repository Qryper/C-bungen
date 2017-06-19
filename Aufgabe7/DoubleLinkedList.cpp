#include "DoubleLinkedList.hpp"
#include <iostream>

DoubleLinkedList::DoubleLinkedList() : first(nullptr), last(nullptr), size(0) {};

DoubleLinkedList::~DoubleLinkedList()
{
  while (size > 0)
    {
      Node *node_to_be_removed = first;
      first = first->next;
      delete node_to_be_removed;
      size--;
    }
}

int
DoubleLinkedList::getFirst() const
{
  return first->content;
}

int
DoubleLinkedList::getLast() const
{
  return last->content;
}

int
DoubleLinkedList::getSize() const
{
  return size;
}

int
DoubleLinkedList::get(int index) const
{
  return getNode(index)->content;
}

DoubleLinkedList::Node*
DoubleLinkedList::getNode(int index) const
{
  Node *current_node = first;
  while (index > 0)
    {
      current_node = current_node->next;
      index--;
    }
  return current_node;
}

bool
DoubleLinkedList::add(int data)
{
  if(isEmpty())
    {
      first = new Node(data);
      last = first;
    }
  else
    {
      Node* old_last = last;
      last = new Node(data);
      last->previous = old_last;
      old_last->next = last;
    }
  size++;
  return true;
}

bool
DoubleLinkedList::add(int data, int index)
{
  if (index < 0 || index > size)
    return false;
  if (index == size)
    return add(data);

  if (index == 0)
    {
      addAsFirst(data);
    }
  else
    {
      addToMiddle(data, index);
    }
  size++;
  return true;
}

void
DoubleLinkedList::addAsFirst(int data)
{
  Node *old_first = first;
  first = new Node(data);
  first->next = old_first;
  old_first->previous = first;
}

void
DoubleLinkedList::addToMiddle(int data, int index)
{
  Node *node_at_index = getNode(index);
  Node *new_node = new Node(data);
  Node *node_before_index = node_at_index->previous;
  new_node->previous = node_at_index->previous;
  new_node->next = node_at_index;
  node_at_index->previous = new_node;
  node_before_index->next = new_node;
}

bool
DoubleLinkedList::remove(int index)
{
  if (index < 0 || index >= size)
    return false;

  else if (index == 0)
    {
      removeFirst();
    }
  else if (index == size-1)
    {
      removeLast();
    }
  else
    {
      removeFromMiddle(index);
    }
  size--;
  if (size == 0)
    {
      first = nullptr;
      last = nullptr;
    }
  return true;
}

void
DoubleLinkedList::removeFirst()
{
  Node *node_to_be_removed = first;
  first = first->next;
  first->previous = nullptr;
  delete node_to_be_removed;
}

void
DoubleLinkedList::removeLast()
{
  Node *node_to_be_removed = last;
  last = last->previous;
  last->next = nullptr;
  delete node_to_be_removed;
}

void
DoubleLinkedList::removeFromMiddle(int index)
{
  Node *node_to_be_removed = getNode(index);
  Node *node_after_index = node_to_be_removed->next;
  Node *node_before_index = node_to_be_removed->previous;

  node_before_index->next = node_after_index;
  node_after_index->previous = node_before_index;
  delete node_to_be_removed;
}

void
DoubleLinkedList::print() const
{
  for (Node *current_node = first; current_node->next != nullptr;
       current_node = current_node->next)
    {
      std::cout << current_node->content << ", ";
    }
  std::cout << std::endl;
}

bool
DoubleLinkedList::isEmpty() const
{
  return size == 0;
}
