/*
 Title: Graph Traversal using DFS and BFS
 Author: adityakamble49
*/

#include<iostream>
#include<list>

using namespace std;

class Graph{

	list<int> *adj_list;
	int total_vertices;

	public: Graph(int total_vertices);
	public:	void add_edge(int v_one, int v_two);
	public: void display_adj_list();
	private: bool is_in_list(list<int> *conn_list, int vertex);
	public: void print_bfs(int v_start);
	public: void print_dfs(int v_start);

};

int main(){

	Graph *graph = new Graph(4);

	graph->add_edge(0,1);
	graph->add_edge(0,2);
	graph->add_edge(1,3);
	graph->add_edge(2,3);

	graph->display_adj_list();

	cout<<"BFS Traversal"<<endl;
	graph->print_bfs(0);

	return 0;
}

Graph::Graph(int total_vertices){

	this->total_vertices = total_vertices;
	this->adj_list = new list<int>[total_vertices];
	cout<<"Graph Created";
}

void Graph::add_edge(int v_one, int v_two){

	adj_list[v_one].push_back(v_two);
	adj_list[v_two].push_back(v_one);

}

void Graph::display_adj_list(){

	for(int i=0; i<total_vertices; i++){

		cout<<endl<<i<<" : ";

		list<int>::iterator adj_list_it;
		for(adj_list_it = adj_list[i].begin(); 
			adj_list_it != adj_list[i].end(); adj_list_it++ ){

			cout<<(*adj_list_it)<<" ";

		}
	}

	cout<<endl;
}

bool Graph::is_in_list(list<int> *conn_list,int vertex){

	list<int>::iterator v_it;

	for(v_it = conn_list->begin(); v_it != conn_list->end(); v_it++){

		if(vertex == (*v_it)){

			return true;
		}
	}	

	return false;

}

void Graph::print_bfs(int  v_start){

	bool *visited_vertices= new bool[total_vertices];
	for(int i=0; i<total_vertices; i++){

		visited_vertices[i] = false;
	}

	list<int> conn_list;
	conn_list.push_back(v_start);

	list<int>::iterator v_it;

	while(!conn_list.empty()){

		int current_element = conn_list.front();
		cout<<current_element<<" ";

		visited_vertices[current_element] = true;
		conn_list.pop_front();

		for(v_it = adj_list[current_element].begin();
			v_it != adj_list[current_element].end(); v_it++){

			if(!visited_vertices[*v_it]){

				if(!is_in_list(&conn_list,(*v_it))){

					conn_list.push_back(*v_it);

				}
			}
		}
	}

	cout<<endl;

}

