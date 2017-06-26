#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

class ArrayList
{
public:
  friend std::ostream&
  ArrayList();
  ~ArrayList();
  ArrayList(const ArrayList& a);
  ArrayList operator<<(const ArrayList& list);
  ArrayList& operator<<(const ArrayList& list);
  ArrayList(ArrayList&& other);
  const int* getFirst() const;
  const int* getLast() const;
  int getSize() const;
  int get(int index) const;
  bool add(int data);
  bool add(int data, int index);
  bool remove(int index);
  void print() const;
  bool isEmpty() const;

private:
  int current_size;
  int *array;
  bool needToGrow() const;
  bool needToShrink() const;
  void moveElementsBeginningWithIndexOneStepToTheRight(int index);
  void transferElementsToBiggerArrayLeavingIndexEmpty(int index);
  void moveElementsRightFromIndexOneStepToTheLeft(int index);
  void transferElementsExceptIndexToSmallerArray(int index);
  bool indexDoesNotExist(int index) const;
  bool noElementCanBeAddedAt(int index) const;
};

#endif
