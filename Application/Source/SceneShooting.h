#ifndef SCENE_SHOOTING_H
#define SCENE_SHOOTING_H

#include "Scene.h"
#include "Mesh.h"
#include "CameraFPS.h"
#include "MatrixStack.h"
#include "Light.h"
#include "gameObject.h"

class SceneShooting : public Scene
{
public:
	enum GEOMETRY_TYPE
	{
		GEO_AXES,
		GEO_SPHERE,
		GEO_LEFT,
		GEO_RIGHT,
		GEO_GUI,
		GEO_TOP,
		GEO_BOTTOM,
		GEO_TEXT,
		GEO_FRONT,
		GEO_BACK,
		GEO_PLANE,
		GEO_PLAYER,
		GEO_COLLIDER,
		NUM_GEOMETRY,
	};

	enum UNIFORM_TYPE
	{
		U_MVP = 0,
		U_MODELVIEW,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_MATERIAL_AMBIENT,
		U_MATERIAL_DIFFUSE,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,

		U_LIGHT0_TYPE,
		U_LIGHT0_POSITION,
		U_LIGHT0_COLOR,
		U_LIGHT0_POWER,
		U_LIGHT0_KC,
		U_LIGHT0_KL,
		U_LIGHT0_KQ,
		U_LIGHT0_SPOTDIRECTION,
		U_LIGHT0_COSCUTOFF,
		U_LIGHT0_COSINNER,
		U_LIGHT0_EXPONENT,

		U_LIGHT1_TYPE,
		U_LIGHT1_POSITION,
		U_LIGHT1_COLOR,
		U_LIGHT1_POWER,
		U_LIGHT1_KC,
		U_LIGHT1_KL,
		U_LIGHT1_KQ,
		U_LIGHT1_SPOTDIRECTION,
		U_LIGHT1_COSCUTOFF,
		U_LIGHT1_COSINNER,
		U_LIGHT1_EXPONENT,

		U_NUMLIGHTS,
		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,
		U_LIGHTENABLED,
		U_TEXT_ENABLED,
		U_TEXT_COLOR,
		U_TOTAL,
	};

	SceneShooting();
	~SceneShooting();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

	void spawnCollider(glm::vec3 pos, glm::vec3 scale, int number, bool spawn);
	
private:
	void HandleKeyPress();
	void HandleMouseInut();

	void RenderMesh(Mesh* mesh, bool enableLight);

	glm::vec3 playerPosition;	
	unsigned m_vertexArrayID;
	Mesh* meshList[NUM_GEOMETRY];

	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];

	CameraFPS camera;
	int projType = 1; // fix to 0 for orthographic, 1 for projection

	MatrixStack modelStack, viewStack, projectionStack;

	static const int NUM_LIGHTS = 6;
	Light light[NUM_LIGHTS];
	bool enableLight;
	void RenderMeshOnScreen(Mesh* mesh, float x, float y, float sizex, float sizey);
	void RenderText(Mesh* mesh, std::string text, Color color);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
	float speed = 3;
	float opoSpeed;
	float playerRotation;
	glm::vec3 previousPos;

	//0 is player
	gameObject* collider;

	int scene =1;
	int numofcol = 30;
};

#endif