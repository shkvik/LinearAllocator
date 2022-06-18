#include "LinearAllocator.h"
#include <iostream>

template<typename Type>

LinearAllocator<Type>::LinearAllocator(int count) noexcept : Count(count), Area(new Type[count]{ 0 }), Used(Area) {
	static_assert(!std::is_same<Type, void*>::value, "Type can't be a void*");
}


template<typename Type>
void LinearAllocator<Type>::PushOne(Type type) {
	if (AllocateCount < this->Count) {
		this->Area[AllocateCount] = type;
		this->AllocateCount++;
		if (AllocateCount != this->Count) this->Used = this->Used + 1;
	}
	else {
		throw std::runtime_error("I haven't place more");
	}
}


template<typename Type>
void LinearAllocator<Type>::ShowAllElements() {
	int countBuffer = this->Count;
	while (countBuffer--) {
		std::cout << Area[countBuffer] << " \n";
	}
}


template<typename Type>
void LinearAllocator<Type>::PushArray(Type* type) {

	auto elementsCount = CountType(type);

	if (elementsCount <= (this->Count - this->AllocateCount)) {
		for (int i = 0; i < elementsCount; i++) {
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
	this->Area[AllocateCount - 1] = 0;
	this->Used = this->Used - 1;
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
size_t LinearAllocator<Type>::CountType(const Type* type) {
	size_t result = 0;
	while (*(type)++) {
		result++;
	}
	return result - 1;
}

