#ifndef ROBOT_H
#define ROBOT_H

#include <map>
#include <string>

using namespace std;

namespace toy_robot {

class Robot
{
public:
    Robot(const int x = 0,
          const int y = 0,
          const string facing = "NORTH"):
            _x(x),
            _y(y),
            _facing(facing) {};
    ~Robot();

    void report() const;
    void left();
    void right();
    void move();
    void place(const std::string raw_coordinates);
    void exec(const string raw_command, const string raw_args = "");

    inline const int x() const { return _x; }
    inline const int y() const { return _y; }
    inline const string facing() const { return _facing; }

private:
    const map<string, map<string, string>> kTurn = {
        {"NORTH", {{"LEFT", "WEST"}, {"RIGHT", "EAST"}}},
        {"SOUTH", {{"LEFT", "EAST"}, {"RIGHT", "WEST"}}},
        {"EAST", {{"LEFT", "NORTH"}, {"RIGHT", "SOUTH"}}},
        {"WEST", {{"LEFT", "SOUTH"}, {"RIGHT", "NORTH"}}}
    };

    const map<string, map<char, int>> kMove = {
        {"NORTH", {{'x', 0}, {'y', 1}}},
        {"SOUTH", {{'x', 0}, {'y', -1}}},
        {"EAST", {{'x', 1}, {'y', 0}}},
        {"WEST", {{'x', -1}, {'y', 0}}}
    };

    int _x;
    int _y;
    string _facing;
};

int run(char** argv);

}

#endif
