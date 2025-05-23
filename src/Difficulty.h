//
// Created by willw on 04/15/2025.
//
#ifndef DIFFICULTY_H
#define DIFFICULTY_H
#include "Easy.h"
#include "Medium.h"
#include "Hard.h"
void title();
inline void difficulty()
{
    sf :: RenderWindow difficulty;
    difficulty.create(sf :: VideoMode({1920,1080}), "MINESWEEPER", sf :: State :: Fullscreen);
    difficulty.setFramerateLimit(60);
    while (difficulty.isOpen())
    {
        bool mouseHoverEasy,mouseHoverMedium,mouseHoverHard;
        //checks for events that occur while the window is open
        while (const std :: optional event = difficulty.pollEvent())
        {
            //if the user closes the window the program ends
            if (event->is<sf :: Event :: Closed>())
                difficulty.close();
            //closes the window if the user presses the ESC key
            else if (const auto* keyPressed = event->getIf<sf :: Event :: KeyPressed>())
            {
                if (keyPressed->scancode == sf :: Keyboard :: Scancode :: Escape)
                    difficulty.close();
            }
            //sets up buttons for the user to click
            else if (const auto* mouseButtonReleased = event->getIf<sf::Event::MouseButtonReleased>())
            {
                if (mouseButtonReleased->button == sf::Mouse::Button::Left)
                {
                    if (sf::Mouse::getPosition(difficulty).x >=17 && sf::Mouse::getPosition(difficulty).x <=189 && sf::Mouse::getPosition(difficulty).y >=14 && sf::Mouse::getPosition(difficulty).y <=89)
                    {
                        difficulty.close();
                        //title window is reopened
                        title();
                    }
                    else if ((sf::Mouse::getPosition(difficulty).x >=746 && sf::Mouse::getPosition(difficulty).x <=1170) && (sf::Mouse::getPosition(difficulty).y >= 189 && sf::Mouse::getPosition(difficulty).y <=319))
                    {
                        difficulty.close();
                        //easy window opens
                        Easy();
                    }
                    else if ((sf::Mouse::getPosition(difficulty).x >= 747 && sf::Mouse::getPosition(difficulty).x <= 1174) && (sf::Mouse::getPosition(difficulty).y >= 481 && sf::Mouse::getPosition(difficulty).y <= 605))
                    {
                        difficulty.close();
                        //medium window opens
                        Medium();
                    }
                    else if ((sf::Mouse::getPosition(difficulty).x >= 750 && sf::Mouse::getPosition(difficulty).x <= 1169) && (sf::Mouse::getPosition(difficulty).y >= 743 && sf::Mouse::getPosition(difficulty).y <= 873))
                    {
                        difficulty.close();
                        //hard window opens
                        Hard();
                    }
                }
            }
            //checks if mouse moved in order to highlight buttons
            else if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(difficulty);
                if ((localPosition.x >=746 && localPosition.x <=1170) && (localPosition.y >= 189 && localPosition.y <=319))
                {
                    difficulty.clear(sf :: Color :: Black);
                    sf :: Texture texture("../../src/Minesweeper_difficulty_select_easy.png", false, sf :: IntRect({0,0},{1920,1080}));
                    sf::Sprite sprite(texture);
                    difficulty.draw(sprite);
                    if (sf::Mouse::getPosition(difficulty).x >=17 && sf::Mouse::getPosition(difficulty).x <=189 && sf::Mouse::getPosition(difficulty).y >=14 && sf::Mouse::getPosition(difficulty).y <=89)
                    {
                        sf :: Texture HighlightedBackButton("../../src/backButtonHighlighted.png", false, sf :: IntRect({0,0},{173,77}));
                        sf::Sprite highlightedBackButton(HighlightedBackButton);
                        highlightedBackButton.setPosition({17.f, 14.f});
                        difficulty.draw(highlightedBackButton);
                    }
                    else
                    {
                        sf :: Texture BackButton("../../src/backButton.png", false, sf :: IntRect({0,0},{173,77}));
                        sf::Sprite backButton(BackButton);
                        backButton.setPosition({17.f, 14.f});
                        difficulty.draw(backButton);
                    }
                    difficulty.display();
                    mouseHoverEasy=true;
                }
                else if ((localPosition.x >= 747 && localPosition.x <= 1174) && (localPosition.y >= 481 && localPosition.y <= 605))
                {
                    difficulty.clear(sf :: Color :: Black);
                    sf :: Texture texture("../../src/Minesweeper_difficulty_select_medium.png", false, sf :: IntRect({0,0},{1920,1080}));
                    sf::Sprite sprite(texture);
                    difficulty.draw(sprite);
                    if (sf::Mouse::getPosition(difficulty).x >=17 && sf::Mouse::getPosition(difficulty).x <=189 && sf::Mouse::getPosition(difficulty).y >=14 && sf::Mouse::getPosition(difficulty).y <=89)
                    {
                        sf :: Texture HighlightedBackButton("../../src/backButtonHighlighted.png", false, sf :: IntRect({0,0},{173,77}));
                        sf::Sprite highlightedBackButton(HighlightedBackButton);
                        highlightedBackButton.setPosition({17.f, 14.f});
                        difficulty.draw(highlightedBackButton);
                    }
                    else
                    {
                        sf :: Texture BackButton("../../src/backButton.png", false, sf :: IntRect({0,0},{173,77}));
                        sf::Sprite backButton(BackButton);
                        backButton.setPosition({17.f, 14.f});
                        difficulty.draw(backButton);
                    }
                    difficulty.display();
                    mouseHoverMedium=true;
                }
                else if ((localPosition.x >= 750 && localPosition.x <= 1169) && (localPosition.y >= 743 && localPosition.y <= 873))
                {
                    difficulty.clear(sf :: Color :: Black);
                    sf :: Texture texture("../../src/Minesweeper_difficulty_select_hard.png", false, sf :: IntRect({0,0},{1920,1080}));
                    sf::Sprite sprite(texture);
                    difficulty.draw(sprite);
                    if (sf::Mouse::getPosition(difficulty).x >=17 && sf::Mouse::getPosition(difficulty).x <=189 && sf::Mouse::getPosition(difficulty).y >=14 && sf::Mouse::getPosition(difficulty).y <=89)
                    {
                        sf :: Texture HighlightedBackButton("../../src/backButtonHighlighted.png", false, sf :: IntRect({0,0},{173,77}));
                        sf::Sprite highlightedBackButton(HighlightedBackButton);
                        highlightedBackButton.setPosition({17.f, 14.f});
                        difficulty.draw(highlightedBackButton);
                    }
                    else
                    {
                        sf :: Texture BackButton("../../src/backButton.png", false, sf :: IntRect({0,0},{173,77}));
                        sf::Sprite backButton(BackButton);
                        backButton.setPosition({17.f, 14.f});
                        difficulty.draw(backButton);
                    }
                    difficulty.display();
                    mouseHoverHard=true;
                }
                else
                {
                    difficulty.clear(sf :: Color :: Black);
                    sf :: Texture texture("../../src/Minesweeper_difficulty_select.png", false, sf :: IntRect({0,0},{1920,1080}));
                    sf::Sprite sprite(texture);
                    difficulty.draw(sprite);
                    if (sf::Mouse::getPosition(difficulty).x >=17 && sf::Mouse::getPosition(difficulty).x <=189 && sf::Mouse::getPosition(difficulty).y >=14 && sf::Mouse::getPosition(difficulty).y <=89)
                    {
                        sf :: Texture HighlightedBackButton("../../src/backButtonHighlighted.png", false, sf :: IntRect({0,0},{173,77}));
                        sf::Sprite highlightedBackButton(HighlightedBackButton);
                        highlightedBackButton.setPosition({17.f, 14.f});
                        difficulty.draw(highlightedBackButton);
                    }
                    else
                    {
                        sf :: Texture BackButton("../../src/backButton.png", false, sf :: IntRect({0,0},{173,77}));
                        sf::Sprite backButton(BackButton);
                        backButton.setPosition({17.f, 14.f});
                        difficulty.draw(backButton);
                    }
                    difficulty.display();
                    mouseHoverEasy=false,mouseHoverMedium=false,mouseHoverHard=false;
                }
            }
        }
        //series of if statements to keep buttons highlighted again
        if (mouseHoverEasy==true && mouseHoverMedium==false && mouseHoverHard==false)
        {
            difficulty.clear(sf :: Color :: Black);
            sf :: Texture texture("../../src/Minesweeper_difficulty_select_easy.png", false, sf :: IntRect({0,0},{1920,1080}));
            sf::Sprite sprite(texture);
            difficulty.draw(sprite);
            if (sf::Mouse::getPosition(difficulty).x >=17 && sf::Mouse::getPosition(difficulty).x <=189 && sf::Mouse::getPosition(difficulty).y >=14 && sf::Mouse::getPosition(difficulty).y <=89)
            {
                sf :: Texture HighlightedBackButton("../../src/backButtonHighlighted.png", false, sf :: IntRect({0,0},{173,77}));
                sf::Sprite highlightedBackButton(HighlightedBackButton);
                highlightedBackButton.setPosition({17.f, 14.f});
                difficulty.draw(highlightedBackButton);
            }
            else
            {
                sf :: Texture BackButton("../../src/backButton.png", false, sf :: IntRect({0,0},{173,77}));
                sf::Sprite backButton(BackButton);
                backButton.setPosition({17.f, 14.f});
                difficulty.draw(backButton);
            }
            difficulty.display();
        }
        else if (mouseHoverMedium==true && mouseHoverHard==false && mouseHoverEasy==false)
        {
            difficulty.clear(sf :: Color :: Black);
            sf :: Texture texture("../../src/Minesweeper_difficulty_select_medium.png", false, sf :: IntRect({0,0},{1920,1080}));
            sf::Sprite sprite(texture);
            difficulty.draw(sprite);
            if (sf::Mouse::getPosition(difficulty).x >=17 && sf::Mouse::getPosition(difficulty).x <=189 && sf::Mouse::getPosition(difficulty).y >=14 && sf::Mouse::getPosition(difficulty).y <=89)
            {
                sf :: Texture HighlightedBackButton("../../src/backButtonHighlighted.png", false, sf :: IntRect({0,0},{173,77}));
                sf::Sprite highlightedBackButton(HighlightedBackButton);
                highlightedBackButton.setPosition({17.f, 14.f});
                difficulty.draw(highlightedBackButton);
            }
            else
            {
                sf :: Texture BackButton("../../src/backButton.png", false, sf :: IntRect({0,0},{173,77}));
                sf::Sprite backButton(BackButton);
                backButton.setPosition({17.f, 14.f});
                difficulty.draw(backButton);
            }
            difficulty.display();
        }
        else if (mouseHoverHard==true && mouseHoverEasy==false && mouseHoverMedium==false)
        {
            difficulty.clear(sf :: Color :: Black);
            sf :: Texture texture("../../src/Minesweeper_difficulty_select_hard.png", false, sf :: IntRect({0,0},{1920,1080}));
            sf::Sprite sprite(texture);
            difficulty.draw(sprite);
            if (sf::Mouse::getPosition(difficulty).x >=17 && sf::Mouse::getPosition(difficulty).x <=189 && sf::Mouse::getPosition(difficulty).y >=14 && sf::Mouse::getPosition(difficulty).y <=89)
            {
                sf :: Texture HighlightedBackButton("../../src/backButtonHighlighted.png", false, sf :: IntRect({0,0},{173,77}));
                sf::Sprite highlightedBackButton(HighlightedBackButton);
                highlightedBackButton.setPosition({17.f, 14.f});
                difficulty.draw(highlightedBackButton);
            }
            else
            {
                sf :: Texture BackButton("../../src/backButton.png", false, sf :: IntRect({0,0},{173,77}));
                sf::Sprite backButton(BackButton);
                backButton.setPosition({17.f, 14.f});
                difficulty.draw(backButton);
            }
            difficulty.display();
        }
        else if (mouseHoverEasy==false && mouseHoverMedium==false && mouseHoverHard==false)
        {
            difficulty.clear(sf :: Color :: Black);
            sf :: Texture texture("../../src/Minesweeper_difficulty_select.png", false, sf :: IntRect({0,0},{1920,1080}));sf::Sprite sprite(texture);
            difficulty.draw(sprite);
            if (sf::Mouse::getPosition(difficulty).x >=17 && sf::Mouse::getPosition(difficulty).x <=189 && sf::Mouse::getPosition(difficulty).y >=14 && sf::Mouse::getPosition(difficulty).y <=89)
            {
                sf :: Texture HighlightedBackButton("../../src/backButtonHighlighted.png", false, sf :: IntRect({0,0},{173,77}));
                sf::Sprite highlightedBackButton(HighlightedBackButton);
                highlightedBackButton.setPosition({17.f, 14.f});
                difficulty.draw(highlightedBackButton);
            }
            else
            {
                sf :: Texture BackButton("../../src/backButton.png", false, sf :: IntRect({0,0},{173,77}));
                sf::Sprite backButton(BackButton);
                backButton.setPosition({17.f, 14.f});
                difficulty.draw(backButton);
            }
            difficulty.display();
        }
    }
}
#endif //DIFFICULTY_H
