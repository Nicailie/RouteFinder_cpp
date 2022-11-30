/**
 * This head file encloses the class Routes with it privates methods as well as variable
 * **/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Routes {
private :
    string airlineCode;
    string airlineId;
    string sourceofAirport;
    string sourceofAirportId;
    string destinationAirport;
    string destinationAirportId;
    string codeShare;
    string stops;
    string equipment;

public :
    Routes( string aircode, string Id, string source, string sourceId,
            string destination, string destinationId, string share,
            string stops, string equipment){
        this->airlineCode = aircode;
        this->airlineId = Id;
        this->sourceofAirport = source;
        this->destinationAirportId = sourceId;
        this->destinationAirport = destination;
        this->destinationAirportId = destinationId;
        this->codeShare = share;
        this->stops = stops;
        this->equipment = equipment;
    }

    const string &getAirlineCode() const {
        return airlineCode;
    }

    const string &getAirlineId() const {
        return airlineId;
    }

    const string &getSourceofAirport() const {
        return sourceofAirport;
    }

    const string &getSourceofAirportId() const {
        return sourceofAirportId;
    }

    const string &getDestinationAirport() const {
        return destinationAirport;
    }

    const string &getDestinationAirportId() const {
        return destinationAirportId;
    }

    const string &getCodeShare() const {
        return codeShare;
    }

    const string &getStops() const {
        return stops;
    }

    const string &getEquipment() const {
        return equipment;
    }
};

