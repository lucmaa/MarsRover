//
// Created by luc on 2020/1/9.
//

#include <gtest/gtest.h>
#include "../src/Rover.h"

using namespace std;

TEST(MarsRover, should_at_0_0_N_when_a_rover_is_born) {
    Rover r;

    EXPECT_EQ(r.X(), 0);
    EXPECT_EQ(r.Y(), 0);
    EXPECT_EQ(r.D(), 'N');
}

TEST(MarsRover, should_turn_left_when_command_is_L) {
    Rover r;
    LCommand c;

    r.execute(std::make_shared<LCommand>(c));

    EXPECT_EQ(r.current_pos().d, 'W');
}

TEST(MarsRover, should_turn_right_when_command_is_R) {
    Rover r;
    RCommand c;

    r.execute(std::make_shared<RCommand>(c));

    EXPECT_EQ(r.current_pos().d, 'E');
}

TEST(MarsRover, should_march_one_step_when_command_is_M) {
    Rover r;
    MCommand c;

    r.execute(std::make_shared<MCommand>(c));

    EXPECT_EQ(r.current_pos().d, 'N');
    EXPECT_EQ(r.current_pos().x, 0);
    EXPECT_EQ(r.current_pos().y, 1);
}

