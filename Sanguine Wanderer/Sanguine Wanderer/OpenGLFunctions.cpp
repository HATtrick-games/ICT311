#include "OpenGLFunctions.h"
#include <stdlib.h>
#include <iostream>

OpenGLFunctions::OpenGLFunctions()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	GLfloat ambientColor[] = {0.4f, 0.4f, 0.4f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	GLfloat lightColor0[] = {0.6f, 0.6f, 0.6f, 1.0f};
	GLfloat lightPos0[] = {-0.5f, 0.8f, 0.1f, 0.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
}


OpenGLFunctions::~OpenGLFunctions(void)
{
}


GLuint OpenGLFunctions::LoadTexture(Texture* tex)
{
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
		0,                            //0 for now
		GL_RGB,                       //Format OpenGL uses for image
		tex->GetWidth(), tex->GetHeight(),  //Width and height
		0,                            //The border of the image
		GL_RGB, //GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
		//as unsigned numbers
		tex->GetData());               //The actual pixel data
	return textureId; //Returns the id of the texture
}

void OpenGLFunctions::RenderTerrain(Terrain* ter, float x, float y, float z, btDiscreteDynamicsWorld* dynamicsWorld)
{



		glLoadIdentity();
	// Set the camera
	gluLookAt(	0, 50, 70,
			0, 0,  0,
			0.0f, 1.0f,  0.0f);
	//std::cout<<y;
    glPushMatrix();
	glTranslatef(x,y,z);
	//glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(1,20,20);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.3f, 0.9f, 0.0f);
	dynamicsWorld->debugDrawWorld();
	glPopMatrix();
	
	float scale = 1;
	glScalef(scale, scale, scale);
	glTranslatef(-29.5,0,-29.5);
		
	glColor3f(0.3f, 0.9f, 0.0f);
	for(int z = 0; z < ter->GetLength() - 1; z++) {
		//Makes OpenGL draw a triangle at every three consecutive vertices
		glBegin(GL_TRIANGLE_STRIP);
		for(int x = 0; x < ter->GetWidth(); x++) {
			glm::vec3 normal = ter->GetNormal(x, z);
			glNormal3f(normal[0], normal[1], normal[2]);
			glVertex3f(x, ter->GetHeight(x, z), z);
			normal = ter->GetNormal(x, z + 1);
			glNormal3f(normal[0], normal[1], normal[2]);
			glVertex3f(x, ter->GetHeight(x, z + 1), z + 1);
		}
		glEnd();

	
	}	

	
		
}

/*void OpenGLFunctions::RenderMesh(Mesh* mesh)
{
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	for(unsigned int i = 0; i < m_entries.size(); ++i)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_entries[i].VB);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)12);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)20);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_entries[i].IB);

		const unsigned int materialIndex = m_entries[i].materialIndex;

		if(materialIndex < m_textures.size() && m_textures[materialIndex])
		{
			m_textures[materialIndex]->Bind(GL_TEXTURE0);
		}

		glDrawElements(GL_TRIANGLES, m_entries[i].numIndicies, GL_UNSIGNED_INT, 0);
	}

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}*/