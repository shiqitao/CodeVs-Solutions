#include <iostream>
#include <cstring>
using namespace std;
int index1 = 0, index2 = 0;
bool *data;
bool *ifSearch;
int main()
{
	int R, C; cin >> R >> C;
	data = new bool[R*C];
	ifSearch = new bool[R*C];
	memset(ifSearch, false, sizeof(bool)*R*C);
	char ch;
	for (int i = 0; i < R*C; i++)
	{
		cin >> ch;
		if (ch == '#') data[i] = true;
		else data[i] = false;
	}
	int num = 0;
	for (index1 = 0; index1 < R; index1++)
	{
		for (index2 = 0; index2 < C; index2++)
		{
			if (!ifSearch[index1*C + index2])
			{
				if (data[index1*C + index2])
				{
					ifSearch[index1*C + index2] = true;
					int edge1 = index1, edge2 = index2;
					while (edge1 != R - 1 && data[(edge1 + 1)*C + index2])
					{
						ifSearch[(edge1 + 1)*C + index2] = true;
						edge1++;
					}
					while (edge2 != C - 1 && data[index1*C + edge2 + 1])
					{
						ifSearch[index1*C + edge2 + 1] = true;
						edge2++;
					}
					for (int i = index1 + 1; i <= edge1; i++)
					{
						for (int j = index2 + 1; j <= edge2; j++)
						{
							if (!data[i*C + j])
							{
								cout << "Bad placement." << endl;
								delete[] data;
								delete[] ifSearch;
								return 0;
							}
							ifSearch[i*C + j] = true;
						}
					}
					if (index2 != 0)
					{
						for (int i = index1 + 1; i <= edge1; i++)
						{
							if (data[i*C + index2 - 1])
							{
								cout << "Bad placement." << endl;
								delete[] data;
								delete[] ifSearch;
								return 0;
							}
							ifSearch[i*C + index2 - 1] = true;
						}
					}
					if (edge1 != R - 1)
					{
						for (int i = index2; i <= edge2; i++)
						{
							if (data[(edge1 + 1)*C + i])
							{
								cout << "Bad placement." << endl;
								delete[] data;
								delete[] ifSearch;
								return 0;
							}
							ifSearch[(edge1 + 1)*C + i] = true;
						}
					}
					if (edge2 != C - 1)
					{
						for (int i = index1; i <= edge1; i++)
						{
							if (data[i*C + edge2 + 1])
							{
								cout << "Bad placement." << endl;
								delete[] data;
								delete[] ifSearch;
								return 0;
							}
							ifSearch[i*C + edge2 + 1] = true;
						}
					}
					index2 = edge2;
					num++;
				}
				else ifSearch[index1*C + index2] = true;
			}
		}
	}
	cout << "There are " << num << " ships." << endl;
	delete[] data;
	delete[] ifSearch;
	return 0;
}