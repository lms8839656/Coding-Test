#include <iostream>

#define MAX 100

using namespace std;

int MAP[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool IsPossibleX[MAX];
bool IsPossibleY[MAX];

int N, L;

void Input();
void CalRoad();
void DebugOutput();

int main(void)
{
	Input();
	DebugOutput();
	return 0;
}

void Input(){
	cin >> N >> L;
	for(int x = 0; x < N; x++){
		for(int y = 0; y < N; y++){
			cin >> MAP[x][y];
		}
	}
}

void CalRoad(){
	int setNum;
	bool IsPossble;
	for(int x = 0; x < N; x++){
		IsPossble = true;
		for(int y = 0; y < N; y++){
			if(y == 0){
				setNum = MAP[x][y];
				continue;	
			}
			
			
			
		}
	}
	
	for(int y = 0; y < N; y++){
		for(int x = 0; x < N; x++){
			
		}
	}
}

void DebugOutput(){
	cout << "\n";
	for(int x = 0; x < N; x++){
		for(int y = 0; y < N; y++){
			cout << MAP[x][y] << " ";
		}
		cout << "\n";
	}
}
