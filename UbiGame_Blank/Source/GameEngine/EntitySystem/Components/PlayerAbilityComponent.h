#pragma once

#include "../Component.h"
#include "HookComponent.h"

namespace Game
{
    class PlayerAbilityComponent : public GameEngine::Component
    {
    private:
            HookComponent* hook = nullptr;
    public:

        virtual void Update() override;
        virtual void OnAddToWorld() override;
    };
}