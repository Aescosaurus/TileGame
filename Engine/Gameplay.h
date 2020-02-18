#pragma once

#include "Keyboard.h"
#include "TileMap.h"
#include "Player.h"
#include "Level.h"
#include "FrameTimer.h"
#include "Lantern.h"
#include "Door.h"
#include "BasicGate.h"
#include "Replicator.h"
#include "StepGate.h"
#include "Turret.h"
#include "Teleporter.h"
#include "Enemy.h"
#include "AutoShooter.h"

class Gameplay
{
public:
	Gameplay( const Keyboard& kbd,TileMap& tilemap );

	void Update();
	void Draw();
private:
	void Load( const std::string& levelName );
	std::string GenerateLevelName() const;
private:
	const Keyboard& kbd;
	TileMap& tilemap;

	FrameTimer ft;
	Level level;
	LevelObject::UpdateInfo updateInfo;
	std::vector<PLevelObjectArr> levelObjects;
	Player guy;
	Door door;
	int curLevel = 0;
	bool canAdvanceLevel = false;
	CSoundPtr exitSound = SoundCodex::Fetch( "Sounds/Door.wav" );
	CSoundPtr music = SoundCodex::Fetch( "Sounds/Puzzle01.wav" );
};