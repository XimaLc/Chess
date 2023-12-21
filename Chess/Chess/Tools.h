#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#define RAD2DEG 57.295779f
//RAD2DEG multiplier par DEG2RAD pour avoir les radiants
#define DEG2RAD 0.017453f
//DEG2RAD multiplier par RAD2DEG pour avoir les degrés
#define PI 3.14159265358979323846
//Buttons sizes
#define BUTTON_WIDTH 400.f
#define BUTTON_HEIGHT 100.f
#define KEY(_A) sf::Keyboard::isKeyPressed(sf::Keyboard::_A)
#define MOUSE(_Left) sf::Mouse::isButtonPressed(sf::Mouse::_Left)
//-----------------------------------------------------------
//	Fonction d'initialisation des tools
//	à mettre obligatoirement dans votre init 
//	pour utiliser les fonctions de cette bibliothèque
//-----------------------------------------------------------
enum state {menu, game, options};


void setState(int state);
int getState();

void initTools();

float GetDeltaTime();

void restartClock();

int rand_int(int _min, int _max);

double rand_float(float _min, float _max);

sf::CircleShape CreateCircle(sf::Texture& _texture, sf::Vector2f _pos = sf::Vector2f(), float _radius = 0.f, sf::Vector2f _origin = sf::Vector2f(), float _rotation = 0.f, sf::Color _color = sf::Color());

sf::CircleShape CreateCircle(sf::Vector2f _pos = sf::Vector2f(), float _radius = 0.f, sf::Vector2f _origin = sf::Vector2f(), float _rotation = 0.f, sf::Color _color = sf::Color());

sf::RectangleShape CreateRectangle(sf::Texture& _texture, sf::Vector2f _pos = sf::Vector2f(), sf::Vector2f _size = sf::Vector2f(), sf::Vector2f _origin = sf::Vector2f(), float _rotation = 0.f, sf::Color _color = sf::Color(255, 255, 255));

sf::RectangleShape CreateRectangle(sf::Vector2f _pos = sf::Vector2f(), sf::Vector2f _size = sf::Vector2f(), sf::Vector2f _origin = sf::Vector2f(), float _rotation = 0.f, sf::Color _color = sf::Color(255, 255, 255));

//POINT/CIRCLE
bool pointCircle(sf::Vector2f _mpos, sf::Vector2f _cpos, float _r);

// CIRCLE/CIRCLE
bool circleCircle(sf::Vector2f _c1pos, float _c1r, sf::Vector2f _c2pos, float _c2r);

// POINT/RECTANGLE
bool pointRect(sf::Vector2f _mpos, sf::FloatRect _rect);

// RECTANGLE/RECTANGLE
bool rectRect(sf::FloatRect _rect1, sf::FloatRect _rect2);

// CIRCLE/RECTANGLE
bool circleRect(sf::Vector2f cpos, float radius, sf::FloatRect rect);

sf::Vector2f AddVector2f(sf::Vector2f a, sf::Vector2f b);

sf::Vector2f SubstractVector2f(sf::Vector2f a, sf::Vector2f b);

sf::Vector2f MultiplyVector2f(sf::Vector2f a, float b);

sf::Vector2f DivideVector2f(sf::Vector2f a, float b);

sf::Vector2f Lerp(sf::Vector2f a, sf::Vector2f b, float t);

sf::Vector2f Normalize(sf::Vector2f v);

float GetAngle(sf::Vector2f a, sf::Vector2f b);

float DotProduct(sf::Vector2f a, sf::Vector2f b);

float GetNorme(sf::Vector2f a);

float GetSignedAngleBetween(sf::Vector2f a, sf::Vector2f b);

float GetSignedAngleBetweenB(sf::Vector2f a, sf::Vector2f b);

float GetAngleBetween(sf::Vector2f a, sf::Vector2f b);

bool collisionbutton(float px, float py, float rx, float ry, float rw, float rh);

float GetDistance(sf::Vector2f a_, sf::Vector2f b_);
float GetDistance(sf::Vector2i a_, sf::Vector2i b_);

float GetPi();

int decoupeSecteur(sf::Vector2f playerPos, sf::Vector2f enemyPos);

/* utilisation simplifiée du clavier */
// first line keyboard //
bool Escape_Pressed();
bool F1_Pressed();
bool F2_Pressed();
bool F3_Pressed();
bool F4_Pressed();
bool F5_Pressed();
bool F6_Pressed();
bool F7_Pressed();
bool F8_Pressed();
bool F9_Pressed();
bool F10_Pressed();
bool F11_Pressed();
bool F12_Pressed();
bool Suppr_Pressed();
// second line keyboard //
bool Num1_Pressed();
bool Num2_Pressed();
bool Num3_Pressed();
bool Num4_Pressed();
bool Num5_Pressed();
bool Num6_Pressed();
bool Num7_Pressed();
bool Num8_Pressed();
bool Num9_Pressed();
bool Num0_Pressed();
bool Backspace_Pressed();
bool Divide_Pressed();
bool Multiply_Pressed();
bool Substract_Pressed();
// third line keyboard //
bool Tab_Pressed();
bool A_Pressed();
bool Z_Pressed();
bool E_Pressed();
bool R_Pressed();
bool T_Pressed();
bool Y_Pressed();
bool U_Pressed();
bool I_Pressed();
bool O_Pressed();
bool P_Pressed();
bool NumPad7_Pressed();
bool NumPad8_Pressed();
bool NumPad9_Pressed();
bool Add_Pressed();
// fourth line keyboard //
bool Q_Pressed();
bool S_Pressed();
bool D_Pressed();
bool F_Pressed();
bool G_Pressed();
bool H_Pressed();
bool J_Pressed();
bool K_Pressed();
bool L_Pressed();
bool M_Pressed();
bool Enter_Pressed();
bool Numpad4_Pressed();
bool Numpad5_Pressed();
bool Numpad6_Pressed();
// fifth line keyboard //
bool LeftShift_Pressed();
bool W_Pressed();
bool X_Pressed();
bool C_Pressed();
bool V_Pressed();
bool B_Pressed();
bool N_Pressed();
bool Virgule_Pressed();
bool PointVirgule_Pressed();
bool DeuxPoints_Pressed();
bool RightShift_Pressed();
bool Numpad1_Pressed();
bool Numpad2_Pressed();
bool Numpad3_Pressed();
// sixth line keyboard //
bool LeftControl_Pressed();
bool Home_Pressed();
bool LeftAlt_Pressed();
bool Space_Pressed();
bool RightAlt_Pressed();
bool Menu_Pressed();
bool RightControl_Pressed();
bool Up_Pressed();
bool Numpad0_Pressed();
bool Left_Pressed();
bool Down_Pressed();
bool Right_Pressed();

/* utilisation simplifiée de la souris */
// mouse controls //
bool RightClick();
bool LeftClick();
bool MiddleClick();
bool XButton1Click();
bool XButton2Click();
void printString(std::string string);
void printInt(int _int);
void printDouble(double _double);