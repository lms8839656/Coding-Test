#include <iostream>

#define MAX 20

using namespace std;

int N, M, K;

int MAP[MAX+1][MAX+1];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0}

void Input();
void DebugOutput();

int main(void)
{
    Input();
    DebugOutput();
    
    return 0;
}

void Input(){
    cin >> N >> M >> K;
    
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= M; y++){
            cin >> MAP[x][y];
        }
    }
}

void DebugOutput(){
    cout << "\n";
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= M; y++){
            cout << MAP[x][y] << " ";
        }
        cout << "\n";
    }
}
