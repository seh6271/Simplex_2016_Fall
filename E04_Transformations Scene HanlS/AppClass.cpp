#include "AppClass.h"
void Application::InitVariables(void)
{
	////Change this to your name and email
	m_sProgrammer = "Shannon Hanley - seh6271@g.rit.edu";

	////Alberto needed this at this position for software recording.
	//m_pWindow->setPosition(sf::Vector2i(710, 0));

	//fill the vector
	for (int i = 0; i < 46; i++)
	{
		MyMesh* m_pMesh = nullptr;

		//init the meshes
		m_pMesh = new MyMesh();
		m_pMesh->GenerateCone(1.0f,1.5f, 10, C_GREEN_LIME);

		m_vpCubes.push_back(m_pMesh);
	}
	
	timer = 150;
	change = .05f;
	
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();	

	//movement vars
	timer++;
	if (timer > 300)
	{
		timer = 0;
		change *= -1;
	}

	
	//get proj + view matrices
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();

	//use the same scale for every cube
	matrix4 m4Scale = glm::scale(IDENTITY_M4, vector3(1.0f, 1.0f, 1.0f));

	SetPositions();

	static float value = 0.0f;
	
	value += 0.01f;

	//render shape
	for (int i = 0; i < 46; i++)
	{
		matrix4 m4Translate = glm::translate(IDENTITY_M4, m_vv3Transforms[i]);
		matrix4 m4Model = m4Scale * m4Translate;
		m_vpCubes[i]->Render(m4Projection, m4View, m4Model);
	}
	
	MoveShape();

	//m_pMesh->Render(m4Projection, m4View, m4Model);
	
	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();
	
	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}

void Application::SetPositions()
{
	//create a transform matrix for every cube and add it to the vector
#pragma region transform matrices
	//bottom row
	vector3 v3Translate1 =  vector3(1.0f, -2.0f, -3.0f);
	vector3 v3Translate2 =  vector3(2.0f, -2.0f, -3.0f);
	vector3 v3Translate3 =  vector3(-1.0f, -2.0f, -3.0f);
	vector3 v3Translate4 =  vector3(-2.0f, -2.0f, -3.0f);
	//second row
	vector3 v3Translate5 =  vector3(3.0f, -1.0f, -3.0f);
	vector3 v3Translate6 =  vector3(5.0f, -1.0f, -3.0f);
	vector3 v3Translate7 =  vector3(-3.0f, -1.0f, -3.0f);
	vector3 v3Translate8 =  vector3(-5.0f, -1.0f, -3.0f);
	//third row
	vector3 v3Translate9 =  vector3(0.0f, 0.0f, -3.0f);
	vector3 v3Translate10 =  vector3(1.0f, 0.0f, -3.0f);
	vector3 v3Translate11 =  vector3(2.0f, 0.0f, -3.0f);
	vector3 v3Translate12 =  vector3(3.0f, 0.0f, -3.0f);
	vector3 v3Translate13 =  vector3(5.0f, 0.0f, -3.0f);
	vector3 v3Translate14 =  vector3(-1.0f, 0.0f, -3.0f);
	vector3 v3Translate15 =  vector3(-2.0f, 0.0f, -3.0f);
	vector3 v3Translate16 =  vector3(-3.0f, 0.0f, -3.0f);
	vector3 v3Translate17 =  vector3(-5.0f, 0.0f, -3.0f);
	//fourth row
	vector3 v3Translate18 =  vector3(0.0f, 1.0f, -3.0f);
	vector3 v3Translate19 =  vector3(1.0f, 1.0f, -3.0f);
	vector3 v3Translate20 =  vector3(2.0f, 1.0f, -3.0f);
	vector3 v3Translate21 =  vector3(3.0f, 1.0f, -3.0f);
	vector3 v3Translate22 =  vector3(4.0f, 1.0f, -3.0f);
	vector3 v3Translate23 =  vector3(5.0f, 1.0f, -3.0f);
	vector3 v3Translate24 =  vector3(-1.0f, 1.0f, -3.0f);
	vector3 v3Translate25 =  vector3(-2.0f, 1.0f, -3.0f);
	vector3 v3Translate26 =  vector3(-3.0f, 1.0f, -3.0f);
	vector3 v3Translate27 =  vector3(-4.0f, 1.0f, -3.0f);
	vector3 v3Translate28 =  vector3(-5.0f, 1.0f, -3.0f);
	//fifth row
	vector3 v3Translate29 =  vector3(0.0f, 2.0f, -3.0f);
	vector3 v3Translate30 =  vector3(1.0f, 2.0f, -3.0f);
	vector3 v3Translate31 =  vector3(3.0f, 2.0f, -3.0f);
	vector3 v3Translate32 =  vector3(4.0f, 2.0f, -3.0f);
	vector3 v3Translate33 =  vector3(-1.0f, 2.0f, -3.0f);
	vector3 v3Translate34 =  vector3(-3.0f, 2.0f, -3.0f);
	vector3 v3Translate35 =  vector3(-4.0f, 2.0f, -3.0f);
	//sixth row
	vector3 v3Translate36 =  vector3(0.0f, 3.0f, -3.0f);
	vector3 v3Translate37 =  vector3(1.0f, 3.0f, -3.0f);
	vector3 v3Translate38 =  vector3(2.0f, 3.0f, -3.0f);
	vector3 v3Translate39 =  vector3(3.0f, 3.0f, -3.0f);
	vector3 v3Translate40 =  vector3(-1.0f, 3.0f, -3.0f);
	vector3 v3Translate41 =  vector3(-2.0f, 3.0f, -3.0f);
	vector3 v3Translate42 =  vector3(-3.0f, 3.0f, -3.0f);
	//seventh row
	vector3 v3Translate43 =  vector3(2.0f, 4.0f, -3.0f);
	vector3 v3Translate44 =  vector3(-2.0f, 4.0f, -3.0f);
	//top row
	vector3 v3Translate45 =  vector3(3.0f, 5.0f, -3.0f);
	vector3 v3Translate46 =  vector3(-3.0f, 5.0f, -3.0f);

#pragma endregion

#pragma region vector push_back

	m_vv3Transforms.push_back(v3Translate1);
	m_vv3Transforms.push_back(v3Translate2);
	m_vv3Transforms.push_back(v3Translate3);
	m_vv3Transforms.push_back(v3Translate4);
	m_vv3Transforms.push_back(v3Translate5);
	m_vv3Transforms.push_back(v3Translate6);
	m_vv3Transforms.push_back(v3Translate7);
	m_vv3Transforms.push_back(v3Translate8);
	m_vv3Transforms.push_back(v3Translate9);
	m_vv3Transforms.push_back(v3Translate10);
	m_vv3Transforms.push_back(v3Translate11);
	m_vv3Transforms.push_back(v3Translate12);
	m_vv3Transforms.push_back(v3Translate13);
	m_vv3Transforms.push_back(v3Translate14);
	m_vv3Transforms.push_back(v3Translate15);
	m_vv3Transforms.push_back(v3Translate16);
	m_vv3Transforms.push_back(v3Translate17);
	m_vv3Transforms.push_back(v3Translate18);
	m_vv3Transforms.push_back(v3Translate19);
	m_vv3Transforms.push_back(v3Translate20);
	m_vv3Transforms.push_back(v3Translate21);
	m_vv3Transforms.push_back(v3Translate22);
	m_vv3Transforms.push_back(v3Translate23);
	m_vv3Transforms.push_back(v3Translate24);
	m_vv3Transforms.push_back(v3Translate25);
	m_vv3Transforms.push_back(v3Translate26);
	m_vv3Transforms.push_back(v3Translate27);
	m_vv3Transforms.push_back(v3Translate28);
	m_vv3Transforms.push_back(v3Translate29);
	m_vv3Transforms.push_back(v3Translate30);
	m_vv3Transforms.push_back(v3Translate31);
	m_vv3Transforms.push_back(v3Translate32);
	m_vv3Transforms.push_back(v3Translate33);
	m_vv3Transforms.push_back(v3Translate34);
	m_vv3Transforms.push_back(v3Translate35);
	m_vv3Transforms.push_back(v3Translate36);
	m_vv3Transforms.push_back(v3Translate37);
	m_vv3Transforms.push_back(v3Translate38);
	m_vv3Transforms.push_back(v3Translate39);
	m_vv3Transforms.push_back(v3Translate40);
	m_vv3Transforms.push_back(v3Translate41);
	m_vv3Transforms.push_back(v3Translate42);
	m_vv3Transforms.push_back(v3Translate43);
	m_vv3Transforms.push_back(v3Translate44);
	m_vv3Transforms.push_back(v3Translate45);
	m_vv3Transforms.push_back(v3Translate46);
	
#pragma endregion

}

void Application::MoveShape()
{
	for (int i = 0; i < 46; i++)
	{
		m_vv3Transforms[i].x += change;
	}
}
void Application::Release(void)
{
	//empty the vector
	for (int i = 0; i < 46; i++)
	{
	SafeDelete(m_vpCubes[i])
	}

	//release GUI
	ShutdownGUI();
}