/// Class Vector description
/**
* Vector is template class
*/

#pragma once

template <class T>
class  Vector
{
public:
	/// Default constructor
	Vector();

	/// Construct Vector object with size
	Vector(unsigned int size);

	/// Construct Vector object with size and initial value
	Vector(unsigned int size, const T & initial);

	/// Copy contructor
	Vector(const Vector<T> & v);

	/// Destructor
	~Vector();

	/// Vector assignment from another Vector obj
	Vector<T> & operator=(const Vector<T> &);

public:
	/// Vector capacity
	unsigned int capacity() const;

	/// Vector size
	unsigned int size() const;

	/// Check if the Vector is empty
	bool empty() const;

	/// Return the first element
	T & front();

	/// Return the last element
	T & back();

	/// Push element at the end of the Vector
	void push_back(const T & value);

	/// Removes the last element in the Vector
	void pop_back();

	/// Request a change in capacity
	void reserve(unsigned int capacity);

	/// Change size
	void resize(unsigned int size);

	/// Returns a reference to the element at position index 
	T & operator[](unsigned int index);

	/// Clear Vector informations
	void clear();

private:
	/// Buffer size
	unsigned m_size;

	/// Buffer capacity 
	unsigned m_capacity;

	/// Buffer with different value <T>
	T * m_buffer;
};

#include"Vector.hpp"