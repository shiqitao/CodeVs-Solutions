#include <iostream>
#include <string>
#include<sstream>
using namespace std;
struct word
{
	string thisWord;
	word *next;
};
struct stack
{
	word *top;
	int num;
};
void stackInit(stack *s);
void stackPush(stack *s, string *str);
void stackPop(stack *s, string *str);
int main()
{
	string str;
	getline(cin, str);
	stack s;
	stackInit(&s);
	stringstream sentence(str);
	while (sentence >> str)
	{
		stackPush(&s, &str);
	}
	while (s.num != 0)
	{
		stackPop(&s, &str);
		cout << str << " ";
	}
	cout << endl;
	return 0;
}
void stackInit(stack *s)
{
	s->num = 0;
	s->top = NULL;
}
void stackPush(stack *s, string *str)
{
	word *next = new word;
	next->thisWord = *str;
	next->next = s->top;
	s->top = next;
	s->num++;
}
void stackPop(stack *s, string *str)
{
	*str = s->top->thisWord;
	s->num--;
	word *p;
	p = s->top;
	s->top = s->top->next;
	delete(p);
}