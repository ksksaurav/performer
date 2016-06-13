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

	bool operator() (const Test &t1, const Test &t2) const{
		return t1.a < t2.a;
	}
};

int main(){
	priority_queue<Test, vector<Test>, comp> que;
	Test t1,t2;
	t1.a = 3;
	t2.a = 5;
	que.push(t1);
	que.push(t2);
	t1.a = 8;
	que.push(t1);
	que.pop();
	cout << que.top().a;
}