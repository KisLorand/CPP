#include <string>
#include <vector>

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

        ~GraphNode()
        {
           /*  delete value;
            delete neighbours; */
        }
};

class Graph
{
    public : 
        std::vector<GraphNode> nodes;

        Graph(int nodeCount, int edgeCount)
        {
            for (int i=0; i<nodeCount; ++i)
            {
                GraphNode node = GraphNode(std::to_string(i));

                nodes.push_back(node);
            }

            for (int j=0; j<nodes.size()-1; j++)
            {
                nodes[j].neighbours.push_back(nodes[j+1]);
            }

            for (int j=0; j<nodes.size()-2; j=j+2)
            {
                nodes[j].neighbours.push_back(nodes[j+2]);
            }
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