#pragma once
#include<iostream>
#include<ctime>

struct  Particle 
{
	double x, y, z, v_x, v_y, v_z, x1, y1, z1,dv_rx,dv_ry,dv_rz, dv_rx1, dv_ry1, dv_rz1;

};
class RealGas
{
private:

	int n;

public:
	double a, r, m, E,Epot,Ekin,Etot,t;
	int nt;
	Particle* p;
	RealGas(int n, double t,double a, double r, double m, double E);
	void Epot_Ekin_Etot(double& Epot, double& Ekin, double& Etot);
	void SetInit();
	void DoOneStep();
	void Force();

};

