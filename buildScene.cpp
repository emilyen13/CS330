#include "buildScene.h"
#include "buildShape.h"
#include "meshes (1).h"

using namespace std;

void BuildScene::UBuildScene(vector<GLMesh>& scene)
{

	//seed the rand() function once
	srand(time(nullptr));

	//nail polish box
	GLMesh BoxMesh;
	BoxMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color (rgba)
		1.4f, 0.5f, 0.6f,					// scale (xyz)
		0.0f, 1.0f, 0.0f, 0.0f,				// x rotation (xyz)
		0.0f, 0.0f, 1.0f, 0.0f,				// y rotation (xyz)
		0.0f, 0.0f, 0.0f, 1.0f,				// z rotation (xyz)
		0.5f, 0.02f, 2.0f,					// translate (xyz)
		2.0f, 2.0f
	};
	//BoxMesh.height = 0.8f;
	BoxMesh.texFilename = "images\\box_texture.jpg";
	BuildShape::UBoxMesh(BoxMesh);
	scene.push_back(BoxMesh);


	//nail polish bottle
	GLMesh BottleMesh;
	BottleMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color (rgba)
		0.5f, 0.75f, 0.5f,					// scale (xyz)
		0.0f, 1.0f, 0.0f, 0.0f,				// x rotation (xyz)
		0.0f, 0.0f, 1.0f, 0.0f,				// y rotation (xyz)
		0.0f, 0.0f, 0.0f, 1.0f,				// z rotation (xyz)
		-1.0f, 0.02f, 2.0f,					// translate (xyz)
		2.0f, 2.0f
	};
	//BottleMesh.height = 0.8f;
	BottleMesh.texFilename = "images\\bottle_texture.jpg";
	BuildShape::UBottleMesh(BottleMesh);
	scene.push_back(BottleMesh);


	//nail polish brush
	GLMesh BrushMesh;
	BrushMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color (rgba)
		0.15f, 0.70f, 0.15f,				// scale (xyz)
		0.0f, 1.0f, 0.0f, 0.0f,				// x rotation (xyz)
		0.0f, 0.0f, 1.0f, 0.0f,				// y rotation (xyz)
		0.0f, 0.0f, 0.0f, 1.0f,				// z rotation (xyz)
		-1.0f, 0.75f, 2.0f,					// translate (xyz)
		1.0f, 1.0f
	};
	BrushMesh.height = 0.8f;
	BrushMesh.texFilename = "images\\brush_texture.jpg";
	BuildShape::UCylinderMesh(BrushMesh);
	scene.push_back(BrushMesh);


	//counter top
	GLMesh CounterMesh;
	CounterMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color (rgba)
		5.0f, 5.0f, 5.0f,					// scale (xyz)
		0.0f, 1.0f, 0.0f, 0.0f,				// x rotation (xyz)
		0.0f, 0.0f, 1.0f, 0.0f,				// y rotation (xyz)
		0.0f, 0.0f, 0.0f, 1.0f,				// z rotation (xyz)
		0.0f, 0.0f, 0.0f,					// translate (xyz)
		1.0f, 1.0f
	};
	CounterMesh.height = 0.8f;
	CounterMesh.texFilename = "images\\countertop.jpg";
	BuildShape::UPlaneMesh(CounterMesh);
	scene.push_back(CounterMesh);

	//ring
	GLMesh RingMesh;
	RingMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color (rgba)
		0.45f, 0.45f, 0.45f,				// scale (xyz)
		90.0f, 1.0f, 0.0f, 0.0f,			// x rotation (xyz)
		0.0f, 0.0f, 1.0f, 0.0f,				// y rotation (xyz)
		0.0f, 0.0f, 0.0f, 1.0f,				// z rotation (xyz)
		-0.45f, 0.04f, 3.2f,				// translate (xyz)
		1.0f, 1.0f
	};
	RingMesh.height = 0.8f;
	RingMesh.texFilename = "images\\metal.jpg";
	BuildShape::UTorusMesh(RingMesh);
	scene.push_back(RingMesh);

	//cotton puff
	GLMesh CottonMesh;
	CottonMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color (rgba)
		0.3f, 0.3f, 0.3f,					// scale (xyz)
		0.0f, 1.0f, 0.0f, 0.0f,				// x rotation (xyz)
		0.0f, 0.0f, 1.0f, 0.0f,				// y rotation (xyz)
		0.0f, 0.0f, 0.0f, 1.0f,				// z rotation (xyz)
		-0.45f, 0.3f, 3.2f,					// translate (xyz)
		1.0f, 1.0f
	};
	CottonMesh.height = 0.8f;
	CottonMesh.texFilename = "images\\cotton_puff.jpg";
	BuildShape::USphereMesh(CottonMesh);
	scene.push_back(CottonMesh);
}