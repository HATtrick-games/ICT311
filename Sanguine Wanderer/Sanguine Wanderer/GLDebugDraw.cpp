#include "GLDebugDraw.h"

GLDebugDraw::GLDebugDraw()
:m_debugMode(0)
{
   
}

void    GLDebugDraw::setDebugMode(int debugMode)
{
   m_debugMode = debugMode;
}

void    GLDebugDraw::drawLine(const btVector3& from,const btVector3& to,const btVector3& fromColor, const btVector3& toColor)
{
	glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3d(from.getX(), from.getY(), from.getZ());
        glColor3f(1,1,1);
        glVertex3d(to.getX(), to.getY(), to.getZ());
    glEnd();
}


void    GLDebugDraw::draw3dText(const btVector3& location,const char* textString)
{
   //glRasterPos3f(location.x(),  location.y(),  location.z());
   //BMF_DrawString(BMF_GetFont(BMF_kHelvetica10),textString);
}

void    GLDebugDraw::reportErrorWarning(const char* warningString)
{
   printf(warningString);
}

void    GLDebugDraw::drawContactPoint(const btVector3& pointOnB,const btVector3& normalOnB,btScalar distance,int lifeTime,const btVector3& color)
{
  /* {
      btVector3 to=pointOnB+normalOnB*distance;
     const btVector3&from = pointOnB;
   glColor4f(color.getX(), color.getY(), color.getZ(), 1.0f);   
      
     GLDebugDraw::drawLine(from, to, color);
      
      glRasterPos3f(from.x(),  from.y(),  from.z());
      char buf[12];
      sprintf(buf," %d",lifeTime);
     // BMF_DrawString(BMF_GetFont(BMF_kHelvetica10),buf);
   }*/
}

void    GLDebugDraw::drawLine(const btVector3& from,const btVector3& to,const btVector3& color)
{
   //      if (m_debugMode > 0)
 	glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3d(from.getX(), from.getY(), from.getZ());
        glColor3f(1,1,1);
        glVertex3d(to.getX(), to.getY(), to.getZ());
    glEnd();
}
