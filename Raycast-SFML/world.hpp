#pragma once

#include <cstdint>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

namespace world
{
    struct Player
    {
        // not from the player's perspective - from a top down perspective
        sf::Vector2f position;
        sf::Vector2f face;
        sf::Vector2f cameraPlane;

        // amount of movement and rotation to update position and face by each frame
        float move;
        float rotate;

        // squares / second
        static constexpr float moveSpeed = 5.f;

        // radians / second
        static constexpr float rotSpeed = 3.f;
    };

    enum class Square : uint8_t
    {
        Empty = 0,
        Outer = 1,
        Inner1 = 2,
        Inner2 = 3,
        Column = 4,
    };

    static const sf::Color floorColor = sf::Color{ 244, 239, 203 };
    static const sf::Color ceilingColor = sf::Color{ 111, 163, 247 };

    constexpr size_t width = 32u;
    constexpr size_t height = 32u;

    sf::Color color(sf::Vector2u sqr) noexcept;
    Square map(sf::Vector2u pos) noexcept;
    Square map(sf::Vector2f pos) noexcept;
}
