#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
public:
	list<int> *adj; //adjacency list containing adjacent nodes of a vertex
	int V; //no of vertices of a graph

	Graph(int V)
	{
		this->adj = new list<int>[V];
		this->V = V;
	}

	void addnew(int u,int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void BFS(int s)
	{
		bool *visited = new bool[V];
		queue<int> queue;
		list<int>::iterator it;

		for(int i = 0 ; i < V ; i++)
			visited[i]=false;

		queue.push(s);

		while(!queue.empty())
		{
			int currentelement = queue.front();
			visited[currentelement]=true;
			cout<<currentelement<<" ";

			queue.pop();

			for(it = adj[currentelement].begin() ; it != adj[currentelement].end() ; it++)
			{
				if(!visited[*it])
				{
					queue.push(*it);
				}
			}
		}
	}

	void DFS(int s)
	{
		bool *visited = new bool[V];
		for(int i = 0 ; i < V ; i++)
			visited[i]=false;

		DFSRecursive(s,visited);
	}

	void DFSRecursive(int v,bool visited[])
	{
		visited[v]=true;
		cout<<v<<" ";

		list<int>::iterator it;
		for( it = adj[v].begin() ; it != adj[v].end() ; it++ )
		{
			if(!visited[*it])
			{
				DFSRecursive(*it,visited);
			}
		}
	}
};

int main()
{
	Graph *g = new Graph(7);
	g->addnew(0,1);
	g->addnew(0,2);
	g->addnew(1,3);
	g->addnew(1,4);
	g->addnew(2,5);
	g->addnew(2,6);
	cout<<"---------DFS-------"<<endl;
	g->DFS(0);
	cout<<endl;
	cout<<"---------BFS-------"<<endl;
	g->BFS(0);
	cout<<endl;
	return 0;
}

