//
// Created by willw on 04/08/2025.
//
#ifndef HARD_H
#define HARD_H
void difficulty();
//floodfill algorithm
inline void Hard()
{
    int countMinesHard(bool grid[30][30], int rows, int columns);
    int rows;
    int columns;
    bool grid[30][30]={false};
    int mines=0;
    while (mines<180)
    {
        rows=rand()%30;
        columns=rand()%30;
        if (!grid[rows][columns])
        {
            grid[rows][columns]=true;
            mines++;
        }
    }
    sf :: RenderWindow hard;
    hard.create(sf :: VideoMode(), "MINESWEEPER", sf :: State :: Fullscreen);
    hard.setFramerateLimit(60);
    while (hard.isOpen())
    {
        while (const std :: optional event = hard.pollEvent())
        {
            if (event->is<sf :: Event :: Closed>())
                hard.close();
            else if (const auto* keyPressed = event->getIf<sf :: Event :: KeyPressed>())
            {
                if (keyPressed->scancode == sf :: Keyboard :: Scancode :: Escape)
                    hard.close();
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) )
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(hard);
                std::cout << localPosition.x << " " << localPosition.y << std::endl;
                if (sf::Mouse::getPosition(hard).x >=17 && sf::Mouse::getPosition(hard).x <=189 && sf::Mouse::getPosition(hard).y >=14 && sf::Mouse::getPosition(hard).y <=89)
                {
                    hard.close();
                    difficulty();
                }
                else if (sf::Mouse::getPosition(hard).x >=1731 && sf::Mouse::getPosition(hard).x <=1901 && sf::Mouse::getPosition(hard).y >=14 && sf::Mouse::getPosition(hard).y <=89)
                {
                    hard.close();
                    Hard();
                }
            }
        }
        hard.clear(sf :: Color :: Black);
        sf :: Texture texture("../../src/Minesweeper_hard.png", false, sf :: IntRect({0,0},{1920,1080}));
        sf::Sprite sprite(texture);
        hard.draw(sprite);
        for (rows=0; rows<30; rows++)
        {
            for (columns=0; columns<30; columns++)
            {
                if (grid[rows][columns]==false)
                {
                    int mineCount=countMinesHard(grid,rows,columns);
                    switch (mineCount)
                    {
                        case 1:
                        {
                            sf :: Texture Num1("../../src/minNum1Hard.png", false, sf :: IntRect({0,0},{30,30}));
                            sf::Sprite num1(Num1);
                            num1.setPosition({511.f+(30*rows),93.f+(30*columns)});
                            hard.draw(num1);
                            break;
                        }
                        case 2:
                        {
                            sf :: Texture Num2("../../src/minNum2Hard.png", false, sf :: IntRect({0,0},{30,30}));
                            sf::Sprite num2(Num2);
                            num2.setPosition({511.f+(30*rows),93.f+(30*columns)});
                            hard.draw(num2);
                            break;
                        }
                        case 3:
                        {
                            sf :: Texture Num3("../../src/minNum3Hard.png", false, sf :: IntRect({0,0},{30,30}));
                            sf::Sprite num3(Num3);
                            num3.setPosition({511.f+(30*rows),93.f+(30*columns)});
                            hard.draw(num3);
                            break;
                        }
                        case 4:
                        {
                            sf :: Texture Num4("../../src/minNum4Hard.png", false, sf :: IntRect({0,0},{30,30}));
                            sf::Sprite num4(Num4);
                            num4.setPosition({511.f+(30*rows),93.f+(30*columns)});
                            hard.draw(num4);
                            break;
                        }
                        case 5:
                        {
                            sf :: Texture Num5("../../src/minNum5Hard.png", false, sf :: IntRect({0,0},{30,30}));
                            sf::Sprite num5(Num5);
                            num5.setPosition({511.f+(30*rows),93.f+(30*columns)});
                            hard.draw(num5);
                            break;
                        }
                        case 6:
                        {
                            sf :: Texture Num6("../../src/minNum6Hard.png", false, sf :: IntRect({0,0},{30,30}));
                            sf::Sprite num6(Num6);
                            num6.setPosition({511.f+(30*rows),93.f+(30*columns)});
                            hard.draw(num6);
                            break;
                        }
                        case 7:
                        {
                            sf :: Texture Num7("../../src/minNum7Hard.png", false, sf :: IntRect({0,0},{30,30}));
                            sf::Sprite num7(Num7);
                            num7.setPosition({511.f+(30*rows),93.f+(30*columns)});
                            hard.draw(num7);
                            break;
                        }
                        case 8:
                        {
                            sf :: Texture Num8("../../src/minNum8Hard.png", false, sf :: IntRect({0,0},{30,30}));
                            sf::Sprite num8(Num8);
                            num8.setPosition({511.f+(30*rows),93.f+(30*columns)});
                            hard.draw(num8);
                            break;
                        }
                        default:
                        {
                            sf :: Texture Empty("../../src/emptySelectedSquareHard.png", false, sf :: IntRect({0,0},{30,30}));
                            sf::Sprite empty(Empty);
                            empty.setPosition({511.f+(30*rows),93.f+(30*columns)});
                            hard.draw(empty);
                            break;
                        }
                    }
                }
                if (grid[rows][columns] == true)
                {
                    sf :: Texture Mine("../../src/mineHard.png", false, sf :: IntRect({0,0},{30,30}));
                    sf::Sprite mine(Mine);
                    mine.setPosition({511.f+(30*rows),93.f+(30*columns)});
                    hard.draw(mine);
                }
            }
        }
        sf :: Texture Square("../../src/emptySquareHard.png", false, sf :: IntRect({0,0},{30,30}));
        Square.setRepeated(true);
        sf::Sprite square(Square);
        square.setTextureRect(sf::IntRect({0,0},{900,900}));
        square.setPosition({511.f,93.f});
        hard.draw(square);
        if (sf::Mouse::getPosition(hard).x >=17 && sf::Mouse::getPosition(hard).x <=189 && sf::Mouse::getPosition(hard).y >=14 && sf::Mouse::getPosition(hard).y <=89)
        {
            sf :: Texture HighlightedBackButton("../../src/backButtonHighlighted.png", false, sf :: IntRect({0,0},{173,77}));
            sf::Sprite highlightedBackButton(HighlightedBackButton);
            highlightedBackButton.setPosition({17.f, 14.f});
            hard.draw(highlightedBackButton);
        }
        else
        {
            sf :: Texture BackButton("../../src/backButton.png", false, sf :: IntRect({0,0},{173,77}));
            sf::Sprite backButton(BackButton);
            backButton.setPosition({17.f, 14.f});
            hard.draw(backButton);
        }
        if (sf::Mouse::getPosition(hard).x >=1731 && sf::Mouse::getPosition(hard).x <=1901 && sf::Mouse::getPosition(hard).y >=14 && sf::Mouse::getPosition(hard).y <=89)
        {
            sf :: Texture HighlightedResetButton ("../../src/resetButtonHighlighted.png", false, sf :: IntRect({0,0},{173,77}));
            sf::Sprite highlightedResetButton(HighlightedResetButton);
            highlightedResetButton.setPosition({1730.f, 14.f});
            hard.draw(highlightedResetButton);
        }
        else
        {
            sf :: Texture ResetButton ("../../src/resetButton.png", false, sf :: IntRect({0,0},{173,77}));
            sf::Sprite resetButton(ResetButton);
            resetButton.setPosition({1730.f, 14.f});
            hard.draw(resetButton);
        }
        hard.display();
    }
}
int countMinesHard(bool grid[30][30], int rows, int columns)
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
            if ((checkHorizontal >=0 && checkHorizontal<30) && (checkVertical >=0 && checkVertical<30))
            {
                if (grid[checkHorizontal][checkVertical])
                    count++;
            }
        }
    }
    return count;
}
#endif //HARD_H
