#include "collsion.h"

bool isCollision(Player& p, Object& o) 
{
	SDL_Rect object, player;
	object = o.getObject();
	player = p.getPlayer();

	if (object.x + object.w >= player.x &&
		player.x + player.w >= object.x &&
		object.y + object.h >= player.y &&
		player.y + player.h >= object.y) return true;
	else return false;
};
/*
R - right
L - left
U - up
D - down
(i can add enum here)
*/
char directionOfCollision(Player& p, Object& o, bool col) {
	
	if (!col) return 'N';

	SDL_Rect object, player;
	player = p.getPlayer();
	object = o.getObject();

	//find the lowest path between sides
	int right = player.x + player.w - object.x;
	int left = object.x + object.w - player.x;
	int down = player.y + player.h - object.y;
	int up = object.y + object.h - player.y;

	int minValue = std::min({ left, right, up, down });
	
	if (minValue == left) return 'L';
	else if (minValue == right) return 'R';
	else if (minValue == up) return 'U';
	else return 'D';
}
//char directionOfCollision(Player& p, Object& o, bool col)
//{
//	SDL_Rect object, player;
//	object = o.getObject();
//	player = p.getPlayer();
//
//	if (col) {
//		int playerCenterX = player.x + player.w / 2;
//		int playerCenterY = player.y + player.h / 2;
//		int objectCenterX = object.x + object.w / 2;
//		int objectCenterY = object.y + object.h / 2;
//
//		int diffrenceX = playerCenterX - objectCenterX;
//		int diffrenceY = playerCenterY - objectCenterY;
//
//		int absX = std::abs(diffrenceX);
//		int absY = std::abs(diffrenceY);
//
//		if (absX > absY) {
//			if (diffrenceX > 0)
//			{
//				return 'L';
//			}
//			else {
//				
//				return 'R';
//			}
//		}
//		else {
//			if (diffrenceY > 0) 
//			{
//				
//				return 'U';
//			}
//			else 
//			{
//				
//				return 'D';
//			}
//		}
//	}
//	else
//	return 'N';
//}
