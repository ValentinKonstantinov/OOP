#include <fstream>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <string>

	using namespace std;

// Проверяет, находится ли позиция (row, col) в границах лабиринта
bool is_valid(const vector<string>& maze, int row, int col)
{
	if (row < 0 || row >= maze.size())
		return false;
	if (col < 0 || col >= maze[row].size())
		return false;
	return true;
}

int main(int argc, char* argv[])
{
	vector<string> maze;
	bool file_mode = (argc == 3); // Режим работы с файлами

	// Проверка количества аргументов
	if (argc != 1 && argc != 3)
	{
		cout << "ERROR" << endl;
		return 1;
	}

	// Чтение лабиринта
	if (file_mode)
	{
		ifstream fin(argv[1]);
		if (!fin.is_open())
		{
			cout << "ERROR" << endl;
			return 1;
		}
		string line;
		while (getline(fin, line))
		{
			if (line.size() > 100)
			{
				cout << "ERROR" << endl;
				return 1;
			}
			maze.push_back(line);
		}
		fin.close();
		if (maze.size() > 100)
		{
			cout << "ERROR" << endl;
			return 1;
		}
	}
	else
	{
		string line;
		while (getline(cin, line))
		{
			if (line.size() > 100)
			{
				cout << "ERROR" << endl;
				return 0;
			}
			maze.push_back(line);
		}
		if (maze.size() > 100)
		{
			cout << "ERROR" << endl;
			return 0;
		}
	}

	// Проверка символов и подсчет A, B
	int count_A = 0, count_B = 0;
	pair<int, int> A_pos, B_pos;
	bool error = false;
	for (int i = 0; i < maze.size(); ++i)
	{
		for (int j = 0; j < maze[i].size(); ++j)
		{
			char c = maze[i][j];
			if (c == 'A')
			{
				count_A++;
				A_pos = { i, j };
			}
			else if (c == 'B')
			{
				count_B++;
				B_pos = { i, j };
			}
			else if (c != '#' && c != ' ')
			{
				error = true;
			}
		}
	}

	// Обработка ошибок ввода
	if (count_A != 1 || count_B != 1 || error)
	{
		cout << "ERROR" << endl;
		return file_mode ? 1 : 0;
	}

	// Инициализация матрицы расстояний
	vector<vector<int>> distance(maze.size());
	for (int i = 0; i < maze.size(); ++i)
		distance[i].resize(maze[i].size(), -1);

	queue<pair<int, int>> q;
	q.push(A_pos);
	distance[A_pos.first][A_pos.second] = 0;

	// Направления: север, юг, запад, восток
	vector<pair<int, int>> directions = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	bool found_B = false;

	// Поиск пути BFS
	while (!q.empty() && !found_B)
	{
		auto current = q.front();
		q.pop();

		for (auto dir : directions)
		{
			int new_row = current.first + dir.first;
			int new_col = current.second + dir.second;

			if (is_valid(maze, new_row, new_col))
			{
				char c = maze[new_row][new_col];
				if (c == 'B')
				{
					distance[new_row][new_col] = distance[current.first][current.second] + 1;
					found_B = true;
					break;
				}
				else if (c == ' ' && distance[new_row][new_col] == -1)
				{
					distance[new_row][new_col] = distance[current.first][current.second] + 1;
					q.push({ new_row, new_col });
				}
			}
		}
		if (found_B)
			break;
	}

	// Восстановление пути
	if (found_B)
	{
		pair<int, int> current = B_pos;
		while (current != A_pos)
		{
			bool found_step = false;
			for (auto dir : directions)
			{
				int new_row = current.first + dir.first;
				int new_col = current.second + dir.second;

				if (is_valid(maze, new_row, new_col))
				{
					if (distance[new_row][new_col] == distance[current.first][current.second] - 1)
					{
						// Помечаем путь, кроме A и B
						if (maze[new_row][new_col] == ' ')
							maze[new_row][new_col] = '.';
						current = { new_row, new_col };
						found_step = true;
						break;
					}
				}
			}
			if (!found_step)
				break;
		}
	}

	// Вывод результата
	if (file_mode)
	{
		ofstream fout(argv[2]);
		if (!fout.is_open())
		{
			cout << "ERROR" << endl;
			return 1;
		}
		for (const string& line : maze)
			fout << line << endl;
		fout.close();
	}
	else
	{
		for (const string& line : maze)
			cout << line << endl;
	}

	return 0;
}
