#pragma once

#include "btBulletDynamicsCommon.h"
#include "LinearMath/btIDebugDraw.h"
#include <GL/freeglut.h>

using namespace std;
class GLDebugDraw :public btIDebugDraw
{
	int m_debugMode;
public:
	GLDebugDraw();
	virtual ~GLDebugDraw(){};
    virtual void drawLine(const btVector3& from, const btVector3& to, const btVector3& fromColor, const btVector3& toColor);
	virtual void   drawLine(const btVector3& from,const btVector3& to,const btVector3& color);
	virtual void   setDebugMode(int debugMode);
    virtual int      getDebugMode() const { return m_debugMode;}
	     virtual void   drawContactPoint(const btVector3& PointOnB,const btVector3& normalOnB,btScalar distance,int lifeTime,const btVector3& color);
      
        virtual void   reportErrorWarning(const char* warningString);
      
        virtual void   draw3dText(const btVector3& location,const char* textString);
   
};

