#include "maths.h"

ObjFileModel::xyz* Maths::Normalise(ObjFileModel::xyz* v)
{
	ObjFileModel::xyz* vector;
	vector->x = v->x;
	vector->y = v->y;
	vector->z = v->z;

	//Normalise the normal
	float length = sqrt((vector->x * vector->x) + (vector->y * vector->y) + (vector->z * vector->z));
	vector->x /= length;
	vector->y /= length;
	vector->z /= length;

	return vector;
}

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

ObjFileModel::xyz* Maths::Normal(ObjFileModel::xyz* A, ObjFileModel::xyz* B, ObjFileModel::xyz* C)
{

	ObjFileModel::xyz* v1;
	ObjFileModel::xyz* v2;

	v1->x = B->x - A->x;
	v1->y = B->y - A->y;
	v1->z = B->z - A->z;

	v2->x= C->x - A->x;
	v2->y = C->y - A->y;
	v2->z = C->z - A->z;

	ObjFileModel::xyz* normal = CrossProduct(v1,v2);

	normal = Normalise(normal);

	return normal;

}

Maths::Plane Maths::PlaneEquation(ObjFileModel::xyz* v1, ObjFileModel::xyz* v2, ObjFileModel::xyz* v3)
{
	//calculate the normal vector to the triangle
	ObjFileModel::xyz* normal = Normal(v1, v2, v3);

	//calculate the d offset
	float d = -DotProduct(v1, normal);

	Maths::Plane plane;
	plane.d = d;
	plane.normal = *normal;

	return plane;
}

float Maths::PlaneEquationForPoint(Plane p, ObjFileModel::xyz* v)
{
	float result = (p.normal.x * v->x) + (p.normal.y * v->y) + (p.normal.z * v->z) + p.d;
	return result;
}