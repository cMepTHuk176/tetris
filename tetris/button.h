#pragma once
/* енто кароч шоб кнопка была знач нужна 
1) создать объект класса button
2) задать button.newButton и button.setLabel
3) в цикле рендеразадать вектора позиции курсора 
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    sf::Vector2f pos = window.mapPixelToCoords(pixelPos);
4) в цикле рендера отобразить кнопку с текстом (window.draw(button.button) и window.draw(button.text)
5) условие нажатия if ((testButton.isCursor(pos.x, pos.y)) && (event.type == sf::Event::MouseButtonReleased))
6) ???
7) Profit*/


class Button {
private:
    int weight; // высота
    int height; // ширина
    int posx;   // позиция x
    int posy;   // позиция y
    std::string label;
    sf::Font font;

public:
    sf::RectangleShape button;
    sf::Text text;
    sf::Text shadow;
    // ширина, высота, позиция х, позиция y
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
    // x, y, цвет RGB
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
    // строка, шрифт, цвет, размер шрифта
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
    // строка, шрифт, цвет, размер шрифта
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