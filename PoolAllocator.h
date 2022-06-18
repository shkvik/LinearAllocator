#pragma once
#include "IAllocator.h"
#include <iostream>

template<typename Type>
class PoolAllocator : public IAllocator<Type>
{
public:

	explicit PoolAllocator(size_t blockSize, size_t blockCount) noexcept;
	~PoolAllocator();

	/* IAllocator Interface Access */
	void PushOne(Type type) override final;
	void PushArray(Type* type) override final;
	void ShowAllElements() const override final;
	void ClearLastOne() override final;
	void ClearAll() override final;

	/* PoolAllocator methods */
	void TargetPushOne(size_t blockNumber, size_t cellNumber, Type data);
	void PrintBlocksAdress();


private:

	struct Block {
		Block() {}
		~Block() {}
		Type* Data;
		Block* blockPrevious;
		Block* blockNext;
		Block* blockThis;
	};


	Block* Blocks;
	Block* const FirstBlock;


	size_t BlockCount;
	size_t BlockSize;


	void AllocateBlocks(Block* blocks, size_t& blockSize);

	bool ValidateBlockSize(size_t& blockSize);
	bool ValidateBlockCount(size_t& blockCount);



};