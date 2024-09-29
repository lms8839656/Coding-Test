#include <iostream>
#include <vector>
#include <math.h>

#define MAX 64

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int MAP[MAX][MAX];
int tempMAP[MAX][MAX];

vector<int> Oder;

int N, Q;
int MAPsize = 1;

void Input();
void DivArea();
void RotateClock();
void CopyMapToTemp();
void DebugOutput();


int main(void)
{
	Input();
	CopyMapToTemp();
	//RotateClock();
	DivArea();
	DebugOutput();
	
	return 0;
}

void Input(){
	int num;
	cin >> N >> Q;
	
	MAPsize = pow(2, N);
	
	for(int x = 0; x < MAPsize; x++){
		for(int y = 0; y < MAPsize; y++){
			cin >> MAP[x][y];
		}
	}
	
	for(int i = 0; i < Q; i++){
		cin >> num;
		Oder.push_back(num);
	}
	
}

void DebugOutput(){
	cout << "\n";
	for(int x = 0; x < MAPsize; x++){
		for(int y = 0; y < MAPsize; y++){
			cout << tempMAP[x][y] << " ";
		}
		cout << "\n";
	}
}

void CopyMapToTemp(){
	for(int x = 0; x < MAPsize; x++){
		for(int y = 0; y < MAPsize; y++){
			tempMAP[x][y] = MAP[x][y];
		}
	}
}

void DivArea(){
	int divnum = MAPsize / pow(2, 1);
	int cnt = 1;
	for(int ox = 0; ox < divnum; ox++){
		for(int oy = 0; oy < divnum; oy++){
			for(int ix = ox * 2; ix < ox * 2 + pow(2, 1); ix++){
				for(int iy = oy * 2; iy < oy * 2 + pow(2, 1); iy++){
					tempMAP[iy][int(ox * 2 + pow(2, 1)) - ix - 1] = MAP[ix][iy];
				}
			}
		}
	}
}

void RotateClock(){
	for(int x = 0; x < MAPsize; x++){
		for(int y = 0; y < MAPsize; y++){
			MAP[x][y] = tempMAP[y][MAPsize - x - 1];
		}
	}
}
