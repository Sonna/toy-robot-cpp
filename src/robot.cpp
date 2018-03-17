#include <iostream>
#include "robot.h"

using namespace std;

namespace ToyRobot {

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

}

void Robot::right() {

}

void Robot::move() {

}

void Robot::place(const string coordinates) {

}

void Robot::exec(const string raw_command, const string raw_args) {

}

}
