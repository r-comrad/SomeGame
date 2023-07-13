#include "gui.hpp"

#include "window.hpp"

// gui::GUI::GUI() noexcept
// {
//     // mScenes.emplace_back();
// }

void
gui::GUI::draw(const std::vector<Scene>& aScenes) noexcept
{

    auto& window = Window::getInstance();

    window.clear();
    for (auto& i : aScenes) i.draw();
    window.display();
}

// void
// gui::GUI::update() noexcept
// {
// }
