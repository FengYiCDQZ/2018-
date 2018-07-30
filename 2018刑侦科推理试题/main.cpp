//答案:BCACA CDABA
#include<cstdio>
#include<iostream>
#include<cmath>
#include<ctime>
#define FOR(k) for(ans[k]=1;ans[k]<=4;ans[k]++)

using namespace std;
const int Size = 10;
int ans[Size + 1];

bool check2()
{
	if (ans[5] == 3 && ans[2] == 1)return true;
	if (ans[5] == 4 && ans[2] == 2)return true;
	if (ans[5] == 1 && ans[2] == 3)return true;
	if (ans[5] == 2 && ans[2] == 4)return true;
	return false;
}

bool check3()
{
	if (ans[4] == ans[6] && ans[6] == ans[2] && ans[2] != ans[3] && ans[3] == 1) return true;
	if (ans[2] == ans[3] && ans[3] == ans[4] && ans[4] != ans[6] && ans[3] == 2) return true;
	if (ans[3] == ans[4] && ans[4] == ans[6] && ans[6] != ans[2] && ans[3] == 3) return true;
	if (ans[6] == ans[2] && ans[2] == ans[3] && ans[3] != ans[4] && ans[3] == 4) return true;
	return false;
}

bool check4()
{
	int cont = 0, temp;
	if (ans[1] == ans[5]) temp = 1, cont++;
	if (ans[2] == ans[7]) temp = 2, cont++;
	if (ans[1] == ans[9]) temp = 3, cont++;
	if (ans[6] == ans[10]) temp = 4, cont++;
	if (cont == 1 && ans[4] == temp) return true;
	return false;
}

bool check5()
{
	int cont = 0, temp;
	if (ans[8] == ans[5]) cont++, temp = 1;
	if (ans[4] == ans[5]) cont++, temp = 2;
	if (ans[9] == ans[5]) cont++, temp = 3;
	if (ans[7] == ans[5]) cont++, temp = 4;
	if (cont == 1 && ans[5] == temp) return true;
	return false;
}

bool check6()
{
	int cont = 0, temp;
	if (ans[2] == ans[4] && ans[4] == ans[8]) cont++, temp = 1;
	if (ans[1] == ans[6] && ans[6] == ans[8]) cont++, temp = 2;
	if (ans[3] == ans[10] && ans[10] == ans[8]) cont++, temp = 3;
	if (ans[5] == ans[9] && ans[9] == ans[8]) cont++, temp = 4;
	if (cont == 1 && ans[6] == temp) return true;
	return false;
}

bool check7()
{
	int temp;
	int cont[4 + 1], mi = 1000;
	for (int i = 0; i <= 4; i++) cont[i] = 0;
	for (int i = 1; i <= Size; i++) cont[ans[i]]++;
	for (int i = 1; i <= 4; i++) if (cont[i] < mi) mi = cont[i];
	if (cont[3] == mi) cont[0]++, temp = 1;
	if (cont[2] == mi) cont[0]++, temp = 2;
	if (cont[1] == mi) cont[0]++, temp = 3;
	if (cont[4] == mi) cont[0]++, temp = 4;
	if (cont[0] == 1 && ans[7] == temp) return true;
	return false;
}

bool check8()
{
	int cont = 0, temp;
	if (abs(ans[1] - ans[7]) != 1) cont++, temp = 1;
	if (abs(ans[1] - ans[5]) != 1) cont++, temp = 2;
	if (abs(ans[1] - ans[2]) != 1) cont++, temp = 3;
	if (abs(ans[1] - ans[10]) != 1) cont++, temp = 4;
	if (cont == 1 && ans[8] == temp) return true;
	return false;
}

bool check9()
{
	int cont = 0, temp;
	if ((ans[1] == ans[6]) ^ (ans[5] == ans[6])) cont++, temp = 1;
	if ((ans[1] == ans[6]) ^ (ans[5] == ans[10])) cont++, temp = 2;
	if ((ans[1] == ans[6]) ^ (ans[5] == ans[2])) cont++, temp = 3;
	if ((ans[1] == ans[6]) ^ (ans[5] == ans[9])) cont++, temp = 4;
	if (cont == 1 && ans[9] == temp) return true;
	return false;
}

bool check10()
{
	int ma = -1, mi = 1000, cont[4 + 1], temp;
	for (int i = 0; i <= 4; i++) cont[i] = 0;
	for (int i = 1; i <= Size; i++) cont[ans[i]]++;
	for (int i = 1; i <= 4; i++)
	{
		if (cont[i] > ma) ma = cont[i];
		if (cont[i] < mi) mi = cont[i];
	}
	if (ma - mi == 3) temp = 1;
	if (ma - mi == 2) temp = 2;
	if (ma - mi == 4) temp = 3;
	if (ma - mi == 1) temp = 4;
	if (ans[10] == temp) return true;
	return false;
}

bool check()
{
	if (check2() == false) return false;
	if (check3() == false) return false;
	if (check4() == false) return false;
	if (check5() == false) return false;
	if (check6() == false) return false;
	if (check7() == false) return false;
	if (check8() == false) return false;
	if (check9() == false) return false;
	if (check10() == false) return false;
	return true;
}

void print()
{
	for (int i = 1; i <= Size; i++)
		cout << char(ans[i] + 'A' - 1);
	cout << endl;
}

int main()
{
	FOR(1) FOR(2) FOR(3) FOR(4) FOR(5) FOR(6) FOR(7) FOR(8) FOR(9) FOR(10)
		if (check())
			print();
	cout << "用时" << clock() << "毫秒" << endl;
	system("pause");
}