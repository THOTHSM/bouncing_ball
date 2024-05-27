#include <SFML/Graphics.hpp>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bouncing Ball");

    // Define the ball
    sf::CircleShape ball(20.0f);
    ball.setFillColor(sf::Color::Red);
    ball.setPosition(400.0f, 300.0f);

    // Ball properties
    sf::Vector2f velocity(0.2f, 0.2f);

    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Update the ball's position
        sf::Vector2f position = ball.getPosition();
        position += velocity;

        // Check for collisions with the window borders and reverse direction if necessary
        if (position.x < 0 || position.x + ball.getRadius() * 2 > window.getSize().x) {
            velocity.x = -velocity.x;
        }
        if (position.y < 0 || position.y + ball.getRadius() * 2 > window.getSize().y) {
            velocity.y = -velocity.y;
        }

        ball.setPosition(position);

        // Clear the window
        window.clear(sf::Color::Black);

        // Draw the ball
        window.draw(ball);

        // Display the contents of the window
        window.display();
    }

    return 0;
}

