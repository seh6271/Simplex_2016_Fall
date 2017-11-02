#ifndef _MYRIGIDBODY_H_
#define  _MYRIGIDBODY_H_

#include "MyMesh.h"
#include "MyCamera.h"
#include "Simplex\Simplex.h"

namespace Simplex
{

class MyRigidBody
{

	Mesh* m_BS = nullptr;
	Mesh* m_BB = nullptr;
	vector3 v3Min;
	vector3 v3Max;
	vector3 v3Center;

public:

	MyRigidBody(MyMesh* a_pObject);//constructor
	void Render(MyCamera* a_pCamera, matrix4 a_m4Model);
};

}

#endif //_MYRIGIDBODY_H_