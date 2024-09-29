#include <iostream>
#include <vector>

using namespace std;

int MAP[1000];

void Input();
void Sol();
void Output();

int N;

vector <int>v;
int dx[4] = {-2, -1, 1, 2};
int cnt = 0;

int main()
{
    
    for(int x = 0; x < 10; x++){
        Input();
        Sol();
        v.push_back(cnt);
    }
    Output();

    return 0;
}

void Input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> MAP[i];
    }
}

void Sol(){
    int MAX, nx;
    cnt = 0;
    for(int i = 2; i < N - 2; i++){
        MAX = 0;
        for(int j = 0; j < 4; j++){
            nx = i + dx[j];
            if(MAX < MAP[nx]){
                MAX = MAP[nx];
            }
        }
        
        if(MAP[i] <= MAX) continue;
        else cnt = cnt + MAP[i] - MAX;
    }
}

void Output(){
    for(int i = 1; i <= v.size(); i++){
        cout << "#" << i << " " << v[i-1] << "\n";
    }
}
