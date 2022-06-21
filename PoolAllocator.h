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
	void PushArray(Type* type, size_t count) override final;
	void GetAllElements() const;
	void ClearLastOne() override final;
	void ClearAll() override final;

	/* PoolAllocator methods */
	void TargetPushOne(size_t blockNumber, size_t cellNumber, Type data);
	void PrintVarBlocksAdress();


private:

	struct Block {
		Block() {}
		~Block() { delete[] this->Data; }
		struct Cell {
			bool Free = true;
			Type* Data;
		};
		Type* Data = nullptr;
		Block* blockPrevious = nullptr;
		Block* blockNext = nullptr;
		Block* blockThis = nullptr;
	};


	Block* Blocks;
	Block* const FirstBlock;


	size_t BlockCount;
	size_t BlockSize;


	void AllocateBlocks(Block* blocks, size_t& blockSize);
	void SearchFreeBlock(size_t& blocksize);

	bool ValidateBlockSize(size_t& blockSize) noexcept;
	bool ValidateBlockCount(size_t& blockCount) noexcept;


};