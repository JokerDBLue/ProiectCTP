#include "ContBancar.h"


ContBancar::ContBancar()
{
	this->balans = 0;
	this->cod = "";
	this->codspate = "";
}
ContBancar::ContBancar(string cod, string codspate, float balans)
{
	this->balans = balans;
	this->cod = cod;
	this->codspate = codspate;
}
string ContBancar::GetCod()
{
	return cod;
}
string ContBancar::GetCodSpate()
{
	return codspate;
}
float ContBancar::GetBalans()
{
	return balans;
}

void ContBancar::SetCod(string cod)
{
	this->cod = cod;
}
void ContBancar::SetCodSpate(string codspate)
{
	this->codspate = codspate;
}

void ContBancar::SetBalans(float balans)
{
	this->balans = balans;
}

bool ContBancar::operator==(const ContBancar & cb)
{
	if ((cb.cod == this->cod) && (cb.codspate == this->codspate))
		return true;
	return false;
}

ContBancar::~ContBancar()
{
}