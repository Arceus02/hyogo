#include "BuyableEntity.h"

BuyableEntity::BuyableEntity(const Asset &asset,
							 std::string name,
							 int maxHp,
							 int viewRange)
		: Entity(asset,
				 name,
				 maxHp,
				 viewRange) {}