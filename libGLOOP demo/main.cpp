#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#include "fluid/Render/ImplicitMesh.h"
#include "fluid/Tess/ContinuousTessellator.h"
#include "fluid/Tess/MarchingCube.h"
#include "fluid/Tess/CubePolygonizer.h"
#include "fluid/SurfRep/PotentialPoints.h"
#include "fluid/SurfRep/SurfaceSampler.h"

#define BLOB_NUMBER 2000

GLfloat diffuseMaterial[4] = { 0., 0., 1.0, 0.5 };
GLfloat mat_specular[] = { 0.2, 0.2, 0.7, 0.2 };
//GLfloat light0_position[] = { 10.0, 10.0, 10.0, 0.0 };
GLfloat light1_position[] = { 10.0, 20.0, 3.0, 0.0 };
GLfloat light1_diffuse[] = {0.7, 0.7, 1.0, 1.0};
GLfloat ambient_light[] = {0.5, 0.5, 0.7, 0.5};


ImplicitMesh mesh;
ContinuousTessellator tess;
PotentialPoints implicitPoints;
SurfaceSampler sampler;
CubePolygonizer polygonizer;
MarchingCube cube;

PhysicalPoint blob[BLOB_NUMBER];

float xvel[BLOB_NUMBER];
float yvel[BLOB_NUMBER];
float yaccel[BLOB_NUMBER];

float surfaceThreshold = 1.0;
float strength = 0.7;
float cubeletSize = 0.5;



void init(void) 
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.05);
//	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient_light);
	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

    /*
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    */

	sampler.setPotentialPoints(&implicitPoints);
	polygonizer.setSurfaceSampler(&sampler);
	polygonizer.setImplicitMesh(&mesh);
	tess.setMarchingCube(&cube);
	tess.setCubePolygonizer(&polygonizer);

	mesh.setUseColorArrays(false);
	mesh.setUseTexCoordArrays(false);
	mesh.setUseNormalArrays(true);
        
/*
	for(int i = 0; i < BLOB_NUMBER; ++i)
	{
		float x, y, z;
		x = (((float)rand()/(float)RAND_MAX) * 5.0) - 2.5;
		y = (((float)rand()/(float)RAND_MAX) * 5.0) - 2.5;
		z = 0.0;//(((float)rand()/(float)RAND_MAX) * 5.0) - 2.5;
		blob[i].loc.x = x;
		blob[i].loc.y = y;
		blob[i].loc.z = z;
		blob[i].strength = 1.;//(((float)rand()/(float)RAND_MAX) * 2.0);
		implicitPoints.addPoint(blob[i]);
	}
*/
    for(int i = 0; i < BLOB_NUMBER; ++i)
    {
        yvel[i] = 0.0;
        yaccel[i] = 0.0;
   		float x = (((float)rand()/(float)RAND_MAX) * 25) - 30;
        blob[i].loc.x = x;
        blob[i].loc.y = 8.0;
        float z = (((float)rand()/(float)RAND_MAX) * 5.0) - 2.5;
        blob[i].loc.z = z;
        blob[i].strength = strength;

        if(z == 0.0)
            xvel[i] = 0.1;
        xvel[i] = 0.1 - fabs(z/175);

        blob[i].color = Vector(255, 0, 0);

        implicitPoints.addPoint(blob[i]);
    }
    
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
  	gluLookAt(12.0, 0.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


	implicitPoints.finalizePointChanges();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	implicitPoints.clear();
    for(int i = 0; i < BLOB_NUMBER; ++i)
    {
        blob[i].strength = strength;
        blob[i].loc.x += xvel[i];
        yvel[i] += yaccel[i];
        blob[i].loc.y += yvel[i];
    
        if(blob[i].loc.x > 12.0)
        {
            blob[i].loc.x = -12;
            yaccel[i] = 0.0;
            yvel[i] = 0.0;
            blob[i].loc.y = 8.0;
        }
        else if(blob[i].loc.x > 8)
        {
            blob[i].loc.y = -5;
        }
        else if(blob[i].loc.x > -3.0)
        {
            yaccel[i] = -0.005;
        }

        if(blob[i].loc.y < -5)
        {
            yaccel[i] = 0.0;
            yvel[i] = 0.0;
            blob[i].loc.y = -5 + (((float)rand()/(float)RAND_MAX) * 1.5) - 0.75;
        }


        implicitPoints.addPoint(blob[i]);
    }

	implicitPoints.finalizePointChanges();
	mesh.clear();
	tess.tessellate(implicitPoints, cubeletSize, surfaceThreshold);
	mesh.generateNormals();
	mesh.doLight();
//	mesh.doSphereMap(Position(0.0, 0.0, 10.0));
	mesh.render();
	glFlush ();
    glutSwapBuffers();
    glutPostRedisplay();
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
   	gluPerspective(90, (GLfloat)w/(GLfloat)h, 0.0001, 1000000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
    case 'a':
     	cubeletSize += 0.1;
        break;
    case 'z':
        if(cubeletSize > 0.0)
            cubeletSize -= 0.1;
        else
            cubeletSize = 0.1;
        break;
    case 's':
        strength += 0.1;
        break;
    case 'x':
        strength -= 0.1;
        break;
    }
        
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (500, 500); 
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Morning Thunder and ReaLemon");
	init ();
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

