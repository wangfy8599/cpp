#include <iostream>
#include <vector>

using namespace std;

struct TestStruct
{
	int n;

	TestStruct()
	{
	}

	TestStruct(TestStruct &&other)
	{
		cout << "move construct called" << endl;
	}
};

int main()
{
	TestStruct testStruct;
	vector<TestStruct> list;
	list.reserve(2);
	cout << &testStruct << endl;
	testStruct.n = 1;
	list.emplace_back(testStruct);
	testStruct.n = 2;
	TestStruct testStruct2;
	testStruct2.n = 3;
	list.emplace_back(testStruct2);

	cout << &list.at(0) << ":" << list.at(0).n << endl;
	cout << &list.at(1) << ":" << list.at(1).n << endl;
    return 0;
}