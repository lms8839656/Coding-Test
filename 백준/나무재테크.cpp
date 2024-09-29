#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10

using namespace std;

int MAP[MAX+1][MAX+1];
int tempMAP[MAX+1][MAX+1];
int A[MAX+1][MAX+1];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N, M, K;

typedef struct _Tree{
    int year;
    int x;
    int y;
    bool IsDeath;
}Tree;

vector <Tree> myTree;

void Init();
void Input();
bool SortYear(Tree a, Tree b);
void Spring();
void Summer();
void Fall();
void Winter();

void DebugOutput();

int main(void)
{
    Input();
    Init();
    sort(myTree.begin(), myTree.end(), SortYear);
    while(K){
        Spring();
        Summer();
        Fall();
        Winter();
        K--;
    }
    //DebugOutput();
    cout << myTree.size();
    return 0;
}

void Init(){
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            MAP[x][y] = 5;
        }
    }
}

void Input(){
    cin >> N >> M >> K;
    
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            cin >> A[x][y];
        }
    }
    
    Tree tempTree;
    for(int i = 0; i < M; i++){
        cin >> tempTree.x >> tempTree.y >> tempTree.year;
        myTree.push_back(tempTree);
    }
}

bool SortYear(Tree a, Tree b){
    return a.year < b.year;
}

void Spring(){
    int x, y;
    for(int i = 0; i < myTree.size(); i++){
        x = myTree[i].x;
        y = myTree[i].y;
        if(myTree[i].year > MAP[x][y]){
            myTree[i].IsDeath = true;
        }
        else{
            MAP[x][y] = MAP[x][y] - myTree[i].year;
            myTree[i].year++;
        } 
    }
}

void Summer(){
    int x, y;
    for(int i = 0; i < myTree.size(); i++){
        if(myTree[i].IsDeath == true){
            x = myTree[i].x;
            y = myTree[i].y;
            MAP[x][y] = MAP[x][y] + myTree[i].year / 2;
            myTree.erase(myTree.begin() + i);
            i = i - 1;
        }
    }
}

void Fall(){
    int x, y, nx, ny;
    Tree tempTree;
    for(int i = 0; i < myTree.size(); i++){
        if(myTree[i].year % 5 == 0 && myTree[i].year != 0){
            x = myTree[i].x;
            y = myTree[i].y;
            for(int i = 0; i < 8; i++){
                nx = x + dx[i];
                ny = y + dy[i];
                if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
                tempTree.x = nx;
                tempTree.y = ny;
                tempTree.year = 1;
                myTree.push_back(tempTree);
            }
        }
    }
}

void Winter(){
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            MAP[x][y] = MAP[x][y] + A[x][y];
        }
    }
}

void DebugOutput(){
    cout << "myTree Size :" << myTree.size() << "\n";
    for(int i = 0; i < myTree.size(); i++){
        cout << myTree[i].x << " " << myTree[i].y << " " << myTree[i].year << " " << 
        myTree[i].IsDeath << "\n";
    }
}

