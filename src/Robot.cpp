#include <WPILib.h>
#include <CANTalon.h>

CANTalon * fl = new CANTalon(4);
CANTalon * rl = new CANTalon(5);
CANTalon * fr = new CANTalon(2);
CANTalon * rr = new CANTalon(3);
CANTalon * climber = new CANTalon(11);
CANTalon * groundIntake = new CANTalon(10);
CANTalon * saladSpinner = new CANTalon(13);
CANTalon * shooterMaster = new CANTalon(6);
CANTalon * shooterSlave = new CANTalon(9);
CANTalon * angle = new CANTalon(12);
CANTalon * shooterIntake = new CANTalon(1);

Joystick* xBox = new Joystick(0);
std::time_t startTime; //Used to calculate delay through time

int state;
bool isPressed;


class Robot: public frc::IterativeRobot {
public:
	void RobotInit() {
		groundIntake->SetInverted(true);
		fl->SetInverted(true);
		fr->SetInverted(true);
		rl->SetInverted(true);
		rr->SetInverted(true);
		saladSpinner->SetInverted(true);
		shooterIntake->SetInverted(true);

		shooterMaster->SetControlMode(CANSpeedController::kSpeed);
		shooterSlave->SetControlMode(CANTalon::ControlMode::kFollower);
		shooterSlave->Set(shooterMaster->GetDeviceID());
		startTime = 0;
		state = 10;
		isPressed = false;
	}

	void AutonomousInit() {
	}

	void AutonomousPeriodic() {
	}

	void TeleopInit() {

	}

	void TeleopPeriodic() {

		if (xBox->GetRawButton(1)){
			isPressed = true;
		}

		switch(state){
		case 10:
			frontLeftOn();
			if (!xBox->GetRawButton(1) && isPressed){
				isPressed = false;
				state = 20;
			}
			break;

		case 20:
			frontRightOn();
			if (!xBox->GetRawButton(1) && isPressed){
				isPressed = false;
				state = 21;
			}
			break;

		case 21:
			rearLeftOn();
			if (!xBox->GetRawButton(1) && isPressed){
				isPressed = false;
				state = 22;
			}
			break;

		case 22:
			rearLeftOn();
			if (!xBox->GetRawButton(1) && isPressed){
				isPressed = false;
				state = 30;
			}
			break;

		case 30:
			climberOn();
			if (!xBox->GetRawButton(1) && isPressed){
				isPressed = false;
				climberOff();
				state = 40;
			}
			break;

		case 40:
			groundIntakeOn();
			if (!xBox->GetRawButton(1) && isPressed){
				isPressed = false;
				groundIntakeOff();
				state = 50;
			}
			break;

		case 50:
			saladSpinnerOn();
			if (!xBox->GetRawButton(1) && isPressed){
				isPressed = false;
				saladSpinnerOff();
				state = 60;
			}
			break;

		case 60:
			shooterOn();
			if (!xBox->GetRawButton(1) && isPressed){
				isPressed = false;
				shooterOff();
				state = 60;
			}
			break;

		case 70:
			shooterIntakeOn();
			if (!xBox->GetRawButton(1) && isPressed){
				isPressed = false;
				shooterIntakeOff();
			}
	}

		SmartDashboard::PutNumber("current state", state);
}


	void TestPeriodic() {
	}

private:
	bool waited(double seconds){
		if(startTime == 0){
			std::time(&startTime);
		}
		std::time_t currentTime;
		std::time(&currentTime);
		if (std::difftime(currentTime, startTime) >= seconds) {
			startTime = 0;
			return true;
		}
		return false;
	}

	void frontLeftOn(){
		fl->Set(0.5);
	}

	void frontRightOn(){
		fr->Set(0.5);
	}

	void rearLeftOn(){
		rl->Set(0.5);
	}

	void rearRightOn(){
		rr->Set(0.5);
	}

	void climberOn(){
		climber->Set(-0.3);
	}

	void climberOff(){
		climber->Set(0.0);
	}

	void groundIntakeOn(){
		groundIntake->Set(0.5);
	}

	void groundIntakeOff(){
		groundIntake->Set(0.0);
	}

	void saladSpinnerOn(){
		saladSpinner->Set(0.3);
	}

	void saladSpinnerOff(){
		saladSpinner->Set(0.0);
	}

	void shooterOn(){
		shooterMaster->Set(0.3);
	}

	void shooterOff(){
		shooterMaster->Set(0.0);
	}

	void angleOn(){

	}

	void angleOff(){

	}

	void shooterIntakeOn(){
		shooterIntake->Set(0.3);
	}

	void shooterIntakeOff(){
		shooterIntake->Set(0.0);
	}


};

START_ROBOT_CLASS(Robot)
