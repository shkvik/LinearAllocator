#include "main.h"

using namespace std;

class ForTest {
public:
	ForTest() = default;
	ForTest(uint64_t number) : Number(number) {
		std::cout << "Call Constructor: " << Number << " \n";
	}
	~ForTest() {
		std::cout << "Call Destructor: " << Number << " \n";
	}
	uint64_t Number = 0;
};

int main() {

	LinearAllocator<ForTest> tested(5);

	PoolAllocator<int> e(4, 5);
	
	e.GetAllElements();
	e.TargetPushOne(0, 0, 51);
	e.TargetPushOne(1, 1, 52);
	e.TargetPushOne(2, 2, 53);
	e.TargetPushOne(3, 3, 54);
	e.TargetPushOne(5, 6, 54);
	e.GetAllElements();

	e.PrintVarBlocksAdress();

	void* pointer = new void* [5];

	LinearAllocator<int> allocatorInt(8);


	cout << "Not Add \n";
	allocatorInt.GetAllElements();
	


	allocatorInt.PushOne(1);
	allocatorInt.PushOne(2);
	allocatorInt.PushOne(3);
	allocatorInt.PushOne(4);
	allocatorInt.PushOne(5);

	int * a = new int[3] {1, 2, 5};

	allocatorInt.PushArray(a, 3);

	cout << "After Add \n";
	allocatorInt.GetAllElements();
	

	cout << "After Clear Last \n";
	allocatorInt.ClearLastOne();
	allocatorInt.GetAllElements();



	auto j = allocatorInt.ReturnUsedElement();
	cout << "Last Elem: " << *(j) << " \n";
	allocatorInt.GetAllElements();

	allocatorInt.ClearAll();

	cout << "After Clear All \n";
	allocatorInt.GetAllElements();

	LinearAllocator<char> allocatorChar(5);
	allocatorChar.PushOne('a');
	allocatorChar.PushOne('b');
	allocatorChar.PushOne('c');
	allocatorChar.PushOne('d');
	allocatorChar.PushOne('e');
	auto k = allocatorChar.ReturnUsedElement();
	cout << *(k) << " \n";
	allocatorChar.GetAllElements();

}