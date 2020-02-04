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
//kruskal有向图
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
vector<EdgeStruct> edgeVector;   //存放所有已经按大小排好序的边的结构体
vector<EdgeStruct> minTree;      //存放最小生成树用来输出的vector
int endPoint[7] = { -1, -1, -1, -1, -1, -1, -1 };//用来记录各顶点的终点
bool sortWay(EdgeStruct start, EdgeStruct end) //此处应该传结构体类型的参数
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
		cout << map[start] << " 的终点为：" << map[startEnd] << endl;
		cout << map[end] << " 的终点为 ：" << map[endEnd] << endl;;
		cout << "---------------" << endl;
		if (startEnd != endEnd)
		{
			cout << map[start] << "的终点和" << map[end] << "的终点不相同" << endl;
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