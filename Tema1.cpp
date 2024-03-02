#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/object2D.h"
#include "lab_m1/Tema1/Romb.h"
#include "lab_m1/Tema1/Star.h"
#include "lab_m1/Tema1/Inamic.h"

using namespace std;
using namespace m1;



Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}


void Tema1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 first_lane1 = glm::vec3(100, 350, 0);
    glm::vec3 second_lane1 = glm::vec3(100, 200, 0);
    glm::vec3 third_lane1 = glm::vec3(100, 50, 0);
    glm::vec3 first_lane2 = glm::vec3(250, 350, 0);
    glm::vec3 second_lane2 = glm::vec3(250, 200, 0);
    glm::vec3 third_lane2 = glm::vec3(250, 50, 0);
    glm::vec3 first_lane3 = glm::vec3(400, 350, 0);
    glm::vec3 second_lane3 = glm::vec3(400, 200, 0);
    glm::vec3 third_lane3 = glm::vec3(400, 50, 0);
    glm::vec3 corner = glm::vec3(20, 50, 0);
    glm::vec3 top1 = glm::vec3(100, 600, 0);
    glm::vec3 top2 = glm::vec3(250, 600, 0);
    glm::vec3 top3 = glm::vec3(400, 600, 0);
    glm::vec3 top4 = glm::vec3(550, 600, 0);
    glm::vec3 out = glm::vec3(1250, 300, 0);
    glm::vec3 p1 = glm::vec3(130, 650, 0);
    glm::vec3 p2 = glm::vec3(280, 650, 0);
    glm::vec3 p3 = glm::vec3(430, 650, 0);
    glm::vec3 p4 = glm::vec3(580, 650, 0);

    glm::vec3 pos_star = glm::vec3(700, 550, 0);
    glm::vec3 HS = glm::vec3(50, 50, 0);

    float squareSide = 100;
    float rectangleheight = 400;
    float rectanglewight = 50;


    // Initialize tx and ty (the translation steps)
    translateX = 0;
    translateY = 0;


    // Initialize sx and sy (the scale factors)
    scaleX = 1;
    scaleY = 1;

    

    Mesh* square1 = object2D::CreateSquare("square1", first_lane1, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square1);
    Mesh* square2 = object2D::CreateSquare("square2", second_lane1, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square2);
    Mesh* square3 = object2D::CreateSquare("square3", third_lane1, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square3);
    Mesh* square4 = object2D::CreateSquare("square4", first_lane2, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square4);
    Mesh* square5 = object2D::CreateSquare("square5", second_lane2, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square5);
    Mesh* square6 = object2D::CreateSquare("square6", third_lane2, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square6);
    Mesh* square7 = object2D::CreateSquare("square7", first_lane3, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square7);
    Mesh* square8 = object2D::CreateSquare("square8", second_lane3, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square8);
    Mesh* square9 = object2D::CreateSquare("square9", third_lane3, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square9);
    Mesh* square10 = object2D::CreateSquare("square10", top1, squareSide, glm::vec3(1, 0.5, 0));
    AddMeshToList(square10);
    Mesh* square11 = object2D::CreateSquare("square11", top2, squareSide, glm::vec3(0, 0, 1));
    AddMeshToList(square11);
    Mesh* square12 = object2D::CreateSquare("square12", top3, squareSide, glm::vec3(1, 1, 0));
    AddMeshToList(square12);
    Mesh* square13 = object2D::CreateSquare("square13", top4, squareSide, glm::vec3(0.5, 0, 0.5));
    AddMeshToList(square13);
    Mesh* square14 = object2D::CreateSquare("viata1", glm::vec3(800, 600, 0), squareSide, glm::vec3(1, 0, 0), true);
    AddMeshToList(square14);
    Mesh* square15 = object2D::CreateSquare("viata2", glm::vec3(950, 600, 0), squareSide, glm::vec3(1, 0, 0), true);
    AddMeshToList(square15);
    Mesh* square16 = object2D::CreateSquare("viata3", glm::vec3(1100, 600, 0), squareSide, glm::vec3(1, 0, 0), true);
    AddMeshToList(square16);

    Mesh* rectangle = object2D::CreateRectangle("rectangle", corner, rectanglewight, rectangleheight, glm::vec3(1, 0, 0), true);
    AddMeshToList(rectangle);

    float rhombusDiagonalLength = 35;
    glm::vec3 CornerR =glm::vec3 (600, 150, 0);
    cxR = CornerR.x + rhombusDiagonalLength/2;
    cyR = CornerR.y + rhombusDiagonalLength/2;

    Mesh* romb = object2D::CreateRomb("romb", glm::vec3(600, 150, 0), glm::vec3(1, 0.5, 0), true);
    AddMeshToList(romb);

    Mesh* romb1 = object2D::CreateRomb("romb1", p1, glm::vec3(1, 0.5, 0), true);
    AddMeshToList(romb1);
    Mesh* romb2 = object2D::CreateRomb("romb2", p2, glm::vec3(0, 0, 1), true);
    AddMeshToList(romb2);
    Mesh* romb3 = object2D::CreateRomb("romb3", p3, glm::vec3(1, 1, 0), true);
    AddMeshToList(romb3);
    Mesh* romb4 = object2D::CreateRomb("romb4", p4, glm::vec3(0.5, 0, 0.5), true);
    AddMeshToList(romb4);

    Mesh* star1 = object2D::CreateStar("star1", glm::vec3(110, 580, 0), 5, 12, glm::vec3(0.5, 0.5, 0.5), true);
    AddMeshToList(star1);
    Mesh* star2 = object2D::CreateStar("star2", glm::vec3(260, 580, 0), 5, 12, glm::vec3(0.5, 0.5, 0.5), true);
    AddMeshToList(star2);
    Mesh* star3 = object2D::CreateStar("star3", glm::vec3(290, 580, 0), 5, 12, glm::vec3(0.5, 0.5, 0.5), true);
    AddMeshToList(star3);
    Mesh* star4 = object2D::CreateStar("star4", glm::vec3(410, 580, 0), 5, 12, glm::vec3(0.5, 0.5, 0.5), true);
    AddMeshToList(star4);
    Mesh* star5 = object2D::CreateStar("star5", glm::vec3(440, 580, 0), 5, 12, glm::vec3(0.5, 0.5, 0.5), true);
    AddMeshToList(star5);
    Mesh* star6 = object2D::CreateStar("star6", glm::vec3(560, 580, 0), 5, 12, glm::vec3(0.5, 0.5, 0.5), true);
    AddMeshToList(star6);
    Mesh* star7 = object2D::CreateStar("star7", glm::vec3(590, 580, 0), 5, 12, glm::vec3(0.5, 0.5, 0.5), true);
    AddMeshToList(star7);
    Mesh* star8 = object2D::CreateStar("star8", glm::vec3(620, 580, 0), 5, 12, glm::vec3(0.5, 0.5, 0.5), true);
    AddMeshToList(star8);

    Mesh* star = object2D::CreateStar("star", pos_star, 7, 30, glm::vec3(1, 0, 0),true);
    AddMeshToList(star);

    float laturahexagonM = 35;
    float laturahexagonm = 25;
    glm::vec3 Corner = glm::vec3(0,0,0);
    cx = Corner.x + laturahexagonM;
    cy = Corner.y + laturahexagonM;

    Mesh* hexagon1 = object2D::CreateHexagons("hexagon1", out , 35, 25, glm::vec3(1, 0.5, 0), glm::vec3(0, 0.5, 0.5), true, true);
    AddMeshToList(hexagon1);
    Mesh* hexagon2 = object2D::CreateHexagons("hexagon2", out, 35, 25, glm::vec3(0, 0, 1), glm::vec3(0, 0.5, 0.5), true, true);
    AddMeshToList(hexagon2);
    Mesh* hexagon3 = object2D::CreateHexagons("hexagon3", out, 35, 25, glm::vec3(1, 1, 0), glm::vec3(0, 0.5, 0.5), true, true);
    AddMeshToList(hexagon3);
    Mesh* hexagon4 = object2D::CreateHexagons("hexagon4", out, 35, 25, glm::vec3(0.5, 0, 0.5), glm::vec3(0, 0.5, 0.5), true, true);
    AddMeshToList(hexagon4);

    Mesh* hexagonS = object2D::CreateHexagons("hexagonS", HS, 35, 25, glm::vec3(0.5, 0, 0.5), glm::vec3(0, 0.5, 0.5), true, true);
    AddMeshToList(hexagonS);
 //   Mesh* hexagonM = object2D::CreateHexagons("hexagonM", glm::vec3(1250,500,0), 35, 25, glm::vec3(0.5, 0, 0.5), glm::vec3(0, 0.5, 0.5), true, true);
 //   AddMeshToList(hexagonM);

    direction = true;
    ok = false;

}


void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0.3, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::Update(float deltaTimeSeconds)
{

    deltaTime += deltaTimeSeconds;
    if (deltaTime > 4.0f) {
        int randomX = rand() % 1000;
        int randomY = rand() % 700;
        Star::Star stea;
        stea.setCoordinates(randomX, randomY);
        stars.push_back(stea);
        deltaTime = 0;
    }

    for (Star::Star stea : stars) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(stea.getX() - 600, stea.getY() - 400);
        RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
    }


    if (scaleX >= 1)
        ok = false;
    if (scaleX < 0)
        ok = true;

    if (ok)
        scaleX += deltaTimeSeconds;
    else
        scaleX -= deltaTimeSeconds;

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(cx * 1.3, cy * 1.3);
    modelMatrix *= transform2D::Scale(scaleX, scaleX);
    modelMatrix *= transform2D::Translate(-cx*1.3, -cy*1.3);

    
    RenderMesh2D(meshes["hexagonS"], shaders["VertexColor"], modelMatrix);


    if (scaleX >= 1)
        ok = false;
    if (scaleX < 0)
        ok = true;

    if (ok)
        scaleX += deltaTimeSeconds;
    else
        scaleX -= deltaTimeSeconds;

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(cxR, cyR);
    modelMatrix *= transform2D::Scale(scaleX, scaleX);
    modelMatrix *= transform2D::Translate(-cxR, -cyR);
    RenderMesh2D(meshes["romb"], shaders["VertexColor"], modelMatrix);


  /*  if (direction == true) {
        translateX += deltaTimeSeconds * 50;
    }

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(-translateX, 0);
    RenderMesh2D(meshes["hexagonM"], shaders["VertexColor"], modelMatrix);
    */

    delta += deltaTimeSeconds;
    if (delta > timex) {
        Inamic::Inamic hexagon;
        int randomLineIndex = rand() % 3;
        glm::vec3 randomLine;
        switch (randomLineIndex) {
        case 0:
            randomLine = glm::vec3(0, 100, 0);
            hexagon.setCoordinates(0, 100);
            break;
        case 1:
            randomLine = glm::vec3(0, -50, 0);
            hexagon.setCoordinates(0, -50);
            break;
        case 2:
            randomLine = glm::vec3(0, -200, 0);
            hexagon.setCoordinates(0, -200);
            break;
        }
        int randomColorIndex = rand() % 4;
        glm::vec3 randomColor;
        switch (randomColorIndex) {
        case 0:
            randomColor = glm::vec3(1, 0.5, 0);
            break;
        case 1:
            randomColor = glm::vec3(0, 0, 1);
            break;
        case 2:
            randomColor = glm::vec3(1, 1, 0);
            break;
        case 3:
            randomColor = glm::vec3(0.5, 0, 0.5);
            break;
        }
        hexagon.setColor(randomColor);
        hexagon.setLine(randomLine);
        hexagon.setIndexColor(randomColorIndex);
        inamici.push_back(hexagon);
        delta = 0;
    }

    modelMatrix = glm::mat3(1);

    float speed = 50.0f; 

    for (Inamic::Inamic& inamic : inamici) {
        glm::vec3 line = inamic.getLine();
        float x = inamic.getX();
        float y = inamic.getY();
        glm::vec3 color = inamic.getColor();

        if (direction == true) {
            x -= deltaTimeSeconds * speed;
        }

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(x, y);

        switch (inamic.getIndexColor()) {
        case 0:
            RenderMesh2D(meshes["hexagon1"], shaders["VertexColor"], modelMatrix);
            break;
        case 1:
            RenderMesh2D(meshes["hexagon2"], shaders["VertexColor"], modelMatrix);
            break;
        case 2:
            RenderMesh2D(meshes["hexagon3"], shaders["VertexColor"], modelMatrix);
            break;
        case 3:
            RenderMesh2D(meshes["hexagon4"], shaders["VertexColor"], modelMatrix);
            break;
        }

        inamic.setCoordinates(x, y);
    }


    modelMatrix = glm::mat3(1);


    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square3"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square4"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square5"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square6"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square7"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square8"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square9"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square10"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square11"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square12"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square13"], shaders["VertexColor"], modelMatrix);

    RenderMesh2D(meshes["viata1"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["viata2"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["viata3"], shaders["VertexColor"], modelMatrix); 
    
    RenderMesh2D(meshes["rectangle"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);

    RenderMesh2D(meshes["romb1"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["romb2"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["romb3"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["romb4"], shaders["VertexColor"], modelMatrix);

    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["star2"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["star3"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["star4"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["star5"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["star6"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["star7"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["star8"], shaders["VertexColor"], modelMatrix);


    glm::vec3 center = glm::vec3(700, 550, 0);
    totalRotationAngle += rotationSpeed * deltaTimeSeconds;
    horizontalTranslation += 100.0f * deltaTimeSeconds; 

    glm::mat3 modelMatrix = glm::mat3(1.0f);
    modelMatrix *= transform2D::Translate(center.x + horizontalTranslation, center.y);
    modelMatrix *= transform2D::Rotate(totalRotationAngle);
    modelMatrix *= transform2D::Translate(-center.x, -center.y);

    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);

}


void Tema1::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
    // if (IS_BIT_SET(button, GLFW_MOUSE_BUTTON_LEFT)) {
    //	printf("%d %d \n", mouseX, mouseY);
	//}
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}
