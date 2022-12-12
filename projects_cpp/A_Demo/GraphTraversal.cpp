#include <iostream>
#include <string> 
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>
#include <memory>
//#include "graph.h"

using graphMap_t = std::map<std::string, std::vector<std::string>>;


class GraphNode
{
    public :
        std::string value;
        std::vector<GraphNode> neighbours;

        GraphNode()
        {

        }

        GraphNode(std::string value)
        {
            this->value = value;
        }

        ~GraphNode()
        {
/*             delete &value;
            delete &neighbours;
            std::cout << "Node destructed" << std::endl; */
        }
};

class Graph
{
    public : 
        std::vector<GraphNode> nodes;
        std::vector<GraphNode*> nodeptrs;
        //std::vector<std::shared_ptr<GraphNode>> nodes_ptr;//
        //std::shared_ptr<GraphNode> nodes_ptr;//

        Graph(int nodeCount, int edgeCount)
        {
            for (int i=0; i<nodeCount; ++i)
            {
                GraphNode* pNode = new GraphNode(std::to_string(i));
                //GraphNode* node = new GraphNode(std::to_string(i));

                nodeptrs.push_back(pNode);
                nodes.push_back(*pNode);
            }

            //auto nodes_ptr = std::make_shared<GraphNode>(nodes[0]);

            for (int j=0; j<nodes.size()-1; j++)
            {
                nodes[j].neighbours.push_back(nodes[j+1]);
            }

            for (int j=0; j<nodes.size()-2; j=j+2)
            {
                nodes[j].neighbours.push_back(nodes[j+2]);
            }
        }

        ~Graph()
        {
/*             for (GraphNode node : nodes)
            {
                delete &node;
            }
            delete &nodes; */
            std::cout << "Graph destructor" << std::endl;
        }

        void addNode()
        {
            
        }

        void connectNodes(GraphNode &nodeA, GraphNode &nodeB)
        {
            nodeA.neighbours.push_back(nodeB);
            nodeB.neighbours.push_back(nodeA);
        }
};

graphMap_t createAdjacencyList(Graph &pGraph);

void traversal_depthFirst_Iterative(graphMap_t &graph, std::string sourceNode);
void traversal_depthFirst_Recursive(graphMap_t &graph, std::string sourceNode, std::unordered_set<std::string> &visited);
void traversal_breathFirst(graphMap_t &graph, std::string sourceNode);

void printGraph_withIterator(const graphMap_t &graphMap);
void printGraph(const graphMap_t &graphMap);


int main()
{
    Graph *pGraph = new Graph(6, 3);

    //std::cout << "ssss  " << (*pGraph).nodes[0].value << std::endl;

    graphMap_t graphMap = createAdjacencyList(*pGraph);
    printGraph_withIterator(graphMap);

    delete pGraph;
    //std::cout << "ssss  " << (*pGraph).nodes[0].value << std::endl;

    std::string sourceNode = "2";
    std::unordered_set<std::string> visited = {sourceNode};

    std::cout << "\n\nIterative Depth First Search : \n";
    traversal_depthFirst_Iterative(graphMap, sourceNode);

    std::cout << "\n\nRecursive Depth First Search : \n";
    traversal_depthFirst_Recursive(graphMap, sourceNode, visited);

    std::cout << "\n\nIterative Breadth First Search : \n";
    traversal_breathFirst(graphMap, sourceNode);

    delete &visited;

    return 0;
}

graphMap_t createAdjacencyList(Graph &pGraph)
{
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
    std::cout << "Current node : " << sourceNode << '\n';

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


