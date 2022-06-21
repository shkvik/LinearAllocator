#include "main.h"

using namespace std;

class ForTest {
public:

	
	ForTest()  {
		Number++;
		hisNumber = Number;
		std::cout << "Call Constructor" << hisNumber << " \n";
		this->Array = new int[10]{0};

		for (int i = 0; i < 9; i++) {
			Array[i] = i;
		}
	}

	ForTest(int check) : hisNumber(check) {
		std::cout << "Call Constructor" << hisNumber << " \n";
	}
	~ForTest() {
		delete[] Array;
		std::cout << "Call Destructor: " << hisNumber << " \n";
	}

	void ShowMyElem() {
		for (int i = 0; i < 9; i++) {
			cout << Array[i] << " \n";
		}
	}

	int* Array = nullptr;
	int Changeable;
	int hisNumber = 0;

	static uint64_t Number;
};

uint64_t ForTest::Number = 0;

int main() {

	PoolAllocator<int> e(4, 5);
	
	

	e.GetAllElements();
	e.TargetPushOne(0, 0, 51);
	e.TargetPushOne(1, 1, 52);
	e.TargetPushOne(2, 2, 53);
	e.TargetPushOne(3, 3, 54);
	e.TargetPushOne(5, 6, 54);
	e.GetAllElements();

	e.PrintVarBlocksAdress();

	LinearAllocator<ForTest> tested(5);

	tested.PushOne(ForTest(6));

	tested.PushOne(ForTest(7));

	tested.PushOne(ForTest(8));

	tested.PushOne(ForTest(9));


	for (int i = 0; i < 5; i++) {
		cout << (tested.ReturnStartElement() + i)->Changeable << " \n";
	}
	

	tested.ShowAllElements();
	tested.ClearLastOne();


	LinearAllocator<int> allocatorInt(8);


	cout << "Not Add \n";
	allocatorInt.ShowAllElements();
	


	allocatorInt.PushOne(1);
	allocatorInt.PushOne(2);
	allocatorInt.PushOne(3);
	allocatorInt.PushOne(4);
	allocatorInt.PushOne(5);

	int * a = new int[3] {1, 2, 5};

	allocatorInt.PushArray(a, 3);

	cout << "After Add \n";
	allocatorInt.ShowAllElements();
	

	cout << "After Clear Last \n";
	allocatorInt.ClearLastOne();
	allocatorInt.ShowAllElements();



	auto j = allocatorInt.ReturnUsedElement();
	cout << "Last Elem: " << *(j) << " \n";
	allocatorInt.ShowAllElements();

	allocatorInt.ClearAll();

	cout << "After Clear All \n";
	allocatorInt.ShowAllElements();

	LinearAllocator<char> allocatorChar(5);
	allocatorChar.PushOne('a');
	allocatorChar.PushOne('b');
	allocatorChar.PushOne('c');
	allocatorChar.PushOne('d');
	allocatorChar.PushOne('e');
	auto k = allocatorChar.ReturnUsedElement();
	cout << *(k) << " \n";
	allocatorChar.ShowAllElements();

}