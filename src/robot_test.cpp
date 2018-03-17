#include "src/test_helpers.h"

#include "src/robot.h"

TEST(RobotTest, Report) {
    // ToyRobot::Robot* subject = new ToyRobot::Robot();

    // const char* stdout_contents = capture_output(subject->report);
    ToyRobot::Robot subject;
    auto function_pointer = std::bind(&ToyRobot::Robot::report, subject);
    // function1(fp);

    const char* stdout_contents = capture_output(function_pointer);
    // const char* stdout_contents = capture_output(subject.report);
    const char* expected_output = "0,0,NORTH\n";
    EXPECT_EQ(0, strncmp(stdout_contents, expected_output, strlen(expected_output)));
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
