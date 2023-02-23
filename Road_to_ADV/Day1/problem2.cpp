#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permute(int index, vector<int> arr, int n)
{
	if (index == n - 1)
	{
		for (int k = 0; k < n; ++k)
		{
			printf("%d ", arr[k]);
		}

		printf("\n");
		return;
	}

	for (int i = index; i < n; i++)
	{
		swap(arr[index], arr[i]);
		permute(index + 1, arr, n);
		swap(arr[i], arr[index]);
	}

	return;
}

int main()
{
	vector<int> arr;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		arr.push_back(i + 1);
	}

	permute(0, arr, n);
	return 0;
}