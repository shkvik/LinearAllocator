#pragma once

#include "IAllocator.h"


template<typename Type>
class LinearAllocator : public IAllocator<Type> {

public:

	explicit LinearAllocator(int count) noexcept;
	void PushOne(Type type) override final;
	void PushArray(Type* type, size_t count) override final;
	void ClearLastOne() override final;
	void ClearAll() override final;
	void GetAllElements() const override final;

	Type * ReturnUsedElement();


	~LinearAllocator();

private:

	int Count;
	int AllocateCount = 0;

	Type* Area = nullptr;
	Type* Start = nullptr;
	Type* End = nullptr;
	Type* Used = nullptr;
	
	bool ValidatePrintableType(Type type) const;
};

