
/// Default constructor
template<class T>
Vector<T>::Vector()
{
	m_capacity = 0;
	m_size = 0;
	m_buffer = NULL;
}

/// Construct Vector object with size
template<class T>
Vector<T>::Vector(unsigned int size)
{
	m_capacity = size;
	m_size = size;
	m_buffer = new T[size];
}

/// Construct Vector object with size and initial value
template<class T>
Vector<T>::Vector(unsigned int size, const T & initial)
{
	m_size = size;
	m_capacity = size;
	m_buffer = new T[size];
	for (unsigned int i = 0; i < size; i++)
		m_buffer[i] = initial;
}

/// Copy contructor
template<class T>
Vector<T>::Vector(const Vector<T> & v)
{
	m_size = v.m_size;
	m_capacity = v.m_capacity;
	m_buffer = new T[m_size];
	for (unsigned int i = 0; i < m_size; i++)
		m_buffer[i] = v.m_buffer[i];
}

/// Destructor
template<class T>
Vector<T>::~Vector()
{
	clear();
}

/// Vector assignment from another Vector obj
template<class T>
Vector<T> & Vector<T>::operator = (const Vector<T> & v)
{
	delete[] m_buffer;
	m_size = v.m_size;
	m_capacity = v.m_capacity;
	m_buffer = new T[m_size];
	for (unsigned int i = 0; i < m_size; i++)
		m_buffer[i] = v.m_buffer[i];
	return *this;
}

/// Vector capacity
template<class T>
unsigned int Vector<T>::capacity()const
{
	return m_capacity;
}

/// Vector size
template<class T>
unsigned int Vector<T>::size()const
{
	return m_size;
}

/// Check if the Vector is empty
template<class T>
bool Vector<T>::empty() const
{
	if (m_buffer == NULL)
		return true;

	return false;
}

/// Return the first element
template<class T>
T& Vector<T>::front()
{
	return m_buffer[0];
}

/// Return the last element
template<class T>
T& Vector<T>::back()
{
	return m_buffer[m_size - 1];
}

/// Push element at the end of the Vector
template<class T>
void Vector<T>::push_back(const T & v)
{
	if (m_size >= m_capacity)
	{
		if(m_capacity == 0)
			reserve(5);
		else
			reserve(m_capacity * 5);
	}
	m_buffer[m_size++] = v;
}

/// Removes the last element in the Vector
template<class T>
void Vector<T>::pop_back()
{
	m_size--;
}

/// Request a change in capacity
template<class T>
void Vector<T>::reserve(unsigned int capacity)
{
	if (m_buffer == NULL)
	{
		m_size = 0;
		m_capacity = 0;
	}
	T * Newbuffer = new T[capacity];
	unsigned int BufferSize = capacity < m_size ? capacity : m_size;

	for (unsigned int i = 0; i < BufferSize; i++)
		Newbuffer[i] = m_buffer[i];

	m_capacity = capacity;
	delete[] m_buffer;
	m_buffer = Newbuffer;
}

/// Change size
template<class T>
void Vector<T>::resize(unsigned int size)
{
	reserve(size);
	m_size = size;
}

/// Returns a reference to the element at position index 
template<class T>
T& Vector<T>::operator[](unsigned int index)
{
	return m_buffer[index];
}

/// Clear Vector informations
template <class T>
void Vector<T>::clear()
{
	m_capacity = 0;
	m_size = 0;
	if (m_buffer != NULL)
	{
		delete[] m_buffer;
		m_buffer = NULL;
	}
}