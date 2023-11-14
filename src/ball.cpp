#include "ball.h"
#include "config.h"
#include <vector>
Ball::Ball(Point P, GLfloat radius, GLint slices,GLint stacks):P(P),radius(radius),slices(slices),stacks(stacks)
{
    for (int i = 0; i <= stacks; ++i) {
        GLfloat theta = i * PI / stacks;
        GLfloat sinTheta = sin(theta);
        GLfloat cosTheta = cos(theta);

        for (int j = 0; j <= slices; ++j) {
            GLfloat phi = j * 2 * PI / slices;
            GLfloat sinPhi = sin(phi);
            GLfloat cosPhi = cos(phi);

            GLfloat x = cosPhi * sinTheta;
            GLfloat y = cosTheta;
            GLfloat z = sinPhi * sinTheta;

            GLfloat nx = cosPhi * cosTheta;
            GLfloat ny = sinTheta;
            GLfloat nz = sinPhi * cosTheta;

            vertices.push_back({x * radius, y * radius, z * radius});
            normals.push_back({nx, ny, nz});
        }
    }
}

void Ball::render() 
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices.data());
    glNormalPointer(GL_FLOAT, 0, normals.data());

    glPushMatrix();
    glTranslatef(P.x, P.y, P.z);

    for (int i = 0; i < stacks; ++i) {
        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j <= slices; ++j) {
            glArrayElement(i * (slices + 1) + j);
            glArrayElement((i + 1) * (slices + 1) + j);
        }
        glEnd();
    }

    glPopMatrix();

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}