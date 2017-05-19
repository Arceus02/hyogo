#pragma once

#include "Field.h"
#include <vector>
#include "../util/const.h"
#include "../util/Vect2D.h"
#include "../util/Asset.h"
#include "../util/ResourceManager.h"
#include <Imagine/Graphics.h>


enum TerrainType {
    MEADOW, FOREST, RIVER
};

AssetId getTerrainTypeAssetId(TerrainType terrainType);

class Map {
private:
    int width, height;
    std::vector<TerrainType> terrainType;
    std::vector<Field> fields;
public:
    Map(int width, int height);

    /// Set map terrain type at specified coordinates
    /// \param x
    /// \param y
    /// \param terrainType
    void setTerrainType(int x, int y, TerrainType terrainType);

    /// Get map terrain type at specified coordinates
    /// \param x
    /// \param y
    /// \return
    TerrainType getTerrainType(int x, int y) const;

    /// Add field to map
    /// \param field
    void addField(Field &field);

    /// Is there a field at coordinates
    /// \param x
    /// \param y
    /// \return
    bool isField(int x, int y);

    /// Get field on map at coordinates
    /// \param x
    /// \param y
    /// \return
    Field &getField(int x, int y);

    /// Draw fields on map
    /// \param resourceManager
    /// \param viewOffset
    /// \param minRender
    /// \param maxRender
    void draw(const ResourceManager &resourceManager, const Vect2D &viewOffset, const Vect2D &minRender,
              const Vect2D &maxRender) const;

    const int getWidth() const;

    const int getHeight() const;
};
