#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

using namespace sf;

const float pi = 3.14159265358f;
const double G = 6.674f * pow(10,-2);

/**********----------Class For Objects That Physics Apply To----------**********/
class ObjectWithPhysics
{
	public:
		Sprite objectSprite;
		float mass,volume,density;
		float gravityAngle,movementAngle;
		Vector2<float> pos,vel,accel;
		Vector2<float> gravityForce, friction;
		Vector2<float> currentScale;

		void applyFriction(float);
		void set_origin();
		void set_density(float);
		float get_mass();
		float get_volume();
		float get_density();
		void calc_gravityAngle();
		void calc_movementAngle();
		float getRadius();
		void update(float,float);

};

class Planet:public ObjectWithPhysics
{
};

class People:public ObjectWithPhysics
{
		public:
			  float health;
			  Vector2<float> distanceToPlanet;
				bool collided;
        bool facingRight = false;
				People();
				void update(float,float);
};
class Arrow:public ObjectWithPhysics
{
public:
	bool collided;
	Vector2<float> distanceToPlanet;
	Arrow(Vector2<float>,float);
	void update(float,Planet);
};
class Player:public People
{
		public:
			  std::vector<Arrow> firedArrows;
				std::vector<Arrow> stuckArrows;
				Vector2<float> keyPressVel;//vel added because of key press
				void update(float,float,Planet);
				Player();
				void fireArrow();
};
class Enemy:public People
{
	public:
		  float planetPlayerAngle;//angle between self-planet-player IN DEGREES
			float angleToPlayer; //angle pointing towards player
      Vector2<float> playerTrackVel;//vel added to get player
			Enemy();
			void update(float,Planet);
			void trackPlayer(float dt,Player,Planet);
};

/**********----------Other Functions---------**********/
float getAngle(Vector2<float>);
float getMag(Vector2<float>);
