#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define EMPTY 0

//#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

extern bool swap(int dir);
extern void DebugOutput();

void CheckEmptyBlock(int board[5][5]);
void BFS(int x, int y, int ex, int ey);
void colorBFS(int x, int y, int color);
void ResetMAP();
void ResetmyMAP();
void MoveBlock();
bool myswap(int dir);
bool blockswap(int dir);
void ResetAll();
//void mDebugOutput();

queue<pair<int, int> > q;
int MAP[5][5];
int myboard[5][5];
int m_dx[4] = {1, -1, 0, 0};
int m_dy[4] = {0, 0, 1, -1};
int c_x, c_y;
int m_x, m_y;
int t_x, t_y;
int t_cx, t_cy;

typedef struct _Block{
	int x;
	int y;
}Block;

Block empty;
Block pocus;
Block c_myMAP[5][5];
Block myMAP[5][5];

void solve(int board[5][5], int pattern[3][3], int callCntLimit) {
	ResetAll();
	
	for(int x = 0; x < 5; x++){
		for(int y = 0; y < 5; y++){
			myboard[x][y] = board[x][y];
		}
	}
	CheckEmptyBlock(myboard);
	//myswap(DOWN);
	
	for(int x = 1; x < 4; x++){
		for(int y = 1; y < 4; y++){
			ResetmyMAP();
			ResetMAP();
			colorBFS(x, y, pattern[x-1][y-1]);
	
			while(1){
				if(c_myMAP[c_x][c_y].x == 55 && c_myMAP[c_x][c_y].y == 55) break;
				t_cx = c_x;
				t_cy = c_y;
				
				ResetMAP();
				CheckEmptyBlock(myboard);
				
				//mDebugOutput();
				BFS(c_myMAP[c_x][c_y].x, c_myMAP[c_x][c_y].y, empty.x, empty.y);
				MoveBlock();
				//mDebugOutput();

				if(c_x > c_myMAP[c_x][c_y].x){
					swap(DOWN);
					myswap(DOWN);
				}
				else if(c_x < c_myMAP[c_x][c_y].x) {
					swap(UP);
					myswap(UP);
				}
				
				if(c_y > c_myMAP[c_x][c_y].y) {
					swap(RIGHT);
					myswap(RIGHT);
				}
				else if(c_y < c_myMAP[c_x][c_y].y) {
					swap(LEFT);
					myswap(LEFT);
				}
				//mDebugOutput();

				c_x = c_myMAP[t_cx][t_cy].x;
				c_y = c_myMAP[t_cx][t_cy].y;
			}
			
			MAP[x][y] = 2;
		}
	}
	
	//mDebugOutput();
}

void CheckEmptyBlock(int board[5][5]){
	for(int x = 0; x < 5; x++){
		for(int y = 0; y < 5; y++){
			if(board[x][y] == EMPTY)
			{
				empty.x = x;
				empty.y = y;
			}
		}
	}
}

void BFS(int x, int y, int ex, int ey){
	int nx, ny;
	q.push(make_pair(x,y));
	MAP[x][y] = true;
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		MAP[x][y] = true;
		
		if(x == ex && y == ey){
			m_x = x;
			m_y = y;
			return;	
		}
		
		for(int i = 0; i < 4; i++){
			nx = x + m_dx[i];
			ny = y + m_dy[i];
			
			if(nx >= 5 || ny >= 5 || nx < 0 || ny < 0 || MAP[nx][ny]) continue;
			if(nx == c_x && ny == c_y) continue;
			
			myMAP[nx][ny].x = x;
			myMAP[nx][ny].y = y;
			q.push(make_pair(nx,ny));
		}
	}
}

void colorBFS(int x, int y, int color){
	int nx, ny;
	q.push(make_pair(x,y));
	MAP[x][y] = true;
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		MAP[x][y] = true;
		
		if(myboard[x][y] == color)
		{
			c_x = x;
			c_y = y;
			return;
		}
		
		for(int i = 0; i < 4; i++){
			nx = x + m_dx[i];
			ny = y + m_dy[i];
			
			if(nx >= 5 || ny >= 5 || nx < 0 || ny < 0 || MAP[nx][ny]) continue;
			c_myMAP[nx][ny].x = x;
			c_myMAP[nx][ny].y = y;
			q.push(make_pair(nx,ny));
		}
	}
}

void ResetMAP(){
	while(!q.empty()){
		q.pop();	
	}
	for(int x = 0; x < 5; x++){
		for(int y = 0; y < 5; y++){
			if(MAP[x][y] == 1) MAP[x][y] = false;
		}
	}
	
	for(int x = 0; x < 5; x++){
		for(int y = 0; y < 5; y++){
			myMAP[x][y].x = 55;
			myMAP[x][y].y = 55;
		}
	}
}

void ResetmyMAP(){
	for(int x = 0; x < 5; x++){
		for(int y = 0; y < 5; y++){
			myMAP[x][y].x = 55;
			myMAP[x][y].y = 55;
		}
	}
	
	for(int x = 0; x < 5; x++){
		for(int y = 0; y < 5; y++){
			c_myMAP[x][y].x = 55;
			c_myMAP[x][y].y = 55;
		}
	}
}

void MoveBlock(){
	//cout << m_x << " " << m_y << "\n";
	while(1){
		if(myMAP[m_x][m_y].x == 55 && myMAP[m_x][m_y].y == 55) break;
		t_x = m_x;
		t_y = m_y;
		
		//cout << "now:" << m_x << " " << m_y << "\n";
		//cout << "tobe" << myMAP[m_x][m_y].x << " " << myMAP[m_x][m_y].y<< "\n";
		if(m_x > myMAP[m_x][m_y].x){
			swap(UP);
			myswap(UP);
		}
		else if(m_x < myMAP[m_x][m_y].x) {
			swap(DOWN);
			myswap(DOWN);
		}
		
		if(m_y > myMAP[m_x][m_y].y) {
			swap(LEFT);
			myswap(LEFT);
		}
		else if(m_y < myMAP[m_x][m_y].y) {
			swap(RIGHT);
			myswap(RIGHT);
		}
		
		//mDebugOutput();
		
		m_x = myMAP[t_x][t_y].x;
		m_y = myMAP[t_x][t_y].y;
		//cout << m_x << " " << m_y << "\n";
	}
}

bool myswap(int dir) {
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	if (dir < UP || dir > LEFT) {
		return false;
	}

	int newY = empty.y + dy[dir];
	int newX = empty.x + dx[dir];

	if (newY < 0 || newY >= 5 || newX < 0 || newX >= 5) {
		return false;
	}

	myboard[empty.x][empty.y] = myboard[newX][newY];
	myboard[newX][newY] = 0;
	empty.y = newY;
	empty.x = newX;

	return true;
}

void ResetAll(){
	while(!q.empty()){
		q.pop();	
	}
	for(int x = 0; x < 5; x++){
		for(int y = 0; y < 5; y++){
			MAP[x][y] = false;
		}
	}
	
	for(int x = 0; x < 5; x++){
		for(int y = 0; y < 5; y++){
			myMAP[x][y].x = 55;
			myMAP[x][y].y = 55;
		}
	}
}

/*
void mDebugOutput()
{
	cout << "\n";
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cout << myboard[i][j] << " ";
		}
		cout << "\n";
	}	
}
*/
