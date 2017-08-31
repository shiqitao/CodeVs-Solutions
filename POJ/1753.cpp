#include <iostream>
#include <queue>
using namespace std;
short flip[16] = {
	0xC800, 0xE400, 0x7200, 0x3100,
	0x8C80, 0x4E40, 0x2720, 0x1310,
	0x08C8, 0x04E4, 0x0272, 0x0131,
	0x008C, 0x004E, 0x0027, 0x0013 };
struct Node
{
	unsigned short data;
	int numFlip;
};
int main()
{
	unsigned short data = 0;
	char ch;
	for (int i = 0; i < 16; i++)
	{
		cin >> ch;
		if (ch == 'b') data = (data << 1) + 1;
		else data = data << 1;
	}
	if (data == 0 || data == 0xFFFF)
	{
		cout << 0 << endl;
		return 0;
	}
	Node node = { data, 0 };
	queue<Node> BFS;
	BFS.push(node);
	bool visit[65536];
	memset(visit, false, sizeof(bool)* 65536);
	while (!BFS.empty())
	{
		node = BFS.front();
		BFS.pop();
		for (int i = 0; i < 16; i++)
		{
			Node temp = { node.data^flip[i], node.numFlip + 1 };
			if (!visit[temp.data])
			{
				if (temp.data == 0 || temp.data == 0xFFFF)
				{
					cout << temp.numFlip << endl;
					return 0;
				}
				visit[temp.data] = true;
				BFS.push(temp);
			}
		}
	}
	cout << "Impossible" << endl;
	return 0;
}