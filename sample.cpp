#include<bits/stdc++.h>
#include "VDS/VDS.h"
#define maxn 100
#define maxm 10000
#define tr(i,l,r) for(i=(l);i<=(r);i++)
using namespace std;

int n,m,V[maxn],ah[maxn],id[maxn],od[maxn];
struct edge{int x,y,pre,d;} a[maxm];

void newedge(int x,int y,int d)
{
	m++;
	a[m].x=x; a[m].y=y; a[m].pre=ah[x]; ah[x]=m;
	a[m].d=d; id[y]++; od[x]++;
}
int main()
{
	n=10; srand(time(0));
	for(int i=1;i<=20;) 
	{
		newedge(rand()%n+1,rand()%n+1,rand()%10);
		i++;
	}
	return 0;
}

void VDS_SHOW()	//DG
{
	static VDS VDS0;
	static VDS::Property P;
	typedef VDS::T T;
	
	VDS0.Directed=1;
	VDS0.ShowOld=1;
	VDS0.HighlightDiff=1;
	
	int i;
	tr(i,1,n) 
	{
		P.clear();
		P.push_back(make_pair("id",id[i]));
		P.push_back(make_pair("od",od[i]));
		VDS0.AddVertex((T)i,P);
	}
	tr(i,1,m) 
	{
		P.clear();
		P.push_back(make_pair("d",a[i].d));
		VDS0.AddEdge((T)a[i].x,(T)a[i].y,P);
	}
	
	VDS0.Show();
}
