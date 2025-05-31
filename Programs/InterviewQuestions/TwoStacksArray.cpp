#include <iostream>
using namespace std;

class twoStacks {
	int* arr;
	int size;
	int top1, top2;

public:
	// Constructor
	twoStacks(int n)
	{
		size = n;
		arr = new int[n];
		top1 = -1;       // Stack 1 starts from left
		top2 = n;        // Stack 2 starts from right
	}

	// Method to push in stack1
	void push1(int x)
	{
		if (top1 + 1 < top2) {
			top1++;
			arr[top1] = x;
		}
		else {
			cout << "Stack Overflow by element: " << x << " in Stack 1" << endl;
		}
	}

	// Method to push in stack2
	void push2(int x)
	{
		if (top2 - 1 > top1) {
			top2--;
			arr[top2] = x;
		}
		else {
			cout << "Stack Overflow by element: " << x << " in Stack 2" << endl;
		}
	}

	// Method to pop from stack1
	int pop1()
	{
		if (top1 >= 0) {
			int x = arr[top1];
			top1--;
			return x;
		}
		else {
			cout << "Stack Underflow in Stack 1" << endl;
			exit(1);
		}
	}

	// Method to pop from stack2
	int pop2()
	{
		if (top2 < size) {
			int x = arr[top2];
			top2++;
			return x;
		}
		else {
			cout << "Stack Underflow in Stack 2" << endl;
			exit(1);
		}
	}
};

// Driver Code
int main()
{
	twoStacks ts(5);

	ts.push1(1);  // Stack1: [1]
	ts.push2(2);  // Stack2: [   ,   ,   ,   ,2]
	ts.push1(3);  // Stack1: [1, 3]
	ts.push2(4);  // Stack2: [   ,   ,   ,4, 2]
	ts.push1(5);  // Stack1: [1, 3, 5]

	// Should trigger overflow now
	ts.push2(6);  // No space left between stacks

	cout << "Popped from stack1: " << ts.pop1() << endl;
	cout << "Popped from stack2: " << ts.pop2() << endl;

	return 0;
}
