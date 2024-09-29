#include <iostream>

#define MAX 499

using namespace std;

int N;

int MAP[MAX+1][MAX+1];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

float send[5][5] = {0, 0, 0.02, 0, 0,
                    0, 0.1, 0.07, 0.01, 0,
                    0.05, 1, 0, 0, 0,
                    0, 0.1, 0.07, 0.01, 0,
                    0, 0, 0.02, 0, 0};

int tempsend[5][5];

int movecnt = 1;
int movedistance = 1;
int outsend = 0;

void Input();
void MoveStorm();
void SpreadSend(int x, int y);
void CopySend();
void RotateCountClock();
void DebugOutput();

int main(void)
{
    Input();
    //DebugOutput();
    int x = (N + 1) / 2;
    int y = (N + 1) / 2;
    int nx, ny;
    
    
    while(!(x == 1 && y == 0)){
        
        //MAP[x][y] = movecnt;
        
        
        
        DebugOutput();

        RotateCountClock();
        
        int cnt = 1;
        int nx = x;
        int ny = y;
        while(cnt < movedistance){
            cnt++;
            nx = nx + dx[movecnt%4];
            ny = ny + dy[movecnt%4];
            SpreadSend(nx, ny);
            //MAP[nx][ny] = movecnt;
            DebugOutput();
        }
        x = x + movedistance * dx[movecnt%4];
        y = y + movedistance * dy[movecnt%4];
        SpreadSend(x, y);
        
        movecnt++;
        if(movecnt % 2 == 1){
            movedistance++;
            
        }
        
        
    }

    DebugOutput();
    cout << outsend;
    return 0;
}

void Input(){
    cin >> N;
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            cin >> MAP[x][y];
        }
    }
}

void MoveStorm(){
    int cnt = 0;
    int nx, ny;
    while(cnt == movecnt){
        cnt++;
        //nx = x + movedistance * dx[movecnt%4];
        //ny = y + movedistance * dy[movecnt%4];
        MAP[nx][ny] = movecnt;
    }
}

void SpreadSend(int x, int y){
    int center = 2;
    int tx, ty;
    int ax, ay;
    bool IsAsendPossible = false;
    int centerSend = MAP[x][y];
    for(int sx = 0; sx < 5; sx++){
        for(int sy = 0; sy < 5; sy++){
            tx = sx - center;
            ty = sy - center;
            if(send[sx][sy] == 1){
                if(x + tx > N || y + ty > N || x + tx < 1 || y + ty < 1) IsAsendPossible = false;
                else{
                    IsAsendPossible = true;
                    ax = x + tx;
                    ay = y + ty;
                }
                continue;
            }
            
            
            if(x + tx > N || y + ty > N || x + tx < 1 || y + ty < 1) outsend = outsend + centerSend * send[sx][sy];
            else MAP[x + tx][y + ty] = MAP[x + tx][y + ty] + centerSend * send[sx][sy];
            
            MAP[x][y] = MAP[x][y] - centerSend * send[sx][sy];
        }
    }
    if(IsAsendPossible){
        MAP[ax][ay] = MAP[x][y];
        MAP[x][y] = 0;
    }
    else outsend = outsend + MAP[x][y];
}

void CopySend(){
    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 5; y++){
            continue;
        }
    }
}

void RotateCountClock(){
    float temp[5][5];
    
    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 5; y++){
            temp[x][y] = send[x][y];
        }
    }
    
    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 5; y++){
            send[4-x][y] = temp[y][x];
        }
    }
}

void DebugOutput(){
    cout << "\n";
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            cout << MAP[x][y] << " ";
        }
        cout << "\n";
    }
}
