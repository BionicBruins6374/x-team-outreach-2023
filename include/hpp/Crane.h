#include "api.h"
#include "hpp/Constants.h"

#ifndef CRANE_H
#define CRANE_H

class Crane {
	private:
		pros::Motor left_motor;
		pros::Motor right_motor;

	public:
		Crane(int cl, int cr) : left_motor(cl), right_motor(cr) {}

		Crane() : Crane(constants::CRANE_LEFT, constants::CRANE_RIGHT) {}

		void move_velocity(bool up, int speed);

		void cancel_velocity();
};

#endif /* CRANE_H */