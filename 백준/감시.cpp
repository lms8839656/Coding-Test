#include <iostream>

#define MAX 8

using namespace std;

int N, M;
int MAP[MAX][MAX];
int tempMAP[MAX][MAX];
int preMAP[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int MinArea = 987654321;
int cameraNum = 0;
int depth = 0;

void Input();
void Camera(int x, int y, int num, int direction);
void SearchMap(int x, int y, int direction);
void Run();
void MapToTemp();
void TempToMap();
void CalMin();
void MapToPre();
void PreToMap();

void DebugOutput();

int main(void)
{
    Input();
    MapToTemp();
    Run();
    //DebugOutput();
    cout << MinArea;
    
    return 0;
}

void Input(){
    cin >> N >> M;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            cin >> MAP[x][y];
            if(MAP[x][y] > 0 && MAP[x][y] != 6) cameraNum++;
        }
    }
}

void DebugOutput(){
    cout << "\n";
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            cout << MAP[x][y] << " ";
        }
        cout << "\n";
    }
}

void Camera(int x, int y, int num, int direction){
    switch(num){
        case 1:
            SearchMap(x, y, direction);
            break;
            
        case 2:
            SearchMap(x, y, direction);
            SearchMap(x, y, (direction + 2) % 4);
            break;
        
        case 3:
            SearchMap(x, y, direction);
            SearchMap(x, y, (direction + 1) % 4);
            break;
            
        case 4:
            SearchMap(x, y, direction);
            SearchMap(x, y, (direction + 1) % 4);
            SearchMap(x, y, (direction + 2) % 4);
            break;
            
        case 5:
            SearchMap(x, y, 0);
            SearchMap(x, y, 1);
            SearchMap(x, y, 2);
            SearchMap(x, y, 3);
            break;
    }
}

void SearchMap(int x, int y, int direction){
    int nx, ny;

    nx = dx[direction] + x;
    ny = dy[direction] + y;
    if(nx >= N || ny >= M || nx < 0 || ny < 0 || MAP[nx][ny] == 6){
        return;   
    }
    
    MAP[nx][ny] = 7;

    
    SearchMap(nx, ny, direction);
}

void Run(){
    if(cameraNum == depth){
        CalMin();
        PreToMap();
        return;
    }
    
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            if(MAP[x][y] == 6 || MAP[x][y] == 7) continue;
            if(MAP[x][y]){
                if(visited[x][y] == true) continue;
                visited[x][y] = true;
                depth++;
                for(int i = 0; i < 4; i++){
                    MapToPre();
                    Camera(x, y, MAP[x][y], i);
                    Run();
                }
                depth--;
                visited[x][y] = false;
            }
        }
    }
}

void MapToTemp(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            tempMAP[x][y] = MAP[x][y];
        }
    }
}

void TempToMap(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            MAP[x][y] = tempMAP[x][y];
        }
    }
}

int Flag = false;
void CalMin(){
    int cnt = 0;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            if(tempMAP[x][y] > 0 && tempMAP[x][y] != 6) MAP[x][y] = tempMAP[x][y];
            if(MAP[x][y] == 0) cnt++;
        }
    }
    if(MinArea > cnt) MinArea = cnt;
    
    
    if(MinArea == 10 && Flag == false){
        DebugOutput();
        Flag = true;   
    }
}

void MapToPre(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            preMAP[x][y] = MAP[x][y];
        }
    }
}

void PreToMap(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            MAP[x][y] = preMAP[x][y];
        }
    }
}


/*
#include <iostream>

#define MAX 8

using namespace std;

int MAP[MAX][MAX];
int tempMAP[MAX][MAX];
bool visited[MAX][MAX];
bool checkCamera[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;

int maxSpace, space;

void Input();
void SearchMap();
void SetMap(int head, int x, int y);
void SetCameraMap(int num, int x, int y);
void countMap();

void DebugMap();

int main(void)
{
    Input();
    SearchMap();
    DebugMap();
    return 0;
}

void Input(){
    cin >> N >> M;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            cin >> MAP[x][y];
        }
    }
}

void SearchMap(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            if(MAP[x][y] > 0){
                SetCameraMap(MAP[x][y], x, y);
            }
        }
    }
}

void SetMap(int head, int x, int y){
    int nx, ny;
    visited[x][y] = true;
    nx = x + dx[head];
    ny = y + dy[head];
    MAP[nx][ny] = 7;
    
    if(nx >= N || ny >= M || nx < 0 || ny < 0 || visited[nx][ny] || MAP[nx][ny] == 6){
        return;
    }
    
    SetMap(head, nx, ny);
}

void SetCameraMap(int num, int x, int y){
    switch(num){
        case 1:
            SetMap(2, x, y);
            break;
        
        case 2:

            break;
            
        case 3:

            break;
            
        case 4:
 
            break;
            
        case 5:

            break;
    }
}

void countMap(){
    space = 0;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            if(MAP[x][y] == 0) space++;
        }
    }
    
    if(maxSpace < space) maxSpace = space;
}

void DebugMap(){
    cout << "\n";
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            cout << MAP[x][y] << " ";
        }
        cout << "\n";
    }
}

*/
