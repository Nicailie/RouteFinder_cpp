/**
 * This head file encloses the class Airlines, with it privates methods as well as variable
 * which will be used while reading the files
 * **/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;


 //INDIVIDUAL_PROJECT_AIRLINES_H
class Airlines {
private:
    string airlineId;
    string airlineName;
    string alias;
    string iata;
    string icao;
    string callsign;
    string country;
    string active;

public:
    Airlines(string airline_Id, string airline_Name, string airl_Alias, string airl_Iata, string airl_Icao,
             string airl_Callsign, string airl_Country, string airl_Active) {
        this->airlineId = airline_Id;
        this->airlineName = airline_Name;
        this->alias = airl_Alias;
        this->iata = airl_Iata;
        this->icao = airl_Icao;
        this->callsign = airl_Callsign;
        this->country = airl_Country;
        this->active = airl_Active;
    }

    const basic_string<char> getAirlineId() const {
        return airlineId;
    }

    const string &getAirlineName() const {
        return airlineName;
    }

    const string &getAlias() const {
        return alias;
    }

    const string &getIata() const {
        return iata;
    }

    const string &getIcao() const {
        return icao;
    }

    const string &getCallsign() const {
        return callsign;
    }

    const string &getCountry() const {
        return country;
    }

    const string &getActive() const {
        return active;
    }
};
