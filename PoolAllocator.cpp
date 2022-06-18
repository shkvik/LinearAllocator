#include "PoolAllocator.h"




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
PoolAllocator<Type>::~PoolAllocator() {}



template<typename Type>
void PoolAllocator<Type>::AllocateBlocks(Block* blocks, size_t& blockSize){
	for (int i = 0; i < BlockCount; i++) { blocks->Data = new Type[blockSize]; blocks++; }
}


template<typename Type>
void PoolAllocator<Type>::TargetPushOne(size_t blockNumber, size_t cellNumber, Type data) {
	Block* copyFirstBlock = this->FirstBlock + blockNumber;
	copyFirstBlock->Data[cellNumber] = data;
}


template<typename Type>
void PoolAllocator<Type>::PrintBlocksAdress() {
	std::cout << this->Blocks << " \n";
}