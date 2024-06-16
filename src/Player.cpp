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
    m_fuel = 1000;
    m_maxHealth = 10;
    m_maxFuel = 1000;
    m_speed = arg_speed;
    original_speed = arg_speed;
    m_nitro = false;
    //cout << m_rocket.rect.x << endl;

    m_healthBar.init("health_bar.txt");
    m_fuelBar.init("fuel_bar.txt");
    m_score_field.init("score.txt");
    
}

void Player::update()
{
    m_fuelBar.setBar(m_fuel, m_maxFuel);
    m_healthBar.setBar(m_health, m_maxHealth);
    m_score_field.setText("Score: " + to_string(m_score));
   
}

void Player::draw()
{
    drawObject(m_rocket);
    m_healthBar.draw();
    m_fuelBar.draw();
    m_score_field.draw();
}

void Player::destroy()
{
    SDL_DestroyTexture(m_rocket.texture);
    m_score_field.destroy();
}

void Player::moveRocket()
{
    if (isKeyPressed(SDL_SCANCODE_A) && m_rocket.rect.x >= 0) {
        m_rocket.rect.x -= m_speed;
        burningFuel();
    }
    else if (isKeyPressed(SDL_SCANCODE_D) && m_rocket.rect.x + m_rocket.rect.w <= 1920) {
        m_rocket.rect.x += m_speed;
        burningFuel();
    }
}

void Player::statsChange(int arg_type)
{
    switch (arg_type) {
    case 1: // pepper
        m_fuel = m_maxFuel;
        break;

    case 2: // meteor
        m_health -= 1;
        break;

    case 3: // star
        m_health += 1;
        if (m_health > m_maxHealth) {
            m_health = m_maxHealth;
        }
        break;
    case 4:
        m_score++;

    default:
        break;
    }
}

void Player::burningFuel()
{
    if (m_fuel > 0) {
        if (isKeyPressed(SDL_SCANCODE_SPACE)) {
            m_fuel -= 5;
           
            m_speed = original_speed + 5;
        }
        else {
            m_speed = original_speed;
            m_fuel -= 1;
            
        }
        //cout << m_fuel << endl;
    }
    else {
        if (isKeyPressed(SDL_SCANCODE_SPACE)) {
            m_health -= 5;
            
            m_speed = original_speed + 5;
        }
        else {
            m_speed = original_speed;
            m_health -= 1;
            
        }
        //cout << m_health << endl;
        m_fuel = 0;
    }
}

bool Player::collisionDetection(SDL_Rect debreeRect, int type)
{
    if (collRectRect(debreeRect, m_rocket.rect)) {
        statsChange(type);
        cout << type << "\n";
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


