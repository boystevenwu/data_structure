#include "proj5.hpp"
#include <iostream>
#include "MyPriorityQueue.hpp"

// As a reminder, for this project, edges have positive cost, g[i][j] = 0 means no edge.
std::vector<Edge> compute_mst(std::vector< std::vector<unsigned>> & graph)
{
	std::vector<Edge> mst;
	std::vector<int> visited(graph.size(), 0);
	visited[0] = 1;
    std::vector<MyPriorityQueue<Edge>> collection;

	for (int i = 0; i < graph.size()-1; ++i) {
	    MyPriorityQueue<Edge> temp;

	    for (int j = i+1; j < graph[i].size(); ++j) {
            temp.insert(Edge(i, j, graph[i][j]));
	    }
	    collection.push_back(temp);
	}

    while (true) {
        std::vector<int> todo(graph.size(), INT_MAX);

        for (int i = 0; i < visited.size()-1; i++) {
            if (visited[i]) {
                todo[i] = collection[i].min().weight;
            }
        }

        int index = std::min_element(todo.begin(), todo.end()) - todo.begin();
        auto temp {collection[index].min()};
        collection[index].extractMin();
        std::cout << index << " - " << temp.weight << " --- ";

        if (visited[temp.pt1] != 1 or visited[temp.pt2] != 1) {
            mst.push_back(temp);
            std::cout << mst.back().pt1 << " " << mst.back().pt2;
            visited[mst.back().pt1] = 1;
            visited[mst.back().pt2] = 1;
        }
        std::cout << std::endl;
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
