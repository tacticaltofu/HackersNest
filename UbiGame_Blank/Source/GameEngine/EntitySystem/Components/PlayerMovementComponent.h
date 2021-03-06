#pragma once

#include "../Component.h"
#include "HookComponent.h"

namespace Game
{
    class PlayerMovementComponent : public GameEngine::Component
    {
        float destination_x = 150.0f;
        float destination_y = 150.0f;
        float inputAmount = 0.0f;
    public:
        virtual void Update() override;
        virtual void OnAddToWorld() override;
        bool death = false;
        Game::HookComponent*hook = nullptr;
        float rooted = 0.f;
    };
}