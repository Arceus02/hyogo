#include "BuyableEntity.h"

BuyableEntity::BuyableEntity(std::string pathToAsset,
							 int maxHp,
							 int viewRange)
		: Entity(pathToAsset,
				 maxHp,
				 viewRange) {}