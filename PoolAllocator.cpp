#include "PoolAllocator.h"
#include <exception>



template<typename Type>
PoolAllocator<Type>::PoolAllocator(size_t blockSize, size_t blockCount) noexcept : 
BlockSize(blockSize), BlockCount(blockCount), Blocks(new Block[blockCount]), FirstBlock(Blocks)
{
	PoolAllocator<Type>::AllocateBlocks(this->Blocks, blockSize);
	static_assert(!std::is_same<Type, void*>::value, "Type can't be a void*");
}

template<typename Type>
void PoolAllocator<Type>::PushOne(Type type){

}
 
template<typename Type>
void PoolAllocator<Type>::PushArray(Type* type) {}



template<typename Type>
void PoolAllocator<Type>::ShowAllElements() const{
	Block* blocksCopy = PoolAllocator<Type>::Blocks;
	std::cout << "Blocks count: " << BlockCount << " Block size: " << BlockSize << " \n";
	for (int i = 0; i < BlockCount; i++) {
		std::cout << "Block #" << i << " Adress:" << blocksCopy << " \n";
		for (int i = 0; i < BlockSize; i++) {
			std::cout << "\tCell #" << i << ":  value: " << blocksCopy->Data[i] << " \n";
		} blocksCopy++;
	}
}


template<typename Type>
void PoolAllocator<Type>::ClearLastOne() {}


template<typename Type>
void PoolAllocator<Type>::ClearAll() {}

template<typename Type>
PoolAllocator<Type>::~PoolAllocator() {
	delete [] this->Blocks
}



template<typename Type>
void PoolAllocator<Type>::AllocateBlocks(Block* blocks, size_t& blockSize){
	for (int i = 0; i < BlockCount; i++) { blocks->Data = new Type[blockSize]; blocks++; }
}


template<typename Type>
void PoolAllocator<Type>::TargetPushOne(size_t blockNumber, size_t cellNumber, Type data) {
	if (PoolAllocator<Type>::ValidateBlockSize(cellNumber) && PoolAllocator<Type>::ValidateBlockCount(blockNumber)) {
		Block* copyFirstBlock = this->FirstBlock + blockNumber; copyFirstBlock->Data[cellNumber] = data;
	}
}


template<typename Type>
void PoolAllocator<Type>::PrintVarBlocksAdress() {
	std::cout << this->Blocks << " \n";
}

template<typename Type>
bool PoolAllocator<Type>::ValidateBlockSize(size_t& blockSize) noexcept {
	try { if (blockSize > BlockSize) throw std::overflow_error("Your value bigger than block size");}
	catch (std::overflow_error error) { std::cout << error.what() << " \n"; return false; }
	return true;
}

template<typename Type>
bool PoolAllocator<Type>::ValidateBlockCount(size_t& blockCount) noexcept {
	try { if (blockCount > BlockCount) throw std::overflow_error("Your value bigger than block count");}
	catch (std::overflow_error error) { std::cout << error.what() << " \n"; return false; }
	return true;
}

