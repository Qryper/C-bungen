#include "LinkedLists.hpp"
#include <iostream>

LinkedList::LinkedList() : first(nullptr), size(0){};

LinkedList::~LinkedList()
{
  Node* node_to_be_removed;
  while(first != nullptr)
    {
      node_to_be_removed = first;
      first = first->next;
      delete node_to_be_removed;
    }
}

int
LinkedList::getFirst() const
{
  return first->content;
}

int
LinkedList::getLast() const
{
  return getNode(size-1)->content;
}

int
LinkedList::getSize() const
{
  return size;
}

int
LinkedList::get(int index) const
{
  return getNode(index)->content;
}

bool
LinkedList::add(int data)
{
  Node *new_node = new Node(data);
  if (isEmpty())
    {
      first = new_node;
    }
  else
    {
      getNode(size-1)->next = new_node;
    }
  size++;
  return true;
}

bool
LinkedList::add(int data, int index)
{
  if (index < 0 || index > size)
    {
      return false;
    }
  else if (index == size)
    {
      return add(data);
    }
  else if (index == 0)
    {
      addAsFirst(data);
    }
  else
    {
      Node* node_before_index = getNode(index-1);
      Node* new_node = new Node(data);
      new_node->next = node_before_index->next;
      node_before_index->next = new_node;
    }
  size++;
  return true;
}

void
LinkedList::addAsFirst(int data)
{
  Node* new_node = new Node(data);
  new_node->next = first;
  first = new_node;
}

bool
LinkedList::remove(int index)
{
  if (index < 0 || index >= size)
    {
      return false;
    }
  else if (index == 0)
    {
      removeFirst();
    }
  else
    {
      Node *node_before_index = getNode(index-1);
      Node *node_to_be_removed = node_before_index->next;
      node_before_index->next = node_before_index->next->next;
      delete node_to_be_removed;
    }
  size--;
  return true;
}

void
LinkedList::removeFirst()
{
  Node *node_to_be_removed = first;
  first = first->next;
  delete node_to_be_removed;
}


void
LinkedList::print() const
{
  for (Node *current_node = first; current_node->next != nullptr;
       current_node = current_node->next)
    {
      std::cout << current_node->content << ", ";
    }
  std::cout << std::endl;
}



bool
LinkedList::isEmpty() const
{
  return size == 0;
}

LinkedList::Node*
LinkedList::getNode(int index) const
{
  Node* current_node = first;
  while (index > 0)
    {
      current_node = current_node->next;
      index--;
    }
  return current_node;
}
