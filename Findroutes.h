/**
 * This head file "Findroutes" contains all the predefined functions which will help in realizing what we are working on
 * It contains the implementation of the breadth first search as well as the part of comparing the input to the
 * different others file
 * */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include "Readfile.h"
#include "Airports.h"
#include "Route.h"
#include "Airlines.h"
#include "Node.h"
#include <queue>
#include <unordered_set>
using namespace std;

class Findroute{
public:
    /**
     * This method was created in order to check if a certain route is in the set of the frontier,
     * and it will optimally return true or false
     * @param code will be the state code of the source, so it check if there is a route corresponding to that code in
     * the @param frontier, which is a queue of all possible route */

    bool found_queue(string code, queue<Node>frontier){
        while (frontier.size() != 0){
            if(code == frontier.front().state){
                return true;
            }
            frontier.pop();
        }
        return false;
    }
    bool bfs(){
        ReadFile r = ReadFile ("airports.csv", "routes.csv", "airlines.csv", "InputFile.txt");
        vector<string> inputvect = r.readInputs();
        unordered_map<string, Airports> airportVect = r.readAirports();
        string IatafromCountry ;
        string IatatoCountry;
        for(auto const &pair:r.airportsmap){

            if(pair.second.getCity() == inputvect[0] && pair.second.getCountry() == inputvect[1]){
                IatafromCountry = pair.second.getIata();
                cout << "\n iatacode: "<< IatafromCountry<<endl;
                break;
            }
        }
        for(auto const &pair:r.airportsmap){
            if(pair.second.getCity() == inputvect[2] && pair.second.getCountry() == inputvect[3]){
                IatatoCountry = pair.second.getIata();
                cout << "iatacode: "<< IatatoCountry<<endl;
                break;
            }
        }
     /**This code is the implementation of the bread first search, which is an algorithm that consists of
      * going through the routes map and find direct or optimal routes from a source to its
      * destination.
      *@param Iatafromcountry which is the code that represents an airport, like : ACC, BJA, ...
      * @param node represents the state, parent, child, ... used in the algorithm
      * */
        Node node (IatafromCountry);
        queue<Node> frontier;
        if(IatafromCountry == IatatoCountry){
            cout<<"You are in the same location";
            return true;
        }
        frontier.push(node);
        unordered_set<string> explored;

        unordered_map<string, vector<Routes>> routes = r.readRoutes();

        while(!frontier.empty()){
            node = frontier.front();
            frontier.pop();
            explored.insert(node.state);

            vector<Routes> succ_states;
            succ_states = routes[node.state];

            for(Routes child: succ_states){
            Node child_node(child.getSourceofAirport(),node.state, node.path_cost+1);
            if(explored.find(child_node.state) == explored.end() && !found_queue(child_node.state, frontier)){
                if(child_node.state == IatatoCountry){
                    cout<<"This is your route: "<< child_node.state;
                    cout<<"The number of stops:"<<child_node.path_cost;
                    return true;}
                frontier.push(child_node);}
            }return true;
        }
    }
};

