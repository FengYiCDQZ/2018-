#include<cstdio>
#include<iostream>
#include<camth>
#define FOR(k) for(int ans[k]=1;ans[k]<=4;ans[k]++)

using namespace std;
const int Size = 10 + 1;
int ans[Size];

bool check3()
{
	//2346题有且只有一个与的答案其他不同
	if (ans[3] == ans[4] && ans[4] == ans[6] && ans[6] != ans[2]) return true;//2不同
	if (ans[4] == ans[6] && ans[6] == ans[2] && ans[2] != ans[3]) return true;//3不同
	if (ans[6] == ans[2] && ans[2] == ans[3] && ans[3] != ans[4]) return true;//4不同
	if (ans[2] == ans[3] && ans[3] == ans[4] && ans[4] != ans[6]) return true;//6不同
	return false;
}

bool check()
{
	if (check3() == false) return false;
}

int main()
{
	FOR(1) FOR(2) FOR(3) FOR(4) FOR(5) FOR(6) FOR(7) FOR(8) FOR(9) FOR(10) check();
}