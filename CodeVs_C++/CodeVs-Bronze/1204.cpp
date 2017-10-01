#include <iostream>
#include <string>
using namespace std;

/*暴力搜索*/
short violence(string s, string p);
/*KMP算法*/
short KMP(string s, string p);
/*求解Next数组*/
void getNext(string p, short next[]);
/*求解Next数组的优化*/
void getNextVal(string p, short next[]);

int main()
{
	string s, p;
	cin >> s >> p;
	cout << KMP(s, p) << endl;
	return 0;
}
/*暴力搜索*/
short violence(string s, string p)
{
	unsigned short sLen = s.length();
	unsigned short pLen = p.length();
	int i = 0;
	int j = 0;
	while (i < sLen && j < pLen)
	{
		if (s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			i -= j - 1;
			j = 0;
		}
	}
	if (j == pLen)
		return i -= j - 1;		//实际应为：i -= j；
	else
		return -1;
}
/*KMP算法*/
short KMP(string s, string p)
{
	unsigned short sLen = s.length();
	unsigned short pLen = p.length();
	int i = 0;
	int j = 0;
	short *next = new short[pLen];
	//getNext(p, next);
	getNextVal(p, next);
	while (i < sLen && j < pLen)
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j == pLen)
		return i -= j - 1;		//实际应为：i -= j；
	else
		return -1;
	delete(next);
}
/*求解Next数组*/
void getNext(string p, short next[])
{
	unsigned short pLen = p.length();
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]表示前缀，p[j]表示后缀  
		if (k == -1 || p[j] == p[k])
		{
			++k;
			++j;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}
/*求解Next数组的优化*/
void getNextVal(string p, short next[])
{
	unsigned short pLen = p.length();
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]表示前缀，p[j]表示后缀    
		if (k == -1 || p[j] == p[k])
		{
			++j;
			++k;
			//较之前next数组求法，改动在下面4行  
			if (p[j] != p[k])
				next[j] = k;   //之前只有这一行  
			else
				//因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]  
				next[j] = next[k];
		}
		else
		{
			k = next[k];
		}
	}
}