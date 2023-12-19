#include "Game.h"
//#include "Client.h"

int main()
{
	//Game game;
	Client client;

	bool running = true;
	int x;
	while (running)
	{
		std::cout << "1 pour envoyer; 0 pour quitter" << std::endl;
		std::cin >> x;
		std::cin.ignore();
		if (x == 0)
			running = false;
		if(x == 1)
			client.sendMessage("MESSAGE");
	}
}