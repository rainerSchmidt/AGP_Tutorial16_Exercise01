#include "maths.h"

float Maths::DotProduct(ObjFileModel::xyz* v1, ObjFileModel::xyz* v2)
{
	float dot = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
	return dot;
}

ObjFileModel::xyz* Maths::CrossProduct(ObjFileModel::xyz* v1, ObjFileModel::xyz* v2)
{
	ObjFileModel::xyz* Vector3;

	Vector3->x = (v1->y * v2->z) - (v1->z * v2->y);
	Vector3->y = (v1->z * v2->x) - (v1->x * v2->z);
	Vector3->z = (v1->x * v2->y) - (v1->y * v2->x);

	return Vector3;
}

ObjFileModel::xyz* Maths::Normal(ObjFileModel::xyz* v1, ObjFileModel::xyz* v2, ObjFileModel::xyz* v3)
{
	ObjFileModel::xyz* normal;


}