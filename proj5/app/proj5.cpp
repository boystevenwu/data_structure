#include "proj5.hpp"

// As a reminder, for this project, edges have positive cost, g[i][j] = 0 means no edge.
std::vector<Edge> compute_mst(std::vector< std::vector<unsigned>> & graph)
{
	std::vector<Edge> mst;

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
