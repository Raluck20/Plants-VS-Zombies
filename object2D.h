#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D
{

    Mesh* CreateSquare(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateRectangle(const std::string& name, glm::vec3 leftBottomCorner, float width, float height, glm::vec3 color, bool fill = false);
    Mesh* CreateRomb(const std::string& name, glm::vec3 position, glm::vec3 color, bool fill);
    Mesh* CreateHexagons(const std::string& name, glm::vec3 center, float outerSideLength, float innerSideLength, glm::vec3 outerColor, glm::vec3 innerColor, bool fillOuter, bool fillInner);
    Mesh* CreateStar(const std::string& name, glm::vec3 center, float outerRadius, float innerRadius, glm::vec3 color, bool fill);


}


