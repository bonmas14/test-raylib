/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Title Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "screens.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;
static int hovered = 0;
//----------------------------------------------------------------------------------
// Title Screen Functions Definition
//----------------------------------------------------------------------------------

// Title Screen Initialization logic
void InitTitleScreen(void)
{
    // TODO: Initialize TITLE screen variables here!
    framesCounter = 0;
    finishScreen = 0;
	hovered = 0;
}

// Title Screen Update logic
void UpdateTitleScreen(void)
{
    // TODO: Update TITLE screen variables here!

	// Press enter or tap to change to GAMEPLAY screen
	Vector2 position = GetMousePosition();
	if (position.x > 20 && position.x < (MeasureText("start", 40) + 20)
		&& position.y < (GetScreenHeight() - 20) && position.y >(GetScreenHeight() - 60))
	{
		if (!IsSoundPlaying(fxCoin) && !hovered)
		{
			PlaySound(hover);
			hovered = 1;
		}

		if (IsGestureDetected(GESTURE_TAP))
		{
			finishScreen = 2; 
			PlaySound(fxCoin);
		}
	}
	else
	{
		hovered = 0;
	}

}

// Title Screen Draw logic
void DrawTitleScreen(void)
{
	if (hovered)
	{
		DrawRectangle(20, GetScreenHeight() - 60, MeasureText("start", 40) + 20, 40, Fade(WHITE, 0.2f));
	}

    DrawRectangleLines(20, GetScreenHeight() - 60, MeasureText("start", 40) + 20, 40, WHITE);
    DrawText("start", 30, GetScreenHeight() - 60, 40, WHITE);
}

void UnloadTitleScreen(void)
{

}

// Title Screen should finish?
int FinishTitleScreen(void)
{
    return finishScreen;
}