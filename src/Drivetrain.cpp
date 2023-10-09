#include "hpp/Drivetrain.h"

Drivetrain::Drivetrain(int lf, int lb, int rf, int rb) {
	left_front = lf;
	left_back = lb;
	right_front = rf;
	right_back = rb;
}

void Drivetrain::move_velocity(Side side, int velocity) {
	switch (side) {
		case left: 
			pros::c::motor_move_velocity(left_front, velocity);
			pros::c::motor_move_velocity(left_back, velocity);
			break;
		case right:
			pros::c::motor_move_velocity(right_front, velocity);
			pros::c::motor_move_velocity(right_back, velocity);
			break;
	}
}

void Drivetrain::handle(pros::Controller controller) {
	move_velocity(Side(left), controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
	move_velocity(Side(right), controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
}