#include "main.h"

using namespace std;




int main() {

	LinearAllocator<int> allocatorInt(8);

	cout << "Not Add \n";
	allocatorInt.ShowAllElements();
	


	allocatorInt.PushOne(1);
	allocatorInt.PushOne(2);
	allocatorInt.PushOne(3);
	allocatorInt.PushOne(4);
	allocatorInt.PushOne(5);

	int * a = new int[3] {1, 2, 5};

	allocatorInt.PushArray(a);

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