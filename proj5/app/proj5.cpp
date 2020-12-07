#include "proj5.hpp"
#include "MyPriorityQueue.hpp"

// As a reminder, for this project, edges have positive cost, g[i][j] = 0 means no edge.
std::vector<Edge> compute_mst(std::vector< std::vector<unsigned>> & graph)
{
	std::vector<Edge> mst;
	std::vector<int> visited(graph.size(), 0);
	visited[0] = 1;
    std::vector<MyPriorityQueue<Edge>> collection;

	for (int i = 0; i < graph.size(); ++i) {
	    MyPriorityQueue<Edge> temp;

	    for (int j = 0; j < graph[i].size(); ++j) {
	        if (graph[i][j]) {
                temp.insert(Edge(i, j, graph[i][j]));
            }
	    }
	    collection.push_back(temp);
	}

    while (true) {
        std::vector<int> todo(graph.size(), INT_MAX);

        for (int i = 0; i < visited.size(); i++) {
            if (visited[i]) {
                todo[i] = collection[i].min().weight;
            }
        }

        int index = std::min_element(todo.begin(), todo.end()) - todo.begin();
        auto temp {collection[index].min()};
        collection[index].extractMin();

        if (visited[temp.pt1] != 1 or visited[temp.pt2] != 1) {
            mst.push_back(temp);
            visited[mst.back().pt1] = 1;
            visited[mst.back().pt2] = 1;
        }
        if ( std::equal(visited.begin() + 1, visited.end(), visited.begin()) )
        {
            break;
        }
    }

	return mst;
}


// Returns the cost of the edges in the given vector,
// This does not confirm that it is a MST at all.  
unsigned mstCost(const std::vector<Edge> & vE)
{
	unsigned sum = 0;
	for (auto e : vE)
	{
		sum += e.weight;
	}
	return sum;
}
