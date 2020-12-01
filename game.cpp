#include <SFML/Graphics.hpp>
#include <string>


int main()
{


    const int windowWidth = 1100, windowHeight = 619;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "trampo");
    window.setFramerateLimit(60);


    sf::Texture bgTexture;
    bgTexture.loadFromFile("imagens/background.jpg");
    bgTexture.setRepeated(true);
    sf::IntRect bgRect(0, 0, windowWidth, windowHeight);
    sf::Sprite bgSprite(bgTexture);

    sf::Texture nvTexture;
    nvTexture.loadFromFile("imagens/n1.png");
    sf::IntRect nvRect(4, 4, 65, 100);
    sf::Sprite nvSprite(nvTexture);



    sf::Texture inv2Texture;
    inv2Texture.loadFromFile("imagens/n2.png");
    sf::IntRect inv2Rect(177, 3, 78, 67);
    sf::Sprite inv2Sprite(inv2Texture);

    sf::Texture inv3Texture;
    inv3Texture.loadFromFile("imagens/n2.png");
    sf::IntRect inv3Rect(177, 3, 78, 67);
    sf::Sprite inv3Sprite(inv3Texture);

    sf::Texture bnvTexture;
    bnvTexture.loadFromFile("imagens/n3.png");
    sf::IntRect bnvRect(194, 0, 77, 99);
    sf::Sprite bnvSprite(bnvTexture);

    sf::Texture bnv1Texture;
    bnv1Texture.loadFromFile("imagens/n3.png");
    sf::IntRect bnv1Rect(194, 0, 77, 99);
    sf::Sprite bnv1Sprite(bnv1Texture);

    sf::Texture anvTexture;
    anvTexture.loadFromFile("imagens/n4.png");
    sf::IntRect anvRect(276, 2, 103, 93);
    sf::Sprite anvSprite(anvTexture);

    sf::Texture shTexture;
    shTexture.loadFromFile("imagens/shots.png");
    sf::Sprite shSprite(shTexture);

    sf::Texture sh1Texture;
    sh1Texture.loadFromFile("imagens/shot.png");
    sf::Sprite sh1Sprite(sh1Texture);

    sf::Texture sh2Texture;
    sh2Texture.loadFromFile("imagens/shot.png");
    sf::Sprite sh2Sprite(sh2Texture);

    sf::Texture sh3Texture;
    sh3Texture.loadFromFile("imagens/shot.png");
    sf::Sprite sh3Sprite(sh3Texture);

    sf::Texture sh4Texture;
    sh4Texture.loadFromFile("imagens/shot.png");
    sf::Sprite sh4Sprite(sh4Texture);



    float invY = windowHeight-350, nvY = windowHeight-350, shX = windowWidth;
    bool gameOver = false;

    // game loop
    while (window.isOpen())
    {
        // Tratamento dos eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
             {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
             }


        }

        // Atualização do estado do jogo
        if(!gameOver)
        {
        bgRect.left++;
        bgSprite.setTextureRect(bgRect);

        nvSprite.setTextureRect(nvRect); // nave do player
        nvSprite.setPosition(25, nvY);



        inv2Sprite.setTextureRect(inv2Rect);
        inv2Sprite.setPosition(950, invY+200);
        inv3Sprite.setTextureRect(inv3Rect);
        inv3Sprite.setPosition(950, invY-200);

        bnvSprite.setTextureRect(bnvRect); // 2 naves no meio
        bnvSprite.setPosition(800, invY+100);
        bnv1Sprite.setTextureRect(bnvRect);
        bnv1Sprite.setPosition(800, invY-100);

        anvSprite.setTextureRect(anvRect); // 1 nave na frente
        anvSprite.setPosition(650, invY);

        shX -= 2;
        if(shX <= 10) shX = windowWidth;
        shSprite.setPosition(shX-530, invY-75);
        sh1Sprite.setPosition(shX-380, invY-172);
        sh2Sprite.setPosition(shX-380, invY+28);
        sh3Sprite.setPosition(shX-230, invY-287);
        sh4Sprite.setPosition(shX-230, invY+113);

        if(nvSprite.getGlobalBounds().intersects(shSprite.getGlobalBounds()))
          {
          gameOver = true;
          }
        }



        // Desenha o frame
        window.clear(sf::Color::White);
        window.draw(bgSprite);

        window.draw(nvSprite);

        window.draw(inv2Sprite);
        window.draw(inv3Sprite);
        window.draw(bnvSprite);
        window.draw(bnv1Sprite);
        window.draw(anvSprite);

        window.draw(shSprite);
        window.draw(sh1Sprite);
        window.draw(sh2Sprite);
        window.draw(sh3Sprite);
        window.draw(sh4Sprite);

        window.display();



    }

    return 0;
}
