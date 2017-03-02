#include <WPILib.h>
#include <CANTalon.h>

CANTalon * fl = new CANTalon(5);
CANTalon * rl = new CANTalon(9);
CANTalon * fr = new CANTalon(2);
CANTalon * rr = new CANTalon(3);
CANTalon * climber = new CANTalon(11);
CANTalon * groundIntake = new CANTalon(10);
CANTalon * saladSpinner = new CANTalon(13);
CANTalon * shooterMaster = new CANTalon(6);
CANTalon * shooterSlave = new CANTalon(9);
CANTalon * angle = new CANTalon(12);
CANTalon * shooterIntake = new CANTalon(1);

frc::RobotDrive* robotDrive = new frc::RobotDrive(fl,rl,fr,rr);

std::time_t startTime; //Used to calculate delay through time


class Robot: public frc::IterativeRobot {
public:
	void RobotInit() {
		groundIntake->SetInverted(true);
		fl->SetInverted(true);
		fr->SetInverted(true);
		rl->SetInverted(true);
		rr->SetInverted(true);

		shooterSlave->SetControlMode(CANTalon::ControlMode::kFollower);
		shooterSlave->Set(shooterMaster->GetDeviceID());
	}

	void AutonomousInit() {
	}

	void AutonomousPeriodic() {
	}

	void TeleopInit() {
	}

	void TeleopPeriodic() {

	}

	void TestPeriodic() {
		leftDriveOn();
		if (waited(0.5)){
			driveOff();//i hate josef

		}

		rightDriveOn();
		if (waited(0.5)){
			driveOff();
		}

		climberOn();
		if (waited(1.0)){
			climberOff();
		}
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

	void drive(double left, double right){
		robotDrive->TankDrive(left,right,false);
	}

	void leftDriveOn(){
		drive(0.5, 0.0);
	}

	void driveOff(){
		drive(0.0, 0.0);
	}

	void rightDriveOn(){
		drive(0.0, 0.5);
	}

	void climberOn(){
		climber->Set(-0.8);
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
		saladSpinner->Set(0.5);
	}

	void saladSpinnerOff(){
		saladSpinner->Set(0.0);
	}

	void shooterOn(){
		shooterMaster->Set(0.5);
	}

	void shooterOff(){
		shooterMaster->Set(0.0);
	}

	void angleOn(){

	}

	void angleOff(){

	}

	void shooterIntakeOn(){
		shooterIntake->Set(0.5);
	}

	void shooterIntakeOff(){
		shooterIntake->Set(0.0);
	}


};

START_ROBOT_CLASS(Robot)
