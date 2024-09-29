#include <stdio.h> 
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int N, W;

typedef struct _Mine{
    int weight;
    int price;
}Mine;

Mine myMine[];

void Input();
void Swap();

int main(void)
{
    Input();
    
    sort(
    
    return 0;
}

void Input(){
    cin >> W >> N;
    Mine tempMine[N];
    for(int i = 0; i < N; i++){
        cin >> myMine[i].weight >> myMine[i].price;
    }
    
}

void Swap(){
    int max;
    Mine temp;
    
    for(int i = 0; i < N; i++){
        max = myMine[i].price;
        for(int sel = i+1; sel < N; sel++){
            if(max < myMine[sel].
        }
    }
}
