#include "RealGas.h"
RealGas::RealGas(int n,double t, double a, double r, double m, double E)
{
	this->n = n;
	this->t = t;
	this->a = a;
	this->r = r;
	this->m = m;
	this->E = E;
	this->nt = 1000;
	this->Epot = 0;
	this->Ekin = 0;
	this->Etot = 0;
	p = new Particle[n];
}

void RealGas::Epot_Ekin_Etot(double& Epot, double& Ekin, double& Etot)
{
	Epot = 0;
	Ekin = 0;
	Etot = 0;
	double r_x, r_y, r_z,r2,r6,r12;
	for (int i = 0;i < n;i++)
	{
		Ekin += 0.5 * m * (p[i].v_x * p[i].v_x + p[i].v_y * p[i].v_y + p[i].v_z * p[i].v_z);
		for (int j = i + 1;j < n;j++)
		{
			r_x = p[i].x - p[j].x;
			r_y = p[i].y - p[j].y;
			r_z = p[i].z - p[j].z;
			r2 = r_x * r_x + r_y * r_y + r_z * r_z;
			if (r2 < 10)
			{
				r2 = 1. / r2;
				r6 = r2 * r2 * r2;
				r12 = r6 * r6;
				Epot += 4. * (r12 - r6);
			}
		}
	}
	Etot = Ekin + Epot;
}
void RealGas::SetInit()
{
	srand(NULL);
	do
	{
		for (int i = 0;i < n;i++)
		{
			p[i].dv_rx = 0;
			p[i].dv_ry = 0;
			p[i].dv_rz = 0;
			p[i].x = (a - 1) * rand() / RAND_MAX + 0.5;
			p[i].y = (a - 1) * rand() / RAND_MAX + 0.5;
			p[i].z = (a - 1) * rand() / RAND_MAX + 0.5;
			p[i].v_x = 0;
			p[i].v_y = 0;
			p[i].v_z = 0;
			p[i].x1 = p[i].x;
			p[i].y1 = p[i].y;
			p[i].z1 = p[i].z;
			Epot_Ekin_Etot(Epot, Ekin, Etot);
			
		}
	} while (Etot > E);

	for (int i = 0;i < n;i++)
	{
		p[i].v_x = sqrt(3. * (E - Epot))/n;
		p[i].v_y = sqrt(3. * (E - Epot)) / n;
		p[i].v_z = sqrt(3. * (E - Epot)) / n;
	}
}

void RealGas::Force()
{
	double r2, r8, r14, r_x, r_y, r_z,f;
	for (int i = 0;i < n;i++)
	{
		/*p[i].x1 = p[i].x;
		p[i].y1 = p[i].y;
		p[i].z1 = p[i].z;
		p[i].x = 0;
		p[i].y = 0;
		p[i].z = 0;*/
		p[i].dv_rx1 = p[i].dv_rx;
		p[i].dv_ry1 = p[i].dv_ry;
		p[i].dv_rz1 = p[i].dv_rz;
		p[i].dv_rx = 0;
		p[i].dv_ry = 0;
		p[i].dv_rz = 0;

	}
	for (int i = 0;i < n;i++)
	{

		for (int j = i + 1;j < n;j++)
		{
			r_x = p[i].x - p[j].x;
			r_y = p[i].y - p[j].y;
			r_z = p[i].z - p[j].z;
			r2 = r_x * r_x + r_y * r_y + r_z * r_z;
			if (r2 < 10)
			{
				r2 = 1. / r2;
				r8 = r2 * r2 * r2 * r2;
				r14 = r8 * r8 / r2;
				f = 24 * (2. * r14 - r8);
				p[i].dv_rx = f*r_x;
				p[i].dv_ry = f * r_y;
				p[i].dv_rz = f * r_z;
				p[j].dv_rx = -f * r_x;
				p[j].dv_ry = -f * r_y;
				p[j].dv_rz = -f * r_z;
			}
			
		}
	}
}

void RealGas::DoOneStep()
{
	
	for (int j = 0;j < nt;j++)
	{
		Force();
		for (int i = 0;i < n;i++)
		{

			p[i].x += (p[i].v_x + 0.5 * p[i].dv_rx * t) * t;
			p[i].y += (p[i].v_y + 0.5 * p[i].dv_ry * t) * t;
			p[i].z += (p[i].v_z + 0.5 * p[i].dv_rz * t) * t;
			p[i].v_x += 0.5 * (p[i].dv_rx + p[i].dv_rx1) * t;
			p[i].v_y += 0.5 * (p[i].dv_ry + p[i].dv_ry1) * t;
			p[i].v_z += 0.5 * (p[i].dv_rz + p[i].dv_rz1) * t;

			if (p[i].x >= (a - r) && p[i].v_x > 0)
			{
				p[i].v_x = -p[i].v_x;
				//p[i].x1 = 2 * p[i].x - p[i].x1;
			}
			if (p[i].y >= (a - r) && p[i].v_y > 0)
			{
				p[i].v_y = -p[i].v_y;
				//p[i].y1 = 2 * p[i].y - p[i].y1;
			}
			if (p[i].z >= (a - r) && p[i].v_z > 0)
			{
				p[i].v_z = -p[i].v_z;
				//p[i].z1 = 2 * p[i].z - p[i].z1;
			}
			if (p[i].x <= r && p[i].v_x < 0)
			{
				p[i].v_x = -p[i].v_x;
				//p[i].x1 = 2 * p[i].x - p[i].x1;
			}
			if (p[i].y <= r && p[i].v_y < 0)
			{
				p[i].v_y = -p[i].v_y;
				//p[i].y1 = 2 * p[i].y - p[i].y1;
			}
			if (p[i].z <= r && p[i].v_z < 0)
			{
				p[i].v_z = -p[i].v_z;
				//p[i].z1 = 2 * p[i].z - p[i].z1;
			}

		}
	}

	Epot_Ekin_Etot(Epot, Ekin, Etot);
	double  vf;
	vf = sqrt(abs(E - Epot) / Ekin);
	for (int i = 0;i < n;i++)
	{
		p[i].v_x *= vf;
		p[i].v_y *= vf;
		p[i].v_z *= vf;
	}
	
}

