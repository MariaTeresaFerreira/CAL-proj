/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include "MutablePriorityQueue.h"
#include "Libraries.h"
using namespaces std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;


/****************** Provided structures  ********************/

template <class T>
class Vertex {
	T info;                // contents
	vector<Edge<T> > adj;  // list of outgoing edges
	bool visited;          // auxiliary field used by dfs and bfs
	int indegree;          // auxiliary field used by topsort
	bool processing;       // auxiliary field used by isDAG

	double dist = 0;
	Vertex<T> *path = NULL;
	int queueIndex = 0; 		// required by MutablePriorityQueue


	void addEdge(Vertex<T> *dest, double w);
	bool removeEdgeTo(Vertex<T> *d);
public:
	Vertex(T in);
	friend class Graph<T>;

	bool operator<(Vertex<T> & vertex) const; // // required by MutablePriorityQueue

	T getInfo() const;
	T* getInfoPointer(){
		return &info;
	}

	int getIndegree() const;
	double getDist() const;
	Vertex *getPath() const;
	friend class MutablePriorityQueue<Vertex<T>>;

	void setDist(double d);
	void setPath(Vertex<T> *vert);
	void setInfo(T info);
};

/*
 * Ficha 5, funções dadas.
*/

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
	adj.push_back(Edge<T>(d, w));
}

template <class T>
bool Vertex<T>::operator<(Vertex<T> & vertex) const {
	return this->dist < vertex.dist;
}

template <class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template <class T>
double Vertex<T>::getDist() const {
	return this->dist;
}

template <class T>
Vertex<T> *Vertex<T>::getPath() const {
	return this->path;
}

template <class T>
int Vertex<T>::getIndegree() const{
	return this->indegree;
}

template <class T>
void Vertex<T>::setDist(double d) {
	this->dist = d;
}

template <class T>
void Vertex<T>::setPath(Vertex<T> *vert){
	this->path = vert;
}

template <class T>
void Vertex<T>::setInfo(T info) {
	this->info = info;
}


template <class T>
class Edge {
	Vertex<T> * dest;      // destination vertex
	Vertex<T> * orig;
	double weight;         // edge weight
public:
	Edge(Vertex<T> *d, double w);
	friend class Graph<T>;
	friend class Vertex<T>;
	double getWeight() const{
		return weight;
	}
};

template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;    // vertex set

	void dfsVisit(Vertex<T> *v,  vector<T> & res) const;
	Vertex<T> *findVertex(const T &in) const;
	bool dfsIsDAG(Vertex<T> *v) const;
public:
	int getNumVertex() const;
	bool addVertex(const T &in);
	bool removeVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	bool removeEdge(const T &sourc, const T &dest);
	bool isDAG() const;


	vector<T> dfs() const;
	vector<T> bfs(const T &source) const;
	vector<T> topsort() const;
	vector<T> getPath(const T &origin, const T &dest);


	int maxNewChildren(const T &source, T &inf) const;
	void unweightedShortestPath(const T &orig);
	void dijkstraShortestPath(const T &origin);
};

/****************** Provided constructors and functions ********************/

template <class T>
Vertex<T>::Vertex(T in): info(in) {}

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {}


template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
	for (auto v : vertexSet)
		if (v->info == in)
			return v;
	return NULL;
}

/****************** 1a) addVertex ********************/

/*
 *  Adds a vertex with a given content/info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const T &in) {

	auto v1 = findVertex(in);

	if(v1 != NULL) return false;

	vertexSet.push_back(new Vertex<T>(in));

	return false;
}

/****************** 1b) addEdge ********************/

/*
 * Adds an edge to a graph (this), given the contents of the source (sourc) and
 * destination (dest) vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {

	auto vs = findVertex(sourc);
	auto vd = findVertex(dest);

	if(vs == NULL || vd == NULL) return false;

	vs->addEdge(vd, w);
	return true;
}

/****************** 1c) removeEdge ********************/

/*
 * Removes an edge from a graph (this).
 * The edge is identified by the source (sourc) and destination (dest) contents.
 * Returns true if successful, and false if such edge does not exist.
 */
template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {

	auto vs = findVertex(sourc);
	auto vd = findVertex(dest);

	if(vs == NULL || vd == NULL) return false;

	return vs->removeEdgeTo(vd);
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {

	for(auto it = adj.begin(); it != adj.end(); it++)
		if(it->dest == d){
			adj.erase(it);
			return true;
		}

	return false;
}


/****************** 1d) removeVertex ********************/

/*
 *  Removes a vertex with a given content (in) from a graph (this), and
 *  all outgoing and incoming edges.
 *  Returns true if successful, and false if such vertex does not exist.
 */
template <class T>
bool Graph<T>::removeVertex(const T &in) {
	// TODO (10 lines)
	// HINT: use an iterator to scan the "vertexSet" vector and then erase the vertex.
	// HINT: take advantage of "removeEdgeTo" to remove incoming edges.
	for(auto it = vertexSet.begin(); it != vertexSet.end(); it++){
		if((*it)->info == in){
			auto v = *it;
			vertexSet.erase(it);
			for(auto u : vertexSet)
				u->removeEdgeTo(v);
			delete v;
			return true;
		}
	}
	return false;
}


/****************** 2a) dfs ********************/

/*
 * Performs a depth-first search (dfs) in a graph (this).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
template <class T>
vector<T> Graph<T>::dfs() const {
	// TODO (7 lines)
	vector<T> res;

	for(auto v : vertexSet)
		v->visited = false;
	for(auto v : vertexSet)
		if(! v->visited)
			dfsVisit(v, res);
	return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent not yet visited, recursively.
 * Updates a parameter with the list of visited node contents.
 */
template <class T>
void Graph<T>::dfsVisit(Vertex<T> *v, vector<T> & res) const {
	// TODO (7 lines)
	v->visited = true;
	res.push_back(v->info);

	for(auto & x : v->adj){
			auto y = x.dest;
		if( ! y->visited)
			dfsVisit(y, res);
	}
}

/****************** 2b) bfs ********************/

/*
 * Performs a breadth-first search (bfs) in a graph (this), starting
 * from the vertex with the given source contents (source).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
template <class T>
vector<T> Graph<T>::bfs(const T & source) const {
	// TODO (22 lines)
	// HINT: Use the flag "visited" to mark newly discovered vertices .
	// HINT: Use the "queue<>" class to temporarily store the vertices.
	vector<T> res;

	auto sourc = findVertex(source);
	if(sourc==NULL) return res;
	queue<Vertex<T>*> queue;

	queue.push(sourc);
	sourc->visited = true;

	while(!queue.empty()){
		auto v = queue.front();
		queue.pop();
		res.push_back(v->info);
		for(auto & edge : v->adj){
			auto w = edge.dest;
			if( ! w->visited ){
				queue.push(w);
				w->visited = true;
			}
		}
	}
	return res;
}

/****************** 2c) toposort ********************/

/*
 * Performs a topological sorting of the vertices of a graph (this).
 * Returns a vector with the contents of the vertices by topological order.
 * If the graph has cycles, returns an empty vector.
 * Follows the algorithm described in theoretical classes.
 */

template<class T>
vector<T> Graph<T>::topsort() const {
	// TODO (26 lines)
	vector<T> res;
	for(auto v : vertexSet) v->indegree = 0;
	for(auto v : vertexSet)
		for(auto & edge : v->adj)
			edge.dest->indegree++;

	queue<Vertex<T>*> queue;
	for(auto v : vertexSet){
		if(v->indegree == 0)
			queue.push(v);
	}

	while(!queue.empty()){
		auto v = queue.front();
		queue.pop();
		res.push_back(v->info);
		for(auto & edge : v->adj){
			auto w = edge.dest;
			w->indegree--;
			if( w->indegree == 0){
				queue.push(w);
			}
		}
	}

	if( vertexSet.size() != res.size()){
		cout << "É impossível ordenar topologicamente!" << endl;
		res.clear();
		return res;
	}
	return res;
}

/****************** 3a) maxNewChildren (HOME WORK)  ********************/

/*
 * Performs a breadth-first search in a graph (this), starting
 * from the vertex with the given source contents (source).
 * During the search, determines the vertex that has a maximum number
 * of new children (adjacent not previously visited), and returns the
 * contents of that vertex (inf) and the number of new children (return value).
 */

template <class T>
int Graph<T>::maxNewChildren(const T & source, T &inf) const {
	auto s = findVertex(source);
	if(s == NULL) return -1;

	int maxChild = 0;
	queue<Vertex<T>*> q;
	inf = s->info;

	for(auto v = vertexSet.begin(); v != vertexSet.end(); v++){
		(*v)->visited = false;
	}
	s->visited = true;
	q.push(s);

	while(!q.empty()){
		auto v = q.front();
		q.pop();
		int children = 0;
		for(auto &e : v->adj){
			auto d = e.dest;
			if( ! d->visited ){
				d->visited = true;
				q.push(d);
				children++;
			}
		}
		if(maxChild < children){
			maxChild = children;
			inf = v->info;
		}
	}
	return maxChild;
}

/****************** 3b) isDAG   (HOME WORK)  ********************/

/*
 * Performs a depth-first search in a graph (this), to determine if the graph
 * is acyclic (acyclic directed graph or DAG).
 * During the search, a cycle is found if an edge connects to a vertex
 * that is being processed in the the stack of recursive calls (see theoretical classes).
 * Returns true if the graph is acyclic, and false otherwise.
 */

template <class T>
bool Graph<T>::isDAG() const {
	// TODO (9 lines, mostly reused)
	// HINT: use the auxiliary field "processing" to mark the vertices in the stack.
	for(auto v : vertexSet){
		v->visited = false;
		v->processing = false;
	}
	for( auto v : vertexSet ){
		if( !v->visited){
			if(! dfsIsDAG(v))
				return false;
			}
	}
	return true;
}

/**
 * Auxiliary function that visits a vertex (v) and its adjacent not yet visited, recursively.
 * Returns false (not acyclic) if an edge to a vertex in the stack is found.
 */
template <class T>
bool Graph<T>::dfsIsDAG(Vertex<T> *v) const {
	// TODO (12 lines, mostly reused)
	v->visited = true;
	v->processing = true;
	for( auto &e : v->adj){
		auto d = e.dest;
		if(d->processing){
			return false;
		}
		if(!d->visited){
			if(!dfsIsDAG(d)){
				return false;
			}
		}
	}
	v->processing = false;
	return true;
}

template<class T>
vector<T> Graph<T>::getPath(const T &origin, const T &dest){
	vector<T> res;
	auto v1 = findVertex(origin);
	auto v2 = findVertex(dest);

	if( v1 == NULL || v2 == NULL) return res;

	while(v2->getPath() != NULL) {

		res.push_back(v2->getInfo());

		v2 = v2->getPath();

	}

	res.push_back(origin);

	reverse(res.begin(), res.end());

	return res;
}

template<class T>
void Graph<T>::unweightedShortestPath(const T &orig) {

	int infinite = std::numeric_limits<int>::max();

	for(auto v : vertexSet){
		v->setDist(infinite);
		v->setPath(NULL);
	}
	auto s = findVertex(orig);
	s->dist = 0;
	queue<Vertex<T>*> q;
	q.push(s);

	while(!q.empty()){
		auto v = q.front();
		q.pop();

		for(auto &e : v->adj){

			auto w = e.dest;
			if(w->getDist() == infinite){
				w->dist = v->dist + 1;
				w->path = v;
				q.push(w);
			}
		}
	}
}

template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
	auto s = findVertex(origin);

	int infinite = std::numeric_limits<int>::max();

	for(auto v : vertexSet){
		v->setDist(infinite);
		v->setPath(NULL);
		v->visited = false;
	}

	s->setDist(0);

	MutablePriorityQueue<Vertex<T>> q;

	q.insert(s);

	while(!q.empty()){

		auto v = q.extractMin();

		for( auto &e : v->adj){

			auto w = e.dest;

			double old_d = w->getDist();
			double new_d = v->getDist() + e.weight;

			if(old_d > new_d){

				w->setDist(new_d);

				w->setPath(v);

				if(!w->visited){
					q.insert(w);
				}else{
					q.decreaseKey(w);
				}
				w->visited = true;
			}
		}
	}
}

#endif /* GRAPH_H_ */
