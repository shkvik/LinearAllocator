#pragma once

template<typename Type>
class IAllocator {
public:
	virtual void PushOne(Type type) = 0;
	virtual void PushArray(Type * type) = 0;
	virtual void ShowAllElements() = 0;
	virtual void ClearLastOne() = 0;
	virtual void ClearAll() = 0;
};



