#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct  EdgeData
{
	int start;
	int end;
	int weight;
}EdgeStruct;
char map[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
//kruskal����ͼ
int K[7][7] = {
	//j:  A, B, C, D, E, F, G   i
	{ 0, 12, 0, 0, 0, 16, 14 },//A
	{ 0, 0, 10, 0, 0, 7, 0 },//B
	{ 0, 0, 0, 3, 5, 6, 0 },//C
	{ 0, 0, 0, 0, 4, 0, 0 },//D
	{ 0, 0, 0, 0, 0, 2, 8 },//E
	{ 0, 0, 0, 0, 0, 0, 9 },//F
	{ 0, 0, 0, 0, 0, 0, 0 } //G
};
vector<EdgeStruct> edgeVector;   //��������Ѿ�����С�ź���ıߵĽṹ��
vector<EdgeStruct> minTree;      //�����С���������������vector
int endPoint[7] = { -1, -1, -1, -1, -1, -1, -1 };//������¼��������յ�
bool sortWay(EdgeStruct start, EdgeStruct end) //�˴�Ӧ�ô��ṹ�����͵Ĳ���
{
	if (start.weight < end.weight)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int getEnd(int temp)
{
	while (endPoint[temp] != -1)
	{
		temp = endPoint[temp];
	}
	return temp;
}
void printEndPoint()
{
	cout << "A\tB\tC\tD\tE\tF\tG" << endl;
	for (int i = 0; i < 7; i++)
	{
		if (endPoint[i] == -1)
		{
			cout << "-1\t";
		}
		else
		{
			cout <<map[endPoint[i]]<<"\t";
		}
	}
	cout << endl;
}
void Kruskal()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (K[i][j] != 0)
			{
				EdgeStruct e;
				e.start = i;
				e.end = j;
				e.weight = K[i][j];
				edgeVector.push_back(e);
			}
		}
	}
	sort(edgeVector.begin(), edgeVector.end(), sortWay);
	for (int i = 0; i < edgeVector.size(); i++)
	{
		int start = edgeVector[i].start;
		int end = edgeVector[i].end;
		int startEnd = getEnd(start);
		int endEnd = getEnd(end);
		printEndPoint();
		cout << map[start] << " ���յ�Ϊ��" << map[startEnd] << endl;
		cout << map[end] << " ���յ�Ϊ ��" << map[endEnd] << endl;;
		cout << "---------------" << endl;
		if (startEnd != endEnd)
		{
			cout << map[start] << "���յ��" << map[end] << "���յ㲻��ͬ" << endl;
			cout << "------------------------------" << endl;
			minTree.push_back(edgeVector[i]);
			endPoint[startEnd] = endEnd;
		}
	}
	for (int i = 0; i < minTree.size(); i++)
	{
		cout << map[minTree[i].start] << " ---> " << map[minTree[i].end] << " " << minTree[i].weight << " " << endl;
	}
}
void Prim()
{
}
int main()
{
	Kruskal();
	return 0;
}