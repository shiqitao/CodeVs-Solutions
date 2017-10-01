#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct State
{
	char checkerboard[16];
	char piece;		//BÎªºÚ£¬WÎª°×
	int space0, space1;
	int num;
};
bool ifEnd(State state);
bool ifExist(const State state, const int space, const int direction);
void go(State &state, const int space, const int direction);
void back(State &state, const int space, const int direction);
int main()
{
	queue<State> state;
	State newState, temp;
	newState.num = 0;
	newState.piece = 'B';
	bool ifSpace = false;
	for (int i = 0; i < 16; i++)
	{
		cin >> newState.checkerboard[i];
		if (newState.checkerboard[i] == 'O' && !ifSpace)
		{
			newState.space0 = i;
			ifSpace = true;
		}
		else if (newState.checkerboard[i] == 'O') newState.space1 = i;
	}
	state.push(newState);
	newState.piece = 'W';
	state.push(newState);
	while (true)
	{
		newState = state.front();
		if (ifEnd(newState))
		{
			cout << newState.num << endl;
			return 0;
		}
		else
		{
			memcpy(temp.checkerboard, newState.checkerboard, sizeof(char)* 16);
			temp.piece = newState.piece == 'B' ? 'W' : 'B';
			temp.space0 = newState.space0;
			temp.space1 = newState.space1;
			temp.num = newState.num;
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (ifExist(temp, i, j))
					{
						go(temp, i, j);
						state.push(temp);
						back(temp, i, j);
					}
				}
			}
		}
		state.pop();
	}
}
bool ifEnd(const State state)
{
	for (int i = 0; i < 4; i++)
	{
		if (state.checkerboard[i * 4 + 0] == state.checkerboard[i * 4 + 1] && state.checkerboard[i * 4 + 1] == state.checkerboard[i * 4 + 2] && state.checkerboard[i * 4 + 2] == state.checkerboard[i * 4 + 3])
		{
			return true;
		}
		if (state.checkerboard[0 * 4 + i] == state.checkerboard[1 * 4 + i] && state.checkerboard[1 * 4 + i] == state.checkerboard[2 * 4 + i] && state.checkerboard[2 * 4 + i] == state.checkerboard[3 * 4 + i])
		{
			return true;
		}
	}
	if (state.checkerboard[0 * 4 + 0] == state.checkerboard[1 * 4 + 1] && state.checkerboard[1 * 4 + 1] == state.checkerboard[2 * 4 + 2] && state.checkerboard[2 * 4 + 2] == state.checkerboard[3 * 4 + 3])
	{
		return true;
	}
	if (state.checkerboard[0 * 4 + 3] == state.checkerboard[1 * 4 + 2] && state.checkerboard[1 * 4 + 2] == state.checkerboard[2 * 4 + 1] && state.checkerboard[2 * 4 + 1] == state.checkerboard[3 * 4 + 0])
	{
		return true;
	}
	return false;
}
bool ifExist(const State state, const int space, const int direction)
{
	int next = space == 0 ? state.space0 : state.space1;
	if (direction == 0 && next % 4 == 0) return false;
	if (direction == 1 && next % 4 == 3) return false;
	if (direction == 0) next--;
	if (direction == 1) next++;
	if (direction == 2) next -= 4;
	if (direction == 3) next += 4;
	if (next < 0 || next > 15) return false;
	if (next == state.space0 || next == state.space1) return false;
	if (state.checkerboard[next] != state.piece) return false;
	return true;
}
void go(State &state, const int space, const int direction)
{
	int next = space == 0 ? state.space0 : state.space1;
	state.checkerboard[next] = state.piece;
	if (direction == 0) next--;
	if (direction == 1) next++;
	if (direction == 2) next -= 4;
	if (direction == 3) next += 4;
	state.checkerboard[next] = 'O';
	if (space == 0) state.space0 = next;
	else state.space1 = next;
	state.num++;
}
void back(State &state, const int space, const int direction)
{
	int next = space == 0 ? state.space0 : state.space1;
	state.checkerboard[next] = state.piece;
	if (direction == 0) next++;
	if (direction == 1) next--;
	if (direction == 2) next += 4;
	if (direction == 3) next -= 4;
	state.checkerboard[next] = 'O';
	if (space == 0) state.space0 = next;
	else state.space1 = next;
	state.num--;
}