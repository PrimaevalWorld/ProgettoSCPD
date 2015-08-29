#pragma once
#include "RelPixel.h"
#include <map>
using namespace std;
class Rilevatore
{
private:
	//AGGIUNGERE la porzione propria i atmosfera
	//gli va dato in pasto un insieme di riferimenti globali
	double LatSite;  //latitudine del telescopio cui appartiene il rilevatore
	double LongSite;
//4 telescopi --> 4 gruppi di 6 rilevatori e 4 posizioni diverse
	double Orientation;
	double FoV;  //Field of View: campo visivo del rivelatore, in gradi, centrato sull'Orientation
	bool Status; //indica se acceso o spento.
	int Resolution;
	map<int, RelPixel> Matrice_Osservazione;
public:
	Rilevatore();
	Rilevatore(double Lat, double Long, double fOv, int res);
	~Rilevatore();
	map<int, RelPixel> Rel2Ion(double In_X, double In_Y, double In_Z);
	bool GetStatus();
	double GetOrientation();
	double GetLatSite();
	double GetLongSite();
	int GetResolution();
};

