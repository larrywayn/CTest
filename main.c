#include <stdlib.h> 
#include <stdio.h>
#define GLFW_DLL
#include <GLFW/glfw3.h>
#include "Math3D.h"
#include "Vektor4.h"

int WinMain(int argc, char **argv) {
	
	Vektor4 *v1 =newVektor4(),*v2 = newVektor4(), *v3= newVektor4();
	v1->x = 2;
	v1->y = 0;
	v1->z = 2;
	v1->w = 1;
	
	v2->x = 0;
	v2->y = 2;
	v2->z = 2;
	v2->w = 1;
	
	v3->x = 0;
	v3->y = 0;
	v3->z = 0;
	v3->w = 0;
	addiereVV(v1,v2,v3);
	printf("Vektor 3: %e, %e, %e, %e \n", v3->x,v3->y,v3->z,v3->w);	
	free(v3);
	
	v3= newVektor4();
	subVV(v1,v2,v3);
	printf("Vektor 3: %e, %e, %e, %e \n", v3->x,v3->y,v3->z,v3->w);	
	free(v3);
	
	double skal = skalarV(v1);
	printf("Skalar V1: %e \n", skal);	
	
	v3= newVektor4();
	kreuzVV(v1,v2,v3);
	printf("Vektor 3: %e, %e, %e, %e \n", v3->x,v3->y,v3->z,v3->w);	
	

	invertiereV(v2);
	printf("Vektor 2: %e, %e, %e, %e \n", v2->x,v2->y,v2->z,v2->w);	
	
	skaliereV(v2, 2,3,4,5);
	printf("Vektor 2: %e, %e, %e, %e \n", v2->x,v2->y,v2->z,v2->w);	
	
	double lang = laengeV(v2);
	printf("Laenge V2: %e \n", lang);	
	
	free(v1);
	free(v2);
	free(v3);
	GLFWwindow* window;
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

	glfwMakeContextCurrent(window);

	//glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window)) {
        float ratio;
        int width;
		int height;

        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);

        glLoadIdentity();
        glRotatef((float) 20 * 50.f, 0.f, 0.f, 1.f);

        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

	glfwDestroyWindow(window);
	glfwTerminate();	
    return 0;
}
