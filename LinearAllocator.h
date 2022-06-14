#pragma once

#include "IAllocator.h"


template<typename Type>
class LinearAllocator : public IAllocator<Type> {

public:

	explicit LinearAllocator(int count) noexcept;

	void PushOne(Type type) override final;

	void PushArray(Type* type) override final;

	void ClearLastOne() override final;

	void ClearAll() override final;

	void ShowAllElements() override final;

	Type * ReturnUsedElement();

	~LinearAllocator();

private:

	int Count;

	int AllocateCount = 0;

	Type* Area;

	Type* Start = nullptr;

	Type* End = nullptr;

	Type* Used = nullptr;

	size_t CountType(const Type* type);

};

