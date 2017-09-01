#include <iostream>
#include <cstring>
using namespace std;
short change[16] = {
	0xF888, 0xF444, 0xF222, 0xF111,
	0x8F88, 0x4F44, 0x2F22, 0x1F11,
	0x88F8, 0x44F4, 0x22F2, 0x11F1,
	0x888F, 0x444F, 0x222F, 0x111F };
struct VisitNode
{
	bool ifVisit;
	short numSwitch;
	unsigned short ancestor;
	short ancestorX;
	short ancestorY;
};
int main()
{
	unsigned short data = 0;
	char ch;
	for (int i = 0; i < 16; i++)
	{
		cin >> ch;
		if (ch == '+') data = (data << 1) + 1;
		else data = data << 1;
	}
	if (data == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	VisitNode visit[65536];
	memset(visit, 0, sizeof(visit));
	visit[data].ifVisit = true;
	visit[data].numSwitch = 0;
	visit[data].ancestor = 0;
	visit[data].ancestorX = -1;
	visit[data].ancestorY = -1;
	unsigned short queue[65536];
	memset(queue, 0, sizeof(queue));
	queue[0] = data;
	int pointer = 0;
	int tempPointer = 0;
	unsigned short temp;
	while (true)
	{
		data = queue[pointer];
		for (int i = 0; i < 16; i++)
		{
			temp = data^change[i];
			if (!visit[temp].ifVisit)
			{
				visit[temp].ifVisit = true;
				visit[temp].numSwitch = visit[data].numSwitch + 1;
				visit[temp].ancestor = data;
				visit[temp].ancestorX = i / 4;
				visit[temp].ancestorY = i % 4;
				if (temp == 0)
				{
					cout << visit[temp].numSwitch << endl;
					short *resultX = new short[visit[temp].numSwitch];
					short *resultY = new short[visit[temp].numSwitch];
					for (int i = visit[data].numSwitch; i >= 0; i--)
					{
						resultX[i] = visit[temp].ancestorX;
						resultY[i] = visit[temp].ancestorY;
						temp = visit[temp].ancestor;
					}
					for (int i = 0; i <= visit[data].numSwitch; i++)
						cout << resultX[i] + 1 << " " << resultY[i] + 1 << endl;
					delete[] resultX;
					delete[] resultY;
					return 0;
				}
				queue[++tempPointer] = temp;
			}
		}
		pointer++;
	}
}