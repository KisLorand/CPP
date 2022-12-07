#include <iostream>
#include <string> 
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>
#include "graph.h"

using graphMap_t = std::map<std::string, std::vector<std::string>>;

graphMap_t createAdjacencyList(Graph &pGraph);

void traversal_depthFirst_Iterative(graphMap_t &graph, std::string sourceNode);
void traversal_depthFirst_Recursive(graphMap_t &graph, std::string sourceNode, std::unordered_set<std::string> &visited);
void traversal_breathFirst(graphMap_t &graph, std::string sourceNode);

void printGraph_withIterator(const graphMap_t &graphMap);
void printGraph(const graphMap_t &graphMap);


int main()
{
    Graph *pGraph = new Graph(6, 3);
    std::cout << &pGraph << std::endl;

    graphMap_t graphMap = createAdjacencyList(*pGraph);
    printGraph_withIterator(graphMap);

    delete pGraph;


    std::unordered_set<std::string> visited = {};
    std::string sourceNode = "2";

    std::cout << "\nIterative Depth First Search : \n";
    traversal_depthFirst_Iterative(graphMap, sourceNode);

    std::cout << "\nRecursive Depth First Search : \n";
    traversal_depthFirst_Recursive(graphMap, sourceNode, visited);

    std::cout << "\nIterative Breadth First Search : \n";
    traversal_breathFirst(graphMap, sourceNode);

    delete &visited;

    return 0;
}

graphMap_t createAdjacencyList(Graph &pGraph)
{
    std::cout << &pGraph << std::endl;
    graphMap_t graphMap;
    Graph graph_22 = pGraph;
    for (GraphNode node : graph_22.nodes)
    {
        std::vector<std::string> neightbourNodes;
        for(GraphNode gNode : node.neighbours)
        {
            graphMap[node.value].push_back(gNode.value);
            graphMap[gNode.value].push_back(node.value); // for non directed graph
        }
    }
    return graphMap;
}

void traversal_depthFirst_Iterative(graphMap_t &graph, std::string sourceNode)
{
    std::stack<std::string> stack;
    std::unordered_set<std::string> visited;

    stack.push(sourceNode);
    visited.insert(sourceNode);

    std::string current;
    while (!stack.empty())
    {
        current = stack.top();
        stack.pop(); 

        std::cout << "Top : " << current << '\n';

        for (auto neighbour : graph[current])
        {
            if (visited.find(neighbour) == visited.end())
            {
                visited.insert(neighbour);
                stack.push(neighbour);

                std::cout << "\nVisited : ";
                for ( auto s : visited)
                {
                    std::cout << s << ' ';
                }
                std::cout << "\n";
            }
        }
    }
};

void traversal_depthFirst_Recursive(graphMap_t &graph, std::string sourceNode, std::unordered_set<std::string> &visited)
{
    std::cout << "graph: " << &graph << '\n';
    std::cout << sourceNode << '\n';

    for (auto neighbour : graph[sourceNode])
    {
        if (visited.find(neighbour) == visited.end())
        {
            visited.insert(neighbour);

            std::cout << "\nVisited : ";
            for (auto s : visited)
            {
                std::cout << s << ' ';
            }
            std::cout << "\n";

            traversal_depthFirst_Recursive(graph, neighbour, visited);
        }
    }
};

void traversal_breathFirst(graphMap_t &graph, std::string sourceNode)
{
    std::queue<std::string> queue;
    std::unordered_set<std::string> visited;

    visited.insert(sourceNode);
    queue.push(sourceNode);

    while (queue.size()>0)
    {
        std::string current = queue.front();
        queue.pop();

        std::cout << "Current : " << current << "\n";

        for (auto neighbour : graph[current])
        {
            if (visited.find(neighbour) == visited.end())
            {
                visited.insert(neighbour); // adding the neighbours before visiting them, to stop them to be visited multiple times
                queue.push(neighbour);

                std::cout << "\nVisited : ";
                for ( auto s : visited)
                {
                    std::cout << s << ' ';
                }
                std::cout << "\n";
            }
        }
    }
}

void printGraph_withIterator(const graphMap_t &graphMap)
{
    graphMap_t::iterator it;

    for (auto it = graphMap.begin(); it != graphMap.end(); it++)
    {
        std::cout << it->first << " : ";
        for(auto str : it->second)
        {
            std::cout << str << ", ";
        }
        std::cout << "\n";
    }
    std::cout << "\n" << std::endl;
}

void printGraph(const graphMap_t &graphMap)
{

}