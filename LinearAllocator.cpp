#pragma once
#include "LinearAllocator.h"
#include <iostream>
#include <vector>
#include <string> 

template<typename Type>

LinearAllocator<Type>::LinearAllocator(int count) noexcept : Count(count), Area(new Type[count]{ 0 }), Used(Area) {
	static_assert(!std::is_same<Type, void*>::value, "Type can't be a void*");
}


template<typename Type>
void LinearAllocator<Type>::PushOne(Type type) {
	if (AllocateCount < this->Count) { Area[AllocateCount] = type; AllocateCount++;
		if (AllocateCount != this->Count) this->Used = this->Used + 1;	}
	else { throw std::runtime_error("I haven't place more");}
}


template<typename Type>
void LinearAllocator<Type>::GetAllElements() const{

	bool validate = ValidatePrintableType(*(Area));

	int countBuffer = this->Count;

}


template<typename Type>
void LinearAllocator<Type>::PushArray(Type* type, size_t count) {

	if (count <= (this->Count - this->AllocateCount)) {
		for (int i = 0; i < count; i++) {
			this->Area[AllocateCount] = *(type); type++; AllocateCount++;
			if (AllocateCount != this->Count) this->Used += 1;
		}
	}
}


template<typename Type>
Type * LinearAllocator<Type>::ReturnUsedElement() {
	return this->Used;
}


template<typename Type>
void LinearAllocator<Type>::ClearLastOne() {
	Area[AllocateCount - 1] = NULL;
	Used = Used - 1;
	AllocateCount--;
}


template<typename Type>
void LinearAllocator<Type>::ClearAll() {
	for (int i = AllocateCount; i > -1; i--) {
		this->Area[i] = 0;
		AllocateCount--;
	}
}


template<typename Type>
LinearAllocator<Type>::~LinearAllocator() {
	delete[] this->Area;
}


template<typename Type>
bool LinearAllocator<Type>::ValidatePrintableType(Type type) const {
	
	int controllVal = 0;

	std::vector<bool> flags{
		typeid(type) == typeid(int),
		typeid(type) == typeid(char),
		typeid(type) == typeid(const char),
		typeid(type) == typeid(std::string),
	};

	for (auto item : flags) { controllVal += (int)item; }

	return controllVal > 0 ? true : false;

}
