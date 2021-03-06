#include "ArrayList.hpp"
#include <algorithm>
#include <iostream>

static bool
isPowerOfTwo(unsigned number);

ArrayList::ArrayList() : current_size(0), array(nullptr)
{
  array = new int[1];
}

static int calculateNextPowerOfTwo(unsigned int number)
{

}

ArrayList::~ArrayList()
{
  delete[] array;
}

ArrayList::ArrayList(const ArrayList& a) : current_size(a.current_size), array(new int[calculateNextPowerOfTwo(a.current_size)]){
/*	array = new int [a.current_size];
	current_size = a.current_size;  */

	for(int index = 0; index <a.current_size; index ++){
		this->add(a.get(index),index);
		//array[index]= a.array[index]
	}
	//std::copy(other.array, other.array+curent_size, array); (anstatt for)

}

ArrayList::ArrayList(ArrayList&& other) : current_size(other.current_size) , array(other.array){
	other.array = nullptr; //damit Destruktor nicht aufgerufen wird und die Daten vom Pointer mit l�scht
	//NULL ist Makro (void*) 0 und nicht Nullptr
}

std::ostream& operator<<(std::ostream& out_stream,const ArrayList& list){
	for(int i=0;i<list.current_size;i++){
		out_stream << list.array[i] << ", ";
	}
	out_stream << *list.getLast() << std::endl;
}
/*
 * Meine Impl.
ArrayList::ArrayList operator+(const ArrayList rhs)const{
	ArrayList new_List;
	new_List.current_size = this->current_size + list.current_size;
	new_List.array = new int*();
	for(int i=0; i<this->current_size;i++){
		new_List.add(this->get(i));
	}
	for(int i=0; i<list.current_size;i++){
		new_List.add(list.get(i));
	}
	return new_List;
}
*/

ArrayList:: ArrayList operator+(const ArrayList rhs)const{ //rhs = right hand side
	 ArrayList new_List;  // nicht dynamisch alloziert, da sonst expl. deleted werden muss
	 new_List += *this;
	 new_List += rhs;
	 return new_List;
 }

ArrayList&
ArrayList::operator+=(const ArrayList& rhs){
	int new_size = rhs.current_size + current_size;
	int capacity = calculateNextPowerOfTwo(new_size);
	int new_array[] = new int[capacity];
	std::copy(array, array+current_size, new_size);
	std::copy(rhs.array, rhs.array+rhs.current_size, array+current_size);
	delete[] array;
	array = new_array;
	current_size = new_size;
	return *this;
}

ArrayList
ArrayList::operator-(const ArrayList& rhs){

}

ArrayList&
ArrayList::operator-=(const ArrayList& rhs){
	for(int lhs_index = 0; lhs_index < current_size;lhs_index++){
		for(int rhs_index = 0; rhs_index < rhs.current_size; rhs_index++){
			if(array[lhs_index] == rhs.array[rhs_index]){
				this->remove(lhs_index);
			}
		}
	}
}


const int*
ArrayList::getFirst() const
{
  return array;
}

const int*
ArrayList::getLast() const
{
  return array+current_size;
}

int
ArrayList::getSize() const
{
  return current_size;
}

int
ArrayList::get(int index) const
{
  return array[index];
}

bool
ArrayList::add(int data)
{
  return add(data, current_size);
}

bool
ArrayList::add(int data, int index)
{
  if (noElementCanBeAddedAt(index)) return false;
  if (needToGrow())
    {
      transferElementsToBiggerArrayLeavingIndexEmpty(index);
    }
  else
    {
      moveElementsBeginningWithIndexOneStepToTheRight(index);
    }
  array[index] = data;
  current_size++;
  return true;
}

bool
ArrayList::remove(int index)
{
  if (indexDoesNotExist(index)) return false;
  if (needToShrink())
    {
      transferElementsExceptIndexToSmallerArray(index);
    }
  else
    {
      moveElementsRightFromIndexOneStepToTheLeft(index);
    }
  current_size--;
  return true;
}

bool
ArrayList::indexDoesNotExist(int index) const
{
  return (index < 0 || index > current_size-1);
}

bool
ArrayList::noElementCanBeAddedAt(int index) const
{
  return (index < 0 || index > current_size);
}


bool
ArrayList::needToGrow() const
{
  unsigned int size = static_cast<unsigned int>(current_size);
  return isPowerOfTwo(size);
}

bool
ArrayList::needToShrink() const
{
  unsigned int size_after_remove = static_cast<unsigned int> (current_size-1);
  return isPowerOfTwo(size_after_remove);
}

bool
isPowerOfTwo(unsigned int number)
{  /* We need to grow if the current size is a power of two.
    * The trick here is, that the expression
    * (number & number-1)
    * evaluates to zero iff size is a power of two.
    * As an example look at the number
    * 001000
    * subtracting one produces
    * 000111
    * therefore the binary AND produces zero.
    */
  return (number != 0 & !(number & number-1));
}

void
ArrayList::transferElementsToBiggerArrayLeavingIndexEmpty(int index)
{
  int* new_array = new int[current_size*2];
  std::copy(array, array+index, new_array);
  std::copy(array+index, array+current_size, new_array+index+1);
  delete[] array;
  array = new_array;
}

void
ArrayList::moveElementsBeginningWithIndexOneStepToTheRight(int index)
{
  // Move all elements beginning from index one step to the right,
  // to free space for the element to be added.
  // copy_backward has to be used here, so copying starts with the
  // last element and no elements get overwritten
  std::copy_backward(array+index, array+current_size, array+current_size+1);
}

void
ArrayList::moveElementsRightFromIndexOneStepToTheLeft(int index)
{
  std::copy(array+index+1, array+current_size, array+index);
}

void
ArrayList::transferElementsExceptIndexToSmallerArray(int index)
{
  // at this point we know, that current_size-1 is a power of two
  // and the correct size for the smaller array
  int* new_array = new int[current_size-1];
  std::copy(array, array+index, new_array);
  std::copy(array+index+1, array+current_size, new_array+index);
  delete[] array;
  array = new_array;
}

void
ArrayList::print() const
{
  for(int index=0; index < current_size; index++)
    {
      std::cout << "" << array[index] << ", ";
    }
  std::cout << std::endl;
}

bool
ArrayList::isEmpty() const
{
  return current_size == 0;
}
