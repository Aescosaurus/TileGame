#include "Arrow.h"

Arrow::Arrow( const Vec2& pos,const Vec2& target )
	:
	pos( pos ),
	vel( ( target - ( pos * TileMap::tileSize ) +
		Vec2::Left() * TileMap::padding ).GetNormalized() * speed )
{}

void Arrow::Update( float dt )
{
	pos += vel * dt;
}

void Arrow::Draw( TileMap& tilemap ) const
{
	tilemap.PutPixel( int( pos.x ),int( pos.y ),Colors::Yellow );
}