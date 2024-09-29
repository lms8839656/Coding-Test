#include <iostream>
#include <vector>

using namespace std;

int TC, TCn, n;

int score[100+1];
int maxVal;
vector <int>v;


void Sol();
void SearchMaxValue();
void ResetScore();
void Output();

int main()
{
    Sol();
    Output();
    return 0;
} 

void Sol(){
    cin >> TC;
    int temp;
    
    for(int x = 0; x < TC; x++){
        cin >> TCn;
        for(int i = 0; i < 1000; i++){
            cin >> temp;
            score[temp]++;
        } 
        
        SearchMaxValue();
        ResetScore();
    }
}

void SearchMaxValue(){
    maxVal = 0;
    int maxNum = 0;
    for(int i = 100; i >= 0; i--){
        if(score[i] > maxVal){
            maxVal = score[i];
            maxNum = i;   
        }
    }
    v.push_back(maxNum);
}

void ResetScore(){
    for(int i = 0; i <= 100; i++){
        score[i] = 0;
    }
    maxVal = 0;
}

void Output(){
    for(int i = 0; i < TC; i++){
        cout << "#" << i+1 << " " << v[i] << "\n";
    }
}
