#pragma once

class Diff
{
protected:
	double m_Accuracy = 0.0;
	virtual double calc_Diff(std::function <double(double)>& f, double x0, double Dx)
	{
		return 0.0;
	}
public:
	double Accuracy()
	{
		return m_Accuracy;
	}
	double Func(std::function <double(double)>& f, double x0, double Dx)
	{
		return calc_Diff(f,x0,Dx);
	}
};

class LeftDiff : public Diff
{
	double calc_Diff(std::function <double(double)>& f, double x0, double Dx) override
	{
		m_Accuracy = Dx;
		return (f(x0) - f(x0 - Dx)) / Dx;
	}
};

class RightDiff : public Diff
{
	double calc_Diff(std::function <double(double)>& f, double x0, double Dx) override
	{
		m_Accuracy = Dx;
		return (f(x0 + Dx) - f(x0)) / Dx;
	}
};

class middleDiff : public Diff
{
	double calc_Diff(std::function <double(double)>& f, double x0, double Dx) override
	{
		m_Accuracy = Dx * Dx;
		return (f(x0 + Dx) - f(x0 - Dx)) / (2 * Dx);
	}
};
