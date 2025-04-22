//
// Created by willw on 04/08/2025.
//
#ifndef DEMOLITION_H
#define DEMOLITION_H
void title();
//floodfill algorithm
inline void Demolition()
{
    int countMinesDemolition(bool grid[20][20], int rows, int columns);
    void floodDemolition(bool grid[20][20], bool selected[20][20], int rows, int columns);
    int rows;
    int columns;
    bool grid[20][20]={false};
    bool selected[20][20]={false};
    bool scored[20][20]={false};
    int gameOver=0;
    int mines=0;
    int score=0;
    int lives=5;
    int clicks=0;
    std::stringstream ss;
    ss << score;
    std::stringstream ll;
    ll << lives;
    while (mines<60)
    {
        rows=rand()%20;
        columns=rand()%20;
        if (!grid[rows][columns])
        {
            grid[rows][columns]=true;
            mines++;
        }
    }
    sf :: RenderWindow demolition;
    sf::Font font("../../src/CascadiaCode.ttf");
    sf::Text Score(font);
    Score.setCharacterSize(55);
    Score.setPosition({849.f,110.f});
    Score.setFillColor(sf::Color::Black);
    Score.setString(ss.str());
    sf::Text LivesLeft(font);
    LivesLeft.setCharacterSize(55);
    LivesLeft.setPosition({1040.f,110.f});
    LivesLeft.setFillColor(sf::Color::Black);
    LivesLeft.setString("Lives:");
    sf::Text Lives(font);
    Lives.setCharacterSize(50);
    Lives.setPosition({1250.f,115.f});
    Lives.setFillColor(sf::Color::Black);
    Lives.setString(ll.str());
    demolition.create(sf :: VideoMode(), "MINESWEEPER", sf :: State :: Fullscreen);
    demolition.setFramerateLimit(60);
    while (demolition.isOpen())
    {
        while (const std :: optional event = demolition.pollEvent())
        {

            if (event->is<sf :: Event :: Closed>())
                demolition.close();
            else if (const auto* keyPressed = event->getIf<sf :: Event :: KeyPressed>())
            {
                if (keyPressed->scancode == sf :: Keyboard :: Scancode :: Escape)
                    demolition.close();
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) )
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(demolition);
                std::cout << localPosition.x << " " << localPosition.y << std::endl;
                if (sf::Mouse::getPosition(demolition).x >=17 && sf::Mouse::getPosition(demolition).x <=189 && sf::Mouse::getPosition(demolition).y >=14 && sf::Mouse::getPosition(demolition).y <=89)
                {
                    demolition.close();
                    title();
                }
                else if (sf::Mouse::getPosition(demolition).x >=1731 && sf::Mouse::getPosition(demolition).x <=1901 && sf::Mouse::getPosition(demolition).y >=14 && sf::Mouse::getPosition(demolition).y <=89)
                {
                    demolition.close();
                    Demolition();
                }
            }
            else if (const auto* mouseButtonReleased = event->getIf<sf::Event::MouseButtonReleased>())
            {
                if (mouseButtonReleased->button == sf::Mouse::Button::Left)
                {
                    for (rows=0; rows<20; rows++)
                    {
                        for (columns=0; columns<20; columns++)
                        {
                            if (gameOver==0 && clicks!=0 && sf::Mouse::getPosition(demolition).x >=610+(rows*35) && sf::Mouse::getPosition(demolition).x <=610+(1+rows)*35 && sf::Mouse::getPosition(demolition).y >=190+(columns*35) && sf::Mouse::getPosition(demolition).y <=190+(1+columns)*35)
                            {
                                if (!grid[rows][columns] && !selected[rows][columns])
                                {
                                    lives-=1;
                                    ll.str(std::string());
                                    ll << lives;
                                    Lives.setString(ll.str());
                                }
                                selected[rows][columns]=true;
                            }
                            else if (gameOver==0 && clicks==0 && sf::Mouse::getPosition(demolition).x >=610+(rows*35) && sf::Mouse::getPosition(demolition).x <=610+(1+rows)*35 && sf::Mouse::getPosition(demolition).y >=190+(columns*35) && sf::Mouse::getPosition(demolition).y <=190+(1+columns)*35)
                            {
                                selected[rows][columns]=true;
                                clicks++;
                            }
                        }
                    }
                }
            }
        }
        demolition.clear(sf :: Color :: Black);
        sf :: Texture texture("../../src/Minesweeper_demolition.png", false, sf :: IntRect({0,0},{1920,1080}));
        sf::Sprite sprite(texture);
        demolition.draw(sprite);
        for (rows=0; rows<20; rows++)
        {
            for (columns=0; columns<20; columns++)
            {
                if (grid[rows][columns] == false)
                {
                    int mineCount=countMinesMedium(grid,rows,columns);
                    switch (mineCount)
                    {
                        case 1:
                        {
                            sf :: Texture Num1("../../src/minNum1Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num1(Num1);
                            num1.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            demolition.draw(num1);
                            break;
                        }
                        case 2:
                        {
                            sf :: Texture Num2("../../src/minNum2Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num2(Num2);
                            num2.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            demolition.draw(num2);
                            break;
                        }
                        case 3:
                        {
                            sf :: Texture Num3("../../src/minNum3Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num3(Num3);
                            num3.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            demolition.draw(num3);
                            break;
                        }
                        case 4:
                        {
                            sf :: Texture Num4("../../src/minNum4Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num4(Num4);
                            num4.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            demolition.draw(num4);
                            break;
                        }
                        case 5:
                        {
                            sf :: Texture Num5("../../src/minNum5Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num5(Num5);
                            num5.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            demolition.draw(num5);
                            break;
                        }
                        case 6:
                        {
                            sf :: Texture Num6("../../src/minNum6Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num6(Num6);
                            num6.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            demolition.draw(num6);
                            break;
                        }
                        case 7:
                        {
                            sf :: Texture Num7("../../src/minNum7Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num7(Num7);
                            num7.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            demolition.draw(num7);
                            break;
                        }
                        case 8:
                        {
                            sf :: Texture Num8("../../src/minNum8Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num8(Num8);
                            num8.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            demolition.draw(num8);
                            break;
                        }
                        default:
                        {
                            sf :: Texture Empty("../../src/emptySelectedSquareMedium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite empty(Empty);
                            empty.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            demolition.draw(empty);
                            if (selected[rows][columns])
                            {
                                floodDemolition(grid, selected, rows, columns);
                            }
                            break;
                        }
                    }
                }
                if (grid[rows][columns] == true)
                {
                    sf :: Texture Mine("../../src/mineMedium.png", false, sf :: IntRect({0,0},{35,35}));
                    sf::Sprite mine(Mine);
                    mine.setPosition({610.f+(35*rows),190.f+(35*columns)});
                    demolition.draw(mine);
                    if (selected[rows][columns] && !scored[rows][columns])
                    {
                        scored[rows][columns] = true;
                        score+=500;
                        ss.str(std::string());
                        ss << score;
                        Score.setString(ss.str());
                        floodDemolition(grid, selected, rows, columns);
                    }
                }
            }
        }

        for (rows=0; rows<20; rows++)
        {
            for (columns=0; columns<20; columns++)
            {
                if (selected[rows][columns] == false)
                {
                    sf :: Texture Square("../../src/emptySquareMedium.png", false, sf :: IntRect({0,0},{35,35}));
                    sf::Sprite square(Square);
                    square.setPosition({610.f+(35*rows), 190.f+(35*columns)});
                    demolition.draw(square);
                }
            }
        }
        for (rows=0; rows<20; rows++)
        {
            for (columns=0; columns<20; columns++)
            {
                if (selected[rows][columns] == true && grid[rows][columns] == false && lives<=0)
                    gameOver=1;
            }
        }
        if (gameOver != 1)
        {
            for (rows=0; rows<20; rows++)
            {
                for (columns=0; columns<20; columns++)
                {
                    if (selected[rows][columns] == true && grid[rows][columns] == true)
                    {
                        gameOver=2;
                    }
                    else if (selected[rows][columns] == false && grid[rows][columns] == true)
                    {
                        gameOver=0;
                        break;
                    }
                }
                if (gameOver==0)
                    break;
            }
        }
        switch (gameOver)
        {
            case 1:
                for (rows=0; rows<20; rows++)
                {
                    for (columns=0; columns<20; columns++)
                    {
                        if (grid[rows][columns] == true)
                        {
                            sf :: Texture Mine("../../src/mineMedium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite mine(Mine);
                            mine.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            demolition.draw(mine);
                        }
                    }
                }
            break;
            case 2:
                for (rows=0; rows<20; rows++)
                {
                    for (columns=0; columns<20; columns++)
                    {
                        if (grid[rows][columns] == true)
                        {
                            sf :: Texture MineWin("../../src/mineWinMedium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite mineWin(MineWin);
                            mineWin.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            demolition.draw(mineWin);
                        }
                    }
                }
        }
        demolition.draw(Score);
        demolition.draw(LivesLeft);
        demolition.draw(Lives);
        if (sf::Mouse::getPosition(demolition).x >=17 && sf::Mouse::getPosition(demolition).x <=189 && sf::Mouse::getPosition(demolition).y >=14 && sf::Mouse::getPosition(demolition).y <=89)
        {
            sf :: Texture HighlightedBackButton("../../src/backButtonHighlighted.png", false, sf :: IntRect({0,0},{173,77}));
            sf::Sprite highlightedBackButton(HighlightedBackButton);
            highlightedBackButton.setPosition({17.f, 14.f});
            demolition.draw(highlightedBackButton);
        }
        else
        {
            sf :: Texture BackButton("../../src/backButton.png", false, sf :: IntRect({0,0},{173,77}));
            sf::Sprite backButton(BackButton);
            backButton.setPosition({17.f, 14.f});
            demolition.draw(backButton);
        }
        if (sf::Mouse::getPosition(demolition).x >=1731 && sf::Mouse::getPosition(demolition).x <=1901 && sf::Mouse::getPosition(demolition).y >=14 && sf::Mouse::getPosition(demolition).y <=89)
        {
            sf :: Texture HighlightedResetButton ("../../src/resetButtonHighlighted.png", false, sf :: IntRect({0,0},{173,77}));
            sf::Sprite highlightedResetButton(HighlightedResetButton);
            highlightedResetButton.setPosition({1730.f, 14.f});
            demolition.draw(highlightedResetButton);
        }
        else
        {
            sf :: Texture ResetButton ("../../src/resetButton.png", false, sf :: IntRect({0,0},{173,77}));
            sf::Sprite resetButton(ResetButton);
            resetButton.setPosition({1730.f, 14.f});
            demolition.draw(resetButton);
        }
        demolition.display();
    }
}
int countMinesDemolition(bool grid[20][20], int rows, int columns)
{
    int checkHorizontal;
    int checkVertical;
    int count=0;
    for (int horizontal=-1;horizontal<=1;horizontal++)
    {
        for (int vertical=-1;vertical<=1;vertical++)
        {
            if (horizontal==0 && vertical==0)
                continue;
            else
            {
                checkHorizontal=rows+horizontal;
                checkVertical=columns+vertical;
            }
            if ((checkHorizontal >=0 && checkHorizontal<20) && (checkVertical >=0 && checkVertical<20))
            {
                if (grid[checkHorizontal][checkVertical])
                    count++;
            }
        }
    }
    return count;
}
void floodDemolition(bool grid[20][20], bool selected[20][20], int rows, int columns)
{
    int checkHorizontal;
    int checkVertical;
    for (int horizontal=-1;horizontal<=1;horizontal++)
    {
        for (int vertical=-1;vertical<=1;vertical++)
        {
            if (horizontal==0 && vertical==0)
            {
                continue;
            }
            else
            {
                checkHorizontal=rows+horizontal;
                checkVertical=columns+vertical;
            }
            if ((checkHorizontal >=0 && checkHorizontal<20) && (checkVertical >=0 && checkVertical<20))
            {
                if (!grid[checkHorizontal][checkVertical])
                {
                    selected[checkHorizontal][checkVertical]=true;
                }
            }
        }
    }
}
#endif //DEMOLITION_H
