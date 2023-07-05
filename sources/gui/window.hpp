#ifndef KUS_WINDOW_HPP
#define KUS_WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

#include <map>
#include <vector>

#include "domain/error_message.hpp"
#include "domain/string.hpp"
#include "domain/type.hpp"

#include "type.hpp"

namespace gui
{
class Window
{
public:
    static Window& getInstance() noexcept;

    void draw(sf::Text& aTarget) noexcept;
    void draw(sf::Sprite& aTarget) noexcept;

    void clear() noexcept;
    void display() noexcept;
    void close() noexcept;

    void setView(const sf::View& aView) noexcept;

    // bool pollEvent(sf::Event& event) const noexcept;

private:
    Window() noexcept;

    sf::RenderWindow mWindow;
};
} // namespace gui

#endif // !KUS_WINDOW_HPP
