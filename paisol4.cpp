#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;

struct Location {
    string name;

    Location(string _name) : name(_name) {}
};

struct Edge {
    Location* destination;
    double distance;

    Edge(Location* dest, double dist) : destination(dest), distance(dist) {}
};

class Graph {
private:
    unordered_map<string, vector<Edge>> adjacencyList;

public:
    void addLocation(Location* loc) {
        adjacencyList[loc->name] = vector<Edge>();
    }

    void addRoad(Location* src, Location* dest, double dist) {
        adjacencyList[src->name].push_back(Edge(dest, dist));
    }

    vector<Location*> shortestPath(Location* start, Location* end) {
        priority_queue<pair<double, Location*>, vector<pair<double, Location*>>, greater<pair<double, Location*>>> pq;
        
        unordered_map<Location*, double> distance;
        unordered_map<Location*, Location*> predecessor;

        for (auto& pair : adjacencyList) {
            Location* loc = new Location(pair.first);
            distance[loc] = numeric_limits<double>::infinity();
            predecessor[loc] = nullptr;
        }

        distance[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            Location* current = pq.top().second;
            pq.pop();

            for (Edge& edge : adjacencyList[current->name]) {
                double newDist = distance[current] + edge.distance;
                if (newDist < distance[edge.destination]) {
                    distance[edge.destination] = newDist;
                    predecessor[edge.destination] = current;
                    pq.push({newDist, edge.destination});
                }
            }
        }

        vector<Location*> path;
        Location* current = end;
        while (current != nullptr) {
            path.push_back(current);
            current = predecessor[current];
        }
        reverse(path.begin(), path.end());

        return path;
    }
};

int main() {
   
    Graph map;

    Location* locationA = new Location("Location A");
    Location* locationB = new Location("Location B");
    Location* locationC = new Location("Location C");
    Location* locationD = new Location("Location D");

    map.addLocation(locationA);
    map.addLocation(locationB);
    map.addLocation(locationC);
    map.addLocation(locationD);

    map.addRoad(locationA, locationB, 5.0);
    map.addRoad(locationA, locationC, 10.0); 
    map.addRoad(locationB, locationD, 15.0); 
    map.addRoad(locationC, locationD, 20.0); 

    vector<Location*> shortestPath = map.shortestPath(locationA, locationD);
    cout << "Shortest path from Location A to Location D: ";
    for (Location* loc : shortestPath) {
        cout << loc->name << " -> ";
    }
    cout << endl;

    return 0;
}
