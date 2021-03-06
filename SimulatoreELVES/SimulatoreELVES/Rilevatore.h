#pragma once
#include "RelPixel.h"
#include <map>
using namespace std;
class Rilevatore
{
private:
	//se la posizione è identificata da latitudine e longitudine, x,y,z sono inutili.
	/*double PosX;  //si riferiscono alla posizione del rilevatore una sorta di media della posizione dei singoli pixel
	double PosY;
	double PosZ;*/
	//AGGIUNGERE la porzione propria i atmosfera
	//gli va dato in pasto un insieme di riferimenti globali
	double LatSite;  //latitudine del telescopio cui appartiene il rilevatore
	double LongSite;
//4 telescopi --> 4 gruppi di 6 rilevatori e 4 posizioni diverse
	double Orientation;
	double right_end;  //limite destro del fov, in radianti
	double left_end;  //limite sinistro del fov, in radianti
	bool Status; //indica se acceso o spento.
	int ResolutionX;
	int ResolutionY;
	map<int, RelPixel*> Mirror1;
	map<int, RelPixel*> Mirror2;
	map<int, RelPixel*> Mirror3;
	map<int, RelPixel*> Mirror4;
	map<int, RelPixel*> Mirror5;
	map<int, RelPixel*> Mirror6;
public:
	Rilevatore();
	Rilevatore(double Lat, double Long, double r_e);
	~Rilevatore();
	map<int, RelPixel*> Rel2Ion(double pix_lat, double pix_long);
	bool GetStatus();
	double GetOrientation();
	/*double GetX();
	double GetY();
	double GetZ();*/
	double GetLatSite();
	double GetLongSite();
	int GetResolution();
	bool Spotted(double alpha);
	void SetStatus(bool In_Status);
};

