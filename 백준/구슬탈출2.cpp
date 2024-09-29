#include <iostream>
#include <queue>
#include <vector>
#include <string>

#define MAX 10

using namespace std;

char MAP[MAX][MAX];
char tempMAP[MAX][MAX];
bool visited[MAX][MAX];

int N, M;

queue <int> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

typedef struct _Ball{
    int x;
    int y;
}Ball;

Ball red;
Ball blue;

void Input();
void CopyMap();
void BFS(int x);
void MoveBall();

void DebugOutput();

int main(void)
{
    Input();
    MoveBall();
    DebugOutput();
    
    return 0;
}

void Input(){
    string s;
    
    cin >> N >> M;
    
    for(int x = 0; x < N; x++){
        cin >> s;
        for(int y = 0; y< N; y++){
            MAP[x][y] = s[y];
            
            if(MAP[x][y] == 'R'){
                red.x = x;
                red.y = y;
            }
            
            if(MAP[x][y] == 'B'){
                blue.x = x;
                blue.y = y;
            }
        }
    }
}

void CopyMap(){
    
}

void BFS(int x){
    q.push(x);
    int nx;
    
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            
            
        }
    }
}

void MoveBall(){
    int ny;
    
    int x;
    
    if(red.y < blue.y){
        x = red.x;
        ny = red.y;
        MAP[x][ny] = '.';
        while(MAP[x][ny] == '.'){
            ny = red.y + dy[4];
        }
        red.y = ny;
        
        x = blue.x;
        ny = blue.y;
        MAP[x][ny] = '.';
        while(MAP[x][ny] == '.'){
            ny = blue.y + dy[4];
        }
        blue.y = ny;
    }
    else{
        x = blue.x;
        ny = blue.y;
        MAP[x][ny] = '.';
        while(MAP[x][ny] == '.'){
            ny = blue.y + dy[4];
        }
        blue.y = ny;
        
        x = red.x;
        ny = red.y;
        MAP[x][ny] = '.';
        while(MAP[x][ny] == '.'){
            ny = red.y + dy[4];
        }
        red.y = ny;
    }
    
    MAP[x][red.y] = 'R';
    MAP[x][blue.y] = 'B';


}

void DebugOutput(){
    cout << "\n";
    for(int x = 0; x < N; x++){
        for(int y = 0; y< N; y++){
            cout << MAP[x][y];
        }
        cout << "\n";
    }
}
