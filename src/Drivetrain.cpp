#include "hpp/Drivetrain.h"

Drivetrain::Drivetrain(int lf, int lb, int rf, int rb) {
	left_front = lf;
	left_back = lb;
	right_front = rf;
	right_back = rb;
}

void Drivetrain::move_velocity(bool left, int velocity) {
	if (left) {
		pros::c::motor_move(left_front, velocity);
		pros::c::motor_move(left_back, velocity);
	} else {
		pros::c::motor_move(right_front, velocity);
		pros::c::motor_move(right_back, velocity);
	}
}

void Drivetrain::handle(pros::Controller controller) {
	move_velocity(true, -controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
	move_velocity(false, controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
}