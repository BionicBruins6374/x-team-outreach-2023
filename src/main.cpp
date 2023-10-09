#include "main.h"
#include "hpp/Drivetrain.h"
#include "hpp/Crane.h"

#include "hpp/Constants.h"

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	Drivetrain dt;
	Crane crane;

	while (true) {
		dt.handle(master);

		// Control crane movement (maybe works !?)
		if (master.get_digital(DIGITAL_R1)) {
			crane.move_velocity(true, constants::SPEED);
		} else if (master.get_digital(DIGITAL_R2)) {
			crane.move_velocity(false, constants::SPEED);
		}
 
		pros::delay(20);
	}
}
