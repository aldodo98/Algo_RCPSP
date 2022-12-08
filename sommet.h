#pragma once
class sommet
{
public:
	int numero_sommet;
	int cout_ressource;
	int duree;
	int nombre_succ;
	int succ[10] = {0};
	int position = 0;

	sommet();
	sommet(int,int,int,int);
};

