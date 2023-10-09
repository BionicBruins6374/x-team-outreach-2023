#include "hpp/Crane.h"

void Crane::move_velocity(bool up, int speed) {
	speed *= up ? 1 : -1; // Invert based on up

	int pos = std::min(left_motor.get_position(), right_motor.get_position());

	const int T_THRESHOLD = 100; // experiment :pray:
	const int B_THRESHOLD = 0; // experiment :pray:

	//if (pos < B_THRESHOLD || pos >= T_THRESHOLD) return; // clamp position

	left_motor.move_velocity(speed);
	right_motor.move_velocity(speed);
}

void Crane::cancel_velocity() {
	left_motor.move_velocity(0);
	right_motor.move_velocity(0);
}