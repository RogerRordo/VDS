//注意：T必须可流输出
/**
*  @File: VDS.h$
*  Visualization of Data Structure
*  @Author: RogerRo
*  @Data: 2017/09/10
*/

#ifndef VDS_h
#define VDS_h

#include<GL/glut.h>
#include<boost/any.hpp>
#include<fstream>
#include<vector>
#include<string>
#include<assert.h>

#define VDS_DotFILE "temp.dot" 
#define VDS_PngFILE "temp.png" 
#define VDS_DotConf "VDS/conf"
#define OldNodePrefix "YwK7O1nF"

class VDS
{
public:
	typedef boost::any T;
	typedef std::vector<std::pair<T,T> > Property;
	bool Directed=0;
	bool ShowOld=1;
	bool HighlightDiff=1;
	
private:
	struct _Vertex
	{
		T x;
		Property Prop;
		int Highlight;
		bool operator!=(_Vertex _);
	};
	std::vector<_Vertex> OldVertex,Vertex;
	struct _Edge
	{
		T x,y;
		Property Prop;
		int Highlight;
		bool operator!=(_Edge _);
	};
	std::vector<_Edge> OldEdge,Edge;
	
	bool CheckDiff();
	void WriteDot();
	void FHighlightDiff();
	void _ClearV(std::vector<_Vertex> &a);
	void _ClearE(std::vector<_Edge> &a);
	
public:
	void AddVertex(const T &x,Property &Prop,const bool Highlight=0);
	void AddEdge(const T &x,const T &y,Property &Prop,const bool Highlight=0);
	void Show();
	void Clear();
};

#endif
