#pragma once
/* ���� ����� ��� ������ ���� ���� ����� 
1) ������� ������ ������ button
2) ������ button.newButton � button.setLabel
3) � ����� ������������� ������� ������� ������� 
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    sf::Vector2f pos = window.mapPixelToCoords(pixelPos);
4) � ����� ������� ���������� ������ � ������� (window.draw(button.button) � window.draw(button.text)
5) ������� ������� if ((testButton.isCursor(pos.x, pos.y)) && (event.type == sf::Event::MouseButtonReleased))
6) ???
7) Profit*/


class Button {
private:
    int weight; // ������
    int height; // ������
    int posx;   // ������� x
    int posy;   // ������� y
    std::string label;
    sf::Font font;

public:
    sf::RectangleShape button;
    sf::Text text;
    sf::Text shadow;
    // ������, ������, ������� �, ������� y
    void newButton(int wh, int hh, int px, int py)
    {

        weight = wh; height = hh; posx = px; posy = py;
        button.setSize(sf::Vector2f(weight, height));
        button.setPosition(posx, posy);
    };

    bool isCursor(double corx, double cory)
    {
        if ((corx > posx) && (corx < weight + posx) && (cory > posy) && (cory < height + posy)) {
            button.setFillColor(sf::Color(100, 100, 100));
            return true;
        }
        else {
            button.setFillColor(sf::Color(250, 250, 250));
            return false;
        }
    }
    // x, y, ���� RGB
    bool isCursor(double corx, double cory, int R , int G, int B)
    {
        if ((corx > posx) && (corx < weight + posx) && (cory > posy) && (cory < height + posy)) {
            button.setFillColor(sf::Color(R, G, B));
            return true;
        }
        else {
            button.setFillColor(sf::Color(R + 200, G + 200, B + 200));
            return false;
        }
    }
    // ������, �����, ����, ������ ������
    void setLabel(std::string lb, std::string fnt, sf::Color color, int size)
    {
        label = lb;
        font.loadFromFile(fnt);
        text.setString(label);
        shadow.setString(label);
        text.setFont(font);
        shadow.setFont(font);
        text.setCharacterSize(size);
        shadow.setCharacterSize(size);
        text.setFillColor(color);
        shadow.setFillColor(sf::Color(0,0,0));
        text.setPosition(posx + weight / 10, posy + height / 8);
        shadow.setPosition((posx + weight / 10)+2, (posy + height / 8)+1);

    }
    // ������, �����, ����, ������ ������
    void setLabel(std::string lb, std::string fnt)
    {
        label = lb;

        font.loadFromFile(fnt);
        text.setString(label);
        text.setFont(font);

        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        text.setPosition(posx + weight / 10, posy + height / 8);

    }
};