#pragma once


#include <Imagine/Graphics.h>
#include "../util/const.h"
#include "../util/Vect2D.h"
#include "../util/ResourceManager.h"

class UIComponent {
protected:
    Vect2D position;
    int width, height;
    bool activated;
public:
    UIComponent(const int width, const int height, const Vect2D &position);

    /// Draw component in place
    virtual void draw(const ResourceManager &resourceManager) const = 0;

    /// Get component position
    /// \return component position on windows
    Vect2D getPosition() const;

    /// Get if the component is active (showing and can interact)
    /// \return is activated
    const bool isActivated() const;

    /// Set if the component should be drawn and handle clicks
    /// \param activate
    void setActivated(bool activate);
};