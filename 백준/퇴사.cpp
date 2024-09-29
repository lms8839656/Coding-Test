#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

int sum = 0;
int maxsum = 0;

vector <pair<int, int> > Table;
vector <bool> visited;
queue <int>q;

void Input();
void CalValue();
void DFS(int day);
void BFS(int day);
void ResetVisited();

void DebugOutput();

int main(void)
{
    Input();
    CalValue();
    cout << maxsum;
    //DebugOutput();
    
    return 0;
}


void Input(){
    int T, P;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> T >> P;
        Table.push_back(make_pair(T, P));
        visited.push_back(false);
    }
}

void CalValue(){
    for(int i = 0; i < Table.size(); i++){
        sum = 0;
        DFS(i);
    }
}

void DFS(int day){
    if(day + Table[day].first >= N){
        if(day + Table[day].first == N) sum = sum + Table[day].second;
        if(maxsum < sum) maxsum =  sum;
        if(day + Table[day].first == N) sum = sum - Table[day].second;
        return;
    }
    
    
    
    for(int i = day + Table[day].first; i < N; i++){
        sum = sum + Table[day].second;
        DFS(i);
        sum = sum - Table[day].second;
    }
}

void BFS(int day){
    visited[day] = true;
    sum = Table[day].second;
    q.push(day);
    
    while(Table.empty()){
        day = q.front() + Table[day].first;
        q.pop();
        
        if(day > Table.size()){
            if(sum > maxsum) maxsum = sum;
        }
        
        for(int i = day; i < Table.size(); i++){
            q.push(i);
            sum = sum + Table[day].second;
            visited[i] = true;
        }
    }
}

void ResetVisited(){
    for(int i = 0;  i < Table.size(); i++){
        visited[i] = false;
    }
}

void DebugOutput(){
    cout << "\n";
    for(int i = 0; i < Table.size(); i++){
        cout << Table[i].first << " ";
    }
    cout << "\n";
    cout << maxsum;
}








/*
#include <iostream>
#include <stdio.h>

#include MAX 15

void Input();
void Output();
void CalBenefit();

int N;
int answer;
int sum;

typedef struct _Table{
    int T;
    int P;
}Table;

Table myTable[MAX];

int main(void)
{

    return 0;
} 


void Input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        Cin >> myTable[i].T >> myTable[i].P;
    }
}

void Output(){
    cout << answer;
}

void CalBenefit(){
    
    int tempT;
    
    for(int i = 0; i < N; i++){
        if(myTable[i + 1] == NULL) break;
    }
}
*/
