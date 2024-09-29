#include <stdio.h>
#include <iostream>

#define MAX 20

using namespace std;

int N, M;
int MAP[MAX + 1][MAX + 1];
int visited[MAX + 1][MAX + 1];
int tempMAP[MAX + 1][MAX + 1];
int maxsize;
int cntsize;
int zerosize;
int score = 0;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

typedef struct _Group {
    int x;
    int y;
    int size;
    int rainbow;
    int color;
}Group;

Group maxGroup;

void Input();
void Groupping(int x, int y);
void DFS(int x, int y, int color);
void ResetZeroSpace();
void EraseGroup(int x, int y, int color);
void ResetMAPVisitied();
void Gravity();
void Turn();
void DebugOutput();


int main(void)
{
    Input();
    do {
        maxsize = 1;
        //find maxgroup
        ResetMAPVisitied();
        for (int x = 1; x <= N; x++) {
            for (int y = 1; y <= N; y++) {
                Groupping(x, y);
            }
        }
        if (maxsize == 1) break;
        
        ResetMAPVisitied();
        EraseGroup(maxGroup.x, maxGroup.y, maxGroup.color);
        score = score + maxGroup.size * maxGroup.size;
        Gravity();
        Turn();
        Gravity();
    } while (maxsize > 1);


    cout << score;
    return 0;
}

void Input() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> MAP[i][j];
        }
    }
}

void DebugOutput() {
    cout << "\n";
    cout << "score : " << score << "\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
}

void Groupping(int x, int y) {
    int color = MAP[x][y];
    cntsize = 0;
    zerosize = 0;
    if (visited[x][y] || MAP[x][y] == -1 || MAP[x][y] == 8 || MAP[x][y] == 0) return;

    DFS(x, y, color);

    if (cntsize == 1) return;
    else if (cntsize > maxsize) {
        maxsize = cntsize;
        maxGroup.x = x;
        maxGroup.y = y;
        maxGroup.size = maxsize;
        maxGroup.color = color;
        maxGroup.rainbow = zerosize;

    }
    else if (cntsize == maxsize) {
        if (zerosize >= maxGroup.rainbow) {
            maxsize = cntsize;
            maxGroup.x = x;
            maxGroup.y = y;
            maxGroup.size = maxsize;
            maxGroup.color = color;
            maxGroup.rainbow = zerosize;
        }
    }

    ResetZeroSpace();
}

void DFS(int x, int y, int color) {
    visited[x][y] = true;
    cntsize++;
    if (MAP[x][y] == 0) zerosize++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
        if (!visited[nx][ny] && (MAP[nx][ny] == color || MAP[nx][ny] == 0)) DFS(nx, ny, color);
    }
}

void ResetZeroSpace() {
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            if (MAP[x][y] == 0) visited[x][y] = false;
        }
    }
}

void EraseGroup(int x, int y, int color) {
    visited[x][y] = true;
    MAP[x][y] = 8;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
        if (!visited[nx][ny] && (MAP[nx][ny] == color || MAP[nx][ny] == 0)) EraseGroup(nx, ny, color);
    }
}

void ResetMAPVisitied() {
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            visited[x][y] = false;
        }
    }
}

void Gravity() {
    int temp;
    for (int x = N - 1; x >= 1; x--) {
        for (int y = N; y >= 1; y--) {
            if (MAP[x][y] == -1 || MAP[x][y] == 8) continue;

            temp = x;
            while (MAP[temp + 1][y] == 8) {
                if (MAP[temp + 1][y] == -1) break;
                MAP[temp + 1][y] = MAP[temp][y];
                MAP[temp][y] = 8;
                temp++;
            }
        }
    }
}


void Turn() {
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            tempMAP[x][y] = MAP[x][y];
        }
    }

    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            MAP[x][y] = tempMAP[y][N - x + 1];
        }
    }
}

