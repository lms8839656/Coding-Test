#include <iostream>

#define MAX 50

using namespace std;

int MAP[MAX][MAX];
int tempMAP[MAX][MAX];
int orgtempMAP[MAX][MAX];
bool CheckVirus[MAX][MAX];
int TimeMAP[MAX][MAX];


int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;

int time;
int mintime = 987654321;

void Input();
void SpreadVirus(int x, int y);
void CopyTempToMap();
void CopyMapToTemp();
void CopySelectVirusToTemp();
void CopytemptoOrg();
void SelectVirus(int cnt);
bool CheckCondition();

void DebugOutput();

int main(void)
{
    Input();
    CopyMapToTemp();
    
    SelectVirus(0);
    

    
    cout << mintime;

    return 0;
}

void Input(){
    cin >> N >> M;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N ; y++){
            cin >> MAP[x][y];
        }
    }
}

void SpreadVirus(int x, int y){
    int nx, ny;
    for(int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx >= N || ny >= N || nx < 0 || ny < 0 || tempMAP[nx][ny] == 1 || (MAP[nx][ny] == 2 && !CheckVirus[nx][ny])) continue;
        
        tempMAP[nx][ny] = 2;
    }
}

void CopyTempToMap(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N ; y++){
            MAP[x][y] = tempMAP[x][y];
        }
    }
}

void CopyMapToTemp(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N ; y++){
            tempMAP[x][y] = MAP[x][y];
        }
    }
}

void CopySelectVirusToTemp(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N ; y++){
            tempMAP[x][y] = MAP[x][y];
            if(MAP[x][y] == 2 && CheckVirus[x][y] == false) tempMAP[x][y] = 0;
        }
    }
}

void CopytemptoOrg(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N ; y++){
            orgtempMAP[x][y] = tempMAP[x][y];
        }
    }
}

void SelectVirus(int cnt){
    if(cnt == M){
        CopySelectVirusToTemp();
        time = 0;
        do{
            CopytemptoOrg();
            for(int x = 0; x < N; x++){
                for(int y = 0; y < N; y++){
                    if(orgtempMAP[x][y] == 2) SpreadVirus(x, y);
                }
            }
        }while(CheckCondition());
        
        if(time < mintime) mintime = time;
        return;
    }
    
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N ; y++){
            if(MAP[x][y] == 2 && !CheckVirus[x][y]){
                CheckVirus[x][y] = true;
                SelectVirus(cnt+1);
                CheckVirus[x][y] = false;
            }
        }
    }
}

bool CheckCondition(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N ; y++){
            if(tempMAP[x][y] != orgtempMAP[x][y]){
                time++;
                return true;
            }
        }
    }
    
    return false;
} 
//활성바이러스 각각 dfs 진행 깊이 최소값으로 갱신 
void DebugOutput(){
    cout << "\n";
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N ; y++){
            cout << tempMAP[x][y] << " ";
        }
        cout << "\n";
    }
}
