#include "MyOctant.h"
using namespace Simplex;

//uint MyOctant::m_uOctantCount = 0;
//uint MyOctant::m_uMaxLevel = 3;
//uint MyOctant::m_uIdealEntityCount = 5;

Simplex::MyOctant::MyOctant(uint a_nMaxLevel, uint a_nIdealEntityCount)
{
	//constructor
	Init();
	
	//vars passed in
	m_uMaxLevel = a_nMaxLevel;
	m_uIdealEntityCount = a_nIdealEntityCount;



}

Simplex::MyOctant::MyOctant(vector3 a_v3Center, float a_fSize)
{

}

Simplex::MyOctant::MyOctant(MyOctant const & other)
{
}

//MyOctant & Simplex::MyOctant::operator=(MyOctant const & other)
//{
//	// TODO: insert return statement here
//
//}


Simplex::MyOctant::~MyOctant(void)
{
}

void Simplex::MyOctant::Swap(MyOctant & other)
{
	std::swap(m_uID, other.m_uID);
	std::swap(m_uLevel, other.m_uLevel);
	std::swap(m_uChildren, other.m_uChildren);

	std::swap(m_fSize, other.m_fSize);

	std::swap(m_v3Center, other.m_v3Center);
	std::swap(m_v3Max, other.m_v3Max);
	std::swap(m_v3Min, other.m_v3Min);

	std::swap(m_pParent, other.m_pParent);
	for (int i = 0; i < 8; i++)
	{
		std::swap(m_pChild[i], other.m_pChild[i]);
	}

	std::swap(m_pRoot, other.m_pRoot);
	std::swap(m_lChild, other.m_lChild);

}

float Simplex::MyOctant::GetSize(void)
{
	return m_fSize;
}

vector3 Simplex::MyOctant::GetCenterGlobal(void)
{
	return m_v3Center;
}

vector3 Simplex::MyOctant::GetMinGlobal(void)
{
	return m_v3Min;
}

vector3 Simplex::MyOctant::GetMaxGlobal(void)
{
	return m_v3Max;
}

bool Simplex::MyOctant::IsColliding(uint a_uRBIndex)
{
	return false;
}

void Simplex::MyOctant::Display(uint a_nIndex, vector3 a_v3Color)
{
}

void Simplex::MyOctant::Display(vector3 a_v3Color)
{
}

void Simplex::MyOctant::DisplayLeafs(vector3 a_v3Color)
{
}

void Simplex::MyOctant::ClearEntityList(void)
{
}

void Simplex::MyOctant::Subdivide(void)
{
}

MyOctant * Simplex::MyOctant::GetChild(uint a_nChild)
{
	return m_pChild[a_nChild];
}

MyOctant * Simplex::MyOctant::GetParent(void)
{
	return m_pParent;
}

bool Simplex::MyOctant::IsLeaf(void)
{
	//if no children = leaf
	if (m_pChild[0] == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool Simplex::MyOctant::ContainsMoreThan(uint a_nEntities)
{
	return false;
}

void Simplex::MyOctant::KillBranches(void)
{
}

void Simplex::MyOctant::ConstructTree(uint a_nMaxLevel)
{
}

void Simplex::MyOctant::AssignIDtoEntity(void)
{
}

uint Simplex::MyOctant::GetOctantCount(void)
{
	return m_uOctantCount;
}

void Simplex::MyOctant::Release(void)
{
}

void Simplex::MyOctant::Init(void)
{
	//set all variables to 0/start
	//m_uID = m_uOctantCount; 
	//m_uLevel = 0; 
	//m_uChildren = 0;

	//m_fSize = 0.0f;

	m_pMeshMngr = MeshManager::GetInstance();
	m_pEntityMngr = MyEntityManager::GetInstance();

	/*m_v3Center = vector3(0.0f,0.0f,0.0f);
	m_v3Max = vector3(0.0f, 0.0f, 0.0f);
	m_v3Min = vector3(0.0f, 0.0f, 0.0f);

	m_pParent = nullptr;
	for (int i = 0; i < 8; i++)
	{
		m_pChild[i] = nullptr;
	}

	m_pRoot = nullptr;*/

}

void Simplex::MyOctant::ConstructList(void)
{
}
