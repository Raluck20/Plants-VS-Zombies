#pragma once

#include "components/simple_scene.h"
#include "lab_m1/Tema1/Inamic.h"
#include "lab_m1/Tema1/Star.h"


namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

    protected:
        float cx, cy, cxR, cyR;
        glm::mat3 modelMatrix;

        float translateX, translateY;
        float scaleX, scaleY;
        float angularStep;
     
        float totalRotationAngle = 0.0f;
        float horizontalTranslation = 0.0f;
        float rotationSpeed = 2.0f;

        // TODO(student): If you need any other class variables, define them here.

        bool direction,ok;
        float rotation;

        float timex = 5.0f;
        float delta = 0.0f;
        std::vector<Inamic::Inamic> inamici;


        float deltaTime = 0.0f;
        std::vector<Star::Star> stars;

     

    };
}   // namespace m1
