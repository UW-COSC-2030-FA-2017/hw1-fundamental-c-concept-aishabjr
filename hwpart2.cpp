#include <iostream>
using namespace std;

void recursiveFunction(int time)
{
	cout << "Step 3: Water is not boiled yet, increase gas" << endl;
	cout << "Step 4: Wait for 5 more minutes " << endl;
	time++;
	if (time < 5)
	{
		recursiveFunction(time);
	}
}


int main()
{
	int time = 0;
	cout << "Steps to cook Pasta" << endl;
	cout << "Step 1: Put water on Fire" << endl;
	cout << "Step 2: Wait for 5 mins" << endl;
	recursiveFunction(time);
	cout << "Step 5: Water is boiled now, Add Pasta now" << endl;

	return 0;
}