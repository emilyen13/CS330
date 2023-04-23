#pragma once

#include "meshes (1).h"

using namespace std;

class BuildShape
{
public:
	static void UBoxMesh(GLMesh& mesh);
	static void UBottleMesh(GLMesh& mesh);
	static void UCylinderMesh(GLMesh& mesh);
	static void UPlaneMesh(GLMesh& mesh);
	static void USphereMesh(GLMesh& mesh);
	static void UTorusMesh(GLMesh& mesh);
	static void UTranslator(GLMesh& mesh);

};
