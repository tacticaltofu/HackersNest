#include "NetComponent.h"
#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>
#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames
#include "PlayerMovementComponent.h"
#include "PlayerAbilityComponent.h"
#include <math.h>

using namespace Game;

void NetComponent::Update()
{
    Component::Update();

    const float dt = GameEngine::GameEngineMain::GetTimeDelta();

    sf::Vector2f displacement{ 0.0f,0.0f };

    float inputAmount = 125.0f;

    sf::Vector2f windowPos{ static_cast<float>(GetEntity()->window->getPosition().x), static_cast<float>(GetEntity()->window->getPosition().y) };

    sf::Vector2f destination{destination_x, destination_y};
    sf::Vector2f pos_diff = destination - GetEntity()->GetPos() - windowPos;

    float vector_length = sqrt(pos_diff.x * pos_diff.x + pos_diff.y * pos_diff.y);

    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);

    sf::Vector2f unit{0.f,1.f};

    float dot = pos_diff.x*unit.x + pos_diff.y*unit.y;
    float det = pos_diff.x*unit.y - pos_diff.y*unit.x;
    float angle = 180*atan(dot/det)/3.14;
    if(pos_diff.x < 0){
        angle += 180;
    }
    GetEntity()->SetRotation(angle);

    if (liveTime > 0) {
        displacement.x += inputAmount * (pos_diff.x / vector_length) * dt;
        displacement.y += inputAmount * (pos_diff.y / vector_length) * dt;
        liveTime -= dt;
    } else {
        GameEngine::GameEngineMain::GetInstance()->RemoveEntity(GetEntity());
    }

}  

void NetComponent::OnAddToWorld() {}