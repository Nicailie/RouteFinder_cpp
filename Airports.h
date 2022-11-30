/**
 * This head file encloses the class Airports, with it privates methods as well as variable
 * which will be used while reading the files
 * **/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;


class Airports {
private:
    basic_string<char> airportID;
    string name;
    string city;
    string country;
    string IATA;
    string ICAO;
    basic_string<char> latitude;
    basic_string<char> longitude;
    basic_string<char> altitude;
    basic_string<char> timezone;
    string DST;
    string databaseTimeZone;
    string typeOfAirport;
    string sourceOfData;

public:
    Airports(basic_string<char> Id, string airpName, string airpCity, string airpCountry, string airpIata, string airpIcao,
             basic_string<char> latitude, basic_string<char> longitude, basic_string<char> altitude, basic_string<char> timezone,
             string airpDst, string airpTimeZone, string typeOfAirport, string airpSourceOfData) {
            this->airportID = Id;
            this -> name = airpName;
            this -> city = airpCity;
            this -> country = airpCountry;
            this -> IATA = airpIata;
            this -> ICAO = airpIcao;
            this -> latitude = latitude;
            this -> longitude = longitude;
            this ->altitude = altitude;
            this -> timezone = timezone;
            this ->DST = airpDst;
            this -> databaseTimeZone = airpTimeZone;
            this ->typeOfAirport = airpSourceOfData;
    }

    const basic_string<char> getAirportId() const {
        return airportID;
    }

    const string &getName() const {
        return name;
    }

    const string &getCity() const {
        return city;
    }

    const string &getCountry() const {
        return country;
    }

    const string &getIata() const {
        return IATA;
    }

    const string &getIcao() const {
        return ICAO;
    }

    const basic_string<char> getLatitude() const {
        return latitude;
    }

    const basic_string<char> getLongitude() const {
        return longitude;
    }

    const basic_string<char> getAltitude() const {
        return altitude;
    }

    const basic_string<char> getTimezone() const {
        return timezone;
    }

    const string &getDst() const {
        return DST;
    }

    const string &getDatabaseTimeZone() const {
        return databaseTimeZone;
    }

    const string &getTypeOfAirport() const {
        return typeOfAirport;
    }

    const string &getSourceOfData() const {
        return sourceOfData;
    }


};
