#ifndef ROBOT_H
#define ROBOT_H

#include <string>

namespace ToyRobot {

class Robot
{
public:
    Robot(const int x = 0,
          const int y = 0,
          const std::string facing = "NORTH"):
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
    inline const std::string facing() const { return _facing; }

private:
    int _x;
    int _y;
    std::string _facing;
};

}

#endif
