#include <iostream>

using namespace std;

bool MAP[30+1][10+1];
bool CheckMAP[30+1][10+1];
bool visited[30+1][10+1];
bool Line[10+1];
bool tempMAP[30+1][10+1];

int N, M, H;

int startNum;
bool EndFlag = false;

int dy[2] = {1, -1};


void Input();
void DFS(int x, int y);
void SetLine(int cnt);
void ResetVisted();
void Run();

void DebugOutput();

int main(void)
{
    Input();
    
    
//    cout << "\n";
//    for(int x = 1; x <= H; x++){
//        for(int y = 1; y <= N; y++){
//            cout << MAP[x][y] << " ";
//        }
//        cout << "\n";
//    }
    
    for(int i = 0; i < 4; i++){
        
        SetLine(i);
        if(EndFlag){
            cout << i;
            return 0;     
        }
    }
    
    if(EndFlag == false) cout << "-1";
    return 0;
}

void Input(){
    cin >> N >> M >> H;
    int x, y;
    for(int i = 0; i < M; i++){
        if(M == 0) continue;
        cin >> x >> y;
        MAP[x][y] = true;
        CheckMAP[x][y] = true;
        MAP[x][y+1] = true;
    }
}

void DebugOutput(){
    
    
//    cout << "\n";
//    for(int x = 1; x <= H; x++){
//        for(int y = 1; y <= N; y++){
//            cout << MAP[x][y] << " ";
//        }
//        cout << "\n";
//    }
    
    cout << "\n";
    for(int x = 1; x <= H; x++){
        for(int y = 1; y <= N; y++){
            cout << visited[x][y] << " ";
        }
        cout << "\n";
    }
    
//    cout << "\n";
//    for(int i = 1; i <= N; i++){
//        cout << Line[i] << " ";
//    }
//    cout << "\n";
//    cout << EndFlag;
    
    
//    cout << "\n";
//    for(int x = 1; x <= H; x++){
//        for(int y = 1; y <= N; y++){
//            cout << tempMAP[x][y] << " ";
//        }
//        cout << "\n";
//    }
}

void DFS(int x, int y){
    if(x > H){
        //DebugOutput();
        if(startNum == y) Line[startNum] = true;
        else Line[startNum] = false;
        return;
    }
    visited[x][y] = true;
    
    if(MAP[x][y] == true && CheckMAP[x][y] == true && !visited[x][y+1]) DFS(x, y+1);
    else if(MAP[x][y] == true && CheckMAP[x][y] == false && !visited[x][y-1]) DFS(x, y-1);
    else DFS(x+1, y);
    
    
//    for(int i = 0; i < 2; i++){
//        ny = y + dy[i];
//        eny = y + 2*dy[i];
//        nny = y - dy[i];
//        if(ny > N || ny < 1 || visited[x][ny]) continue;
//        
//        if(MAP[x][y] == 1 && MAP[x][ny] == 1 && !visited[x][ny]){
//            if(MAP[x][ny] == 1 && MAP[x][nny] == 1){
//                if(MAP[x][eny] == 0){
//                    DFS(x+1, ny);
//                    Flag = true;
//                }
//                else continue;
//            }
//            else DFS(x+1, ny);   
//            Flag = true;
//        }
//    }
//    if(Flag == false) DFS(x+1, y);
}

void SetLine(int cnt){
    if(EndFlag == true) return;
    
    if(cnt == 0){
        Run();
        return;
    }
    else{
        for(int x = 1; x <= H; x++){
            for(int y = 1; y <= N-1; y++){
                if(MAP[x][y] || MAP[x][y+1]) continue;
                MAP[x][y] = true;
                MAP[x][y+1] = true;
                CheckMAP[x][y] = true;
                cnt--;
                SetLine(cnt);
                MAP[x][y] = false;
                MAP[x][y+1] = false;
                CheckMAP[x][y] = false;
                cnt++;
            }
        }
    }
}

void Run(){
    for(int i = 1; i <= N; i++){
        startNum = i;
        DFS(1, i);
        ResetVisted();
    }
    
    
    for(int i = 1; i <= N; i++){
        if(!Line[i]) return;
    }
    
    EndFlag = true;
}

void ResetVisted(){
    for(int x = 1; x <= H; x++){
        for(int y = 1; y <= N; y++){
            visited[x][y] = false;
        }
    }
}
