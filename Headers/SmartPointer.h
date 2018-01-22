#ifndef SMART_POINTER_H
#define SMART_POINTER_H

using namespace std;

template <class T>
class SmartPointer
{

	friend ostream& operator<<(ostream &os, const SmartPointer<T> &obj)
	{
		os << *(obj.SmartPointer<T>::getVal());
		return os;
	}
	
	private:
		T *val;

	public:
		SmartPointer();
		SmartPointer(T *);
		SmartPointer(const SmartPointer &);
	
		void setVal(T *);
		T* getVal() const;
	
		void Delete();
	
		SmartPointer<T> operator=(const SmartPointer<T> &);
		SmartPointer<T> operator=(T *);
		
		T& operator*() const;
		T* operator->() const;
		
		int operator>(const SmartPointer<T> &) const;
		int operator<(const SmartPointer<T> &) const;
		int operator==(const SmartPointer<T> &) const;
	
	
		~SmartPointer();
};

#endif

