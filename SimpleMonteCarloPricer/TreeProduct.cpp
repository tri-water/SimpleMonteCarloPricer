#include "TreeProduct.h"

TreeProduct::TreeProduct(double fFinalTime):
FinalTime(fFinalTime)
{

}

double TreeProduct::GetFinalTime() const
{
	return FinalTime;
}