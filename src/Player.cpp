#include "Player.h"
#include "Presenter.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::init(string configFile, int arg_speed)
{
    string tmp, textureImgPath;
    
    fstream stream;
    m_rocket.rect.x = 0;

    //cout << CONFIG_FOLDER + configFile << endl;

    stream.open(CONFIG_FOLDER + configFile);
    stream >> tmp >> textureImgPath;
    stream >> tmp >> m_rocket.rect.x >> m_rocket.rect.y >> m_rocket.rect.w >> m_rocket.rect.h;
    stream.close();

    //cout << textureImgPath << endl;

    m_rocket.texture = loadTexture(GAME_FOLDER + textureImgPath);
    m_health = 10;
    m_fuel = 100;
    m_speed = arg_speed;
    original_speed = arg_speed;
    m_nitro = false;
    //cout << m_rocket.rect.x << endl;

}

void Player::update()
{

}

void Player::draw()
{
    drawObject(m_rocket);
}

void Player::destroy()
{
    SDL_DestroyTexture(m_rocket.texture);
}

void Player::moveRocket()
{
    if (isKeyPressed(SDL_SCANCODE_A) && m_rocket.rect.x >= 0) {
        m_rocket.rect.x -= m_speed;
    }
    else if (isKeyPressed(SDL_SCANCODE_D) && m_rocket.rect.x + m_rocket.rect.w <= 1920) {
        m_rocket.rect.x += m_speed;
    }
}

void Player::statsChange(int arg_type)
{
    switch (arg_type) {
    case 1: // pepper
        m_fuel = 100;
        break;

    case 2: // meteor
        m_health -= 1;
        break;

    case 3: // star
        m_health += 1;
        break;

    default:
        break;
    }
}

void Player::burningFuel()
{
    if (isKeyPressed(SDL_SCANCODE_SPACE)) {
        m_fuel -= 5;
        m_speed = original_speed + 5;
    }
    else {
        m_speed = original_speed;
        m_fuel -= 1;
    }
}

void Player::collisionDetection(SDL_Rect debreeRect, int type)
{
    if (collRectRect(debreeRect, m_rocket.rect)) {
        statsChange(type);
    }
}

int Player::getHealth()
{
    return m_health;
}

int Player::getFuel()
{
    return m_fuel;
}


