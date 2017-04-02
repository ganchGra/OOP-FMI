#ifndef _SET_HEADER_
#define _SET_HEADER_

class Set
{
public:
	Set();
	Set(const Set&);
	Set& operator=(const Set&);
	~Set();

public:
	Set getUnion(const Set&) const;
	Set getIntersection(const Set&) const;
	Set getDifference(const Set&) const;
	Set getSymmetricDifference(const Set&) const;
	bool isSubset(const Set&) const;
	bool isSuperset(const Set&) const;
	bool areSame(const Set&) const;
public:
	void print() const;
	size_t size() const;
	void addElement(int);
	void removeElement(int);


private:
	bool isInIt(int) const;
	void copy(const Set&);
	void resize(size_t);
	void clean();              //TODO
	void copySet(int*,const int*, size_t);

private:
	int* m_set;
	size_t m_size;
	size_t m_capacity;
};

#endif	// _SET_HEADER_