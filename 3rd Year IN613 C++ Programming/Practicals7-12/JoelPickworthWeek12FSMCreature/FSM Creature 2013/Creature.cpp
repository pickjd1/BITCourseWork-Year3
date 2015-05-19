#include "StdAfx.h"
#include "Creature.h"

//====================================================
// Creature Constructor
//====================================================
Creature::Creature(Graphics^ startCanvas, Random^ startRandom, int startWorldWidth, int startWorldHeight, String^ imageFileName)
: Thing(startCanvas, startRandom, startWorldWidth, startWorldHeight, imageFileName)
{
	creatureState = ECreatureState::WANDERING;
	eatingTicks = 0;
	wanderingTicks = 0;
	wanderingTime = rGen->Next(wanderingLimit) + 10;

	radius /= 2;	// creatures start out small and grow as they eat
	sensingRange = radius * 2;

	ChangeRandomDirection();
}

// FSM Methods

//====================================================
// Update State
// Passed in an array of all the food objects in the universe
// Passed in an array of all the obstacle objects in the universe
//====================================================

void Creature::UpdateState(array<Thing^>^ foodInWorld, array<Thing^>^ obstaclesInWorld)
{
	// Returns the index in foodInWorld of first food found in range. If nothing found, returns -1
	int nearFoodIndex = findNearIndex(foodInWorld);

	// Returns the index in obstaclesInWorld of first obstacle found in range. If nothing found, returns -1
	int nearObstacleIndex = findNearIndex(obstaclesInWorld);

	switch(creatureState)
	{
	case ECreatureState::EATING:
		//ADD CODE HERE

		if (eatingTicks >= eatingTime)
		{
			foodInWorld[myFoodIndex]->isAlive = false;
			radius = radius * 1.5;
			creatureState = WANDERING;
		}

		// If eating time is up
		//	Kill the food you just ate by setting its isAlive to false
		//	Increment your radius property to grow
		//	Change to WANDERING state

		break; // end EATING

	case ECreatureState::ORIENTING:
		//ADD CODE HERE

		//PerformAction()::
		wanderingTicks = 0;
		creatureState = WANDERING;


		// Only spend one cycle in this state (see PerformAction...)
		// Set wanderingTicks to 0 to begin counting wandering time
		// Change to WANDERING state

		break; // end ORIENTING

	case ECreatureState::WANDERING:
		//ADD CODE HERE

		if (nearFoodIndex > 0)
		{
			eatingTicks = 0;
			myFoodIndex = nearFoodIndex;
			creatureState = EATING;
		}
		
		else 
		{
			if (nearObstacleIndex > 0)
			{
				creatureState = ORIENTING;
			}
		}
		// If you are near food...
		//	Set eatingTicks to 0
		//	Store the index of prey in variable myFoodIndex
		//	Change to EATING state

		// else, if you are near an obstacle
		//	change to ORIENTING state

		break; // end WANDERING
	} // end switch
} // end UpdateState

//====================================================
// PerformAction
//====================================================

void Creature::PerformAction()
{
	switch(creatureState)
	{
		case ECreatureState::EATING:
			//ADD CODE HERE

			eatingTicks++;

			// Increment eatingTicks to record how long you are in the EATING state
			break; // end EATING

		case ECreatureState::ORIENTING:
			//ADD CODE HERE

			ChangeRandomDirection();
			Move();
			// Turn to a new direction by calling ChangeRandomDirection(), 
			// a method inherited from Thing class.
			// Take a step or two to get out of range of the obstacle you encountered

			break; // end ORIENTING

		case ECreatureState::WANDERING:
			//ADD CODE HERE

			Move();
			wanderingTicks++;

			if (wanderingTicks >= wanderingTime)
			{
				ChangeRandomDirection();
			}

			// Move
			// Increment wanderingTicks to record how long you are in the WANDERING state
			// If you've been wandering more than wanderingTime ticks, change direction (call ChangeRandomDirection())

			break; // end WANDERING
		} // end switch
} // end performAction


//====================================================
// Returns the index of the first Thing it finds in range
//====================================================
int Creature::findNearIndex(array<Thing^>^ otherGuys)
{
	int foundIndex = -1;

	for (int i=0; i<otherGuys->Length; i++)
	{
		double distance = ComputeDistance(otherGuys[i]);
		if ((otherGuys[i]->isAlive) && (distance < sensingRange))
		{
			foundIndex = i;
			break;
		}
	}

	return foundIndex;
}