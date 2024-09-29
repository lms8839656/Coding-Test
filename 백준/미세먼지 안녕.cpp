#include <stdio.h>
#include <iostream>

#define MAX 50

using namespace std;

int MAP[MAX][MAX];
int tempMAP[MAX][MAX];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void Input();
void DebugOutput();
void CopyMAP();
void Spread(int x, int y);
void RunAir();
void SumDust();
void tempReset();

int R, C, T;
bool CheckUpDown;
int xUpAir;
int yUpAir;
int xDownAir;
int yDownAir;
int sum;

int main(void)
{
    Input();

    
    
    while(T>0){
        T = T-1;
        for(int x = 0; x < R; x++){
            for(int y = 0; y < C; y++){
                if(MAP[x][y] > 0) Spread(x, y);
            }
        }
        CopyMAP();
        //DebugOutput();
        RunAir();
        CopyMAP();
        tempReset();
    }
    //DebugOutput();
    
    SumDust();
    cout << sum;
    
    return 0;
}


void Input(){
    cin >> R >> C >> T;
    for(int x = 0; x < R; x++){
        for(int y = 0; y < C; y++){
            cin >> MAP[x][y];
            if(MAP[x][y] == -1 && CheckUpDown == false){
                xUpAir = x;
                yUpAir = y;
                CheckUpDown = true;
            }
            else if(MAP[x][y] == -1 && CheckUpDown == true){
                xDownAir = x;
                yDownAir = y;
            }
        }
    }
}

void DebugOutput(){
    
    
    cout << "\nMAP\n";
    for(int x = 0; x < R; x++){
        for(int y = 0; y < C; y++){
            cout << MAP[x][y] << " ";
        }
        cout << "\n";
    }
    
    cout << "\ntempMAP\n";
    for(int x = 0; x < R; x++){
        for(int y = 0; y < C; y++){
            cout << tempMAP[x][y] << " ";
        }
        cout << "\n";
    }
}

void CopyMAP(){
    tempMAP[xUpAir][yUpAir] = -1;
    tempMAP[xDownAir][yDownAir] = -1;
    
    for(int x = 0; x < R; x++){
        for(int y = 0; y < C; y++){
            MAP[x][y] = tempMAP[x][y];
        }
    }
}

void Spread(int x, int y){
    int nx, ny;
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= R || ny >= C || MAP[nx][ny] < 0) continue;
        
        tempMAP[nx][ny] = MAP[x][y] / 5 + tempMAP[nx][ny];
        cnt++;        
    }
    tempMAP[x][y] = (MAP[x][y] - MAP[x][y] / 5 * cnt) + tempMAP[x][y];
}

void RunAir(){
    
    //tempMAP[xDownAir][yDownAir+1] = 0;
    
    int x = xUpAir;
    int y = yUpAir;
    
    int cnt = 0;
    while(cnt < 4){
        switch(cnt){
            case 0:
                tempMAP[x][y+1] = MAP[x][y];
                y++;
                if(y+1 >= C) cnt++;
                break;
            case 1:
                tempMAP[x-1][y] = MAP[x][y];
                x--;
                if(x-1 < 0) cnt++;
                break;
            case 2:
                tempMAP[x][y-1] = MAP[x][y];
                y--;
                if(y-1 < 0) cnt++;
                break;
            case 3:
                tempMAP[x+1][y] = MAP[x][y];
                x++;
                if(x+1 >= xUpAir) cnt++;
                break;
                
        }
    }
    
    x = xDownAir;
    y = yDownAir;
    cnt = 0;
    while(cnt < 4){
        switch(cnt){
            case 0:
                tempMAP[x][y+1] = MAP[x][y];
                y++;
                if(y+1 >= C) cnt++;
                break;
            case 1:
                tempMAP[x+1][y] = MAP[x][y];
                x++;
                if(x+1 >= R) cnt++;
                break;
            case 2:
                tempMAP[x][y-1] = MAP[x][y];
                y--;
                if(y-1 < 0) cnt++;
                break;
            case 3:
                tempMAP[x-1][y] = MAP[x][y];
                x--;
                if(x-1 < xUpAir) cnt++;
                break;
                
        }
    }
    
    tempMAP[xUpAir][yUpAir] = -1;
    tempMAP[xUpAir][yUpAir+1] = 0;
    tempMAP[xDownAir][yDownAir] = -1;
    tempMAP[xDownAir][yDownAir+1] = 0;
}

void SumDust(){
    sum = 0;
    for(int x = 0; x < R; x++){
        for(int y = 0; y < C; y++){
            if(MAP[x][y] > 0) sum = sum + MAP[x][y];
        }
    }
}

void tempReset(){
    for(int x = 0; x < R; x++){
        for(int y = 0; y < C; y++){
            tempMAP[x][y] = 0;
        }
    }
}
