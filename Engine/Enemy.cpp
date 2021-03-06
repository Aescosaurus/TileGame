#include "Enemy.h"

Enemy::Enemy( const Vei2& pos )
	:
	LevelObject( pos,style.Generate() )
{}

void Enemy::Update( UpdateInfo& info )
{
	for( auto& arrow : info.levelObjects[int( Type::Arrow )] )
	{
		if( arrow->GetPos() == pos )
		{
			hitSound->Play();
		}
	}

	if( info.player.GetPos() != playerPos )
	{
		lastTry = false;
		Update2( info );
	}
}

void Enemy::Update2( UpdateInfo& info )
{
	playerPos = info.player.GetPos();

	const auto testPos = pos + Vei2::Right() * dir;
	if( info.level.GetTile( testPos ) != Level::TileType::Wall &&
		CheckPos( testPos,info ) )
	{
		pos = testPos;
	}
	else if( !lastTry )
	{
		dir *= -1;
		lastTry = true;
		Update2( info );
	}
}
