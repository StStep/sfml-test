
#include "Blocks.hpp"

#include <SFML/Graphics.hpp>

#include <vector>

class Entities : public sf::Drawable, public sf::Transformable
{
public:

    bool load(sf::Vector2f dim, unsigned int count)
    {
        // resize the vertex array to fit the level size
        m_size = count;
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(m_size * 8);

        m_halfDim.x = dim.x/2.f;
        m_halfDim.y = dim.y/2.f;

        for (unsigned int i = 0; i < m_size; ++i)
        {
            setPos(i, sf::Vector2f(0.f, 0.f));
        }

        return true;
    }

    void setPos(const std::vector<sf::Vector2f> &pos)
    {
        for (unsigned int i = 0; i < m_size; ++i)
        {
            setPos(i, pos[i]);
        }
    }

    void setPos(unsigned int i, sf::Vector2f pos)
    {
        sf::Vertex* quad = &m_vertices[i * 8];

        // Outer
        quad[0].position = sf::Vector2f(pos.x - m_halfDim.x, pos.y + m_halfDim.y);
        quad[1].position = sf::Vector2f(pos.x + m_halfDim.x, pos.y + m_halfDim.y);
        quad[2].position = sf::Vector2f(pos.x + m_halfDim.x, pos.y - m_halfDim.y);
        quad[3].position = sf::Vector2f(pos.x - m_halfDim.x, pos.y - m_halfDim.y);
        quad[0].color = sf::Color::White;
        quad[1].color = sf::Color::White;
        quad[2].color = sf::Color::White;
        quad[3].color = sf::Color::White;

        // Inner
        sf::Color color;
        if (i % 4 == 0 )
        {
            color = sf::Color::Blue;
        }
        else if (i % 4 == 1)
        {
            color = sf::Color::Red;
        }
        else if (i % 4 == 2)
        {
            color = sf::Color::Yellow;
        }
        else
        {
            color = sf::Color::Green;
        }

        quad[4].position = sf::Vector2f(pos.x - m_halfDim.x + 1.f, pos.y + m_halfDim.y - 1.f);
        quad[5].position = sf::Vector2f(pos.x + m_halfDim.x - 1.f, pos.y + m_halfDim.y - 1.f);
        quad[6].position = sf::Vector2f(pos.x + m_halfDim.x - 1.f, pos.y - m_halfDim.y + 1.f);
        quad[7].position = sf::Vector2f(pos.x - m_halfDim.x + 1.f, pos.y - m_halfDim.y + 1.f);
        quad[4].color = color;
        quad[5].color = color;
        quad[6].color = color;
        quad[7].color = color;
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    sf::Vector2f m_halfDim;
    sf::VertexArray m_vertices;
    unsigned int m_size;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML Test");

	/* Create a new simulator instance and setup scenario. */
	RVO::RVOSimulator *sim = new RVO::RVOSimulator();
	setupScenario(sim, RVO::Vector2(500.f, 500.f));

    auto ents = Entities();
    ents.load(sf::Vector2f(8.f, 8.f), (unsigned int) sim->getNumAgents());

    sf::VertexArray obstacles;
    obstacles.setPrimitiveType(sf::Quads);
    obstacles.resize(sim->getNumObstacleVertices());
    for (size_t i = 0; i < sim->getNumObstacleVertices(); i++)
    {
        auto v = sim->getObstacleVertex(i);
        obstacles[i] = sf::Vector2f(v.x(), v.y());
        obstacles[i].color = sf::Color::Blue;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (!reachedGoal(sim)) {
            setPreferredVelocities(sim);
            sim->doStep();
            for (unsigned int i = 0; i < sim->getNumAgents(); ++i) {
                auto v = sim->getAgentPosition(i);
                ents.setPos(i, sf::Vector2f(v.x(), v.y()));
            }
        }

        window.clear();
        window.draw(obstacles);
        window.draw(ents);
        window.display();
	}

	delete sim;

    return 0;
}
