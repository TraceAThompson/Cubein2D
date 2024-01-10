//windows/mingw: g++ -o Cubein2D.exe Cubein2D.cpp -I include -lglew32 -lglfw3 -lgdi32 -lopengl32
//mac: g++ -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -o helloTriangle helloTriangle.cpp -I include -I/sw/include -I/usr/local/include

#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GLFW/glfw3.h> // GLFW helper library
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;


//global variables for transformation parameters
float tX = 0.0;
float tY = 0.0;
float tZ = 0.0;
float scaleX = 1.0;
float scaleY = 1.0;
float scaleZ = 1.0;
float angDegZ = 0.0; 
float angDegX = 0.0;
float angDegY = 0.0;
float angSk = 0.0; 

/*float near = 0.0;
float far = 0.0;
float fov = 0.0;
float aspect = 0.0;
float range = tan(fov * 0.5) * near;

float Sx = (2 * near) / (range * aspect + (range * aspect));
float Sy = (near / range);
float Sz = (-1 * (far + near))/(far - near);
float Pz = (-1 * (2 * far * near)) / (far - near);*/





void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode){
	if (key == GLFW_KEY_A && action == GLFW_PRESS){
		tX -= 0.1;
		cout << "tX: " << tX << endl;
	}
	
	if (key == GLFW_KEY_D && action == GLFW_PRESS){
		tX += 0.1;
		cout << "tX: " << tX << endl;
	}
	if (key == GLFW_KEY_S && action == GLFW_PRESS) {
		tY -= 0.1;
		cout << "tY: "<< tY << endl;
	}
	if (key == GLFW_KEY_W && action == GLFW_PRESS) {
		tY += 0.1;
		cout << "tY: "<< tY << endl;
	}
	if (key == GLFW_KEY_E && action == GLFW_PRESS) {
		tZ -= 0.1;
		cout << "tZ: "<< tZ << endl;
	}
	if (key == GLFW_KEY_Q && action == GLFW_PRESS) {
		tZ += 0.1;
		cout << "tZ: "<< tZ << endl;
	}
	if (key == GLFW_KEY_Z && action == GLFW_PRESS) {
		scaleX += 0.1;
		cout << "scaleX: "<< scaleX << endl;
	}
	if (key == GLFW_KEY_X && action == GLFW_PRESS) {
		scaleX -= 0.1;
		cout << "scaleX: "<< scaleX << endl;
	}
	if (key == GLFW_KEY_R && action == GLFW_PRESS) {
		scaleY += 0.1;
		cout << "scaleY: "<< scaleY << endl;
	}
	if (key == GLFW_KEY_T && action == GLFW_PRESS) {
		scaleY -= 0.1;
		cout << "scaleY: "<< scaleY << endl;
	}
	if (key == GLFW_KEY_F && action == GLFW_PRESS) {
		scaleZ += 0.1;
		cout << "scaleZ: "<< scaleZ << endl;
	}
	if (key == GLFW_KEY_G && action == GLFW_PRESS) {
		scaleZ -= 0.1;
		cout << "scaleZ: "<< scaleZ << endl;
	}
	if (key == GLFW_KEY_C && action == GLFW_PRESS) {
		angDegZ += 5.0;
		cout << "angDegZ: "<< angDegZ << endl;
	}
	if (key == GLFW_KEY_V && action == GLFW_PRESS) {
		angDegZ -= 5.0;
		cout << "angDegZ: "<< angDegZ << endl;
	}
	if (key == GLFW_KEY_Y && action == GLFW_PRESS) {
		angDegX += 5.0;
		cout << "angDegX: "<< angDegX << endl;
	}
	if (key == GLFW_KEY_U && action == GLFW_PRESS) {
		angDegX -= 5.0;
		cout << "angDegX: "<< angDegX << endl;
	}
	if (key == GLFW_KEY_H && action == GLFW_PRESS) {
		angDegY += 5.0;
		cout << "angDegY: "<< angDegY << endl;
	}
	if (key == GLFW_KEY_J && action == GLFW_PRESS) {
		angDegY -= 5.0;
		cout << "angDegY: "<< angDegY << endl;
	}
	/*if (key == GLFW_KEY_B && action == GLFW_PRESS) {
		near += 1.0;
		cout << "near: "<< near << endl;
	}
	if (key == GLFW_KEY_N && action == GLFW_PRESS) {
		near-= 1.0;
		cout << "near: "<< near << endl;
	}*/
	
	

}





int main() {
  // start GL context and O/S window using the GLFW helper library
  if (!glfwInit()) {
    fprintf(stderr, "ERROR: could not start GLFW3\n");
    return 1;
  } 
  
  // uncomment these lines if on Apple OS X
  /*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);*/

  GLFWwindow* window = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);
  if (!window) {
    fprintf(stderr, "ERROR: could not open window with GLFW3\n");
    glfwTerminate();
    return 1;
  }
  glfwMakeContextCurrent(window);
                                  
  // start GLEW extension handler
  glewExperimental = GL_TRUE;
  glewInit();

  // get version info
  const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
  const GLubyte* version = glGetString(GL_VERSION); // version as a string
  printf("Renderer: %s\n", renderer);
  printf("OpenGL version supported %s\n", version);

  // tell GL to only draw onto a pixel if the shape is closer to the viewer
  glEnable(GL_DEPTH_TEST); // enable depth-testing
  glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"


  glPointSize(5.0f);
  glClearColor(0.0f,0.0f,0.8f,1.0f);

  /* OTHER STUFF GOES HERE NEXT */
	float points[] = {
		//Front 1
	   0.2f,  0.1f,  -0.1f, //x, y, z 1st pt
	   0.2f, -0.2f,  -0.1f, //x, y, z 2nd pt
	  -0.1f, 0.1f,  -0.1f,  //x, y, z 3rd pt
	   
	   -0.1f, 0.1f, -0.1f,
	   -0.1f, -0.2f, -0.1f,
	    0.2f, -0.2f, -0.1f,
		//back 1
		0.2f,  0.1f,  0.4f, 
	   0.2f, -0.2f,  0.4f, 
	  -0.1f, 0.1f,  0.4f,  
	   
	   -0.1f, 0.1f, 0.4f,
	   -0.1f, -0.2f, 0.4f,
	    0.2f, -0.2f, 0.4f,
		
		//right 1
		0.2f, 0.1f, -0.1f,
		0.2f, -0.2f, -0.1f,
		0.2f, 0.1f, 0.4f,
		
		0.2f, 0.1f, 0.4f,
		0.2f, -0.2f, -0.1f,
		0.2f, -0.2f, 0.4f, 
		
		//left 1
		-0.1f, 0.1f, -0.1f,
		-0.1f, -0.2f, -0.1f,
		-0.1f, 0.1f, 0.4f,
		
		-0.1f, 0.1f, 0.4f,
		-0.1f, -0.2f, -0.1f,
		-0.1f, -0.2f, 0.4f,
		
		//top 1
		-0.1f, 0.1f, -0.1f,
		-0.1f, 0.1f, 0.4f,
		0.2f, 0.1f, -0.1f,
		
		0.2f, 0.1f, -0.1f,
		0.2f, 0.1f, 0.4f,
		-0.1f, 0.1f, 0.4f,
		
		//bottom 1
		-0.1f, -0.2f, -0.1f,
		-0.1f, -0.2f, 0.4f,
		0.2f, -0.2f, -0.1f,
		
		0.2f, -0.2f, -0.1f,
		-0.1f, -0.2f, 0.4f,
		0.2f, -0.2f, 0.4f,
		
		//front 2
		0.5f, -0.5f, -0.5f,
		0.8f, -0.7f, -0.5f,
		0.8f, -0.5f, -0.5f,
		
		0.8f, -0.7f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.7f, -0.5f,
		
		//back 2
		0.5f, -0.5f, -0.8f,
		0.8f, -0.7f, -0.8f,
		0.8f, -0.5f, -0.8f,
		
		0.8f, -0.7f, -0.8f,
		0.5f, -0.5f, -0.8f,
		0.5f, -0.7f, -0.8f,
		
		//right 2
		0.8f, -0.5f, -0.5f,
		0.8f, -0.7f, -0.5f,
		0.8f, -0.7f, -0.8f,
		
		0.8f, -0.5f, -0.5f,
		0.8f, -0.5f, -0.8f,
		0.8f, -0.7f, -0.8f,
		
		//left 2
		0.5f, -0.5f, -0.8f,
		0.5f, -0.7f, -0.8f,
		0.5f, -0.5f, -0.5f,
		
		0.5f, -0.7f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.7f, -0.8f,
		
		//top 2
		0.5f, -0.5f, -0.5f,
		0.8f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.8f,
		
		0.8f, -0.5f, -0.8f,
		0.5f, -0.5f, -0.8f,
		0.8f, -0.5f, -0.5f,
		
		//bottom 2
		0.5f, -0.7f, -0.5f,
		0.8f, -0.7f, -0.5f,
		0.5f, -0.7f, -0.8f,
		
		0.8f, -0.7f, -0.8f,
		0.5f, -0.7f, -0.8f,
		0.8f, -0.7f, -0.5f
		
		
	};
	
	float colors[] = {
		//front
		1.0, 1.0, 0.0, //r g b color of 1st pt
		1.0, 1.0, 0.0, //r g b color of 2nd pt		
		1.0, 1.0, 0.0,  //r g b color of 3rd pt
		
		1.0, 1.0, 0.0, //r g b color of 1st pt
		1.0, 1.0, 0.0, //r g b color of 2nd pt		
		1.0, 1.0, 0.0,  //r g b color of 3rd pt
		
		//back
		1.0, 0.0, 1.0, //r g b color of 1st pt
		1.0, 0.0, 1.0, //r g b color of 2nd pt		
		1.0, 0.0, 1.0,  //r g b color of 3rd pt
		
		1.0, 0.0, 1.0, //r g b color of 1st pt
		1.0, 0.0, 1.0, //r g b color of 2nd pt		
		1.0, 0.0, 1.0,  //r g b color of 3rd pt
		
		//right
		1.0, 0.0, 0.0, //r g b color of 1st pt
		1.0, 0.0, 0.0, //r g b color of 2nd pt		
		1.0, 0.0, 0.0,  //r g b color of 3rd pt
		
		
		1.0, 0.0, 0.0, //r g b color of 1st pt
		1.0, 0.0, 0.0, //r g b color of 2nd pt		
		1.0, 0.0, 0.0,  //r g b color of 3rd pt
		
		//left
		0.0, 1.0, 0.0, //r g b color of 1st pt
		0.0, 1.0, 0.0, //r g b color of 2nd pt		
		0.0, 1.0, 0.0,  //r g b color of 3rd pt
		
		
		0.0, 1.0, 0.0, //r g b color of 1st pt
		0.0, 1.0, 0.0, //r g b color of 2nd pt		
		0.0, 1.0, 0.0,  //r g b color of 3rd pt
		
		//top
		0.75, 0.0, 1.0, //r g b color of 1st pt
		0.75, 0.0, 1.0, //r g b color of 2nd pt		
		0.75, 0.0, 1.0,  //r g b color of 3rd pt
		
		0.75, 0.0, 1.0, //r g b color of 1st pt
		0.75, 0.0, 1.0, //r g b color of 2nd pt		
		0.75, 0.0, 1.0,  //r g b color of 3rd pt
		
		//bottom
		1.0, 0.75, 0.0, //r g b color of 1st pt
		1.0, 0.75, 0.0, //r g b color of 2nd pt		
		1.0, 0.75, 0.0,  //r g b color of 3rd pt
		
		1.0, 0.75, 0.0, //r g b color of 1st pt
		1.0, 0.75, 0.0, //r g b color of 2nd pt		
		1.0, 0.75, 0.0,  //r g b color of 3rd pt
		
		
		//front 2
		1.0, 0.5, 0.5,
		1.0, 0.5, 0.5,
		1.0, 0.5, 0.5,
		
		1.0, 0.5, 0.5,
		1.0, 0.5, 0.5,
		1.0, 0.5, 0.5,
		
		//back 2
		0.5, 1.0, 0.5,
		0.5, 1.0, 0.5,
		0.5, 1.0, 0.5,
		
		0.5, 1.0, 0.5,
		0.5, 1.0, 0.5,
		0.5, 1.0, 0.5,
		
		//right 2
		0.5, 0.5, 1.0,
		0.5, 0.5, 1.0,
		0.5, 0.5, 1.0,
		
		0.5, 0.5, 1.0,
		0.5, 0.5, 1.0,
		0.5, 0.5, 1.0,
		
		//left 2
		0.25, 0.5, 0.75,
		0.25, 0.5, 0.75,
		0.25, 0.5, 0.75,
		
		0.25, 0.5, 0.75,
		0.25, 0.5, 0.75,
		0.25, 0.5, 0.75,
		
		//top 2
		0.25, 0.75, 0.5,
		0.25, 0.75, 0.5,
		0.25, 0.75, 0.5,
		
		0.25, 0.75, 0.5,
		0.25, 0.75, 0.5,
		0.25, 0.75, 0.5,
		
		//bottom 2
		0.75, 0.25, 0.5,
		0.75, 0.25, 0.5,
		0.75, 0.25, 0.5,
		
		0.75, 0.25, 0.5,
		0.75, 0.25, 0.5,
		0.75, 0.25, 0.5
	};
	
	
	float up[] = {0, 1, 0} ;
	float right[] = {1, 0, 0} ;
	float forw[] = {0, 0, 1} ;
	float pos[] = {0, 1, 0} ;
	


	//transformation matrices
	
	//translation
	float tranMat[] = {  
		1, 0, 0, 0, 	//1st column
		0, 1, 0, 0, 	//2nd column
		0, 0, 1, 0, 	//3rd column
		tX, tY, tZ, 1	//4th column (tx, ty, tz parameters)	
	};
	
	//scale
	float scaleMat[] = {
		scaleX, 0, 0, 0,	//1st column
		0, scaleY, 0, 0,	//2nd column
		0, 0, scaleZ, 0,	//3rd column
		0, 0, 0, 1		//4th column
	};
    //cout << "pi: " << M_PI << endl;

	/*//projection matrices
	GLfloat proMat[] = {
		Sx, 0.0f, 0.0f, 0.0f,
		0.0f, Sy, 0.0f, 0.0f,
		0.0f, 0.0f, Sz, -1.0f,
		0.0f, 0.0f, Pz, 1.0f
	};
	
	GLfloat lookAt[] = {
		right[0], up[0], -forw[0], 0.0f,
		right[1], up[1], -forw[1], 0.0f,
		right[2], up[2], -forw[2], 0.0f,
		-pos[0], -pos[1], -pos[2], 1.0f
	};*/
	
	
	
	




	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 288 * sizeof(float), points, GL_STATIC_DRAW);
	//notice the 9 and the points above

	//duplicate for color data
	GLuint colors_vbo = 0;
	glGenBuffers(1, &colors_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
	glBufferData(GL_ARRAY_BUFFER,  288 * sizeof(float), colors, GL_STATIC_DRAW);
		

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	
	glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(1);


	
	const char* vertex_shader =
	"#version 400\n"
	"layout(location = 0) in vec3 vp;"  // <--- 
	"layout(location = 1) in vec3 vertex_color;"  // <--- 
	"attribute vec3 vp;"
	"uniform mat4 t, rZ, rX, rY, sc;"	
	
	"out vec3 color;"
	"void main() {"
	"  color = vertex_color;"
	//"  gl_Position = vec4(vp.x, vp.y, vp.z, 1.0);"
		"gl_Position = t*sc*rZ*rX*rY*vec4(vp, 1.0);" //transformations then look at then perspective
	"}";

	const char* fragment_shader =
	"#version 400\n"
	"in vec3 color;"
	"out vec4 frag_color;"
	"void main() {"
	//"  frag_color = vec4(1.0, 0.5, 1.0, 1.0);"  //rgba
	"	frag_color = vec4(color, 1.0);"
	"}";	


	//compiling the shaders and saying use these
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_program = glCreateProgram();
	glAttachShader(shader_program, fs);
	glAttachShader(shader_program, vs);
	glLinkProgram(shader_program);

	
			  
	int logLen;
	GLchar* log;
	glGetProgramiv(shader_program, GL_INFO_LOG_LENGTH, &logLen);

	
	//potentially help you find errors in vertex and fragment shaders
	/*if(logLen > 0) {

		// Show any errors as appropriate

		glGetProgramInfoLog(shader_program, logLen, &logLen, log);

		fprintf(stderr, "Prog Info Log: %s\n", log);

	}*/
			

	cout << "here\n"; 			
	
			  
	while(!glfwWindowShouldClose(window)) {
	
	  
	  tranMat[12] = tX;
	  tranMat[13] = tY;
	  tranMat[14] = tZ;
	  scaleMat[0] = scaleX;
	  scaleMat[5] = scaleY;
	  scaleMat[10] = scaleZ;
	  
	//rotation about z
	float angZ = (3.14159/180.0)*angDegZ; 
	float rotZMat[] = {  
		cos(angZ), sin(angZ), 0, 0, 	//1st column
		-sin(angZ), cos(angZ), 0, 0, 	//2nd column
		0, 0, 1, 0, 				//3rd column
		0, 0, 0, 1					//4th column 	
	};
	//rotation about x
	float angX = (3.14159/180.0)*angDegX; 
	float rotXMat[] = {  
		1, 0, 0, 0, 	//1st column
		0, cos(angX), -sin(angX), 0, 	//2nd column
		0, sin(angX), cos(angX), 0, 	//3rd column
		0, 0, 0, 1					//4th column 	
	};
	
	//rotation about y
	float angY = (3.14159/180.0)*angDegY; 
	float rotYMat[] = {  
		cos(angY), 0, sin(angY), 0, 	//1st column
		0, 1, 0, 0, 	//2nd column
		-sin(angY), 0, cos(angY), 0, 				//3rd column
		0, 0, 0, 1					//4th column 	
	};
	
	//skew/shear
	float skewMat[] = {
		1, 0, 0, 0,	//1st column
		cos(angSk)/sin(angSk), 1, 0, 0,	//2nd column
		0, 0, 1, 0,	//3rd column
		0, 0, 0, 1	//4th column
	};
	  

	
	  //add these 3 lines for every matrix you pass to the vertex shader
	  int trans_mat_location = glGetUniformLocation(shader_program, "t");
	  glUseProgram(shader_program);
	  glUniformMatrix4fv(trans_mat_location, 1, GL_FALSE, tranMat);
	  
	  int scale_mat_location = glGetUniformLocation(shader_program, "sc");
	  glUseProgram(shader_program);
	  glUniformMatrix4fv(scale_mat_location, 1, GL_FALSE, scaleMat);	
	  
	  int skew_mat_location = glGetUniformLocation(shader_program, "sk");  
	  glUseProgram(shader_program);
	  glUniformMatrix4fv(skew_mat_location, 1, GL_FALSE, skewMat);
	  
	  int rotZ_mat_location = glGetUniformLocation(shader_program, "rZ");
	  glUseProgram(shader_program);
	  glUniformMatrix4fv(rotZ_mat_location, 1, GL_FALSE, rotZMat);
	  
	  int rotX_mat_location = glGetUniformLocation(shader_program, "rX");
	  glUseProgram(shader_program);
	  glUniformMatrix4fv(rotX_mat_location, 1, GL_FALSE, rotXMat);
	  
	  int rotY_mat_location = glGetUniformLocation(shader_program, "rY");
	  glUseProgram(shader_program);
	  glUniformMatrix4fv(rotY_mat_location, 1, GL_FALSE, rotYMat);
	  
	  /*int view_mat_location = glGetUniformLocation(shader_program, "view");
	  glUseProgram(shader_program);
	  glUniformMatrix4fv(view_mat_location, 1, GL_FALSE, lookAt);
	  
	  int proj_mat_location = glGetUniformLocation(shader_program, "proj");
	  glUseProgram(shader_program);
	  glUniformMatrix4fv(proj_mat_location, 1, GL_FALSE, proMat);*/
	  
		
		
	  glfwSetKeyCallback(window, key_callback);	
		
		
	  // wipe the drawing surface clear
	  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	  glUseProgram(shader_program);
	  glBindVertexArray(vao);
	  glPointSize(15.0);
	  // draw points 0-3 from the currently bound VAO with current in-use shader
	  glDrawArrays(GL_TRIANGLES, 0, 72);
		//GL_POINTS, GL_LINE_STRIP

	  // update other events like input handling 
	  glfwPollEvents();
	  // put the stuff we've been drawing onto the display
	  glfwSwapBuffers(window);
	}

  // close GL context and any other GLFW resources
  glfwTerminate();
  return 0;
}

