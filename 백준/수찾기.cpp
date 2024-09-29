#include <iostream>

#define MAX 100000

using namespace std;

int A[MAX];
int M[MAX];
bool visited[MAX];

int N, Mn;

void Input();
void SearchNum();

int main(void)
{
    Input();
    SearchNum();
    return 0;
}

void Input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    cin >> Mn;
    for(int i = 0; i < Mn; i++){
        cin >> M[i];
    }
}

void SearchNum(){
    bool Flag = false;
    for(int i = 0; i < Mn; i++){
        Flag = false;
        for(int j = 0; j < N; j++){
            if(M[i] == A[j]){
                cout << "1\n";
                Flag = true;
                break;
            }
        }
        if(Flag == false){
            cout << "0\n";
        }
    }
}
