#include "BuyableEntity.h"

BuyableEntity::BuyableEntity(std::string pathToAsset,
                             std::string name,
							 int maxHp,
							 int viewRange)
		: Entity(pathToAsset,
                 name,
				 maxHp,
				 viewRange) {}
