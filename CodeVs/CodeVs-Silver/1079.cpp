#include <iostream>
#include <cstring>
#include <map>
#include <limits.h>
using namespace std;
void Dijkstra(int adj[], int v0, int num, int dist[]);
int main()
{
	int n; cin >> n;
	char *start = new char[n];
	char *end = new char[n];
	int *length = new int[n];
	map<char, int> data;
	data.insert(pair<char, int>('Z', 0));
	int num = 1;
	map<char, int>::iterator iter;
	for (int i = 0; i < n; i++)
	{
		cin >> start[i] >> end[i] >> length[i];
		iter = data.find(start[i]);
		if (iter == data.end())
		{
			data.insert(pair<char, int>(start[i], num));
			num++;
		}
		iter = data.find(end[i]);
		if (iter == data.end())
		{
			data.insert(pair<char, int>(end[i], num));
			num++;
		}
	}
	int *adj = new int[num*num];
	for (int i = 0; i < num * num; i++)
		adj[i] = INT_MAX;
	int node1, node2;
	for (int i = 0; i < n; i++)
	{
		iter = data.find(start[i]);
		node1 = iter->second;
		iter = data.find(end[i]);
		node2 = iter->second;
		if (adj[node1*num + node2] > length[i])
		{
			adj[node1*num + node2] = length[i];
			adj[node2*num + node1] = length[i];
		}
	}
	delete[] start;
	delete[] end;
	delete[] length;
	int *dist = new int[num];
	memset(dist, 0, sizeof(int)* num);
	Dijkstra(adj, 0, num, dist);
	char result;
	int min = INT_MAX;
	for (iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->first >= 'A' && iter->first < 'Z' && dist[iter->second] < min)
		{
			min = dist[iter->second];
			result = iter->first;
		}
	}
	delete[] adj;
	delete[] dist;
	cout << result << " " << min << endl;
	return 0;
}
void Dijkstra(int adj[], int v0, int num, int dist[])
{
	bool *S = new bool[num];
	for (int i = 0; i < num; i++)
	{
		dist[i] = adj[v0*num + i];
		S[i] = false;
	}
	dist[v0] = 0;
	S[v0] = true;
	for (int i = 1; i < num; i++)
	{
		int mindist = INT_MAX;
		int u = v0;
		for (int j = 0; j < num; j++)
		{
			if (!S[j] && dist[j] < mindist)
			{
				u = j;
				mindist = dist[j];
			}
		}
		S[u] = true;
		for (int j = 0; j < num; j++)
		{
			if (!S[j] && adj[u*num + j] != INT_MAX && dist[u] + adj[u*num + j] < dist[j])
				dist[j] = dist[u] + adj[u*num + j];
		}
	}
}