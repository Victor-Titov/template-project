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
    m_health = 100;
    m_fuel = 100;
    m_speed = arg_speed;
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
    if (isKeyPressed(SDL_SCANCODE_A)) {
        m_rocket.rect.x -= m_speed;
    }
    else if (isKeyPressed(SDL_SCANCODE_D)) {
        m_rocket.rect.x += m_speed;
    }
}

bool Player::collisionDetection(SDL_Rect debreeRect)
{
    if (((debreeRect.x > m_rocket.rect.x && debreeRect.x < m_rocket.rect.x + m_rocket.rect.w) || (m_rocket.rect.x > debreeRect.x && m_rocket.rect.x < debreeRect.x + debreeRect.w)) && ((debreeRect.y > m_rocket.rect.y && debreeRect.y < m_rocket.rect.y + m_rocket.rect.h) || (m_rocket.rect.y > debreeRect.y && m_rocket.rect.y < debreeRect.y + debreeRect.h))) {
        return true;
    }
    return false;
}

int Player::getHealth()
{
    return m_health;
}

int Player::getFuel()
{
    return m_fuel;
}


