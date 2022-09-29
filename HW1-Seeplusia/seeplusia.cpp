#include "seeplusia.hpp"
#include "mover.hpp"

int applesLeft = 20, nCrystalsFound = 0;
string gameState = "Running";

string currentState = "Enchanted Forest";

string enchantedForest = "Enchanted Forest",
	   sandsOFQuick = "Sands of Quick",
	   wampireCove = "Wampire Cove",
	   marshOFUndead = "Marsh of Undead",
	   swampsOFDespair = "Swamps of Despair",
	   elvinWaterfall = "Elvin Waterfall",
	   werewolfHill = "Werewolf Hill",
	   eistenTunnel = "Eisten Tunnel",
	   applesOrchard = "Apple's Orchard",
	   bridgeOFDeath = "Bridge of Death",
	   wizardsCastle = "Wizard's Castle";

bool isCrystal1Available = true, // Marsh of Undead crystal availability
	isCrystal2Available = true,	 // Swampos of Despair crystal availability
	isCrystal3Available = true,	 // Eisten Tunnel crystal availability
	isCrystal4Available = true;	 // Werewolf Hill crystal availability

// This is a demo implementation of makeMove function
// It doesn't follow the game rules at all
// You have to implement it according to game logic

void makeMove(string direction)
{
	// Player would only move if the game is running.
	if (gameState == "Running")
	{

		if (direction == "East")
		{
			// When Right Arrow is pressed

			if (currentState == enchantedForest)
			{
				moveEast();
				applesLeft -= 1;
				currentState = sandsOFQuick;
				gameState = "Lost";
			}
			else if (currentState == wampireCove)
			{
				moveEast();
				applesLeft -= 1;
				currentState = marshOFUndead;

				if (isCrystal1Available)
				{
					nCrystalsFound++;
					isCrystal1Available = false;
				}
			}
			else if (currentState == swampsOFDespair)
			{
				moveEast();
				applesLeft -= 1;
				currentState = wampireCove;
			}
			else if (currentState == elvinWaterfall)
			{
				moveEast();
				applesLeft -= 2;
				currentState = werewolfHill;
				if (isCrystal4Available)
				{
					nCrystalsFound++;
					isCrystal4Available = false;
				}
			}
			else if (currentState == eistenTunnel)
			{
				moveEast();
				applesLeft -= 2;
				currentState = elvinWaterfall;
			}
			else
			{
				applesLeft--;
			}
		}

		else if (direction == "West")
		{
			// When Left Arrow is pressed

			if (currentState == marshOFUndead)
			{
				moveWest();
				applesLeft--;
				currentState = wampireCove;
			}
			else if (currentState == wampireCove)
			{
				moveWest();
				applesLeft--;
				currentState = swampsOFDespair;
				if (isCrystal2Available)
				{
					nCrystalsFound++;
					isCrystal2Available = false;
				}
			}
			else if (currentState == applesOrchard)
			{
				moveWest();
				applesLeft--;
				currentState = werewolfHill;
				if (isCrystal4Available)
				{
					nCrystalsFound++;
					isCrystal4Available = false;
				}
			}
			else if (currentState == werewolfHill)
			{
				moveWest();
				applesLeft -= 2;
				currentState = elvinWaterfall;
			}
			else if (currentState == elvinWaterfall)
			{
				moveWest();
				applesLeft -= 2;
				currentState = eistenTunnel;
				if (isCrystal3Available)
				{
					nCrystalsFound++;
					isCrystal3Available = false;
				}
			}
			else if (currentState == bridgeOFDeath)
			{
				if (nCrystalsFound == 4 && applesLeft >= 5)
				{
					moveWest();
					currentState = wizardsCastle;
					applesLeft -= 5;
					gameState = "Won";
				}
				else
				{
					gameState = "Lost";
				}
			}
			else
			{
				applesLeft--;
			}
		}
		else if (direction == "North")
		{
			// When Up Arrow is pressed

			if (currentState == wampireCove)
			{
				moveNorth();
				applesLeft -= 3;
				currentState = enchantedForest;
			}
			else if (currentState == werewolfHill)
			{
				moveNorth();
				applesLeft -= 3;
				currentState = wampireCove;
			}
			else if (currentState == swampsOFDespair)
			{
				moveNorth();
				applesLeft--;
				currentState = bridgeOFDeath;
				if (nCrystalsFound < 4 || applesLeft < 5)
				{
					gameState = "Lost";
				}
			}
			else if (currentState == swampsOFDespair)
			{
				moveNorth();
				applesLeft--;
				currentState = bridgeOFDeath;
			}
			else if (currentState == eistenTunnel)
			{
				if (nCrystalsFound >= 3 && applesLeft >= 10)
				{
					applesLeft -= 10;

					moveNorth();
					moveNorth();
					currentState = wizardsCastle;
					gameState = "Won";
				}
			}
			else
			{
				applesLeft--;
			}
		}
		else if (direction == "South")
		{
			// When Down Arrow is pressed

			if (currentState == enchantedForest)
			{

				moveSouth();
				applesLeft -= 3;
				currentState = wampireCove;
			}
			else if (currentState == wampireCove)
			{
				moveSouth();
				applesLeft -= 3;
				currentState = werewolfHill;
				if (isCrystal4Available)
				{
					nCrystalsFound++;
					isCrystal4Available = false;
				}
			}
			else if (currentState == marshOFUndead)
			{
				moveSouth();
				applesLeft--;
				currentState = applesOrchard;
				applesLeft += 6;
			}
			else
			{
				applesLeft--;
			}
		}
		// Check after each move if the player dies due to starvation or sands of quick
		if (applesLeft <= 0)
		{
			gameState = "Lost";
		}
	}
}