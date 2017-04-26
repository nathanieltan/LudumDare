#include "thingsWithMass.h"
#include "Collision.h"
#include <iostream>
using namespace std;

/**********----------Class Functions----------**********/

/*** Functions For Class ObjectWithPhysics ***/
void ObjectWithPhysics::set_density(float setDensity)
{
	density = setDensity;
}

void ObjectWithPhysics::set_origin()
{
	objectSprite.setOrigin(objectSprite.getGlobalBounds().width/2.f,objectSprite.getGlobalBounds().width/2.f);
}

float ObjectWithPhysics::get_mass()
{
	return mass;
}

float ObjectWithPhysics::get_volume()
{
	return volume;
}

float ObjectWithPhysics::get_density()
{
	return density;
}
float ObjectWithPhysics::getRadius()
{
	return objectSprite.getGlobalBounds().width/2.f;
}

void ObjectWithPhysics::update(float objectScaler, float dt)
{
	currentScale = objectSprite.getScale();
	this->objectSprite.setScale(currentScale*objectScaler);
	volume = (4.f/3.f) * pi * this->getRadius();
	mass = volume*density;
	//cout<<mass<<endl;
}
void ObjectWithPhysics::applyFriction(float dt)
{
	vel += -1.f*vel*dt;
}


void ObjectWithPhysics::calc_movementAngle()
{
	movementAngle = getAngle(vel);
}
void ObjectWithPhysics::calc_gravityAngle()
{
	gravityAngle = getAngle(gravityForce);
}

/***Functions For Class People ***/
People::People()
{
		health = 1000.f;
}

void People::update(float objectScaler,float dt)
{
	calc_gravityAngle();
	volume = (4.f/3.f) * pi * this->getRadius();
	mass = volume*density;

	accel = gravityForce/mass;
	if(collided){
		accel *= 0.f;
		vel *= -0.3f;
	}
	applyFriction(dt);
	pos += vel*dt + 0.5f * accel*pow(dt,2);

	objectSprite.setPosition(pos.x,pos.y);

	vel += accel*dt;
}

/*** Functions For Class Player ***/
Player::Player()
{
}
void Player::update(float objectScaler, float dt, Planet smallWorld)
{
	distanceToPlanet.x = -1.f*(pos.x - smallWorld.pos.x)*2.0f;
	distanceToPlanet.y = -1.f*(pos.y - smallWorld.pos.y)*2.0f;
  if(pow(getMag(distanceToPlanet),3)>0){
	gravityForce.x = G*smallWorld.mass*mass*distanceToPlanet.x/pow(getMag(distanceToPlanet),3);
	gravityForce.y = G*smallWorld.mass*mass*distanceToPlanet.y/pow(getMag(distanceToPlanet),3);
}
else{
	gravityForce.x = G*smallWorld.mass*mass*distanceToPlanet.x/pow(1,3);
	gravityForce.y = G*smallWorld.mass*mass*distanceToPlanet.y/pow(1,3);
}
	if(Collision::CircleTest(objectSprite,smallWorld.objectSprite))
	{
		collided = true;
	}
	else
	  collided = false;

  for(int x=0;x<firedArrows.size();x++)
	{
		if(Collision::PixelPerfectTest(objectSprite,firedArrows[x].objectSprite)){
			firedArrows.erase(firedArrows.begin()+x);
			health -=3;
		}
	}
  //cout<<health<<endl;

	calc_gravityAngle();
	objectSprite.setRotation((gravityAngle*180/pi)-90);
	volume = (4.f/3.f) * pi * this->getRadius();
	mass = volume*density;

	accel = gravityForce/mass;
	if(collided){
		accel *= 0.f;
		vel *= -0.3f;
	}
	applyFriction(dt);

	vel += keyPressVel;
	pos += vel*dt + 0.5f * accel*pow(dt,2);

	objectSprite.setPosition(pos.x,pos.y);

	vel += accel*dt;
	//cout<<gravityForce.x<<"|"<<gravityForce.y<<endl;
}

void Player::fireArrow()
{
	calc_gravityAngle();
	if(facingRight)
			firedArrows.push_back(Arrow(pos+getRadius()*Vector2f(cos(gravityAngle-(pi/2.f)),sin(gravityAngle-(pi/2.f))), gravityAngle-(pi/2.f)));
	else
	    firedArrows.push_back(Arrow(pos+getRadius()*Vector2f(cos(gravityAngle+(pi/2.f)),sin(gravityAngle+(pi/2.f))), gravityAngle+(pi/2.f)));
}

/*** Functions For Class Arrow ***/
Arrow::Arrow(Vector2f initialPos, float initialAngle):ObjectWithPhysics()
{
	//cout<<"pew"<<endl;
	mass = 650;
	//cout<<initialPos.x<<" | "<<initialPos.y<<endl;
	pos = initialPos;
	objectSprite.setPosition(pos);
	vel.x = 700.f*cos(initialAngle);
	vel.y = 700.f*sin(initialAngle);
}

void Arrow::update(float dt,Planet smallWorld)
{
	/****Physics****/
	distanceToPlanet.x = -1.f*(pos.x - smallWorld.pos.x)*2.0f;
	distanceToPlanet.y = -1.f*(pos.y - smallWorld.pos.y)*2.0f;

	if(pow(getMag(distanceToPlanet),3)>0){
	gravityForce.x = G*smallWorld.mass*mass*distanceToPlanet.x/pow(getMag(distanceToPlanet),3);
	gravityForce.y = G*smallWorld.mass*mass*distanceToPlanet.y/pow(getMag(distanceToPlanet),3);
}
else{
	gravityForce.x = G*smallWorld.mass*mass*distanceToPlanet.x/pow(1,3);
	gravityForce.y = G*smallWorld.mass*mass*distanceToPlanet.y/pow(1,3);
}

	if(Collision::CircleTest(objectSprite,smallWorld.objectSprite))
	{
		collided = true;
	}
	else
		collided = false;
	//cout<<gravityForce.x <<" | "<<gravityForce.y<<endl;
	calc_gravityAngle();
	calc_movementAngle();
	objectSprite.setRotation((movementAngle*180/pi));
	accel = gravityForce/mass;
	if(collided){
		accel *= 0.f;
	  vel *= -0.9f;
	}
	//applyFriction(dt);
	pos += vel*dt + 0.5f * accel*pow(dt,2);

	objectSprite.setPosition(pos.x,pos.y);
  //cout<<vel.x<<" | "<<vel.y<<endl;
	vel += accel*dt;
}

/*** Functions for Class Enemy ***/
Enemy::Enemy()
{
	health = 255;
	vel = Vector2f(0,0);
	accel = Vector2f(0,0);
	playerTrackVel = Vector2f(0,0);
}
void Enemy::update(float dt, Planet smallWorld)
{

	/***Physics**/
	distanceToPlanet.x = -1.f*(pos.x - smallWorld.pos.x)*2.0f;
	distanceToPlanet.y = -1.f*(pos.y - smallWorld.pos.y)*2.0f;
	//cout<<getMag(distanceToPlanet)<<endl;
	if(pow(getMag(distanceToPlanet),3)>0){
	gravityForce.x = G*smallWorld.mass*mass*distanceToPlanet.x/pow(getMag(distanceToPlanet),3);
	gravityForce.y = G*smallWorld.mass*mass*distanceToPlanet.y/pow(getMag(distanceToPlanet),3);
}
else{
	gravityForce.x = G*smallWorld.mass*mass*distanceToPlanet.x/pow(1,3);
	gravityForce.y = G*smallWorld.mass*mass*distanceToPlanet.y/pow(1,3);
}

	calc_gravityAngle();
	objectSprite.setRotation(90+(getAngle(playerTrackVel)*180/pi));
	volume = (4.f/3.f) * pi * this->getRadius();
	mass = volume*density;

	accel = gravityForce/mass;
	if(collided){
		accel *= 0.f;
		vel *= -0.3f;
	}
	//applyFriction(dt);
	accel = gravityForce/mass;
	vel += playerTrackVel;
	pos += vel*dt + 0.5f * accel*pow(dt,2);

	objectSprite.setPosition(pos.x,pos.y);
//cout<<0.5f*pow(dt,2)<<endl;
	vel += accel*dt;
}

void Enemy::trackPlayer(float dt,Player player, Planet smallWorld)
{
	planetPlayerAngle = (player.gravityAngle*180.f/pi - gravityAngle*180.f/pi);
	if(planetPlayerAngle<20.f)  // Go Straight For the Player
	{
		angleToPlayer = getAngle(player.pos - pos);
		playerTrackVel.x = dt*8000.f*cos(angleToPlayer);
		playerTrackVel.y = dt*8000.f*sin(angleToPlayer);
	}
	else
	{
		if(planetPlayerAngle < 0 || planetPlayerAngle>180)
		{
			//cout<<"less than 0"<<endl;
			playerTrackVel.x = dt*8000.f*cos(gravityAngle+(pi/2.f));
			playerTrackVel.y = dt*8000.f*sin(gravityAngle+(pi/2.f));
		}
		else
		{
			//cout<<"more than 0"<<endl;
			playerTrackVel.x = dt*8000.f*cos(gravityAngle-(pi/2.f));
			playerTrackVel.y = dt*8000.f*sin(gravityAngle-(pi/2.f));
		}
	}
}
/**********----------Other Functions----------**********/
float getAngle(Vector2<float> myVec){
	return atan2(myVec.y,myVec.x);
}

float getMag(Vector2<float> myVec){
	return sqrt(pow((double)myVec.x,2)+pow((double)myVec.y,2));
}
