#ifndef SFML_WINDOW_H_
#define SFML_WINDOW_H_

#include <SFML/Graphics.hpp>
#include "client.hpp"

//int SFML_test();
class		SFML_win : public Client
{
public:
	SFML_win();
	~SFML_win();

	Client	*client;
	int		get_win_x();
	int		get_win_y();
	void	set_win_x();
	void	set_win_y();

private:
	int		win_x;
	int		win_y;
};

#endif /* !SFML_WINDOW_H_ */