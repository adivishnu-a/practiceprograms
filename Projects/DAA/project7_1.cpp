
#include<iostream>
#include <list>
using namespace std;

class Graph
{
	int V; 
	list<int> *adj; 
	public:
		Graph(int V); 
		void insert(int v, int w); 
		void printVertexCover(); 
		void printGraph(list<int> adj[], int V);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::insert(int u, int v)
{
	adj[u].push_back(v); 
	adj[v].push_back(u); 
}

void Graph::printGraph(list<int> adj[], int V)
{
    for (int v = 0; v < V-1; v++) {
        cout << "vertex " << v << " ";
		cout << "--->";
        for (auto x : adj[v])
            cout << " " << x <<", ";
        cout<<endl;
    }
    cout<<endl;
}


void Graph::printVertexCover()
{
	bool visited[V];
	for (int i=0; i<V; i++)
		visited[i] = false;

	list<int>::iterator i;

	for (int u=0; u<V; u++)
	{
		if (visited[u] == false)
		{
			for (i= adj[u].begin(); i != adj[u].end(); ++i)
			{
				int v = *i;
				if (visited[v] == false)
				{
					visited[v] = true;
					visited[u] = true;
					break;
				}
			}
		}
	}

	printGraph(adj, V);

	for (int i=0; i<V; i++)
		if (visited[i])
		cout << i << " ";
}


int main()
{
	int V = 5;
	Graph g(V);
	g.insert(0, 1);
	g.insert(0, 3);
	g.insert(1, 2);
	g.insert(2, 3);
	g.printVertexCover();
	return 0;
}