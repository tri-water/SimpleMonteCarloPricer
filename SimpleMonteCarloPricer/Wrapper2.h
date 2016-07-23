#pragma once
#include <memory>

template< class T>
class Wrapper
{
public:
	Wrapper():
	{
		DataPtr(nullptr);
	}

	Wrapper(const T& inner)
	{
		DataPtr = inner.clone();
	}

	Wrapper(const Wrapper<T>& original)
	{
		if (original.DataPtr != nullptr) {
			DataPtr = original.DataPtr->clone();
		}
		else {
			DataPtr = 0;
		}
	}
	
	T& operator=(const Wrapper<T>& original)
	{
		if (this != original) {
			T* newPtr = original->DataPtr != 0 ? original.DataPtr->clone() : 0;
			if (DataPtr != 0) {
				delete DataPtr;
			}
			DataPtr = newPtr;
		}
		
		
		return *this;
	}

	T& operator* ()
	{
		return *DataPtr;
	}

	const T& operator*() const
	{
		return *DataPtr;
	}

	const std::shared_ptr<T> operator->() const
	{
		return DataPtr;
	}

	std::shared_ptr<T> operator->()
	{
		return DataPtr;
	}

private:
	std::shared_ptr<T> DataPtr;
};