#include <iostream>
using namespace std;

int map[5][5];
int visitedMap[5][5];
int start_row, start_col, finish_row, finish_col;

#define maxStep INT_MAX

int dfs(int row, int col, int n_step, int visit[5][5], int resultStep)
{
	//Base Case
	if (row < 0 || col < 0 || row > 4 || col > 4) return resultStep;

	else if (visit[row][col]) return resultStep;

	else if (map[row][col] == 0) return resultStep;

	else if (map[row][col] == 3) return n_step;

	else if (map[row][col] != 0)
	{
		visit[row][col] = 1;

		int right = dfs(row, col + 1, n_step + 1, visit, resultStep);
		resultStep > right ? resultStep = right : resultStep;

		int left = dfs(row, col - 1, n_step + 1, visit, resultStep);
		resultStep > left ? resultStep = left : resultStep;

		int down = dfs(row + 1, col, n_step + 1, visit, resultStep);
		resultStep > down ? resultStep = down : resultStep;

		int up = dfs(row - 1, col, n_step + 1, visit, resultStep);
		resultStep > up ? resultStep = up : resultStep;

		//Area Backtrack
		visit[row][col] = 0;
	}

	return resultStep;

}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> map[i][j];
			visitedMap[i][j] = 0;

			if (map[i][j] == 2)
			{
				start_row = i;
				start_col = j;
			}

			if (map[i][j] == 3)
			{
				finish_row = i;
				finish_col = j;
			}
		}
	}

	int minimumStep = dfs(start_row, start_col, 0, visitedMap, maxStep);

	if (minimumStep == maxStep)
	{
		cout << -1;
	}
	else
	{
		cout << minimumStep;
	}

	return 0;
}