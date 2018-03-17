#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <map>
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
    void place(const std::string coordinates);
    void exec(const std::string raw_command, const std::string raw_args);

    inline const int x() const { return _x; }
    inline const int y() const { return _y; }
    inline const string facing() const { return _facing; }

private:
    const map<string, map<string, string>> const kTurn = {
        {"NORTH", {{"LEFT", "WEST"}, {"RIGHT", "EAST"}}},
        {"SOUTH", {{"LEFT", "EAST"}, {"RIGHT", "WEST"}}},
        {"EAST", {{"LEFT", "NORTH"}, {"RIGHT", "SOUTH"}}},
        {"WEST", {{"LEFT", "SOUTH"}, {"RIGHT", "NORTH"}}}
    };

    int _x;
    int _y;
    string _facing;
};

}

#endif
