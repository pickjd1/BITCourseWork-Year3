#pragma once
#include "Pellet.h"

ref class PelletList
{
private:
	Pellet^ head;
	Pellet^ tail;
public:
	PelletList(void);
	void addPellet(Pellet^ newPellet);
	void deletePellet(Pellet^ pelletToDelete);
	void renderPellets();
	int countPellets();
	void updatePellets();
};
