#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

#define MAX 20

using namespace std;

int MAP[MAX + 1][MAX + 1];
int likescore[MAX + 1][MAX + 1];

int N;
int SatyPoint = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

typedef struct _Student {
    int num;
    int favorite[4];
}Student;

Student myStudent[MAX + 1];

void Input();
void Run();
void SearchPlace();
void ReSetMap();
void CalSatyPoint();


void DebugOutput();

int main(void)
{
    Input();
    ReSetMap();
    SearchPlace();
    DebugOutput();
    CalSatyPoint();
    cout << SatyPoint;
    return 0;
}

void Input() {
    cin >> N;
    for (int i = 1; i <= N * N; i++) {
        cin >> myStudent[i].num;
        for (int j = 0; j < 4; j++) {
            cin >> myStudent[i].favorite[j];
        }
    }
}


void SearchPlace() {
    int nx, ny;
    int setxfav, setyfav;
    int setxvoid, setyvoid;
    int cntFavStd = 0;
    int cntVoid = 0;
    int tempFavStd = 0;
    int tempVoid = 0;
    int cntFavVoid = 0;

    for (int k = 1; k <= N * N; k++) {
        for (int x = 1; x <= N; x++) {
            for (int y = 1; y <= N; y++) {
                for (int i = 0; i < 4; i++) {
                    nx = x + dx[i];
                    ny = y + dy[i];
                    if (nx < 1 || ny < 1 || nx > N || ny > N) continue;


                    for (int j = 0; j < 4; j++) {
                        if (MAP[nx][ny] == myStudent[k].favorite[j]) tempFavStd++;
                    }

                    if (MAP[nx][ny] == 0) tempVoid++;
                }

                if (tempVoid > cntVoid) {
                    cntVoid = tempVoid;
                    setxvoid = x;
                    setyvoid = y;
                }

                if (tempFavStd > cntFavStd && MAP[x][y] == 0) {
                    cntFavStd = tempFavStd;
                    cntFavVoid = tempVoid;
                    setxfav = x;
                    setyfav = y;
                }

                if (tempFavStd == cntFavStd && MAP[x][y] == 0) {
                    if (tempVoid > cntFavVoid) {
                        cntFavStd = tempFavStd;
                        cntFavVoid = tempVoid;
                        setxfav = x;
                        setyfav = y;
                    }
                }
                tempFavStd = 0;
                tempVoid = 0;
            }
        }

        if (cntFavStd) {
            MAP[setxfav][setyfav] = myStudent[k].num;
        }
        else MAP[setxvoid][setyvoid] = myStudent[k].num;
        cntFavStd = 0;
        cntVoid = 0;
    }
}

void DebugOutput() {
    /*
    cout << N << "\n";
    for(int i = 1; i <= N; i++){
        cout << myStudent[i].num << " ";
        for(int j = 0; j < 4; j++){
            cout << myStudent[i].favorite[j] << " ";
        }
        cout << "\n";
    }
    */
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }

}

void ReSetMap() {
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            MAP[i][j] = 0;
        }
    }
}

void CalSatyPoint() {

    int cnt = 0;
    int nx, ny;
    int selStudent;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            for (int k = 1; k <= N * N; k++) {
                if (MAP[x][y] == myStudent[k].num) {
                    selStudent = k;
                    break;
                }
            }

            for (int i = 0; i < 4; i++) {
                nx = x + dx[i];
                ny = y + dy[i];
                if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
                
                for (int j = 0; j < 4; j++) {
                    if (MAP[nx][ny] == myStudent[selStudent].favorite[j]) cnt++;
                }
            }


            switch (cnt) {
            case 0:
                SatyPoint = SatyPoint + 0;
                break;
            case 1:
                SatyPoint = SatyPoint + 1;
                break;
            case 2:
                SatyPoint = SatyPoint + 10;
                break;
            case 3:
                SatyPoint = SatyPoint + 100;
                break;
            case 4:
                SatyPoint = SatyPoint + 1000;
                break;
            }

            cnt = 0;
        }
    }
}
