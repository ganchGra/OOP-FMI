#include"Set.h"
#include<iostream>

//TODO

///
///Resize Set
///
void Set::resize(size_t newCapacity)
{
	int * buffer = new int[newCapacity];
	copySet(buffer, m_set, m_size);
	delete[] m_set;
	m_set = buffer;
	m_capacity = newCapacity;
}

///
/// Add element
///
void Set::addElement(int x)
{
	if (isInIt(x))
	{
		return;
	}
	if (m_size==m_capacity)
	{
		resize(m_capacity ? 2 * m_capacity : 2);
	}
	m_set[m_size++] = x;
}
///
/// Remove element
///
void Set::removeElement( int x)
{
	for (size_t i = 0; i < m_size; i++)
	{
		if (m_set[i] == x)
		{
			m_set[i] = m_set[--m_size];
			return;
		}
	}
}
///
///Copy Set
///
void Set::copySet(int* result, const int* input, size_t size)
{
	for (size_t i = 0; i < size; i++)
		result[i] = input[i];
}
///
///Clean array
///
void Set::clean()
{ 
	delete[] m_set;
	this->m_set = NULL;
	this->m_size = 0;
	this->m_capacity = 0;
}
/// Allocates a new int and copies the contents of value
///
void Set::copy(Set const& other)
{
	this->m_set = new (std::nothrow) int[this->m_capacity];
	if (this->m_set == NULL)
	{
		std::cout << "NO MEMORY\n";
		return;
	}
	this->m_size = other.m_size;
	
	for (size_t i = 0; i < this->m_size; i++)
		m_set[i] = other.m_set[i];
}
///
/// Default constructor: Initializes an empty Student object
///
Set::Set()
{
	m_set = NULL;
	m_size = 0;
	m_capacity = 0;
}
///
/// Free the resources used by a Student object
///
Set::~Set()
{
	delete[] m_set;
}
///
/// Copy constructor
///
Set::Set(Set const& n)
{
	clean();
	copy(n);
}
///
/// Assignment operator
///
Set& Set::operator=(Set const& other)
{
	if (this != &other)
		copy(other);

	return *this;
}

///
///Is in the Set
///
bool Set::isInIt(int element) const
{
	for (size_t i = 0; i < this->m_size; i++)
	{
		if (this->m_set[i] == element)
		{
			return true;
		}
	}
	return false;
}

///
///Get size
///
size_t Set::size() const {
	return this->m_size;
}

///
///Is subset
///
bool Set::isSubset(const Set& other) const
{
	for (size_t j = 0; j < other.m_size; j++)
	{
		if (!isInIt(other.m_set[j]))
			return false;
	}

	return true;
}

///
///Is super set
///
bool Set::isSuperset(const Set& x) const
{
	return x.isSubset(*this);
}

///
///Are same
///
bool Set::areSame(const Set& rhs) const
{
	bool is_Subset = isSubset(rhs);
	if (!is_Subset)
	{
		return false;
	}
	is_Subset = rhs.isSubset(*this);
	return is_Subset;
}

///
///Print element
///
void Set::print() const
{
	for (size_t i = 0; i < this->m_size; i++)
	{
		std::cout << this->m_set[i] << " ";
	}
}