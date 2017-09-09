#include<bits/stdc++.h>
#include "VDS/VDS.h"
#define maxn 100
#define maxm 10000
#define tr(i,l,r) for(i=(l);i<=(r);i++)
using namespace std;

int n,m,V[maxn],ah[maxn];
struct edge{int x,y,pre,E;} a[maxm];

void VDS_SHOW()	//DG
{
	static VDS VDS0;
	static VDS::Property P;
	typedef VDS::T T;
	
	VDS0.Directed=1;
	
	int i;
	tr(i,1,n) 
	{
		P.clear();
		P.push_back(make_pair("V",V[i]));
		VDS0.AddVertex((T)i,P);
	}
	tr(i,1,m) 
	{
		P.clear();
		P.push_back(make_pair("E",a[i].E));
		VDS0.AddEdge((T)a[i].x,(T)a[i].y,P);
	}
	
	VDS0.Show();
}

void newedge(int x,int y,int z)
{
	m++;
	a[m].x=x; a[m].y=y; a[m].pre=ah[x]; ah[x]=m;
	a[m].E=z;
}
void init()
{
	int mm,i,x,y,z;
	scanf("%d%d",&n,&mm);
	tr(i,1,n) scanf("%d",&V[i]);
	tr(i,1,mm)
	{
		scanf("%d%d%d",&x,&y,&z);
		newedge(x,y,z);
	}
}
void work()
{
	int tot=0,i;
	srand(time(0));
	for(;tot<=10;)
	{
		//VDS_SHOW();
		//tot++; cout<<tot<<endl;
		//VDS_SHOW();
		tot++; cout<<tot<<endl;
		tr(i,1,n) V[i]=rand()%10; cout<<"CV"<<endl;
		//VDS_SHOW(); 
		tr(i,1,m) a[i].E=rand()%10; cout<<"CE"<<endl;
		//VDS_SHOW();
	}
}
int main()
{
	freopen("test.in","r",stdin);
	init();
	work();
	return 0;
}
