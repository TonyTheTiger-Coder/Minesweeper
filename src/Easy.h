//
// Created by willw on 04/07/2025.
//

#ifndef EASY_H
#define EASY_H
void difficulty();
//floodfill algorithm
inline void Easy()
{
    int countMinesEasy(bool grid[10][10], int rows, int columns);
    int rows;
    int columns;
    bool grid[10][10]={false};
    int mines=0;
    while (mines<10)
    {
        rows=rand()%10;
        columns=rand()%10;
        if (!grid[rows][columns])
        {
            grid[rows][columns]=true;
            mines++;
        }
    }
    sf :: RenderWindow easy;
    easy.create(sf :: VideoMode(), "MINESWEEPER", sf :: State :: Fullscreen);
    easy.setFramerateLimit(60);
    while (easy.isOpen())
    {
        while (const std :: optional event = easy.pollEvent())
        {
            if (event->is<sf :: Event :: Closed>())
                easy.close();
            else if (const auto* keyPressed = event->getIf<sf :: Event :: KeyPressed>())
            {
                if (keyPressed->scancode == sf :: Keyboard :: Scancode :: Escape)
                    easy.close();
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) )
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(easy);
                std::cout << localPosition.x << " " << localPosition.y << std::endl;
                if (sf::Mouse::getPosition(easy).x >=17 && sf::Mouse::getPosition(easy).x <=189 && sf::Mouse::getPosition(easy).y >=14 && sf::Mouse::getPosition(easy).y <=89)
                {
                    easy.close();
                    difficulty();
                }
                else if (sf::Mouse::getPosition(easy).x >=1731 && sf::Mouse::getPosition(easy).x <=1901 && sf::Mouse::getPosition(easy).y >=14 && sf::Mouse::getPosition(easy).y <=89)
                {
                    easy.close();
                    Easy();
                }
            }
        }
        easy.clear(sf :: Color :: Black);
        sf :: Texture texture("../../src/Minesweeper_easy.png", false, sf :: IntRect({0,0},{1920,1080}));
        sf::Sprite sprite(texture);
        easy.draw(sprite);
        for (rows=0; rows<10; rows++)
        {
            for (columns=0; columns<10; columns++)
            {
                if (grid[rows][columns]==false)
                {
                    int mineCount=countMinesEasy(grid,rows,columns);
                    switch (mineCount)
                    {
                        case 1:
                        {
                            sf :: Texture Num1("../../src/minNum1Easy.png", false, sf :: IntRect({0,0},{50,50}));
                            sf::Sprite num1(Num1);
                            num1.setPosition({712.f+(50*rows),289.f+(50*columns)});
                            easy.draw(num1);
                            break;
                        }
                        case 2:
                        {
                            sf :: Texture Num2("../../src/minNum2Easy.png", false, sf :: IntRect({0,0},{50,50}));
                            sf::Sprite num2(Num2);
                            num2.setPosition({712.f+(50*rows),289.f+(50*columns)});
                            easy.draw(num2);
                            break;
                        }
                        case 3:
                        {
                            sf :: Texture Num3("../../src/minNum3Easy.png", false, sf :: IntRect({0,0},{50,50}));
                            sf::Sprite num3(Num3);
                            num3.setPosition({712.f+(50*rows),289.f+(50*columns)});
                            easy.draw(num3);
                            break;
                        }
                        case 4:
                        {
                            sf :: Texture Num4("../../src/minNum4Easy.png", false, sf :: IntRect({0,0},{50,50}));
                            sf::Sprite num4(Num4);
                            num4.setPosition({712.f+(50*rows),289.f+(50*columns)});
                            easy.draw(num4);
                            break;
                        }
                        case 5:
                        {
                            sf :: Texture Num5("../../src/minNum5Easy.png", false, sf :: IntRect({0,0},{50,50}));
                            sf::Sprite num5(Num5);
                            num5.setPosition({712.f+(50*rows),289.f+(50*columns)});
                            easy.draw(num5);
                            break;
                        }
                        case 6:
                        {
                            sf :: Texture Num6("../../src/minNum6Easy.png", false, sf :: IntRect({0,0},{50,50}));
                            sf::Sprite num6(Num6);
                            num6.setPosition({712.f+(50*rows),289.f+(50*columns)});
                            easy.draw(num6);
                            break;
                        }
                        case 7:
                        {
                            sf :: Texture Num7("../../src/minNum7Easy.png", false, sf :: IntRect({0,0},{50,50}));
                            sf::Sprite num7(Num7);
                            num7.setPosition({712.f+(50*rows),289.f+(50*columns)});
                            easy.draw(num7);
                            break;
                        }
                        case 8:
                        {
                            sf :: Texture Num8("../../src/minNum8Easy.png", false, sf :: IntRect({0,0},{50,50}));
                            sf::Sprite num8(Num8);
                            num8.setPosition({712.f+(50*rows),289.f+(50*columns)});
                            easy.draw(num8);
                            break;
                        }
                        default:
                        {
                            sf :: Texture Empty("../../src/emptySelectedSquareEasy.png", false, sf :: IntRect({0,0},{50,50}));
                            sf::Sprite empty(Empty);
                            empty.setPosition({712.f+(50*rows),289.f+(50*columns)});
                            easy.draw(empty);
                            break;
                        }
                    }
                }
                if (grid[rows][columns] == true)
                {
                    sf :: Texture Mine("../../src/mineEasy.png", false, sf :: IntRect({0,0},{50,50}));
                    sf::Sprite mine(Mine);
                    mine.setPosition({712.f+(50*rows),289.f+(50*columns)});
                    easy.draw(mine);
                }
            }
        }
        sf :: Texture Square("../../src/emptySquareEasy.png", false, sf :: IntRect({0,0},{50,50}));
        Square.setRepeated(true);
        sf::Sprite square(Square);
        square.setTextureRect(sf::IntRect({0,0},{500,500}));
        square.setPosition({712.f, 289.f});
        easy.draw(square);
        if (sf::Mouse::getPosition(easy).x >=17 && sf::Mouse::getPosition(easy).x <=189 && sf::Mouse::getPosition(easy).y >=14 && sf::Mouse::getPosition(easy).y <=89)
        {
            sf :: Texture HighlightedBackButton("../../src/backButtonHighlighted.png", false, sf :: IntRect({0,0},{173,77}));
            sf::Sprite highlightedBackButton(HighlightedBackButton);
            highlightedBackButton.setPosition({17.f, 14.f});
            easy.draw(highlightedBackButton);
        }
        else
        {
            sf :: Texture BackButton("../../src/backButton.png", false, sf :: IntRect({0,0},{173,77}));
            sf::Sprite backButton(BackButton);
            backButton.setPosition({17.f, 14.f});
            easy.draw(backButton);
        }
        if (sf::Mouse::getPosition(easy).x >=1731 && sf::Mouse::getPosition(easy).x <=1901 && sf::Mouse::getPosition(easy).y >=14 && sf::Mouse::getPosition(easy).y <=89)
        {
            sf :: Texture HighlightedResetButton ("../../src/resetButtonHighlighted.png", false, sf :: IntRect({0,0},{173,77}));
            sf::Sprite highlightedResetButton(HighlightedResetButton);
            highlightedResetButton.setPosition({1730.f, 14.f});
            easy.draw(highlightedResetButton);
        }
        else
        {
            sf :: Texture ResetButton ("../../src/resetButton.png", false, sf :: IntRect({0,0},{173,77}));
            sf::Sprite resetButton(ResetButton);
            resetButton.setPosition({1730.f, 14.f});
            easy.draw(resetButton);
        }
        easy.display();
    }
}
int countMinesEasy(bool grid[10][10], int rows, int columns)
{
    int checkHorizontal;
    int checkVertical;
    int count=0;
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
                if ((checkHorizontal >=0 && checkHorizontal<10) && (checkVertical >=0 && checkVertical<10))
                    {
                        if (grid[checkHorizontal][checkVertical])
                            count++;
                    }
            }
        }
    return count;
}
#endif //EASY.h
