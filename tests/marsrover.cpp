//
// Created by luc on 2020/1/9.
//

#include <gtest/gtest.h>
#include "../src/rover.h"

using namespace std;

TEST(MarsRover, should_at_0_0_N_when_a_rover_is_born) {
    Rover r;

    EXPECT_EQ(r.X(), 0);
    EXPECT_EQ(r.Y(), 0);
    EXPECT_EQ(r.D(), 'N');
}

TEST(MarsRover, should_turn_left_when_command_is_L) {
    Rover r;
    Context c("L");

    r.execute(c);

    EXPECT_EQ(r.D(), 'W');
}

TEST(MarsRover, should_turn_right_when_command_is_R) {
    Rover r;
    Context c("R");

    r.execute(c);

    EXPECT_EQ(r.D(), 'E');
}

TEST(MarsRover, should_march_one_step_when_command_is_M) {
    Rover r;
    Context c("M");

    r.execute(c);

    EXPECT_EQ(r.D(), 'N');
    EXPECT_EQ(r.X(), 0);
    EXPECT_EQ(r.Y(), 1);
}

TEST(MarsRover, should_1_3_N_when_locate_1_2_N_then_lmlmlmlmm) {
    Rover r(1, 2, 'N');
    Context c("LMLMLMLMM");

    r.execute(c);

    EXPECT_EQ(r.logger(), "1 3 N");
}

TEST(MarsRover, should_rest_in_peace_when_loc_0_0_S_t_then_pace) {
    Rover r(0, 0, 'S');
    Context c("M");

    r.execute(c);

    EXPECT_EQ(r.logger(), "0 0 S RIP");
}
