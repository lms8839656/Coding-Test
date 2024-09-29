#include <iostream> 


#define MAX 3000

using namespace std;

int arr[MAX+1];
int N;

void Input();
void sol();

int cnt, maxnum, maxcnt;

int main(void)
{
    Input();
    sol();
    cout << maxcnt;
    return 0;
}

void Input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
}

void sol(){
    maxcnt = 0;
    for(int i = 1; i <= N; i++){
        maxnum = arr[i];
        cnt = 1;
        for(int j = i; j <= N; j++){
            if(arr[j] > maxnum){
                maxnum = arr[j];
                cnt++;
            }   
        }
        
        if(cnt > maxcnt) maxcnt = cnt;
    }
}
