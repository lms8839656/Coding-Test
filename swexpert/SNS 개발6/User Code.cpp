#include <iostream>

#define MAX 10000+1
#define MAXL	5
#define MAXF	10

using namespace std;

typedef struct _User{
	int id;
	int ids[MAX];
};

User myUser[MAX];
int n_User = 0;

void init(int N)
{
	cin >> n_User;
}

void add(int id, int F, int ids[MAXF])
{
	for(int i = 0; i < F; i++){
		myUser[id].ids[i] = true;
		myUser[i].ids[id] = true;
	}
}

void del(int id1, int id2)
{
	myUser[id1].ids[id2] = false;
	myUser[id2].ids[id1] = false;
}

int recommend(int id, int list[MAXL])
{
	return 0;
}
