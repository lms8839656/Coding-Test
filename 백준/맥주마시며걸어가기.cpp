#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

#define MAX 100

using namespace std;

int t, n, house_x, house_y, rock_x, rock_y;

typedef struct _Conv{
    int x;
    int y;
}Conv;

Conv myConv[MAX];
bool visited[MAX];
vector <bool>result;

void Input();
void BFS(int x, int y);
void Output();
void ResetVisited();

int main(void)
{
    
    cin >> t;
    for(int i = 0; i < t; i++){
        Input();
        BFS(house_x, house_y);
        ResetVisited();
    }
    Output();
    return 0;
}

void Input(){
    cin >> n >> house_x >> house_y;
    
    for(int i = 0; i < n; i++){
        cin >> myConv[i].x >> myConv[i].y;
    }
    
    cin >> rock_x >> rock_y;
}



void BFS(int x, int y){
    queue <pair<int, int> > q;
    q.push(make_pair(x, y));
    
    int nx, ny;
    
    while(!q.empty()){
        
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        if(abs(x - rock_x) + abs(y - rock_y) <= 1000){
            result.push_back(true);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(abs(myConv[i].x - x) + abs(myConv[i].y - y) > 1000 || visited[i]) continue;
            
            nx = myConv[i].x;
            ny = myConv[i].y;
            
            q.push(make_pair(nx, ny));
            visited[i] = true;
        }
    }
    
    result.push_back(false);
    
}

void Output(){
    for(int i = 0; i < result.size(); i++){
        if(result[i]) cout << "happy\n";
        else cout << "sad\n";
    }
}

void ResetVisited(){
    for(int i = 0; i < MAX; i++){
        visited[i] = false;
    }
}
