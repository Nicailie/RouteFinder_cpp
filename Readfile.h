/**
 * This head file "ReadFiles" contains all the predefined functions which will help in reading the documents.
 * */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include "Airports.h"
#include "Route.h"
#include "Airlines.h"

using namespace std;

class ReadFile {
public :
    unordered_map<string, vector<Routes>> routesmap;
    unordered_map<string, Airports> airportsmap;
    unordered_map<string, vector<Airlines>> airlinesmap;
    unordered_map<string, string> iatatoairport;

/**Variables that will store the file to read**/
    string file_airport;
    string file_airline;
    string file_route;
    string inputfile;
/**method that will help reading the files and stores in different, appropriates struuctures,
 * map and vectors in this case
 * */
    unordered_map<string, vector<Routes>> readRoutes();
    unordered_map<string, Airports> readAirports();
    unordered_map<string, vector<Airlines>> readAirlines();
    vector<string> readInputs();

/**method that reads all the file when it called, it takes the argument file
 * @param airline, @param route
 * @param airport, @param inputfile**/

    ReadFile(string airport , string route, string airline,string inputfile){
        this->file_airport = airport;
        this->file_route = route;
        this->file_airline = airline;
        this->inputfile = inputfile;
    }
};
/**This is the function to read the routes file and it will put it in the map of the route, with the key as source airport, and the
 * vector of all possibles airports to the source as a value.
 * It is a method that returns map of the routes, for example if airport ACC can connects to 6 routes,
 * it will be a map with key : Acc and
 * value the  vector of the object Routes class**/
unordered_map<string, vector<Routes>> ReadFile::readRoutes() {
    fstream file; //open file pointers
    string line;
    string routestr;
    file.open(file_route);//open the existing file
    getline(file, line);

    while(getline(file, line)){
        vector<string> RoutesVect;
        stringstream stream(line);
        while(stream.good()){
            string routestr;
            getline(stream, routestr, ',');
            RoutesVect.push_back(routestr);
        }

            if(RoutesVect.size() == 9){
                string source_airp = RoutesVect[2];
                Routes one_route = Routes(RoutesVect[0], RoutesVect[1],RoutesVect[2],RoutesVect[3],
                                          RoutesVect[4], RoutesVect[5], RoutesVect[6], RoutesVect[7], RoutesVect[8]);
                if(routesmap.find(source_airp) == routesmap.end()){
                    vector<Routes> all_routes;
                    all_routes.push_back(one_route);
                    routesmap.insert({source_airp, all_routes});}
                else{routesmap.at(source_airp).push_back(one_route);
                    }
            }
    }return routesmap;
}
/**This is the function to read the input file and it will put it in the vector,
 * It is a method that returns the source city and source country, and destination country and destination city,
**/
vector<string> ReadFile :: readInputs() {
    fstream file;
    string inputline;
    file.open(inputfile);
    vector<string> inputvect;
    while (getline(file, inputline)) {
        stringstream stream(inputline);
        while (stream.good()) {
            string inputsr;
            getline(stream, inputsr, ',');
            inputvect.push_back(inputsr);
        }
    }
    return inputvect;
}
/**This is the function to read the airlines file and it will put it in the map of the airline, with the key as airline Id, and the
 * vector of all possibles airlines to the source as a value.
 * It is a method that returns map of the airlines,
**/
unordered_map<string, vector<Airlines>> ReadFile::readAirlines() {
        fstream file; //open file pointers
        string line;

        file.open(file_airline);//open the existing file
        getline(file, line);
        while (getline(file, line)) {
            vector<string> airlinesVect;
            stringstream stream(line);

            while (stream.good()) {
                string airlinestr;
                getline(stream, airlinestr, ',');
                airlinesVect.push_back(airlinestr);
            }
            if (airlinesVect.size() == 8) {
                string airline_Id = airlinesVect[0];
                Airlines one_airline = Airlines(airlinesVect[0], airlinesVect[1], airlinesVect[2], airlinesVect[3],
                                                airlinesVect[4], airlinesVect[5], airlinesVect[6], airlinesVect[7]);
                if (airlinesmap.find(airline_Id) == airlinesmap.end()) {
                    vector<Airlines> all_airlines;
                    all_airlines.push_back(one_airline);
                    airlinesmap.insert({airline_Id, all_airlines});
                } else { airlinesmap.at(airline_Id).push_back(one_airline); }
            }
        }
    }

/**This is the function to read the airports file and it will put it in the map of the route, with the key as source airport Id,
 * and the airport object as a value.
 * It is a method that returns map of the airports, for example if airport ACC can connects to 6 routes,
 * it will be a map with key : 1 and
 * value the object Airports class**/
unordered_map<string, Airports> ReadFile::readAirports() {
        fstream file; //open file pointers
        string line;
        file.open(file_airport);
        while (getline(file, line)) {
            vector<string> airportVect;
            stringstream stream(line);
            while (stream.good()) {
                string airportstr;
                getline(stream, airportstr, ',');
                airportVect.push_back(airportstr);
            }
            if (airportVect.size() == 14) {
                string airp_Id = airportVect[0];
                Airports one_airport(airportVect[0], airportVect[1], airportVect[2], airportVect[3],
                                     airportVect[4], airportVect[5], airportVect[6], airportVect[7],
                                     airportVect[8], airportVect[9], airportVect[10], airportVect[11],
                                     airportVect[12], airportVect[13]);
                airportsmap.insert({airp_Id, one_airport});}
        }
        return airportsmap;
    }
