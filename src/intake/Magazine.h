#ifndef _MAGAZINE_H_
#define _MAGAZINE_H_

#include "WPILib.h"

/**
	@Author:								Jesse Grabowski
	@Date:									01/12/2012
	@Description:			
		Provides a template for 3539's 2013 robot's magazine mechanism.
*/

class Magazine {
	public:
		enum MagazineStates {
			MAGAZINE_EMPTY,
			MAGAZINE_ONE,
			MAGAZINE_TWO,
			MAGAZINE_THREE,
			MAGAZINE_FULL
		};
		
		/**
			Public constructor.
			@param magazineMotor controls magazine position
			@param magazineLimit1 reads occupancy of disk slot 1
			@param magazineLimit2 reads occupancy of disk slot 2
			@param magazineLimit3 reads occupancy of disk slot 3
			@param magazineLimit4 reads occupancy of disk slot 4
			@param magazineKicker pushes disk into shooter
		*/
		Magazine(Talon* magazineMotor, DigitalInput* magazineLimit1, DigitalInput* magazineLimit2, DigitalInput* magazineLimit3, DigitalInput* magazineLimit4, Solenoid* magazineKicker);
		
		/**
			Called every step in main class, magazine attempts to push disks to highest adjacent cells.
			Alternatively, run magazine as a seperate thread and let it handle this without a call every step.
		*/
		void autoIndex();
		
		/**
			Pushes the top disk into the shooter.
		*/
		void ejectDisk();
		
		/**
			Returns the numer of disks in the intake
		*/
		MagazineStates getOccupancy();
	
	private
		//Motors
		Talon* magazineMotor_;
		
		//LimitSwitches
		DigitalInput* magazineLimit1_;
		DigitalInput* magazineLimit2_; 
		DigitalInput* magazineLimit3_; 
		DigitalInput* magazineLimit4_;
		
		//Solenoids
		Solenoid* magazineKicker_;
		
		/**
			Returns the occupancy status of slot one
		*/
		bool getSlotOne();
		
		/**
			Returns the occupancy status of slot two
		*/
		bool getSlotTwo();
		
		/**
			Returns the occupancy status of slot three
		*/
		bool getSlotThree();
		
		/**
			Returns the occupancy status of slot four
		*/
		bool getSlotFour()
		
		/**
			Private default constructor
		*/
		Magazine();
		
}