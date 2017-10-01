#include <iostream>
#include <cstring>
using namespace std;
struct Node
{
	int layer;
	int data;
	int threshold;
};
int main()
{
	int n; int p; cin >> n >> p;
	Node *node = new Node[n];
	for (int i = 0; i < n; i++)
	{
		cin >> node[i].data >> node[i].threshold;
		if (node[i].data > 0) node[i].layer = 1;
		else node[i].layer = 0;
	}
	int *adj = new int[n*n];
	memset(adj, 0, sizeof(int)*n*n);
	int node1, node2;
	for (int i = 0; i < p; i++)
	{
		cin >> node1 >> node2;
		cin >> adj[(node1 - 1)*n + node2 - 1];
	}
	int layer = 1;
	bool stop = false;
	while (!stop)
	{
		stop = true;
		for (int i = 0; i < n; i++)
		{
			if (node[i].layer == layer)
			{
				if (node[i].data > node[i].threshold)
				{
					for (int j = 0; j < n; j++)
					{
						if (adj[i*n + j] != 0)
						{
							node[j].data += (node[i].data - node[i].threshold)*adj[i*n + j];
							node[j].layer = layer + 1;
							stop = false;
						}
					}
				}
				else
				{
					for (int j = 0; j < n; j++)
					{
						if (adj[i*n + j] != 0)
						{
							node[j].layer = layer + 1;
							stop = false;
						}
					}
				}
			}
		}
		layer++;
	}
	bool ifNull = true;
	for (int i = 0; i < n; i++)
	{
		if (node[i].layer == layer - 1 && node[i].data - node[i].threshold > 0)
		{
			cout << i + 1 << " " << node[i].data - node[i].threshold << endl;
			ifNull = false;
		}
	}
	if (ifNull)
	{
		cout << "NULL" << endl;
	}
	delete[] node;
	delete[] adj;
	return 0;
}