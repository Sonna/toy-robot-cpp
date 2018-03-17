#include <iostream>
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

void Robot::place(const string coordinates) {

}

void Robot::exec(const string raw_command, const string raw_args) {

}

}
