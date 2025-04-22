//
// Created by willw on 04/08/2025.
//
#ifndef MEDIUM_H
#define MEDIUM_H
void difficulty();
inline void Medium()
{
    int countMinesMedium(bool grid[20][20], int rows, int columns);
    int floodMedium(bool grid[20][20], bool selected[20][20], bool scored[20][20], int rows, int columns);
    int rows;
    int columns;
    //grid is used to determine whether a square has a mine or not
    bool grid[20][20]={false};
    //selected is used to determine whether a user has selected a square or not
    bool selected[20][20]={false};
    //scored is used to determine whether a selected square triggered by floodMedium has already been scored or not
    bool scored[20][20]={false};
    //flagged is used to determine whether a user has placed a flag on a square or not
    bool flagged[20][20]={false};
    int gameOver=0;
    int mines=0;
    int score=0;
    std::stringstream scoreStream;
    scoreStream << score;
    //places 60 mines
    while (mines<60)
    {
        //randomly selects a spot on the grid and places a mine if there is not one already
        rows=rand()%20;
        columns=rand()%20;
        if (!grid[rows][columns])
        {
            grid[rows][columns]=true;
            mines++;
        }
    }
    sf :: RenderWindow medium;
    sf::Font font("../../src/CascadiaCode.ttf");
    sf::Text Score(font);
    Score.setCharacterSize(55);
    Score.setPosition({849.f,110.f});
    Score.setFillColor(sf::Color::Black);
    Score.setString(scoreStream.str());
    medium.create(sf :: VideoMode(), "MINESWEEPER", sf :: State :: Fullscreen);
    medium.setFramerateLimit(60);
    while (medium.isOpen())
    {
        while (const std :: optional event = medium.pollEvent())
        {
            //ends program if the user closes the window
            if (event->is<sf :: Event :: Closed>())
                medium.close();
            //closes window if the ESC key is pressed
            else if (const auto* keyPressed = event->getIf<sf :: Event :: KeyPressed>())
            {
                if (keyPressed->scancode == sf :: Keyboard :: Scancode :: Escape)
                    medium.close();
            }
            else if (const auto* mouseButtonReleased = event->getIf<sf::Event::MouseButtonReleased>())
            {
                //checks if the user has right-clicked on the grid
                if (mouseButtonReleased->button == sf::Mouse::Button::Right)
                {
                    for (rows=0; rows<20; rows++)
                    {
                        for (columns=0; columns<20; columns++)
                        {
                            //if square is not currently flagged, place a flag
                            if (gameOver==0 && flagged[rows][columns]==false && sf::Mouse::getPosition(medium).x >=610+(rows*35) && sf::Mouse::getPosition(medium).x <=610+(1+rows)*35 && sf::Mouse::getPosition(medium).y >=190+(columns*35) && sf::Mouse::getPosition(medium).y <=190+(1+columns)*35)
                            {
                                flagged[rows][columns]=true;
                            }
                            //if square is currently flagged, then remove the flag
                            else if (gameOver==0 && flagged[rows][columns]==true && sf::Mouse::getPosition(medium).x >=610+(rows*35) && sf::Mouse::getPosition(medium).x <=610+(1+rows)*35 && sf::Mouse::getPosition(medium).y >=190+(columns*35) && sf::Mouse::getPosition(medium).y <=190+(1+columns)*35)
                            {
                                flagged[rows][columns]=false;
                            }
                        }
                    }
                }
                //checks if the user has left-clicked on the grid or on one of the buttons
                if (mouseButtonReleased->button == sf::Mouse::Button::Left)
                {
                    if (sf::Mouse::getPosition(medium).x >=17 && sf::Mouse::getPosition(medium).x <=189 && sf::Mouse::getPosition(medium).y >=14 && sf::Mouse::getPosition(medium).y <=89)
                    {
                        medium.close();
                        //difficulty window is reopened
                        difficulty();
                    }
                    else if (sf::Mouse::getPosition(medium).x >=1731 && sf::Mouse::getPosition(medium).x <=1901 && sf::Mouse::getPosition(medium).y >=14 && sf::Mouse::getPosition(medium).y <=89)
                    {
                        medium.close();
                        //medium window is reopened
                        Medium();
                    }
                    for (rows=0; rows<20; rows++)
                    {
                        for (columns=0; columns<20; columns++)
                        {
                            if (gameOver==0 && flagged[rows][columns]==false && sf::Mouse::getPosition(medium).x >=610+(rows*35) && sf::Mouse::getPosition(medium).x <=610+(1+rows)*35 && sf::Mouse::getPosition(medium).y >=190+(columns*35) && sf::Mouse::getPosition(medium).y <=190+(1+columns)*35)
                            {
                                //if the square has not already been selected and there is no mine, then add 100 points
                                if (!grid[rows][columns] && !selected[rows][columns])
                                {
                                    score+=100;
                                    scoreStream.str(std::string());
                                    scoreStream << score;
                                    Score.setString(scoreStream.str());
                                }
                                selected[rows][columns]=true;
                            }
                        }
                    }
                }
            }
        }
        medium.clear(sf :: Color :: Black);
        sf :: Texture texture("../../src/Minesweeper_medium.png", false, sf :: IntRect({0,0},{1920,1080}));
        sf::Sprite sprite(texture);
        medium.draw(sprite);
        for (rows=0; rows<20; rows++)
        {
            for (columns=0; columns<20; columns++)
            {
                //if the square is not a mine
                if (grid[rows][columns] == false)
                {
                    int mineCount=countMinesMedium(grid,rows,columns);
                    //switch case for displaying number squares
                    switch (mineCount)
                    {
                        case 1:
                        {
                            sf :: Texture Num1("../../src/minNum1Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num1(Num1);
                            num1.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(num1);
                            break;
                        }
                        case 2:
                        {
                            sf :: Texture Num2("../../src/minNum2Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num2(Num2);
                            num2.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(num2);
                            break;
                        }
                        case 3:
                        {
                            sf :: Texture Num3("../../src/minNum3Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num3(Num3);
                            num3.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(num3);
                            break;
                        }
                        case 4:
                        {
                            sf :: Texture Num4("../../src/minNum4Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num4(Num4);
                            num4.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(num4);
                            break;
                        }
                        case 5:
                        {
                            sf :: Texture Num5("../../src/minNum5Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num5(Num5);
                            num5.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(num5);
                            break;
                        }
                        case 6:
                        {
                            sf :: Texture Num6("../../src/minNum6Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num6(Num6);
                            num6.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(num6);
                            break;
                        }
                        case 7:
                        {
                            sf :: Texture Num7("../../src/minNum7Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num7(Num7);
                            num7.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(num7);
                            break;
                        }
                        case 8:
                        {
                            sf :: Texture Num8("../../src/minNum8Medium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite num8(Num8);
                            num8.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(num8);
                            break;
                        }
                        default:
                        {
                            sf :: Texture Empty("../../src/emptySelectedSquareMedium.png", false, sf :: IntRect({0,0},{35,35}));
                            sf::Sprite empty(Empty);
                            empty.setPosition({610.f+(35*rows),190.f+(35*columns)});
                            medium.draw(empty);
                            //if an empty square is selected, the floodMedium function is called to select other safe squares near it
                            if (selected[rows][columns])
                            {
                                score+=floodMedium(grid, selected, scored, rows, columns);
                                scoreStream.str(std::string());
                                scoreStream << score;
                                Score.setString(scoreStream.str());
                            }
                            break;
                        }
                    }
                }
                //if the square is a mine
                if (grid[rows][columns] == true)
                {
                    sf :: Texture Mine("../../src/mineMedium.png", false, sf :: IntRect({0,0},{35,35}));
                    sf::Sprite mine(Mine);
                    mine.setPosition({610.f+(35*rows),190.f+(35*columns)});
                    medium.draw(mine);
                }
            }
        }
        for (rows=0; rows<20; rows++)
        {
            for (columns=0; columns<20; columns++)
            {
                //if the square is not selected then redraw it over the generated board
                if (selected[rows][columns] == false)
                {
                    sf :: Texture Square("../../src/emptySquareMedium.png", false, sf :: IntRect({0,0},{35,35}));
                    sf::Sprite square(Square);
                    square.setPosition({610.f+(35*rows), 190.f+(35*columns)});
                    medium.draw(square);
                }
            }
        }
        for (rows=0; rows<20; rows++)
        {
            for (columns=0; columns<20; columns++)
            {
                //if the user has right-clicked on an unselected square then draw the flag
                if (flagged[rows][columns] == true && selected[rows][columns] == false)
                {
                    sf :: Texture Flag("../../src/minFlagMedium.png", false, sf :: IntRect({0,0},{35,35}));
                    sf::Sprite flag(Flag);
                    flag.setPosition({610.f+(35*rows), 190.f+(35*columns)});
                    medium.draw(flag);
                }
            }
        }
        for (rows=0; rows<20; rows++)
        {
            for (columns=0; columns<20; columns++)
            {
                //if the user has selected a mine the game ends
                if (selected[rows][columns] == true && grid[rows][columns] == true)
                    gameOver=1;
            }
        }
        if (gameOver != 1)
        {
            for (rows=0; rows<20; rows++)
            {
                for (columns=0; columns<20; columns++)
                {
                    //if all safe squares are selected the game ends
                    if (selected[rows][columns] == true && grid[rows][columns] == false)
                    {
                        gameOver=2;
                    }
                    //if any safe squares have not been selected then the game continues
                    else if (selected[rows][columns] == false && grid[rows][columns] == false)
                    {
                        gameOver=0;
                        break;
                    }
                }
                if (gameOver==0)
                    break;
            }
        }
        //switch case for both game over possibilities
        switch (gameOver)
        {
            //game over for loss
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
                            medium.draw(mine);
                        }
                    }
                }
                break;
            //game over for win
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
                            medium.draw(mineWin);
                        }
                    }
                }
        }
        medium.draw(Score);
        if (sf::Mouse::getPosition(medium).x >=17 && sf::Mouse::getPosition(medium).x <=189 && sf::Mouse::getPosition(medium).y >=14 && sf::Mouse::getPosition(medium).y <=89)
        {
            sf :: Texture HighlightedBackButton("../../src/backButtonHighlighted.png", false, sf :: IntRect({0,0},{173,77}));
            sf::Sprite highlightedBackButton(HighlightedBackButton);
            highlightedBackButton.setPosition({17.f, 14.f});
            medium.draw(highlightedBackButton);
        }
        else
        {
            sf :: Texture BackButton("../../src/backButton.png", false, sf :: IntRect({0,0},{173,77}));
            sf::Sprite backButton(BackButton);
            backButton.setPosition({17.f, 14.f});
            medium.draw(backButton);
        }
        if (sf::Mouse::getPosition(medium).x >=1731 && sf::Mouse::getPosition(medium).x <=1901 && sf::Mouse::getPosition(medium).y >=14 && sf::Mouse::getPosition(medium).y <=89)
        {
            sf :: Texture HighlightedResetButton ("../../src/resetButtonHighlighted.png", false, sf :: IntRect({0,0},{173,77}));
            sf::Sprite highlightedResetButton(HighlightedResetButton);
            highlightedResetButton.setPosition({1730.f, 14.f});
            medium.draw(highlightedResetButton);
        }
        else
        {
            sf :: Texture ResetButton ("../../src/resetButton.png", false, sf :: IntRect({0,0},{173,77}));
            sf::Sprite resetButton(ResetButton);
            resetButton.setPosition({1730.f, 14.f});
            medium.draw(resetButton);
        }
        medium.display();
    }
}
//function for counting the number of mines touching a safe square
int countMinesMedium(bool grid[20][20], int rows, int columns)
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
            //makes sure the array stays in bounds
            if ((checkHorizontal >=0 && checkHorizontal<20) && (checkVertical >=0 && checkVertical<20))
            {
                //increases the count whenever a mine is in one of the adjacent spaces
                if (grid[checkHorizontal][checkVertical])
                    count++;
            }
        }
    }
    return count;
}
//function for flood filling and scoring safe squares
int floodMedium(bool grid[20][20], bool selected[20][20], bool scored[20][20], int rows, int columns)
{
    int score=0;
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
            //makes sure the array stays in bounds
            if ((checkHorizontal >=0 && checkHorizontal<20) && (checkVertical >=0 && checkVertical<20))
            {
                //if the square is not a mine and has not already been scored, then that square is selected and then scored
                if (!grid[checkHorizontal][checkVertical] && !scored[checkHorizontal][checkVertical])
                {
                    selected[checkHorizontal][checkVertical]=true;
                    scored[checkHorizontal][checkVertical]=true;
                    score+=100;
                }
            }
        }
    }
    return score;
}
#endif //MEDIUM_H
