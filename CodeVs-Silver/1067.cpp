#include <iostream>
#include <queue>
using namespace std;
struct Word
{
	int word;
	Word *next;
};
struct Queue
{
	Word *front;
	Word *back;
	int size;
};
void init(Queue *queue);
void push(Queue *queue, int n);
int pop(Queue *queue);
//这个search复杂度较高，可以搭建二叉搜索树减少复杂度
bool search(Queue *queue, int n);
int main()
{
	int n, m; cin >> m >> n;
	Queue queue;
	init(&queue);
	int temp;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (!search(&queue, temp))
		{
			sum++;
			if (queue.size == m)
				pop(&queue);
			push(&queue, temp);
		}
	}
	cout << sum << endl;
	return 0;
}
void init(Queue *queue)
{
	queue->front = NULL;
	queue->back = NULL;
	queue->size = 0;
}
void push(Queue *queue, int n)
{
	Word *newWord = new Word{ n, NULL };
	if (queue->front == NULL)
		queue->front = newWord;
	if (queue->back == NULL)
		queue->back = newWord;
	else
	{
		queue->back->next = newWord;
		queue->back = newWord;
	}
	queue->size++;
}
int pop(Queue *queue)
{
	int result = queue->front->word;
	queue->front = queue->front->next;
	queue->size--;
	return result;
}
bool search(Queue *queue, int n)
{
	Word *it = queue->front;
	int size = queue->size;
	for (int i = 0; i < size; i++)
	{
		if (it->word == n)
			return true;
		else
			it = it->next;
	}
	return false;
}