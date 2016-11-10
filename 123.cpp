//#include <GL/gl.h>
//#include <GL/glu.h>]//]
// g++ 123.cpp -o  main -lGL -lGLU -lglut && ./main

#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
GLfloat rot = 0.0;
GLfloat ctlpoints3[4][4][3] = {
   {{ -1.5, -1.5, 4.0}, { -0.5, -1.5, 2.0}, {0.5, -1.5, -1.0}, {1.5, -1.5, 2.0}}, 
   {{ -1.5, -0.5, 1.0}, { -0.5, -0.5, 3.0}, {0.5, -0.5, 0.0}, {1.5, -0.5, -1.0}}, 
   {{ -1.5, 0.5, 4.0}, { -0.5, 0.5, 0.0}, {0.5, 0.5, 3.0}, {1.5, 0.5, 4.0}}, 
   {{-1.5, 1.5, -2.0}, { -0.5, 1.5, -2.0}, {0.5, 1.5, 0.0}, {1.5, 1.5, -1.0}}
};
GLfloat ctlpoints[4][4][3] = {
	{ { -1.5, 1.0, -1.5 },{ -0.5, 1.0,-1.5 },{ 0.5, 1.0, -1.5 },{ 1.5, 1.0,-1.5 } },
	{ { -1.5, 1.0, -0.5 },{ -0.5, 1.0,-0.5 },{ 0.5, 1.0, -0.5 },{ 1.5, 1.0,-0.5 } },
	{ { -1.5, 1.0,  0.5 },{ -0.5, 1.0, 0.5 },{ 0.5, 1.0,  0.5 },{ 1.5, 1.0, 0.5 } },
	{ { -1.5, 1.0,  1.5 },{ -0.5, 1.0, 1.5 },{ 0.5, 1.0,  1.5 },{ 1.5, 1.0, 1.5 } }
};

GLfloat ctlpoints2[7][4] = {
	{5.0,-5.0,0.0,1.0},{-5.0,2.0,0.0,1.0},{-2.0,5.0,0.0,1.0},{0.0,2.0,0.0,1.0},
	{2.0,5.0,0.0,1.0},{5.0,2.0,0.0,1.0},{-5.0,-5.0,0.0,1.0}};



GLfloat peca[21][4] ={{-5.854,-2.556,0,1},{-5.375,3.516,0,1},{-5.432,3.288,0,1},{0.337,2.726,0,1},
{0.282,2.931,0,1},{-0.051,1.086,0,1},{2.066,1.726,0,1},{1.846,0.043,0,1},{-0.233,0.778,0,1},
{0.535,-1.775,0,1},{-2.571,-1.232,0,1},{-1.891,0.339,0,1},{-3.749,0.582,0,1},{-3.024,-1.344,0,1},
{-5.808,-0.79,0,1},{-6.223,-1.328,0,1},{-5.96,0.739,0,1},{-3.495,0.946,0,1},{-4.326,1.925,0,1},
{-6.657,2.237,0,1},{-0.549,7.707,0,1}};

GLfloat k_peca[25] = {0,0.042,0.083,0.125,
        0.167,0.208,0.25,0.292,0.333,0.375,0.417,0.458,0.5,0.542,0.583,
        0.625,0.667,0.708,0.75,0.792,0.833,0.875,0.917,0.958,1};

int cpeca = 25;
GLfloat p[9][4] = {{-0.599,-5.756,0.333,1},{-7.574,-5.756,0.049,0.707},{-9.11,-0.116,-0.527,1},
{-7.89,6.05,-0.5,0.707},{-0.025,5.059,-0.18,1},{6.593,4.447,0.109,0.707},
{7.849,-0.737,0.079,1},{6.557,-6.37,0.406,0.707},{-0.599,-5.756,0.333,1}};

//teste
GLfloat p2[12][4] = {{-0.02,-6.033,0,1},{-0.8,-6.141,0,0.707},{0.608,-2.366,0,1},
{-2.687,3.24,0,0.707},{0,4,0,1},{4.07,4.303,0,0.707},{3.47,-0.073,0,1},
{4,-4,0,0.707},{-0.791,-4.501,0,1},{-0.305,-0.247,0,1},
{-1.5,-1.49,0,1},{-4.188,-2.528,0,1}};

int cont = 18;
GLfloat kp[18] = {0,.059,0.118,0.176,0.235,0.294,0.353,0.412,
        0.471,0.529,0.588,0.647,0.706,0.765,0.824,
        0.882,0.941,1};



GLfloat p1[12] =  {0,0,0,0.25,0.25,0.5,0.5,0.75,0.75,1,1,1}; 

GLfloat ctlpointcirc[7][4]  = {    
    {0,-.5, 0, 1},{.5,-.5, 0, 0.5},{0.25, -0.0669873, 0, 1},{0, 0.3880254, 0, 0.5},
    {-.25,  -0.0669873, 0, 1},{-.5,-.5, 0, 0.5},{0,-.5, 0, 1}};
 GLfloat ctrlPoints[7][4];
    
 GLfloat Knots[10] = {0,0,0,1,1,2,2,3,3,3};
 GLfloat ki[10] = {0.1,0.2,0.3,0.4,0.5,0.5,0.6,0.7,0.8,0.9};
// GLfloat k_peca[22] = { 0,0.048,0.095,0.143,0.19,0.238,0.286,0.333,
  //      0.381,0.429,0.476,0.524,0.571,0.619,0.667,0.714,0.762,0.81,
    //    0.857,0.905,0.952,1};  
GLfloat texpts[2][2][2] = {{{0.0, 0.0}, {0.0, 1.0}}, 
                        {{1.0, 0.0}, {1.0, 1.0}}};
//GLfloat ctlpoints[4][4][3];
int showPoints = 0;
float yy = 0.0;


GLUnurbsObj *theNurb;
GLUnurbsObj *theNurb2;

void quebra(void){
	int i;
//glRotatef(90,1,0,0);

gluNurbsCurve(theNurb2, cpeca, k_peca,4, 
            &peca[0][0], 4, GL_MAP1_VERTEX_4);


}

void Pote(void){
	int i;
	float tam = 0;
glRotatef(90,1,0,0);
       glRotatef(yy+=0.4,1,0,0);   
			gluNurbsCurve(theNurb2, cont, kp,4, 
            &p2[0][0], 6, GL_MAP1_VERTEX_4);
               
       for(i = 0; i < 60;i++){
        glTranslatef(0, 0, tam+=0.001);
  		 gluBeginCurve(theNurb2);
        
        // Send the Non Uniform Rational BSpline
        	gluNurbsCurve(theNurb2, cont, kp,4, 
            &p2[0][0], 6, GL_MAP1_VERTEX_4);
        
        gluEndCurve(theNurb2);
        
        }
        glTranslatef(0,0,0);
        glColor3f(0.0, 0.0, 1.0);
        glScalef(1.15,1.15,1.15);
        glPushMatrix();
        glTranslatef(-0.25,-0.08,0);
        for(i = 0 ; i < 10;i++){
        	glTranslatef(0, 0, tam+=0.001);
          gluBeginCurve(theNurb2);
        
        // Send the Non Uniform Rational BSpline
        	gluNurbsCurve(theNurb2, cont, kp,4, 
            &p2[0][0], 6, GL_MAP1_VERTEX_4);
        
        gluEndCurve(theNurb2);
        
        
        }
        float g = 1;
        for(i = 0;i < 200;i++){
				        
        gluBeginCurve(theNurb2);
        
        // Send the Non Uniform Rational BSpline
        	gluNurbsCurve(theNurb2, cont, kp,4, 
            &p2[0][0], 6, GL_MAP1_VERTEX_4);
        
        gluEndCurve(theNurb2);
        glScalef(g-=0.0001,g-=0.0001,g-=0.0001);
        }
        glPopMatrix();





}
void init_surface(void)
{
   int u, v;
   for (u = 0; u < 4; u++) {
      for (v = 0; v < 4; v++) {
//OpenGL   Programming Guide − Chapter 12,  Evaluators and NURBS − 16
         ctlpoints[u][v][0] = 2.0*((GLfloat)u - 1.5);
         ctlpoints[u][v][1] = 2.0*((GLfloat)v - 1.5);
         if ( (u == 1 || u == 2) && (v == 1 || v == 2))
            ctlpoints[u][v][2] = 3.0;
         else
            ctlpoints[u][v][2] = -3.0;
      }
   }    
}    
void nurbsError(GLenum errorCode)
{
   const GLubyte *estring;
   estring = gluErrorString(errorCode);
   //fprintf (stderr, "Nurbs Error: %s\n", estring);
   printf("%s\n", estring);
   exit (0);
}
void init(void)
{
   GLfloat mat_diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 100.0 };
   glClearColor (0.0, 0.0, 0.0, 0.0);
   //glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   //glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   //glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   //glEnable(GL_LIGHTING);
   //glEnable(GL_LIGHT0);
   //glEnable(GL_DEPTH_TEST);
   //glEnable(GL_AUTO_NORMAL);
   //glEnable(GL_NORMALIZE);
   //init_surface();
   theNurb = gluNewNurbsRenderer();
   theNurb2 = gluNewNurbsRenderer();
   gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 25.0);
   gluNurbsProperty(theNurb, GLU_DISPLAY_MODE, GLU_FILL);
   gluNurbsCallback(theNurb, GLU_ERROR, 
//OpenGL   Programming Guide − Chapter 12,  Evaluators and NURBS − 17
                    (GLvoid (*)()) nurbsError);
                    
                    
    gluNurbsProperty(theNurb2, GLU_SAMPLING_TOLERANCE, 5.0f);
}
void display(void)
{
   GLfloat knots[8] = {0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0};
   int i, j;
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f(1.0, 1.0, 0.0);
 
   glPushMatrix();
   //glRotatef(rot+=0.4,1,0,0);  
   //glRotatef(330.0, 1.,0.,0.);
  // glScalef (0.5, 0.5, 0.5);
   int k;
   
   for(k=0;k<1000;k++){
   	
   	//glTranslatef(0.1,0,0);
   	for(i = 0; i < 7; i++)
            {
                ctrlPoints[i][3] = ctlpointcirc[i][3];
                for (j = 0; j < 3; j++)
                {
                    ctrlPoints[i][j] = ctlpointcirc[i][j]*ctrlPoints[i][3];
                }
            }}
       
       glScalef(0.1,0.1,0.1);  
       quebra();
        
       // gluBeginSurface(theNurb);
    //gluNurbsSurface(theNurb,cont,kp,cont,kp,4*3,4,&p2[0][0],5,5,GL_MAP2_TEXTURE_COORD_2);
    //gluNurbsSurface(theNurb,cont,kp,cont,kp,4*3,4,&p2[0][0],5,5,GL_MAP2_NORMAL);
   //gluNurbsSurface(theNurb, cont, kp, cont, kp,4 * 3, 4, &p2[0][0], 5, 5, GL_MAP2_VERTEX_3);
    //gluEndSurface(theNurb);       
     /*   
     gluBeginCurve(theNurb2);
     gluNurbsCurve(theNurb2, 10, k,4, 
            &ctlpoints2[0][0], 3, GL_MAP1_VERTEX_4);
     gluEndCurve(theNurb2);
           
   */
   //gluEndSurface(theNurb);
   
   glPopMatrix();
   glFlush();
   glutPostRedisplay();
}
void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
//OpenGL   Programming Guide − Chapter 12,  Evaluators and NURBS − 18
   glLoadIdentity();
   gluPerspective (45.0, (GLdouble)w/(GLdouble)h, 3.0, 8.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -5.0);
}
void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutReshapeFunc(reshape);
   glutDisplayFunc(display);
   glutKeyboardFunc (keyboard);
   glutMainLoop();
   return 0; 
}
