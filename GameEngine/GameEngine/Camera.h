#pragma once

#include "boost\smart_ptr.hpp"
#include <glload/gl_3_3.h>

class Camera
{
public:
	Camera(void);
	~Camera(void);
	
	static boost::scoped_ptr<Camera>* GetInstance();

	void SetupCamera();
	void CreateCamera();
	bool SetCameraScale(float newScale);
	
private:

	float fPerspectiveMatrix[16];
	float fCameraScale;
	float fzNear;
	float fzFar;

	static boost::scoped_ptr<Camera> pCameraSingleton;
};

