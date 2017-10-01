#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;
#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
int **data;			// 记录美学值
int *ex_flower;		// 记录花的期望值
int *ex_vase;		// 记录花瓶的期望值
bool *vis_flower;	// 记录每一轮匹配过的花
bool *vis_vase;		// 记录每一轮匹配过的花瓶
int *match_flower;	// 记录每个花匹配到的花瓶，没有则为-1（可以不用）
int *match_vase;	// 记录每个花瓶匹配到的花，没有则为-1
unsigned int *slack;	// slack优化
int F, V;
int KM();
bool findPath(int flower);
int main()
{
	cin >> F >> V;
	data = new int*[F];
	for (int i = 0; i < F; i++)
	{
		data[i] = new int[V];
		for (int j = 0; j < V; j++)
			cin >> data[i][j];
	}
	cout << KM() << endl;
	for (int i = 0; i < F; i++)
		delete[] data[i];
	delete[] data;
	delete[] ex_flower;
	delete[] ex_vase;
	delete[] vis_flower;
	delete[] vis_vase;
	delete[] match_flower;
	delete[] match_vase;
	delete[] slack;
	return 0;
}
int KM()
{
	ex_flower = new int[F];
	// 每个花的初始期望值是与她相连的花瓶最大的好感度
	for (int i = 0; i < F; i++)
	{
		ex_flower[i] = data[i][0];
		for (int j = 1; j < V; j++)
			ex_flower[i] = MAX(ex_flower[i], data[i][j]);
	}
	ex_vase = new int[V];
	memset(ex_vase, 0, sizeof(int)*V);		// 初始每个花瓶的期望值为0
	match_flower = new int[F];
	match_vase = new int[V];
	memset(match_flower, -1, sizeof(int)*F);// 初始每个花都没有匹配的花瓶
	memset(match_vase, -1, sizeof(int)*V);	// 初始每个花瓶都没有匹配的花
	// 尝试为每一个花解决问题
	vis_flower = new bool[F];
	vis_vase = new bool[V];
	slack = new unsigned int[F];
	for (int i = 0; i < F; i++)
	{
		memset(slack, 511, sizeof(int)*F);
		while (true)
		{
			// 为每个花解决问题的方法是 ：如果找不到就降低期望值，直到找到为止
			// 记录每轮匹配中花和花瓶是否被尝试匹配过
			memset(vis_flower, false, sizeof(bool)*F);
			memset(vis_vase, false, sizeof(bool)*V);
			if (findPath(i)) break;  // 找到归宿 退出
			// 如果不能找到 就降低期望值
			// 最小可降低的期望值
			int d = INT_MAX;
			for (int j = 0; j < F; j++)
			{
				if (vis_flower[j])
					d = MIN(d,slack[j]);
			}
			for (int j = 0; j < F; j++)
			{
				if (vis_flower[j]) ex_flower[j] -= d;	// 所有访问过的花降低期望值
			}
			for (int j = 0; j < V; j++)
			{
				if (vis_vase[j]) ex_vase[j] += d;		// 所有访问过的花瓶增加期望值
			}
		}
	}
	// 匹配完成 求出所有配对的好感度的和
	int res = 0;
	for (int i = 0; i < F; i++)
		res += data[i][match_flower[i]];
	return res;
}
bool findPath(int flower)
{
	vis_flower[flower] = true;
	for (int vase = 0; vase < V; vase++)
	{
		if (vis_vase[vase]) continue; // 每一轮匹配 每个花瓶只尝试一次
		int gap = ex_flower[flower] + ex_vase[vase] - data[flower][vase];
		if (gap == 0)
		{	// 如果符合要求
			vis_vase[vase] = true;
			if (match_vase[vase] == -1 || findPath(match_vase[vase]))
			{	// 找到一个没有匹配的花瓶 或者该花瓶的花可以找到其他花瓶
				match_flower[flower] = vase;
				match_vase[vase] = flower;
				return true;
			}
		}
		else
			slack[flower] = MIN(slack[flower], gap);
	}
	return false;
}