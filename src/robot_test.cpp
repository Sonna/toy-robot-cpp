#include "src/test_helpers.h"

#include "src/robot.h"

using namespace toy_robot;

TEST(RobotTest, Report) {
    Robot subject;
    auto function_pointer = std::bind(&Robot::report, subject);

    const char* stdout_contents = capture_output(function_pointer);
    const char* expected_output = "0,0,NORTH\n";
    EXPECT_EQ(0, strncmp(stdout_contents, expected_output, strlen(expected_output)));
}

TEST(RobotTest, ReportFromDereferenceSubjectPointer) {
    Robot* subject = new Robot();
    auto function_pointer = std::bind(&Robot::report, *subject);

    const char* stdout_contents = capture_output(function_pointer);
    const char* expected_output = "0,0,NORTH\n";
    EXPECT_EQ(0, strncmp(stdout_contents, expected_output, strlen(expected_output)));
}

TEST(RobotTest, TurnLeft) {
    Robot* subject = new Robot();
    subject->left();

    EXPECT_STREQ(subject->facing().c_str(), "WEST");
}

TEST(RobotTest, TurnLeftWhenFacingWEST) {
    Robot* subject = new Robot(0, 0, "WEST");
    subject->left();

    EXPECT_STREQ(subject->facing().c_str(), "SOUTH");
}

TEST(RobotTest, TurnLeftWhenFacingSOUTH) {
    Robot* subject = new Robot(0, 0, "SOUTH");
    subject->left();

    EXPECT_STREQ(subject->facing().c_str(), "EAST");
}

TEST(RobotTest, TurnLeftWhenFacingEAST) {
    Robot* subject = new Robot(0, 0, "EAST");
    subject->left();

    EXPECT_STREQ(subject->facing().c_str(), "NORTH");
}

TEST(RobotTest, TurnRight) {
    Robot* subject = new Robot();
    subject->right();

    EXPECT_STREQ(subject->facing().c_str(), "EAST");
}

TEST(RobotTest, TurnRightWhenFacingEAST) {
    Robot* subject = new Robot(0, 0, "EAST");
    subject->right();

    EXPECT_STREQ(subject->facing().c_str(), "SOUTH");
}

TEST(RobotTest, TurnRightWhenFacingSOUTH) {
    Robot* subject = new Robot(0, 0, "SOUTH");
    subject->right();

    EXPECT_STREQ(subject->facing().c_str(), "WEST");
}

TEST(RobotTest, TurnRightWhenFacingWEST) {
    Robot* subject = new Robot(0, 0, "WEST");
    subject->right();

    EXPECT_STREQ(subject->facing().c_str(), "NORTH");
}

TEST(RobotTest, Move) {
    Robot* subject = new Robot;
    subject->move();

    ASSERT_EQ(subject->x(), 0);
    ASSERT_EQ(subject->y(), 1);
}

TEST(RobotTest, MoveEAST) {
    Robot* subject = new Robot(0, 0, "EAST");
    subject->move();

    ASSERT_EQ(subject->x(), 1);
    ASSERT_EQ(subject->y(), 0);
}

TEST(RobotTest, MoveWEST) {
    Robot* subject = new Robot(1, 1, "WEST");
    subject->move();

    ASSERT_EQ(subject->x(), 0);
    ASSERT_EQ(subject->y(), 1);
}

TEST(RobotTest, MoveSOUTH) {
    Robot* subject = new Robot(1, 1, "SOUTH");
    subject->move();

    ASSERT_EQ(subject->x(), 1);
    ASSERT_EQ(subject->y(), 0);
}

TEST(RobotTest, MoveDoesNotFallOffTableAt00SOUTH) {
    Robot* subject = new Robot(0, 0, "SOUTH");
    subject->move();

    ASSERT_EQ(subject->x(), 0);
    ASSERT_EQ(subject->y(), 0);
    ASSERT_STREQ(subject->facing().c_str(), "SOUTH");
}

TEST(RobotTest, MoveDoesNotFallOffTableAt00WEST) {
    Robot* subject = new Robot(0, 0, "WEST");
    subject->move();

    ASSERT_EQ(subject->x(), 0);
    ASSERT_EQ(subject->y(), 0);
    ASSERT_STREQ(subject->facing().c_str(), "WEST");
}

TEST(RobotTest, MoveDoesNotFallOffTableAt04WEST) {
    Robot* subject = new Robot(0, 4, "WEST");
    subject->move();

    ASSERT_EQ(subject->x(), 0);
    ASSERT_EQ(subject->y(), 4);
    ASSERT_STREQ(subject->facing().c_str(), "WEST");
}

TEST(RobotTest, MoveDoesNotFallOffTableAt04NORTH) {
    Robot* subject = new Robot(0, 4, "NORTH");
    subject->move();

    ASSERT_EQ(subject->x(), 0);
    ASSERT_EQ(subject->y(), 4);
    ASSERT_STREQ(subject->facing().c_str(), "NORTH");
}

TEST(RobotTest, MoveDoesNotFallOffTableAt44NORTH) {
    Robot* subject = new Robot(4, 4, "NORTH");
    subject->move();

    ASSERT_EQ(subject->x(), 4);
    ASSERT_EQ(subject->y(), 4);
    ASSERT_STREQ(subject->facing().c_str(), "NORTH");
}

TEST(RobotTest, MoveDoesNotFallOffTableAt44EAST) {
    Robot* subject = new Robot(4, 4, "EAST");
    subject->move();

    ASSERT_EQ(subject->x(), 4);
    ASSERT_EQ(subject->y(), 4);
    ASSERT_STREQ(subject->facing().c_str(), "EAST");
}

TEST(RobotTest, MoveDoesNotFallOffTableAt40EAST) {
    Robot* subject = new Robot(4, 0, "EAST");
    subject->move();

    ASSERT_EQ(subject->x(), 4);
    ASSERT_EQ(subject->y(), 0);
    ASSERT_STREQ(subject->facing().c_str(), "EAST");
}

TEST(RobotTest, MoveDoesNotFallOffTableAt40SOUTH) {
    Robot* subject = new Robot(4, 0, "SOUTH");
    subject->move();

    ASSERT_EQ(subject->x(), 4);
    ASSERT_EQ(subject->y(), 0);
    ASSERT_STREQ(subject->facing().c_str(), "SOUTH");
}

TEST(RobotTest, Place) {
    Robot* subject = new Robot;
    subject->place("4,2,SOUTH");

    ASSERT_EQ(subject->x(), 4);
    ASSERT_EQ(subject->y(), 2);
    ASSERT_STREQ(subject->facing().c_str(), "SOUTH");
}

TEST(RobotTest, PlaceAt23EAST) {
    Robot* subject = new Robot;
    subject->place("2,3,EAST");

    ASSERT_EQ(subject->x(), 2);
    ASSERT_EQ(subject->y(), 3);
    ASSERT_STREQ(subject->facing().c_str(), "EAST");
}

TEST(RobotTest, ExecReport) {
    Robot* subject = new Robot;
    string command = "REPORT";
    string args = "REPORT";
    // auto function_pointer = std::bind(&Robot::exec, *subject, command, args);
    auto function_pointer = std::bind(&Robot::exec, *subject, placeholders::_1, placeholders::_2);
    // auto function_pointer = std::bind(&Robot::exec, *subject);
    // auto function_pointer = std::bind(&Robot::exec, *subject);
    // auto function_pointer = std::bind(&Robot::exec, *subject, "REPORT", "");

    // const char* stdout_contents = capture_output(function_pointer);
    // const char* stdout_contents = capture_output(function_pointer, "REPORT");
    const char* stdout_contents = capture_output(function_pointer, command, args);
    const char* expected_output = "0,0,NORTH\n";
    EXPECT_EQ(0, strncmp(stdout_contents, expected_output, strlen(expected_output)));

    ASSERT_EQ(subject->x(), 0);
    ASSERT_EQ(subject->y(), 0);
    ASSERT_STREQ(subject->facing().c_str(), "NORTH");
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
