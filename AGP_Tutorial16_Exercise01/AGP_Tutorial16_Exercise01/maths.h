#pragma once
#include "objfilemodel.h"

class Maths
{
public:

	struct Plane
	{
		ObjFileModel::xyz normal; // the normal to the plane
		float d; // the 'd' constant in the equation for this plane
	};

	float DotProduct(ObjFileModel::xyz* Vector1, ObjFileModel::xyz* Vector2);
	ObjFileModel::xyz* CrossProduct(ObjFileModel::xyz* Vector1, ObjFileModel::xyz* Vector2);
	ObjFileModel::xyz* Normal(ObjFileModel::xyz* Vector1, ObjFileModel::xyz* Vector2, ObjFileModel::xyz* Vector3);
	Plane PlaneEquation(ObjFileModel::xyz* Vector1, ObjFileModel::xyz* Vector2, ObjFileModel::xyz* Vector3);
	float PlaneEquationForPoint(Plane Plane, ObjFileModel::xyz* Vector);

};
