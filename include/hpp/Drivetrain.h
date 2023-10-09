#include "hpp/Constants.h"

#include "api.h"

#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

enum Side { left, right };

class Drivetrain {
	private:
		int left_front, left_back; // Left Forward, Backward
		int right_front, right_back; // Right Backward, Forward

	public:
		Drivetrain(int lf, int lb, int rf, int rb);

		Drivetrain() 
			: Drivetrain(constants::LEFT_FORWARD, constants::LEFT_BACKWARD, constants::RIGHT_FORWARD, constants::RIGHT_FORWARD) {}

		void move_velocity(Side side, const int velocity);

		void handle(pros::Controller controller);
};

#endif // DRIVETRAIN_H