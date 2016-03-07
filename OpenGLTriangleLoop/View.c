//
//  View.c
//  OpenGLPerspective
//
//  Created by Laura del Pino Díaz on 7/3/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#include "View.h"



void Init(){
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // TO DO
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-gl_width/2.0, gl_width/2.0, -gl_height/2.0, gl_height/2.0, gl_near, gl_far);
    }


void Display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // // TO DO
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(-0.8f, 0.8f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.8f, 0.8f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.8f, -0.8f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(-0.8f, 0.8f);
    glEnd();
    glFlush(); // actualiza el framebuffer
}

void ReshapeSize(int width, int height){
    
    float dx = gl_width;
    float dy = gl_height;
    
    dx *= (float)width / (float)w_width;
    dy *= (float)height / (float)w_height;
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-dx / 2.0, dx / 2.0, -dy / 2.0, dy / 2.0, gl_near, gl_far); // espacio de trabajo
    glutPostRedisplay();
}