#include <iostream>
#include <SFML/Graphics.hpp>
#include <typeinfo>
#include <cmath>
#include "thingsWithMass.h"
#include "Collision.h"

using namespace std;

//const float pi = 3.14159265358;

const float fps = 60.0f; // 60 fps
const float fpms = fps/1000.f;
const float dt = 1.0f/fps; // desired consistant time between frames
const float smallWorldDensity = 8*pow(10,6); // kg/pixel^3
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main()
{
  /**** Creates Window and Configures it ****/
  RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "A World Getting Smaller");
  View mainView;
  View HUD;

  Vector2u windowScale = window.getSize();

  mainView.reset(FloatRect(0,0,SCREEN_WIDTH*5,SCREEN_HEIGHT*5));
  //HUD.reset(FloatRect(0,SCREEN_HEIGHT-50,SCREEN_WIDTH,50));
  window.setView(mainView);
  window.setFramerateLimit(60); // sets framerate to 60fps

  Clock Clock; // sets up clock

  Texture planetTexture;
  planetTexture.loadFromFile("../src/images/planet.png");

  Texture deathScreenTexture;
  deathScreenTexture.loadFromFile("../src/images/deathScreen.png");

  Texture winScreenTexture;
  winScreenTexture.loadFromFile("../src/images/winScreen.png");

  Texture enemyTexture;
  enemyTexture.loadFromFile("../src/images/enemy.png");

  Sprite deathScreen;
  deathScreen.setTexture(deathScreenTexture);
  deathScreen.setPosition(0,0);

  Sprite winScreen;
  winScreen.setTexture(winScreenTexture);
  winScreen.setPosition(0,0);

  Texture playerTexture;
  playerTexture.loadFromFile("../src/images/player.png");

  Texture arrowTexture;
  arrowTexture.loadFromFile("../src/images/arrow.png");

  RectangleShape rectangle(Vector2f(windowScale.x,windowScale.y/6.f));

  rectangle.setPosition(0,windowScale.y*5/6);
  rectangle.setFillColor(Color::Green);

  bool restartGame = false;
  /*** Declares and Initializes the Planet ***/
  float initialWorldRadius = 500.0f;
  Planet smallWorld;
  smallWorld.objectSprite.setTexture(planetTexture);
  smallWorld.set_origin();
  smallWorld.pos.x = 0;
  smallWorld.pos.y = 0;
  smallWorld.objectSprite.setScale(smallWorld.objectSprite.getScale()*4.f);
  smallWorld.objectSprite.setPosition(smallWorld.pos.x,smallWorld.pos.y);
  smallWorld.set_density(smallWorldDensity);

  /*** Declares and Initializes the Player ***/
  Player player;
  player.objectSprite.setTexture(playerTexture);
  player.set_origin();
  player.set_density(500.0);
  player.pos.x = 1500;
  player.pos.y = 1500;
  player.objectSprite.setPosition(player.pos.x,player.pos.y);
  //player.update(0.25f,dt);

  /***Declares and Initializes Enemies***/
  vector<Enemy> enemies;

  for(int x=0;x<5;x++){
    Enemy enemy;
    enemy.objectSprite.setTexture(enemyTexture);
    enemy.set_origin();
    enemy.set_density(100);
    enemy.pos.x = 1.2f*smallWorld.getRadius()*cos(x);
    enemy.pos.y = 1.2f*smallWorld.getRadius()*sin(x);
    enemy.objectSprite.setPosition(enemy.pos.x,enemy.pos.y);

    enemies.push_back(enemy);
  }



  float smallWorldScaler =  dt * 59.99f;
  float timeAccumulator = 0.0; // the accumulation of time

  Vector2<float> distance;
  float distanceMag;

  RectangleShape gravityDirection(Vector2f(150,5));
  gravityDirection.setPosition(900,900);

  mainView.setSize(windowScale.x*3,windowScale.y*3);
  HUD.setSize(windowScale.x,windowScale.y);
  /**************----------Main Game Loop----------**************/
  while (window.isOpen())
  {
    cout<<getMag(smallWorld.vel)<<endl;
    //cout<<smallWorld.mass<<endl;
    if(restartGame)
    {
       player = Player();
       player.objectSprite.setTexture(playerTexture);
       player.set_origin();
       player.set_density(500.0);
       player.pos.x = 1500;
       player.pos.y = 1500;
       player.objectSprite.setPosition(player.pos.x,player.pos.y);

       smallWorld = Planet();
       smallWorld.objectSprite.setTexture(planetTexture);
       smallWorld.set_origin();
       smallWorld.pos.x = 0;
       smallWorld.pos.y = 0;
       smallWorld.objectSprite.setScale(smallWorld.objectSprite.getScale()*4.f);
       smallWorld.objectSprite.setPosition(smallWorld.pos.x,smallWorld.pos.y);
       smallWorld.set_density(smallWorldDensity);

       enemies.resize(5);
       for(int x=0;x<5;x++){
         Enemy enemy = Enemy();
         enemy.objectSprite.setTexture(enemyTexture);
         enemy.set_origin();
         enemy.set_density(100);
         enemy.pos.x = 1.2f*smallWorld.getRadius()*cos(x);
         enemy.pos.y = 1.2f*smallWorld.getRadius()*sin(x);
         enemy.objectSprite.setPosition(enemy.pos.x,enemy.pos.y);
         enemies[x]=enemy;
       }

       Clock.restart();
       timeAccumulator = 0.f;
       rectangle.setFillColor(Color::Green);
       restartGame = false;
    }

    float frameTime = (float)Clock.restart().asSeconds(); // frameTime is the time since the last frame in ms
    timeAccumulator += frameTime;
    //cout<<"FPS: " << 1.f/frameTime<<endl;
    //cout<<timeAccumulator<<endl;

    while(timeAccumulator >= dt)
    {
      /***HUD Stuff***/
      rectangle.setSize(Vector2f((player.health/1000.f)*windowScale.x,windowScale.y/6.f));
      rectangle.setPosition(0,windowScale.y*5.f/6.f);

      if(player.health<700)rectangle.setFillColor(Color(255,140,0));
      if(player.health<300)rectangle.setFillColor(Color::Red);

      if(Keyboard::isKeyPressed(Keyboard::Up))
      {
        player.keyPressVel.x = -1000.f*dt*cos(player.gravityAngle);
        player.keyPressVel.y = -1000.f*dt*sin(player.gravityAngle);
      }
      else if(Keyboard::isKeyPressed(Keyboard::Down))
      {
        player.keyPressVel.x = 500*dt*cos(player.gravityAngle);
        player.keyPressVel.y = 500*dt*sin(player.gravityAngle);
      }
      else if(Keyboard::isKeyPressed(Keyboard::Right))
      {
        player.keyPressVel.x = dt*1000.f*cos(player.gravityAngle-(pi/2.f));
        player.keyPressVel.y = dt*1000.f*sin(player.gravityAngle-(pi/2.f));
        player.facingRight = true;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Left))
      {
        player.keyPressVel.x = dt*1000.f*cos(player.gravityAngle+(pi/2.f));
        player.keyPressVel.y = dt*1000.f*sin(player.gravityAngle+(pi/2.f));
        player.facingRight = false;
      }
      else
      {
        player.keyPressVel.x = 0;
        player.keyPressVel.y = 0;
      }

      if(Keyboard::isKeyPressed(Keyboard::Space))
      {
        player.fireArrow();
      }

      if((Keyboard::isKeyPressed(Keyboard::Return) && player.health<0) || (Keyboard::isKeyPressed(Keyboard::Return) && enemies.size()==0))
      {
        restartGame = true;
      }

      Event event;

      while (window.pollEvent(event))
      {
        switch(event.type)
        {
          case Event::Closed: // close window
          window.close();
          break;

          case Event::Resized:
            windowScale = window.getSize();
            mainView.setSize(windowScale.x*5,windowScale.y*5);
            HUD.setSize(windowScale.x,windowScale.y);
          		break;
        }
      }
      /***Updates All Arrows***/
      for(int x=0;x<player.firedArrows.size();x++){
        player.firedArrows[x].update(dt,smallWorld);
      }
      /***Collision Detection With Enemies***/

      for(int x=0;x<enemies.size();x++){
        for(int y=0;y<player.firedArrows.size();y++){
          if(Collision::PixelPerfectTest(player.firedArrows[y].objectSprite,enemies[x].objectSprite)){
            player.firedArrows.erase(player.firedArrows.begin()+y);
            enemies[x].health -=2;
          }
        }

        if(Collision::PixelPerfectTest(player.objectSprite,enemies[x].objectSprite)){
          player.vel = 3.f*enemies[x].vel;
          enemies[x].vel *= -1.f;
          enemies[x].health -= 300.f*dt;
          player.health -= 2000.f*dt;
        }

        for(int z=x+1;z<enemies.size();z++){
          if(Collision::PixelPerfectTest(enemies[z].objectSprite,enemies[x].objectSprite)){
            Vector2f zVel = enemies[z].vel;
            enemies[z].vel = 2.f*enemies[x].vel;
            enemies[x].vel = 2.f*zVel;
          }
        }

        enemies[x].objectSprite.setColor(Color((int)(255-enemies[x].health),(int)enemies[x].health,20));
        if(enemies[x].health<0){
          enemies.erase(enemies.begin()+x);
        }
      }


      /****Updates Player and World****/
      player.update(1.0f,dt,smallWorld);
      smallWorld.update(smallWorldScaler,dt);

      for(int x=0;x<enemies.size();x++){
        enemies[x].trackPlayer(dt,player,smallWorld);
        enemies[x].update(dt,smallWorld);
      }

      gravityDirection.setPosition(player.objectSprite.getPosition());
      gravityDirection.setRotation(player.gravityAngle*180.f/pi);


      timeAccumulator -= dt;
    }

    if(player.health>0 && player.health <= 1000 && enemies.size()>0){
    mainView.setCenter(player.pos);
    HUD.setCenter(windowScale.x/2,windowScale.y/2);
    window.setView(mainView);

    window.clear(Color::Blue);
    window.draw(smallWorld.objectSprite);
    window.draw(player.objectSprite);
    window.draw(gravityDirection);

    for(int x=0;x<player.firedArrows.size();x++)
    {
      player.firedArrows[x].objectSprite.setTexture(arrowTexture);
      window.draw(player.firedArrows[x].objectSprite);
    }

    for(int x=0;x<enemies.size();x++){
          //cout<<"test"<<endl;
          window.draw(enemies[x].objectSprite);
    }


    window.setView(HUD);
    window.draw(rectangle);
    }
     else if(player.health<0){
       window.clear(Color::Black);
       HUD.setCenter(windowScale.x/2,windowScale.y/2);
       window.setView(HUD);
       //SSdeathScreen.scale(windowScale.x,windowScale.y);
       //deathScreen.setOrigin(windowScale.x/2,windowScale.y/2); +-
       window.draw(deathScreen);
     }

     else if(enemies.size()<=0){
       window.clear();
       HUD.setCenter(windowScale.x/2,windowScale.y/2);
       window.setView(HUD);
       window.draw(winScreen);
     }
    window.display();
  }

  return 0;
}
