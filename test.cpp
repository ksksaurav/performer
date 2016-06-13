#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>
#define INT_MAX 100001

typedef long long int li;

using namespace std;

class Test{
public:
	int a;
};

class comp{
public:
	bool rev;
	comp(bool &re = false){
		this-> rev = re;
	}
	bool operator () (Test &t1, Test &t2){
		return t1.a < t2.a;
	}
};

int main(){
	priority_queue<Test, vactor<Test>, comp> que;
	Test t1,t2;
	t1.a = 3;
	t2.a = 5;
	que.push(t1);
	queue.push(t2);

	cout << que.top().a;
}