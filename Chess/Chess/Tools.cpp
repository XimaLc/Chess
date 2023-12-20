#include "Tools.h"

sf::Clock clocks;
sf::Time times;


void initTools()
{
	times = clocks.getElapsedTime();
	srand((unsigned)time(NULL));
}

float GetDeltaTime()
{
	return times.asSeconds();
}

void restartClock()
{
	times = clocks.restart();
}

int rand_int(int _min, int _max)
{
	return rand() % (_max - _min) + _min;
}

double rand_float(float _min, float _max)
{
	return ((rand() / (double)RAND_MAX) * ((double)_max - (double)_min) + (double)_min);
}

sf::CircleShape CreateCircle(sf::Texture& _texture, sf::Vector2f _pos, float _radius, sf::Vector2f _origin, float _rotation, sf::Color _color)
{
	sf::CircleShape circle;
	circle.setOrigin(_origin);
	circle.setPosition(_pos);
	circle.setRadius(_radius);
	circle.setRotation(_rotation);
	circle.setTexture(&_texture);
	circle.setFillColor(_color);
	return circle;
}

sf::CircleShape CreateCircle(sf::Vector2f _pos, float _radius, sf::Vector2f _origin, float _rotation, sf::Color _color)
{
	sf::CircleShape circle;
	circle.setOrigin(_origin);
	circle.setPosition(_pos);
	circle.setRadius(_radius);
	circle.setRotation(_rotation);
	circle.setFillColor(_color);
	return circle;
}

sf::RectangleShape CreateRectangle(sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size, sf::Vector2f _origin, float _rotation, sf::Color _color)
{
	sf::RectangleShape rectangle;
	rectangle.setOrigin(_origin);
	rectangle.setPosition(_pos);
	rectangle.setRotation(_rotation);
	rectangle.setSize(_size);
	rectangle.setTexture(&_texture);
	rectangle.setFillColor(_color);
	return rectangle;
}

sf::RectangleShape CreateRectangle(sf::Vector2f _pos, sf::Vector2f _size, sf::Vector2f _origin, float _rotation, sf::Color _color)
{
	sf::RectangleShape rectangle;
	rectangle.setOrigin(_origin);
	rectangle.setPosition(_pos);
	rectangle.setSize(_size);
	rectangle.setRotation(_rotation);
	rectangle.setFillColor(_color);
	return rectangle;
}

//POINT/CIRCLE
bool pointCircle(sf::Vector2f _mpos, sf::Vector2f _cpos, float _r) {

	// get distance between the point and circle's center
	// using the Pythagorean Theorem
	float distX = _mpos.x - _cpos.x;
	float distY = _mpos.y - _cpos.y;
	float distance = sqrt((distX * distX) + (distY * distY));

	// if the distance is less than the circle's
	// radius the point is inside!
	if (distance <= _r) {
		return true;
	}
	return false;
}

// CIRCLE/CIRCLE
bool circleCircle(sf::Vector2f _c1pos, float _c1r, sf::Vector2f _c2pos, float _c2r) {

	// get distance between the circle's centers
	// use the Pythagorean Theorem to compute the distance
	float distX = _c1pos.x - _c2pos.x;
	float distY = _c1pos.y - _c2pos.y;
	float distance = sqrt((distX * distX) + (distY * distY));

	// if the distance is less than the sum of the circle's
	// radii, the circles are touching!
	if (distance <= _c1r + _c2r) {
		return true;
	}
	return false;
}

// POINT/RECTANGLE
bool pointRect(sf::Vector2f _mpos, sf::FloatRect _rect) {

	// is the point inside the rectangle's bounds?
	if (_mpos.x >= _rect.left &&        // right of the left edge AND
		_mpos.x <= _rect.left + _rect.width &&   // left of the right edge AND
		_mpos.y >= _rect.top &&        // below the top AND
		_mpos.y <= _rect.top + _rect.height) {   // above the bottom
		return true;
	}
	return false;
}

// RECTANGLE/RECTANGLE
bool rectRect(sf::FloatRect _rect1, sf::FloatRect _rect2) {

	// are the sides of one rectangle touching the other?

	if (_rect1.left + _rect1.width >= _rect2.left &&    // r1 right edge past r2 left
		_rect1.left <= _rect2.left + _rect2.width &&    // r1 left edge past r2 right
		_rect1.top + _rect1.height >= _rect2.top &&    // r1 top edge past r2 bottom
		_rect1.top <= _rect2.top + _rect2.height) {    // r1 bottom edge past r2 top
		return true;
	}
	return false;
}

// CIRCLE/RECTANGLE
bool circleRect(sf::Vector2f cpos, float radius, sf::FloatRect rect) {

	// temporary variables to set edges for testing
	float testX = cpos.x;
	float testY = cpos.y;

	// which edge is closest?
	if (cpos.x < rect.left)         testX = rect.left;      // test left edge
	else if (cpos.x > rect.left + rect.width) testX = rect.left + rect.width;   // right edge
	if (cpos.y < rect.top)         testY = rect.top;      // top edge
	else if (cpos.y > rect.top + rect.height) testY = rect.top + rect.height;   // bottom edge

	// get distance from closest edges
	float distX = cpos.x - testX;
	float distY = cpos.y - testY;
	float distance = sqrt((distX * distX) + (distY * distY));

	// if the distance is less than the radius, collision!
	if (distance <= radius) {
		return true;
	}
	return false;
}

//Addition de vector
sf::Vector2f AddVector2f(sf::Vector2f a, sf::Vector2f b)
{
	sf::Vector2f addVector2 = { a.x + b.x, a.y + b.y };
	return addVector2;
}

//Soustraction de vector
sf::Vector2f SubstractVector2f(sf::Vector2f a, sf::Vector2f b)
{
	sf::Vector2f substractVector2 = { a.x - b.x, a.y - b.y };
	return substractVector2;
}

//Multiplication de vector
sf::Vector2f MultiplyVector2f(sf::Vector2f a, float b)
{
	sf::Vector2f multiplyVector2 = { b * a.x, b * a.y };
	return multiplyVector2;
}

//Diviser vector
sf::Vector2f DivideVector2f(sf::Vector2f a, float b)
{
	sf::Vector2f divideVector2 = { a.x / b, a.y / b };
	return divideVector2;
}

//sert a obtenir l'angle entre deux vecteur
float DotProduct(sf::Vector2f a, sf::Vector2f b)
{
	return b.x * a.x + b.y * a.y;
}

//theore de pythagore
float GetNorme(sf::Vector2f a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

bool collisionbutton(float px, float py, float rx, float ry, float rw, float rh)
{
	if (px >= rx && px <= rx + rw && py >= ry && py <= ry + rh)
	{
		return true;
	}
	return false;
}

float GetDistance(sf::Vector2f a_, sf::Vector2f b_)
{
	return sqrt((b_.x - a_.x) * (b_.x - a_.x) + (b_.y - a_.y) * (b_.y - a_.y));
}

float GetDistance(sf::Vector2i a_, sf::Vector2i b_)
{
	return sqrt((b_.x - a_.x) * (b_.x - a_.x) + (b_.y - a_.y) * (b_.y - a_.y));
}

float GetSignedAngleBetween(sf::Vector2f a, sf::Vector2f b)
{
	return atan2f(a.x * b.y - a.y * b.x, a.x * b.x + a.y * b.y);
}

float GetSignedAngleBetweenB(sf::Vector2f _a, sf::Vector2f _b)
{
	return atan2f(_a.y - _b.y, _a.x - _b.x);
}

float GetAngleBetween(sf::Vector2f a, sf::Vector2f b)
{
	return fabsf(GetSignedAngleBetween(a, b));
}


float GetPi()
{
	return 3.1415926536f;
}


//obtenir combien l'angle fait de degré
float GetAngle(sf::Vector2f a, sf::Vector2f b)
{
	return acos(DotProduct(a, b) / (GetNorme(a) * GetNorme(b)));
}

//permet de choisir un nombre parmi le pourcentage demandé
sf::Vector2f Lerp(sf::Vector2f a, sf::Vector2f b, float t)
{
	return AddVector2f(MultiplyVector2f(SubstractVector2f(b, a), t), a);
}

//Transforme le vector pour qu'il renvoie 1 
sf::Vector2f Normalize(sf::Vector2f v)
{
	return DivideVector2f(v, GetNorme(v));
}



bool MenuCollision(sf::Vector2f MousePos_, float rx, float ry, float rw, float rh)
{
	// is the point inside the rectangle's bounds?
	if (MousePos_.x >= rx &&        // right of the left edge AND
		MousePos_.x <= rx + rw &&   // left of the right edge AND
		MousePos_.y >= ry &&        // below the top AND
		MousePos_.y <= ry + rh)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Retourne un int entre 0 et 7
//pour découper l'espace en 8 secteurs
//suivant où se trouve l'ennemi par rapport au joueur
//avec 0 = ennemi au-dessus du joueur
//ensuite on tourne en sens horaire
int decoupeSecteur(sf::Vector2f playerPos, sf::Vector2f enemyPos)
{
	int secteur;
	if (GetSignedAngleBetween(sf::Vector2f(1, 0), SubstractVector2f(playerPos, enemyPos)) > 3 * PI / 8.f && GetSignedAngleBetween(sf::Vector2f(1, 0), SubstractVector2f(playerPos, enemyPos)) <= 5 * PI / 8.f)
		secteur = 0;
	if (GetSignedAngleBetween(sf::Vector2f(1, 0), SubstractVector2f(playerPos, enemyPos)) > 5 * PI / 8.f && GetSignedAngleBetween(sf::Vector2f(1, 0), SubstractVector2f(playerPos, enemyPos)) <= 7 * PI / 8.f)
		secteur = 1;
	if (GetSignedAngleBetween(sf::Vector2f(1, 0), SubstractVector2f(playerPos, enemyPos)) > 7 * PI / 8.f || GetSignedAngleBetween(sf::Vector2f(1, 0), SubstractVector2f(playerPos, enemyPos)) <= -7 * PI / 8.f)
		secteur = 2;
	if (GetSignedAngleBetween(sf::Vector2f(1, 0), SubstractVector2f(playerPos, enemyPos)) > -7 * PI / 8.f && GetSignedAngleBetween(sf::Vector2f(1, 0), SubstractVector2f(playerPos, enemyPos)) <= -5 * PI / 8.f)
		secteur = 3;
	if (GetSignedAngleBetween(sf::Vector2f(1, 0), SubstractVector2f(playerPos, enemyPos)) > -5 * PI / 8.f && GetSignedAngleBetween(sf::Vector2f(1, 0), SubstractVector2f(playerPos, enemyPos)) <= -3 * PI / 8.f)
		secteur = 4;
	if (GetSignedAngleBetween(sf::Vector2f(1, 0), SubstractVector2f(playerPos, enemyPos)) > -3 * PI / 8.f && GetSignedAngleBetween(sf::Vector2f(1, 0), SubstractVector2f(playerPos, enemyPos)) <= -1 * PI / 8.f)
		secteur = 5;
	if (GetSignedAngleBetween(sf::Vector2f(1, 0), SubstractVector2f(playerPos, enemyPos)) > -1 * PI / 8.f && GetSignedAngleBetween(sf::Vector2f(1, 0), SubstractVector2f(playerPos, enemyPos)) <= 1 * PI / 8.f)
		secteur = 6;
	if (GetSignedAngleBetween(sf::Vector2f(1, 0), SubstractVector2f(playerPos, enemyPos)) > 1 * PI / 8.f && GetSignedAngleBetween(sf::Vector2f(1, 0), SubstractVector2f(playerPos, enemyPos)) <= 3 * PI / 8.f)
		secteur = 7;
	return secteur;
}

bool Escape_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
}

bool F1_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::F1);
}

bool F2_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::F2);
}

bool F3_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::F3);
}

bool F4_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::F4);
}

bool F5_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::F5);
}

bool F6_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::F6);
}

bool F7_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::F7);
}

bool F8_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::F8);
}

bool F9_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::F9);
}

bool F10_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::F10);
}

bool F11_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::F11);
}

bool F12_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::F12);
}

bool Suppr_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Delete);
}

bool Num1_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Num1);
}

bool Num2_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Num2);
}

bool Num3_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Num3);
}

bool Num4_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Num4);
}

bool Num5_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Num5);
}

bool Num6_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Num6);
}

bool Num7_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Num7);
}

bool Num8_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Num8);
}

bool Num9_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Num9);
}

bool Num0_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Num0);
}

bool Backspace_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace);
}

bool Divide_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Divide);
}

bool Multiply_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Multiply);
}

bool Substract_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract);
}

bool Tab_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Tab);
}

bool A_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
}

bool Z_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
}

bool E_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::E);
}

bool R_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::R);
}

bool T_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::T);
}

bool Y_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Y);
}

bool U_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::U);
}

bool I_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::I);
}

bool O_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::O);
}

bool P_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::P);
}

bool NumPad7_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7);
}

bool NumPad8_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8);
}

bool NumPad9_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9);
}

bool Add_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Add);
}

bool Q_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
}

bool S_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}

bool D_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::D);
}

bool F_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::F);
}

bool G_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::G);
}

bool H_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::H);
}

bool J_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::J);
}

bool K_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::K);
}

bool L_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::L);
}

bool M_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::M);
}

bool Enter_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
}

bool Numpad4_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4);
}

bool Numpad5_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5);
}

bool Numpad6_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6);
}

bool LeftShift_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
}

bool W_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
}

bool X_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::X);
}

bool C_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::C);
}

bool V_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::V);
}

bool B_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::B);
}

bool N_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::N);
}

bool Virgule_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Comma);
}

bool PointVirgule_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Period);
}

bool DeuxPoints_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Slash);
}

bool RightShift_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);
}

bool Numpad1_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1);
}

bool Numpad2_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2);
}

bool Numpad3_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3);
}

bool LeftControl_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);
}

bool Home_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem);
}

bool LeftAlt_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt);
}

bool Space_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

bool RightAlt_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt);
}

bool Menu_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Menu);
}

bool RightControl_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::RControl);
}

bool Up_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
}

bool Numpad0_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0);
}

bool Left_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
}

bool Down_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
}

bool Right_Pressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

bool RightClick()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Right);
}

bool LeftClick()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool MiddleClick()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Middle);
}

bool XButton1Click()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::XButton1);
}

bool XButton2Click()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::XButton2);
}

void printString(std::string string)
{
	std::cout << string << std::endl;
}

void printInt(int _int)
{
	std::cout << _int << std::endl;
}

void printDouble(double _double)
{
	std::cout << _double << std::endl;
}