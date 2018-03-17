#include <functional>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

#include "robot.h"

using namespace std;

namespace toy_robot {

// Constructor
// Robot::Robot(const int x, const int y, const std::string facing): _x(x), _y(y), _facing(facing) {
// }

// Destructor
Robot::~Robot() {
}


void Robot::report() const {
    cout << x() << "," << y() << "," << facing() << endl;
}

void Robot::left() {
    _facing = kTurn.at(facing()).at("LEFT");
}

void Robot::right() {
    _facing = kTurn.at(facing()).at("RIGHT");
}

void Robot::move() {
    _x = x() + kMove.at(facing()).at('x');
    _y = y() + kMove.at(facing()).at('y');

    if (_x < 0 || _x > 4) {
        _x = x() - kMove.at(facing()).at('x');
    }

    if (_y < 0 || _y > 4) {
        _y = y() - kMove.at(facing()).at('y');
    }
}

void Robot::place(const string raw_coordinates) {
    vector<string> coordinates;
    stringstream ss(raw_coordinates);
    string coordinate;
    char delim = ',';

    while (getline(ss, coordinate, delim)) {
        coordinates.push_back(coordinate);
    }

    if (coordinates.size() < 3) { return; }

    _x = stoi(coordinates[0]);
    _y = stoi(coordinates[1]);
    _facing = coordinates[2];
}

void Robot::exec(const string raw_command, const string raw_args) {
    // switch (raw_command) {
    //     case "REPORT":
    //         report();
    //         break;
    //     case "LEFT":
    //         left();
    //         break;
    //     case "RIGHT":
    //         right();
    //         break;
    //     case "MOVE":
    //         move();
    //         break;
    //     case "PLACE":
    //         place(raw_args);
    //         break;
    //     default:
    //         // Do Nothing
    //         break;
    // }

    const unordered_map<string,function<void(const string)>> commands = {
        {"REPORT", [&](const string args){ report(); }},
        {"LEFT",   [&](const string args){ left(); }},
        {"RIGHT",  [&](const string args){ right(); }},
        {"MOVE",   [&](const string args){ move(); }},
        {"PLACE",  [&](const string args){ place(args); }}
    };
    const auto end = commands.end();
    auto it = commands.find(raw_command);
    if (it != end) {
        it->second(raw_args);
    }
}

}
