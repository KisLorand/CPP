#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>
//#include <bits/stdc++.h> DO NOT USE THIS!!!

//these could be obj/struct adresses
using edgesList_t = std::vector<std::vector<char>>;
using graph_t = std::map<char, std::vector<char>>; 

// in a header file probably
struct GraphNode
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
};

class Graph
{
    public : 
        std::vector<GraphNode> nodes;

        void addNode()
        {
            
        }

        void connectNodes(GraphNode &nodeA, GraphNode &nodeB)
        {
            nodeA.neighbours.push_back(nodeB);
            nodeB.neighbours.push_back(nodeA);
        }
};

graph_t buildGraph_ByEdgesList(edgesList_t &edges);
void traversal_depthFirst_Iterative(graph_t graph, char sourceNode);
void traversal_depthFirst_Recursive(graph_t &graph, char sourceNode, std::unordered_set<char> &visited);
void traversal_breathFirst(graph_t graph, char sourceNode);

int main()
{
    edgesList_t edges = {
    {'i','j'},
    {'k','i'},
    {'m','k'},
    {'k','l'},
    {'o','n'},
    {'o','j'}, //just to connect the graph
    };

    graph_t graph1 = buildGraph_ByEdgesList(edges);

    std::vector<char> s = graph1['i'];
    std::cout << "i : " << graph1['i'][0] << ' ';
    std::cout << graph1['i'][1] << '\n';
    std::cout << "j : " << graph1['j'][0] << '\n';
    std::cout << "k : " << graph1['k'][0] << ' ';
    std::cout << graph1['k'][1] << ' ';
    std::cout << graph1['k'][2] << '\n';
    std::cout << "m : " << graph1['m'][0] << '\n';
    std::cout << "l : " << graph1['l'][0] << '\n';
    std::cout << "o : " << graph1['o'][0] << '\n';
    std::cout << "n : " << graph1['n'][0] << '\n';
    std::cout << '\n';

    std::unordered_set<char> visited = {};

    std::cout << "Iterative Depth First Search : \n";
    traversal_depthFirst_Iterative(graph1, 'i');

    std::cout << "Recursive Depth First Search : \n";
    traversal_depthFirst_Recursive(graph1, 'i', visited);

    std::cout << "Iterative Breadth First Search : \n";
    traversal_breathFirst(graph1, 'i');

    delete &visited;

    return 0;
}

graph_t buildGraph_ByEdgesList(std::vector<std::vector<char>> &edges)
{
    graph_t graph = {};

    for (auto edge : edges) {
        //
        char a = edge[0];
        char b = edge[1];
        if ( graph.count(a) == 0 ) 
            graph[a] = std::vector<char> {};
        if ( graph.count(b) == 0  ) 
            graph[b] = std::vector<char> {};
        /* if ( graph.find(a) == graph.end() ) 
            graph[a] = std::vector<char> {};
        if ( graph.find(b) == graph.end() ) 
            graph[b] = std::vector<char> {}; */

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    return graph;
};

void traversal_depthFirst_Iterative(graph_t graph, char sourceNode)
{
    std::stack<char> stack;
    std::unordered_set<char> visited;

    stack.push(sourceNode);

    char current;
    while (!stack.empty())
    {
        std::cout << "Top : " << stack.top() << '\n';   
        current = stack.top();
        stack.pop(); 

        std::cout << current << '\n';

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

void traversal_depthFirst_Recursive(graph_t &graph, char sourceNode, std::unordered_set<char> &visited)
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

void traversal_breathFirst(graph_t graph, char sourceNode)
{
    std::queue<char> queue;
    std::unordered_set<char> visited;

    queue.push(sourceNode);

    while (queue.size()>0)
    {
        auto current = queue.front();
        queue.pop();

        std::cout << current << "\n";

        for (auto neighbour : graph[current])
        {
            if (visited.find(neighbour) == visited.end())
            {
                visited.insert(neighbour);
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