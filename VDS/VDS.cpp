/**
*  @File: VDS.cpp$
*  Visualization of Data Structure
*  @Author: RogerRo
*  @Data: 2017/09/10
*/

#include "VDS.h"

std::ostream &operator<<(std::ostream &out,const boost::any &a)
{
	using namespace std;
	if (a.type()==typeid(bool)) out<<boost::any_cast<bool>(a);
	else if (a.type()==typeid(short)) out<<boost::any_cast<short>(a);
	else if (a.type()==typeid(unsigned short)) out<<boost::any_cast<unsigned short>(a);
	else if (a.type()==typeid(int)) out<<boost::any_cast<int>(a);
	else if (a.type()==typeid(unsigned int)) out<<boost::any_cast<unsigned int>(a);
	else if (a.type()==typeid(long)) out<<boost::any_cast<long>(a);
	else if (a.type()==typeid(unsigned long)) out<<boost::any_cast<unsigned long>(a);
	else if (a.type()==typeid(long long)) out<<boost::any_cast<long long>(a);
	else if (a.type()==typeid(unsigned long long)) out<<boost::any_cast<unsigned long long>(a);
	else if (a.type()==typeid(float)) out<<boost::any_cast<float>(a);
	else if (a.type()==typeid(double)) out<<boost::any_cast<double>(a);
	else if (a.type()==typeid(long double)) out<<boost::any_cast<long double>(a);
	else if (a.type()==typeid(void*)) out<<boost::any_cast<void*>(a);
	else if (a.type()==typeid(streambuf*)) out<<boost::any_cast<streambuf*>(a);
	
	else if (a.type()==typeid(string)) out<<boost::any_cast<string>(a);
	else if (a.type()==typeid(char*)) out<<boost::any_cast<char*>(a);
	else if (a.type()==typeid(const char*)) out<<boost::any_cast<const char*>(a);
	else assert(0);
	//else if (a.type()==typeid(ostream&)) out<<boost::any_cast<ostream&>(a);
	//else if (a.type()==typeid(ios&)) out<<boost::any_cast<ios&>(a);
	//else if (a.type()==typeid(ios_base&)) out<<boost::any_cast<ios_base&>(a);
	return out;
}

bool operator==(const boost::any a,const boost::any b)
{
	using namespace std;
	if (a.type()==typeid(bool)) return boost::any_cast<bool>(a)==boost::any_cast<bool>(b);
	else if (a.type()==typeid(short)) return boost::any_cast<short>(a)==boost::any_cast<short>(b);
	else if (a.type()==typeid(unsigned short)) return boost::any_cast<unsigned short>(a)==boost::any_cast<unsigned short>(b);
	else if (a.type()==typeid(int)) return boost::any_cast<int>(a)==boost::any_cast<int>(b);
	else if (a.type()==typeid(unsigned int)) return boost::any_cast<unsigned int>(a)==boost::any_cast<unsigned int>(b);
	else if (a.type()==typeid(long)) return boost::any_cast<long>(a)==boost::any_cast<long>(b);
	else if (a.type()==typeid(unsigned long)) return boost::any_cast<unsigned long>(a)==boost::any_cast<unsigned long>(b);
	else if (a.type()==typeid(long long)) return boost::any_cast<long long>(a)==boost::any_cast<long long>(b);
	else if (a.type()==typeid(unsigned long long)) return boost::any_cast<unsigned long long>(a)==boost::any_cast<unsigned long long>(b);
	else if (a.type()==typeid(float)) return boost::any_cast<float>(a)==boost::any_cast<float>(b);
	else if (a.type()==typeid(double)) return boost::any_cast<double>(a)==boost::any_cast<double>(b);
	else if (a.type()==typeid(long double)) return boost::any_cast<long double>(a)==boost::any_cast<long double>(b);
	else if (a.type()==typeid(void*))return boost::any_cast<void*>(a)==boost::any_cast<void*>(b);
	else if (a.type()==typeid(streambuf*)) return boost::any_cast<streambuf*>(a)==boost::any_cast<streambuf*>(b);
	
	else if (a.type()==typeid(string)) return boost::any_cast<string>(a)==boost::any_cast<string>(b);
	else if (a.type()==typeid(char*)) return strcmp(boost::any_cast<char*>(a),boost::any_cast<char*>(b))==0;
	else if (a.type()==typeid(const char*)) return strcmp(boost::any_cast<const char*>(a),boost::any_cast<const char*>(b))==0;
	else assert(0);
}

bool operator!=(const boost::any a,const boost::any b)
{
	return !(a==b);
}

//

bool VDS::_Vertex::operator!=(_Vertex _)
{
	if (x!=_.x) return 1;
	if (Prop.size()!=_.Prop.size()) return 1;
	for(auto it=Prop.begin(),_it=_.Prop.begin();it!=Prop.end();it++,_it++)
		if (it->first!=_it->first||it->second!=_it->second) return 1;
	return 0;
}

bool VDS::_Edge::operator!=(_Edge _)
{
	if (x!=_.x||y!=_.y) return 1;
	if (Prop.size()!=_.Prop.size()) return 1;
	for(auto it=Prop.begin(),_it=_.Prop.begin();it!=Prop.end();it++,_it++)
		if (it->first!=_it->first||it->second!=_it->second) return 1;
	return 0;
}

bool VDS::CheckDiff()
{
	if (Vertex.size()!=OldVertex.size()) return 1;
	if (Edge.size()!=OldEdge.size()) return 1;
	auto Ovit=OldVertex.begin();
	auto Nvit=Vertex.begin();
	for(;Ovit!=OldVertex.end();Ovit++,Nvit++) 
		if ((*Ovit)!=(*Nvit)) return 1;
	auto Oeit=OldEdge.begin();
	auto Neit=Edge.begin();
	for(;Oeit!=OldEdge.end();Oeit++,Neit++) 
		if ((*Oeit)!=(*Neit)) return 1;
	return 0;
}

void VDS::WriteDot()
{
	std::fstream fs,conf;
	fs.open(VDS_DotFILE,std::fstream::out);
	if (!fs.is_open())
	{
		std::string st=std::string("touch ")+VDS_DotFILE;
		system(st.c_str());
		fs.open(VDS_DotFILE,std::fstream::out);
	}
	if (Directed) fs<<"digraph G{"<<std::endl;
	else fs<<"graph G{"<<std::endl;
	conf.open(VDS_DotConf,std::fstream::in);
	char ch;
	while(conf.get(ch)) fs<<ch;
	fs<<std::endl;
	conf.close();
	//
	if (ShowOld)
	{
		fs<<"subgraph cluster_old{"<<std::endl;
		fs<<"label=\"old\";"<<std::endl;
		if (!OldVertex.empty())
		for(auto it=OldVertex.begin();it!=OldVertex.end();it++)
		{
			fs<<OldNodePrefix<<it->x<<"[label=\""<<it->x;
			if (!it->Prop.empty())
			{
				fs<<"|{";
				auto it2=it->Prop.begin();
				fs<<(it2->first)<<"="<<(it2->second);
				for(it2++;it2!=it->Prop.end();it2++)
					fs<<"|"<<(it2->first)<<"="<<(it2->second);
				fs<<"}";
			}
			fs<<"\"";
			if (it->Highlight)
			{
				fs<<",color=red,fontcolor=red";
				if (it->Highlight==1) fs<<",style=bold";
			}
			fs<<"];"<<std::endl;
		}
		if (!OldEdge.empty())
		for(auto it=OldEdge.begin();it!=OldEdge.end();it++)
		{
			fs<<OldNodePrefix<<it->x<<"->"<<OldNodePrefix<<it->y<<"[";
			if (!it->Prop.empty())
			{
				fs<<"label=\"";
				auto it2=it->Prop.begin();
				fs<<(it2->first)<<"="<<(it2->second);
				for(it2++;it2!=it->Prop.end();it2++)
					fs<<"\\n"<<(it2->first)<<"="<<(it2->second);
				fs<<"\"";
			}
			if (it->Highlight)
			{
				fs<<",color=red,fontcolor=red";
				if (it->Highlight==1) fs<<",style=bold";
			}
			fs<<"];"<<std::endl;
		}
		fs<<"}"<<std::endl;
		fs<<"subgraph cluster_new{"<<std::endl;
		fs<<"label=\"new\";"<<std::endl;
	}
	//
	if (!Vertex.empty())
		for(auto it=Vertex.begin();it!=Vertex.end();it++)
		{
			fs<<it->x<<"[label=\""<<it->x;
			if (!it->Prop.empty())
			{
				fs<<"|{";
				auto it2=it->Prop.begin();
				fs<<(it2->first)<<"="<<(it2->second);
				for(it2++;it2!=it->Prop.end();it2++)
					fs<<"|"<<(it2->first)<<"="<<(it2->second);
				fs<<"}";
			}
			fs<<"\"";
			if (it->Highlight)
			{
				fs<<",color=red,fontcolor=red";
				if (it->Highlight==1) fs<<",style=bold";
			}
			fs<<"];"<<std::endl;
		}
	if (!Edge.empty())
		for(auto it=Edge.begin();it!=Edge.end();it++)
		{
			fs<<it->x<<"->"<<it->y<<"[";
			if (!it->Prop.empty())
			{
				fs<<"label=\"";
				auto it2=it->Prop.begin();
				fs<<(it2->first)<<"="<<(it2->second);
				for(it2++;it2!=it->Prop.end();it2++)
					fs<<"\\n"<<(it2->first)<<"="<<(it2->second);
				fs<<"\"";
			}
			if (it->Highlight)
			{
				fs<<",color=red,fontcolor=red";
				if (it->Highlight==1) fs<<",style=bold";
			}
			fs<<"];"<<std::endl;
		}
	if (ShowOld) fs<<"}"<<std::endl;
	fs<<"}"<<std::endl;
	fs.close();
}

void VDS::FHighlightDiff()
{
	auto Ovit=OldVertex.begin();
	auto Nvit=Vertex.begin();
	for(;Ovit!=OldVertex.end()||Nvit!=Vertex.end();) 
	{
		if (Ovit!=OldVertex.end()&&Ovit->Highlight==2) Ovit->Highlight=0;
		if (Ovit==OldVertex.end()||Nvit==Vertex.end()||(*Ovit)!=(*Nvit))
		{
			if (Ovit!=OldVertex.end()) Ovit->Highlight=2;
			if (Nvit!=Vertex.end()) Nvit->Highlight=2;
		}
		if (Ovit!=OldVertex.end()) Ovit++;
		if (Nvit!=Vertex.end()) Nvit++;
	}
	//
	auto Oeit=OldEdge.begin();
	auto Neit=Edge.begin();
	for(;Oeit!=OldEdge.end()||Neit!=Edge.end();) 
	{
		if (Oeit!=OldEdge.end()&&Oeit->Highlight==2) Oeit->Highlight=0;
		if (Oeit==OldEdge.end()||Neit==Edge.end()||(*Oeit)!=(*Neit))
		{
			if (Oeit!=OldEdge.end()) Oeit->Highlight=2;
			if (Neit!=Edge.end()) Neit->Highlight=2;
		}
		if (Oeit!=OldEdge.end()) Oeit++;
		if (Neit!=Edge.end()) Neit++;
	}
}

void VDS::_ClearV(std::vector<_Vertex> &a)
{
	for(auto it=a.begin();it!=a.end();it++) it->Prop.clear();
	a.clear();
}

void VDS::_ClearE(std::vector<_Edge> &a)
{
	for(auto it=a.begin();it!=a.end();it++) it->Prop.clear();
	a.clear();
}

void VDS::AddVertex(const T &x,Property &Prop,const bool Highlight)
{
	Vertex.push_back(_Vertex{x,Prop,(int)Highlight});
}

void VDS::AddEdge(const T &x,const T &y,Property &Prop,const bool Highlight)
{
	Edge.push_back(_Edge{x,y,Prop,(int)Highlight});
}

void VDS::Show()
{
	if (!CheckDiff()) 
	{
		_ClearV(Vertex); _ClearE(Edge);
		return;
	}
	if (HighlightDiff) FHighlightDiff();
	std::string st;
	WriteDot();
	st=std::string("dot -Tpng ")+VDS_DotFILE+" -o "+VDS_PngFILE;
	system(st.c_str());
	//st=std::string("display ")+VDS_PngFILE;
	//system(st.c_str());
	_ClearV(OldVertex); _ClearE(OldEdge);
	OldVertex=Vertex; OldEdge=Edge;
	_ClearV(Vertex); _ClearE(Edge);
}

void VDS::Clear()
{
	Directed=0;
	ShowOld=1;
	HighlightDiff=1;
	_ClearV(Vertex); _ClearE(Edge);
	_ClearV(OldVertex); _ClearE(OldEdge);
}
