#include <iostream>
#include <vector>

using namespace std;

// n = total number of object in the set
// r = number of choosing objects from the set

int n, r;

vector <int> arr;

void findCombination(vector <int> arr, vector <int> data, int start, int end, int index, int c);

void printCombination(vector <int> arr, int n, int r)
{
	// A temporary array to store
	// all combination one by one
	// int data[r];
	vector <int> data(r);

	// Print all combination using
	// temporary array 'data[]'
	findCombination(arr, data, 0, n - 1, 0, r);
}

void findCombination(vector <int> arr, vector <int> data, int start, int end, int index, int r)
{
	// Current combination is ready
	// to be printed, print it
	if (index == r)
	{
		for (int j = 0; j < r; j++)
			cout << data[j] << " ";
		cout << endl;
		return;
	}

	for (int i = start; i <= end && end - i + 1 >= r - index; i++)
	{
		data[index] = arr[i];
		findCombination(arr, data, i + 1,
			end, index + 1, r);
	}
}

// Driver code
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		arr.push_back(i + 1);
	}

	cin >> r;

	// int arr[] = { 1, 2, 3, 4, 5 };
	// int r = 3;
	// int n = sizeof(arr) / sizeof(arr[0]);
	printCombination(arr, n, r);
}
