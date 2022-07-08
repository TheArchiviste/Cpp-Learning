#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// Directed graph.

class Vertex {
    private:
        string label;
        vector<Vertex*> outGoingEgdges;
    
    public:
        Vertex(const string & labelIn)
        : label(labelIn) {}

        void addEdgeTo(Vertex * to) {
            outGoingEgdges.push_back(to);
        }

        void write(ostream & o) const {
            o << label << " -> [";
            for (auto v : outGoingEgdges) {
                o << " " << v->label;
            }
            o << " ]";
        }
};

ostream & operator<<(ostream & o, const Vertex & toPrint) {
    toPrint.write(o);
    return o;
}

// If we use vector of obj => the obj are copied to each new vector upon extending it
// Thus objs change memory location

// If we use pointer only pointer are copied and the obj are static in the memory.
class DiGraph {
    private:
        vector<unique_ptr<Vertex>> verticies;

    public:
        void addVertex(const string & labelIn) {
            verticies.emplace_back(new Vertex(labelIn));
        }

        Vertex* operator[](const int i) {
            return verticies[i].get();
        }
};

#if 1
int main() {
    DiGraph g;

    g.addVertex("Vertex A");
    g.addVertex("Vertex B");
    g.addVertex("Vertex C");
    g.addVertex("Vertex D");
    g.addVertex("Vertex E");
    g.addVertex("Vertex F");
    g.addVertex("Vertex G");

    g[0]->addEdgeTo(g[1]);
    g[1]->addEdgeTo(g[2]);
    g[2]->addEdgeTo(g[3]);
    g[3]->addEdgeTo(g[4]);
    g[4]->addEdgeTo(g[5]);

    cout << *g[0] << endl;
    cout << *g[1] << endl;
    cout << *g[2] << endl;

    return 0;
}
#endif