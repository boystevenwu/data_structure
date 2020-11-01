#include "proj2.hpp"

/**
 * Perform a breadth first traversal in the graph
 * Count the shortest path from the starting location to other nodes
 * Use visit to track visited nodes and dist to count path length
 **/
void bfs(const std::vector< std::vector<unsigned> > & friends, std::vector<unsigned> & wait_list,
         std::vector<unsigned> & visit, std::vector<unsigned> & dist, unsigned step) {
    unsigned vertex = wait_list.front();
    wait_list.erase(wait_list.begin());
    step = dist[vertex] + 1;
    auto adjacent = friends[vertex];

    for(unsigned i : adjacent) {
        if (!visit[i]) {
            wait_list.push_back(i);
            visit[i] = 1;
            dist[i] = step;
        }
    }
}

/**
 * Perform  a depth first traversal in the graph
 * Count the number of shortest paths from the starting location to other nodes
 * Use visit to track, path to record every path found and compare them to already known shortest distances
 **/
void dfs(const std::vector< std::vector<unsigned> > & friends, const std::vector<unsigned> & wait_list,
         const std::vector<unsigned> & dist, const std::vector<unsigned> & visit, std::vector<unsigned> & path,
         const unsigned step) {
    auto curr_visit = visit;

    for (unsigned i : wait_list) {
        curr_visit[i] = 1;
        if (step == dist[i]) { path[i] += 1; }

        std::vector<unsigned> adjacent;
        for (unsigned j : friends[i]) {
            if (!visit[j]) { adjacent.push_back(j); }
        }

        if (!adjacent.empty()) {
            dfs(friends, adjacent, dist, curr_visit, path, step+1);
        }
    }
}

/**
 * Call functions to fill in pathLengths and numSHortestPaths
 **/
void countPaths(const std::vector< std::vector<unsigned> > & friends, unsigned start,
                std::vector<unsigned> & pathLengths, std::vector<unsigned> & numShortestPaths) {
    {
        std::vector<unsigned> visit(friends.size(), 0), wait_list;
        visit[start] = 1;

        wait_list.push_back(start);
        while (!wait_list.empty()) {
            bfs(friends, wait_list, visit, pathLengths, 0);
        }
    }

    {
        std::vector<unsigned> visit(friends.size(), 0), wait_list;

        wait_list.push_back(start);
        dfs(friends, wait_list, pathLengths, visit, numShortestPaths, 0);
    }
}
