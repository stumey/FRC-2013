#ifndef _FLOOR_INTAKE_H_
#define _FLOOR_INTAKE_H_

#include "WPILib.h"

/**
	@Author:								Jesse Grabowski
	@Date:									01/12/2012
	@Description:			
		Provides a template for 3539's 2013 robot's floor intake mechanism.
*/

class Floor_Intake {
	public:
		enum FloorIntakeStates {
			INTAKE_STOP,
			INTAKE_IN,
			INTAKE_OUT,
			INTAKE_UNJAM
		};
		
		/**
			Public constructor.
			@param intakeMotor controls motor pulling disks into intake
			@param intakeRoller controls motor pulling disks into magazine
			@param intakeAccentuator controls relay that allows intake ramp to accentuate
		*/
		Floor_Intake(Talon* intakeMotor, Talon* intakeRoller, Relay* intakeAccentuator);
		
		/**
			Sets the main intake wheel's speed
			@param pwr the power to which the wheel is set
		*/
		void setIntakePower(double pwr);
		
		/**
			Sets the state of the intake
			@param state (see FloorIntakeStates)
		*/
		void setIntakeState(FloorIntakeStates state);
		
		/**
			Returns the intake's current power
		*/
		double getIntakePower();
		
		/**
			Returns the intake's current state
		*/
		FloorIntakeStates getIntakeState();
	
	private
		//Motors
		Talon* floorIntakeMotor_1;
		Talon* floorIntakeMotor_2;
		
		//Relay
		Relay* floorAccentuator_1;
		
		/**
			Private default constructor
		*/
		Floor_Intake();
		
}