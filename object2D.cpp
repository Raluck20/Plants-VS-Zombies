#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"
#include "object2D.h"
#include "object2D.h"
#include "object2D.h"


Mesh* object2D::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateRectangle(const std::string& name, glm::vec3 leftBottomCorner, float width, float height, glm::vec3 color, bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices;

    if (fill) {
        vertices.push_back(VertexFormat(corner, color));
        vertices.push_back(VertexFormat(corner + glm::vec3(width, 0, 0), color));
        vertices.push_back(VertexFormat(corner + glm::vec3(width, height, 0), color));
        vertices.push_back(VertexFormat(corner + glm::vec3(0, height, 0), color));
    }
    else {
        vertices.push_back(VertexFormat(corner, color));
        vertices.push_back(VertexFormat(corner + glm::vec3(width, 0, 0), color));
        vertices.push_back(VertexFormat(corner + glm::vec3(width, height, 0), color));
        vertices.push_back(VertexFormat(corner + glm::vec3(0, height, 0), color));
    }

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3, 0, 2 };

    if (!fill) {
        rectangle->SetDrawMode(GL_LINE_LOOP);
    }

    rectangle->InitFromData(vertices, indices);
    return rectangle;
}

Mesh* object2D::CreateRomb(
    const std::string& name,
    glm::vec3 position,
    glm::vec3 color,
    bool fill)
{
    float rombDiagonalLength = 40;
    float rombHalfDiagonal = rombDiagonalLength / 2.0f;

    std::vector<VertexFormat> rombVertices =
    {
        VertexFormat(position + glm::vec3(0, rombDiagonalLength, 0), color),     // Top
        VertexFormat(position + glm::vec3(rombHalfDiagonal, 0, 0), color),       // Right
        VertexFormat(position + glm::vec3(0, -rombDiagonalLength, 0), color),    // Bottom
        VertexFormat(position + glm::vec3(-rombHalfDiagonal, 0, 0), color)       // Left
    };

    std::vector<unsigned int> rombIndices = { 0, 1, 2, 2, 3, 0 };

    float rectWidth = 50;
    float rectHeight = 20;

    // Lipesc dreptunghiul de romb
    glm::vec3 rectCorner = position + glm::vec3(rombHalfDiagonal-10, -rectHeight / 2.0f, 0);

    std::vector<VertexFormat> rectVertices;
    rectVertices.push_back(VertexFormat(rectCorner, color));
    rectVertices.push_back(VertexFormat(rectCorner + glm::vec3(rectWidth, 0, 0), color));
    rectVertices.push_back(VertexFormat(rectCorner + glm::vec3(rectWidth, rectHeight, 0), color));
    rectVertices.push_back(VertexFormat(rectCorner + glm::vec3(0, rectHeight, 0), color));

    Mesh* rombfinal = new Mesh(name);
    std::vector<unsigned int> rectIndices = { 0, 1, 2, 3, 0, 2 };

    rombfinal->vertices.insert(rombfinal->vertices.end(), rombVertices.begin(), rombVertices.end());
    rombfinal->vertices.insert(rombfinal->vertices.end(), rectVertices.begin(), rectVertices.end());

    rombfinal->indices.insert(rombfinal->indices.end(), rombIndices.begin(), rombIndices.end());
    unsigned int rectIndexOffset = rombVertices.size();
    for (unsigned int index : rectIndices) {
        rombfinal->indices.push_back(index + rectIndexOffset);
    }

    if (!fill) {
        rombfinal->SetDrawMode(GL_LINE_LOOP);
    }

    rombfinal->InitFromData(rombfinal->vertices, rombfinal->indices);

    return rombfinal;
}


Mesh* object2D::CreateHexagons(
    const std::string& name,
    glm::vec3 center,
    float HEXASideLength,
    float hexaSideLength,
    glm::vec3 HEXAColor,
    glm::vec3 hexaColor,
    bool fillHEXA,
    bool fillhexa)
{
    std::vector<VertexFormat> vertices;
    std::vector<unsigned int> indices;

    for (int i = 0; i < 6; ++i) {
        float angle = glm::radians(60.0f * i);
        glm::vec3 hexaVertexPosition = center + glm::vec3(hexaSideLength * cos(angle), hexaSideLength * sin(angle), 0);
        vertices.emplace_back(hexaVertexPosition, hexaColor);
    }

    vertices.emplace_back(center, hexaColor);

    for (int i = 0; i < 6; ++i) {
        indices.push_back(i);
        indices.push_back((i + 1) % 6);
        indices.push_back(6);
    }

    for (int i = 0; i < 6; ++i) {
        float angle = glm::radians(60.0f * i);
        glm::vec3 HEXAVertexPosition = center + glm::vec3(HEXASideLength * cos(angle), HEXASideLength * sin(angle), 0);
        vertices.emplace_back(HEXAVertexPosition, HEXAColor);
    }

    vertices.emplace_back(center, HEXAColor);

    for (int i = 0; i < 6; ++i) {
        indices.push_back(i + 7); 
        indices.push_back((i + 1) % 6 + 7);
        indices.push_back(13);
    }

    Mesh* hexagon = new Mesh(name);

    if (fillHEXA || fillhexa) {
        hexagon->SetDrawMode(GL_TRIANGLES);
    }
    else {
        hexagon->SetDrawMode(GL_LINE_LOOP);
    }

    hexagon->InitFromData(vertices, indices);

    return hexagon;
}

Mesh* object2D::CreateStar(
    const std::string& name,
    glm::vec3 center,
    float razaExterioara,
    float razaInterioara,
    glm::vec3 color,
    bool fill)
{
    std::vector<VertexFormat> vertices;
    std::vector<unsigned int> indices;

    float dreptUnghi = glm::radians(125.0f);

    for (int i = 0; i < 5; ++i) {
        float unghiExterior = glm::radians(360.0f * i / 5) + dreptUnghi;
        glm::vec3 exteriorVertexPosition = center + glm::vec3(razaExterioara * cos(unghiExterior), razaExterioara * sin(unghiExterior), 0);
        vertices.emplace_back(exteriorVertexPosition, color);

        float unghiInterior = glm::radians(360.0f * (i + 0.5f) / 5) + dreptUnghi;
        glm::vec3 interiorVertexPosition = center + glm::vec3(razaInterioara * cos(unghiInterior), razaInterioara * sin(unghiInterior), 0);
        vertices.emplace_back(interiorVertexPosition, color);
    }

    vertices.emplace_back(center, color);

    for (int i = 0; i < 5; ++i) {

        indices.push_back(i * 2);
        indices.push_back((i * 2 + 1) % 10);
        indices.push_back(10);

        indices.push_back((i * 2 + 1) % 10);
        indices.push_back((i * 2 + 2) % 10);
        indices.push_back(10);

        indices.push_back((i * 2 + 2) % 10);
        indices.push_back((i * 2 + 3) % 10);
        indices.push_back(i * 2);

        indices.push_back((i * 2 + 3) % 10);
        indices.push_back((i * 2 + 4) % 10);
        indices.push_back(i * 2);
    }

    Mesh* star = new Mesh(name);

    if (fill) {
        star->SetDrawMode(GL_TRIANGLES);
    }
    else {
        star->SetDrawMode(GL_LINE_LOOP);
    }

    star->InitFromData(vertices, indices);

    return star;
}
